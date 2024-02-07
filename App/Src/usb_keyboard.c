/*
 * usb_keyboard.c
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */
#include "usb_keyboard.h"




void USBKeyboardWriteNewMessage(USBD_HandleTypeDef *usb_handler, subKeyBoard * report,
		uint8_t mod, uint8_t kcode1, uint8_t kcode2, uint8_t kcode3,
		uint8_t kcode4, uint8_t kcode5, uint8_t kcode6)
{
USBKeyboardClearMessage(report);

report->MODIFIER = mod;
report->KEYCODE1 = kcode1;
report->KEYCODE2 = kcode2;
report->KEYCODE3 = kcode3;
report->KEYCODE4 = kcode4;
report->KEYCODE5 = kcode5;
report->KEYCODE6 = kcode6;

USBD_HID_SendReport(usb_handler, report, sizeof(&report));
};

void USBKeyboardWriteMessage(USBD_HandleTypeDef *usb_handler, subKeyBoard * report)
{
	USBD_HID_SendReport(usb_handler, report, sizeof(&report));
}

void USBKeyboardClearMessage(subKeyBoard * report)
{
	report->MODIFIER = 0;
	report->KEYCODE1 = 0;
	report->KEYCODE2 = 0;
	report->KEYCODE3 = 0;
	report->KEYCODE4 = 0;
	report->KEYCODE5 = 0;
	report->KEYCODE6 = 0;
};


//USBD_HID_SendReport(&hUsbDeviceFS,&keyBoardHIDsub,sizeof(keyBoardHIDsub));
