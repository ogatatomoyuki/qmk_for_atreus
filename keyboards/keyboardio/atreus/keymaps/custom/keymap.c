#include QMK_KEYBOARD_H

enum layer_names {
    _BASE = 0,
    _L1,
    _L2,
    _L3
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// ホームロウモディファイア (左手下段)
#define CTL_Z MT(MOD_LCTL, KC_Z)
#define SFT_X MT(MOD_LSFT, KC_X)
#define ALT_C MT(MOD_LALT, KC_C)
#define GUI_V MT(MOD_LGUI, KC_V)

// 親指キー
#define L1_LNG2 LT(_L1, KC_LNG2)
#define GUI_SPC MT(MOD_LGUI, KC_SPC)
#define L2_LNG1 LT(_L2, KC_LNG1)
#define L3_BSPC LT(_L3, KC_BSPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer - QWERTY with home row mods
     * Row 0: 左5 + 右5
     * Row 1: 左5 + 右5
     * Row 2: 左6 + 右6
     * Row 3: 左6 + 右6 (親指)
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,

        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS,

        CTL_Z,   SFT_X,   ALT_C,   GUI_V,   KC_B,    XXXXXXX,
        XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,

        XXXXXXX, XXXXXXX, L1_LNG2, GUI_SPC, L2_LNG1, XXXXXXX,
        XXXXXXX, L3_BSPC, SFT_ENT, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Layer 1 - Navigation */
    [_L1] = LAYOUT(
        KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, KC_F4,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,

        KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TAB,  XXXXXXX,
        XXXXXXX, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  XXXXXXX,

        XXXXXXX, XXXXXXX, _______, KC_LGUI, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_RSFT, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Layer 2 - Mouse (disabled) + Reset */
    [_L2] = LAYOUT(
        QK_BOOT, KC_PWR,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Layer 3 - Numbers & Symbols */
    [_L3] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_EQL,  KC_BSLS, KC_GRV,  KC_SCLN, KC_QUOT,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH,

        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};
