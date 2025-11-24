/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

// ----- Vial 固有設定 -----
#define VIAL_KEYBOARD_UID {0x6B, 0xBA, 0xFA, 0x7D, 0xDA, 0x53, 0xF5, 0x0C}

// アンロックコンボ（そのままでOK。キー位置を変えたいときだけ変更）
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0, 3, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1, 7, 10 }

// レイヤー数
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// ----- Tap / Hold 関連のチューニング -----
// （前に QMK Settings で使っていた値に近い設定にしてあります）

// Tapping Term
#define TAPPING_TERM 150

// Permissive Hold = ON
#define PERMISSIVE_HOLD

// Hold On Other Key Press = ON
#define HOLD_ON_OTHER_KEY_PRESS

// Retro Tapping = OFF（定義しない）

// Quick Tap Term
#define QUICK_TAP_TERM 65

// Tap Code Delay
#define TAP_CODE_DELAY 15

// Tap Hold Caps Delay
#define TAP_HOLD_CAPS_DELAY 15

// Tapping Toggle = 0 （デフォルトのまま）
// Chordal Hold / Flow Tap もデフォルトOFFのまま
