use std::fmt::format;

use tree_sitter;
use tree_sitter_jianpu;
use wasm_minimal_protocol::*;

use serde::{Deserialize, Serialize};

initiate_protocol!();

#[derive(Debug, PartialEq, serde::Serialize)]
pub struct Source {
    pub elements: Vec<Element>,
}

#[derive(Debug, PartialEq, serde::Serialize)]
pub enum Element {
    Note(Note),
    Bar(Bar),
    Tilde,
    LeftParen,
    RightParen,
    EmptyLine,
}

#[derive(Debug, PartialEq, serde::Serialize)]
pub enum Accidental {
    Sharp,        // #
    Flat,         // b
    Natural,      // =
    DoubleSharp,  // ##
    DoubleFlat,   // bb
}

#[derive(Debug, PartialEq, serde::Serialize)]
pub struct Note {
    pub accidental: Option<Accidental>,
    pub pitch: Pitch,
    pub duration: Duration,
}

/// 音高可能是休止符（Rest）或者具体的音高值（Tone）
#[derive(Debug, PartialEq, serde::Serialize)]
pub enum Pitch {
    Rest, // 对应 token "0"
    Tone {
        pitch_class: PitchClass,
        octave: Option<Octave>,
    },
}

/// 用枚举来表示数字 1-7，对应音高的音级
#[derive(Debug, PartialEq, serde::Serialize)]
pub enum PitchClass {
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
}

/// 表示音符的八度信息：逗号表示低八度，撇号表示高八度，数值代表连续出现的个数
#[derive(Debug, PartialEq, serde::Serialize)]
pub enum Octave {
    Lower(u8),  // 例如：",,," 表示 3 个逗号
    Higher(u8), // 例如："''" 表示 2 个撇号
}

/// 音符时值，对应各种记谱符号
#[derive(Debug, PartialEq, serde::Serialize)]
pub enum Duration {
    DottedSemiquaver, // token: "\\."
    Semiquaver,       // token: "\\"
    DottedQuaver,     // token: "\."
    Quaver,           // token: "\"
    DottedCrotchet,   // token: "."
    Crotchet,         //
    Semibreve,        // token: " - - -"
    DottedMinim,      // token: " - -"
    Minim,            // token: " -"
}

/// 小节符号，根据不同的记谱符号定义了不同的类型
#[derive(Debug, PartialEq, serde::Serialize)]
pub enum Bar {
    Standard,     // token: '|'
    Double,       // token: '||'
    Beg,          // token: '[|'
    End,          // token: '|]'
    BegRepeat,    // token: '|:'
    EndRepeat,    // token: ':|'
    BegEndRepeat, // token: '::'
}

fn parse_tone(node: &tree_sitter::Node) -> Result<Pitch, String> {
    let pitch_class = match node.child_by_field_name("pitch_class") {
        Some(pitch_class_node) => match pitch_class_node.kind() {
            "p_one" => PitchClass::One,
            "p_two" => PitchClass::Two,
            "p_three" => PitchClass::Three,
            "p_four" => PitchClass::Four,
            "p_five" => PitchClass::Five,
            "p_six" => PitchClass::Six,
            "p_seven" => PitchClass::Seven,
            _ => return Err("Invalid pitch class".to_string()),
        },
        None => return Err("Missing pitch class".to_string()),
    };

    let octave = match node.child_by_field_name("octave") {
        Some(octave_node) => {
            let length = octave_node.end_position().column - octave_node.start_position().column;
            match octave_node.kind() {
                "lower" => Some(Octave::Lower(length as u8)),
                "higher" => Some(Octave::Higher(length as u8)),
                _ => return Err("Invalid octave".to_string()),
            }
        }

        None => None,
    };

    Ok(Pitch::Tone {
        pitch_class,
        octave,
    })
}

fn parse_pitch(node: &tree_sitter::Node) -> Result<Pitch, String> {
    let c = node.child(0).unwrap();
    match c.kind() {
        "rest" => Ok(Pitch::Rest),
        "tone" => parse_tone(&c),
        _ => Err("Invalid pitch".to_string()),
    }
}

fn parse_duration(node: &tree_sitter::Node) -> Result<Duration, String> {
    match node.kind() {
        "d_dotted_semiquaver" => Ok(Duration::DottedSemiquaver),
        "d_semiquaver" => Ok(Duration::Semiquaver),
        "d_dotted_quaver" => Ok(Duration::DottedQuaver),
        "d_quaver" => Ok(Duration::Quaver),
        "d_dotted_crotchet" => Ok(Duration::DottedCrotchet),
        "d_semibreve" => Ok(Duration::Semibreve),
        "d_dotted_minim" => Ok(Duration::DottedMinim),
        "d_minim" => Ok(Duration::Minim),
        _ => Err("Invalid duration".to_string()),
    }
}

fn parse_note(node: &tree_sitter::Node) -> Result<Note, String> {
    let pitch = match node.child_by_field_name("pitch") {
        Some(pitch_node) => parse_pitch(&pitch_node)?,
        None => return Err("Missing pitch".to_string()),
    };

    let accidental = match node.child_by_field_name("acc") {
        Some(acc_node) => match acc_node.kind() {
            "acc_sharp" => Some(Accidental::Sharp),
            "acc_flat" => Some(Accidental::Flat),
            "acc_natural" => Some(Accidental::Natural),
            "acc_double_sharp" => Some(Accidental::DoubleSharp),
            "acc_double_flat" => Some(Accidental::DoubleFlat),
            _ => return Err("Invalid accidental".to_string()),
        },
        None => None,
    };

    let duration = match node.child_by_field_name("duration") {
        Some(duration_node) => parse_duration(&duration_node)?,
        None => Duration::Crotchet,
    };

    Ok(Note { accidental, pitch, duration })
}

fn parse_bar(node: &tree_sitter::Node) -> Result<Bar, String> {
    match node.child(0).unwrap().kind() {
        "bar_standard" => Ok(Bar::Standard),
        "bar_double" => Ok(Bar::Double),
        "bar_beg" => Ok(Bar::Beg),
        "bar_end" => Ok(Bar::End),
        "bar_beg_repeat" => Ok(Bar::BegRepeat),
        "bar_end_repeat" => Ok(Bar::EndRepeat),
        "bar_beg_end_repeat" => Ok(Bar::BegEndRepeat),
        _ => Err("Invalid bar".to_string()),
    }
}

fn parse_element(node: &tree_sitter::Node) -> Result<Element, String> {
    match node.kind() {
        "note" => Ok(Element::Note(parse_note(node)?)),
        "bar" => Ok(Element::Bar(parse_bar(node)?)),
        "empty_line" => Ok(Element::EmptyLine),
        "tilde" => Ok(Element::Tilde),
        "leftparen" => Ok(Element::LeftParen),
        "rightparen" => Ok(Element::RightParen),
        _ => Err("Invalid element".to_string()),
    }
}

fn parse_source(node: &tree_sitter::Node) -> Result<Source, String> {
    let mut elements = vec![];
    let cursor = &mut node.walk();
    for node in node.children(cursor) {
        elements.push(parse_element(&node)?);
    }
    Ok(Source { elements })
}

#[wasm_func]
pub fn parse(input: &[u8]) -> Result<Vec<u8>, String> {
    let mut parser = tree_sitter::Parser::new();
    let language = tree_sitter_jianpu::LANGUAGE;
    parser
        .set_language(&language.into())
        .expect("Error loading Jianpu parser");
    let Ok(code) = std::str::from_utf8(input) else {
        return Err("Invalid UTF-8".to_string());
    };
    let tree = parser.parse(code, None).unwrap();
    let root = tree.root_node();

    let source = parse_source(&root).unwrap();
    let mut buffer = vec![];
    _ = ciborium::ser::into_writer(&source, &mut buffer)
        .map_err(|e| format!("failed to serialize results: {}", e.to_string()))?;

    Ok(buffer)
}

// test
#[test]
fn test_hello() {
    let src = r"0 0 0 0 | 3\. 5\\ 5 3\. 2\\ 1 | 2\. 3\\ 5\. 3\\ 2 - | 3\. 5\\ 5 3\. 2\\ 1 |

2\ 3\ 2\. 1\\ 1 - | 6\. 1'\\ 1' 7\ 5\ 6 | 6\ 1'\ 7\ 5\ 6 - | 6\. 1'\\ 1' 7\ 5\ 6 |
6\ 1'\ 7\ 5\ 6 - | 3\. 5\\ 5 3\ 2\ 1 | 2\. 3\\ 5\. 3\\ 2 - | 3\. 5\\ 5 1'\. 2'\\ 3' |
2'\. 1'\\ 2'\ 6\ 1' - | 0 0 0 0 | 2'. 1'\ 2' 6 | 1' - - - |

% test
% test
0 0 0 0 |]";
    let result = parse(src.as_bytes()).unwrap();
    unreachable!();
}
