#include "quantum.h"
#include <stdio.h>

#define L_BASE 0
#define L_RAISE (1 << 3)
#define L_LOWER (1 << 4)
#define L_ADJUST (1 << 5)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}

// Default Layers
char default_layer_str[24];

const char *get_default_layer_name(void) {
    if (default_layer_state == 0) {
        snprintf(default_layer_str, sizeof(default_layer_str), "Layer: QWERTY");
    } else if (default_layer_state == 1) {
        snprintf(default_layer_str, sizeof(default_layer_str), "Layer: QWERTY2");
    } else if (default_layer_state == 2) {
        snprintf(default_layer_str, sizeof(default_layer_str), "Layer: COLEMAK");
    } else {
        snprintf(default_layer_str, sizeof(default_layer_str), "Layer: Unknown");
    }

    return default_layer_str;
}