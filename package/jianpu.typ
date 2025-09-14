#let p = plugin("dist/jianpu.wasm")

#let toabc(srcraw, key: "Cmaj") = {
  let src = srcraw
  let parsed = cbor(p.parse(bytes(src)))
  let numname = ("One", "Two", "Three", "Four", "Five", "Six", "Seven")
  let keys = (
    // with sharps
    "Gmaj": ("G", "A", "B", "c", "d", "e", "f"),
    "Dmaj": ("D", "E", "F", "G", "A", "B", "c"),
    "Amaj": ("A", "B", "c", "d", "e", "f", "g"),
    "Emaj": ("E", "F", "G", "A", "B", "c", "d"),
    "Bmaj": ("B", "c", "d", "e", "f", "g", "a"),
    "F#maj": ("F", "G", "A", "B", "c", "d", "e"),
    "C#maj": ("C", "D", "E", "F", "G", "A", "B"),
    // no sharps and flats
    "Cmaj": ("C", "D", "E", "F", "G", "A", "B"),
    // with flats
    "Fmaj": ("F", "G", "A", "B", "c", "d", "e"),
    "Bbmaj": ("B", "c", "d", "e", "f", "g", "a"),
    "Ebmaj": ("E", "F", "G", "A", "B", "c", "d"),
    "Abmaj": ("A", "B", "c", "d", "e", "f", "g"),
    "Dbmaj": ("D", "E", "F", "G", "A", "B", "c"),
    "Gbmaj": ("G", "A", "B", "c", "d", "e", "f"),
    "Cbmaj": ("C", "D", "E", "F", "G", "A", "B"),
  )
  let num2abc(num) = {
    keys.at(key.split(" ").at(0)).at(numname.position(x => x == num))
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

