/* Copyright 2017 Wunder
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

// Layer shorthand
#define _QW 0
#define _FN 1
#define _MV 3

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_Q:
        if (record->event.pressed) {
            if (keyboard_report->mods & MOD_BIT(KC_LCMD) || keyboard_report->mods & MOD_BIT(KC_RCMD)){
                register_code(KC_TAB);
                return false;
            }
        } else {
            if (keyboard_report->mods & MOD_BIT(KC_LCMD) || keyboard_report->mods & MOD_BIT(KC_RCMD)){
                unregister_code(KC_TAB);
                return false;
            }
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ` ~    | 1      | 2      | 3      | 4      | 5      |        |        | 6      | 7      | 8      | 9      | 0      | - _    | = +    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |        |        | Y      | U      | I      | O      | P      | [ {    | ] }    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CTL/ESC| A      | S      | D      | F      | G      |        |        | H      | J      | K      | L      | ; L2   | ' "    | \ |    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | SHFT/Z | X      | C      | V      | B      |        |        | N      | M      | , <    | . >    | / ?    | ENTER  | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        | DEL    | CTRL   | ALT/ESC| CMD    | CMD/BS | CTL/TAB| HYP/ENT| L1/SPC | L1     | BS     | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,         KC_1,         KC_2,    KC_3,           KC_4,    KC_5,            KC_NO,          KC_NO,          KC_6,            KC_7,    KC_8,    KC_9,    KC_0,             KC_MINS, KC_PLUS,
    KC_TAB,         KC_Q,         KC_W,    KC_E,           KC_R,    KC_T,            KC_NO,          KC_NO,          KC_Y,            KC_U,    KC_I,    KC_O,    KC_P,             KC_LBRC, KC_RBRC,
    LCTL_T(KC_ESC), KC_A,         KC_S,    KC_D,           KC_F,    KC_G,            KC_NO,          KC_NO,          KC_H,            KC_J,    KC_K,    KC_L,    LT(_MV, KC_SCLN), KC_QUOT, KC_BSLS,
    KC_LSFT,        LSFT_T(KC_Z), KC_X,    KC_C,           KC_V,    KC_B,            KC_NO,          KC_NO,          KC_N,            KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),  KC_ENT,  KC_RSFT,
    KC_NO,          KC_DEL,       KC_LCTL, LOPT_T(KC_ESC), KC_LCMD, LCMD_T(KC_BSPC), LCTL_T(KC_TAB), HYPR_T(KC_ENT), LT(_FN, KC_SPC), MO(_FN), KC_BSPC, KC_LEFT, KC_DOWN,          KC_UP,   KC_RGHT
  ),
/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 1 !    | 2 @    | 3 #    | 4 $    | 5 %    |        |        | 6 ^    | 7 &    | 8 *    | 9 (    | 0 )    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F1     | F2     | F3     | F4     | F5     |        |        | F6     | - _    | = +    | ` ~    | ' "    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    |        |        | F12    |        | [ {    | ] }    | SHFT\| |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_TRNS, KC_TRNS, KC_6,     KC_7,    KC_8,    KC_9,    KC_0,            KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_TRNS, KC_TRNS, KC_F6,    KC_MINS, KC_EQL,  KC_GRV,  KC_QUOT,         KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_TRNS, KC_TRNS, KC_F12,   KC_TRNS, KC_LBRC, KC_RBRC, RSFT_T(KC_BSLS), KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS
  ),
/* MOVEMENT
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | MU     | M3     |        |        |        | HOME   | END    | PGDN   | PGUP   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | M1     | ML     | MD     | MR     | M2     |        |        | LEFT   | DOWN   | UP     | RIGHT  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | PREV   | STOP   | PLAY   | NEXT   |        |        | Br-    | Br+    | Vol-   | Vol+   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
  [_MV] = LAYOUT_ortho_5x15( /* MOVEMENT */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END,  KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
