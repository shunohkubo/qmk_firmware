#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  1!  |  2@  |  3#  |  4$  |  5%  |      |           |      |  6^  |  7&  |  8*  |  9(  |  0)  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   `~   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  |   '"   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /?  |   -_   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | ESC  | KP2  |                                       | KP1  | =+   |      |      |      |
 *   |      |      |      | /LGui| /L1  |                                       | /L1  | /LAlt|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |  L2  |       |  L1  |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Del  |       | PgUp |        |      |
 *                                 | Space| Space|------|       |------| Enter  |Enter |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,       KC_1,   KC_2,   KC_3,           KC_4,          KC_5,     KC_NO,
        KC_TAB,       KC_Q,   KC_W,   KC_E,           KC_R,          KC_T,     KC_NO,
        KC_LCTL,      KC_A,   KC_S,   KC_D,           LT(MDIA, KC_F),KC_G,
        KC_LSFT,      KC_Z,   KC_X,   KC_C,           KC_V,          KC_B,     KC_NO,
        KC_NO,        KC_NO,  KC_NO,  GUI_T(KC_ESC),  LT(SYMB,KC_P2),

                                                      KC_NO,    TG(MDIA),
                                                                KC_DEL,
                                            KC_SPC,   KC_SPC,   KC_END,

        // right hand
        KC_NO,    KC_6,            KC_7,     KC_8,    KC_9,    KC_0,     KC_NO,
        KC_NO,    KC_Y,            KC_U,     KC_I,    KC_O,    KC_P,     KC_GRV,
                  KC_H,            KC_J,     KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_NO,    KC_N,            KC_M,     KC_COMM, KC_DOT,  KC_SLSH,  KC_MINS,
                  LT(SYMB,KC_P1),  ALT_T(KC_EQL),   KC_NO,   KC_NO,   KC_NO,

        TG(SYMB), KC_NO,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
    --------------------------------------------------             --------------------------------------------------
   |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   |-------- ------ ------ ------ ------ -------------|           |------ ------ ------ ------ ------ ------ --------|
   |        |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   |        |
   |-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
   |        |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |   BS   |
   |-------- ------ ------ ------ ------ ------|      |           |      |------ ------ ------ ------ ------ --------|
   |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    -------- ------ ------ ------ ------ -------------             ------------- ------ ------ ------ ------ --------
     |      |      |      |      |      |                                       |      |      |      |      |      |
     |      |      |      |      |      |                                       |      |      |      |      |      |
      ----------------------------------                                         ----------------------------------
                                           -------------         -------------
                                          |      |      |       |      |        |
                                    ------|------|------|       |------ -------- ------
                                   |      |      |      |       |      |        |      |
                                   |      |      |------|       |------|        |      |
                                   |      |      |      |       |      |        |      |
                                    --------------------         ----------------------
 */
// SYMB
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,     KC_F4,     KC_F5,    KC_TRNS,
       KC_TRNS,  S(KC_1),  S(KC_2),  S(KC_3),   S(KC_4),   S(KC_5),  KC_TRNS,
       KC_TRNS,  KC_1,     KC_2,     KC_3,      KC_4,      KC_5,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,

                                                         KC_TRNS,  KC_TRNS,
                                                                   KC_TRNS,
                                               KC_TRNS,  KC_TRNS,  KC_TRNS,

       // right hand
       KC_TRNS,  KC_F6,    KC_F7,          KC_F8,          KC_F9,         KC_F10,       KC_TRNS,
       KC_TRNS,  S(KC_6),  S(KC_7),        S(KC_8),        S(KC_9),       S(KC_0),      KC_BSLS,
                 KC_6,     KC_7,           KC_8,           KC_9,          KC_0,         KC_BSPC,
       KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,      KC_TRNS,
                           KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,      KC_TRNS,

       KC_TRNS,  KC_TRNS,
       KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |  [   |  ]   |  {   |  }   |  \   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| LEFT | DOWN |  UP  | RIGHT|  |   |  BS    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Reset|      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_U,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    RESET,    KC_TRNS,  KC_TRNS,  KC_BTN1,  KC_BTN2,

                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                            KC_TRNS,  KC_TRNS,  KC_TRNS,

    // right hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_LBRC,  KC_RBRC,  S(KC_LBRC),S(KC_RBRC),KC_BSLS,  KC_TRNS,
              KC_LEFT,  KC_DOWN,  KC_UP,     KC_RGHT,   KC_PIPE,  KC_BSPC,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,   KC_MNXT,   KC_TRNS,  KC_TRNS,
                        KC_VOLU,  KC_VOLD,   KC_MUTE,   KC_TRNS,  KC_TRNS,

    KC_TRNS,  KC_TRNS,
    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

