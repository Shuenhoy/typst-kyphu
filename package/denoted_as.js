
if (typeof abc2svg == "undefined")
    abc2svg = {}

abc2svg.denotedas = {
    new_note: function (of, gr, tp) {
        let p_v = this.get_curvoice()

        // Call the original function first
        let s = of(gr, tp)
        if (!p_v.denotedas_key)
            return
        if (!s.notes || s.type != abc2svg.C.NOTE)
            return

        let current_key = p_v.ckey
        let target_key = p_v.denotedas_key
        let current_map = current_key.k_map
        let target_map = target_key.k_map

        for (let i = 0; i < s.notes.length; i++) {
            let note = s.notes[i]
            let pit_class = (note.pit + 19) % 7  // Convert to 0-6 (C-B)

            // Get the accidental that should be applied in current key
            let current_acc = current_map[pit_class]

            // Get the accidental that should be applied in target key
            let target_acc = target_map[pit_class]



            // Only add accidental if it's different from what target key would provide
            if (note.acc === undefined) {
                if (current_acc != target_acc) {
                    let needed_acc = target_acc - current_acc
                    if (target_acc == 0) {
                        note.acc = 3  // natural
                    } else {
                        note.acc = needed_acc
                    }
                }
            }

        }

    },
    set_fmt: function (of, cmd, param) {
        if (cmd == "denotedas") {
            this.set_v_param("denotedas", param)
            return
        }
        of(cmd, param)
    }, // set_fmt()
    set_vp: function (of, a) {
        let p_v = this.get_curvoice()

        for (let i = 0; i < a.length; i++) {
            if (a[i] == "denotedas=") {
                let key = a[++i]
                if (!key) {
                    this.syntax(1, "No key specified for %%denotedas")
                    break
                }
                let sf_target = "FCGDAEB".indexOf(key[0]) - 1
                if (sf_target < -1) {
                    this.syntax(1, "Invalid key '" + key + "' for %%denotedas")
                    break
                }

                // Handle sharps/flats
                let j = 1
                if (key[j] == '#') {
                    sf_target += 7
                    j++
                } else if (key[j] == 'b') {
                    sf_target -= 7
                    j++
                }

                // Handle mode (simplified - just major/minor for now)
                let mode = 0
                let remaining = key.slice(j).trim().toLowerCase()
                if (remaining.indexOf('min') == 0) {
                    sf_target -= 3
                    mode = 5  // minor mode
                }

                if (sf_target < -7 || sf_target > 7) {
                    this.syntax(1, "Key signature out of range for %%denotedas")
                    break
                }

                p_v = this.get_curvoice()
                p_v.denotedas_key = {
                    k_sf: sf_target,
                    k_map: abc2svg.keys[sf_target + 7],
                    k_mode: mode
                }


                break
            }
        }
        of(a)
    }, // set_vp()
    set_hooks: function (abc) {
        abc.set_format = abc2svg.denotedas.set_fmt.bind(abc, abc.set_format)
        abc.new_note = abc2svg.denotedas.new_note.bind(abc, abc.new_note)
        abc.set_vp = abc2svg.denotedas.set_vp.bind(abc, abc.set_vp)
    }
}
if (!abc2svg.mhooks)
    abc2svg.mhooks = {}
abc2svg.mhooks.denotedas = abc2svg.denotedas.set_hooks