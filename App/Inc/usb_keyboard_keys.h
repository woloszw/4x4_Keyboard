/*
 * usb_keyboard_keys.h
 *
 *  Created on: Feb 8, 2024
 *      Author: wolos
 */

#ifndef USB_KEYBOARD_KEYS_H_
#define USB_KEYBOARD_KEYS_H_


// Modifiers
#define KEY_LCTRL 0x01
#define KEY_LCTRL_SHIFT 0
#define KEY_LSHIFT 0x02
#define KEY_LSHIFT_SHIFT 1
#define KEY_LALT 0x04
#define KEY_LALT_SHIFT 2
#define KEY_LGUI 0x08
#define KEY_LGUI_SHIFT 3
#define KEY_RCTRL 0x10
#define KEY_RCTRL_SHIFT 4
#define KEY_RSHIFT 0x20
#define KEY_RSHIFT_SHIFT 5
#define KEY_RALT 0x40
#define KEY_RALT_SHIFT 6
#define KEY_RGUI 0x80
#define KEY_RGUI_SHIFT 7

// Keys
// Keys are in lowercase by default
#define KEY_A 0x04
#define KEY_B 0x05
#define KEY_C 0x06
#define KEY_D 0x07
#define KEY_E 0x08
#define KEY_F 0x09
#define KEY_G 0x0a
#define KEY_H 0x0b
#define KEY_I 0x0c
#define KEY_J 0x0d
#define KEY_K 0x0e
#define KEY_L 0x0f
#define KEY_M 0x10
#define KEY_N 0x11
#define KEY_O 0x12
#define KEY_P 0x13
#define KEY_Q 0x14
#define KEY_R 0x15
#define KEY_S 0x16
#define KEY_T 0x17
#define KEY_U 0x18
#define KEY_V 0x19
#define KEY_W 0x1a
#define KEY_X 0x1b
#define KEY_Y 0x1c
#define KEY_Z 0x1d


// Numbers
// Keyboard
#define KEY_1 0x1E
#define KEY_2 0x1F
#define KEY_3 0x20
#define KEY_4 0x21
#define KEY_5 0x22
#define KEY_6 0x23
#define KEY_7 0x24
#define KEY_8 0x25
#define KEY_9 0x26
#define KEY_0 0x27

//Keypad
#define KEY_KEYPAD1 0x59
#define KEY_KEYPAD2 0x5a
#define KEY_KEYPAD3 0x5b
#define KEY_KEYPAD4 0x5c
#define KEY_KEYPAD5 0x5d
#define KEY_KEYPAD6 0x5e
#define KEY_KEYPAD7 0x5f
#define KEY_KEYPAD8 0x60
#define KEY_KEYPAD9 0x61

#define KEY_ENTER 0x28
#define KEY_ESCAPE 0x29
#define KEY_BACKSPACE 0x2A
#define KEY_TAB 0x2B
#define KEY_SPACEBAR 0x2C

//Function keys
#define KEY_F1 0x3a
#define KEY_F2 0x3b
#define KEY_F3 0x3c
#define KEY_F4 0x3d
#define KEY_F5 0x3e
#define KEY_F6 0x3f
#define KEY_F7 0x40
#define KEY_F8 0x41
#define KEY_F9 0x42
#define KEY_F10 0x43
#define KEY_F11 0x44
#define KEY_F12 0x45
#define KEY_F13 0x68
#define KEY_F14 0x69
#define KEY_F15 0x6a
#define KEY_F16 0x6b
#define KEY_F17 0x6c
#define KEY_F18 0x6d
#define KEY_F19 0x6e
#define KEY_F20 0x6f
#define KEY_F21 0x70
#define KEY_F22 0x71
#define KEY_F23 0x72
#define KEY_F24 0x73

// Action
#define ACTION_UNDO 0x7a
#define ACTION_CUT 0x7b
#define ACTION_COPY 0x7c
#define ACTION_PASTE 0x7d
#define ACTION_FIND 0x7e
#define ACTION_MUTE 0x7f
#define ACTION_VOLUME_UP 0x80
#define ACTION_VOLUME_DOWN 0x81
























#endif /* USB_KEYBOARD_KEYS_H_ */
