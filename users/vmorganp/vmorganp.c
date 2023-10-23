#include "vmorganp.h"
#include "quantum.h"

// allow for custom keymap in board still
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCRNS:
            if (record->event.pressed) {
                if (biton32(layer_state) == _OSX) {
                    tap_code16(C(S(G(KC_4))));
                } else {
                    tap_code16(S(G(KC_S)));
                }
            }
            return false;
        case MUTE:
            if (record->event.pressed) {
                if (biton32(layer_state) == _GAME) {
                    tap_code16(A(KC_P0));
                } else {
                    tap_code16(C(S(KC_M)));
                }
            }
            return false;
        default:
            return process_record_keymap(keycode, record);
    }
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_L)) {
        if (biton32(layer_state) == _OSX) {
            tap_code16(G(C(KC_Q)));
        } else {
            tap_code16(G(KC_L));
        }
    } else if (leader_sequence_two_keys(KC_P, KC_W)) {
        // work password
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_P, KC_U)) {
        // work username
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_P, KC_M)) {
        // password manager
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_P, KC_E)) {
        // email
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_P, KC_D)) {
        // da us
        SEND_STRING("fake");
    } else if (leader_sequence_two_keys(KC_O, KC_O)) {
        // open obsidian
        tap_code16(A(KC_P7));
    }
}

