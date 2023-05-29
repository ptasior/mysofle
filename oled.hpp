#ifdef OLED_ENABLE

char g_wpm_buf[4];

const char* knob_to_str(int idx)
{
	switch (idx)
	{
		case aTmux: return "tmux";
		case aMacDesktop: return "desk";
		case aVolume: return "vol ";
		case aScroll: return "wh^v";
		case aScrollH: return "wh<>";
		case aZoom: return "zoom";
		case aPage: return "page";
		case aLRArrows: return "ar<>";
		case aUDArrows: return "ar^v";
		case aVim: return "vim ";
		case aTab: return "tab ";
		case aBrightness: return "bri ";
	}
	return "???";
}

static void print_status_right(void)
{
	/* if (get_highest_layer(default_layer_state) == L_COLEMAK) */
	/* if (get_mods() & MOD_MASK_SHIFT) */
	if (get_highest_layer(layer_state) == L_AUX)
	{
		oled_clear();
		oled_write_P(PSTR("^&*()"), false);
		oled_write_P(PSTR("JLUY;"), false);
		oled_write_P(PSTR("HNEIO"), false);
		oled_write_P(PSTR("KM,./"), false);
		oled_write_P(PSTR("\n>)}]\n"), false);
		oled_write_P(PSTR("\nPrSc"), false);
		oled_write_P(PSTR("\nSyRq"), false);
		oled_write_P(PSTR("\nPaus"), false);
		oled_write_P(PSTR("\nNuLk"), false);
		return;
	}

#ifdef WPM_ENABLE
	oled_write_P(PSTR("\n\n\n\nWPM\n"), false);

	itoa(get_current_wpm(), g_wpm_buf, 9);
	oled_write(g_wpm_buf, false);
	oled_write_P(PSTR("\n\n\n\n\n\n\n"), false);
#endif

	/* static const char PROGMEM qmk_logo[] = { */
	/*     153,154,10, */
	/*     185,186,0 */
	/* }; */
	/*  */
	/* for (int i = 0; i < 3; i++) */
	/* { */
	/* 	oled_write_P(PSTR("\n\n\n"), false); */
	/* 	oled_write_P(qmk_logo, false); */
	/* } */

	/* else */
	/* { */
	/*     static const char PROGMEM qmk_logo[] = { */
	/*         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
	/*         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
	/*         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0 */
	/*     }; */
	/*  */
	/*     oled_write_P(qmk_logo, false); */
	/*     oled_scroll_left(); */
	/* } */
}

static void print_status_left(void)
{
	if (get_highest_layer(layer_state) == L_AUX)
	{
		oled_clear();
		oled_write_P(PSTR("!@#$%"), false);
		oled_write_P(PSTR("QWFPG"), false);
		oled_write_P(PSTR("ARSTD"), false);
		oled_write_P(PSTR("ZXCVB"), false);
		oled_write_P(PSTR("\n[{(<"), false);
		oled_write_P(PSTR("\n+-=_\n"), false);
		oled_write_P(PSTR("\nScLk"), false);
		oled_write_P(PSTR("\nCpLk"), false);
		oled_write_P(PSTR("\nSwEs\n"), false);

		oled_write_P(PSTR("\n"),false);
		oled_write(knob_to_str(g_l_knob[get_highest_layer(layer_state)]), false);
		oled_write_P(PSTR("\n"),false);
		oled_write(knob_to_str(g_r_knob[get_highest_layer(layer_state)]), false);
		return;
	}

	// Print current mode
	const led_t led_usb_state = host_keyboard_led_state();
	oled_write_P(PSTR("C"), led_usb_state.caps_lock);
	oled_write_P(PSTR(" "), false);
	oled_write_P(PSTR("N"), led_usb_state.num_lock);
	oled_write_P(PSTR(" "), false);
	oled_write_P(PSTR("S"),  led_usb_state.scroll_lock);

	oled_write_P(PSTR("\n"), false);

	oled_write_P(PSTR("HOST\n"), false);
	switch (g_host_os)
	{
		case hUnknown:
			oled_write_P(PSTR("???"), false);
			break;
		case hPC:
			oled_write_P(PSTR("pc"), false);
			break;
		case hMac:
			oled_write_P(PSTR("mac"), false);
			break;
	}

	oled_write_P(PSTR("\n\n"), false);
	oled_write_P(PSTR("LAYER"), false);
	switch (get_highest_layer(layer_state))
	{
		case L_QWERTY:
		case L_COLEMAK:
			switch (get_highest_layer(default_layer_state))
			{
				case L_QWERTY:
					oled_write_P(PSTR("base"), false);
					break;
				case L_COLEMAK:
					oled_write_P(PSTR("cole"), false);
					break;
			}
			break;
		case L_CHARS:
			oled_write_P(PSTR("char"), false);
			break;
		case L_MOVE:
			oled_write_P(PSTR("move"), false);
			break;
		case L_AUX:
			oled_write_P(PSTR("aux"), false);
			break;
		default:
			oled_write_P(PSTR("???"), false);
	}
	oled_write_P(PSTR("\n\n"), false);

	oled_write_P(PSTR("ESC\n"), false);
	if (g_swap_esc)
		oled_write_P(PSTR("swap"), false);
	else
		oled_write_P(PSTR("norm"), false);

	oled_write_P(PSTR("\n\n"), false);

	oled_write_P(PSTR("KNOBS"), false);
	oled_write(knob_to_str(g_l_knob[get_highest_layer(layer_state)]), false);

	oled_write_P(PSTR("\n"), false);
	oled_write(knob_to_str(g_r_knob[get_highest_layer(layer_state)]), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
	/* if (is_keyboard_master()) */
		return OLED_ROTATION_270;

	/* return rotation; */
}

bool oled_task_user(void)
{
	if (is_keyboard_master())
		print_status_left();
	else
		print_status_right();

	return false;
}

#endif

