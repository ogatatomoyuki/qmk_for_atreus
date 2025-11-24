# Vial を使うので VIA はオフ
VIA_ENABLE          = no
VIAL_ENABLE         = yes
LTO_ENABLE          = yes

# Vial のために必要
EEPROM_ENABLE       = yes

# 余計な設定画面はいらない
QMK_SETTINGS        = yes

# --- 必要なければ全部 no に（あとで必要になったら yes に変える） ---
MOUSEKEY_ENABLE     = no   # マウスキー使うなら yes
EXTRAKEY_ENABLE     = no   # メディアキーとかが欲しければ yes
CONSOLE_ENABLE      = no
COMMAND_ENABLE      = no
NKRO_ENABLE         = no
BACKLIGHT_ENABLE    = no
RGBLIGHT_ENABLE     = no
AUDIO_ENABLE        = no
UNICODE_ENABLE      = no
UNICODEMAP_ENABLE   = no
TAP_DANCE_ENABLE    = no
LEADER_ENABLE       = no
COMBO_ENABLE        = no
KEY_OVERRIDE_ENABLE = no
CAPS_WORD_ENABLE    = no
STENO_ENABLE        = no
AUTOCORRECT_ENABLE  = no
MAGIC_ENABLE        = no
BOOTMAGIC_ENABLE    = no
SPACE_CADET_ENABLE  = no
GRAVE_ESC_ENABLE    = no   # 必要なら yes に
