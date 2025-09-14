#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 18
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 0
#define TOKEN_COUNT 37
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 7

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
  sym_acc_sharp = 14,
  sym_acc_flat = 15,
  sym_acc_natural = 16,
  sym_acc_double_sharp = 17,
  sym_acc_double_flat = 18,
  sym_p_one = 19,
  sym_p_two = 20,
  sym_p_three = 21,
  sym_p_four = 22,
  sym_p_five = 23,
  sym_p_six = 24,
  sym_p_seven = 25,
  sym_rest = 26,
  sym_lower = 27,
  sym_higher = 28,
  sym_d_dotted_semiquaver = 29,
  sym_d_semiquaver = 30,
  sym_d_dotted_quaver = 31,
  sym_d_quaver = 32,
  sym_d_dotted_crotchet = 33,
  sym_d_semibreve = 34,
  sym_d_dotted_minim = 35,
  sym_d_minim = 36,
  sym_source_file = 37,
  sym__seps = 38,
  sym__line = 39,
  sym__elm = 40,
  sym_bar = 41,
  sym_note = 42,
  sym_pitch = 43,
  sym__acc = 44,
  sym__pitch_class = 45,
  sym_tone = 46,
  sym__octave = 47,
  sym__duraion = 48,
  aux_sym__line_repeat1 = 49,
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
  [sym_acc_sharp] = "acc_sharp",
  [sym_acc_flat] = "acc_flat",
  [sym_acc_natural] = "acc_natural",
  [sym_acc_double_sharp] = "acc_double_sharp",
  [sym_acc_double_flat] = "acc_double_flat",
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
  [sym__acc] = "_acc",
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
  [sym_acc_sharp] = sym_acc_sharp,
  [sym_acc_flat] = sym_acc_flat,
  [sym_acc_natural] = sym_acc_natural,
  [sym_acc_double_sharp] = sym_acc_double_sharp,
  [sym_acc_double_flat] = sym_acc_double_flat,
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
  [sym__acc] = sym__acc,
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
  [sym_acc_sharp] = {
    .visible = true,
    .named = true,
  },
  [sym_acc_flat] = {
    .visible = true,
    .named = true,
  },
  [sym_acc_natural] = {
    .visible = true,
    .named = true,
  },
  [sym_acc_double_sharp] = {
    .visible = true,
    .named = true,
  },
  [sym_acc_double_flat] = {
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
  [sym__acc] = {
    .visible = false,
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
  field_acc = 1,
  field_duration = 2,
  field_octave = 3,
  field_pitch = 4,
  field_pitch_class = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_acc] = "acc",
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
  [5] = {.index = 6, .length = 2},
  [6] = {.index = 8, .length = 3},
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
    {field_acc, 0},
    {field_pitch, 1},
  [6] =
    {field_octave, 1},
    {field_pitch_class, 0},
  [8] =
    {field_acc, 0},
    {field_duration, 2},
    {field_pitch, 1},
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
  [15] = 15,
  [16] = 16,
  [17] = 17,
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
        '#', 22,
        '%', 1,
        '\'', 36,
        '(', 8,
        ')', 9,
        ',', 35,
        '.', 41,
        '0', 34,
        '1', 27,
        '2', 28,
        '3', 29,
        '4', 30,
        '5', 31,
        '6', 32,
        '7', 33,
        ':', 4,
        '=', 24,
        '[', 5,
        '\\', 40,
        'b', 23,
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
      if (lookahead == '-') ADVANCE(43);
      END_STATE();
    case 3:
      if (lookahead == '-') ADVANCE(42);
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
      if (lookahead == '-') ADVANCE(44);
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
      ACCEPT_TOKEN(sym_acc_sharp);
      if (lookahead == '#') ADVANCE(25);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_acc_flat);
      if (lookahead == 'b') ADVANCE(26);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_acc_natural);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_acc_double_sharp);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_acc_double_flat);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_p_one);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_p_two);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_p_three);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_p_four);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_p_five);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_p_six);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_p_seven);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_rest);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_lower);
      if (lookahead == ',') ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_higher);
      if (lookahead == '\'') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_d_dotted_semiquaver);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_d_semiquaver);
      if (lookahead == '.') ADVANCE(37);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_d_dotted_quaver);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_d_quaver);
      if (lookahead == '.') ADVANCE(39);
      if (lookahead == '\\') ADVANCE(38);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_d_dotted_crotchet);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_d_semibreve);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_d_dotted_minim);
      if (lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 44:
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
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
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
    [sym_acc_sharp] = ACTIONS(1),
    [sym_acc_flat] = ACTIONS(1),
    [sym_acc_natural] = ACTIONS(1),
    [sym_acc_double_sharp] = ACTIONS(1),
    [sym_acc_double_flat] = ACTIONS(1),
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
    [sym_source_file] = STATE(16),
    [sym__line] = STATE(17),
    [sym__elm] = STATE(9),
    [sym_bar] = STATE(9),
    [sym_note] = STATE(9),
    [sym_pitch] = STATE(4),
    [sym__acc] = STATE(8),
    [sym__pitch_class] = STATE(3),
    [sym_tone] = STATE(6),
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
    [sym_acc_sharp] = ACTIONS(11),
    [sym_acc_flat] = ACTIONS(11),
    [sym_acc_natural] = ACTIONS(13),
    [sym_acc_double_sharp] = ACTIONS(13),
    [sym_acc_double_flat] = ACTIONS(13),
    [sym_p_one] = ACTIONS(15),
    [sym_p_two] = ACTIONS(15),
    [sym_p_three] = ACTIONS(15),
    [sym_p_four] = ACTIONS(15),
    [sym_p_five] = ACTIONS(15),
    [sym_p_six] = ACTIONS(15),
    [sym_p_seven] = ACTIONS(15),
    [sym_rest] = ACTIONS(17),
  },
  [2] = {
    [sym__elm] = STATE(14),
    [sym_bar] = STATE(14),
    [sym_note] = STATE(14),
    [sym_pitch] = STATE(4),
    [sym__acc] = STATE(8),
    [sym__pitch_class] = STATE(3),
    [sym_tone] = STATE(6),
    [sym_leftparen] = ACTIONS(19),
    [sym_rightparen] = ACTIONS(19),
    [sym__comments] = ACTIONS(3),
    [sym_bar_standard] = ACTIONS(7),
    [sym_bar_double] = ACTIONS(9),
    [sym_bar_beg] = ACTIONS(9),
    [sym_bar_end] = ACTIONS(9),
    [sym_bar_beg_repeat] = ACTIONS(9),
    [sym_bar_end_repeat] = ACTIONS(9),
    [sym_bar_begend_repeat] = ACTIONS(9),
    [sym_acc_sharp] = ACTIONS(11),
    [sym_acc_flat] = ACTIONS(11),
    [sym_acc_natural] = ACTIONS(13),
    [sym_acc_double_sharp] = ACTIONS(13),
    [sym_acc_double_flat] = ACTIONS(13),
    [sym_p_one] = ACTIONS(15),
    [sym_p_two] = ACTIONS(15),
    [sym_p_three] = ACTIONS(15),
    [sym_p_four] = ACTIONS(15),
    [sym_p_five] = ACTIONS(15),
    [sym_p_six] = ACTIONS(15),
    [sym_p_seven] = ACTIONS(15),
    [sym_rest] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(3), 1,
      sym__comments,
    STATE(7), 1,
      sym__octave,
    ACTIONS(25), 2,
      sym_lower,
      sym_higher,
    ACTIONS(21), 6,
      ts_builtin_sym_end,
      sym_tilde,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(23), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [27] = 6,
    ACTIONS(3), 1,
      sym__comments,
    STATE(13), 1,
      sym__duraion,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(29), 2,
      sym__spaces,
      sym_empty_line,
    ACTIONS(31), 4,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(33), 4,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [54] = 6,
    ACTIONS(3), 1,
      sym__comments,
    STATE(15), 1,
      sym__duraion,
    ACTIONS(35), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(37), 2,
      sym__spaces,
      sym_empty_line,
    ACTIONS(39), 4,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(41), 4,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [81] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(43), 6,
      ts_builtin_sym_end,
      sym_tilde,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(45), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [101] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(47), 6,
      ts_builtin_sym_end,
      sym_tilde,
      sym_d_dotted_semiquaver,
      sym_d_dotted_quaver,
      sym_d_dotted_crotchet,
      sym_d_semibreve,
    ACTIONS(49), 6,
      sym__spaces,
      sym_empty_line,
      sym_d_semiquaver,
      sym_d_quaver,
      sym_d_dotted_minim,
      sym_d_minim,
  [121] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(17), 1,
      sym_rest,
    STATE(3), 1,
      sym__pitch_class,
    STATE(5), 1,
      sym_pitch,
    STATE(6), 1,
      sym_tone,
    ACTIONS(15), 7,
      sym_p_one,
      sym_p_two,
      sym_p_three,
      sym_p_four,
      sym_p_five,
      sym_p_six,
      sym_p_seven,
  [146] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
    ACTIONS(53), 1,
      sym_tilde,
    STATE(2), 1,
      sym__seps,
    STATE(10), 1,
      aux_sym__line_repeat1,
    ACTIONS(55), 2,
      sym__spaces,
      sym_empty_line,
  [166] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(53), 1,
      sym_tilde,
    ACTIONS(57), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym__seps,
    STATE(11), 1,
      aux_sym__line_repeat1,
    ACTIONS(55), 2,
      sym__spaces,
      sym_empty_line,
  [186] = 6,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    ACTIONS(61), 1,
      sym_tilde,
    STATE(2), 1,
      sym__seps,
    STATE(11), 1,
      aux_sym__line_repeat1,
    ACTIONS(64), 2,
      sym__spaces,
      sym_empty_line,
  [206] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(67), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(69), 2,
      sym__spaces,
      sym_empty_line,
  [218] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(71), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(73), 2,
      sym__spaces,
      sym_empty_line,
  [230] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(59), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(75), 2,
      sym__spaces,
      sym_empty_line,
  [242] = 3,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(77), 2,
      ts_builtin_sym_end,
      sym_tilde,
    ACTIONS(79), 2,
      sym__spaces,
      sym_empty_line,
  [254] = 2,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
  [261] = 2,
    ACTIONS(3), 1,
      sym__comments,
    ACTIONS(83), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 27,
  [SMALL_STATE(5)] = 54,
  [SMALL_STATE(6)] = 81,
  [SMALL_STATE(7)] = 101,
  [SMALL_STATE(8)] = 121,
  [SMALL_STATE(9)] = 146,
  [SMALL_STATE(10)] = 166,
  [SMALL_STATE(11)] = 186,
  [SMALL_STATE(12)] = 206,
  [SMALL_STATE(13)] = 218,
  [SMALL_STATE(14)] = 230,
  [SMALL_STATE(15)] = 242,
  [SMALL_STATE(16)] = 254,
  [SMALL_STATE(17)] = 261,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tone, 1, 0, 2),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tone, 1, 0, 2),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 1, 0, 1),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 1, 0, 1),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 2, 0, 4),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 2, 0, 4),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pitch, 1, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pitch, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tone, 2, 0, 5),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tone, 2, 0, 5),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 2, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bar, 1, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bar, 1, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 2, 0, 3),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 2, 0, 3),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_note, 3, 0, 6),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_note, 3, 0, 6),
  [81] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
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
