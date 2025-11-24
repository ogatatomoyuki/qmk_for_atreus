/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// ----- Vial 固有設定 -----
#define VIAL_KEYBOARD_UID {0x6B, 0xBA, 0xFA, 0x7D, 0xDA, 0x53, 0xF5, 0x0C}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0, 3, 3, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1, 7, 10, 11 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 4


// ----- Tap / Hold 関連のチューニング -----
// （あなたが貼ってくれた QMK Settings の値をそのままコンパイル時マクロにしたもの）

// Tapping Term = 75
#define TAPPING_TERM 75

// Permissive Hold = ON
#define PERMISSIVE_HOLD

// Hold On Other Key Press = ON
#define HOLD_ON_OTHER_KEY_PRESS

// Retro Tapping = OFF（何も定義しないのでデフォルトOFF）

// Quick Tap Term = 65
#define QUICK_TAP_TERM 65

// Tap Code Delay = 15
#define TAP_CODE_DELAY 15

// Tap Hold Caps Delay = 15
#define TAP_HOLD_CAPS_DELAY 15

// Tapping Toggle = 0（デフォルト0なので特に定義不要）

// Chordal Hold = OFF（ONにしたければコメントアウトを外す）
// #define CHORDAL_HOLD

// Flow Tap = 0（Flow Tap系の機能は使わないので未定義のまま）
