#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 15
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 40
#define ALIAS_COUNT 0
#define TOKEN_COUNT 29
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym__spaces = 1,
  sym__comments = 2,
  sym_empty_line = 3,
  sym_bar_standard = 4,
  sym_bar_double = 5,
  sym_bar_beg = 6,
  sym_bar_end = 7,
  sym_bar_beg_repeat = 8,
  sym_bar_end_repeat = 9,
  sym_bar_begend_repeat = 10,
  sym_p_one = 11,
  sym_p_two = 12,
  sym_p_three = 13,
  sym_p_four = 14,
  sym_p_five = 15,
  sym_p_six = 16,
  sym_p_seven = 17,
  sym_rest = 18,
  sym_lower = 19,
  sym_higher = 20,
  sym_d_dotted_semiquaver = 21,
  sym_d_semiquaver = 22,
  sym_d_dotted_quaver = 23,
  sym_d_quaver = 24,
  sym_d_dotted_crotchet = 25,
  sym_d_semibreve = 26,
  sym_d_dotted_minim = 27,
  sym_d_minim = 28,
  sym_source_file = 29,
  sym__line = 30,
  sym__elm = 31,
  sym_bar = 32,
  sym_note = 33,
  sym_pitch = 34,
  sym__pitch_class = 35,
  sym_tone = 36,
  sym__octave = 37,
  sym__duraion = 38,
  aux_sym__line_repeat1 = 39,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__spaces] = "_spaces",
  [sym__comments] = "_comments",
  [sym_empty_line] = "empty_line",
  [sym_bar_standard] = "bar_standard",
  [sym_bar_double] = "bar_double",
  [sym_bar_beg] = "bar_beg",
  [sym_bar_end] = "bar_end",
  [sym_bar_beg_repeat] = "bar_beg_repeat",
  [sym_bar_end_repeat] = "bar_end_repeat",
  [sym_bar_begend_repeat] = "bar_begend_repeat",
  [sym_p_one] = "p_one",
  [sym_p_two] = "p_two",
  [sym_p_three] = "p_three",
  [sym_p_four] = "p_four",
  [sym_p_five] = "p_five",
  [sym_p_six] = "p_six",
  [sym_p_seven] = "p_seven",
  [sym_rest] = "rest",
  [sym_lower] = "lower",
  [sym_higher] = "higher",
  [sym_d_dotted_semiquaver] = "d_dotted_semiquaver",
  [sym_d_semiquaver] = "d_semiquaver",
  [sym_d_dotted_quaver] = "d_dotted_quaver",
  [sym_d_quaver] = "d_quaver",
  [sym_d_dotted_crotchet] = "d_dotted_crotchet",
  [sym_d_semibreve] = "d_semibreve",
  [sym_d_dotted_minim] = "d_dotted_minim",
  [sym_d_minim] = "d_minim",
  [sym_source_file] = "source_file",
  [sym__line] = "_line",
  [sym__elm] = "_elm",
  [sym_bar] = "bar",
  [sym_note] = "note",
  [sym_pitch] = "pitch",
  [sym__pitch_class] = "_pitch_class",
  [sym_tone] = "tone",
  [sym__octave] = "_octave",
  [sym__duraion] = "_duraion",
  [aux_sym__line_repeat1] = "_line_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__spaces] = sym__spaces,
  [sym__comments] = sym__comments,
  [sym_empty_line] = sym_empty_line,
  [sym_bar_standard] = sym_bar_standard,
  [sym_bar_double] = sym_bar_double,
  [sym_bar_beg] = sym_bar_beg,
  [sym_bar_end] = sym_bar_end,
  [sym_bar_beg_repeat] = sym_bar_beg_repeat,
  [sym_bar_end_repeat] = sym_bar_end_repeat,
  [sym_bar_begend_repeat] = sym_bar_begend_repeat,
  [sym_p_one] = sym_p_one,
  [sym_p_two] = sym_p_two,
  [sym_p_three] = sym_p_three,
  [sym_p_four] = sym_p_four,
  [sym_p_five] = sym_p_five,
  [sym_p_six] = sym_p_six,
  [sym_p_seven] = sym_p_seven,
  [sym_rest] = sym_rest,
  [sym_lower] = sym_lower,
  [sym_higher] = sym_higher,
  [sym_d_dotted_semiquaver] = sym_d_dotted_semiquaver,
  [sym_d_semiquaver] = sym_d_semiquaver,
  [sym_d_dotted_quaver] = sym_d_dotted_quaver,
  [sym_d_quaver] = sym_d_quaver,
  [sym_d_dotted_crotchet] = sym_d_dotted_crotchet,
  [sym_d_semibreve] = sym_d_semibreve,
  [sym_d_dotted_minim] = sym_d_dotted_minim,
  [sym_d_minim] = sym_d_minim,
  [sym_source_file] = sym_source_file,
  [sym__line] = sym__line,
  [sym__elm] = sym__elm,
  [sym_bar] = sym_bar,
  [sym_note] = sym_note,
  [sym_pitch] = sym_pitch,
  [sym__pitch_class] = sym__pitch_class,
  [sym_tone] = sym_tone,
  [sym__octave] = sym__octave,
  [sym__duraion] = sym__duraion,
  [aux_sym__line_repeat1] = aux_sym__line_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__spaces] = {
    .visible = false,
    .named = true,
  },
  [sym__comments] = {
    .visible = false,
    .named = true,
  },
  [sym_empty_line] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_standard] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_double] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_beg] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_end] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_beg_repeat] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_end_repeat] = {
    .visible = true,
    .named = true,
  },
  [sym_bar_begend_repeat] = {
    .visible = true,
    .named = true,
  },
  [sym_p_one] = {
    .visible = true,
    .named = true,
  },
  [sym_p_two] = {
    .visible = true,
    .named = true,
  },
  [sym_p_three] = {
    .visible = true,
    .named = true,
  },
  [sym_p_four] = {
    .visible = true,
    .named = true,
  },
  [sym_p_five] = {
    .visible = true,
    .named = true,
  },
  [sym_p_six] = {
    .visible = true,
    .named = true,
  },
  [sym_p_seven] = {
    .visible = true,
    .named = true,
  },
  [sym_rest] = {
    .visible = true,
    .named = true,
  },
  [sym_lower] = {
    .visible = true,
    .named = true,
  },
  [sym_higher] = {
    .visible = true,
    .named = true,
  },
  [sym_d_dotted_semiquaver] = {
    .visible = true,
    .named = true,
  },
  [sym_d_semiquaver] = {
    .visible = true,
    .named = true,
  },
  [sym_d_dotted_quaver] = {
    .visible = true,
    .named = true,
  },
  [sym_d_quaver] = {
    .visible = true,
    .named = true,
  },
  [sym_d_dotted_crotchet] = {
    .visible = true,
    .named = true,
  },
  [sym_d_semibreve] = {
    .visible = true,
    .named = true,
  },
  [sym_d_dotted_minim] = {
    .visible = true,
    .named = true,
  },
  [sym_d_minim] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__line] = {
    .visible = false,
    .named = true,
  },
  [sym__elm] = {
    .visible = false,
    .named = true,
  },
  [sym_bar] = {
    .visible = true,
    .named = true,
  },
  [sym_note] = {
    .visible = true,
    .named = true,
  },
  [sym_pitch] = {
    .visible = true,
    .named = true,
  },
  [sym__pitch_class] = {
    .visible = false,
    .named = true,
  },
  [sym_tone] = {
    .visible = true,
    .named = true,
  },
  [sym__octave] = {
    .visible = false,
    .named = true,
  },
  [sym__duraion] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__line_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_duration = 1,
  field_octave = 2,
  field_pitch = 3,
  field_pitch_class = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_duration] = "duration",
  [field_octave] = "octave",
  [field_pitch] = "pitch",
  [field_pitch_class] = "pitch_class",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_pitch, 0},
  [1] =
    {field_pitch_class, 0},
  [2] =
    {field_duration, 1},
    {field_pitch, 0},
  [4] =
    {field_octave, 1},
    {field_pitch_class, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      ADVANCE_MAP(
        '\n', 7,
        ' ', 8,
        '%', 1,
        '\'', 28,
        ',', 27,
        '.', 33,
        '0', 26,
        '1', 19,
        '2', 20,
        '3', 21,
        '4', 22,
        '5', 23,
        '6', 24,
        '7', 25,
        ':', 4,
        '[', 5,
        '\\', 32,
        '|', 12,
      );
      if (('\t' <= lookahead && lookahead <= '\r')) ADVANCE(9);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(35);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(34);
      END_STATE();
    case 4:
      if (lookahead == ':') ADVANCE(18);
      if (lookahead == '|') ADVANCE(17);
      END_STATE();
    case 5:
      if (lookahead == '|') ADVANCE(14);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym__spaces);
      if (lookahead == '\n') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym__spaces);
      if (lookahead == '-') ADVANCE(36);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym__spaces);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym__comments);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_empty_line);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(9);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_bar_standard);
      if (lookahead == ':') ADVANCE(16);
      if (lookahead == ']') ADVANCE(15);
      if (lookahead == '|') ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_bar_double);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_bar_beg);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_bar_end);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_bar_beg_repeat);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_bar_end_repeat);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_bar_begend_repeat);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_p_one);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_p_two);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_p_three);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_p_four);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_p_five);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_p_six);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_p_seven);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_rest);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_lower);
      if (lookahead == ',') ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_higher);
      if (lookahead == '\'') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_d_dotted_semiquaver);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_d_semiquaver);
      if (lookahead == '.') ADVANCE(29);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_d_dotted_quaver);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_d_quaver);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '\\') ADVANCE(30);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_d_dotted_crotchet);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_d_semibreve);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_d_dotted_minim);
      if (lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_d_minim);
      if (lookahead == ' ') ADVANCE(2);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__spaces] = ACTIONS(1),
    [sym__comments] = ACTIONS(3),
    [sym_empty_line] = ACTIONS(1),
    [sym_bar_standard] = ACTIONS(1),
    [sym_bar_double] = ACTIONS(1),
    [sym_bar_beg] = ACTIONS(1),
    [sym_bar_end] = ACTIONS(1),
    [sym_bar_beg_repeat] = ACTIONS(1),
    [sym_bar_end_repeat] = ACTIONS(1),
    [sym_bar_begend_repeat] = ACTIONS(1),
    [sym_p_one] = ACTIONS(1),
    [sym_p_two] = ACTIONS(1),
    [sym_p_three] = ACTIONS(1),
    [sym_p_four] = ACTIONS(1),
    [sym_p_five] = ACTIONS(1),
    [sym_p_six] = ACTIONS(1),
    [sym_p_seven] = ACTIONS(1),
    [sym_rest] = ACTIONS(1),
    [sym_lower] = ACTIONS(1),
    [sym_higher] = ACTIONS(1),
    [sym_d_dotted_semiquaver] = ACTIONS(1),
    [sym_d_semiquaver] = ACTIONS(1),
    [sym_d_dotted_quaver] = ACTIONS(1),
    [sym_d_quaver] = ACTIONS(1),
    [sym_d_dotted_crotchet] = ACTIONS(1),
    [sym_d_semibreve] = ACTIONS(1),
    [sym_d_dotted_minim] = ACTIONS(1),
    [sym_d_minim] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(13),
    [sym__line] = STATE(14),
    [sym__elm] = STATE(7),
    [sym_bar] = STATE(7),
    [sym_note] = STATE(7),
    [sym_pitch] = STATE(4),
    [sym__pitch_class] = STATE(3),
    [sym_tone] = STATE(5),
    [sym__comments] = ACTIONS(3),
    [sym_bar_standard] = ACTIONS(5),
    [sym_bar_double] = ACTIONS(7),
    [sym_bar_beg] = ACTIONS(7),
    [sym_bar_end] = ACTIONS(7),
    [sym_bar_beg_repeat] = ACTIONS(7),
    [sym_bar_end_repeat] = ACTIONS(7),
    [sym_bar_begend_repeat] = ACTIONS(7),
    [sym_p_one] = ACTIONS(9),
    [sym_p_two] = ACTIONS(9),
    [sym_p_three] = ACTIONS(9),
    [sym_p_four] = ACTIONS(9),
    [sym_p_five] = ACTIONS(9),
    [sym_p_six] = ACTIONS(9),
    [sym_p_seven] = ACTIONS(9),
    [sym_rest] = ACTIONS(11),
  },
  [2] = {
    [sym__elm] = STATE(12),
    [sym_bar] = STATE(12),
    [sym_note] = STATE(12),
    [sym_pitch] = STATE(4),
    [sym__pitch_class] = STATE(3),
    [sym_tone] = STATE(5),
    [sym__comments] = ACTIONS(3),
    [sym_bar_standard] = ACTIONS(5),
    [sym_bar_double] = ACTIONS(7),
    [sym_bar_beg] = ACTIONS(7),
    [sym_bar_end] = ACTIONS(7),
    [sym_bar_beg_repeat] = ACTIONS(7),
    [sym_bar_end_repeat] = ACTIONS(7),
    [sym_bar_begend_repeat] = ACTIONS(7),
    [sym_p_one] = ACTIONS(9),
    [sym_p_two] = ACTIONS(9),
    [sym_p_three] = ACTIONS(9),
    [sym_p_four] = ACTIONS(9),
    [sym_p_five] = ACTIONS(9),
    [sym_p_six] = ACTIONS(9),
    [sym_p_seven] = ACTIONS(9),
    [sym_rest] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(3), 1,
      sym__comments,
    STATE(6), 1,
      sym__octave,
    ACTIONS(17), 2,
      sym_lower,
      sym_higher,
    ACTIONS(13), 5,
      ts_builtin_sym_end,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(15), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [26] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    STATE(11), 1,
      sym__duraion,
    ACTIONS(21), 2,
      sym__spaces,
      sym_empty_line,
    ACTIONS(23), 4,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(25), 4,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [52] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(27), 5,
      ts_builtin_sym_end,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(29), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [71] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(31), 5,
      ts_builtin_sym_end,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(33), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [90] = 4,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    STATE(8), 1,
      aux_sym__line_repeat1,
    ACTIONS(37), 2,
      sym__spaces,
      sym_empty_line,
  [104] = 4,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    STATE(9), 1,
      aux_sym__line_repeat1,
    ACTIONS(37), 2,
      sym__spaces,
      sym_empty_line,
  [118] = 4,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    STATE(9), 1,
      aux_sym__line_repeat1,
    ACTIONS(43), 2,
      sym__spaces,
      sym_empty_line,
  [132] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(46), 1,
      ts_builtin_sym_end,
    ACTIONS(48), 2,
      sym__spaces,
      sym_empty_line,
  [143] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(50), 1,
      ts_builtin_sym_end,
    ACTIONS(52), 2,
      sym__spaces,
      sym_empty_line,
  [154] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 2,
      sym__spaces,
      sym_empty_line,
  [165] = 2,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
  [172] = 2,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(58), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 26,
  [SMALL_STATE(5)] = 52,
  [SMALL_STATE(6)] = 71,
  [SMALL_STATE(7)] = 90,
  [SMALL_STATE(8)] = 104,
  [SMALL_STATE(9)] = 118,
  [SMALL_STATE(10)] = 132,
  [SMALL_STATE(11)] = 143,
  [SMALL_STATE(12)] = 154,
  [SMALL_STATE(13)] = 165,
  [SMALL_STATE(14)] = 172,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tone, 1, 0, 2),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tone, 1, 0, 2),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 1, 0, 1),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 1, 0, 1),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitch, 1, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitch, 1, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tone, 2, 0, 4),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tone, 2, 0, 4),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 1, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 2, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0),
  [43] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bar, 1, 0, 0),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bar, 1, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 2, 0, 3),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 2, 0, 3),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_jianpu(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
