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
	KC_MY_L_KNOB,
	KC_MY_R_KNOB,
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
		KC_GRV,        KC_1,          KC_2,              KC_3,           KC_4,       KC_5,                                            KC_6,               KC_7,    KC_8,    KC_9,          KC_0,          KC_DEL,
		KC_TAB,        KC_Q,          KC_W,              KC_E,           KC_R,       KC_T,                                            KC_Y,               KC_U,    KC_I,    KC_O,          KC_P,          KC_BSPC,
		KC_MY_ESC,     KC_A,          KC_S,              KC_D,           KC_F,       KC_G,                                            KC_H,               KC_J,    KC_K,    KC_L,          KC_SCLN,       KC_QUOT,
		KC_LSFT,       KC_Z,          KC_X,              KC_C,           KC_V,       KC_B,                KC_MY_L_KNOB, KC_MY_R_KNOB, KC_N,               KC_M,    KC_COMM, KC_DOT,        KC_SLSH,       KC_RSFT,
                                      KC_LGUI,           KC_LALT,        KC_LCTL,    LT(L_CHARS, KC_BSPC),KC_SPC,       KC_SPC,       LT(L_MOVE, KC_BSPC),KC_RCTL, KC_RALT, KC_RGUI),
                                      /* KC_LGUI,           KC_LALT,        KC_LCTL,    KC_MY_CHARS,KC_SPC,       KC_SPC,       KC_MY_MOVE,KC_RCTL, KC_RALT, KC_RGUI), */
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
		  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,       KC_7,     KC_8,     KC_9,    KC_0,     KC_DEL,
		  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                                   KC_J,       KC_L,     KC_U,     KC_Y,    KC_SCLN,  KC_BSPC,
		  KC_MY_ESC,KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                                   KC_H,       KC_N,     KC_E,     KC_I,    KC_O,     KC_QUOT,
		  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_MY_L_KNOB, KC_MY_R_KNOB, KC_K,       KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                            KC_LGUI,           KC_LALT,        KC_LCTL,    LT(L_CHARS, KC_BSPC),KC_SPC,       KC_SPC,       LT(L_MOVE, KC_BSPC),KC_RCTL, KC_RALT, KC_RGUI),
							/* KC_LGUI, KC_LALT, KC_LCTRL,KC_MY_CHARS,KC_SPC,       KC_SPC,       KC_MY_MOVE, KC_RCTRL, KC_RALT, KC_RGUI), */

[L_CHARS] = LAYOUT( \
		KC_SLCK,       KC_F1,         KC_F2,             KC_F3,          KC_F4,      KC_F5,                        KC_F6,     KC_F7,   KC_F8,   KC_F9,         KC_F10,        KC_F11,
		KC_NLCK,       KC_PLUS,       KC_MINS,           KC_EQL,         KC_UNDS,    KC_NO,                        KC_NO,     KC_NO,   KC_NO,   KC_NO,         KC_NO,         KC_F12,
		KC_MY_CAPS,    KC_LBRC,       KC_LCBR,           KC_LPRN,        KC_LT,      KC_NO,                        KC_NO,     KC_GT,   KC_RPRN, KC_RCBR,       KC_RBRC,       KC_BSLS,
		KC_TRNS,       KC_MY_UNDO,    KC_MY_CUT,         KC_MY_COPY,     KC_MY_PASTE,KC_NO,      KC_TRNS, KC_TRNS, KC_NO,     KC_NO,   KC_NO,   KC_NO,         KC_NO,         KC_TRNS,
                                      KC_TRNS,           KC_TRNS,        KC_TRNS,    MO(L_AUX),    KC_ENT,  KC_ENT,  MO(L_AUX),   KC_TRNS, KC_TRNS, KC_TRNS),
                                      /* KC_TRNS,           KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_ENT,  KC_ENT,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS), */

[L_MOVE] = LAYOUT( \
		KC_NO,         KC_F1,         KC_F2,             KC_F3,          KC_F4,       KC_F5,                        KC_F6,   KC_F7,     KC_F8,             KC_F9,         KC_F10,        KC_F11,
		KC_MY_TAB,     KC_NO,         KC_NO,             KC_NO,          KC_MY_RELOAD,KC_MY_N_TAB,                  KC_PGUP, KC_MY_HOME,KC_MY_P_WORD,      KC_MY_N_WORD,  KC_MY_END,     KC_MY_W_BSPC,
		KC_TRNS,       KC_MY_ALL,     KC_MY_SAVE,        KC_NO,          KC_MY_FIND,  KC_NO,                        KC_PGDN, KC_LEFT,   KC_DOWN,           KC_UP,         KC_RGHT,       KC_NO,
		KC_TRNS,       KC_MY_UNDO,    KC_MY_CUT,         KC_MY_COPY,     KC_MY_PASTE, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,             KC_NO,         KC_NO,         KC_TRNS,
                                      KC_TRNS,           KC_TRNS,        KC_TRNS,    MO(L_AUX),    KC_ENT,  KC_ENT,  MO(L_AUX),   KC_TRNS, KC_TRNS, KC_TRNS),
                                      /* KC_TRNS,           KC_TRNS,        KC_TRNS,     KC_TRNS,    KC_ENT,  KC_ENT,  KC_TRNS, KC_TRNS,   KC_TRNS,           KC_TRNS), */

[L_AUX] = LAYOUT( \
		KC_NLCK,       DF(L_QWERTY),  DF(L_COLEMAK),     KC_NO,          KC_NO,      KC_NO,                        KC_PSCR, KC_SLCK, KC_PAUS, KC_NO,         KC_NO,         KC_WBAK,
		KC_CAPS,       BL_TOGG,       BL_STEP,           BL_BRTG,        BL_INC,     BL_DEC,                       KC_NO,   KC_BTN1, KC_BTN1, KC_BTN2,       KC_BTN3,       KC_NO,
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

enum Actions {
    aTmux,
    aMacDesktop,
    aVolume,
    aScroll,
    aZoom,
    aPage,
    aVim,
    aCount
};

int g_l_knob = 0;
int g_r_knob = 1;

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
                g_l_knob = (g_l_knob + 1) % aCount;
            return false;

        case KC_MY_R_KNOB:
            if (record->event.pressed)
                g_r_knob = (g_r_knob + 1) % aCount;
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

const char* knob_to_str(int idx)
{
    switch (idx)
    {
        case aTmux: return "tmux";
        case aMacDesktop: return "desk";
        case aVolume: return "vol ";
        case aScroll: return "whl ";
        case aZoom: return "zoom";
        case aPage: return "page";
        case aVim: return "vim ";
    }
    return "???";
}

static void print_status_right(void)
{
    oled_clear();

    if (get_highest_layer(default_layer_state) == L_COLEMAK)
    {
        oled_write_P(PSTR("\nJLUY;\n"), false);
        oled_write_P(PSTR("\nHNEIO\n"), false);
        oled_write_P(PSTR("\nKM,./\n"), false);
        return;
    }

    if (get_mods() & MOD_MASK_SHIFT)
    {
        oled_write_P(PSTR("\n!@#$%\n"), false);
        oled_write_P(PSTR("^&*()\n"), false);
        oled_write_P(PSTR("[{(<\n\n"), false);
        oled_write_P(PSTR("+-=_\n"), false);
        return;
    }
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
    if (get_highest_layer(default_layer_state) == L_COLEMAK)
    {
        oled_clear();
        oled_write_P(PSTR("\nQWFPG\n"), false);
        oled_write_P(PSTR("\nARSTD\n"), false);
        oled_write_P(PSTR("\nZXCVB\n"), false);
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
    oled_write(knob_to_str(g_l_knob), false);

    oled_write_P(PSTR("\n"), false);
    oled_write(knob_to_str(g_r_knob), false);
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

uint16_t key_timer = 0;

bool encoder_update_user(uint8_t index, bool clockwise)
{
    int action;
    if (index == 0)
        action = g_l_knob;
    else
        action = g_r_knob;

    // Ignore too frequent changes
    if (timer_elapsed(key_timer) < 100)
        return false;

    key_timer = timer_read();

    switch (action)
    {
        case aTmux:
            tap_code16(LCTL(KC_B));
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

    return true;
}

#endif
