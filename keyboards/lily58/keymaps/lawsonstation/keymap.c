#include QMK_KEYBOARD_H

// Define macros.
#define CTL_ESC LCTL_T(KC_ESC)	 // Mod-Tap for Left Control and Escape.

// Home Row Mods (HRM - CAGSC)
// RH HRM (Qwerty)
#define CTL_V   LCTL_T(KC_V)
#define CTL_A   LCTL_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define GUI_D   LGUI_T(KC_D)
#define SFT_F   LSFT_T(KC_F)

// LH HRM (Qwerty)
#define SFT_J   LSFT_T(KC_J)
#define GUI_K   LGUI_T(KC_K)
#define ALT_L   LALT_T(KC_L)
#define CTL_M   LCTL_T(KC_M)
#define CTL_SC  LCTL_T(KC_SCLN)

// LH HRM (Numbers)
#define CTL_3   LCTL_T(KC_3)
#define CTL_EQL LCTL_T(KC_EQL)
#define ALT_4   LALT_T(KC_4)
#define GUI_5   LGUI_T(KC_5)
#define SFT_6   LSFT_T(KC_6)

// RH HRM (Numbers)
#define CTL_DLR LCTL_T(KC_DLR)

// LH HRM (Navigation and Function)
#define CTL_F3  LCTL_T(KC_F3)
#define CTL_F11 LCTL_T(KC_F11)
#define ALT_F4  LALT_T(KC_F4)
#define GUI_F5  LGUI_T(KC_F5)
#define SFT_F6  LSFT_T(KC_F6)
#define SFT_DN  LSFT_T(KC_DOWN)  // Mod-Tap for Left Shift and Down Arrow.
#define GUI_UP  LGUI_T(KC_UP)    // Mod-Tap for Left GUI and Up Arrow.
#define ALT_RT  LALT_T(KC_RGHT)  // Mod-Tap for Left Alt and Right Arrow
#define CTL_PU  LCTL_T(KC_PGUP)

// Left-hand home row mods (Colemak-DHm)
#define GUI_S   LGUI_T(KC_S)
#define ALT_R   LALT_T(KC_R)
#define ZSFT_T  LSFT_T(KC_T)  // name conflict w/ existing mod tap key alias
#define CTL_D   LCTL_T(KC_D)
#define CTL_A   LCTL_T(KC_A)
#define CTL_O   LCTL_T(KC_O)

// Right-hand home row mods (Colemak-DHm)
#define CTL_H   LCTL_T(KC_H)
#define SFT_N   LSFT_T(KC_N)
#define ALT_I   LALT_T(KC_I)
#define GUI_E   LGUI_T(KC_E)

enum layer_number {
  _QWERTY = 0,
  _QWERTY2,
  _COLEMAK,
  _RAISE,
  _LOWER,
  _ADJUST,
};

enum layer_names {
  _QWERTY,
  _QWERTY2,
  _COLEMAK,
  _RAISE,
  _LOWER,
  _ADJUST,
};

enum lily58_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY2,
  COLEMAK,
  LOWER,
  RAISE,
  FUNCTION
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL/ESC| A |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| Del |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS,
  CTL_ESC,  CTL_A,    ALT_S,    GUI_D,    SFT_F,    KC_G,                     KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SC,   KC_QUOT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     CTL_V,    KC_B, KC_LPRN,  KC_RPRN,  KC_N,    CTL_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_DEL
),
[_QWERTY2] = LAYOUT(
  QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS,
  KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B, KC_LPRN,  KC_RPRN,  KC_N,    CTL_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_DEL
),
 [_COLEMAK] = LAYOUT(
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_MINS,
  CTL_ESC,  CTL_A,    ALT_R,    GUI_S,    ZSFT_T,   KC_G,                     KC_M,    SFT_N,   GUI_E,   ALT_I,   CTL_O,    KC_QUOT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     CTL_D,    KC_V, KC_LPRN,  KC_RPRN,  KC_K,    CTL_H,   KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_DEL
),
/* RAISE (number layer)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   |                    |   6  |   7  |  8   |  9   |  0   |BackSp|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  \   |  7   |  8   |  9   |  [   |                    |  ]   |  +   |  -   |  *   |  /   |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  =   |  4   |  5   |  6   |  (   |-------.    ,-------|  )   |Shift | GUI  | Alt  |  $   |  %   |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |      |  -   |  1   |  2   |  3   |  `   |-------|    |-------|  =   | Ctrl |  ,   |  .   |  /   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | .    | 0     | /Space  /       \Enter \  |RAISE |BackSP| Del |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
   KC_GRV,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
  _______,  KC_BSLS,  KC_7,     KC_8,     KC_9,     KC_LBRC,                  KC_RBRC,  KC_PPLS,  KC_PMNS,  KC_PAST,  KC_PSLS,  KC_MINS,
  _______,  CTL_EQL,  ALT_4,    GUI_5,    SFT_6,    KC_LPRN,                  KC_RPRN,  KC_LSFT,  KC_LGUI,  KC_LALT,  CTL_DLR,  KC_PERC,
  _______,  KC_MINS,  KC_1,     KC_2,     CTL_3,    KC_GRV, KC_LPRN, KC_RPRN, KC_EQL,   KC_LCTL,  KC_COMM,  KC_DOT,   KC_SLSH,  _______,
                        _______, KC_DOT, KC_0,   _______, _______, _______, _______, _______
),
/* LOWER (navigation and function)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  | 4    |      |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | F12  | F7   | F8   | F9   |      |                    | PREV | VOL- | VOL+ | NEXT | MUTE | PLAY |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | F11  | F4   | F5   | F6   |      |-------.    ,-------|  Left | Down |  Up  |Right|      |      |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |      | F10  |  F1  | F2   | F3   |      |-------|    |-------| Home | PGUP | PGDN | End  |     |       |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| DEL  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT(
   KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                      KC_6,     KC_7,     KC_8,     KC_9,      KC_0,    KC_BSPC,
  _______,   KC_F12,   KC_F7,    KC_F8,    KC_F9,    XXXXXXX,                		KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  KC_MPLY,
  _______,   CTL_F11,  ALT_F4,   GUI_F5,   SFT_F6,   XXXXXXX,                	  KC_LEFT,  SFT_DN,   GUI_UP,   ALT_RT,   KC_LCTL,  XXXXXXX,
  _______,   KC_F10,   KC_F1,    KC_F2,    CTL_F3,   XXXXXXX, KC_LBRC, KC_RBRC, KC_HOME,  CTL_PU,   KC_PGDN,  KC_END,   XXXXXXX,  XXXXXXX,
                             _______, _______, _______,   _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET|QWERTY|COLEMK|QWERTY|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |-------.    ,-------| PREV | VOL- | VOL+ | NEXT | MUTE | PLAY |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | SHIFT|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| DEL  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_BOOT, QWERTY,  COLEMAK, QWERTY2, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_MPLY,
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

static void render_wpm(void) {
    uint8_t n = get_current_wpm();

    char wpm_str[4];
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;

    oled_write_P(PSTR("WPM: "), false);
    oled_write(wpm_str, false);
    oled_write_ln_P(PSTR(" "), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    //oled_write(read_logo(), false);
    render_wpm();
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef OLED_ENABLE
    set_keylog(keycode, record);
    #endif
    // set_timelog();
  }
  switch (keycode) {
    case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case QWERTY2:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY2);
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
  }
  return true;
};
