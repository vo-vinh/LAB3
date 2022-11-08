/*
 * global.h
 *
 *  Created on: Nov 7, 2022
 *      Author: admin
 */
#include "software_timer.h"
#include "input_processing.h"
#include "7SEG.h"
#include "input_reading.h"
#include "fsm_trafficlights.h"
#include "Led_blink.h"
#include "display.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 	1
#define RED		2
#define AMBER 	3
#define GREEN 	4

#define SELECT_BUTTON	0
#define MOD_BUTTON		1
#define	SET_BUTTON		2

extern int status;
extern int status1;

extern int counterA;
extern int counterB;

extern int timer_red;
extern int timer_amber;
extern int timer_green;


extern int color_mode;
extern int mode;

extern int inc_flag;

extern int temp_red;
extern int temp_amber;
extern int temp_green;

extern int number;
#endif /* INC_GLOBAL_H_ */
