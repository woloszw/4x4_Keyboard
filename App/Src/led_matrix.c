/*
 * led_matrix.c
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */
#include "led_matrix.h"





void Led_Matrix_Set_All()
{
HAL_GPIO_WritePin(LED_COL1_GPIO_Port, LED_COL1_Pin, 0);
HAL_GPIO_WritePin(LED_COL2_GPIO_Port, LED_COL2_Pin, 0);
HAL_GPIO_WritePin(LED_COL3_GPIO_Port, LED_COL3_Pin, 0);
HAL_GPIO_WritePin(LED_COL4_GPIO_Port, LED_COL4_Pin, 0);

HAL_GPIO_WritePin(LED_ROW1_GPIO_Port, LED_ROW1_Pin, 1);
HAL_GPIO_WritePin(LED_ROW2_GPIO_Port, LED_ROW2_Pin, 1);
HAL_GPIO_WritePin(LED_ROW3_GPIO_Port, LED_ROW3_Pin, 1);
HAL_GPIO_WritePin(LED_ROW4_GPIO_Port, LED_ROW4_Pin, 1);

}



void Led_Matrix_Clear_All()
{
	HAL_GPIO_WritePin(LED_COL1_GPIO_Port, LED_COL1_Pin, 1);
	HAL_GPIO_WritePin(LED_COL2_GPIO_Port, LED_COL2_Pin, 1);
	HAL_GPIO_WritePin(LED_COL3_GPIO_Port, LED_COL3_Pin, 1);
	HAL_GPIO_WritePin(LED_COL4_GPIO_Port, LED_COL4_Pin, 1);

	HAL_GPIO_WritePin(LED_ROW1_GPIO_Port, LED_ROW1_Pin, 0);
	HAL_GPIO_WritePin(LED_ROW2_GPIO_Port, LED_ROW2_Pin, 0);
	HAL_GPIO_WritePin(LED_ROW3_GPIO_Port, LED_ROW3_Pin, 0);
	HAL_GPIO_WritePin(LED_ROW4_GPIO_Port, LED_ROW4_Pin, 0);
}


void Led_Matrix_Set(Led _led)
{
	HAL_GPIO_WritePin(LED_COL1_GPIO_Port, LED_COL1_Pin, 0);
	HAL_GPIO_WritePin(LED_COL2_GPIO_Port, LED_COL2_Pin, 1);
	HAL_GPIO_WritePin(LED_COL3_GPIO_Port, LED_COL3_Pin, 1);
	HAL_GPIO_WritePin(LED_COL4_GPIO_Port, LED_COL4_Pin, 1);

	HAL_GPIO_WritePin(LED_ROW1_GPIO_Port, LED_ROW1_Pin, 1);
}
