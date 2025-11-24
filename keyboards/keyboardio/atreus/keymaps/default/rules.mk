# ----- Vial 基本設定 -----
VIAL_ENABLE   = yes
VIA_ENABLE    = no
EEPROM_ENABLE = yes

QMK_SETTINGS  = no        # ※ 容量の都合でオフ（タップ設定は config.h でやる方針）
LTO_ENABLE    = yes

# Alt Repeat Key は使わないのでオフ（これが今回のエラーの原因）
ALT_REPEAT_KEY_ENABLE = no

# ----- 不要な機能を全部OFFにして軽量化 -----
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
