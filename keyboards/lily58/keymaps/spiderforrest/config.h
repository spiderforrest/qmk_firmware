/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#define FORCE_NKRO

#pragma once

// pick hand
//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

// target taphold behavior: holding taphold key TAPHOLD and pressing key GENARIC will register:
// tap: if GENARIC is relesed first
// hold: if TAPHOLD is released first
// repeated tap: held past threshold
// EXCEPT: on pinkeys, there maybe should to be a ~50ms bias to tapping bc when i roll my hands i'm likely to release the taphold key first bc weak fingy

// taphold configs
#define TAPPING_TERM 160 			        // delay for activating taphold keys
//#define TAPPING_TERM 1                    // with retro tapping the decision is made based on if another key is pressed
//#define TAPPING_TERM 500                    // same as above but for permissive hold
//#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD                     // "rolling" presses(when taphold key is released before other key) register as two taps
// todo: switch to perm hold per key to only apply to mod-taps, i often wanna hold keys on other layers
#define IGNORE_MOD_TAP_INTERRUPT            // applies permissive hold to mod-tap keys
//#define RETRO_TAPPING                       // if no other key is pressed when a taphold key is held, send tap
//#define RETRO_TAPPING_PER_KEY
//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY	// if a second key is tapped while a tap hold is held before the tap term prefer tap, per key, see get_ignore_mod_tap_interrupt()
#define TAPPING_FORCE_HOLD			        // allows you to hold a key right after tapping it instead of it triggering the tap key repeating

// auto shift
//#define RETRO_SHIFT					    // allows using auto shift on taphold keys by triggering it if no other keys are pressed in a hold
//#define AUTO_SHIFT_TIMEOUT 130		    // delay for autoshifting
//#define AUTO_SHIFT_NO_SETUP			    // disables the adjustable autoshift features for memory space
//#define AUTO_SHIFT_REPEAT			        // allows repeat keys with autoshift on
//#define AUTO_SHIFT_MODIFIERS		        // reenables autoshift on modifiers
//#define NO_AUTO_SHIFT_ALPHA			    // disables auto shift on letters so i can just use it for symbols

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

// misc
#define COMBO_TERM 30
#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__) // miryoku macro

// space optimization
#undef LOCKING_SUPPORT_ENABLE		        // disabling lock key support
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_16BIT		            // total 16 layers
#define EXTRA_SHORT_COMBOS

