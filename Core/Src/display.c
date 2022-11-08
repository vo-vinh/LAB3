/*
 * display.c
 *
 *  Created on: Nov 8, 2022
 *      Author: admin
 */

#include "global.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState1 = BUTTON_RELEASED;

void mode1()
{
	display7SEG_B(1);
	if (timer0_flag == 1)
	{
			HAL_GPIO_WritePin(GPIOB, AMBER_A_Pin | AMBER_B_Pin | GREEN_A_Pin | GREEN_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOB, RED_A_Pin | RED_B_Pin);
			setTimer0(500);
	}
	switch(buttonState1)
	{
	case BUTTON_RELEASED:
		if(is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_PRESSED;
			temp_red += 1000;
		}
		break;
	case BUTTON_PRESSED:
		if (!is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_RELEASED;
		}
		else
		{
			if (is_button_pressed_1s(MOD_BUTTON))
			{
				buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_RELEASED;
		}
		if (timer2_flag == 1)
		{
			temp_red += 1000;
			setTimer2(1000);
		}
		if(is_button_pressed(SET_BUTTON))
		{
			timer_red += temp_red;
			mode = 0;
			temp_red = 0;
			buttonState1 = BUTTON_RELEASED;
		}
	}
}

void mode2()
{
	display7SEG_B(2);
	if (timer0_flag == 1)
	{
			HAL_GPIO_WritePin(GPIOB, RED_A_Pin | RED_B_Pin | GREEN_A_Pin | GREEN_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOB, AMBER_A_Pin | AMBER_B_Pin);
			setTimer0(500);
	}
	switch(buttonState1)
	{
	case BUTTON_RELEASED:
		if(is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_PRESSED;
			temp_amber += 1000;

		}
		break;
	case BUTTON_PRESSED:
		if (!is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_RELEASED;
		}
		else
		{
			if (is_button_pressed_1s(MOD_BUTTON))
			{
				buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_RELEASED;
		}
		if (timer2_flag == 1)
		{
			temp_amber += 1000;
			setTimer2(1000);
		}
		if(is_button_pressed(SET_BUTTON))
		{
			timer_amber += temp_amber;
			mode = 0;
			temp_amber = 0;
			buttonState1 = BUTTON_RELEASED;
		}
	}
}

void mode3()
{
	display7SEG_B(3);
	if (timer0_flag == 1)
	{
			HAL_GPIO_WritePin(GPIOB, RED_A_Pin | RED_B_Pin | AMBER_A_Pin | AMBER_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_TogglePin(GPIOB, GREEN_A_Pin | GREEN_B_Pin);
			setTimer0(500);
	}
	switch(buttonState1)
	{
	case BUTTON_RELEASED:
		if(is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_PRESSED;
			temp_amber += 1000;

		}
		break;
	case BUTTON_PRESSED:
		if (!is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_RELEASED;
		}
		else
		{
			if (is_button_pressed_1s(MOD_BUTTON))
			{
				buttonState1 = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(MOD_BUTTON))
		{
			buttonState1 = BUTTON_RELEASED;
		}
		if (timer2_flag == 1)
		{
			temp_green += 1000;
			setTimer2(1000);
		}
		if(is_button_pressed(SET_BUTTON))
		{
			timer_green += temp_green;
			mode = 0;
			temp_green = 0;
			buttonState1 = BUTTON_RELEASED;
		}
	}
}
