#include "quantum.h"
#include <stdio.h>

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (get_highest_layer(layer_state))
  {
  case _QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  case _QWERTY2:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY2");
    break;
  case _COLEMAK:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
    break;
  case _RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case _LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case _ADJUST:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", get_highest_layer(layer_state));
  }

  return layer_state_str;
}
