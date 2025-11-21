#include QMK_KEYBOARD_H

// カスタムキーコードの定義
// GUISP (GUI + SPACE) は Layer 1 での LGUI(KC_SPACE) ショートカットに対応します。
enum custom_keycodes {
    GUISP = SAFE_RANGE, 
};

// レイヤー名の定義 (Vialの4層に対応)
enum layer_names {
    _BASE = 0,
    _ADJUST,
    _MOUSE,
    _NUMBERS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // レイヤー 0: _BASE (QWERTY) - Vial設定 Layer 0 に基づく
  [_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_MINUS,
    LCTL_T(KC_Z), LSFT_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), KC_B, KC_NO, KC_NO, KC_N, KC_M, RALT_T(KC_COMM), RSFT_T(KC_DOT), RCTL_T(KC_SLSH),
    KC_NO,   KC_NO,   LT(_ADJUST,KC_LANG2), LGUI_T(KC_SPACE), LT(_MOUSE,KC_LANG1), KC_NO, KC_NO, LT(_NUMBERS,KC_BSPC), RSFT_T(KC_ENTER), KC_NO, KC_NO, KC_NO
  ),

  // レイヤー 1: _ADJUST (調整レイヤー) - Vial設定 Layer 1 に基づく
  // Row 1, Col 4 に LGUI(KC_SPACE) の代わりとして GUISP を割り当て
  [_ADJUST] = LAYOUT(
    KC_ESCAPE, KC_NO,   KC_NO,   KC_NO,   KC_F4,                     XXXXXXX, XXXXXXX, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,  KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   GUISP,                     XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TAB,                    KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_LGUI, KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSHIFT, KC_NO,   KC_NO,   KC_NO
  ),

  // レイヤー 2: _MOUSE (マウス操作) - Vial設定 Layer 2 に基づく
  [_MOUSE] = LAYOUT(
    KC_NO,   KC_PWR,  KC_NO,   KC_NO,   KC_BTN1,                   XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     XXXXXXX, XXXXXXX, KC_NO,   KC_BTN1, KC_BTN2, KC_BTN3, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_D, KC_MS_R, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO
  ),

  // レイヤー 3: _NUMBERS (数字と記号) - Vial設定 Layer 3 に基づく
  [_NUMBERS] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     XXXXXXX, XXXXXXX, KC_EQL,  KC_BSLS, KC_GRV,  KC_SCLN, KC_QUOT,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH,
    KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO
  )
};

// カスタムマクロ処理の定義
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUISP:
            if (record->event.pressed) {
                // Cmd + Space を1発送る
                tap_code16(LGUI(KC_SPACE));
            }
            return false;  // ここで処理終了（他には流さない）
    }
    return true;
}
