#ifndef USERSPACE
#define USERSPACE

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "action.h"
#include "version.h"

enum userspace_layers { _WIN, _OSX, _GAME, _NAV, _SYM, _ADJ };

enum userspace_keycodes {
    MUSIC = SAFE_RANGE,
    NEW_SAFE_RANGE, // the safe range used at the board level
    // almost everything below here uses custom mapping to do an action
    TERM,
    TEAMS,
    EMAIL,
    BROWS, // open browser
    GHPRS, // open github pull requests requiring my review
    CODE,
    DISC, // open discord
    MUTE,
    SCRNS, // take screenshot (snipping on windows, flameshot on lnx, cmd+shft+4 or whatever on osx)
    OVRVW  // overview if the os supports it
};

#define TEAMS LALT(KC_P1)
#define MUSIC LALT(KC_P2)
#define TERM LALT(KC_P3)
#define BROWS LALT(KC_P5)
#define EMAIL LALT(KC_P6)
#define GHPRS LALT(KC_PENT)
#define CODE LALT(KC_P4)
#define DISC LALT(KC_PDOT)
// #define MUTE LALT(KC_P0)
#define OVRVW MEH(KC_F16)

#endif
