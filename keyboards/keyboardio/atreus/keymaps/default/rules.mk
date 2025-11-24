# --- Vial 本体 ---
VIAL_ENABLE         = yes
VIA_ENABLE          = no        # VIA は使わないので off 推奨
EEPROM_ENABLE       = yes       # 設定を保存するため必須（通常はデフォルトで yes）

# --- QMK Settings（Vial の Tap-Hold 設定タブを有効にする） ---
QMK_SETTINGS        = yes

# --- 不要機能は切って容量を確保 ---
MOUSEKEY_ENABLE     = no
EXTRAKEY_ENABLE     = no
CONSOLE_ENABLE      = no
COMMAND_ENABLE      = no
NKRO_ENABLE         = no
BACKLIGHT_ENABLE    = no
RGBLIGHT_ENABLE     = no
AUDIO_ENABLE        = no
UNICODE_ENABLE      = no
UNICODEMAP_ENABLE   = no
TAP_DANCE_ENABLE    = no        # Tap Dance を使うなら yes に
LEADER_ENABLE       = no
COMBO_ENABLE        = no
KEY_OVERRIDE_ENABLE = no
CAPS_WORD_ENABLE    = no
STENO_ENABLE        = no
AUTOCORRECT_ENABLE  = no
MAGIC_ENABLE        = no
BOOTMAGIC_ENABLE    = no
SPACE_CADET_ENABLE  = no
GRAVE_ESC_ENABLE    = no        # 必要なら yes に
