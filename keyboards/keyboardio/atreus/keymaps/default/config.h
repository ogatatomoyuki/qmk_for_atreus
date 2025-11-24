/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

// ----- Vial 固有設定 -----
#define VIAL_KEYBOARD_UID {0x6B, 0xBA, 0xFA, 0x7D, 0xDA, 0x53, 0xF5, 0x0C}

// アンロックコンボ（今使えている状態のまま）
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0, 3, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1, 7, 10 }

// レイヤー数（Vial 側の設定と合わせる）
#define DYNAMIC_KEYMAP_LAYER_COUNT 4


// ===== Tap / Hold 関連のチューニング =====
// QMK Settings でいじりたかった項目をここで固定します。

// Tapping Term（ミリ秒）
#define TAPPING_TERM 120

// Permissive Hold = ON
#define PERMISSIVE_HOLD

// Hold On Other Key Press = ON
#define HOLD_ON_OTHER_KEY_PRESS

// Retro Tapping = OFF（定義しないのでデフォルトOFF）

// Quick Tap Term（タップ扱いにする短い時間）
#define QUICK_TAP_TERM 100

// Tap Code Delay
#define TAP_CODE_DELAY 15

// Tap Hold Caps Delay
#define TAP_HOLD_CAPS_DELAY 15

// Tapping Toggle = 0（デフォルト0なので定義不要）
// Chordal Hold, Flow Tap も使わない前提で何も定義しません。
