#include "quantum.h"
#include <stdio.h>

char layer_state_str[24];

const char *read_layer_state(void) {
    if (layer_state_cmp(layer_state, _QWERTY)) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    } else if (layer_state_cmp(layer_state, _QWERTY2)) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY2");
    } else if (layer_state_cmp(layer_state, _COLEMAK)) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: COLEMAK");
    } else if (layer_state_cmp(layer_state, _LOWER)) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: LOWER");
    } else if (layer_state_cmp(layer_state, _RAISE)) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RAISE");
    } else if (layer_state_cmp(layer_state, _ADJUST)) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: ADJUST");
    } else {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%lu", layer_state);
    }

    return layer_state_str;
}
