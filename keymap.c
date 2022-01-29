#include QMK_KEYBOARD_H


bool g_swap_esc = true;
int g_l_knob = 0;
int g_r_knob = 1;

#include "layout.hpp"
#include "os_detect.hpp"
#include "knobs.hpp"
#include "oled.hpp"
#include "mappings.hpp"

