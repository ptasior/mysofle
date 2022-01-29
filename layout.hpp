enum sofle_layers {
	L_COLEMAK,
	L_QWERTY,
	L_CHARS,
	L_MOVE,
	L_AUX
};

enum custom_keycodes {
	// Layers
	KC_MY_CHARS = SAFE_RANGE,
	KC_MY_MOVE,
	KC_MY_AUX,

	// Escape
	KC_MY_ESC,
	KC_MY_CAPS,
	KC_MY_SWAP_ESC,

	// Movement
	KC_MY_HOME,
	KC_MY_END,
	KC_MY_N_WORD,
	KC_MY_P_WORD,
	KC_MY_W_DEL,
	KC_MY_W_BSPC,

	// OS independent
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

	KC_MY_TAB,

	// Knobs
	KC_MY_L_KNOB,
	KC_MY_R_KNOB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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

