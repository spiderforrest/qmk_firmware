#include QMK_KEYBOARD_H
#include "action_layer.h"

// define layers as enums
enum layer_number {
    QWERTY,
    LOWER,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


//====================TODO=========================
// done! for now

// CURRENT KEYCAP LAYOUT
/*,-----------------------------------------------------------.
* |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| `| DEL|
* |-----------------------------------------------------------|
* |  Tab|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
* |-----------------------------------------------------------|
* |  BSPC|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
* |-----------------------------------------------------------|
* |  Shift|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|   /?  | Up| LOWER|
* |-----------------------------------------------------------|
* |Ctrl| Alt| Super|       Space       |  HM|  END| LT| DN| RT|
* `-----------------------------------------------------------'*/

  // 0: Base Layer
  LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_GRV,   KC_DEL,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_SLSH, KC_UP,    MO(1),
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_HOME, KC_END,   KC_LEFT, KC_DOWN,  KC_RIGHT),

  // 1: Function Layer
  LAYOUT_all(
      QK_RBT , KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_INS,   KC_DEL,
      KC_NO,   KC_WH_U, KC_MS_UP,KC_WH_D, KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_SLCK,  KC_PAUS,           KC_PSCR,
      KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_BTN2, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_PGUP,  KC_NO,             KC_ENT,
      KC_LSFT, KC_NO,   RGB_TOG, RGB_MOD, RGB_HUI,    RGB_SAI,RGB_VAI,RGB_SPI,KC_MUTE,KC_VOLD, KC_VOLU, KC_PGDN,  KC_RSFT, KC_PGUP,  KC_INS,
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_MS_BTN1,                          KC_RGUI, KC_RCTL,  KC_HOME, KC_PGDOWN,KC_END),

};



// LIGHTING ===============================================

// caps lock indication lighting
const rgblight_segment_t PROGMEM capslockLighting[] = RGBLIGHT_LAYER_SEGMENTS (
    {0, 1, HSV_RED},      // Light 1 LED, starting with LED 0
    {5, 2, HSV_RED},      // led 0 is bottom left, it goes counter clockwise
    {11,1, HSV_RED}      // so this lights all corners
);

// function layer indication lighting
const rgblight_segment_t PROGMEM funcLayerLighting[] = RGBLIGHT_LAYER_SEGMENTS (

    {0, 2, HSV_PURPLE},      // Light 1 LED, starting with LED 0
    {4, 2, HSV_PURPLE}      // led 0 is bottom left, it goes counter clockwise
);


// define array of layers; first layer lowest precedence, last layer highest
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslockLighting,
    funcLayerLighting
);


bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    return state;
}


// runs when keeb boots
void keyboard_post_init_user(void) {
    // enable LED layers
    rgblight_layers = my_rgb_layers;
}
