#include QMK_KEYBOARD_H


enum HostOS {hUnknown = -1, hPC = 0, hMac = 1};
enum HostOS g_host_os = hUnknown;

bool g_swap_esc = true;
int g_l_knob[5] = {0,0,1,10,2};
int g_r_knob[5] = {2,2,1,10,5};

#include "layout.hpp"
#include "os_detect.hpp"
#include "knobs.hpp"
#include "oled.hpp"
#include "rgb.hpp"
#include "mappings.hpp"

