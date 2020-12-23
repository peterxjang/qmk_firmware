#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOVE 2 // motion

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
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  | ;/L2 |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |Shft/Z|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | ,  < | . >  |  / ? |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                       .-------.   .------.                                 .------.   .-------.
 *                       |Opt/Esc|   |Cmd/Bs|                                 |L1/Spc|   |Shft/Bs|
 *                       '-------'   '------'                                 `------.   '-------'
 *                                        ,-------.                      ,-------.
 *                                        |       |                      |       |
 *                                 ,------|-------|                      |-------|------.
 *                                 | Ctrl |       |                      |       | HYPR |
 *                                 | Tab  |       |                      |       | Enter|
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    KC_NO, KC_Q,         KC_W, KC_E, KC_R, KC_T,                                 KC_Y, KC_U, KC_I,    KC_O,   KC_P,              KC_NO,
    KC_NO, KC_A,         KC_S, KC_D, KC_F, KC_G, KC_NO,                   KC_NO, KC_H, KC_J, KC_K,    KC_L,   LT(MOVE, KC_SCLN), KC_NO,
    KC_NO, LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO,     KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,           KC_NO,
       LOPT_T(KC_ESC), LCMD_T(KC_BSPC), LCTL_T(KC_TAB), KC_NO,     KC_NO, HYPR_T(KC_ENT), LT(SYMB, KC_SPC), RSFT_T(KC_BSPC)
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  1!  |  2@  |  3#  |  4$  |  5%  |                         |  6^  |  7&  |  8*  |  9(  |  0)  |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  - _ |  = + |  `~  |  ' " |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |Shf/F7|  F8  |  F9  |  F10 |  F11 |      |           |      |  F12 |      |  [{  |  ]}  |  |\  |        |
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
    KC_TRNS, KC_1,          KC_2,  KC_3,  KC_4,   KC_5,                                               KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_F1,         KC_F2, KC_F3, KC_F4,  KC_F5,   KC_TRNS,                          KC_TRNS, KC_F6,  KC_MINS, KC_EQL,  KC_GRV,  KC_QUOT, KC_TRNS,
    KC_TRNS, LSFT_T(KC_F7), KC_F8, KC_F9, KC_F10, KC_F11,  KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_F12, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |  MU  |      |      |                         | HOME | END  | PGDN | PGUP |RESET |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  M1  |  ML  |  MD  |  MR  |  M2  |      |           |      | LEFT | DOWN |  UP  | RGHT |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        | Shf  |      |  M3  |      |      |      |           |      | Br-  | Br+  | Vol- | Vol+ |      |        |
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
    KC_TRNS, KC_TRNS,         KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS,                                             KC_HOME, KC_END,  KC_PGDN, KC_PGUP, RESET,   KC_TRNS,
    KC_TRNS, KC_BTN1,         KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_TRNS,                           KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, LSFT_T(KC_TRNS), KC_TRNS, KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
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
