#include QMK_KEYBOARD_H

enum sofle_layers {
    _WIN,
    _OSX,
    _GAME,
    _SYM,
    _NAV,
    _ADJ
};

enum custom_keycodes {
    CHAT = SAFE_RANGE,
    TEAMS,
    TERM,
    GHPRS,
    MUSIC,
    VSCDE,
    BRWSR,
    EMAIL,
    OVRVW,
    MUTE,
    SCRNS,
    SPONGE
};

bool            mouse_jiggle_mode = true;
static uint32_t jiggle_timer      = 0;

// bool that holds the current state on or off
bool is_sponge_active = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_WIN] = LAYOUT(
  KC_GRV,   KC_1,         KC_2,         KC_3,         KC_4,         KC_5,   /*&&&&&&    &&&&&&*/  KC_6,       KC_7,         KC_8,         KC_9,         KC_0,            KC_BSPC,
  KC_TAB,   KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   /*&&&&&&    &&&&&&*/  KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,            SCRNS,
  KC_ESC,   LCTL_T(KC_A), LGUI_T(KC_S), LSFT_T(KC_D), LOPT_T(KC_F), KC_G,   /*&&&&&&    &&&&&&*/  KC_H,       LOPT_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), LCTL_T(KC_SCLN), KC_ENT,
  KC_LSFT,  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   _______,    KC_MPLY,  KC_N,       KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
                          MUTE,         KC_LGUI,      KC_LCTL,      KC_SPC, MO(_NAV),   MO(_SYM), KC_MS_BTN1, KC_MS_BTN3,   KC_MS_BTN2,   KC_CAPS
),

[_OSX] = LAYOUT(
  _______, _______, _______, _______, _______, _______, /*&&&&&&    &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, /*&&&&&&    &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, /*&&&&&&    &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                    _______, KC_LCTL, KC_LGUI, _______, _______,    _______, _______, _______, _______, _______
),

[_GAME] = LAYOUT(
  KC_GRV,  KC_1,    KC_2, KC_3,    KC_4,    KC_5,   /*&&&&&&    &&&&&&*/  KC_6,       KC_7,         KC_8,         KC_9,         KC_0,            KC_BSPC,
  KC_TAB,  KC_Q,    KC_W, KC_E,    KC_R,    KC_T,   /*&&&&&&    &&&&&&*/  KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,            SCRNS,
  KC_ESC,  KC_A,    KC_S, KC_D,    KC_F,    KC_G,   /*&&&&&&    &&&&&&*/  KC_H,       LOPT_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), LCTL_T(KC_SCLN), KC_ENT,
  KC_LSFT, KC_Z,    KC_X, KC_C,    KC_V,    KC_B,   KC_MPLY,    _______,  KC_N,       KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
                    MUTE, KC_LGUI, KC_LCTL, KC_SPC, MO(_NAV),   MO(_SYM), KC_MS_BTN1, KC_MS_BTN3,   KC_MS_BTN2,   KC_CAPS
),

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______, /*&&&&&&    &&&&&&*/ KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, /*&&&&&&    &&&&&&*/ KC_PLUS, KC_EQL,   KC_LCBR, KC_RCBR,  KC_PIPE, _______,
  _______, _______, _______, _______, KC_DEL,  _______, /*&&&&&&    &&&&&&*/ KC_DQT,  KC_QUOT,  KC_LBRC, KC_RBRC,  KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, KC_UNDS, KC_MINUS, KC_LPRN, KC_RPRN,  _______, _______,
                    _______, _______, _______, _______, MO(_ADJ),   _______, KC_MPRV, KC_MPLY,  KC_MNXT, _______
),

[_NAV] = LAYOUT(
  _______, KC_F1,    KC_F2,    KC_F3,     KC_F4,   KC_F5, /*&&&&&&    &&&&&&*/  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______,  _______,   EMAIL,    QK_LEAD, TERM,  /*&&&&&&    &&&&&&*/  _______, _______, _______, _______, _______, KC_F12,
  _______, _______,  TEAMS,    CHAT,      KC_BSPC, GHPRS, /*&&&&&&    &&&&&&*/  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, TO(_OSX), TO(_WIN), TO(_GAME), VSCDE,   BRWSR, _______,    _______,  _______, MUSIC,   _______, _______, _______, _______,
                     _______,  _______,   _______, OVRVW, _______,    MO(_ADJ), _______, _______, _______, _______
),

[_ADJ] = LAYOUT(
  _______, _______, _______, _______, _______, _______, /*&&&&&&    &&&&&&*/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, DM_PLY1, _______, /*&&&&&&    &&&&&&*/ KC_VOLU, _______, _______, _______, _______, _______,
  _______, SPONGE,  DM_REC1, DM_RSTP, _______, _______, /*&&&&&&    &&&&&&*/ KC_VOLD, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
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
    switch (biton32(layer_state)) {
        case _OSX:
            render_apl_icon();
            break;
        case _WIN:
            render_win_icon();
            break;
        case _GAME:
            render_game_icon();
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYM\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("JIGLE"), mouse_jiggle_mode);
    oled_write_ln_P(PSTR("SPNGE"), is_sponge_active);
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
    if (is_sponge_active && record->event.pressed) {
        tap_code(KC_CAPS_LOCK);
    }
    switch (keycode) {
        case SPONGE:
            if (record->event.pressed){
                is_sponge_active = !is_sponge_active;
                    // if turning off, also turn off caps lock
                if (!is_sponge_active){
                    if (host_keyboard_led_state().caps_lock){
                        tap_code(KC_CAPS_LOCK);
                    }
                }
            }
            return false;

        case EMAIL:
            if (record->event.pressed){
                tap_code16(A(KC_P6)); 
            }
            return false;
        case CHAT:
            if (record->event.pressed){
                tap_code16(A(KC_PDOT)); 
            }
            return false;
        case TEAMS:
            if (record->event.pressed){
                tap_code16(A(KC_P1)); 
            }
            return false;
        case TERM:
            if (record->event.pressed){
                tap_code16(A(KC_P3)); 
            }
            return false;
        case GHPRS:
            if (record->event.pressed){
                tap_code16(A(KC_KP_ENTER)); 
            }
            return false;
        case MUSIC:
            if (record->event.pressed){
                tap_code16(A(KC_P2)); 
            }
            return false;
        case VSCDE:
            tap_code16(A(KC_P4)); 
            return false;
        case BRWSR:
            if (record->event.pressed){
                tap_code16(A(KC_P5));
            }
            return false;
        case OVRVW:
            if (record->event.pressed){
                tap_code16(MEH(KC_F16));
            }
            return false;
        case SCRNS:
            if (record->event.pressed){
                if (biton32(layer_state) == _OSX)  {
                    tap_code16(C(S(G(KC_4))));
                }
                else {
                    tap_code16(S(G(KC_S)));
                }
            }
            return false;
        case MUTE:
            if (record->event.pressed){
                if (biton32(layer_state) == _GAME)  {
                    tap_code16(A(KC_P0));
                }
                else {
                    tap_code16(C(S(KC_M)));
                }
            }
            return false;
        default:
            return true;
    }
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        case _GAME:
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

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_L)) {
        if (biton32(layer_state) == _OSX){
            tap_code16(G(C(KC_Q)));
        }
        else{
            tap_code16(G(KC_L));
        }
    } else if (leader_sequence_two_keys(KC_P, KC_W)) {
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_P, KC_U)) {
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_P, KC_M)) {
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_P, KC_E)) {
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_O, KC_O)) {
        tap_code16(A(KC_P7));
    }
}

void matrix_scan_user(void) {
    // jiggler stuff
    if (timer_elapsed32(jiggle_timer) > 9000) {  // 9 seconds
        jiggle_timer = timer_read32();           // resets timer
        if (mouse_jiggle_mode) {
            tap_code(KC_MS_U);
            tap_code(KC_MS_D);
        } 
    }
}

