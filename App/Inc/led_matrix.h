/*
 * led_matrix.h
 *
 *  Created on: Feb 5, 2024
 *      Author: wolos
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_
#include "main.h"
#include "gpio.h"

typedef struct Led
{
	GPIO_TypeDef* column_port;
	uint32_t column_pin;
	GPIO_TypeDef* row_port;
	uint32_t row_pin;
} Led;


void Led_Matrix_Clear_All();
void Led_Matrix_Set_All();
void Led_Matrix_Set(Led _led);





#endif /* INC_LED_MATRIX_H_ */
