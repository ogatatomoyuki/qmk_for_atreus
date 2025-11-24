# ----- Vial 基本設定 -----
VIAL_ENABLE   = yes
VIA_ENABLE    = no        # VIAL専用にするので VIA は不要
EEPROM_ENABLE = yes       # Vial の設定保存に必要

# QMK_SETTINGS はフラッシュ容量的に無理なので OFF
# （Tap/Hold の数値は config.h のマクロで固定）
QMK_SETTINGS  = no

# リンク時最適化（コードサイズ削減）
LTO_ENABLE    = yes

# ----- 不要な機能を全てOFFにして軽量化 -----
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
