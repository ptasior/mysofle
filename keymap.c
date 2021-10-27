#include QMK_KEYBOARD_H

enum sofle_layers {
    L_QWERTY,
    L_COLEMAK,
    L_CHARS,
    L_MOVE,
    L_AUX
};

enum custom_keycodes {
    KC_MY_CHARS = SAFE_RANGE,
    KC_MY_MOVE,
    KC_MY_AUX,

    KC_MY_ESC,
    KC_MY_CAPS,

    KC_MY_UNDO,
    KC_MY_CUT,
    KC_MY_COPY,
    KC_MY_PASTE,

    KC_MY_ALL,
    KC_MY_SAVE,
    KC_MY_RELOAD,
    KC_MY_N_TAB,
    KC_MY_FIND,
    KC_MY_CLOSE,

    KC_MY_HOME,
    KC_MY_END,
    KC_MY_N_WORD,
    KC_MY_P_WORD,
    KC_MY_W_DEL,
    KC_MY_W_BSPC,
    KC_MY_TAB,

    KC_MY_SWAP_ESC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Mute  |    | Stop  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |CHARS | /Space  /       \Space \  | MOVE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_QWERTY] = LAYOUT( \
		KC_GRV,        KC_1,          KC_2,              KC_3,           KC_4,       KC_5,                         KC_6,      KC_7,    KC_8,    KC_9,          KC_0,          KC_DEL,
		KC_TAB,        KC_Q,          KC_W,              KC_E,           KC_R,       KC_T,                         KC_Y,      KC_U,    KC_I,    KC_O,          KC_P,          KC_BSPC,
		KC_MY_ESC,     KC_A,          KC_S,              KC_D,           KC_F,       KC_G,                         KC_H,      KC_J,    KC_K,    KC_L,          KC_SCLN,       KC_QUOT,
		KC_LSFT,       KC_Z,          KC_X,              KC_C,           KC_V,       KC_B,       KC_MUTE, KC_MSTP, KC_N,      KC_M,    KC_COMM, KC_DOT,        KC_SLSH,       KC_RSFT,
                                      KC_LGUI,           KC_LALT,        KC_LCTL,    KC_MY_CHARS,KC_SPC,  KC_SPC,  KC_MY_MOVE,KC_RCTL, KC_RALT, KC_RGUI),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------| Mute  |    | Stop  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |CHARS | /Space  /       \Space \  | MOVE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[L_COLEMAK] = LAYOUT( \
		  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,       KC_7,     KC_8,     KC_9,    KC_0,     KC_DEL,
		  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                             KC_J,       KC_L,     KC_U,     KC_Y,    KC_SCLN,  KC_BSPC,
		  KC_MY_ESC,KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                             KC_H,       KC_N,     KC_E,     KC_I,    KC_O,     KC_QUOT,
		  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_MUTE,     KC_MSTP, KC_K,       KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
							KC_LGUI, KC_LALT, KC_LCTRL,KC_MY_CHARS,KC_SPC,      KC_SPC,  KC_MY_MOVE, KC_RCTRL, KC_RALT, KC_RGUI),

[L_CHARS] = LAYOUT( \
		KC_SLCK,       KC_F1,         KC_F2,             KC_F3,          KC_F4,      KC_F5,                        KC_F6,     KC_F7,   KC_F8,   KC_F9,         KC_F10,        KC_F11,
		KC_NLCK,       KC_PLUS,       KC_MINS,           KC_EQL,         KC_UNDS,    KC_NO,                        KC_NO,     KC_NO,   KC_NO,   KC_NO,         KC_NO,         KC_F12,
		KC_MY_CAPS,    KC_LBRC,       KC_LCBR,           KC_LPRN,        KC_LT,      KC_NO,                        KC_NO,     KC_GT,   KC_RPRN, KC_RCBR,       KC_RBRC,       KC_BSLS,
		KC_TRNS,       KC_MY_UNDO,    KC_MY_CUT,         KC_MY_COPY,     KC_MY_PASTE,KC_NO,      KC_TRNS, KC_TRNS, KC_NO,     KC_NO,   KC_NO,   KC_NO,         KC_NO,         KC_TRNS,
                                      KC_TRNS,           KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_ENT,  KC_ENT,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

[L_MOVE] = LAYOUT( \
		KC_NO,         KC_NO,         KC_NO,             KC_NO,          KC_NO,       KC_NO,                        KC_NO,   KC_NO,     KC_NO,             KC_NO,         KC_NO,         KC_MY_W_DEL,
		KC_MY_TAB,     KC_NO,         KC_NO,             KC_NO,          KC_MY_RELOAD,KC_MY_N_TAB,                  KC_PGUP, KC_MY_HOME,KC_MY_P_WORD,      KC_MY_N_WORD,  KC_MY_END,     KC_MY_W_BSPC,
		KC_TRNS,       KC_MY_ALL,     KC_MY_SAVE,        KC_NO,          KC_MY_FIND,  KC_NO,                        KC_PGDN, KC_LEFT,   KC_DOWN,           KC_UP,         KC_RGHT,       KC_NO,
		KC_TRNS,       KC_MY_UNDO,    KC_MY_CUT,         KC_MY_COPY,     KC_MY_PASTE, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,             KC_NO,         KC_NO,         KC_TRNS,
                                      KC_TRNS,           KC_TRNS,        KC_TRNS,     KC_TRNS,    KC_ENT,  KC_ENT,  KC_TRNS, KC_TRNS,   KC_TRNS,           KC_TRNS),

[L_AUX] = LAYOUT( \
		RESET,         DF(L_QWERTY),  DF(L_COLEMAK),     KC_NO,          KC_NO,      KC_NO,                        KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,         KC_NO,         KC_WBAK,
		KC_CALC,       BL_TOGG,       BL_STEP,           BL_BRTG,        BL_INC,     BL_DEC,                       KC_NO,   KC_BTN1, KC_BTN1, KC_BTN2,       KC_BTN3,       KC_NO,
		KC_MY_SWAP_ESC,RGB_TOG,       RGB_MOD,           RGB_SPI,        RGB_VAI,    RGB_HUI,                      KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U,       KC_MS_R,       KC_NO,
		KC_TRNS,       KC_NO,         RGB_RMOD,          RGB_SPD,        RGB_VAD,    RGB_HUD,    KC_NO,   KC_NO,   KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2,       KC_NO,         KC_TRNS,
                                      KC_TRNS,           KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};


enum HostOS {hUnknown, hPC, hMac};
enum HostOS g_host_os = hUnknown;
bool g_swap_esc = true;

void detect_pc(void)
{
    if (g_host_os != hUnknown)
        return;

    // If the numlock is on, it's PC. Note and leave
    if (host_keyboard_led_state().num_lock)
    {
        g_host_os = hPC;
        return;
    }

    tap_code(KC_NUMLOCK); // Tap numlock
    g_host_os = host_keyboard_led_state().num_lock ? hPC : hMac;

    if (g_host_os == hPC) // It is PC, switch numlock off
        tap_code(KC_NUMLOCK);
}

void os_combo(int mod_pc, int mod_mac, int key_pc, int key_mac, bool pressed)
{
    detect_pc();

    if (pressed)
    {
        if (g_host_os == hPC)
        {
            if (mod_pc)
                register_mods(mod_pc);
            register_code(key_pc);
        }
        else
        {
            if (mod_mac)
                register_mods(mod_mac);
            register_code(key_mac);
        }

    }
    else
    {
        if (g_host_os == hPC)
        {
            if (mod_pc)
                unregister_mods(mod_pc);
            unregister_code(key_pc);
        }
        else
        {
            if (mod_mac)
                unregister_mods(mod_mac);
            unregister_code(key_mac);
        }
    }
}

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


#ifdef OLED_ENABLE

char g_wpm_buf[4];

static void print_status_right(void)
{
    // Print current mode
    /* if (get_mods() & MOD_MASK_SHIFT) */
    /* { */
        oled_write_P(PSTR("\n!@#$%\n"), false);
        oled_write_P(PSTR("^&*()\n"), false);
        oled_write_P(PSTR("[{(<\n\n"), false);
        oled_write_P(PSTR("+-=_\n"), false);
    /* } */
    /* else */
    /* { */
        /*  static const char PROGMEM logo[] = { */
        /*     0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,  */
        /*     0x80, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x80, 0x00, 0x00, 0x01, 0xff, 0x00, 0x40, 0x00, 0x00,  */
        /*     0x07, 0xff, 0x80, 0x20, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x10, 0x00, 0x00, 0x3b, 0xff, 0x80, 0x00,  */
        /*     0x00, 0x00, 0xf7, 0xef, 0x00, 0x08, 0x00, 0x03, 0xff, 0x07, 0x00, 0x08, 0x0f, 0xff, 0xf8, 0x01,  */
        /*     0xf8, 0x10, 0x3f, 0xff, 0xc0, 0x00, 0x07, 0xc0, 0x7e, 0x12, 0x00, 0x00, 0x01, 0xc0, 0x7c, 0x02,  */
        /*     0x00, 0x00, 0x01, 0xc0, 0xfc, 0xe1, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xc0,  */
        /*     0xff, 0x00, 0x80, 0x00, 0x00, 0xc0, 0x7f, 0x00, 0x80, 0x00, 0x00, 0xc0, 0x7e, 0x01, 0x00, 0x00,  */
        /*     0x01, 0xc0, 0x3c, 0x01, 0x00, 0x00, 0x19, 0xc0, 0x0f, 0x13, 0xe0, 0x00, 0x7f, 0x00, 0x00, 0x00,  */
        /*     0xfc, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x3f, 0x81, 0xf0, 0x00, 0x00, 0x00, 0x19, 0xf9, 0xc0, 0x00,  */
        /*     0x00, 0x00, 0x06, 0xff, 0x00, 0x10, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e,  */
        /*     0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  */
        /*     0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x80 */
        /* };  */
        /*  */
        /* oled_write_P(logo, false); */
    /* } */
}

static void print_status_left(void)
{
    // Print current mode
    const led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("C"), led_usb_state.caps_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state.num_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"),  led_usb_state.scroll_lock);

    oled_write_P(PSTR("\n\n"), false);

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

    oled_write_P(PSTR("WPM\n"), false);

    itoa(get_current_wpm(), g_wpm_buf, 9);
    oled_write(g_wpm_buf, false);

    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    /* if (is_keyboard_master()) */
        return OLED_ROTATION_270;

    /* return rotation; */
}


void oled_task_user(void)
{
    if (is_keyboard_master())
        print_status_left();
    else
        print_status_right();
}

#endif


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise)
{
    if (index == 0)
    {
        if (clockwise)
            tap_code(KC_VOLU);
        else
            tap_code(KC_VOLD);
    }
    else if (index == 1)
    {
        if (clockwise)
            tap_code(KC_WH_D);
        else
            tap_code(KC_WH_U);
    }

    return true;
}

#endif
