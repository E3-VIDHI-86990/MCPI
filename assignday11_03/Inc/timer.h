/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 30, 2024
*/

#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

#define TCLK	16000000UL
#define PR		16000


void Timer_Init(uint32_t ms);
uint32_t TIM6_DAC_IRQHandler(void);


#endif /* TIMER_H_ */
