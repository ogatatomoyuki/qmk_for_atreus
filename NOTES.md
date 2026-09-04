# Atreus QMK キーマップ設定ノート

## 現在の構成

- **コントローラー**: ATmega32U4（内蔵）
- **ファームウェア**: QMK + Vial
- **キーマップ**: Callum式 One-Shot ベース（hold-tap 排除）
- **接続**: USB のみ

## レイヤー構成

```
BASE: QWERTY + 親指に NAV/SPC/SYM | BSPC/ENT
NAV:  ESC, Swapper, Tabber, CapsLock, 矢印, マクロ(Undo/Cut/Copy/Paste/Redo), スクロール, ズーム
SYM:  数字, 記号, One-Shot Mods
FUN:  F1-F12, 音量（NAV+SYM 同時押し）
```

## コンボ

| キー | 結果 |
|------|------|
| SPC + BSPC | LNG1（IME ON）|
| BSPC + ENT | LNG2（IME OFF）|
| D + F | Ctrl+B（tmux prefix）|

## Swapper 実装

QMK には ZMK の `macro_pause_for_release` がないため、`process_record_user` + `layer_state_set_user` で実装。

- NAV + W: Cmd+Tab（NAV を離すと Cmd を解放）
- NAV + E: Ctrl+Tab（NAV を離すと Ctrl を解放）

## Corne / Charybdis との違い

| 機能 | Atreus (QMK) | Corne / Charybdis (ZMK) |
|------|-------------|------------------------|
| One-Shot Mods | OSM() | &sk |
| Swapper | process_record_user | macro_pause_for_release |
| コンボ | QMK combo (keycode) | ZMK combo (position) |
| Tri-layer | update_tri_layer_state | conditional_layers |
| マウスクリック | なし | あり（Charybdis） |
| BT設定 | なし（USB専用） | FUN レイヤーに配置 |

## ビルド方法

```bash
# ローカルビルド
qmk compile -kb keyboardio/atreus -km custom

# フラッシュ
qmk flash -kb keyboardio/atreus -km custom
# または Atreus をリセットモードにして:
# avrdude でフラッシュ
```

## 変更履歴

### 2026-02-21
- Mod-Tap / Layer-Tap を全廃 → Callum式 One-Shot ベースに変更
- Swapper / Tabber 実装（process_record_user）
- コンボ追加: IME 切替 (SPC+BSPC, BSPC+ENT), tmux prefix (D+F)
- Tri-layer 実装: NAV+SYM=FUN
- NAV レイヤーにクリップボードマクロ、スクロール、ズーム追加
- config.h: Tap/Hold 設定削除、COMBO_TERM 80, ONESHOT_TIMEOUT 2000 追加
- rules.mk: COMBO_ENABLE, MOUSEKEY_ENABLE, EXTRAKEY_ENABLE を有効化
- ファームウェアサイズ: 14508/28672 (50%)
