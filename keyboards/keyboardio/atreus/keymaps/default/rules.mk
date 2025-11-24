# Vial 本体
VIAL_ENABLE   = yes
VIA_ENABLE    = no        # VIAL だけ使う前提
EEPROM_ENABLE = yes       # 設定保存に必要

# QMK Settings を有効化（前に使っていた Tap/Hold 設定UI用）
QMK_SETTINGS  = yes

# コードサイズ削減
LTO_ENABLE    = yes

# ---- 不要な機能は全部OFFにする ----
CONSOLE_ENABLE       = no
COMMAND_ENABLE       = no
MAGIC_ENABLE         = no
BOOTMAGIC_ENABLE     = no
SPACE_CADET_ENABLE   = no
GRAVE_ESC_ENABLE     = no

MOUSEKEY_ENABLE      = no
EXTRAKEY_ENABLE      = no
NKRO_ENABLE          = no
BACKLIGHT_ENABLE     = no
RGBLIGHT_ENABLE      = no
RGB_MATRIX_ENABLE    = no
AUDIO_ENABLE         = no
MIDI_ENABLE          = no

UNICODE_ENABLE       = no
UNICODEMAP_ENABLE    = no
STENO_ENABLE         = no
AUTOCORRECT_ENABLE   = no
CAPS_WORD_ENABLE     = no
KEY_OVERRIDE_ENABLE  = no
TAP_DANCE_ENABLE     = no
LEADER_ENABLE        = no
COMBO_ENABLE         = no
