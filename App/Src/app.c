/*
 * app.c
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */
#include "app.h"


Led single_led =
{
	.column_port = LED_COL1_GPIO_Port,
	.column_pin = LED_COL1_Pin,
	.row_port = LED_ROW1_GPIO_Port,
	.row_pin = LED_ROW1_Pin
};

Led single_led2 =
{
	.column_port = LED_COL4_GPIO_Port,
	.column_pin = LED_COL4_Pin,
	.row_port = LED_ROW4_GPIO_Port,
	.row_pin = LED_ROW4_Pin
};




void App()
{
HAL_GPIO_WritePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin, 1);



while(1)
{
	HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
	Led_Matrix_Clear_All();
	HAL_Delay(1000);
	Led_Matrix_Set(single_led);
	HAL_Delay(1000);
}
}
