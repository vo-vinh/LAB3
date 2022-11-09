/*
 * input_processing.c
 *
 *  Created on: Nov 7, 2022
 *      Author: admin
 */


#include "global.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;

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
		fsm_trafficlights_A();
		fsm_trafficlights_B();
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

