/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

#define L_COLEMAK 0
#define L_QWERTY 1
#define L_NUMBER 2
#define L_SYMBOL 3
#define L_NAVIGATION 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,   DF(1),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL(KC_BSPC),    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               KC_LCTL, KC_ENT, LT(L_NUMBER,KC_TAB),  LT(L_NAVIGATION,KC_BSPC), LT(L_SYMBOL, KC_SPC), KC_LSFT
                                      //`--------------------------'  `--------------------------'

  ),

  [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   DF(0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL(KC_BSPC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                               KC_LCTL, KC_ENT, LT(L_NUMBER,KC_TAB),  LT(L_NAVIGATION,KC_BSPC), LT(L_SYMBOL, KC_SPC), KC_LSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_F12,  KC_F11,  KC_F10,   KC_F9, XXXXXXX,                      XXXXXXX,    KC_P7,  KC_P8,   KC_P9, KC_PPLS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F8,   KC_F7,   KC_F6,   KC_F5, XXXXXXX,                      KC_PEQL,    KC_P4,  KC_P5,   KC_P6, KC_PAST, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F4,   KC_F3,   KC_F2,   KC_F1, XXXXXXX,                        KC_P0,    KC_P1,  KC_P2,   KC_P3, KC_PDOT, KC_PCMM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_LT, KC_LCBR, KC_LBRC, KC_LPRN, KC_SLSH,                      KC_BSLS, KC_RPRN, KC_RBRC, KC_RCBR,   KC_GT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_HOME, KC_PGDN,  KC_END, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

enum {
  TD_Q_TAB = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB)
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

// char keylog_str[24] = {};

// const char code_to_name[60] = {
//     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
//     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
//     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
//     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

// void set_keylog(uint16_t keycode, keyrecord_t *record) {
//   char name = ' ';
//     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
//         (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
//   if (keycode < 60) {
//     name = code_to_name[keycode];
//   }

//   // update keylog
//   snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
//            record->event.key.row, record->event.key.col,
//            keycode, name);
// }

// void oled_render_keylog(void) {
//     oled_write(keylog_str, false);
// }

// void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}



static void render_main_status(void) {
    static const char PROGMEM qwerty_icon[] = {
        0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0xf3, 0xf3, 0xf3, 0xf3, 0x03, 0x03, 0x03, 0x03, 0xfe, 0x00, 
        0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0xff, 0x03, 0x03, 0x03, 0xff, 0x03, 0x03, 0x03, 0x03, 0xfe, 
        0x3f, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x4f, 0x4f, 0x4f, 0xcf, 0x80, 0x80, 0x80, 0x80, 0xff, 0x00, 
        0x3f, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x4f, 0x40, 0x40, 0x40, 0x4f, 0x40, 0x40, 0x40, 0x40, 0x7f
    };

    static const char PROGMEM colemak_icon[] = {
        0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0xe3, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x3e, 0x00, 
        0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0xe3, 0x03, 0x03, 0x03, 0xe3, 0x03, 0x03, 0x03, 0x03, 0xfe, 
        0x7f, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8f, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0x8c, 0xf8, 0x00, 
        0x7f, 0xff, 0x80, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0x80, 0xff
    };

    if (get_highest_layer(default_layer_state) == 0) {
        oled_write_raw_P(colemak_icon, sizeof(colemak_icon));
    } else {
        oled_write_raw_P(qwerty_icon, sizeof(qwerty_icon));
    }
    oled_set_cursor(0, 3);

    

    static const char PROGMEM base_icon[] = {
        0x00, 0x00, 0xff, 0xff, 0xff, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0xff, 0xff, 0xff, 0x00, 
        0xff, 0xff, 0xff, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x8f, 0x9f, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 0xff, 0x00, 
        0xff, 0xff, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe3, 0xf3, 0xff, 0x7f, 0x3f, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    static const char PROGMEM number_icon[] = {
        0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x3e, 0x1f, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x07, 0x07, 0x07, 0x07, 0x87, 0xc7, 0xe7, 0xf7, 0x7f, 0x3f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 
        0xf8, 0xfc, 0xfe, 0xcf, 0xc7, 0xc3, 0xc1, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    static const char PROGMEM symbol_icon[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xfc, 0xfe, 0x7f, 0x07, 0x03, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x03, 0x07, 0x7f, 0xfe, 0xfc, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x7f, 0xfe, 0xfc, 0xc0, 0x80, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x80, 0xc0, 0xfc, 0xfe, 0x7f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    static const char PROGMEM navigation_icon[] = {
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0xfe, 0xff, 0xfe, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 0x00, 
        0x00, 0x03, 0x07, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    switch (get_highest_layer(layer_state)) {
        case L_NUMBER:
            oled_write_raw_P(number_icon, sizeof(number_icon));
            break;
        case L_SYMBOL:
            oled_write_raw_P(symbol_icon, sizeof(symbol_icon));
            break;
        case L_NAVIGATION:
            oled_write_raw_P(navigation_icon, sizeof(navigation_icon));
            break;
        default:
            oled_write_raw_P(base_icon, sizeof(base_icon));
            break;
    }

    oled_set_cursor(0,7);

    oled_write_ln_P(PSTR("SHIFT"), true);
    oled_write_ln_P(PSTR("CTRL "), true);
    oled_write_ln_P(PSTR("ALT  "), false);
    oled_write_ln_P(PSTR("SUPER"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_main_status();
                //oled_render_layer_state();
        // oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
