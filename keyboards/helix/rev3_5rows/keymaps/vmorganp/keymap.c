#include QMK_KEYBOARD_H

enum layers {
    _OSX,
    _OSXCMK,
    _WIN,
    _GAME,
    _NAV,
    _SYM,
    _ADJ
};

// Jiggle stuff
bool            mouse_jiggle_mode = true;
static uint32_t jiggle_timer      = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_OSX] = LAYOUT(
    KC_GRV,   KC_1,         KC_2,         KC_3,         KC_4,         KC_5,   /*&&&&&&     &&&&&&*/  KC_6,       KC_7,         KC_8,         KC_9,         KC_0,            KC_BSPC,
    KC_TAB,   KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   /*&&&&&&     &&&&&&*/  KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,            C(S(G(KC_4))),
    KC_ESC,   LCTL_T(KC_A), LGUI_T(KC_S), LSFT_T(KC_D), LOPT_T(KC_F), KC_G,   /*&&&&&&     &&&&&&*/  KC_H,       LOPT_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), LCTL_T(KC_SCLN), KC_ENT,
    KC_LSFT,  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_BSPC,     KC_MPLY,  KC_N,       KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
    KC_LCTL,  G(S(KC_M)),   _______,      _______,      KC_LGUI,      KC_SPC, MO(_NAV),    MO(_SYM), KC_MS_BTN1, KC_MS_BTN3,   KC_MS_BTN2,   KC_CAPS,      _______,         _______
  ),

  [_OSXCMK] = LAYOUT(
    KC_GRV,   KC_1,         KC_2,         KC_3,         KC_4,         KC_5,   /*&&&&&&     &&&&&&*/  KC_6,       KC_7,         KC_8,         KC_9,         KC_0,         KC_BSPC,
    KC_TAB,   KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,   /*&&&&&&     &&&&&&*/  KC_J,       KC_L,         KC_U,         KC_Y,         KC_SCLN,      C(S(G(KC_4))),
    KC_ESC,   LCTL_T(KC_A), LGUI_T(KC_R), LSFT_T(KC_S), LOPT_T(KC_T), KC_G,   /*&&&&&&     &&&&&&*/  KC_M,       LOPT_T(KC_N), LSFT_T(KC_E), LGUI_T(KC_I), LCTL_T(KC_O), KC_ENT,
    KC_LSFT,  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,   KC_BSPC,     KC_MPLY,  KC_K,       KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,
    KC_LCTL,  G(S(KC_M)),   _______,      _______,      KC_LGUI,      KC_SPC, MO(_NAV),    MO(_SYM), KC_MS_BTN1, KC_MS_BTN3,   KC_MS_BTN2,   KC_CAPS,      _______,      _______
  ),

  [_WIN] = LAYOUT(
    _______, _______,  _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, S(G(KC_S)),
    _______, _______,  _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, A(KC_P0), _______, KC_LGUI, KC_LCTL, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),

  [_GAME] = LAYOUT(
    _______, _______,  _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, S(G(KC_S)),
    _______, KC_A,     KC_S,    KC_D,    KC_F,    _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, A(KC_P0), _______, KC_LALT, KC_SPC,  _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT(
    _______, KC_F1,    KC_F2,    KC_F3,      KC_F4,    KC_F5,      /*&&&&&&     &&&&&&*/  KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______,  _______,  _______,    KC_LEAD,  A(KC_P3),   /*&&&&&&     &&&&&&*/  _______, _______,  _______, _______, _______, KC_F12,
    _______, A(KC_P9), A(KC_P1), A(KC_PDOT), A(KC_P5), A(KC_PENT), /*&&&&&&     &&&&&&*/  KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______, _______,
    _______, TO(_OSX), TO(_WIN), TO(_GAME),  A(KC_P4), _______,    KC_DEL,      _______,  _______, A(KC_P2), _______, _______, _______, _______,
    _______, _______,  _______,  _______,    _______,  MEH(KC_F16),_______,     MO(_ADJ), _______, _______,  _______, _______, _______, _______
  ),

  [_SYM] = LAYOUT(
    _______, _______,  _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______,  KC_7,    KC_8,    KC_9,    _______, /*&&&&&&     &&&&&&*/ KC_PLUS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, _______,
    _______, _______,  KC_4,    KC_5,    KC_6,    _______, /*&&&&&&     &&&&&&*/ KC_DQT,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, _______,
    _______, _______,  KC_1,    KC_2,    KC_3,    _______, _______,     _______, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, _______, _______,
    _______, _______,  KC_0,    _______, _______, _______, MO(_ADJ),    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______
  ),

  [_ADJ] = LAYOUT(
    _______, _______,  _______, _______,     _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
    _______, DF(_OSX), _______, _______,     DM_REC1, _______, /*&&&&&&     &&&&&&*/ KC_VOLU, _______, _______, _______, DM_PLY1, _______,
    _______, _______,  DM_RSTP, _______,     _______, _______, /*&&&&&&     &&&&&&*/ KC_VOLD, _______, _______, _______, _______, _______,
    _______, _______,  _______, DF(_OSXCMK), _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______,  _______, _______,     _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )
};

// disable jiggles if not on osx
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _OSX:
            mouse_jiggle_mode = true;
            break;
        default:  //  for any other layers, or the default layer
            mouse_jiggle_mode = false;
            break;
    }
    return state;
}

LEADER_EXTERNS();
// fancy QMK stuff
// leader dict, JIGGLER, stuff like that
void matrix_scan_user(void) {
    // jiggler stuff
    if (timer_elapsed32(jiggle_timer) > 9000) {  // 9 seconds
        jiggle_timer = timer_read32();           // resets timer
        if (mouse_jiggle_mode) {
            tap_code(KC_MS_U);
            tap_code(KC_MS_D);
        }  // tap if enabled
    }

    // leader key
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
    // switch hands at some point in thefuture
        // maybe???

    // dynamic macros???
        // maybe?? probably not. Abandon all hope, ye who enter here

    // general stuff
        // mute
        SEQ_ONE_KEY(KC_M) {
            tap_code16(A(KC_P0));
        }

        // jiggler
        SEQ_ONE_KEY(KC_J) {
            mouse_jiggle_mode ^= true;
        }

        // lock
        SEQ_ONE_KEY(KC_L) {
            if (biton32(layer_state) == _OSX){
                tap_code16(G(C(KC_Q)));
            }
            else{
                tap_code16(G(KC_L));
            }
        }

    // passwords
        // work (Password work)
        SEQ_TWO_KEYS(KC_P, KC_W) {
            SEND_STRING("fake");
        }
        // work (password, username)
        SEQ_TWO_KEYS(KC_P, KC_U) {
            SEND_STRING("fake");
        }
        // bitwarden (Password Manager)
        SEQ_TWO_KEYS(KC_P, KC_M) {
            SEND_STRING("fake");
        }

    // media
        // next media
        SEQ_TWO_KEYS(KC_M, KC_N) {
            tap_code(KC_MNXT);
        }

        // pause/play media
        SEQ_TWO_KEYS(KC_M, KC_P) {
            tap_code(KC_MPLY);
        }

        // last media
        SEQ_TWO_KEYS(KC_M, KC_L) {
            tap_code(KC_MPRV);
        }

    // applications
        // discord
        SEQ_TWO_KEYS(KC_O, KC_D) {
            tap_code16(A(KC_PDOT));
        }

        // firefox
        SEQ_TWO_KEYS(KC_O, KC_F) {
            tap_code16(A(KC_P5));
        }

        // github
        SEQ_TWO_KEYS(KC_O, KC_G) {
            tap_code16(A(KC_KP_ENTER));
        }

        // music
        SEQ_TWO_KEYS(KC_O, KC_M) {
            tap_code16(A(KC_P2));
        }

        // teams
        SEQ_TWO_KEYS(KC_O, KC_S) {
            tap_code16(A(KC_P1));
        }

        // terminal
        SEQ_TWO_KEYS(KC_O, KC_T) {
            tap_code16(A(KC_P3));
        }

        //vscode
        SEQ_TWO_KEYS(KC_O, KC_V) {
            tap_code16(A(KC_P4));
        }

        // email
        SEQ_TWO_KEYS(KC_O, KC_E) {
            tap_code16(A(KC_P6));
        }

        // obsidian
        SEQ_TWO_KEYS(KC_O, KC_O) {
            tap_code16(A(KC_P7));
        }

        // signal
        SEQ_TWO_KEYS(KC_O, KC_C) {
            tap_code16(A(KC_P8));
        }
    }
}
