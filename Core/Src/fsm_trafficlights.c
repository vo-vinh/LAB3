/*
 * fsm_automatic.c
 *
 *  Created on: 4 Oct 2022
 *      Author: admin
 */
#include "global.h"

void fsm_trafficlights_A()
{
	counterA = timer0_counter / 100;
	switch(status)
	{
	case INIT:
		HAL_GPIO_WritePin(RED_A_GPIO_Port, RED_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(AMBER_A_GPIO_Port, AMBER_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_A_GPIO_Port, GREEN_A_Pin, GPIO_PIN_SET);
		status = RED;
		displayNumber_A(timer0_counter/100);
		setTimer0(timer_red);
		break;
	case RED:
		HAL_GPIO_WritePin(RED_A_GPIO_Port, RED_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AMBER_A_GPIO_Port, AMBER_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_A_GPIO_Port, GREEN_A_Pin, GPIO_PIN_SET);
		displayNumber_A(timer0_counter/100);
		if(timer0_flag == 1)
		{
			status = GREEN;
			setTimer0(timer_green);
		}

		break;
	case AMBER:
		HAL_GPIO_WritePin(RED_A_GPIO_Port, RED_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(AMBER_A_GPIO_Port, AMBER_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_A_GPIO_Port, GREEN_A_Pin, GPIO_PIN_SET);
		displayNumber_A(timer0_counter/100);
		if(timer0_flag == 1)
		{
			status = RED;
			setTimer0(timer_red);
		}

		break;
	case GREEN:
		HAL_GPIO_WritePin(RED_A_GPIO_Port, RED_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(AMBER_A_GPIO_Port, AMBER_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_A_GPIO_Port, GREEN_A_Pin, GPIO_PIN_RESET);
		displayNumber_A(timer0_counter/100);
		if(timer0_flag == 1)
		{
			status = AMBER;
			setTimer0(timer_amber);
		}

		break;
	default:
		break;
	}
}

void fsm_trafficlights_B()
{
	switch(status1)
	{
	case INIT:
		HAL_GPIO_WritePin(RED_B_GPIO_Port, RED_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(AMBER_B_GPIO_Port, AMBER_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_B_GPIO_Port, GREEN_B_Pin, GPIO_PIN_SET);
		displayNumber_B(timer1_counter/100);
		status1 = GREEN;
		setTimer1(timer_green);
		break;
	case RED:
		HAL_GPIO_WritePin(RED_B_GPIO_Port, RED_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AMBER_B_GPIO_Port, AMBER_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_B_GPIO_Port, GREEN_B_Pin, GPIO_PIN_SET);
		displayNumber_B(timer1_counter/100);
		if(timer1_flag == 1)
		{
			status1 = GREEN;
			setTimer1(timer_green);
		}

		break;
	case AMBER:
		HAL_GPIO_WritePin(RED_B_GPIO_Port, RED_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(AMBER_B_GPIO_Port, AMBER_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_B_GPIO_Port, GREEN_B_Pin, GPIO_PIN_SET);
		displayNumber_B(timer1_counter/100);
		if(timer1_flag == 1)
		{
			status1 = RED;
			setTimer1(timer_red);
		}

		break;
	case GREEN:
		HAL_GPIO_WritePin(RED_B_GPIO_Port, RED_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(AMBER_B_GPIO_Port, AMBER_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_B_GPIO_Port, GREEN_B_Pin, GPIO_PIN_RESET);
		displayNumber_B(timer1_counter/100);
		if(timer1_flag == 1)
		{
			status1 = AMBER;
			setTimer1(timer_amber);
		}
		break;
	default:
		break;
	}
}








