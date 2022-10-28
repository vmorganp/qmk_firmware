/* Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// jiggler stuff
static uint32_t jiggle_timer = 0;

// Configuration options
#define DELTA_X_THRESHOLD 60
#define DELTA_Y_THRESHOLD 15

// safe range starts at `PLOOPY_SAFE_RANGE` instead.
bool scroll_enabled = false;
bool lock_state     = false;

// State
static int8_t delta_x = 0;
static int8_t delta_y = 0;

// Dummy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{ KC_NO }}};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scroll_enabled) {
        delta_x += mouse_report.x;
        delta_y += mouse_report.y;

        if (delta_x > DELTA_X_THRESHOLD) {
            mouse_report.h = 1;
            delta_x        = 0;
        } else if (delta_x < -DELTA_X_THRESHOLD) {
            mouse_report.h = -1;
            delta_x        = 0;
        }

        if (delta_y > DELTA_Y_THRESHOLD) {
            mouse_report.v = -1;
            delta_y        = 0;
        } else if (delta_y < -DELTA_Y_THRESHOLD) {
            mouse_report.v = 1;
            delta_y        = 0;
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// jiggly goodness
void matrix_scan_user(void) {
    if (timer_elapsed32(jiggle_timer) > 1500) {  // fast enough to keep stuff green, slow enough to not be too obnoxious
		jiggle_timer = timer_read32(); // resets timer
		tap_code(KC_MS_U);
		tap_code(KC_MS_D);
    }
}

// Scroll using caps lock
void keyboard_post_init_user(void) {
	lock_state = host_keyboard_led_state().caps_lock;
}


bool led_update_user(led_t led_state) {
	if (host_keyboard_led_state().caps_lock){
		scroll_enabled = true;
	}
	else {
		scroll_enabled = false;
	}
	return true;
}
