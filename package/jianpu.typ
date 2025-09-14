#let p = plugin("dist/jianpu.wasm")


#let notes-of-keys() = {
  let modes = ("maj", "dor", "phr", "lyd", "mix", "min", "loc")

  let mode-map = (
    "G": ("G", "A", "B", "C", "D", "E", "F#"),
    "D": ("D", "E", "F#", "G", "A", "B", "C#"),
    "A": ("A", "B", "C#", "D", "E", "F#", "G#"),
    "E": ("E", "F#", "G#", "A", "B", "C#", "D#"),
    "B": ("B", "C#", "D#", "E", "F#", "G#", "A#"),
    "F#": ("F#", "G#", "A#", "B", "C#", "D#", "E#"),
    "C#": ("C#", "D#", "E#", "F#", "G#", "A#", "B#"),
    "C": ("C", "D", "E", "F", "G", "A", "B"),
    "F": ("F", "G", "A", "Bb", "C", "D", "E"),
    "Bb": ("Bb", "C", "D", "Eb", "F", "G", "A"),
    "Eb": ("Eb", "F", "G", "Ab", "Bb", "C", "D"),
    "Ab": ("Ab", "Bb", "C", "Db", "Eb", "F", "G"),
    "Db": ("Db", "Eb", "F", "Gb", "Ab", "Bb", "C"),
    "Gb": ("Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F"),
    "Cb": ("Cb", "Db", "Eb", "Fb", "Gb", "Ab", "Bb"),
  )

  let keys = (:)
  for (base, rels) in mode-map {
    for (i, r) in rels.enumerate() {
      keys.insert(r + modes.at(i), base)
    }
  }
  keys
}
#let keymodes = notes-of-keys()

#let toabc(srcraw, key: "C") = {
  let src = srcraw
  let parsed = cbor(p.parse(bytes(src)))
  let numname = ("One", "Two", "Three", "Four", "Five", "Six", "Seven")
  let keys = (
    // with sharps
    "G": ("G", "A", "B", "c", "d", "e", "f"),
    "D": ("D", "E", "F", "G", "A", "B", "c"),
    "A": ("A", "B", "c", "d", "e", "f", "g"),
    "E": ("E", "F", "G", "A", "B", "c", "d"),
    "B": ("B", "c", "d", "e", "f", "g", "a"),
    "F#": ("F", "G", "A", "B", "c", "d", "e"),
    "C#": ("C", "D", "E", "F", "G", "A", "B"),
    // no sharps and flats
    "C": ("C", "D", "E", "F", "G", "A", "B"),
    // with flats
    "F": ("F", "G", "A", "B", "c", "d", "e"),
    "Bb": ("B", "c", "d", "e", "f", "g", "a"),
    "Eb": ("E", "F", "G", "A", "B", "c", "d"),
    "Ab": ("A", "B", "c", "d", "e", "f", "g"),
    "Db": ("D", "E", "F", "G", "A", "B", "c"),
    "Gb": ("G", "A", "B", "c", "d", "e", "f"),
    "Cb": ("C", "D", "E", "F", "G", "A", "B"),
  )
  let num2abc(num) = {
    keys.at(keymodes.at(key.split(" ").at(0))).at(numname.position(x => x == num))
  }

  let duration = (
    "DottedSemiquaver": "3/4",
    "Semiquaver": "/2",
    "DottedQuaver": "3/2",
    "Quaver": "",
    "Crotchet": "2",
    "DottedCrotchet": "3",
    "Minim": "4",
    "DottedMinim": "6",
    "Semibreve": "8",
  )
  let strings = ()
  for (idx, ele) in parsed.elements.enumerate() {
    // if has key Note:
    if "Note" in ele {
      if "Tone" in ele.Note.pitch {
        strings.push(num2abc(ele.Note.pitch.Tone.pitch_class))
        if "octave" in ele.Note.pitch.Tone {
          let octave = ele.Note.pitch.Tone.octave
          if octave != none {
            if "Higher" in octave {
              strings.push("'" * octave.Higher)
            } else {
              strings.push("," * octave.Lower)
            }
          }
        }
      } else {
        strings.push("z")
      }
      strings.push(duration.at(ele.Note.duration))
      if idx != parsed.elements.len() - 1 {
        if parsed.elements.at(idx + 1) != "Tilde" {
          strings.push(" ")
        }
      }
    } else if "Bar" in ele {
      if ele.Bar == "Standard" {
        strings.push("|")
      } else if ele.Bar == "Double" {
        strings.push("||")
      } else if ele.Bar == "Beg" {
        strings.push("[|")
      } else if ele.Bar == "End" {
        strings.push("|]")
      } else if ele.Bar == "BegRepeat" {
        strings.push("|:")
      } else if ele.Bar == "EndRepeat" {
        strings.push(":|")
      }
    } else if ele == "EmptyLine" {
      strings.push("\n")
    } else if ele == "LeftParen" {
      strings.push("(")
    } else if ele == "RightParen" {
      strings.push(")")
    }
  }
  strings.join("")
}

