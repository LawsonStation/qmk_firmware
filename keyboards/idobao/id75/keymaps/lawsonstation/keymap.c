/* Copyright 2018 Milton Griffin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Keyboard Layers
#define _QW 0
#define _RS 1
#define _LW 2
#define _FN 3

// Define macros
// Left-hand home row mods (QWERTY)
#define GUI_D LGUI_T(KC_D)
#define ALT_S LALT_T(KC_S)
#define SFT_F LSFT_T(KC_F)
#define CTL_V LCTL_T(KC_V)

// Right-hand home row mods (QWERTY)
#define CTL_M LCTL_T(KC_M)
#define SFT_J LSFT_T(KC_J)
#define ALT_L LALT_T(KC_L)
#define GUI_K LGUI_T(KC_K)

// Left-hand home row mods (Number and Function)
#define CTL_3 LCTL_T(KC_3)
#define ALT_4 LALT_T(KC_4)
#define GUI_5 LGUI_T(KC_5)
#define SFT_6 LSFT_T(KC_6)

#define CTL_F3 LCTL_T(KC_F3)
#define ALT_F4 LALT_T(KC_F4)
#define GUI_F5 LGUI_T(KC_F5)
#define SFT_F6 LSFT_T(KC_F6)

// Right-hand home row mods 

#define CTL_PU LCTL_T(KC_PGUP)
#define ALT_RT LALT_T(KC_RGHT)
#define GUI_UP LGUI_T(KC_UP)
#define SFT_DN LSFT_T(KC_DOWN)


// Other keycodes
#define CTL_ESC LCTL_T(KC_ESC)	

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | MS W D | MS U   | MS W U | Y      | U      | I      | O      | P      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CTLESC | A      | S/Alt  | D/GUI  | F/SFT  | G      | MS L   | MS D   | MS R   | H      | J/SFT  | K/GUI  | L/ALT  | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V/CTL  | B      | MS B L | MS B M | MS B R | N      | M/CTL  | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | FN     | LGUI   | LALT   | LOWER  | SPACE  |        |        |        | ENTER  | RAISE  | BACKSP | DELETE | PG DN  | PG UP  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_WH_D, KC_MS_U, KC_WH_U, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    CTL_ESC, KC_A,    ALT_S,   GUI_D,   SFT_F,   KC_G,    KC_MS_L, KC_MS_D, KC_MS_R, KC_H,    SFT_J,   GUI_K,   ALT_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    CTL_V,   KC_B,    KC_BTN1, KC_BTN3, KC_BTN2, KC_N,    CTL_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, MO(_LW), KC_SPC,  _______, _______, _______, KC_ENT,  MO(_RS), KC_BSPC, KC_DEL,  KC_PGDN, KC_PGUP
 ),

/* RAISE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      |        |       |        | 6      | 7      | 8      | 9      | 0       | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | \      | 7      | 8      | 9      | [      |        |        |        | ]      | +      | -      | *      | /      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | =      | 4/Alt  | 5/GUI  | 6/SFT  | (      |        |        |        | )      | Shift  | GUI    | Alt    | $      | %      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | -      | 1      | 2      | 3/CTL  | `      |        |        |        | =      | Ctrl   | ,      | .      | /      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | .      | 0      |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_RS] = LAYOUT_ortho_5x15( /* RAISE */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_BSLS, KC_7,    KC_8,    KC_9,    KC_LBRC, _______, _______, _______, KC_RBRC, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_MINS,
    _______, KC_EQL,  ALT_4,   GUI_5,   SFT_6,   KC_LPRN, _______, _______, _______, KC_RPRN, KC_LSFT, KC_LGUI, KC_LALT, KC_DLR,  KC_PERC,
    _______, KC_MINS, KC_1,    KC_2,    CTL_3,   KC_GRV,  _______, _______, _______, KC_EQL,  KC_LCTL, KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, KC_DOT,  KC_0,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

 /* LOWER
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F12    | F7     | F8     | F9     |        |        |        |        | PREV   | VOL-   | VOL+   | NEXT   | MUTE   | PLAY   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F11    | F4     | F5     | F6     |        |        |        |        | LEFT   | DOWN   | UP     | RIGHT  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F10    | F1     | F2     | F3     |        |        |        |        | HOME   | PG UP  | PG DN  | END    |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |       |         |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_LW] = LAYOUT_ortho_5x15( /* LOWER */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_MPLY,
    _______, KC_F11,  ALT_F4,  GUI_F5,  SFT_F6,  _______, _______, _______, _______, KC_LEFT, SFT_DN,  GUI_UP,  ALT_RT,  _______, _______,
    _______, KC_F10,  KC_F1,   KC_F2,   CTL_F3,  _______, _______, _______, _______, KC_HOME, CTL_PU,  KC_PGDN, KC_END,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

 /* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | QK_BOOT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPS   | HUE+   | SAT+   | BRGTH+ |        |        |        |        |        |        |        |        |        |        | PLAY   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LSHIFT | RGBTOG | RGBPLN | RGBBRT |        |        |        |        |        |        |        |        |        |        | MUTE   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | PREV   | VOL-   | VOL+   | NEXT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_CAPS, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,
    KC_LSFT, RGB_TOG, RGB_M_P, RGB_M_B, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MNXT
 ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      // Macro for Shift + Backspace keys to send (forward) Delete.
      // Source: https://getreuer.info/posts/keyboards/macros3/index.html#shift-backspace-delete
      case KC_BSPC: {
        static uint16_t registered_key = KC_NO;
        if (record->event.pressed) {  // On key press.
          const uint8_t mods = get_mods();
        #ifndef NO_ACTION_ONESHOT
          uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
        #else
          uint8_t shift_mods = mods & MOD_MASK_SHIFT;
        #endif  // NO_ACTION_ONESHOT
          if (shift_mods) {  // At least one shift key is held.
            registered_key = KC_DEL;
            // If one shift is held, clear it from the mods. But if both
            // shifts are held, leave as is to send Shift + Del.
            if (shift_mods != MOD_MASK_SHIFT) {
        #ifndef NO_ACTION_ONESHOT
              del_oneshot_mods(MOD_MASK_SHIFT);
        #endif  // NO_ACTION_ONESHOT
              unregister_mods(MOD_MASK_SHIFT);
            }
          } else {
            registered_key = KC_BSPC;
          }

          register_code(registered_key);
          set_mods(mods);
        } else {  // On key release.
          unregister_code(registered_key);
        }
    } return false;
      }
    return true;
};