# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
LTO_ENABLE = yes			 # optimize space
SPACE_CADET_ENABLE = no	   # disabling for space
GRAVE_ESC_ENABLE = no	   # disabling for space
MAGIC_ENABLE = no		   # disabling for space

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
# Do not enable SLEEP_LED_ENABLE at the same time as BACKLIGHT_ENABLE. it uses the same timer.
SLEEP_LED_ENABLE = no  	    # Breathing sleep LED during USB suspend
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = yes      # Enable one-hand typing
OLED_ENABLE = yes           # OLED display
RAW_ENABLE = no             # Send raw data back and forth

KEY_LOCK_ENABLE = yes    		# key to supress next keyup
DYNAMIC_MACRO_ENABLE = no   	# on the fly macros
DEBOUNCE_TYPE = sym_defer_pk    # i dunno why i picked this but i've literally never had a problem so
COMBO_ENABLE = yes   			# key combo features?
AUTO_SHIFT_ENABLE = no			# holding a key emulates shift. pinkies love him.

Link_Time_Optimization = yes 	# more compile time, less keeb size
EXTRAFLAGS += -flto				# direct arg for link time optimization


# If you want to change the display of OLED, you need to change here
# SRC +=   ./lib/logo_reader.c \
	# ./lib/keylogger.c \
	# ./lib/mode_icon_reader.c \
	# ./lib/layer_state_reader.c \
	# ./lib/host_led_state_reader.c \
	# ./lib/timelogger.c \
	# ./lib/rgb_state_reader.c \
