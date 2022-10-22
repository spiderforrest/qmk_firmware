#include QMK_KEYBOARD_H
#include <stdio.h>

// spider's keyboard layout! 
// currently does not utilize the screens or any lighting
// my dansen layer is heavily built on and includes copy pasted code from the miryoku! you can check it out @ github.com/manna-harbour/miryoku

// define layer vars
enum layer_number {
	// base layers
	DANSEN,
	MIRYOKU,
	COLEMAK,
	QWERTY,
	// miryoku layers:
	DANCELEFT,
	DANCERIGHT,
	NAV,
	MOUSE,
	MEDIA,
	NUM,
	SYM,
	FUN,
	GAME,
	// mod layers
	LEFT,
	RIGHT,
	UTILITY,
};
// mostly defining so when i add a layer it isn't hell where i have to try and hand set the numbers & my names are too long
#define LT_ENT	LT(RIGHT,KC_ENT)
#define SH_LBRC SH_T(KC_LBRC)
#define SH_RBRC SH_T(KC_RBRC)
#define MO_L MO(LEFT)
#define MO_R MO(RIGHT)
#define LT_Q LT(LEFT,KC_Q)
#define LT_SLSH LT(LEFT,KC_SLSH)
#define OS_UTL OSL(UTILITY)
#define LYR_HM TO(COLEMAK)
// defines for miryoku!
#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
#define U_NA KC_NO // mark key as don't use in the future so i don't snap my fingers in half trying to hit a shitty combo

#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)
#define MOD_N LSFT_T(KC_N)
#define MOD_E LCTL_T(KC_E)
#define MOD_I LALT_T(KC_I)
#define MOD_O LGUI_T(KC_O)

// define custom keycodes for macros etc
enum custom_keycodes {
	HEART = SAFE_RANGE,
	SHRUG,
	GHEART,
	WHEART,
	BOTTOM,
	EYEROLL,
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
// layer defs
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base layers
	[DANSEN] = LAYOUT(
KC_NO,		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5,					   			KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_LOCK,	KC_Z,		KC_W,		KC_F, 		KC_P, 		KC_COMM,							KC_DOT, 	KC_L, 		KC_U, 		KC_Y, 		KC_SCLN,	KC_MINS,
KC_BSLS,	MOD_A,		MOD_R,		MOD_S,		MOD_T,		KC_G,					   	  		KC_K, 		MOD_N, 		MOD_E, 		MOD_I, 		MOD_O, 		KC_QUOT,
TG(GAME),	LT_Q,		KC_X, 		KC_C, 		KC_D, 		KC_B, 		SH_LBRC,	SH_RBRC,	KC_M,		KC_H, 		KC_J, 		KC_V, 		LT_SLSH, 	KC_EQL,
						OS_UTL, 	LT(MEDIA,KC_ESC),LT(NAV,KC_SPC),LT(DANCELEFT,KC_TAB),	 	LT(DANCERIGHT,KC_ENT),LT(NUM,KC_BSPC),LT(FUN,KC_DEL),OS_UTL
	), [MIRYOKU] = LAYOUT(
KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		KC_Q,		KC_W,		KC_F,		KC_P,		KC_B,								KC_J,		KC_L,		KC_U,		KC_Y,		KC_QUOT,	KC_NO,
KC_NO, 		MOD_A,		MOD_R,		MOD_S,		MOD_T,		KC_G,					   	  		KC_K, 		MOD_N, 		MOD_E, 		MOD_I, 		MOD_O, 		KC_NO,
KC_NO,		KC_Z,		ALGR_T(KC_X),KC_C,		KC_D,		KC_V,		KC_NO,		KC_NO,		KC_M,		KC_H,		KC_COMM,	ALGR_T(KC_DOT),KC_SLSH	,KC_NO,
						LYR_HM,		LT(MEDIA,KC_ESC),LT(NAV,KC_SPC),LT(MOUSE,KC_TAB),			LT(SYM,KC_ENT),LT(NUM,KC_BSPC),LT(FUN,KC_DEL),LYR_HM
    ), [COLEMAK] = LAYOUT(
KC_ESC,		KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5,					   			KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_DEL, 	KC_Z,	 	KC_W, 		KC_F, 		KC_P, 		KC_COMM,							KC_DOT, 	KC_L, 		KC_U, 		KC_Y, 		KC_SCLN, 	KC_MINS,
KC_TAB, 	KC_A, 		KC_R, 		KC_S,		KC_T, 		KC_G,					   	  		KC_K, 		KC_N, 		KC_E, 		KC_I, 		KC_O, 		KC_QUOT,
KC_LALT, 	LT_Q, 		KC_X, 		KC_C, 		KC_D, 		KC_B, 		SH_LBRC,	SH_RBRC,	KC_M,		KC_H, 		KC_J, 		KC_V, 		KC_SLSH, 	KC_RSFT,
						KC_LCTL, 	KC_LGUI, 	KC_LSFT,	KC_SPC,							 	LT_ENT,		KC_BSPC, 	KC_DEL, 	OS_UTL
	), [QWERTY] = LAYOUT(
KC_ESC, 	KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 								KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_TAB, 	KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_T, 								KC_Y, 		KC_U, 		KC_I, 		KC_O, 		KC_P, 		KC_MINS,
KC_LSFT, 	KC_A, 		KC_S, 		KC_D, 		KC_F, 		KC_G, 								KC_H, 		KC_J, 		KC_K, 		KC_L, 		KC_SCLN, 	KC_QUOT,
KC_LCTL, 	KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 		SH_LBRC,	SH_RBRC,	KC_N, 		KC_M, 		KC_COMM, 	KC_DOT,		KC_SLSH,	KC_EXLM,
						KC_LALT, 	KC_LGUI, 	MO_L, 		KC_SPC, 							LT_ENT,		KC_BSPC, 	KC_RSFT, 	KC_DEL
// miryoku layers
	), [DANCELEFT] = LAYOUT( // mouse and mirrored
KC_GRV,		KC_0, 		KC_9, 		KC_8, 		KC_7, 		KC_6,					   			KC_5, 		KC_4, 		KC_3, 		KC_2, 		KC_1, 		KC_NO,
KC_MINS,	KC_SCLN,	KC_Y,		KC_U, 		KC_L, 		KC_DOT,								U_RDO,		U_PST,		U_CPY,		U_CUT,		U_UND,		KC_NO,
KC_QUOT, 	MOD_O,		MOD_I,		MOD_E,		MOD_N,		KC_K,					   	  		KC_NO,		KC_MS_L,	KC_MS_D,	KC_MS_U,	KC_MS_R,	KC_BTN1,
KC_EXLM,	LT_SLSH,	KC_V, 		KC_J, 		KC_H, 		KC_M, 		SH_LBRC,	SH_RBRC,	KC_NO,		KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,	KC_NO,
						LYR_HM,	 	LT(FUN,KC_DEL),LT(NUM,KC_BSPC),SH_T(KC_ENT),			 	KC_BTN1,	KC_BTN3,	KC_BTN2,	LYR_HM
	), [DANCERIGHT] = LAYOUT( // symbols and mirrored
KC_NO,		KC_0, 		KC_9, 		KC_8, 		KC_7, 		KC_6,					   			KC_5, 		KC_4, 		KC_3, 		KC_2, 		KC_1, 		KC_GRV,
KC_NO, 		KC_LCBR,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RCBR,							KC_COMM, 	KC_P, 		KC_F, 		KC_W, 		KC_Z,		KC_MINS,
KC_TAB,		KC_COLN,	KC_DLR,		KC_PERC,	KC_CIRC,	KC_PLUS,				   	  		KC_G, 		MOD_T, 		MOD_S, 		MOD_R, 		MOD_A, 		KC_QUOT,
KC_NO,		KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_PIPE,	SH_LBRC,	SH_RBRC,	KC_B,		KC_D, 		KC_C, 		KC_X, 		LT_Q, 		KC_EXLM,
						LYR_HM,	 	KC_LPRN,	KC_RPRN,	KC_UNDS,						 	SH_T(KC_TAB),LT(NAV,KC_SPC),LT(MEDIA,KC_ESC),LYR_HM
	), [NAV] = LAYOUT(
KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		RESET,		U_NA,		U_NA,		U_NA,		U_NA,								U_RDO,		KC_NO,		U_CPY,		U_CUT,		U_UND,		KC_NO,
KC_NO,		KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	U_NA,								KC_CAPS,	KC_LEFT,	KC_DOWN,	KC_UP,		KC_RGHT,	KC_NO,
KC_NO,		U_NA,		KC_ALGR,	U_NA,		U_NA,		U_NA,		KC_NO,		KC_NO,		KC_NO,		KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		KC_NO,
						KC_NO,		U_UND,		U_NA,		U_NA,								KC_ENT,		KC_BSPC,	KC_DEL,		KC_NO
	), [MOUSE] = LAYOUT(
KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		RESET,		U_NA,		U_NA,		U_NA,		U_NA,								U_RDO,		U_PST,		U_CPY,		U_CUT,		U_UND,		KC_NO,
KC_NO,		KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	U_NA,								KC_NO,		KC_MS_L,	KC_MS_D,	KC_MS_U,	KC_MS_R,	KC_NO,
KC_NO,		U_NA,		KC_ALGR,	U_NA,		U_NA,		U_NA,		KC_NO,		KC_NO,		KC_NO,		KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,	KC_NO,
						KC_NO,		U_NA,		U_NA,		U_NA,								KC_BTN1,	KC_BTN3,	KC_BTN2,	KC_NO
	), [MEDIA] = LAYOUT(
KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		RESET,		U_NA,		U_NA,		U_NA,		U_NA,								RGB_TOG,	RGB_MOD,	RGB_HUI,	RGB_SAI,	RGB_VAI,	KC_NO,
KC_NO,		KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	U_NA,								OUT_AUTO,	KC_MPRV,	KC_VOLD,	KC_VOLU,	KC_MNXT,	KC_NO,
KC_NO,		U_NA,		KC_ALGR,	U_NA,		U_NA,		U_NA,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_MUTE,    KC_MUTE,	KC_NO,		KC_NO,
						KC_NO,		U_NA,		U_NA,		U_NA,								KC_MSTP,	KC_MPLY,	KC_MUTE,	KC_NO
	), [NUM] = LAYOUT(
KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		KC_LBRC,	KC_7,		KC_8,		KC_9,		KC_RBRC,							KC_NO,		U_NA,		U_NA,		U_NA,		RESET,		KC_NO,
KC_NO,		KC_SCLN,	KC_4,		KC_5,		KC_6,		KC_EQL,								U_NA,		KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,	KC_NO,
KC_NO,		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_BSLS,	KC_NO,		KC_NO,		U_NA,		U_NA,		U_NA,		KC_ALGR,	U_NA,		KC_NO,
						KC_NO,		KC_DOT,		KC_0,		KC_MINS,							U_NA,		U_NA,		U_NA,		KC_NO
	), [SYM] = LAYOUT(
KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		KC_LCBR,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RCBR,							U_NA,		U_NA,		U_NA,		U_NA,		RESET,		KC_NO,
KC_NO,		KC_COLN,	KC_DLR,		KC_PERC,	KC_CIRC,	KC_PLUS,							U_NA,		KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,	KC_NO,
KC_NO,		KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_PIPE,	KC_NO,		KC_NO,		U_NA,		U_NA,		U_NA,		KC_ALGR,	U_NA,		KC_NO,
						KC_NO,		KC_LPRN,	KC_RPRN,	KC_UNDS,							U_NA,		U_NA,		U_NA,		KC_NO
	), [FUN] = LAYOUT(
KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 								KC_NO, 		KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO,
KC_NO,		KC_F12,		KC_F7,		KC_F8,		KC_F9,		KC_PSCR,							U_NA,		U_NA,		U_NA,		U_NA,		RESET,		KC_NO,
KC_NO,		KC_F11,		KC_F4,		KC_F5,		KC_F6,		KC_SLCK,							U_NA,		KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,	KC_NO,
KC_NO,		KC_F10,		KC_F1,		KC_F2,		KC_F3,		KC_PAUS,	KC_NO,		KC_NO,		U_NA,		U_NA,		U_NA,		KC_ALGR,	U_NA,		KC_NO,
						KC_NO,		KC_APP,		KC_SPC,		KC_TAB,								U_NA,		U_NA,		U_NA,		KC_NO
// modifier layers
	), [GAME] = LAYOUT(
KC_ESC, 	KC_1, 		KC_2, 		KC_3, 		KC_4, 		KC_5, 								KC_6, 		KC_7, 		KC_8, 		KC_9, 		KC_0, 		KC_GRV,
KC_GRV, 	KC_Y, 		KC_Q, 		KC_W, 		KC_E, 		KC_R, 								KC_U, 		KC_I, 		KC_UP, 		KC_O, 		KC_P, 		KC_MINS,
KC_TAB, 	KC_G, 		KC_A, 		KC_S, 		KC_D, 		KC_F, 								KC_RCTL, 	KC_LEFT,	KC_DOWN, 	KC_RGHT, 	KC_RSFT,	KC_QUOT,
KC_LALT, 	KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 		KC_F3,		KC_M,		KC_RALT, 	KC_K, 		KC_DOT, 	KC_SLSH, 	KC_SCLN, 	MO_L,
						KC_N, 		KC_H, 		KC_LCTL, 	KC_SPC,		 						KC_TRNS, 	KC_BSPC, 	KC_TRNS, 	TG(GAME)
	), [LEFT] = LAYOUT(
KC_F13, 	KC_F14,		KC_F15, 	KC_F16,		KC_F17, 	KC_F18, 							KC_F19, 	KC_F20, 	KC_F21, 	KC_F22, 	KC_F23, 	KC_F24,
KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_F5, 		KC_F6, 								KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12,
KC_CAPS,	KC_PSCR,	KC_CAPS,	KC_NO, 		KC_NO, 		OS_UTL,								KC_NO,	 	KC_NO,		KC_NO, 		KC_NO, 		KC_NO,		KC_NO,
KC_LCTL, 	KC_TRNS, 	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_BTN1,	KC_NO, 		KC_NO,		KC_PIPE, 	KC_PLUS, 	KC_BSLS, 	KC_EQL,
						KC_LALT,	KC_LGUI, 	KC_NO,		TO(GAME), 							KC_TRNS,	LYR_HM,		KC_TRNS, 	KC_TRNS
	), [RIGHT] = LAYOUT(
KC_PAUS, 	KC_NLCK, 	KC_P7, 		KC_P8, 		KC_P9, 		KC_PAST, 							KC_BTN1, 	KC_BTN1, 	KC_BTN2, 	KC_BTN3, 	KC_WH_D, 	KC_WH_U,
KC_INS, 	KC_NLCK, 	KC_P4, 		KC_P5, 		KC_P6, 		KC_PSLS, 							KC_MUTE, 	KC_VOLD, 	KC_VOLU,	KC_MRWD, 	KC_MFFD,	KC_MPLY,
KC_SLCK, 	KC_NLCK, 	KC_P1, 		KC_P2, 		KC_P3, 		KC_PPLS, 							KC_HOME, 	KC_LEFT, 	KC_DOWN, 	KC_UP,	 	KC_RGHT, 	KC_END,
KC_TRNS, 	KC_PSCR, 	KC_P0, 		KC_P0, 		KC_PDOT,	KC_PMNS,	KC_LOCK, 	OS_UTL,		KC_APP, 	KC_HOME, 	KC_PGDN, 	KC_PGUP, 	KC_BSLS, 	KC_EQL,
						KC_TRNS, 	KC_TRNS, 	KC_TRNS, 	KC_TRNS, 							KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
	), [UTILITY] = LAYOUT(
KC_ASTG,	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_SLEP, 							BOTTOM, 	KC_NO,	 	KC_NO, 		RESET, 		DEBUG, 		EEP_RST,
KC_ASUP,	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_WAKE, 							WHEART, 	GHEART,		HEART, 		NK_ON, 		GUI_ON,	 	GE_SWAP,
KC_ASDN,	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_PWR, 							SHRUG, 		KC_NO, 		KC_NO, 		NK_OFF,		GUI_OFF, 	GE_NORM,
KC_ASRP,	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		TO(COLEMAK),TO(QWERTY),	KC_NO,		KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,
						KC_F20,		KC_NO, 		OSM(MOD_HYPR),TO(DANSEN), 						TO(MIRYOKU),KC_NO,		KC_TRNS, 	KC_F20
)};

// default settings for when the keeb boots
void keyboard_post_init_user() {
    //	autoshift_disable();
    layer_on(DANSEN);
}
// per key configs
// mod tap/hold priority
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(MOUSE,KC_ESC):
            return false;

        case LT(NAV,KC_SPC):
            return false;

        case SH_T(KC_TAB):
            return false;

        case SH_T(KC_ENT):
            return false;

        case LT(NUM,KC_BSPC):
            return false;

        case LT(FUN,KC_DEL):
            return false;

        default:
            return true;
    }
}

// per key tap-hold timings
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
        case LT(1, KC_GRV):
            return 130;
        default:
            return TAPPING_TERM;
    }
}

// combos!
enum combo_events {
    WY_ESC,
    COMBO_LENGTH // must be last!
};

// get total combo by checking last enum value
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM wy_esc[] = {KC_W, KC_Y, COMBO_END};
combo_t key_combos[] = {
    [WY_ESC] = COMBO(wy_esc, KC_ESC)
};

// runs on keypress? listen i don't know how to code i don't understand why any of this compiles what the fuck help
// it is two years later, and i in fact, know how to code, and what a struct is. wack.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
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

// per layer settings
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        // base chill modes, simple
        // or at least what passes for simple for me
        case COLEMAK:
            //autoshift_disable();
            combo_disable();
            break;

        case QWERTY:
            //autoshift_disable();
            combo_disable();
            break;

        case GAME:
            //autoshift_disable();
            combo_disable();
            break;

        case UTILITY:
            break;

        case LEFT:
            combo_disable();
            break;

        case RIGHT:
            combo_disable();
            break;

            // miryoku style layers
        case DANSEN:
            //autoshift_enable();
            combo_enable();
            break;

        case MIRYOKU:
            //autoshift_enable();
            combo_enable();
            break;

        case DANCELEFT:
            break;

        case DANCERIGHT:
            break;

        case NAV:
            break;

        case MOUSE:
            break;

        case MEDIA:
            break;

        case NUM:
            break;

        case SYM:
            break;

        case FUN:
            break;

        default: //  for any other layers, or the default layer
            break;
    }
    return state;
}

