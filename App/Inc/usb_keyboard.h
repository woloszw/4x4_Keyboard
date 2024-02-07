/*
 * usb_keyboard.h
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */

#ifndef INC_USB_KEYBOARD_H_
#define INC_USB_KEYBOARD_H_

#include "usbd_hid.h"
#include "usb_keyboard_keys.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct
{
	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;
}subKeyBoard;



void USBKeyboardWriteNewMessage(USBD_HandleTypeDef *usb_handler, subKeyBoard * report,
		uint8_t mod, uint8_t kcode1, uint8_t kcode2, uint8_t kcode3,
		uint8_t kcode4, uint8_t kcode5, uint8_t kcode6);

void USBKeyboardWriteMessage(USBD_HandleTypeDef *usb_handler, subKeyBoard * report);

void USBKeyboardClearMessage(subKeyBoard * report);





#endif /* INC_USB_KEYBOARD_H_ */
