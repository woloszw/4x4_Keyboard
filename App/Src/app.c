 /*
 * app.c
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */
#include "app.h"


//Keys are numered from left to right and from top to bottom
// E.g Key on the first column and third row is 7th key in the order

Key keys[KEYS_AMOUNT];

void AppInit()
{
	GPIO_TypeDef * keyRowPort;
	uint16_t keyRowPin;
	GPIO_TypeDef * keyColumnPort;
	uint16_t keyColumnPin;

	GPIO_TypeDef * ledRowPort;
	uint16_t ledRowPin;
	GPIO_TypeDef * ledColumnPort;
	uint16_t ledColumnPin;

	for(uint8_t i = 0; i < ROWS_AMOUNT; i++ )
	{
		switch(i)
		{
			case ROW1:
				keyRowPort = KEY_ROW1_GPIO_Port;
				keyRowPin = KEY_ROW1_Pin;
				ledRowPort = LED_ROW1_GPIO_Port;
				ledRowPin = LED_ROW1_Pin;
				break;
			case ROW2:
				keyRowPort = KEY_ROW2_GPIO_Port;
				keyRowPin = KEY_ROW2_Pin;
				ledRowPort = LED_ROW2_GPIO_Port;
				ledRowPin = LED_ROW2_Pin;
				break;
			case ROW3:
				keyRowPort = KEY_ROW3_GPIO_Port;
				keyRowPin = KEY_ROW3_Pin;
				ledRowPort = LED_ROW3_GPIO_Port;
				ledRowPin = LED_ROW3_Pin;
				break;
			case ROW4:
				keyRowPort = KEY_ROW4_GPIO_Port;
				keyRowPin = KEY_ROW4_Pin;
				ledRowPort = LED_ROW4_GPIO_Port;
				ledRowPin = LED_ROW4_Pin;
				break;
		}

		for (uint8_t j = 0; j < ROWS_AMOUNT; j++)
		{
			switch(j)
			{
			case COLUMN1:
				keyColumnPort = KEY_COL1_GPIO_Port;
				keyColumnPin = KEY_COL1_Pin;
				ledColumnPort = LED_COL1_GPIO_Port;
				ledColumnPin = LED_COL1_Pin;
				break;
			case COLUMN2:
				keyColumnPort = KEY_COL2_GPIO_Port;
				keyColumnPin = KEY_COL2_Pin;
				ledColumnPort = LED_COL2_GPIO_Port;
				ledColumnPin = LED_COL2_Pin;
				break;
			case COLUMN3:
				keyColumnPort = KEY_COL3_GPIO_Port;
				keyColumnPin = KEY_COL3_Pin;
				ledColumnPort = LED_COL3_GPIO_Port;
				ledColumnPin = LED_COL3_Pin;
				break;
			case COLUMN4:
				keyColumnPort = KEY_COL4_GPIO_Port;
				keyColumnPin = KEY_COL4_Pin;
				ledColumnPort = LED_COL4_GPIO_Port;
				ledColumnPin = LED_COL4_Pin;
				break;
			}

			keys[i * ROWS_AMOUNT + j].keyPos.column_port = keyColumnPort;
			keys[i * ROWS_AMOUNT + j].keyPos.column_pin = keyColumnPin;
			keys[i * ROWS_AMOUNT + j].keyPos.row_port = keyRowPort;
			keys[i * ROWS_AMOUNT + j].keyPos.row_pin = keyRowPin;

			keys[i * ROWS_AMOUNT + j].ledPos.column_port = ledColumnPort;
			keys[i * ROWS_AMOUNT + j].ledPos.column_pin = ledColumnPin;
			keys[i * ROWS_AMOUNT + j].ledPos.row_port = ledRowPort;
			keys[i * ROWS_AMOUNT + j].ledPos.row_pin = ledRowPin;

			keys[i * ROWS_AMOUNT + j].isPressed = 0;
			keys[i * ROWS_AMOUNT + j].keyTick = 0;
		}
	}
};

uint8_t AppTimeElapsed(uint32_t* _tick, uint32_t period)
{
if(HAL_GetTick()-*_tick >= period)
	return 1;
return 0;
}

void AppAssignMessages()
{

	for(uint8_t i = 0; i< KEYS_AMOUNT ; i++)
	{
		subKeyBoard message = {0,0,0,0,0,0,0,0};
		switch (i) {
			case 0:
				message.KEYCODE1 = KEY_A;
				break;
			case 1:
				message.KEYCODE1 = KEY_B;
				break;
			case 2:
				message.KEYCODE1 = KEY_C;
				break;
			case 3:
				message.KEYCODE1 = KEY_D;
				break;
			case 4:
				message.KEYCODE1 = KEY_1;
				break;
			case 5:
				message.KEYCODE1 = KEY_2;
				break;
			case 6:
				message.KEYCODE1 = KEY_3;
				break;
			case 7:
				message.KEYCODE1 = KEY_4;
				break;
			case 8:
				message.MODIFIER = KEY_LSHIFT;
				message.KEYCODE1 = KEY_A;
				break;
			case 9:
				message.MODIFIER = KEY_LSHIFT;
				message.KEYCODE1 = KEY_B;
				break;
			case 10:
				message.MODIFIER = KEY_LSHIFT;
				message.KEYCODE1 = KEY_C;
				break;
			case 11:
				message.MODIFIER = KEY_LSHIFT;
				message.KEYCODE1 = KEY_D;
				break;
			case 12:
				message.MODIFIER = KEY_LCTRL;
				message.KEYCODE1 = KEY_C;
				break;
			case 13:
				message.KEYCODE1 = ACTION_COPY;
				break;
			case 14:
				message.MODIFIER = KEY_LCTRL;
				message.KEYCODE1 = KEY_V;
				break;
			case 15:
				message.KEYCODE1 = ACTION_PASTE;
				break;
			default:
				break;
		}
		keys[i].usbMessage = message;
	}
}

void App()
{
HAL_GPIO_WritePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin, 1);

Led_Matrix_Set_All();
HAL_Delay(1000);
Led_Matrix_Clear_All();
HAL_Delay(100);

HAL_GPIO_WritePin(KEY_COL1_GPIO_Port, KEY_COL1_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(KEY_COL2_GPIO_Port, KEY_COL2_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(KEY_COL3_GPIO_Port, KEY_COL3_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(KEY_COL4_GPIO_Port, KEY_COL4_Pin, GPIO_PIN_RESET);


	while(1)
	{
		HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
		for(uint8_t i = 0; i< KEYS_AMOUNT ; i++)
		{
			switch(keys[i].keyState)
//			{
//				case IDLE:
//					keys[i].isPressed = HAL_GPIO_ReadPin(keys[i].keyPos.row_port, keys[i].keyPos.row_pin);
//					if(GPIO_PIN_SET == keys[i].isPressed )
//					{
//						keys[i].keyState = DEBOUNCE_PRESSED;
//						keys[i].keyTick = HAL_GetTick();
//					}
//					break;
//
//				case DEBOUNCE_PRESSED:
//					if(AppTimeElapsed(&keys[i].keyTick, DEBOUNCE_TIME))
//						keys[i].keyState = PRESSED;
//					break;
//
//				case PRESSED:
//					if(HAL_GPIO_ReadPin(keys[i].keyPos.row_port, keys[i].keyPos.row_pin))
//					{
//						//send message
//						USBKeyboardWriteMessage(&hUsbDeviceFS, &keys[i].usbMessage);
//						// light led
//						Led_Matrix_Set(&keys[i].ledPos);
//						keys[i].ledTick = HAL_GetTick();
//					}
//					else //The button has been released
//					{
//						keys[i].keyState = DEBOUNCE_DEPRESSED;
//						keys[i].keyTick = HAL_GetTick();
//					}
//					break;
//
//				case DEBOUNCE_DEPRESSED:
//					if(AppTimeElapsed(&keys[i].keyTick, DEBOUNCE_TIME))
//						keys[i].keyState = IDLE;
//					break;
//			}
//			if(AppTimeElapsed(&keys[i].keyTick, LED_DELAY))
//				Led_Matrix_Reset(&keys[i].ledPos);


			HAL_Delay(50);
			if(HAL_GPIO_ReadPin(&keys[i].keyPos.row_port, &keys[i].keyPos.row_pin))
				USBKeyboardWriteMessage(&hUsbDeviceFS, &keys[i].usbMessage);
			Led_Matrix_Set(&keys[i].ledPos);

			HAL_Delay(50);
//
			//HAL_GPIO_WritePin(keys[i].keyPos.column_port, keys[i].keyPos.column_pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(&keys.keyPos.column_port,&keys.keyPos.column_pin, GPIO_PIN_SET);
			Led_Matrix_Clear_All();


		}
	}
}

