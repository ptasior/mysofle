#include QMK_KEYBOARD_H

enum Actions {
	aTmux,
	aTmuxEmbedded,
	aCycleWindows,
	aMacDesktop,
	// aVolume,
	// aScroll,
	aScrollH,
	aZoom,
	// aPage,
	// aLRArrows,
	// aUDArrows,
	aVim,
	// aTab,
	// aBrightness,
	aActionsCount
};


enum HostOS {hUnknown = -1, hPC = 0, hMac = 1};
enum HostOS g_host_os = hUnknown;

bool g_swap_esc = true;
int g_l_knob[5] = {aTmux,aTmux,aTmuxEmbedded,aVim,aZoom};
int g_r_knob[5] = {aCycleWindows,aCycleWindows,aTmuxEmbedded,aVim,aZoom};

#include "layout.hpp"
#include "os_detect.hpp"
#include "knobs.hpp"
#include "oled.hpp"
#include "rgb.hpp"
#include "mappings.hpp"

