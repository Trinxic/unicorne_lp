#include QMK_KEYBOARD_H


// ------------------ Tap-Dance ----------------- //
enum {
    TD_SHFT_CAPS = 0
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_SHFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};


// ------------------- Layers ------------------- //
enum layers {  // Layers
    _DVRK,
    _QWRT,
    _SYMB,
    _NAV,
    _FUNC,
    _SYS
};

/* Layer Blueprint:
    [_{NAME}] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //'--------------------------'  '--------------------------'
    ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVRK] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_TAB, KC_SCLN, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,	KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SHFT_CAPS), KC_QUOT, KC_Q, KC_J, KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSFT,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            KC_LGUI, KC_BSPC, MO(_NAV), MO(_SYMB),  KC_SPC, KC_RALT
                                        //'--------------------------'  '--------------------------'
    ),
    [_QWRT] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SHFT_CAPS), KC_Z, KC_X, KC_C, KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            KC_LGUI, KC_BSPC, MO(_NAV), MO(_SYMB),  KC_SPC, KC_RALT
                                        //'--------------------------'  '--------------------------'
    ),
    [_SYMB] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         KC_ESC, _______, _______, _______, KC_ASTR, KC_CIRC,                      KC_PLUS,    KC_1,    KC_2,  KC_3, KC_PERC, TO(_FUNC),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_HASH, KC_LPRN, KC_RPRN, KC_SLSH, KC_BSLS,                       KC_EQL,    KC_4,    KC_5,    KC_6,    KC_0,   KC_AT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, _______, KC_LBRC, KC_RBRC, KC_EXLM,  KC_GRV,                      KC_MINS,    KC_7,    KC_8,    KC_9,  KC_DLR, _______,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            _______, _______, TO(_FUNC),  _______, _______, _______
                                        //'--------------------------'  '--------------------------'
    ),
    [_NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
      TO(_FUNC), XXXXXXX, KC_FIND, KC_UNDO, KC_AGIN, XXXXXXX,                      XXXXXXX,  KC_END, KC_PGDN, KC_PGUP, KC_HOME, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX,  KC_CUT, KC_COPY, KC_PSTE, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                            KC_LGUI, XXXXXXX, _______,  TO(_FUNC), _______, _______
                                        //'--------------------------'  '--------------------------'
    ),
    [_FUNC] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
          KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, XXXXXXX,                      KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_MPRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                         TO(_SYS), TO(_DVRK), XXXXXXX,    XXXXXXX, TO(_DVRK), TO(_SYS)
                                        //'--------------------------'  '--------------------------'
    ),
    [_SYS] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------,                    ,-----------------------------------------------------,
         QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_MOD, RGB_VAI, RGB_SPI, BL_BRTG,   BL_UP,  QK_RBT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_VAD, RGB_SPD, BL_TOGG, BL_DOWN, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    //'--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------'
                                        TO(_QWRT), TO(_DVRK), XXXXXXX,    XXXXXXX, TO(_DVRK), TO(_QWRT)
                                        //'--------------------------'  '--------------------------'
    )
};


// don't touch.. idk what this does at the moment
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif


// --------- Shift + Backspace = Delete --------- //
// https://docs.qmk.fm/feature_advanced_keycodes#shift-backspace-for-delete
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();  // Store the current modifier state
    switch (keycode) {
        case KC_BSPC: {
            // Track delete key status: registered or not?
            static bool delkey_registered;
            
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // Temporarily canceling both shifts
                    // so 'shift' isn't applied to KC_DEL
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
    }
    return true;
};


// ---------------- Layer Timeout --------------- //
void matrix_scan_user(void) {
    if (  // any 'toggled' layer is active
        (get_highest_layer(layer_state) == _FUNC
        || get_highest_layer(layer_state) == _SYS)
        && last_input_activity_elapsed() > 10000  // 10 seconds
    ) {
        layer_move(_DVRK);
        oled_off();  // not working...
    }
}


// ---------------- OLED Screens ---------------- //
#ifdef OLED_ENABLE

// Rotate Screens
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    bool vertical_text = false;
    if (vertical_text) {  // vertical
        if (!is_keyboard_left()) { return OLED_ROTATION_180; }
        return rotation;
    } else {  // horizontal
        return OLED_ROTATION_270;
    }
}

// Layer Status
void show_current_layer(bool is_left) {
    oled_set_cursor(0, 1);
    switch (get_highest_layer(layer_state)) {
        case _DVRK:
            oled_write(PSTR(is_left ? " DVRK\n" : " DVRK\n"), false); break;
        case _QWRT:
            oled_write(PSTR(is_left ? " QWRT\n" : " QWRT\n"), false); break;
        case _SYMB:
            oled_write(PSTR(is_left ? " SYMB\n" : " SYMB\n"), false); break;
        case _NAV:
            oled_write(PSTR(is_left ? "  NAV\n" : " NAV\n"), false); break;
        case _FUNC:
            oled_write(PSTR(is_left ? " FUNC\n" : " FUNC\n"), false); break;
        case _SYS:
            oled_write(PSTR(is_left ? "  SYS\n" : " SYS\n"), false); break;
        default:
            oled_write(PSTR("ERROR\n"), false); break;
    }
}

// Logos
static void render_apple_logo(void) {
    static const char PROGMEM raw_logo_apple[] = {  // `const unsigned char`
          0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,  0,  0,  0,
        112,124, 62, 62,159,135,128,128,128,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,224,248,252,254,255,255,255,255,255,255,255,255,254,
        254,254,255,255,255,255,255,255,255, 31, 15,  6,  0,  0,  0,  0,
          0,  0,  0, 31,255,255,255,255,255,255,255,255,255,255,255,255,
        255,255,255,255,255,255,255,255,255,248,224,192,192,  0,  0,  0,
          0,  0,  0,  0,  0,  3,  7, 15, 31, 63,127,127,127, 63, 63, 31,
         31, 31, 31, 63, 63,127,127, 63, 63, 31, 15,  3,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo_apple, sizeof(raw_logo_apple));
}

static void render_arch_logo(void) {
    static const char PROGMEM raw_arch_logo[] = {
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,
        240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,248,242,247,239,
        255,255,255,252,240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,192,240,252,254,255,255,127,  7,  3,  1,
          1,  3,  7,127,255,255,255,252,184,160,128,  0,  0,  0,  0,  0,
          0,  0,  0,  8, 12,  7,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,
          0,  0,  0,  0,  0,  0,  1,  1,  3,  3,  7, 14,  8,  0,  0,  0,
    };
    oled_write_raw_P(raw_arch_logo, sizeof(raw_arch_logo));
}

static void render_windows_logo(void) {
    static const char PROGMEM raw_windows_logo[] = {
          0,  0,  0,128,128,128,128,192,192,192,192,192,192,224,  0,224,
        224,224,224,224,240,240,240,240,240,240,248,248,248,  0,  0,  0,
          0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,  0,255,
        255,255,255,255,255,255,255,255,255,255,255,255,255,  0,  0,  0,
          0,  0,  0,254,254,254,254,254,254,254,254,254,254,254,  0,254,
        254,254,254,254,254,254,254,254,254,254,254,254,254,  0,  0,  0,
          0,  0,  0,  3,  3,  3,  3,  3,  3,  7,  7,  7,  7,  7,  0,  7,
         15, 15, 15, 15, 15, 15, 15, 15, 31, 31, 31, 31, 31,  0,  0,  0,
    };
    oled_write_raw_P(raw_windows_logo, sizeof(raw_windows_logo));
}

// OS Status
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    if (is_keyboard_left()) {
        oled_set_cursor(0, 5);
        switch (detected_os) {
            case OS_MACOS:
                render_apple_logo();
                break;
            case OS_IOS:
                oled_write(PSTR(" iOS"), false);
                break;
            case OS_WINDOWS:
                render_windows_logo();
                break;
            case OS_LINUX:
                render_arch_logo();  // this would be awkward if it's not arch..
                                     // and I'm not drawing the penguin for this
                break;
            case OS_UNSURE:
                oled_write(PSTR("OS: ?"), false);
                // display some symbol to represent unfamiliar OS
                break;
        }
    }
    return true;
}

// Display Words-per-minute
int peak_wpm;
int curr_wpm;
void show_words_per_minute(bool is_left) {
    if (!is_left) {
        curr_wpm = get_current_wpm();

        // get WPM Peak | reset if wpm is 0
        oled_set_cursor(0, 12);
        oled_write(PSTR("^"), false);
        if (curr_wpm == 0) { peak_wpm = 0; }
        if (curr_wpm > peak_wpm || last_input_activity_elapsed() > 3500) {
            peak_wpm = curr_wpm;
        }
        oled_write(get_u8_str(peak_wpm, '0'), false);

        oled_set_cursor(0, 13);
        oled_write(PSTR("-----"), false);
        oled_set_cursor(1, 14);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_set_cursor(1, 15);
        oled_write(PSTR("WPM"), false);
    }
}

// Main
bool is_left;
bool oled_task_user() {
    is_left = is_keyboard_left();

    // Layer Status
    show_current_layer(is_left);

    // Capslock Status
    oled_set_cursor(1, 10);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(
        led_state.caps_lock ? PSTR("CAPS") : PSTR("\n"),
        false
    );

    // WPM
    show_words_per_minute(is_left);

    return false;
}

#endif
