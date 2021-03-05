#include <print.h>
#include "vimmode.h"

#include QMK_KEYBOARD_H

#define LAYOUT_L3af( \
  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0e, \
  k10, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
  k20, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c,      k2d, \
  k30, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,      k3d, k3e, \
  k40, k41, k43,                k46,                k4a, k4b, k4d, k4e, \
) { \
  { k00,  k01,   k02,   k03,  k04,   k05,   k06,  k07,   k08,   k09,   k0a,  k0b,  k0c,   KC_NO, k0e   }, \
  { k10,  KC_NO, k12,   k13,  k14,   k15,   k16,  k17,   k18,   k19,   k1a,  k1b,  k1c,   k1d,   k1e   }, \
  { k20,  KC_NO, k22,   k23,  k24,   k25,   k26,  k27,   k28,   k29,   k2a,  k2b,  k2c,   k2d,   KC_NO }, \
  { k30,  KC_NO, k32,   k33,  k34,   k35,   k36,  k37,   k38,   k39,   k3a,  k3b,  KC_NO, k3d,   k3e   }, \
  { k40,  k41,   KC_NO, k43,  KC_NO, KC_NO, k46,  KC_NO, KC_NO, KC_NO, k4a,  k4b,  KC_NO, k4d,   k4e   }  \
}

#define HANDLE_SHIFTED(base_key, shifted_key) case base_key: \
    if (record->event.pressed){                              \
      if (SHIFT_HELD){                                       \
        register_code(shifted_key);                          \
      } else {                                               \
        register_code(base_key);                             \
      }                                                      \
    } else {                                                 \
      unregister_code(base_key);                             \
      unregister_code(shifted_key);                          \
    }                                                        \
    return true;

enum layers {
  _DVP,
  _QTY,
  _FN,
  _VIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* DVP
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │$ ~│& %│[ 7│{ 5│} 3│( 1│= 9│* 0│) 2│+ 4│] 6│! 8│# `│ Bckspc│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │Tab  │; :│, <│. >│ P │ Y │ F │ G │ C │ R │ L │/ ?│@ ^│ \ | │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │(v)Esc│ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │- _│  Return│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │Shift   │" '│ Q │ J │ K │ X │ B │ M │ W │ V │ Z │ Shift│   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │Ctrl│Win │Alt │           Space            │Ldr│Vim│Fn │QWT│
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_DVP] = LAYOUT_L3af( \
    KC_DLR,  KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL, KC_PAST, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH, KC_BSPC, \
    KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_AT,   KC_BSLS, \
    VIM_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,  \
    KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,             KC_RSFT, _______, \
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                            KC_LEAD, VIM_TGL, TT(_FN), DF(_QTY) \
  ),


  /* QWERTY
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │` ~│1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│ Bckspc│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│} ]│ \ | │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │(v)Esc│ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│  Return│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│ Shift│   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │Ctrl│Win │Alt │           Space            │Ldr│Vim│Fn │DVP│
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_QTY] = LAYOUT_L3af( \
    KC_GRV,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    VIM_ESC, KC_A,    KC_L,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_RSFT, _______, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                        KC_LEAD, VIM_TGL, TT(_FN), DF(_DVP) \
  ),


  /* Function
   * 
   * TODO: Test which of these actually work
   *
   * Prefixes
   *   Bl: Backlight
   *     B: Breathe
   *     T: Toggle
   *     C: Cycle
   *   R: RGB
   *     H: Hue
   *     S: Saturation
   *     B: Brightness
   *     E: Effect
   *     M: Mode
   *       >: Next
   *       <: Previous
   *       P: Plain
   *       S: Snake
   *       B: Breathe
   *       X: Christmas
   *       R: Rainbow
   *       G: Gradient
   *       O: Swirl
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Delete│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │F13│F14│F15│F16│F17│F18│F19│F20│F21│F22│F23│F24│     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │Bl+   │BlB│BlT│RH+│RS+│RB+│RE+│RM>│RMP│RMB│RMR│RMO│  Insert│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │Bl-     │BlC│RgT│RH-│RS-│RB-│RB-│RM<│RMS│RMX│RMG│      │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │    │    │    │                            │   │   │   │   │
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_FN] = LAYOUT_L3af( \
    KS_NO,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,  KC_F11,   KC_F12, KC_Del,\
    KS_NO,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,   KC_F20,   KC_F21,  KC_F22,  KC_F23,   KC_F24, KS_NO, \
    BL_INC, BL_BRTG, BL_TOGG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,  RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW,         KC_INS,  \
    BL_DEC, BL_STEP, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD, RGB_M_SN, RGB_M_X, RGB_M_G,           _______, _______, \
    _______, _______, _______,                           _______,                              _______, _______,  _______, _______  \
  )

  // TODO: Figure out what this is used for
  [_VIM] = LAYOUT_L3af( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______, \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool vim_handled = handle_vim_mode(keycode, record, _VIM);
  if (vim_handled)
    return false;

  if (IS_LAYER_ON(_DVP)) {
    switch (keycode) {
      HANDLE_SHIFTED(KC_DLR,  KC_TILD)
      HANDLE_SHIFTED(KC_AMPR, KC_PERC)
      HANDLE_SHIFTED(KC_LBRC, KC_7)
      HANDLE_SHIFTED(KC_LCBR, KC_5)
      HANDLE_SHIFTED(KC_RCBR, KC_3)
      HANDLE_SHIFTED(KC_LPRN, KC_1)
      HANDLE_SHIFTED(KC_EQL,  KC_9)
      HANDLE_SHIFTED(KC_ASTR, KC_0)
      HANDLE_SHIFTED(KC_RPRN, KC_2)
      HANDLE_SHIFTED(KC_PLUS, KC_4)
      HANDLE_SHIFTED(KC_RBRC, KC_6)
      HANDLE_SHIFTED(KC_EXLM, KC_8)
      HANDLE_SHIFTED(KC_HASH, KC_GRV)
      HANDLE_SHIFTED(KC_AT,   KC_CIRC)
    }
  } 

  return true;
}

void matrix_init_user(void) {

}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;

    SEQ_ONE_KEY(KC_E) {
      SEND_STRING("Hi");
    } else 
    SEQ_TWO_KEYS(KC_E, KC_D) {
      SEND_STRING("Hi 2");
    }

    leader_end();
  }
}

void led_set_user(uint8_t usb_led) {

} 
