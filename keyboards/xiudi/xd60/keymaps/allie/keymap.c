#include QMK_KEYBOARD_H
#include "action_layer.h"

// define layers
enum layer_number {
    QWERTY,
    LOWER,
    RAISE,
};

// define custom keycodes for macros, etc
enum custom_keycodes {
    HEART = SAFE_RANGE,
    BOTTOM,
    SHRUG,
    LENNY,
};

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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // 0: Base Layer
  LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_GRV,   KC_DEL,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_TRNS,           KC_ENT,    \
      KC_LSFT, KC_TRNS, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_SLSH, KC_UP,    MO(LOWER), \
      KC_LCTL, KC_LALT, KC_LGUI,                          KC_SPC,                          KC_HOME, KC_END,   KC_LEFT, KC_DOWN,  KC_RIGHT),
  // 1: Lower
  LAYOUT_all(
      TO(0),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,   KC_PAUS,  \
      TO(0),   BL_TOGG, BL_STEP, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_VOLD, KC_VOLU,            KC_MUTE,  \
      KC_DEL,  HEART,   BOTTOM,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_TRNS, CL_NORM,            KC_TRNS,  \
      KC_CAPS, UC(0x203D),UC(0x2E2E),SHRUG,LENNY,  KC_BTN3, KC_BTN2, KC_HOME, KC_END,  KC_WH_U, KC_WH_R, KC_TRNS, TG(RAISE),KC_PGUP,  KC_TRNS,  \
      CMB_TOG, VLK_TOG, KC_TRNS,                            KC_BTN1,                            KC_TRNS, KC_TRNS, KC_HOME, KC_PGDOWN, KC_END),
  // 2: Raise
  LAYOUT_all(
      TO(0),   KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_TRNS,   EE_CLR,  \
      TO(0),   KC_PWR,  KC_SLEP, KC_WAKE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,  \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, TG(RAISE),KC_TRNS,  KC_TRNS,  \
      KC_TRNS, KC_TRNS, KC_TRNS,                            KC_BTN1,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS),
};

// combos!
enum combo_events {
    TABDEL_LAYER,
    FJ_ESC,
    COMBO_LENGTH // must be last!
const uint16_t PROGMEM tabdel_layer[] = {KC_TAB, KC_BSPC, COMBO_END};
const uint16_t PROGMEM fj_esc[] = {KC_F, KC_J, COMBO_END};
//combo actions
combo_t key_combos[] = {
    [TABDEL_LAYER] = COMBO(tabdel_layer, TG(LOWER)),
    [FJ_ESC] = COMBO(fj_esc, KC_ESC),
};

// rgb layer functions
const rgblight_segment_t PROGMEM rgb_layer_caps[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},      // Light 1 LED, starting with LED 0
    {5, 2, HSV_RED},      // led 0 is bottom left, it goes counter clockwise
    {11,1, HSV_RED}      // so this lights all corners
);
const rgblight_segment_t PROGMEM rgb_layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 6, HSV_AZURE}
);
// define the array of layers-later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        rgb_layer_1,
        rgb_layer_2,
        rgb_layer_caps
);

// update rgb on state change
bool led_update_user(led_t led_state) {
    // the 1 below is the position in the rgb_layers array
    rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}

// runs on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    // update rgb
    rgblight_set_layer_state(0, layer_state_cmp(state, LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(state, RAISE));
    // per layer settings
    switch (get_highest_layer(state)) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}

// runs on key event
// read record->event and keycode for specifics 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // macros
    switch (keycode) {
        case HEART:
            if (record->event.pressed)
                SEND_STRING(":heart:");
            break;
        case BOTTOM:
            if (record->event.pressed)
                SEND_STRING(":point_right::point_left::pleading_face:");
            break;
        case SHRUG:
            if (record->event.pressed)
                send_unicode_string("¯\\_(ツ)_/¯");
            break;
        case LENNY:
            if (record->event.pressed)
                send_unicode_string("( ͡° ͜ʖ ͡°)");
            break;
    }

  }
  return true;
}

// runs on keeb boot
void keyboard_post_init_user() {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    combo_enable();
}
