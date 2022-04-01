
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case KC_MY_ESC:
            if (! record->event.pressed)
            {
                if (! g_swap_esc)
                    unregister_code(KC_ESC);
                else
                    unregister_code(KC_CAPS);
            }
            else
            {
                if (! g_swap_esc)
                    register_code(KC_ESC);
                else
                    register_code(KC_CAPS);
            }

            return false;
        case KC_MY_CAPS:
            if (! record->event.pressed)
            {
                if (! g_swap_esc)
                    unregister_code(KC_CAPS);
                else
                    unregister_code(KC_ESC);
            }
            else
            {
                if (! g_swap_esc)
                    register_code(KC_CAPS);
                else
                    register_code(KC_ESC);
            }
            return false;

        case KC_MY_SWAP_ESC:
            if (record->event.pressed)
                g_swap_esc = ! g_swap_esc;
            return false;

        case KC_MY_L_KNOB:
            if (record->event.pressed)
                g_l_knob[get_highest_layer(layer_state)] = (g_l_knob[get_highest_layer(layer_state)] + 1) % aActionsCount;
            return false;

        case KC_MY_R_KNOB:
            if (record->event.pressed)
                g_r_knob[get_highest_layer(layer_state)] = (g_r_knob[get_highest_layer(layer_state)] + 1) % aActionsCount;
            return false;

        case KC_MY_UNDO:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_Z, KC_Z, record->event.pressed);
            return false;
        case KC_MY_CUT:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_X, KC_X, record->event.pressed);
            return false;
        case KC_MY_COPY:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_C, KC_C, record->event.pressed);
            return false;
        case KC_MY_PASTE:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_V, KC_V, record->event.pressed);
            return false;

        case KC_MY_ALL:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_A, KC_A, record->event.pressed);
            return false;
        case KC_MY_SAVE:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_S, KC_S, record->event.pressed);
            return false;
        case KC_MY_RELOAD:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_R, KC_R, record->event.pressed);
            return false;
        case KC_MY_N_TAB:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_T, KC_T, record->event.pressed);
            return false;
        case KC_MY_FIND:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_F, KC_F, record->event.pressed);
            return false;
        case KC_MY_CLOSE:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LGUI), KC_W, KC_W, record->event.pressed);
            return false;

        case KC_MY_HOME:
            os_combo(0,                    mod_config(MOD_LGUI), KC_HOME,  KC_LEFT, record->event.pressed);
            return false;
        case KC_MY_END:
            os_combo(0,                    mod_config(MOD_LGUI), KC_END,   KC_RIGHT, record->event.pressed);
            return false;
        case KC_MY_N_WORD:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LALT), KC_RIGHT, KC_RIGHT, record->event.pressed);
            return false;
        case KC_MY_P_WORD:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LALT), KC_LEFT,  KC_LEFT, record->event.pressed);
            return false;

        case KC_MY_W_DEL:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LALT), KC_DEL,   KC_DEL, record->event.pressed);
            return false;
        case KC_MY_W_BSPC:
            os_combo(mod_config(MOD_LCTL), mod_config(MOD_LALT), KC_BSPC,  KC_BSPC, record->event.pressed);
            return false;

        case KC_MY_TAB:
            os_combo(mod_config(MOD_LALT), mod_config(MOD_LGUI), KC_TAB,   KC_TAB, record->event.pressed);
            return false;

        case KC_MY_CHARS:
            if (record->event.pressed)
                layer_on(L_CHARS);
            else
                layer_off(L_CHARS);

            update_tri_layer(L_CHARS, L_MOVE, L_AUX);
            return false;

        case KC_MY_MOVE:
            if (record->event.pressed)
                layer_on(L_MOVE);
            else
                layer_off(L_MOVE);

            update_tri_layer(L_CHARS, L_MOVE, L_AUX);
            return false;

        case KC_MY_AUX:
            if (record->event.pressed)
                layer_on(L_AUX);
            else
                layer_off(L_AUX);
            return false;
    }

    return true;
}

