/**
 * @file Jianpu grammar for tree-sitter
 * @author Shuenhoy <shuenhoy@gmail.com>
 * @license MIT
 */


/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
module.exports = grammar({
    name: 'jianpu',
    extras: $ => [$._comments],
    rules: {
        source_file: $ => $._line,
        tilde: $ => /~+/,
        leftparen: $ => "(",
        rightparen: $ => ")",
        _seps: $ => choice($.tilde, $._spaces),
        _spaces: $ => /\s+/,
        _spaces0: $ => /\s*/,
        _comments: $ => /%[^\n]*\n/,
        _line: $ => seq(
            $._elm,
            repeat(seq(choice($.empty_line, $._seps), $._elm,))),
        empty_line: $ => "\n\n",
        _elm: $ => choice($.note, $.bar, $.leftparen, $.rightparen),
        bar: $ => choice(
            $.bar_standard, $.bar_double,
            $.bar_beg, $.bar_end,
            $.bar_beg_repeat, $.bar_end_repeat,
            $.bar_begend_repeat
        ),
        bar_standard: $ => '|',
        bar_double: $ => '||',
        bar_beg: $ => '[|',
        bar_end: $ => '|]',
        bar_beg_repeat: $ => '|:',
        bar_end_repeat: $ => ':|',
        bar_begend_repeat: $ => '::',

        note: $ => seq(field("acc", optional($._acc)), field("pitch", $.pitch), field("duration", optional($._duraion))),
        pitch: $ => choice($.rest, $.tone),
        _acc: $ => choice(
            $.acc_sharp, $.acc_flat, $.acc_natural,
            $.acc_double_sharp, $.acc_double_flat
        ),
        acc_sharp: $ => token('#'),
        acc_flat: $ => token('b'),
        acc_natural: $ => token('='),
        acc_double_sharp: $ => token('##'),
        acc_double_flat: $ => token('bb'),
        _pitch_class: $ => choice($.p_one, $.p_two, $.p_three, $.p_four, $.p_five, $.p_six, $.p_seven),
        tone: $ => seq(field("pitch_class", $._pitch_class), field("octave", optional($._octave))),
        p_one: $ => token('1'),
        p_two: $ => token('2'),
        p_three: $ => token('3'),
        p_four: $ => token('4'),
        p_five: $ => token('5'),
        p_six: $ => token('6'),
        p_seven: $ => token('7'),
        rest: $ => token("0"),
        _octave: $ => choice($.lower, $.higher),
        lower: $ => /,+/,
        higher: $ => /'+/,
        _duraion: $ => choice(
            $.d_dotted_semiquaver, $.d_semiquaver,
            $.d_dotted_quaver, $.d_quaver,
            $.d_dotted_crotchet,
            $.d_semibreve, $.d_dotted_minim, $.d_minim,
        ),
        d_dotted_semiquaver: $ => token('\\\\.'),
        d_semiquaver: $ => token('\\\\'),
        d_dotted_quaver: $ => token('\\.'),
        d_quaver: $ => token('\\'),
        d_dotted_crotchet: $ => token('.'),
        d_semibreve: $ => token(' - - -'),
        d_dotted_minim: $ => token(' - -'),
        d_minim: $ => token(' -'),
    },
});