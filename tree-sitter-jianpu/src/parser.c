#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 15
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 44
#define ALIAS_COUNT 0
#define TOKEN_COUNT 32
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 2
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  sym_tilde = 1,
  sym_leftparen = 2,
  sym_rightparen = 3,
  sym__spaces = 4,
  sym__comments = 5,
  sym_empty_line = 6,
  sym_bar_standard = 7,
  sym_bar_double = 8,
  sym_bar_beg = 9,
  sym_bar_end = 10,
  sym_bar_beg_repeat = 11,
  sym_bar_end_repeat = 12,
  sym_bar_begend_repeat = 13,
  sym_p_one = 14,
  sym_p_two = 15,
  sym_p_three = 16,
  sym_p_four = 17,
  sym_p_five = 18,
  sym_p_six = 19,
  sym_p_seven = 20,
  sym_rest = 21,
  sym_lower = 22,
  sym_higher = 23,
  sym_d_dotted_semiquaver = 24,
  sym_d_semiquaver = 25,
  sym_d_dotted_quaver = 26,
  sym_d_quaver = 27,
  sym_d_dotted_crotchet = 28,
  sym_d_semibreve = 29,
  sym_d_dotted_minim = 30,
  sym_d_minim = 31,
  sym_source_file = 32,
  sym__seps = 33,
  sym__line = 34,
  sym__elm = 35,
  sym_bar = 36,
  sym_note = 37,
  sym_pitch = 38,
  sym__pitch_class = 39,
  sym_tone = 40,
  sym__octave = 41,
  sym__duraion = 42,
  aux_sym__line_repeat1 = 43,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_tilde] = "tilde",
  [sym_leftparen] = "leftparen",
  [sym_rightparen] = "rightparen",
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
  [sym__seps] = "_seps",
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
  [sym_tilde] = sym_tilde,
  [sym_leftparen] = sym_leftparen,
  [sym_rightparen] = sym_rightparen,
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
  [sym__seps] = sym__seps,
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
  [sym_tilde] = {
    .visible = true,
    .named = true,
  },
  [sym_leftparen] = {
    .visible = true,
    .named = true,
  },
  [sym_rightparen] = {
    .visible = true,
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
  [sym__seps] = {
    .visible = false,
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
        '\n', 10,
        ' ', 11,
        '%', 1,
        '\'', 31,
        '(', 8,
        ')', 9,
        ',', 30,
        '.', 36,
        '0', 29,
        '1', 22,
        '2', 23,
        '3', 24,
        '4', 25,
        '5', 26,
        '6', 27,
        '7', 28,
        ':', 4,
        '[', 5,
        '\\', 35,
        '|', 15,
        '~', 7,
      );
      if (('\t' <= lookahead && lookahead <= '\r')) ADVANCE(12);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(13);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(38);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(37);
      END_STATE();
    case 4:
      if (lookahead == ':') ADVANCE(21);
      if (lookahead == '|') ADVANCE(20);
      END_STATE();
    case 5:
      if (lookahead == '|') ADVANCE(17);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_tilde);
      if (lookahead == '~') ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_leftparen);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_rightparen);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym__spaces);
      if (lookahead == '\n') ADVANCE(14);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym__spaces);
      if (lookahead == '-') ADVANCE(39);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym__spaces);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym__comments);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_empty_line);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_bar_standard);
      if (lookahead == ':') ADVANCE(19);
      if (lookahead == ']') ADVANCE(18);
      if (lookahead == '|') ADVANCE(16);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_bar_double);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_bar_beg);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_bar_end);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_bar_beg_repeat);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_bar_end_repeat);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_bar_begend_repeat);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_p_one);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_p_two);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_p_three);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_p_four);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_p_five);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_p_six);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_p_seven);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_rest);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_lower);
      if (lookahead == ',') ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_higher);
      if (lookahead == '\'') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_d_dotted_semiquaver);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_d_semiquaver);
      if (lookahead == '.') ADVANCE(32);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_d_dotted_quaver);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_d_quaver);
      if (lookahead == '.') ADVANCE(34);
      if (lookahead == '\\') ADVANCE(33);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_d_dotted_crotchet);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_d_semibreve);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_d_dotted_minim);
      if (lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 39:
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
    [sym_tilde] = ACTIONS(1),
    [sym_leftparen] = ACTIONS(1),
    [sym_rightparen] = ACTIONS(1),
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
    [sym_leftparen] = ACTIONS(5),
    [sym_rightparen] = ACTIONS(5),
    [sym__comments] = ACTIONS(3),
    [sym_bar_standard] = ACTIONS(7),
    [sym_bar_double] = ACTIONS(9),
    [sym_bar_beg] = ACTIONS(9),
    [sym_bar_end] = ACTIONS(9),
    [sym_bar_beg_repeat] = ACTIONS(9),
    [sym_bar_end_repeat] = ACTIONS(9),
    [sym_bar_begend_repeat] = ACTIONS(9),
    [sym_p_one] = ACTIONS(11),
    [sym_p_two] = ACTIONS(11),
    [sym_p_three] = ACTIONS(11),
    [sym_p_four] = ACTIONS(11),
    [sym_p_five] = ACTIONS(11),
    [sym_p_six] = ACTIONS(11),
    [sym_p_seven] = ACTIONS(11),
    [sym_rest] = ACTIONS(13),
  },
  [2] = {
    [sym__elm] = STATE(12),
    [sym_bar] = STATE(12),
    [sym_note] = STATE(12),
    [sym_pitch] = STATE(4),
    [sym__pitch_class] = STATE(3),
    [sym_tone] = STATE(5),
    [sym_leftparen] = ACTIONS(15),
    [sym_rightparen] = ACTIONS(15),
    [sym__comments] = ACTIONS(3),
    [sym_bar_standard] = ACTIONS(7),
    [sym_bar_double] = ACTIONS(9),
    [sym_bar_beg] = ACTIONS(9),
    [sym_bar_end] = ACTIONS(9),
    [sym_bar_beg_repeat] = ACTIONS(9),
    [sym_bar_end_repeat] = ACTIONS(9),
    [sym_bar_begend_repeat] = ACTIONS(9),
    [sym_p_one] = ACTIONS(11),
    [sym_p_two] = ACTIONS(11),
    [sym_p_three] = ACTIONS(11),
    [sym_p_four] = ACTIONS(11),
    [sym_p_five] = ACTIONS(11),
    [sym_p_six] = ACTIONS(11),
    [sym_p_seven] = ACTIONS(11),
    [sym_rest] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(3), 1,
      sym__comments,
    STATE(6), 1,
      sym__octave,
    ACTIONS(21), 2,
      sym_lower,
      sym_higher,
    ACTIONS(17), 6,
      ts_builtin_sym_end,
      sym_tilde,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(19), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [27] = 6,
    ACTIONS(3), 1,
      sym__comments,
    STATE(11), 1,
      sym__duraion,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(25), 2,
      sym__spaces,
      sym_empty_line,
    ACTIONS(27), 4,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(29), 4,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [54] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(31), 6,
      ts_builtin_sym_end,
      sym_tilde,
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
  [74] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(35), 6,
      ts_builtin_sym_end,
      sym_tilde,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(37), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [94] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(39), 1,
      ts_builtin_sym_end,
    ACTIONS(41), 1,
      sym_tilde,
    STATE(2), 1,
      sym__seps,
    STATE(8), 1,
      aux_sym__line_repeat1,
    ACTIONS(43), 2,
      sym__spaces,
      sym_empty_line,
  [114] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(41), 1,
      sym_tilde,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym__seps,
    STATE(9), 1,
      aux_sym__line_repeat1,
    ACTIONS(43), 2,
      sym__spaces,
      sym_empty_line,
  [134] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(47), 1,
      ts_builtin_sym_end,
    ACTIONS(49), 1,
      sym_tilde,
    STATE(2), 1,
      sym__seps,
    STATE(9), 1,
      aux_sym__line_repeat1,
    ACTIONS(52), 2,
      sym__spaces,
      sym_empty_line,
  [154] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(55), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(57), 2,
      sym__spaces,
      sym_empty_line,
  [166] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(59), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(61), 2,
      sym__spaces,
      sym_empty_line,
  [178] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(47), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(63), 2,
      sym__spaces,
      sym_empty_line,
  [190] = 2,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(65), 1,
      ts_builtin_sym_end,
  [197] = 2,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(67), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 27,
  [SMALL_STATE(5)] = 54,
  [SMALL_STATE(6)] = 74,
  [SMALL_STATE(7)] = 94,
  [SMALL_STATE(8)] = 114,
  [SMALL_STATE(9)] = 134,
  [SMALL_STATE(10)] = 154,
  [SMALL_STATE(11)] = 166,
  [SMALL_STATE(12)] = 178,
  [SMALL_STATE(13)] = 190,
  [SMALL_STATE(14)] = 197,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tone, 1, 0, 2),
  [19] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tone, 1, 0, 2),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 1, 0, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 1, 0, 1),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitch, 1, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitch, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tone, 2, 0, 4),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tone, 2, 0, 4),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 1, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 2, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bar, 1, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bar, 1, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 2, 0, 3),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 2, 0, 3),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
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
