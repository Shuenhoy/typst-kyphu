#import "package/lib.typ": sheet

// use `show-raw: true` to get a raw abc
#sheet[
  ```abc
  %%musicfont abc2svg
  %%stretchlast 1.0
  X: 1
  T: 送别
  C: 李叔同 词
  C: 奥德威 曲
  M: 4/4
  L: 1/8
  K: Ebmaj
  %%score {1|2}
  V: 1
  %%jianpu 1
  V: 2
  V: 1,2
  ```
  // You can mix jianpu and abc notation
  // ```jianpu
  // 5 3\~5\ 1' - | 6 1' 5 - | 5 1\~2\ 3 2\~1\ | 2 - - 0 |```
  ```abc
  B2 (GB) E'4 | c2 E'2 B4 | B2 (EF) G2 (FE) | F6 z2```
  ```abc
  V: 2
  w: 长 亭 * 外，| 古 道 边， | 芳 草 * 碧 连 * | 天。
  w: 情 千 * 缕，| 酒 一 杯， | 声 声 * 离 笛 * | 催。
  V: 1,2
  ```
  ```jianpu
  5 ( 3\~5\ ) 1'. 7\ | 6 1' 5 - | 5 ( 2\~3\ ) 4. 7,\  | 1 - - 0 |```
  ```abc
  V: 2
  w: 晚 风 * 拂 柳 | 笛 声 残， | 夕 阳 * 山 外 山。
  w: 问 君 * 此 去 | 几 时 来， | 来 时 * 莫 徘 徊。
  V: 1,2
  ```
  // You can even mix them in the same line
  // ```jianpu
  // 6 1' 1' - | 7 ( 6\ 7 ) 1' - | ( 6\~7\ ) ( 1'\~6\ ) ( 6\~5\ ) ( 3\~1\ ) | 2 - - 0 |
  // ```
  ```jianpu 6 1' 1' - | 7 ( 6\ 7 ) 1' -```
  ```abc
  |(cd )(E'c )(cB )(GE )|F6 z2 |```
  ```abc
  V: 2
  w: 天 之 涯， | 地 之 * 角， | 知 * 交 * 半 * 零 * 落。
  w: 草 碧 色， | 水 绿 * 波， | 南 * 浦 * 伤 * 如 * 何。
  V: 1,2
  ```

  ```abc B2 GB E'3 d |c2 E'2 B4 |```
  ```jianpu
  5 2\~3\ 4. 7,\  | 1 - - 0 :|```
  // ```jianpu
  // 5 3\~5\ 1'. 7\ | 6 1' 5 - | 5 2\~3\ 4. 7,\  | 1 - - 0 :|```
  ```abc
  V: 2
  w: 一 瓢 * 浊 酒 | 尽 余 欢， | 今 宵 * 别 梦 寒。
  w: 人 生 * 难 得 | 是 欢 聚， | 惟 有 * 别 离 多。```
]

// Example of using denotedas to show a piece in a different key
#sheet[
  ```abc
  X: 1
  T: D shown in C key
  V: 1
  K: Cmaj
  %%jianpu 1
  %%denotedas Dmaj
  DEFGABc|

  X: 2
  T: D shown in G key
  V: 1
  K: Gmaj
  %%jianpu 1
  %%denotedas Dmaj
  DEFGABc|

  X: 3
  T: G and F shown in D key
  V: 1
  K: Dmaj
  %%jianpu 1
  %%denotedas Gmaj
  ```
  ```jianpu
  1 2 3 4 5 6 7 |
  ```
  ```abc
  %%denotedas Fmaj
  ```
  ```jianpu
  1 2 3 4 5 6 7 |
  ```
]
