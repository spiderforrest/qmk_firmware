

#define FORCE_NKRO                  // enforce nkro
#define TAPPING_TOGGLE 2            // as above, sets the taps for TT to toggle
#define TAPPING_TERM 175 			// delay for activating taphold keys
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY	// if a second key is tapped while a tap hold is held before the tap term prefer tap
#define TAPPING_FORCE_HOLD			// allows you to hold a key right after tapping it instead of it triggering the tap
#define RGBLIGHT_LAYERS             // an easy system for indicating layers or caps with underglow
#define UNICODE_SELECTED_MODES UC_LNX   // sets unicode to use the linux method-for multi os supportse UC_(R)MOD to cycle
#define RGBLIGHT_ANIMATIONS


// Mouse key speed and acceleration
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// space optimization
#undef LOCKING_SUPPORT_ENABLE		// disabling lock key support
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_8BIT			// total 8 layers
