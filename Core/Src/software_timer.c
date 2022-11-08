/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */

#include "global.h"


static int TIME_CYCLE = 10;

int timer0_flag = 0;
int timer1_flag = 0;
int timer2_flag = 0;

int timer0_counter = 0;
int timer1_counter = 0;
int timer2_counter = 0;

void setTimer0(int duration)
{
	timer0_counter = duration / TIME_CYCLE;
	timer0_flag = 0;
}
void setTimer1(int duration)
{
	timer1_counter  = duration / TIME_CYCLE;
	timer1_flag	 = 0;
}
void setTimer2(int duration)
{
	timer2_counter = duration / TIME_CYCLE;
	timer2_flag = 0;
}

void timerRun(void)
{
	if(timer0_counter  > 0)
	{
		timer0_counter --;
		if(timer0_counter  <= 0)
		{
			timer0_flag = 1;
		}
	}
	if(timer1_counter  > 0)
	{
		timer1_counter --;
		if(timer1_counter  <= 0)
		{
			timer1_flag = 1;
		}
	}
	if(timer2_counter  > 0)
	{
		timer2_counter --;
		if(timer2_counter  <= 0)
		{
			timer2_flag = 1;
		}
	}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2)
	{
		timerRun();
		button_reading();
	}
}

