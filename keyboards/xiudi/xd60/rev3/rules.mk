# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
LTO_ENABLE = yes				 # optimize space, better linker that takes more time 
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
SLEEP_LED_ENABLE = no  		    # Breathing sleep LED during USB suspend
VELOCIKEY_ENABLE = yes			 # as above(does not need above on), but linked to rgb
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.

LAYOUTS = 60_ansi 60_ansi_split_bs_rshift 60_iso 60_iso_split_bs_rshift
