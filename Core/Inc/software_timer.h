/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: ASUS
 */
#include "main.h"

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer0_flag;
extern int timer2_flag;
extern int timer0_counter;
extern int timer1_counter;
extern int timer2_counter;

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);

void timerRun(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
