/*
 * 7SEG.c
 *
 *  Created on: Nov 7, 2022
 *      Author: admin
 */

#include "global.h"
int led_index = 0;
void display7SEG_A(int num)
{
	switch(num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegB_Pin | SegC_Pin |
										SegD_Pin | SegE_Pin | SegF_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegG_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SegB_Pin | SegC_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegD_Pin | SegE_Pin | SegF_Pin | SegG_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegB_Pin | SegD_Pin | SegE_Pin | SegG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegF_Pin | SegC_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegB_Pin | SegC_Pin | SegD_Pin | SegG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegF_Pin | SegE_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SegB_Pin | SegC_Pin | SegF_Pin | SegG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegE_Pin | SegD_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegF_Pin | SegC_Pin | SegD_Pin | SegG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegB_Pin | SegE_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegF_Pin | SegC_Pin | SegD_Pin | SegE_Pin | SegG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegB_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegB_Pin | SegC_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegD_Pin | SegE_Pin | SegF_Pin | SegG_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegB_Pin | SegC_Pin | SegD_Pin | SegE_Pin | SegF_Pin | SegG_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SegA_Pin | SegB_Pin | SegC_Pin | SegD_Pin | SegF_Pin | SegG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegE_Pin, SET);
		break;
	}
}

void display7SEG_B(int num)
{
	switch(num)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegBB_Pin | SegCC_Pin |
										SegDD_Pin | SegEE_Pin | SegFF_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegGG_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SegBB_Pin | SegCC_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegDD_Pin | SegEE_Pin | SegFF_Pin | SegGG_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegBB_Pin | SegDD_Pin | SegEE_Pin | SegGG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegFF_Pin | SegCC_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegBB_Pin | SegCC_Pin | SegDD_Pin | SegGG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegFF_Pin | SegEE_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SegBB_Pin | SegCC_Pin | SegFF_Pin | SegGG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegEE_Pin | SegDD_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegFF_Pin | SegCC_Pin | SegDD_Pin | SegGG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegBB_Pin | SegEE_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegFF_Pin | SegCC_Pin | SegDD_Pin | SegEE_Pin | SegGG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegBB_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegBB_Pin | SegCC_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegDD_Pin | SegEE_Pin | SegFF_Pin | SegGG_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegBB_Pin | SegCC_Pin | SegDD_Pin | SegEE_Pin | SegFF_Pin | SegGG_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SegAA_Pin | SegBB_Pin | SegCC_Pin | SegDD_Pin | SegFF_Pin | SegGG_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SegEE_Pin, SET);
		break;
	}
}

void displayNumber_A(int num)
{
	switch(led_index)
		{
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG_A(num % 10);
			if (timer2_flag == 1)
			{
				led_index = 1;
				setTimer2(20);

			}
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			display7SEG_A(num / 10);
			if (timer2_flag == 1)
			{
				led_index = 0;
				setTimer2(20);
			}
			break;
		default:
			break;
		}
}

void displayNumber_B(int num)
{
	switch(led_index)
	{
	case 0:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SEG_B(num % 10);
		if (timer2_flag == 1)
		{
			led_index = 1;
			setTimer2(20);

		}
		break;
	case 1:
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		display7SEG_B(num / 10);
		if (timer2_flag == 1)
		{
			led_index = 0;
			setTimer2(20);
		}
		break;
	default:
		break;
	}
}

