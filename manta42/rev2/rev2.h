#pragma once

#include "helix.h"

#ifndef SPLIT_KEYBOARD
    extern bool is_helix_master(void);
    #define is_keyboard_master() is_helix_master()
#endif

// Each keymap.c should use is_keyboard_master() instead of 'is_master', 'has_usb()'.
// But keep 'is_master' for a while for backwards compatibility
//  for the old keymap.c.
extern uint8_t is_master; // 'is_master' will be obsolete, it is recommended to use 'is_keyboard_master ()' instead.
#define has_usb() is_keyboard_master()

#define ___ KC_NO
#define LAYOUT( \
    L04, L03, L02, L01, L00,                       R00, R01, R02, R03, R04, \
    L14, L13, L12, L11, L10,                       R10, R11, R12, R13, R14, \
    L24, L23, L22, L21, L20, L30, L40,   R40, R30, R20, R21, R22, R23, R24, \
                   L34, L33, L32, L31,   R31, R32, R33, R34 \
) { \
    { L00, L01, L02, L03, L04, ___, ___ }, \
    { L10, L11, L12, L13, L14, ___, ___ }, \
    { L20, L21, L22, L23, L24, ___, ___ }, \
    { L30, L31, L32, L33, L34, ___, ___ }, \
    { L40, ___, ___, ___, ___, ___, ___ }, \
    { R00, R01, R02, R03, R04, ___, ___ }, \
    { R10, R11, R12, R13, R14, ___, ___ }, \
    { R20, R21, R22, R23, R24, ___, ___ }, \
    { R30, R31, R32, R33, R34, ___, ___ }, \
    { R40, ___, ___, ___, ___, ___, ___ }, \
}
