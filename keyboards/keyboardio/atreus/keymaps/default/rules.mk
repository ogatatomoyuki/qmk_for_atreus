# --- Vial / QMK Settings 有効 ---
VIAL_ENABLE   = yes
VIA_ENABLE    = no        # サイズ節約のため off（Vial だけ使う前提）
QMK_SETTINGS  = yes       # Vial の「QMK Settings」タブを使う

# --- 最低限必要なものだけ ---
EEPROM_ENABLE = yes
LTO_ENABLE    = yes       # リンク時最適化（サイズ削減）

# --- 重い・未使用機能はすべて無効化 ---
CONSOLE_ENABLE       = no
COMMAND_ENABLE       = no
MOUSEKEY_ENABLE      = no
EXTRAKEY_ENABLE      = no
NKRO_ENABLE          = no
BACKLIGHT_ENABLE     = no
RGBLIGHT_ENABLE      = no
RGB_MATRIX_ENABLE    = no
AUDIO_ENABLE         = no
MIDI_ENABLE          = no
STENO_ENABLE         = no
AUTOCORRECT_ENABLE   = no
CAPS_WORD_ENABLE     = no
KEY_OVERRIDE_ENABLE  = no
UNICODE_ENABLE       = no
UNICODEMAP_ENABLE    = no

MAGIC_ENABLE         = no
BOOTMAGIC_ENABLE     = no        # BootMagic Lite も使わない前提
SPACE_CADET_ENABLE   = no
GRAVE_ESC_ENABLE     = no
TAP_DANCE_ENABLE     = no
LEADER_ENABLE        = no
COMBO_ENABLE         = no
