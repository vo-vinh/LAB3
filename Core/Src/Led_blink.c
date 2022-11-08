/*
 * Led_blink.c
 *
 *  Created on: Nov 8, 2022
 *      Author: admin
 */
#include "global.h"

void ledBlink(int color)
{

	if (timer0_flag == 1)
	{
		switch(color)
		{
		case INIT:
			HAL_GPIO_TogglePin(GPIOB, RED_A_Pin | AMBER_A_Pin | GREEN_A_Pin | RED_B_Pin | AMBER_B_Pin | GREEN_B_Pin);
			setTimer1(500);
			break;
		case RED:
			HAL_GPIO_TogglePin(GPIOB, RED_A_Pin | RED_B_Pin);
			setTimer1(500);
			break;
		case AMBER:
			HAL_GPIO_TogglePin(GPIOB, AMBER_A_Pin | AMBER_B_Pin);
			setTimer1(500);
			break;
		case GREEN:
			HAL_GPIO_TogglePin(GPIOB, GREEN_A_Pin | GREEN_B_Pin);
			setTimer1(500);
			break;
		default:
			break;
		}
	}
}

void ledBlinkOFF()
{
	HAL_GPIO_WritePin(GPIOB, RED_A_Pin | AMBER_A_Pin | GREEN_A_Pin | RED_B_Pin | AMBER_B_Pin | GREEN_B_Pin, GPIO_PIN_SET);
}


