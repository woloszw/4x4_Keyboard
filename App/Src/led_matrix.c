/*
 * led_matrix.c
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */
#include "led_matrix.h"

void Led_Matrix_Set_All()
{
HAL_GPIO_WritePin(LED_COL1_GPIO_Port, LED_COL1_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(LED_COL2_GPIO_Port, LED_COL2_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(LED_COL3_GPIO_Port, LED_COL3_Pin, GPIO_PIN_RESET);
HAL_GPIO_WritePin(LED_COL4_GPIO_Port, LED_COL4_Pin, GPIO_PIN_RESET);

HAL_GPIO_WritePin(LED_ROW1_GPIO_Port, LED_ROW1_Pin, GPIO_PIN_SET);
HAL_GPIO_WritePin(LED_ROW2_GPIO_Port, LED_ROW2_Pin, GPIO_PIN_SET);
HAL_GPIO_WritePin(LED_ROW3_GPIO_Port, LED_ROW3_Pin, GPIO_PIN_SET);
HAL_GPIO_WritePin(LED_ROW4_GPIO_Port, LED_ROW4_Pin, GPIO_PIN_SET);
}

void Led_Matrix_Clear_All()
{
	HAL_GPIO_WritePin(LED_COL1_GPIO_Port, LED_COL1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_COL2_GPIO_Port, LED_COL2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_COL3_GPIO_Port, LED_COL3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_COL4_GPIO_Port, LED_COL4_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(LED_ROW1_GPIO_Port, LED_ROW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_ROW2_GPIO_Port, LED_ROW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_ROW3_GPIO_Port, LED_ROW3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_ROW4_GPIO_Port, LED_ROW4_Pin, GPIO_PIN_RESET);
}

void Led_Matrix_Set(LedPosition* _led)
{
	HAL_GPIO_WritePin(_led->column_port, _led->column_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(_led->row_port, _led->row_pin, GPIO_PIN_SET);
}

void Led_Matrix_Reset(LedPosition* _led)
{
	HAL_GPIO_WritePin(_led->column_port, _led->column_pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(_led->row_port, _led->row_pin, GPIO_PIN_RESET);
}
