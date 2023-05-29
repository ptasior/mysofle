void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    const int on = 10;
    for (uint8_t i = led_min; i <= led_max; i++)
    {
        if (get_mods() & MOD_MASK_CTRL)
            rgb_matrix_set_color(i, on, on, on);
        else
            switch(get_highest_layer(layer_state|default_layer_state))
            {
                case L_QWERTY:
                    rgb_matrix_set_color(i, RGB_RED);
                    break;
                case L_MOVE:
                    rgb_matrix_set_color(i, on, on, 0);
                    break;
                case L_CHARS:
                    rgb_matrix_set_color(i, 0, on, on);
                    break;
                case L_AUX:
                    rgb_matrix_set_color(i, on, on, on);
                    break;
                case L_COLEMAK:
                default:
                    rgb_matrix_set_color(i, 0, 0, 0);
                    break;
            }
    }
}
