#pragma once

// #define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WPM_ENABLE

#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif
#define ENCODER_DIRECTION_FLIP

#define RGB_DI_PIN D3
#define RGBLED_NUM 72
#define DRIVER_LED_TOTAL RGBLED_NUM

#ifdef RGB_MATRIX_ENABLE
	#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
	#define RGB_MATRIX_HUE_STEP 8
	#define RGB_MATRIX_SAT_STEP 8
	#define RGB_MATRIX_VAL_STEP 8
	#define RGB_MATRIX_SPD_STEP 10
	#define RGB_MATRIX_SPLIT {36,36}
	#define SPLIT_TRANSPORT_MIRROR
#endif

