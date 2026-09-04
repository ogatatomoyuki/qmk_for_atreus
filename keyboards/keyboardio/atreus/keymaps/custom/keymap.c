// 35-key OSM keymap for Keyboardio Atreus
// hold-tap 完全排除、Callum式カスタム one-shot + Swapper ベース
//
// Atreus LAYOUT (44 keys, 35 使用):
//   k00 k01 k02 k03 k04          k05 k06 k07 k08 k09
//   k10 k11 k12 k13 k14          k15 k16 k17 k18 k19
//   k20 k21 k22 k23 k24 k25  k26 k27 k28 k29 k30 k31
//   k32 k33 k34 k35 k36 k37  k38 k39 k40 k41 k42 k43
//
// マクロ（UNDO/CUT/COPY/PST/REDO/ZMIN/ZMOUT）は Cmd ベース（Mac 用）
// ターミナル Ctrl+C は NAV → skCTL → C で入力

#include QMK_KEYBOARD_H

// --- Layer definitions ---
enum layers {
    _BASE,
    _NAV,
    _SYM,
    _FUN,
};

// --- Custom keycodes ---
enum custom_keycodes {
    SW_WIN = SAFE_RANGE,  // Swapper (Cmd+Tab)
    SW_TAB,               // Tabber (Ctrl+Tab)
    OS_CTL,               // One-Shot Ctrl (Callum式)
    OS_SFT,               // One-Shot Shift
    OS_ALT,               // One-Shot Alt
    OS_GUI,               // One-Shot Gui
    MC_UNDO,              // Cmd+Z
    MC_CUT,               // Cmd+X
    MC_COPY,              // Cmd+C
    MC_PST,               // Cmd+V
    MC_REDO,              // Cmd+Shift+Z
    MC_ZMIN,              // Cmd+=
    MC_ZMOUT,             // Cmd+-
    MC_CW,                // Caps Word toggle (カスタム実装)
};

// --- Combos ---
enum combos {
    COMBO_LNG1,       // SPC+BSPC → LNG1 (IME ON)
    COMBO_LNG2,       // BSPC+ENT → LNG2 (IME OFF)
    COMBO_TMUX,       // D+F → Ctrl+B (tmux prefix)
    COMBO_LENGTH,
};

const uint16_t PROGMEM combo_lng1[] = {KC_SPC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_lng2[] = {KC_BSPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM combo_tmux[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_LNG1] = COMBO(combo_lng1, KC_LNG1),
    [COMBO_LNG2] = COMBO(combo_lng2, KC_LNG2),
    [COMBO_TMUX] = COMBO(combo_tmux, LCTL(KC_B)),
};

// --- Callum式 One-Shot Modifier (状態遷移マシン版) ---
// QMK の OSM() は MO() レイヤー離脱時にリセットされるため、
// 独自実装でレイヤー変更に依存しない one-shot を実現する。
//
// 状態遷移:
//   IDLE → (OS押下) → HELD        mod 登録
//   HELD → (OS離す) → ARMED       mod 登録のまま維持（タップ＝one-shot）
//   HELD → (他キー) → HELD_USED   mod 登録のまま（ホールド修飾）
//   ARMED → (他キー離す) → IDLE   mod 解除（one-shot 消費）
//   HELD_USED → (OS離す) → IDLE   mod 解除（ホールド終了）

typedef enum {
    OS_IDLE,
    OS_HELD,
    OS_ARMED,
    OS_HELD_USED,
} oneshot_state_t;

typedef struct {
    uint16_t        keycode;  // OS_CTL 等
    uint8_t         mod;      // MOD_LCTL 等
    oneshot_state_t state;
} oneshot_mod_t;

static oneshot_mod_t os_mods[] = {
    {OS_CTL, MOD_LCTL, OS_IDLE},
    {OS_SFT, MOD_LSFT, OS_IDLE},
    {OS_ALT, MOD_LALT, OS_IDLE},
    {OS_GUI, MOD_LGUI, OS_IDLE},
};
#define OS_MOD_COUNT (sizeof(os_mods) / sizeof(os_mods[0]))

// one-shot を消費すべきでないキー（レイヤーキー、one-shot 自身）
static bool is_oneshot_ignored(uint16_t keycode) {
    for (int i = 0; i < OS_MOD_COUNT; i++) {
        if (os_mods[i].keycode == keycode) return true;
    }
    switch (keycode) {
        case MO(_NAV):
        case MO(_SYM):
            return true;
    }
    return false;
}

// --- Keymap ---
// XXXXXXX = 未使用, _______ = 透過（下レイヤーのキーを使用）

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Base Layer
    //   Q    W    E    R    T  │  Y    U    I    O    P
    //   A    S    D    F    G  │  H    J    K    L    -
    //   Z    X    C    V    B  │  N    M    ,    .    /
    //             NAV  SPC SYM│  BSPC ENT
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        XXXXXXX, XXXXXXX, MO(_NAV),KC_SPC,  MO(_SYM),XXXXXXX, XXXXXXX, KC_BSPC, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // NAV Layer（左内側親指）
    //   ESC  SWAP STAB CW   --- │  HOME PGDN PGUP END  SCRUP
    //   skCTL skSFT skALT skGUI TAB│ LEFT DOWN UP  RGHT SCRDN
    //   UNDO CUT  COPY PST REDO│  LCLK RCLK MCLK ZMIN ZMOUT
    //             ___  ___  FUN│  ___  ___
    [_NAV] = LAYOUT(
        KC_ESC,  SW_WIN,  SW_TAB,  MC_CW,   XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
        OS_CTL,  OS_SFT,  OS_ALT,  OS_GUI,  KC_TAB,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        MC_UNDO, MC_CUT,  MC_COPY, MC_PST,  MC_REDO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MC_ZMIN, MC_ZMOUT,XXXXXXX,
        XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // SYM Layer（左外側親指）
    //   1    2    3    4    5  │  6    7    8    9    0
    //   skCTL skSFT skALT skGUI -│  =    \    `    ;    '
    //   -    -    -    -    -  │  [    ]    {    }    |
    //             FUN  ___  ___│  ___  ___
    [_SYM] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        OS_CTL,  OS_SFT,  OS_ALT,  OS_GUI,  XXXXXXX,                            KC_EQL,  KC_BSLS, KC_GRV,  KC_SCLN, KC_QUOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, S(KC_LBRC),S(KC_RBRC),S(KC_BSLS),
        XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    // FUN Layer（NAV + SYM 同時）
    //   F1   F2   F3   F4   F5 │  -    -    -    -    -
    //   F6   F7   F8   F9   F10│  MUTE VOLD VOLU -    -
    //   F11  F12  -    -    -  │  -    -    -    -    -
    //             ___  ___  ___│  ___  ___
    [_FUN] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
        KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

// --- 自前 Caps Word 実装（QMK の caps_word は weak mods 依存のため使わない）---
static bool my_caps_word_on = false;

// --- Swapper state ---
static bool swapper_active = false;
static bool tabber_active = false;

// --- Tri-Layer + Swapper deactivation ---
layer_state_t layer_state_set_user(layer_state_t state) {
    // NAV + SYM 同時で FUN 自動起動
    if (layer_state_cmp(state, _NAV) && layer_state_cmp(state, _SYM)) {
        state |= (1UL << _FUN);
    } else {
        state &= ~(1UL << _FUN);
    }
    // NAV 離すと Swapper/Tabber 解除
    if (!layer_state_cmp(state, _NAV)) {
        if (swapper_active) { unregister_code(KC_LGUI); swapper_active = false; }
        if (tabber_active) { unregister_code(KC_LCTL); tabber_active = false; }
    }
    return state;
}

// --- Custom keycode handling ---
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // --- 自前 Caps Word 処理 ---
    if (my_caps_word_on && record->event.pressed) {
        switch (keycode) {
            case KC_A ... KC_Z:
                // Shift + 文字を手動送信
                register_code(KC_LSFT);
                wait_ms(30);
                tap_code(keycode);
                wait_ms(30);
                unregister_code(KC_LSFT);
                return false;  // QMK のデフォルト処理をスキップ
            case KC_1 ... KC_0:
            case KC_BSPC:
            case KC_DEL:
            case KC_MINS:
                // 数字、BS、DEL、- はそのまま通す（Caps Word 継続）
                break;
            case KC_SPC:
            case KC_ENT:
                // スペース、エンターで Caps Word 解除
                my_caps_word_on = false;
                break;
            default:
                // その他のキーで解除
                my_caps_word_on = false;
                break;
        }
    }

    // --- Callum式 One-Shot Modifier 処理 ---

    // (1) one-shot キー自体の処理
    for (int i = 0; i < OS_MOD_COUNT; i++) {
        if (keycode == os_mods[i].keycode) {
            if (record->event.pressed) {
                // 押下: mod を登録して HELD 状態へ
                register_mods(os_mods[i].mod);
                os_mods[i].state = OS_HELD;
            } else {
                // 離す: HELD → ARMED（タップ: mod 維持）
                //        HELD_USED → IDLE（ホールド終了: mod 解除）
                if (os_mods[i].state == OS_HELD) {
                    os_mods[i].state = OS_ARMED;
                    // mod は登録したまま（次キーで消費）
                } else if (os_mods[i].state == OS_HELD_USED) {
                    unregister_mods(os_mods[i].mod);
                    os_mods[i].state = OS_IDLE;
                }
            }
            return false;
        }
    }

    // (2) 通常キー（one-shot を消費すべきでないキーは除く）
    if (!is_oneshot_ignored(keycode)) {
        if (record->event.pressed) {
            // 押下: HELD → HELD_USED（ホールド中の使用を記録）
            for (int i = 0; i < OS_MOD_COUNT; i++) {
                if (os_mods[i].state == OS_HELD) {
                    os_mods[i].state = OS_HELD_USED;
                }
            }
            // ARMED の場合: mod は既に登録済みなので何もしない
        } else {
            // 離す: ARMED → IDLE（one-shot 消費、mod 解除）
            for (int i = 0; i < OS_MOD_COUNT; i++) {
                if (os_mods[i].state == OS_ARMED) {
                    unregister_mods(os_mods[i].mod);
                    os_mods[i].state = OS_IDLE;
                }
            }
        }
    }

    // USB レポート間に delay が必要（modifier 登録後、次キー送信前に
    // 最低 1 USB poll 分の間隔を空けないと macOS が modifier を認識しない）
    #define MACRO_DELAY 30

    switch (keycode) {
        // Swapper (Cmd+Tab): NAV 内で連打→サイクル、NAV 離すと確定
        case SW_WIN:
            if (record->event.pressed) {
                if (!swapper_active) { swapper_active = true; register_code(KC_LGUI); wait_ms(MACRO_DELAY); }
                tap_code(KC_TAB);
            }
            return false;
        // Tabber (Ctrl+Tab): ブラウザ/ターミナルタブ切替
        case SW_TAB:
            if (record->event.pressed) {
                if (!tabber_active) { tabber_active = true; register_code(KC_LCTL); wait_ms(MACRO_DELAY); }
                tap_code(KC_TAB);
            }
            return false;
        // Macros (Cmd ベース = Mac 用)
        case MC_UNDO:
            if (record->event.pressed) { register_code(KC_LGUI); wait_ms(MACRO_DELAY); tap_code(KC_Z); wait_ms(MACRO_DELAY); unregister_code(KC_LGUI); }
            return false;
        case MC_CUT:
            if (record->event.pressed) { register_code(KC_LGUI); wait_ms(MACRO_DELAY); tap_code(KC_X); wait_ms(MACRO_DELAY); unregister_code(KC_LGUI); }
            return false;
        case MC_COPY:
            if (record->event.pressed) { register_code(KC_LGUI); wait_ms(MACRO_DELAY); tap_code(KC_C); wait_ms(MACRO_DELAY); unregister_code(KC_LGUI); }
            return false;
        case MC_PST:
            if (record->event.pressed) { register_code(KC_LGUI); wait_ms(MACRO_DELAY); tap_code(KC_V); wait_ms(MACRO_DELAY); unregister_code(KC_LGUI); }
            return false;
        case MC_REDO:
            if (record->event.pressed) { register_code(KC_LGUI); wait_ms(MACRO_DELAY); register_code(KC_LSFT); wait_ms(MACRO_DELAY); tap_code(KC_Z); wait_ms(MACRO_DELAY); unregister_code(KC_LSFT); unregister_code(KC_LGUI); }
            return false;
        case MC_ZMIN:
            if (record->event.pressed) { register_code(KC_LGUI); wait_ms(MACRO_DELAY); tap_code(KC_EQL); wait_ms(MACRO_DELAY); unregister_code(KC_LGUI); }
            return false;
        case MC_ZMOUT:
            if (record->event.pressed) { register_code(KC_LGUI); wait_ms(MACRO_DELAY); tap_code(KC_MINS); wait_ms(MACRO_DELAY); unregister_code(KC_LGUI); }
            return false;
        case MC_CW:
            if (record->event.pressed) { my_caps_word_on = !my_caps_word_on; }
            return false;
    }
    return true;
}
