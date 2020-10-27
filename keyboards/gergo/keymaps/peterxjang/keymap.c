/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOVE 2 // motion

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |   \ |  |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |Ctrl/Esc|Ctrl/A|   S  |   D  |   F  |   G  | Esc  |           | Spc  |   H  |   J  |   K  |   L  | ;/L2 |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  Shift |Shft/Z|   X  |   C  |   V  |   B  | Bs   |           | Tab  |   N  |   M  | ,  < | . >  |Shft/?|  Enter |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                       .-------.   .------.                                 .------.   .-------.
 *                       |Opt/Esc|   |Cmd/Bs|                                 |L1/Spc|   |Opt/Tab|
 *                       '-------'   '------'                                 `------.   '-------'
 *                                        ,-------.                      ,-------.
 *                                        | Vol+  |                      | Br+   |
 *                                 ,------|-------|                      |-------|------.
 *                                 | HYPR | Vol-  |                      | Br-   | Ctrl |
 *                                 |      |       |                      |       | Enter|
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    KC_TAB,         KC_Q,         KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I,    KC_O,   KC_P,              KC_BSLS,
    LCTL_T(KC_ESC), LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G, KC_ESC,                        KC_SPC, KC_H, KC_J, KC_K,    KC_L,   LT(MOVE, KC_SCLN), KC_QUOT,
    KC_LSFT,        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_BSPC, KC_VOLU,     KC_BRIU, KC_TAB, KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),   KC_ENT,
                 LOPT_T(KC_ESC), LCMD_T(KC_BSPC),    HYPR(KC_NO),  KC_VOLD,     KC_BRID, LCTL_T(KC_ENT),    LT(SYMB, KC_SPC), ROPT_T(KC_TAB)
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |   `~   |  1!  |  2@  |  3#  |  4$  |  5%  |                         |  6^  |  7&  |  8*  |  9(  |  0)  |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |Ctl/F1|  F2  |  F3  |  F4  |  F5  |  F6  |           |      |      |  - _ |  = + |  `~  |  ' " |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |Shf/F7|  F8  |  F9  |  F10 |  F11 |  F12 |           |      |      |      |  [{  |  ]}  |Shf |\|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_GRV,  KC_1,          KC_2,  KC_3,  KC_4,   KC_5,                                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_TRNS,
    KC_TRNS, LCTL_T(KC_F1), KC_F2, KC_F3, KC_F4,  KC_F5,   KC_F6,                            KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_GRV,  KC_QUOT,         KC_TRNS,
    KC_TRNS, LSFT_T(KC_F7), KC_F8, KC_F9, KC_F10, KC_F11,  KC_F12,  KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, RSFT_T(KC_PIPE), KC_TRNS,
                                          KC_TRNS, KC_TRNS, KC_SCLN, KC_EQL,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |  MU  |      |      |                         | HOME | PGDN | PGUP | END  |      | RESET  |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |Ctl/M1|  ML  |  MD  |  MR  |  M2  |      |           |      | LEFT | DOWN |  UP  | RGHT |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        | Shf  |      |  M3  |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[MOVE] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS,         KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS,                                             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, RESET,
    KC_TRNS, LCTL_T(KC_BTN1), KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS,                           KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, LSFT_T(KC_TRNS), KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
