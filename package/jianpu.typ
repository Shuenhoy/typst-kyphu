#let p = plugin("dist/jianpu.wasm")

#let toabc(srcraw, key: "Cmaj") = {
  let src = srcraw
  let parsed = cbor(p.parse(bytes(src)))
  let numname = ("One", "Two", "Three", "Four", "Five", "Six", "Seven")
  let keys = (
    "Bmaj": ("B", "C", "D", "E", "F", "G", "A"),
    "Emaj": ("E", "F", "G", "A", "B", "C", "D"),
    "Amaj": ("A", "B", "C", "D", "E", "F", "G"),
    "Dmaj": ("D", "E", "F", "G", "A", "B", "c"),
    "Gmaj": ("G", "A", "B", "c", "d", "e", "f"),
    "Cmaj": ("C", "D", "E", "F", "G", "A", "B"),
    "Fmaj": ("F", "G", "A", "B", "C", "D", "E"),
    "Bbmaj": ("B", "c", "d", "e", "f", "g", "a"),
    "Ebmaj": ("E", "F", "G", "A", "B", "c", "d"),
  )
  let num2abc(num) = {
    keys.at(key).at(numname.position(x => x == num))
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
  for ele in parsed.elements {
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
    }
  }
  strings.join("")
}

