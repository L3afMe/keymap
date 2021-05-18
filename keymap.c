#include "vimmode.c"

#include QMK_KEYBOARD_H

enum layers {
  _SEL,
  _DVK,
  _DVK_FN,
  _DVK_MS,
  _QTY,
  _QTY_FN,
  _QTY_MS,
  _VIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layout Select
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │DVK│QTY│   │   │   │   │   │   │   │   │   │   │       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │   │   │   │   │   │   │   │   │   │   │      │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │    │    │    │                            │   │   │   │   │
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_SEL] = LAYOUT_60_ansi_split_rshift( \
    KC_NO,   DF(_DVK), DF(_QTY), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO, \
    KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO, \
    KC_NO,   KC_NO,    KC_NO,                               KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO  \
  ),


  /* Dvorak Modified
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │` ~│1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│[ {│} ]│ Bckspc│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │Tab  │; :│, <│. >│ P │ Y │ F │ G │ C │ R │ L │/ ?│= +│  \  │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │(v)Esc│ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │- _│  Return│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │LShift  │' "│ Q │ J │ K │ X │ B │ M │ W │ V │ Z │LShift│ Fn│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │Ctrl│Win │Alt │           Space            │Ldr│Vim│Fn │Sel│
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_DVK] = LAYOUT_60_ansi_split_rshift( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,     \
    KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,     \
    VIM_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,      \
    KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,             KC_RSFT, MO(_DVK_FN), \
    KC_LCTL, MO(_DVK_FN), KC_LALT,                        KC_SPC,                         KC_RALT, VIM_TGL, TT(_DVK_MS), DF(_SEL)     \
  ),


  /* Dvorak Function
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│    Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │  │ ﯦ │  │   │   │   │   │   │   │  │   │   │  Rst│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │CpsLck│ ﱜ │ ﱛ │ ﱝ │   │   │   │  │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │   │   │  │  │   │   │   │   │   │   │      │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │    │    │Win │                            │   │   │   │   │
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_DVK_FN] = LAYOUT_60_ansi_split_rshift( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
    _______, RGB_TOG, RGB_MOD, RGB_HUI, _______, _______, _______, _______, _______, _______, KC_RGHT, _______, _______, RESET,   \
    KC_ESC,  KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_LEFT, _______, _______, _______, _______,          _______, \
    _______, _______, _______, KC_DOWN, KC_UP,   _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, KC_LGUI,                            _______,                            _______, KC_PWR,  KC_SLEP, KC_WAKE  \
  ),


  /* Dvorak Mouse
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │S │   │   │  │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │S │S │   │   │  │   │   │S │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │   │   │  │  │   │   │   │   │   │   │      │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │RClk│    │    │              LClk          │   │   │   │Bck│
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_DVK_MS] = LAYOUT_60_ansi_split_rshift( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_L, KC_NO,   KC_NO,   KC_MS_R, KC_NO,   KC_NO,   KC_NO,      \
    KC_NO,   KC_NO,   KC_NO,   KC_WH_D, KC_WH_U, KC_NO,   KC_NO,   KC_MS_L, KC_NO,   KC_NO,   KC_WH_R, KC_NO,            KC_NO,      \
    KC_NO,   KC_NO,   KC_NO,   KC_MS_D, KC_MS_U, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,      \
    KC_BTN2, KC_NO,   KC_NO,                              KC_BTN1,                            KC_NO,   KC_NO,   KC_NO,   TG(_DVK_MS) \
  ),


  /* QWERTY
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │` ~│1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│ Bckspc│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│} ]│ \ | │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │(v)Esc│ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│  Return│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │LShift  │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│RShift│   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │Ctrl│Win │Alt │           Space            │Ldr│Vim│Fn │Sel│
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_QTY] = LAYOUT_60_ansi_split_rshift( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,     \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,     \
    VIM_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,      \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(_QTY_FN), \
    KC_LCTL, MO(_QTY_FN), KC_LALT,                        KC_SPC,                         KC_RALT, VIM_TGL, TT(_QTY_MS), DF(_SEL)     \
  ),


  /* QWERTY Function
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│    Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │  │ ﯦ │  │   │   │   │   │   │   │   │   │   │  Rst│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │ ﱜ │ ﱛ │ ﱝ │   │   │   │  │  │  │  │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │   │   │   │   │   │   │   │   │   │   │      │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │    │    │Win │                            │   │   │   │   │
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_QTY_FN] = LAYOUT_60_ansi_split_rshift( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
    _______, RGB_TOG, RGB_MOD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
    KC_ESC,  KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, KC_LGUI,                            _______,                            _______, KC_PWR,  KC_SLEP, KC_WAKE  \
  ),


  /* QWERTY Mouse
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │S │S │S │S │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │Cl1│Cl2│Cl3│Cl4│Cl5│   │  │  │  │  │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │   │   │   │   │   │   │   │   │   │   │      │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │    │    │    │                            │   │   │   │Bck│
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_QTY_MS] = LAYOUT_60_ansi_split_rshift( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_NO,   KC_NO,      \
    KC_NO,   KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,            KC_NO,      \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,      \
    KC_NO,   KC_NO,   KC_NO,                              KC_NO,                              KC_NO,   KC_NO,   KC_NO,   TG(_QTY_MS) \
  ),


  /* Vim Mode
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
   * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │   │   │   │   │   │   │   │   │   │   │   │        │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
   * │        │   │   │   │   │   │   │   │   │   │   │RShift│   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬───┼───┤
   * │    │    │    │                            │   │   │   │   │
   * └────┴────┴────┴────────────────────────────┴───┴───┴───┴───┘
   */
  [_VIM] = LAYOUT_60_ansi_split_rshift( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_RSFT, _______, \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______  \
  )
};

bool vim_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VIM_TGL:
      vim_enabled = !vim_enabled;
      return false;
    case VIM_ESC:
      if (!vim_enabled) { 
        register_code(KC_ESC);
        unregister_code(KC_ESC);
        return false;
      }
  }

  if (vim_enabled && handle_vim_mode(keycode, record, _VIM)) 
      return false;

  return true;
}

void matrix_init_user(void) {
  rgblight_mode(1);
  SET_TOP_ROW(HSV_BLUE);
  SET_BOTTOM_ROW(HSV_BLUE);

