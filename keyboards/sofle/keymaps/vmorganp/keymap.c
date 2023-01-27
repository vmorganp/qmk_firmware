#include QMK_KEYBOARD_H

enum sofle_layers {
    _OSX,
    _OSXCMK,
    _WINDOWS,
    _GAMING,
    _NAV,
    _SYMBOLS,
    _ADJUST,
};

enum custom_keycodes {
    JIGGLER = SAFE_RANGE,
};

bool            mouse_jiggle_mode = true;
static uint32_t jiggle_timer      = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_OSX] = LAYOUT(
  KC_GRV,   KC_1,         KC_2,             KC_3,         KC_4,         KC_5,   /*&&&&&&     &&&&&&*/      KC_6,       KC_7,         KC_8,         KC_9,         KC_0,            KC_BSPC,
  KC_TAB,   KC_Q,         KC_W,             KC_E,         KC_R,         KC_T,   /*&&&&&&     &&&&&&*/      KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,            LCTL(LSFT(LGUI(KC_4))),
  KC_ESC,   LCTL_T(KC_A), LGUI_T(KC_S),     LSFT_T(KC_D), LOPT_T(KC_F), KC_G,   /*&&&&&&     &&&&&&*/      KC_H,       LOPT_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), LCTL_T(KC_SCLN), KC_ENT,
  KC_LSFT,  KC_Z,         KC_X,             KC_C,         KC_V,         KC_B,   _______,     KC_MPLY,      KC_N,       KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
                          LGUI(LSFT(KC_M)), KC_LCTL,      KC_LGUI,      KC_SPC, MO(_NAV),    MO(_SYMBOLS), KC_MS_BTN1, KC_MS_BTN3,   KC_MS_BTN2,   KC_CAPS 
),
[_OSXCMK] = LAYOUT(
  KC_GRV,   KC_1,         KC_2,             KC_3,         KC_4,         KC_5,   /*&&&&&&     &&&&&&*/      KC_6,       KC_7,         KC_8,         KC_9,         KC_0,         KC_BSPC,
  KC_TAB,   KC_Q,         KC_W,             KC_F,         KC_P,         KC_B,   /*&&&&&&     &&&&&&*/      KC_J,       KC_L,         KC_U,         KC_Y,         KC_SCLN,      LCTL(LSFT(LGUI(KC_4))),
  KC_ESC,   LCTL_T(KC_A), LGUI_T(KC_R),     LSFT_T(KC_S), LOPT_T(KC_T), KC_G,   /*&&&&&&     &&&&&&*/      KC_M,       LOPT_T(KC_N), LSFT_T(KC_E), LGUI_T(KC_I), LCTL_T(KC_O), KC_ENT,
  KC_LSFT,  KC_Z,         KC_X,             KC_C,         KC_D,         KC_V,   _______,     KC_MPLY,      KC_K,       KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,
                          LGUI(LSFT(KC_M)), KC_LCTL,      KC_LGUI,      KC_SPC, MO(_NAV),    MO(_SYMBOLS), KC_MS_BTN1, KC_MS_BTN3,   KC_MS_BTN2,   KC_CAPS 
),

[_WINDOWS] = LAYOUT(
  _______, _______, _______,  _______, _______, _______, /*&&&&&&   &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, /*&&&&&&   &&&&&&*/ _______, _______, _______, _______, _______, LSFT(LGUI(KC_S)),
  _______, _______, _______,  _______, _______, _______, /*&&&&&&   &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                    A(KC_P0), KC_LGUI, KC_LCTL, KC_SPC,  _______,   _______, _______, _______, _______, _______ 
),

[_GAMING] = LAYOUT(
  _______, _______, _______,  _______, _______, _______, /*&&&&&&   &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, /*&&&&&&   &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, KC_A,    KC_S,     KC_D,    KC_F,    _______, /*&&&&&&   &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______, _______, KC_MPLY,   _______, _______, _______, _______, _______, _______, _______,
                    _______,  KC_LCTL, KC_SPC,  KC_SPC,  _______,   _______, _______, _______, _______, _______ 
),

[_NAV] = LAYOUT(
  _______, KC_F1,    KC_F2,        KC_F3,       KC_F4,    KC_F5,          /*&&&&&&   &&&&&&*/     KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______,  _______,      A(KC_P6),    KC_LEAD,  A(KC_P3),       /*&&&&&&   &&&&&&*/     _______, _______,  _______, _______, _______, KC_F12,
  _______, A(KC_P9), A(KC_P1),     A(KC_PDOT),  KC_BSPC,  A(KC_KP_ENTER), /*&&&&&&   &&&&&&*/     KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______, _______,
  _______, TO(_OSX), TO(_WINDOWS), TO(_GAMING), A(KC_P4), A(KC_P5),       _______,   _______,     _______, A(KC_P2), _______, _______, _______, _______,
                     _______,      _______,     _______,  MEH(KC_F16),    _______,   MO(_ADJUST), _______, _______,  _______, _______
),

[_SYMBOLS] = LAYOUT(
  _______, _______, _______, _______, _______, _______, /*&&&&&&       &&&&&&*/ KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, S(KC_0), _______,
  _______, _______, _______, _______, _______, _______, /*&&&&&&       &&&&&&*/ KC_PLUS, KC_EQL,   KC_LCBR, KC_RCBR,  KC_PIPE, _______,
  _______, _______, _______, _______, KC_DEL,  _______, /*&&&&&&       &&&&&&*/ KC_DQT,  KC_QUOT,  KC_LBRC, KC_RBRC,  KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______,       _______, KC_UNDS, KC_MINUS, KC_LPRN, KC_RPRN,  _______, _______, 
                    _______, _______, _______, _______, MO(_ADJUST),   _______, KC_MPRV, KC_MPLY,  KC_MNXT, _______ 
),

[_ADJUST] = LAYOUT(
  _______, _______,  _______, _______,     _______, _______, /*&&&&&&   &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, DF(_OSX), _______, _______,     DM_REC1, _______, /*&&&&&&   &&&&&&*/ KC_VOLU, _______, _______, _______, DM_PLY1, _______,
  _______, _______,  DM_RSTP, _______,     _______, _______, /*&&&&&&   &&&&&&*/ KC_VOLD, JIGGLER, _______, _______, _______, _______,
  _______, _______,  _______, DF(_OSXCMK), _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                     _______, _______,     _______, _______, _______,   _______, _______, _______, _______, _______ 
  )
};

#ifdef OLED_ENABLE

static void render_qmk_icon(void) {
    static const char PROGMEM qmk_icon[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_icon, false);
}

static void render_apl_icon(void) {
    static const char PROGMEM osxicon[] = {
        149,150,10,
        181,182,0
    };
    oled_write_P(osxicon, false);
}

static void render_win_icon(void) {
    static const char PROGMEM winicon[] = {
        151,152,10,
        183,184,0
    };
    oled_write_P(winicon, false);
}


static void render_game_icon(void) {
    static const char PROGMEM winicon[] = {
        3,4,10,
        5,6,0
    };
    oled_write_P(winicon, false);
}

static void print_status_narrow(void) {
    // switch (get_highest_layer(default_layer_state)) {
    switch (biton32(layer_state)) {
        case _OSX:
            render_apl_icon();
            break;
        case _WINDOWS:
            render_win_icon();
            break;
        case _GAMING:
            render_game_icon();
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _OSX:
        case _WINDOWS:
        case _GAMING:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _OSXCMK:
            oled_write_P(PSTR("Cole\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("JIGLE"), mouse_jiggle_mode);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_qmk_icon();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JIGGLER:
            if (record->event.pressed) {
                mouse_jiggle_mode ^= true;
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        case _GAMING:
            // left encoder
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                // right encoder
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
            }
            break;
        default:
            // right encoder
            if (index == 1) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                // left encoder
            } else if (index == 0) {
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
            }
            break;
    }
    return true;
}

#endif

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

    // passwods
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
