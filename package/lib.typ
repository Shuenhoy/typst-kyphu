#import "abc.typ": render-abc
#import "jianpu.typ"


#let sheet(content, show-raw: false) = {
  let body = ""
  // for each child, if it is lang: abc, append its text to body
  let key = "Cmaj"
  for child in content.children {
    if child.func() == raw {
      if child.lang == "abc" {
        body += child.text
        // if child.text contains: "/K: (.+)/", set key to the value after "K:"
        let keymatch = child.text.matches(regex("K: (.+)"))

        if keymatch.len() > 0 {
          key = keymatch.last().captures.at(0)
        }
      } else if child.lang == "jianpu" {
        body += jianpu.toabc(child.text, key: key)
      }
      if child.block and not str.ends-with(body, "\n") {
        body += "\n"
      }
    }
  }
  let r = raw(lang: "abc", body)
  if show-raw {
    r + render-abc(r)
  } else {
    render-abc(r)
  }
}
