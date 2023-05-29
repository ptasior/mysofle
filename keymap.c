#include QMK_KEYBOARD_H


bool g_swap_esc = true;
int g_l_knob[5] = {0,0,10,9, 2};
int g_r_knob[5] = {1,1,9, 10,5};

#include "layout.hpp"
#include "os_detect.hpp"
#include "knobs.hpp"
#include "oled.hpp"
#include "rgb.hpp"
#include "mappings.hpp"

