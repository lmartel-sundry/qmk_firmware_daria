/*
Copyright 2020 Terry Mathews

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

//  RGB-specific keys:
//  EF_INC, EF_DEC,   // next/previous backlight effect
//  H1_INC, H1_DEC,   // Color 1 hue increase/decrease
//  S1_INC, S1_DEC,   // Color 1 saturation increase/decrease
//  H2_INC, H2_DEC,   // Color 2 hue increase/decrease
//  S2_INC, S2_DEC,   // Color 2 saturation increase/decrease
//  BR_INC, BR_DEC,   // backlight brightness increase/decrease

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_HOME,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,           KC_ENT, KC_PGDN,
        KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,   KC_UP,  KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                               MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
#ifdef RGB_BACKLIGHT_PORTICO
    [1] = LAYOUT_65_ansi_blocker(
        QK_GESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_HOME,
        _______,  EF_INC,  EF_DEC,  BR_INC,  BR_DEC,  H1_INC,  H1_DEC,  S1_INC,  S1_DEC, _______, KC_PSCR, KC_SCRL, KC_PAUS,   QK_BOOT, KC_PGUP,
        KC_CAPS, _______, _______, _______, _______,  H2_INC,  H2_DEC,  S2_INC,  S2_DEC, _______, _______, _______,          _______, KC_PGDN,
        KC_LSFT,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
        _______, _______, _______,                            _______,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
#else
    [1] = LAYOUT_65_ansi_blocker(
        QK_GESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_HOME,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SCRL, KC_PAUS,   QK_BOOT, KC_PGUP,
        KC_CAPS, RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_PGDN,
        KC_LSFT,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
        _______, _______, _______,                            _______,                            _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
#endif
    [2] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    )
};

//void keyboard_post_init_user(void) {
    //rgb_matrix_enable();
    //rgb_matrix_sethsv(10, 255, 95);
    //rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Keymap:
    // {  0,      1,  2,      3,      4,      5,  6,      7,      8,      9, 10, 11, 12,     13, 14 },
    // { 15,     16, 17,     18,     19,     20, 21,     22,     23,     24, 25, 26, 27,     28, 29 },
    // { 30,     31, 32,     33,     34,     35, 36,     37,     38,     39, 40, 41, 42, NO_LED, 43 },
    // { 44, NO_LED, 45,     46,     47,     48, 49,     50,     51,     52, 53, 54, 55,     56, 57 },
    // { 58,     59, 60, NO_LED, NO_LED, NO_LED, 61, NO_LED, NO_LED, NO_LED, 62, 63, 64,     65, 66 }

    int pink_indices[11] = {0, 1, 2, 3, 15, 16, 17, 30, 31, 44, 58};
    int fuchsia_indices[5] = {4, 18, 32, 45, 59};
    int purple_indices[5] = {5, 19, 33, 46, 60};
    int blue_indices[4] = {6, 20, 34, 47};

    for (uint8_t i = led_min; i <= led_max; i++) {
        rgb_matrix_sethsv(0, 0, 125);
    }

    for (uint8_t i = 0; i < 11; i++) {
        rgb_matrix_set_color(pink_indices[i], 0xFF, 0x01, 0x19);
    }

    for (uint8_t i = 0; i < 5; i++) {
        rgb_matrix_set_color(fuchsia_indices[i], 0xFF, 0x00, 0x60);
    }

    for (uint8_t i = 0; i < 5; i++) {
        rgb_matrix_set_color(purple_indices[i], 0x7A, 0x03, 0xFF);
    }

    for (uint8_t i = 0; i < 4; i++) {
        rgb_matrix_set_color(blue_indices[i], 0x1D, 0x18, 0xFF);
    }

    // rgb_matrix_mode(RGB_MATRIX_BAND_VAL);

    return true;
};
