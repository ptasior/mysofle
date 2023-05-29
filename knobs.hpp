enum Actions {
	aTmux,
	aTmuxEmbedded,
	aMacDesktop,
	aVolume,
	aScroll,
	aScrollH,
	aZoom,
	aPage,
	aLRArrows,
	aUDArrows,
	aVim,
	aTab,
	aBrightness,
	aActionsCount
};

#ifdef ENCODER_ENABLE

uint16_t g_key_timer = 0;

bool encoder_update_user(uint8_t index, bool clockwise)
{
	int action;
	if (index == 0)
		action = g_l_knob[get_highest_layer(layer_state)];
	else
		action = g_r_knob[get_highest_layer(layer_state)];

	if (get_mods() & MOD_MASK_CTRL)
		action = aVim; // Doesn't work on mac
	else if (get_mods() & MOD_MASK_SHIFT)
		action = aVolume;

	// Ignore too frequent changes
	if (timer_elapsed(g_key_timer) < 150)
		return false;

	g_key_timer = timer_read();

	uint8_t mods = get_mods();
	clear_mods();

	switch (action)
	{
		case aTmux:
			tap_code16(LCTL(KC_B));
			if (clockwise)
				tap_code(KC_N);
			else
				tap_code(KC_P);
			break;
		case aTmuxEmbedded:
			tap_code16(LCTL(KC_T));
			if (clockwise)
				tap_code(KC_N);
			else
				tap_code(KC_P);
			break;
		case aMacDesktop:
			if (clockwise)
				tap_code16(LCTL(KC_RIGHT));
			else
				tap_code16(LCTL(KC_LEFT));
			break;
		case aVolume:
			if (clockwise)
				tap_code(KC_VOLU);
			else
				tap_code(KC_VOLD);
			break;
		case aScroll:
			if (clockwise)
				tap_code(KC_WH_D);
			else
				tap_code(KC_WH_U);
			break;
		case aScrollH:
			if (clockwise)
				tap_code(KC_WH_L);
			else
				tap_code(KC_WH_R);
			break;
		case aZoom:
			if (clockwise)
				tap_code16(LCTL(KC_PLUS));
			else
				tap_code16(LCTL(KC_MINS));
			break;
		case aPage:
			if (clockwise)
				tap_code(KC_PGDOWN);
			else
				tap_code(KC_PGUP);
			break;
		case aLRArrows:
			if (clockwise)
				tap_code(KC_LEFT);
			else
				tap_code(KC_RIGHT);
			break;
		case aUDArrows:
			if (clockwise)
				tap_code(KC_DOWN);
			else
				tap_code(KC_UP);
			break;
		case aTab:
			if (clockwise)
				tap_code16(LCTL(KC_TAB));
			else
				tap_code16(RCS(KC_TAB));
			break;
		case aBrightness:
			if (clockwise)
				tap_code16(KC_BRIU);
			else
				tap_code16(KC_BRID);
			break;
		case aVim:
			if (clockwise)
			{
				tap_code(KC_G);
				tap_code(KC_T);
			}
			else
			{
				tap_code(KC_G);
				tap_code16(LSFT(KC_T));
			}
			break;
	}

	set_mods(mods);

	return true;
}

#endif

