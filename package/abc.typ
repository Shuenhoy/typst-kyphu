#import "@preview/ctxjs:0.3.1"

#let abc2svg-source = read("./dist/abc2svg-v1.22.26/abc2svg-1.js")
#let jianpu-source = read("./dist/abc2svg-v1.22.26/jianpu-1.js")
#let ctx = ctxjs.new-context(
  load: (
    ctxjs.load.eval(jianpu-source + abc2svg-source),
    ctxjs.load.eval("
    function mytosvg(src) {
      let out = []
      let abcx = new abc2svg.Abc({
        read_file:function(a){},
        errbld:function(a,b,c,d){},
        img_out:(x)=>{out.push(x)},
      })
      abcx.tosvg('out', src)
      return out
    }
    "),
  ),
)
#let render-abc(body) = {
  let src = body.text.split("\n").map(x => x.trim()).join("\n")
  let s = ctxjs.ctx.call-function(
    ctx,
    "mytosvg",
    (
      "%%fullsvg x\n" + src,
    ),
  )
  for (id, value) in s.enumerate() {
    block(image(bytes(value), format: "svg"), sticky: if id == 0 { true } else { false })
  }
}
