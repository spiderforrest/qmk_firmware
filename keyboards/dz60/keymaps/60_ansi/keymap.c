#include QMK_KEYBOARD_H

enum custom_keycodes {
    cLRpNK = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_60_ansi(
		QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
		KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             KC_RALT, KC_RGUI,          KC_APP,   MO(1),

	LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
<<<<<<< HEAD
		KC_TRNS,          UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, QK_BOOT,
		KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS,
		KC_TRNS,          KC_TRNS, KC_TRNS, BL_DOWN, BL_TOGG, BL_UP,   BL_STEP, KC_TRNS, KC_DEL,  KC_END,  KC_PGDN,          KC_TRNS,
=======
<<<<<<< ours
		KC_TRNS,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, RESET,
		KC_TRNS,          KC_TRNS, RGB_RMOD,RGB_SPI, RGB_SPD, cLRpNK,  KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS,
=======
		KC_TRNS,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, QK_BOOT,
		KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_HOME, KC_PGUP, KC_TRNS,
>>>>>>> theirs
		KC_TRNS,          KC_TRNS, KC_TRNS, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, KC_TRNS, KC_DEL,  KC_END,  KC_PGDN,          KC_TRNS,
>>>>>>> c8050edff6 (added my config files)
		KC_TRNS, KC_TRNS,          KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case cLRpNK:
        if (record->event.pressed) {
            rgb_matrix_set_color_all(122, 0, 122);
        }
        break;
    }
    return true;
};
