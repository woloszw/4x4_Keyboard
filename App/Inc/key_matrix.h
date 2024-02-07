/*
 * key_matrix.h
 *
 *  Created on: Feb 7, 2024
 *      Author: wolos
 */

#ifndef INC_KEY_MATRIX_H_
#define INC_KEY_MATRIX_H_

#include "main.h"

enum Columns
{
COLUMN1,
COLUMN2,
COLUMN3,
COLUMN4
};

enum Rows
{
ROW1,
ROW2,
ROW3,
ROW4
};


typedef struct KeyPosition
{
	GPIO_TypeDef* column_port;
	uint32_t column_pin;
	GPIO_TypeDef* row_port;
	uint32_t row_pin;
} KeyPosition;

#endif /* INC_KEY_MATRIX_H_ */
