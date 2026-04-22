#include QMK_KEYBOARD_H
#include <stdio.h>

// spider's keyboard layout!
// my dansen layer system is heavily built on (read: copy pasted) from miryoku! you can check it out @ github.com/manna-harbour/miryoku

// {{{ DEFINITIONS

// #define DRAW_ART
// {{{ Art dump
#ifdef DRAW_ART
static void draw_art(void) {
  static const char PROGMEM art[] = {
0xcf, 0xcf, 0xc7, 0x87, 0x07, 0x63, 0xf7, 0xff, 0xc3, 0x03, 0x19, 0x89, 0x01, 0x33, 0x3f, 0x7f,
0x7f, 0xff, 0x00, 0x00, 0xc9, 0xc1, 0xc3, 0xc7, 0x0f, 0x83, 0x81, 0xf9, 0xf1, 0xe3, 0x87, 0x8f,
0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xfb, 0xff, 0xff, 0xfe, 0xfc, 0xff, 0x7f, 0x7f, 0x7f, 0x3e,
0x3e, 0x3f, 0x3e, 0x1e, 0x1f, 0x0f, 0x07, 0xc3, 0x93, 0x13, 0x03, 0x23, 0x73, 0x31, 0x39, 0x39,
0x67, 0x0f, 0x0f, 0xcf, 0xe7, 0xe7, 0xe3, 0xf3, 0xf3, 0xf3, 0x73, 0x79, 0x78, 0x7c, 0x3c, 0x3e,
0x3e, 0x9f, 0x9f, 0x9f, 0x9f, 0x1f, 0x3e, 0x38, 0x71, 0x63, 0xe7, 0xe0, 0xe0, 0xe2, 0xc3, 0x01,
0xfc, 0xfe, 0xfe, 0x7f, 0x1f, 0x0f, 0x83, 0x00, 0x0c, 0x0d, 0x0e, 0x8e, 0x9e, 0xff, 0xc7, 0xc3,
0xc1, 0x01, 0x20, 0x10, 0x89, 0xcf, 0xcf, 0x8e, 0x8e, 0x9c, 0x18, 0x61, 0x03, 0x1f, 0x7f, 0x7f,
0xff, 0xff, 0x01, 0x00, 0xc0, 0xc0, 0xc0, 0xf8, 0xfc, 0xf8, 0x08, 0x01, 0xf9, 0xff, 0xff, 0xff,
0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfd, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xfe, 0xfe, 0x3e,
0xff, 0xff, 0xf0, 0xc0, 0x07, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xf0, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x07, 0xff, 0xff, 0xff, 0x2f, 0x03, 0x80, 0xe0,
0x8f, 0x1f, 0x3f, 0x0f, 0x03, 0x40, 0xc4, 0x8f, 0x8f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0xff,
0xff, 0x7f, 0x7f, 0x7d, 0x71, 0x33, 0x73, 0x30, 0x08, 0x0f, 0x23, 0x71, 0xfc, 0xfe, 0xff, 0xff,
0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xf0, 0xf9, 0xf3, 0xf3, 0xff, 0xff, 0xe2, 0xe0, 0xc0, 0x00, 0x18,
0x00, 0x00, 0x0e, 0x1e, 0x1c, 0x18, 0x00, 0x02, 0x47, 0xe3, 0xf0, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x07, 0xe3, 0xf1, 0xf8, 0xfe, 0xfe,
0xff, 0xff, 0xfe, 0xc0, 0x80, 0x13, 0x71, 0xf8, 0xfc, 0xc0, 0x01, 0x0f, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0x0f, 0x03, 0xc0, 0xf8, 0xff, 0xfe, 0xf8, 0x00, 0x03, 0x1f, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0x6c, 0x00, 0x93, 0xff, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff,
0xff, 0x0f, 0x0f, 0x80, 0xd0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0x00, 0x10, 0x7f, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x80, 0x0f, 0x1f, 0x7f, 0xff, 0xf8, 0xe0, 0x03, 0x1f, 0xff,
0xc0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x1f, 0x87, 0xc1, 0xf1, 0xfc, 0xe0, 0xc1,
0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf0, 0xe0, 0xc7, 0x83, 0x80, 0x84, 0xff,
0x7f, 0x3f, 0x1f, 0x9f, 0xcf, 0xe7, 0xe1, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xfe, 0xfc, 0xf8, 0xf3, 0xf3, 0xe7, 0xcf, 0x8f, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff,
0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x0f, 0x7f, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf9, 0xf1, 0x67, 0xc7,
0xff, 0x1f, 0x07, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xfb, 0x19, 0x1d, 0x33, 0xf0, 0xe0, 0x81, 0x08,
0x1c, 0x7c, 0xc2, 0x03, 0x11, 0x49, 0x61, 0x63, 0x3f, 0x1c, 0xfc, 0x04, 0x00, 0x20, 0x3c, 0x9f,
0xff, 0xff, 0xf8, 0xf0, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff,
0xfe, 0xfc, 0xf8, 0xfd, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff
    };
  oled_write_raw_P(art, sizeof(art));
}
#endif
// }}}

// define layer vars
enum layer_number {
	// base layers
	DANSEN,
	// miryoku layers:
	DANCELEFT,
	DANCERIGHT,
	NAV,
	MEDIA,
	NUM,
	FUN,
	// mod layers
	GAME,
	UTILITY,
};

// mostly defining so when i add a layer it isn't hell where i have to try and hand set the numbers & my names are too long
#define LT_ENT	LT(RIGHT,KC_ENT)
#define SH_LBRC SH_T(KC_LBRC)
#define SH_RBRC SH_T(KC_RBRC)
#define OS_UTL OSL(UTILITY)
#define LYR_HM TO(DANSEN)

// defines for miryoku!
#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
#define U_NA KC_NO // mark key as don't use in the future so i don't snap my fingers in half trying to hit a shitty combo

// shorten modtaps so the layout is readable at all
#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)
#define MOD_N LSFT_T(KC_N)
#define MOD_E LCTL_T(KC_E)
#define MOD_I LALT_T(KC_I)
#define MOD_O LGUI_T(KC_O)
// if i'm using only one hand i need to be able to mod the same key i'm using. so, upper row becomes modtaps aswell
#define MOD_Z LGUI_T(KC_Z)
#define MOD_W LALT_T(KC_W)
#define MOD_F LCTL_T(KC_F)
#define MOD_P LSFT_T(KC_P)
#define MOD_L LSFT_T(KC_L)
#define MOD_U LCTL_T(KC_U)
#define MOD_Y LALT_T(KC_Y)
#define MOD_SCLN LGUI_T(KC_SCLN)

// define custom keycodes for macros etc
enum custom_keycodes {
	PHEART = SAFE_RANGE,
	SHRUG,
	YHEART,
	GHEART,
};

#ifdef SWAP_HANDS_ENABLE
// hand swap matrix
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
	// Left hand matrix positions
    {{0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5}},
    {{0,6}, {1,6}, {2,6}, {3,6}, {4,6}, {5,6}},
    {{0,7}, {1,7}, {2,7}, {3,7}, {4,7}, {5,7}},
    {{0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}},
    {{0,9}, {1,9}, {2,9}, {3,9}, {4,9}, {5,9}},
	// Right hand matrix positions
    {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}},
    {{0,1}, {1,1}, {2,1}, {3,1}, {4,1}, {5,1}},
    {{0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}},
    {{0,3}, {1,3}, {2,3}, {3,3}, {4,3}, {5,3}},
    {{0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4}},
};
#endif
// }}}

// {{{ LAYERS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base layer
	[DANSEN] = LAYOUT( // {{{
KC_ESC,		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5,					   			KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
QK_LOCK,	KC_Z,		KC_W,		KC_F, 		KC_P, 		KC_COMM,							KC_DOT, 	KC_L, 		KC_U, 		KC_Y, 		KC_SCLN,	KC_MINS,
KC_BSLS,	MOD_A,		MOD_R,		MOD_S,		MOD_T,		KC_G,					   	  		KC_K, 		MOD_N, 		MOD_E, 		MOD_I, 		MOD_O, 		KC_QUOT,
TG(GAME),	KC_Q,		KC_X, 		KC_C, 		KC_D, 		KC_B, 		SH_LBRC,	SH_RBRC,	KC_M,		KC_H, 		KC_J, 		KC_V, 		KC_SLSH, 	KC_EQL,
                        OS_UTL, 	LT(MEDIA,KC_ESC),LT(NAV,KC_SPC),LT(DANCELEFT,KC_TAB),	 	LT(DANCERIGHT,KC_ENT),LT(NUM,KC_BSPC),LT(FUN,KC_DEL),OS_UTL // }}}
// aux miryoku layers
	), [DANCELEFT] = LAYOUT( // {{{ mouse and mirrored
KC_GRV,		KC_0, 		KC_9, 		KC_8, 		KC_7, 		KC_6,					   			KC_5, 		KC_4, 		KC_3, 		KC_2, 		KC_1, 		KC_ESC,
KC_MINS,	MOD_SCLN,	MOD_Y,		MOD_U, 		MOD_L, 		KC_DOT,								U_RDO,		U_PST,		U_CPY,		U_CUT,		U_UND,		KC_NO,
KC_QUOT, 	MOD_O,		MOD_I,		MOD_E,		MOD_N,		KC_K,					   	  		KC_NO,		MS_LEFT,	MS_DOWN,	MS_UP,	    MS_RGHT,	MS_BTN1,
KC_EXLM,	KC_SLSH,	KC_V, 		KC_J, 		KC_H, 		KC_M, 		SH_LBRC,	SH_RBRC,	KC_NO,		MS_WHLL,	MS_WHLD,	MS_WHLU,	MS_WHLR,	KC_NO,
                        LYR_HM,	 	LT(FUN,KC_DEL),LT(NUM,KC_BSPC),SH_T(KC_ENT),			 	MS_BTN1,	MS_BTN3,	MS_BTN2,	LYR_HM // }}}

	), [DANCERIGHT] = LAYOUT( // {{{ symbols and mirrored
KC_GRV,		KC_0, 		KC_9, 		KC_8, 		KC_7, 		KC_6,					   			KC_5, 		KC_4, 		KC_3, 		KC_2, 		KC_1, 		KC_ESC,
KC_NO, 		KC_LCBR,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RCBR,							KC_COMM, 	MOD_P, 		MOD_F, 		MOD_W, 		MOD_Z,		KC_MINS,
KC_TAB,		KC_COLN,	KC_DLR,		KC_PERC,	KC_CIRC,	KC_PLUS,				   	  		KC_G, 		MOD_T, 		MOD_S, 		MOD_R, 		MOD_A, 		KC_QUOT,
KC_NO,		KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_PIPE,	SH_LBRC,	SH_RBRC,	KC_B,		KC_D, 		KC_C, 		KC_X, 		KC_Q, 		KC_EXLM,
                        LYR_HM,	 	KC_LPRN,	KC_RPRN,	KC_UNDS,						 	SH_T(KC_TAB),LT(NAV,KC_SPC),LT(MEDIA,KC_ESC),LYR_HM // }}}

	), [NAV] = LAYOUT( // {{{
KC_ESC,		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5,					   			KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_NO,		KC_NO,		U_NA,		U_NA,		U_NA,		U_NA,								U_RDO,		KC_NO,		U_CPY,		U_CUT,		U_UND,		KC_NO,
KC_NO,		KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	U_NA,								KC_CAPS,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	KC_NO,
KC_NO,		U_NA,		KC_ALGR,	U_NA,		U_NA,		U_NA,		KC_NO,		KC_NO,		KC_NO,		KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		KC_NO,
                        KC_NO,		U_UND,		U_NA,		U_NA,								KC_ENT,		KC_BSPC,	KC_DEL,		KC_NO // }}}

	), [MEDIA] = LAYOUT( // {{{
KC_ESC,		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5,					   			KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_NO,		KC_NO,		U_NA,		U_NA,		U_NA,		U_NA,								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	U_NA,								KC_NO,  	KC_MPRV,	KC_VOLD,	KC_VOLU,	KC_MNXT,	KC_NO,
KC_NO,		U_NA,		KC_ALGR,	U_NA,		U_NA,		U_NA,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_KB_MUTE, KC_KB_MUTE,	KC_NO,		KC_NO,
                        KC_NO,		U_NA,		U_NA,		U_NA,								KC_MSTP,	KC_MPLY,	KC_MUTE,	KC_NO // }}}

	), [NUM] = LAYOUT( // {{{
KC_ESC,		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5,					   			KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_NO,		KC_LBRC,	KC_7,		KC_8,		KC_9,		KC_RBRC,							KC_NO,		U_NA,		U_NA,		U_NA,		KC_NO,		KC_NO,
KC_NO,		KC_SCLN,	KC_4,		KC_5,		KC_6,		KC_EQL,								U_NA,		KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,	KC_NO,
KC_NO,		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_BSLS,	KC_NO,		KC_NO,		U_NA,		U_NA,		U_NA,		KC_ALGR,	U_NA,		KC_NO,
                        KC_NO,		KC_DOT,		KC_0,		KC_MINS,							U_NA,		U_NA,		U_NA,		KC_NO // }}}

	), [FUN] = LAYOUT( // {{{
KC_ESC,		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5,					   			KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_NO,		KC_F12,		KC_F7,		KC_F8,		KC_F9,		KC_PSCR,							U_NA,		U_NA,		U_NA,		U_NA,		KC_NO,		KC_NO,
KC_NO,		KC_F11,		KC_F4,		KC_F5,		KC_F6,		KC_SLCT,							U_NA,		KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,	KC_NO,
KC_NO,		KC_F10,		KC_F1,		KC_F2,		KC_F3,		KC_PAUS,	KC_NO,		KC_NO,		U_NA,		U_NA,		U_NA,		KC_ALGR,	U_NA,		KC_NO,
                        KC_NO,		KC_APP,		KC_SPC,		KC_TAB,								U_NA,		U_NA,		U_NA,		KC_NO // }}}

// modifier layers

	), [GAME] = LAYOUT( // {{{
KC_ESC, 	KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 								KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_GRV, 	KC_Y, 		KC_Q, 		KC_W, 		KC_E, 		KC_R, 								KC_U, 		KC_I, 		KC_UP, 		KC_O, 		KC_P, 		KC_MINS,
KC_TAB, 	KC_G, 		KC_A, 		KC_S, 		KC_D, 		KC_F, 								KC_RCTL, 	KC_LEFT,	KC_DOWN, 	KC_RGHT, 	KC_RSFT,	KC_QUOT,
KC_LALT, 	KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 		KC_F3,		KC_M,		KC_RALT, 	KC_K, 		KC_DOT, 	KC_SLSH, 	KC_SCLN, 	KC_BSLS,
                        KC_N, 		KC_H, 		KC_LCTL, 	KC_SPC,		 						KC_T, 	    KC_BSPC, 	KC_TRNS, 	TG(GAME) // }}}

	), [UTILITY] = LAYOUT( // {{{
KC_NO,  	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_SLEP, 							KC_NO,   	KC_NO,	 	KC_NO, 		KC_NO, 		DB_TOGG,  	QK_RBT,
KC_NO,  	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_WAKE, 							PHEART, 	YHEART,		GHEART, 	NK_ON, 		GU_ON,	 	GE_SWAP,
KC_NO,  	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_PWR, 							SHRUG, 		KC_NO, 		KC_NO, 		NK_OFF,		GU_OFF, 	GE_NORM,
KC_NO,  	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		TG(GAME),   KC_NO,	    KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,
                        KC_F20,		KC_NO, 		OSM(MOD_HYPR),LYR_HM,       					LYR_HM,     KC_NO,		KC_TRNS, 	KC_F20 // }}}

)}; // }}}

// {{{ SCREEN CODE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

/* if (is_keyboard_master()) { */
bool oled_task_user(void) {
    // if the background is white, inverting bold makes it nicer looking. set false to do so
    bool bold = true;
    #ifdef DRAW_ART
    draw_art();
    #endif
    oled_set_cursor(0, 15);
    switch (get_highest_layer(layer_state)) {
        case DANSEN:
            oled_write("dance", !bold);
            break;
        case DANCELEFT:
            oled_write("<<<<<", bold);
            break;
        case DANCERIGHT:
            oled_write(">>>>>", bold);
            break;
        case NAV:
            oled_write(" nav ", !bold);
            break;
        case MEDIA:
            oled_write("media", !bold);
            break;
        case NUM:
            oled_write(" num ", !bold);
            break;
        case FUN:
            oled_write(" sym ", !bold);
            break;
        case GAME:
            oled_write("games", bold);
            break;
        case UTILITY:
            oled_write("|||||", bold);
            break;
        default:
            oled_write("oop", true);
            break;
    }

    // show ""led"" state (idgaf about the others)
    if (host_keyboard_led_state().caps_lock) {
        oled_set_cursor(0, 0);
        oled_write("CAPS", !bold);
    }
    // if the art isn't drawing we need to reset when no caps
    #ifndef DRAW_ART
    else {
        oled_set_cursor(0, 0);
        oled_write("    ", false);
    }
    #endif

    return false;
}
// }}}

// {{{ RANDOM BULLSHIT GO

// {{{ combo(s)!
enum combo_events {
    WY_ESC,
    COMBO_LENGTH // must be last!
};

// get total combo by checking last enum value
    // which is still one.
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM wy_esc[] = {KC_W, KC_Y, COMBO_END};
combo_t key_combos[] = {
    [WY_ESC] = COMBO(wy_esc, KC_ESC)
};
// }}}

// {{{ macros
// runs on keypress? listen i don't know how to code i don't understand why any of this compiles what the fuck help
    // it is two years later, and i in fact, know how to code, and what a struct is. wack.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // macros
        switch (keycode) {
            case PHEART:
                if (record->event.pressed)
                    SEND_STRING(":sparkling_heart:");
                break;

            case YHEART:
                if (record->event.pressed)
                    SEND_STRING(":yellow_heart:");
                break;

            case GHEART:
                if (record->event.pressed)
                    SEND_STRING(":green_heart:");
                break;

            case SHRUG:
                if (record->event.pressed)
                    SEND_STRING("/shrug");
                break;
        }

    }
    return true;
}
// }}}

// {{{ per layer settings
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case DANSEN:
            //autoshift_disable();
            combo_enable();
            break;
        case DANCELEFT:
            //autoshift_enable();
            break;
        case DANCERIGHT:
            //autoshift_enable();
            break;
        case GAME:
            //autoshift_disable();
            combo_disable();
            break;

        default: //  for any other layers, or the default layer
            break;
    }
    return state;
}
// }}}

// default settings for when the keeb boots
void keyboard_post_init_user() {
    //	autoshift_disable();
    layer_on(DANSEN);
}


// }}}

// vim: foldmethod=marker
