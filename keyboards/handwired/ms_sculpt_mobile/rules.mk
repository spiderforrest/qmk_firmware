ifdef ASTAR
    MCU = atmega32u4
    CFLAGS = -D ASTAR
else
    MCU = at90usb1286
endif

# Bootloader selection
ifdef ASTAR
    BOOTLOADER = caterina
else
    BOOTLOADER = atmel-dfu
endif

BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

# Project specific files
SRC = babblePaste.c
