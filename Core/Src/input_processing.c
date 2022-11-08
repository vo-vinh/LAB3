/*
 * input_processing.c
 *
 *  Created on: Nov 7, 2022
 *      Author: admin
 */


#include "global.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;

//void modify(void)
//{
//	if (select_status2 == 0)
//	{
//		select_status2 = 1;
//		ledBlink(INIT);
//		if(is_button_pressed(SELECT_BUTTON))
//		{
//			switch(color_mode)
//			{
//			case INIT:
//				ledBlink(INIT);
//				color_mode = RED;
//				break;
//			case RED:
//				ledBlink(RED);
//				display7SEG_A(color_mode+1);
//				color_mode = AMBER;
//				break;
//			case AMBER:
//				ledBlink(AMBER);
//				display7SEG_A(color_mode+1);
//				color_mode = GREEN;
//				break;
//			case GREEN:
//				ledBlink(GREEN);
//				display7SEG_A(color_mode+1);
//				color_mode = RED;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//	else if(select_mode == 1)
//	{
//		ledBlinkOFF();
//		select_mode = 0;
//	}
//	if (is_button_pressed(MOD_BUTTON))
//	{
//		switch(color_mode)
//		{
//		case RED:
//			temp_red = timer_red / 1000;
//			temp_red = temp_red > 99 ? 1 : temp_red + 1;
//			display7SEG_B(temp_red > 9 ? temp_red % 10 : temp_red);
//			color_mode = AMBER;
//			break;
//		case AMBER:
//			temp_amber = timer_amber / 1000;
//			temp_amber = temp_amber > 99 ? 1 : temp_amber + 1;
//			display7SEG_B(temp_amber > 9 ? temp_amber % 10 : temp_amber);
//			color_mode = GREEN;
//			break;
//		case GREEN:
//			temp_green = timer_green / 1000;
//			temp_green = temp_green > 99 ? 1 : temp_green + 1;
//			display7SEG_B(temp_green > 9 ? temp_green % 10 : temp_green);
//			color_mode = RED;
//			break;
//		default:
//			break;
//		}
//	}
//	if (is_button_pressed(SET_BUTTON))
//	{
//		timer_red	= temp_red   * 1000;
//		timer_amber = temp_amber * 1000;
//		timer_green = temp_green * 1000;
//	}
//}

void fsm_mode(void)
{
	switch(mode)
	{
	case 0:
		if (is_button_pressed(SELECT_BUTTON))
		{
			mode = (mode + 1) % 4 == 0 ? mode = 1 : (mode + 1) % 4;
		}
		break;
	case 1:
		mode1();
		if (is_button_pressed(SELECT_BUTTON))
		{
			mode = (mode + 1) % 4 == 0 ? mode = 1 : (mode + 1) % 4;
		}
		break;
	case 2:
		mode2();
		if (is_button_pressed(SELECT_BUTTON))
		{
			mode = (mode + 1) % 4 == 0 ? mode = 1 : (mode + 1) % 4;
		}
		break;
	case 3:
		mode3();
		if (is_button_pressed(SELECT_BUTTON))
		{
			mode = (mode + 1) % 4 == 0 ? mode = 1 : (mode + 1) % 4;
		}
		break;
	default:
		break;
	}
}

void fsm_for_input_processing(void)
{
	switch(buttonState)
	{
	case BUTTON_RELEASED:
		if(is_button_pressed(SELECT_BUTTON))
		{
			buttonState = BUTTON_PRESSED;
		}
		break;
	case BUTTON_PRESSED:
		//input_process();
		if(!is_button_pressed(0))
		{
			buttonState = BUTTON_RELEASED;
		}
		else
		{
			if(is_button_pressed_1s(SELECT_BUTTON))
			{
				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(is_button_pressed(MOD_BUTTON) || is_button_pressed(SET_BUTTON))
		{
			buttonState = BUTTON_PRESSED;
		}

		if(!is_button_pressed(0))
		{
			buttonState = BUTTON_RELEASED;
		}
		break;
	}
}

