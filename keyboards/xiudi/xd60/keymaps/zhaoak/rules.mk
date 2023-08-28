# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build options
LTO_ENABLE = yes				 # optimize space, better linker that takes more time 
SPACE_CADET_ENABLE = no		   # disabling for space
GRAVE_ESC_ENABLE = yes		   # weirdly useful tbh
MAGIC_ENABLE = no			   # disabling for space
COMMAND_ENABLE = no     	    # Commands for debug and configuration
MOUSEKEY_ENABLE = yes   	     # Mouse keys
EXTRAKEY_ENABLE = yes   	     # Audio control and System control
CONSOLE_ENABLE = no     	    # Console for debug
NKRO_ENABLE = yes       	     # nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = yes   	   # Enable keyboard backlight functionality
# Do not enable SLEEP_LED_ENABLE at the same time as BACKLIGHT_ENABLE. it uses the same timer.
SLEEP_LED_ENABLE = no  		    # Breathing sleep LED during USB suspend
WPM_ENABLE = no	     		    # calculate words per minute 
VELOCIKEY_ENABLE = no			 # as above(does not need above on), but linked to rgb
MIDI_ENABLE = no        	    # MIDI controls
AUDIO_ENABLE = no       	    # Audio output on port C6
UNICODE_ENABLE = no    	    	 # unicode, for sending emojis, etc, maybe enable later
UNICODEMAP_ENABLE = no			# for unicode mapping
UCIS_ENABLE = no				# custom keycode/functions for unicode
BLUETOOTH_ENABLE = no   	    # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = yes   	    # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no  	    # Enable one-hand typing
OLED_DRIVER_ENABLE= no  	   # OLED display
KEY_LOCK_ENABLE = no    	     # key to supress next keyup
DYNAMIC_MACRO_ENABLE = no   	# on the fly macros
LEADER_ENABLE = no 				# vim style leader keys
AUTO_SHIFT_ENABLE = no			# holding a key emulates shift. pinkies love him.
DEBOUNCE_TYPE = sym_defer_pk    # i dunno why i picked this but i've literally never had a problem so

LAYOUTS = 60_ansi 60_ansi_split_bs_rshift 60_iso 60_iso_split_bs_rshift
