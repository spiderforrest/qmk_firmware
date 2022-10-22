#include QMK_KEYBOARD_H
#include <stdio.h>


// define layer vars
enum layer_number {
	_COLEMAK = 0,
	_QWERTY = 1,
	_GAME = 2,
	_MACRO = 3,
	_LEFT = 4,
	_RIGHT = 5,
	_UTILITY = 6,
};

// define custom keycodes for macros etc
enum custom_keycodes {
	HEART = SAFE_RANGE,
    SHRUG,
    GHEART,
    WHEART,
    BOTTOM,
    EYEROLL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_COLEMAK] = LAYOUT(
KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                           KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
KC_TAB, KC_Z, KC_W, KC_F, KC_P, KC_COMM,                        KC_DOT, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
MO(4),	 KC_A, KC_R, KC_S, KC_T, KC_G,                          KC_K, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
KC_LCTL, KC_Q, KC_X, KC_C, KC_D, KC_B, KC_LBRC,         KC_RBRC, KC_M, KC_H, KC_J, KC_V, KC_SLSH, KC_EXLM,
KC_LALT, KC_LGUI, KC_LSFT, KC_SPC,                                LT(5,KC_ENT), KC_BSPC, OSL(3), KC_DEL),


	[_QWERTY] = LAYOUT(
KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, 							KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, 
KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, 							KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, 
KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, 							KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, 		KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EXLM, 
KC_LALT, KC_LGUI, MO(4), KC_SPC, 								LT(5,KC_ENT), KC_BSPC, KC_RSFT, KC_DEL),


	[_GAME] = LAYOUT(
KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, 							KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, 
KC_GRV, KC_Y, KC_Q, KC_W, KC_E, KC_R, 							KC_U, KC_I, KC_UP, KC_O, KC_P, KC_MINS, 
KC_TAB, KC_G, KC_A, KC_S, KC_D, KC_F, 							KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, KC_QUOT, 
KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F3, 				KC_M, KC_RALT, KC_K, KC_DOT, KC_SLSH, KC_SCLN, MO(4), 
KC_N, KC_H, KC_LCTL, KC_SPC, 									KC_TRNS, KC_BSPC, KC_TRNS, TG(2)),


	[_MACRO] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 						BOTTOM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 						WHEART, GHEART, HEART, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 						SHRUG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, KC_NO, KC_NO, 									KC_NO, KC_NO, KC_TRNS, KC_F20),


	[_LEFT] = LAYOUT(
KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, 				KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, 
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, 						KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(6), 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
KC_LCTL, KC_PSCR, OSM(MOD_LCTL|MOD_LALT), OSM(MOD_LSFT|MOD_LALT), OSM(MOD_LALT|MOD_LGUI), OSM(MOD_LSFT|MOD_LGUI), DF(1), 
															DF(2), KC_TRNS, KC_TRNS, KC_PIPE, KC_PLUS, KC_BSLS, KC_EQL, 
KC_LALT, KC_LGUI, KC_TRNS, TG(2), 								KC_TRNS, DF(0), KC_TRNS, KC_TRNS),


	[_RIGHT] = LAYOUT(
KC_PAUS, KC_CAPS, KC_P7, KC_P8, KC_P9, KC_PAST, 				KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN3, KC_WH_D, KC_WH_U, 
KC_INS, KC_SLCK, KC_P4, KC_P5, KC_P6, KC_PSLS, 					KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD, KC_MPLY, 
KC_LSFT, KC_NLCK, KC_P1, KC_P2, KC_P3, KC_PPLS, 				KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_END, 
KC_LCTL, KC_PSCR, KC_P0, KC_P0, KC_PDOT, KC_PMNS, KC_LOCK, MO(6), KC_APP, KC_ENT, KC_PGDN, KC_PGUP, KC_BSLS, KC_EQL, 
KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, 							KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_UTILITY] = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLEP, 					KC_NO, KC_NO, KC_NO, RESET, DEBUG, EEP_RST, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WAKE, 					NK_ON, GUI_ON, GE_SWAP, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 						NK_OFF, GUI_OFF, GE_NORM, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PWR, 		KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, OSM(MOD_HYPR), KC_NO, 							KC_NO, KC_NO, KC_NO, KC_NO)
};


//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
//const char *read_layer_state(void);  // code moved to below
//const char *read_logo(void);        // logo also moved to below
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

static void draw_icon(void) {
  static const char PROGMEM my_logo[] = {
0x49, 0x49, 0xb6, 0x49, 0x49, 0x49, 0xb6, 0x49, 0x49, 0xb6, 0x49, 0x49, 0xb6, 0x49, 0x49, 0xb6,
0x49, 0xb6, 0x49, 0xb6, 0x7f, 0xaa, 0x55, 0xff, 0x00, 0xec, 0x02, 0x02, 0x92, 0x6c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0xa0, 0x90, 0x90, 0x90, 0x48, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0xc0, 0x00, 0x07, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0x40,
0x80, 0x40, 0x30, 0xce, 0x81, 0x25, 0x49, 0x91, 0x23, 0x03, 0xff, 0x22, 0x00, 0x00, 0x00, 0x60,
0xf0, 0x50, 0xac, 0x54, 0xbb, 0x54, 0xe0, 0xb0, 0x5c, 0xaa, 0x55, 0xaa, 0x56, 0xaa, 0x75, 0xab,
0xc6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x41, 0x00, 0x49, 0xaa, 0x55,
0x92, 0x92, 0x6d, 0x92, 0x92, 0x92, 0x6d, 0x92, 0x92, 0x6d, 0x92, 0x92, 0x6d, 0x92, 0x92, 0x6d,
0x92, 0xfd, 0x56, 0xab, 0x55, 0xea, 0x1d, 0x02, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x10, 0x54,
0xa4, 0xa4, 0x88, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x00, 0xc0, 0x30,
0x40, 0x80, 0x80, 0x00, 0x00, 0xdd, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x22, 0xdc, 0x00, 0x00, 0x00, 0x10, 0x14, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x40, 0x7f, 0x20, 0x17, 0x2a, 0x12, 0xe6, 0x86, 0x3f, 0x22, 0x10, 0xe8, 0xac, 0x54,
0xab, 0xd5, 0x2a, 0x9d, 0x76, 0xad, 0x56, 0xaa, 0xa5, 0x5a, 0xa5, 0xda, 0x27, 0x1d, 0x01, 0x03,
0x84, 0x7e, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x10, 0x00, 0x92, 0xaa, 0x55,
0x24, 0x24, 0xdb, 0x24, 0x24, 0x24, 0xdb, 0x24, 0x24, 0xdb, 0x24, 0x24, 0xdb, 0x24, 0x24, 0xdb,
0x24, 0xff, 0x55, 0xaa, 0x55, 0xff, 0x00, 0xe8, 0x04, 0x08, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0xa0, 0x40, 0x40, 0x80, 0x00, 0x00, 0xc0, 0x1b, 0x00,
0x00, 0x00, 0x05, 0x18, 0x04, 0x13, 0x40, 0x68, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x27, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x1c, 0x25, 0xa8, 0x58, 0xb0, 0x30, 0x7d, 0xda, 0xb8, 0x88, 0xc3, 0x5d, 0xb6, 0xed,
0x56, 0xa8, 0x52, 0xa9, 0x57, 0xbc, 0x6b, 0x6d, 0x72, 0x55, 0x9e, 0x05, 0x07, 0x03, 0x00, 0x00,
0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x24, 0xaa, 0x55,
0x49, 0x49, 0xb6, 0x49, 0x49, 0x49, 0xb6, 0x49, 0x49, 0xb6, 0x49, 0x49, 0xb6, 0x49, 0x49, 0xb6,
0x59, 0x6f, 0xf5, 0xaa, 0x55, 0xaf, 0xf0, 0x00, 0x81, 0x41, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x25, 0x19, 0x02, 0x00, 0x00, 0x02, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x58, 0x80, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 0x04,
0x08, 0x00, 0x00, 0xf0, 0x8f, 0x82, 0xa4, 0xc9, 0x92, 0x82, 0xfa, 0x4a, 0x02, 0x21, 0x61, 0xa2,
0xd7, 0xa9, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xeb, 0xd5, 0x6f, 0xb6, 0x69, 0x50, 0x20, 0x00, 0x00,
0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x41, 0x00, 0x49, 0xaa, 0x55};

  oled_write_raw_P(my_logo, sizeof(my_logo));
}



void oled_task_user(void) {
    // actions for master hand
    if (is_keyboard_master()) {
	// prefixes layer, i prefer spaces for alignments
	//oled_write_P(PSTR("Layer:"), false);
		switch (get_highest_layer(layer_state)) {
			case _COLEMAK:
				// there are 20 chars per line, so prepend the correct number of spaces
				// char count:     0123456789ABCDEFGHIJ
				oled_write_P(PSTR("       Colemak\n"), false);
				break;
			case _QWERTY:
				oled_write_P(PSTR("    ew, Qwerty\n"), false);
				break;
			case _ICE:
				oled_write_P(PSTR("        Ice\n"), false);
				break;
			case _GAME:
				oled_write_P(PSTR("       Games\n"), false);
				break;
			case _MACRO:
				oled_write_P(PSTR("       Macros\n"), false);
				break;
			case _LEFT:
				oled_write_P(PSTR("Left\n"), false);
				break;
			case _RIGHT:
				oled_write_P(PSTR("               Right\n"), false);
				break;
			case _UTILITY:
				oled_write_P(PSTR("    Utilities\n"), false);
				break;
			default:
				// if something goes wrong
				// only god can judge me
				oled_write_ln_P(PSTR("upsi whopsi!"), false);
        }

    // prints adress
    oled_write_ln(read_keylog(), false); 
	// prints letterstring
    oled_write_ln(read_keylogs(), false);

    } else {
		// draws from logo file, unused for Allie's drawing
        //oled_write(read_logo(), false);
		draw_icon();
        }
}

#endif // OLED_DRIVER_ENABLE

// runs on keypress? listen i don't know how to code i don't understand why any of this compiles what the fuck help
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
 // updates keystring
  	  set_keylog(keycode, record);
#endif
// macros
	  switch (keycode) {
		  case HEART:
				if (record->event.pressed) 
					SEND_STRING(":heart:");
				break;

		   case GHEART:
				if (record->event.pressed) 
					SEND_STRING(":green_heart:");
				break;

		   case WHEART:
				if (record->event.pressed)
					SEND_STRING(":white_heart:");
				break;

		   case EYEROLL:
				if (record->event.pressed)
				SEND_STRING(":face_with_rolling_eyes:");
				break;

		  case SHRUG:
				if (record->event.pressed) 
					SEND_STRING("/shrug");
				break;

			case BOTTOM:
				if (record->event.pressed)
					SEND_STRING(":point_right::point_left::pleading_face:");
				break;
			}

	  }
  return true;
}
