/*
 * app.h
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"
#include "led_matrix.h"
#include "key_matrix.h"
#include "usb_keyboard.h"

#define KEYS_AMOUNT 16
#define ROWS_AMOUNT 4
#define COLUMNS_AMOUNT 4
#define DEBOUNCE_TIME 20 //ms
#define LED_DELAY 100 //ms

typedef enum KeyStates
{
IDLE,
DEBOUNCE_PRESSED,
PRESSED,
DEBOUNCE_DEPRESSED
} KeyStates;


typedef struct Key
{
LedPosition ledPos;
KeyPosition keyPos;
subKeyBoard usbMessage;
uint8_t isPressed;
uint32_t keyTick;
uint32_t ledTick;
KeyStates keyState;
} Key;


void AppInit();
void AppAssignMessages();
void App();
uint8_t AppTimeElapsed(uint32_t* _tick, uint32_t period);



#endif /* INC_APP_H_ */
