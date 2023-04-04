#include QMK_KEYBOARD_H

enum layers {
    _WIN,
    _OSX,
    _GAME,
    _NAV,
    _SYM,
    _ADJ
};

enum my_keycodes {
    MUSIC = SAFE_RANGE,
    TERM,
    BROWS,
    GHPRS,
    CODE,
    DISC,
    CHAT,
    MUTE,
    SCRNS,
    OVRVW
};

// Jiggle stuff
bool            mouse_jiggle_mode = true;
static uint32_t jiggle_timer      = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT(
            KC_GRV,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,   /*&&&&&&     &&&&&&*/  KC_6,       KC_7,         KC_8,         KC_9,         KC_0,            KC_BSPC,
            KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   /*&&&&&&     &&&&&&*/  KC_Y,       KC_U,         KC_I,         KC_O,         KC_P,            SCRNS,
            KC_ESC,  LCTL_T(KC_A), LGUI_T(KC_S), LSFT_T(KC_D), LOPT_T(KC_F), KC_G,   /*&&&&&&     &&&&&&*/  KC_H,       LOPT_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), LCTL_T(KC_SCLN), KC_ENT,
            KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_BSPC,     MUTE,     KC_N,       KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,
            KC_LCTL, MUTE,         _______,      KC_LGUI,      KC_LCTL,      KC_SPC, MO(_NAV),    MO(_SYM), KC_MS_BTN1, KC_MS_BTN3,   KC_MS_BTN2,   KC_CAPS,      _______,         _______
    ),

    [_OSX] = LAYOUT(
            _______, _______, _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, KC_LCTL, KC_LGUI, _______, _______,     _______, _______, _______, _______, _______, _______, _______
            ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LALT, KC_SPC,  _______, _______,     _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT(
            _______, KC_F1,    KC_F2,    KC_F3,     KC_F4,   KC_F5, /*&&&&&&     &&&&&&*/  KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,
            _______, _______,  _______,  _______,   QK_LEAD, TERM,  /*&&&&&&     &&&&&&*/  _______, _______,  _______, _______, _______, KC_F12,
            _______, _______,  CHAT,     DISC,      KC_BSPC, GHPRS, /*&&&&&&     &&&&&&*/  KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______, _______,
            _______, TO(_OSX), TO(_WIN), TO(_GAME), CODE,    BROWS, KC_DEL,      _______,  _______, MUSIC,    _______, _______, _______, _______,
            _______, _______,  _______,  _______,   _______, OVRVW, _______,     MO(_ADJ), _______, _______,  _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
            _______, _______,  _______, _______,  _______,  _______, /*&&&&&&     &&&&&&*/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
            _______, _______,  _______, _______,  _______,  _______, /*&&&&&&     &&&&&&*/ KC_PLUS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, _______,
            _______, _______,  _______, _______,  KC_DEL,   _______, /*&&&&&&     &&&&&&*/ KC_DQT,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, _______,
            _______, _______,  _______, _______,  _______,  _______, _______,     _______, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, _______, _______,
            _______, _______,  _______, _______,  _______,  _______, MO(_ADJ),    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______
    ),

    [_ADJ] = LAYOUT(
            _______, _______, _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, DM_REC1, _______, /*&&&&&&     &&&&&&*/ KC_VOLU, _______, _______, _______, DM_PLY1, _______,
            _______, _______, _______, _______, _______, _______, /*&&&&&&     &&&&&&*/ KC_VOLD, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
    )
};



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

void matrix_scan_user(void) {
    // jiggler stuff
    if (timer_elapsed32(jiggle_timer) > 9000) {  // 9 seconds
        jiggle_timer = timer_read32();           // resets timer
        if (mouse_jiggle_mode) {
            tap_code(KC_MS_U);
            tap_code(KC_MS_D);
        }  // tap if enabled
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MUSIC:
            if (record->event.pressed){
                tap_code16(A(KC_P2));
            }
            return false;

        case TERM:
                if (record->event.pressed){
                    tap_code16(A(KC_P3));
                }
            return false;

        case BROWS:
                if (record->event.pressed){
                    tap_code16(A(KC_P5));
                }
            return false;

        case GHPRS:
                if (record->event.pressed){
                    tap_code16(A(KC_PENT));
                }
            return false;

        case CODE:
                if (record->event.pressed){
                    tap_code16(A(KC_P4));
                }
            return false;

        case DISC:
                if (record->event.pressed){
                    tap_code16(A(KC_PDOT));
                }
            return false;

        case CHAT:
                if (record->event.pressed){
                    tap_code16(A(KC_P1));
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

        case SCRNS:
                if (record->event.pressed){
                    if (biton32(layer_state) == _OSX){
                        tap_code16(C(S(G(KC_4))));
                    } else {
                        tap_code16(S(G(KC_S)));
                    }
                }
            return false;

        case OVRVW:
                if (record->event.pressed){
                    tap_code16(MEH(KC_F16));
                }
            return false;

        default:
            return true; // Process all other keycodes normally
    }
}
