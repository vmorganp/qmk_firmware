#include QMK_KEYBOARD_H
// flash with
// make keebio/bfo9000:morgan:flash
// qmk flash -kb keebio/bfo9000 -km vmorganpgaming
enum bfo900_layers { _OSX, _WIN, _NAV, _SYM, _GAME };
enum bfo9000_keycodes { JIGGLER = SAFE_RANGE, SCRNSHT};

// jiggler items
bool            mouse_jiggle_mode = true;
static uint32_t jiggle_timer      = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_OSX] = LAYOUT(
		KC_ESC,  KC_6,        KC_7,        KC_8,        KC_9,        KC_0,    KC_VOLU,  _______, _______,     /*&&&&&&&&&&&&&&*/    _______,  KC_F6,      KC_F7,       KC_F8,       KC_F9,       KC_F10,         KC_F11,  KC_F12,  _______,
		KC_GRV,  KC_1,        KC_2,        KC_3,        KC_4,        KC_5,    KC_VOLD,  SCRNSHT, A(KC_P0),    /*&&&&&&&&&&&&&&*/    _______,  KC_6,       KC_7,        KC_8,        KC_9,        KC_0,           KC_BSPC, _______, _______,
		KC_TAB,  KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,    KC_MPRV,  KC_MPLY, KC_MNXT,     /*&&&&&&&&&&&&&&*/    _______,  KC_Y,       KC_U,        KC_I,        KC_O,        KC_P,           SCRNSHT, _______, _______,
		KC_ESC,  CTL_T(KC_A), GUI_T(KC_S), SFT_T(KC_D), OPT_T(KC_F), KC_G,    DM_PLY1,  DM_REC1, DM_RSTP,     /*&&&&&&&&&&&&&&*/    _______,  KC_H,       OPT_T(KC_J), SFT_T(KC_K), GUI_T(KC_L), CTL_T(KC_SCLN), KC_ENT,  _______, _______,
		KC_LSFT, KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,    KC_BSPC,  _______, _______,     /*&&&&&&&&&&&&&&*/    _______,  KC_N,       KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,        KC_RSFT, _______, _______,
		KC_LCTL, _______,     KC_LCTL,     KC_LALT,     KC_LGUI,     KC_SPC,  MO(_NAV), _______, _______,     /*&&&&&&&&&&&&&&*/    MO(_SYM), KC_MS_BTN1, KC_MS_BTN3,  KC_MS_BTN2,  KC_CAPS,     _______,        _______, _______, _______
	),
	[_NAV] = LAYOUT(
		_______, KC_F6,    KC_F7,    KC_F8,      KC_F9,    KC_F10,      _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, _______, _______,  _______, _______, _______, _______, _______, _______,
		_______, KC_F1,    KC_F2,    KC_F3,      KC_F4,    KC_F5,       _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, _______, _______,  _______, _______, _______, _______, _______, _______,
		_______, _______,  _______,  _______,    KC_LEAD,  A(KC_P3),    _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, _______, _______,  _______, _______, _______, _______, _______, _______,
		_______, A(KC_P9), A(KC_P1), A(KC_PDOT), A(KC_P5), _______,     _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______, _______, _______, _______,
		_______, TO(_OSX), TO(_WIN), TO(_GAME),  A(KC_P4), _______,     KC_DEL,  _______, _______,    /*&&&&&&&&&&&&&&*/    _______, _______, A(KC_P2), _______, _______, _______, _______, _______, _______,
		_______, _______,  _______,  _______,    _______,  MEH(KC_F16), _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, _______, _______,  _______, _______, _______, _______, _______, _______
	),
	[_SYM] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, KC_PLUS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, KC_DQT,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,    /*&&&&&&&&&&&&&&*/    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______
	),
	[_WIN] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, KC_LALT, KC_LGUI, KC_LCTL, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______
	),
	[_GAME] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, KC_LALT, KC_LALT, KC_SPC,  _______, _______, _______, _______,     /*&&&&&&&&&&&&&&*/     _______, _______, _______, _______, _______, _______, _______, _______, _______
	)
};

// fancy macro shit is going in here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCRNSHT:
            if (record->event.pressed) {
                switch (biton32(layer_state)) {
                    case _OSX:
                        tap_code16(C(S(G(KC_4))));
                        break;
                    default:
                    tap_code16(S(G(KC_S)));
                }
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

// required for leader key per https://docs.qmk.fm/#/feature_leader_key
LEADER_EXTERNS();

void matrix_scan_user(void) {
		// jiggler stuff
		if (timer_elapsed32(jiggle_timer) > 12000) {  // 12 seconds
				jiggle_timer = timer_read32();           // resets timer
				if (mouse_jiggle_mode) {
						tap_code(KC_MS_U);
						tap_code(KC_MS_D);
				}
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
