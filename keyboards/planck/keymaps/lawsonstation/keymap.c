/* Copyright 2015-2021 Jack Humbert
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

// #ifdef AUDIO_ENABLE
// #    include "muse.h"
// #endif

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  // _DVORAK,
  _LOWER,
  _RAISE,
  // _PLOVER,
  _ADJUST,
  _FUNCTION
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FUNCTION
  // DVORAK,
  // PLOVER,
  // BACKLIT,
  // EXT_PLV
};

// Define macros
// Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FUNCTION MO(_FUNCTION)

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

// TODO: Create Colemak-DHM home row mods

// Left-hand home row mods (Number and Function)
#define CTL_3 LCTL_T(KC_3)
#define ALT_4 LALT_T(KC_4)
#define GUI_5 LGUI_T(KC_5)
#define SFT_6 LSFT_T(KC_6)

#define CTL_F3 LCTL_T(KC_F3)
#define ALT_F4 LALT_T(KC_F4)
#define GUI_F5 LGUI_T(KC_F5)
#define SFT_F6 LSFT_T(KC_F6)

#define CTL_PU LCTL_T(KC_PGUP)
#define ALT_RT LALT_T(KC_RGHT)
#define GUI_UP LGUI_T(KC_UP)
#define SFT_DN LSFT_T(KC_DOWN)

// Right-hand home row mods 

// Other keycodes
#define LCTL_ESC LCTL_T(KC_ESC)	

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Adjust| GUI  | Alt  |Lower |Space |Enter |Raise | Bksp | Del  |Pg Dn |Pg Up |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,     KC_MINS,
    LCTL_ESC, KC_A,     ALT_S,    GUI_D,    SFT_F,    KC_G,     KC_H,     SFT_J,    GUI_K,   ALT_L,   KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     CTL_V,    KC_B,     KC_N,     CTL_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
    KC_LCTL,  FUNCTION, KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,   KC_ENT,   RAISE,    KC_BSPC, KC_DEL,  KC_PGDN,  KC_PGUP
),

/* Colemak (DHm)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtlEsc|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Adjust| GUI  | Alt  |Lower |Space |Enter |Raise | Bksp | Del  |Pg Dn |Pg Up |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_MINS,
    LCTL_ESC, KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT ,
    KC_LCTL,  FUNCTION, KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,   KC_ENT,   RAISE,    KC_BSPC,  KC_DEL,   KC_PGDN,  KC_PGUP
),

// /* Dvorak
//  * ,-----------------------------------------------------------------------------------.
//  * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Bksp | Down |  Up  |Right |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_DVORAK] = LAYOUT_planck_grid(
//     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
//     KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
//     KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
//     BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

/* Lower (Navigation and Function)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F12 |  F7  |  F8  |  F9  |      |MdaPrv|VolDn |Volup |MdaNxt|VolMut|MdaPP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F10 |  F1  |  F2  |  F3  |      | Home |Pg Up |Pg Dn | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______,  KC_F12,   KC_F7,    KC_F8,    KC_F9,    XXXXXXX,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  KC_MPLY,
    _______,  KC_F11,   KC_F4,    KC_F5,    KC_F6,    XXXXXXX,  KC_LEFT,  SFT_DN,   GUI_UP,   ALT_RT,   XXXXXXX,  XXXXXXX,
    _______,  KC_F10,   KC_F1,    KC_F2,    KC_F3,    XXXXXXX,  KC_HOME,  CTL_PU,   KC_PGDN,  KC_END,   XXXXXXX,  XXXXXXX,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

/* Raise (Numbers)
 * ,-----------------------------------------------------------------------------------.
 * |      |   \  |   7  |   8  |   9  |   [  |   ]  |   +  |   -  |   *  |   /  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   =  |   4  |   5  |   6  |   (  |   )  | Shift| GUI  | Alt  |   $  |  %   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   -  |   1  |   2  |   3  |   `  |   =  | Ctrl |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______,  KC_BSLS,  KC_7,     KC_8,     KC_9,     KC_LBRC,  KC_RBRC,  KC_PPLS,  KC_PMNS,  KC_PAST,  KC_PSLS,  KC_MINS,
    _______,  KC_EQL,   ALT_4,    GUI_5,    SFT_6,    KC_LPRN,  KC_RPRN,  KC_LSFT,  KC_LGUI,  KC_LALT,  KC_DLR,   KC_PERC,
    _______,  KC_MINS,  KC_1,     KC_2,     CTL_3,    KC_GRV,   KC_EQL,   KC_LCTL,  KC_COMM,  KC_DOT,   KC_SLSH,  _______,
    _______,  _______,  _______,  KC_DOT,   KC_0,     _______,  _______,  _______,  _______,  _______,  _______,  _______
),

// /* Plover layer (http://opensteno.org)
//  * ,-----------------------------------------------------------------------------------.
//  * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
//  * `-----------------------------------------------------------------------------------'
//  */
// [_PLOVER] = LAYOUT_planck_grid(
//     KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
//     XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
//     XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//     EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
// ),

/* Adjust (Lower + Raise) (Function Keys)
 * ,-----------------------------------------------------------------------------------.
 * |      | F12  |  F7  |  F8  |  F9  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F11  |  F4  |  F5  |  F6  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F10  |  F1  |  F2  |  F3  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX,  KC_F12,   KC_F7,    KC_F8,    KC_F9,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_F11,   KC_F4,    KC_F5,    KC_F6,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_F10,   KC_F1,    KC_F2,    KC_F3,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Qwerty|Colemk|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CapsL| HUE+ | SAT+ |BRGTH+|      |      |      |      |      |      |      | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|RGBTOG|RGBPLN|RGBBRT|      |      |      |      |      |      |      | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_grid(
    QK_BOOT,  QWERTY,   COLEMAK,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    KC_CAPS,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MPLY,
    KC_LSFT,  RGB_TOG,  RGB_M_P,  RGB_M_B,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MUTE,
    XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MRWD,  KC_VOLD,  KC_VOLU,  KC_MNXT

)

};

// #ifdef AUDIO_ENABLE
//   float plover_song[][2]     = SONG(PLOVER_SOUND);
//   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
// #endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;

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
    
//     case DVORAK:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_DVORAK);
//       }
//       return false;
//       break;
//     case BACKLIT:
//       if (record->event.pressed) {
//         register_code(KC_RSFT);
//         #ifdef BACKLIGHT_ENABLE
//           backlight_step();
//         #endif
//         #ifdef KEYBOARD_planck_rev5
//           writePinLow(E6);
//         #endif
//       } else {
//         unregister_code(KC_RSFT);
//         #ifdef KEYBOARD_planck_rev5
//           writePinHigh(E6);
//         #endif
//       }
//       return false;
//       break;
//     case PLOVER:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//           PLAY_SONG(plover_song);
//         #endif
//         layer_off(_RAISE);
//         layer_off(_LOWER);
//         layer_off(_ADJUST);
//         layer_on(_PLOVER);
//         if (!eeconfig_is_enabled()) {
//             eeconfig_init();
//         }
//         keymap_config.raw = eeconfig_read_keymap();
//         keymap_config.nkro = 1;
//         eeconfig_update_keymap(keymap_config.raw);
//       }
//       return false;
//       break;
//     case EXT_PLV:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_gb_song);
//         #endif
//         layer_off(_PLOVER);
//       }
//       return false;
//       break;
  }
  return true;
}

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_DOWN);
//       #else
//         tap_code(KC_PGDN);
//       #endif
//     } else {
//       #ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_UP);
//       #else
//         tap_code(KC_PGUP);
//       #endif
//     }
//   }
//     return true;
// }

// bool dip_switch_update_user(uint8_t index, bool active) {
//     switch (index) {
//         case 0: {
// #ifdef AUDIO_ENABLE
//             static bool play_sound = false;
// #endif
//             if (active) {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_song); }
// #endif
//                 layer_on(_ADJUST);
//             } else {
// #ifdef AUDIO_ENABLE
//                 if (play_sound) { PLAY_SONG(plover_gb_song); }
// #endif
//                 layer_off(_ADJUST);
//             }
// #ifdef AUDIO_ENABLE
//             play_sound = true;
// #endif
//             break;
//         }
//         case 1:
//             if (active) {
//                 muse_mode = true;
//             } else {
//                 muse_mode = false;
//             }
//     }
//     return true;
// }

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     } else {
//         if (muse_counter) {
//             stop_all_notes();
//             muse_counter = 0;
//         }
//     }
// #endif
// }

// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case RAISE:
//     case LOWER:
//       return false;
//     default:
//       return true;
//   }
// }
