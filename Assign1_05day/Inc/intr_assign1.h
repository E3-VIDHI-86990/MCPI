/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 21, 2024
*/

#ifndef INTR_ASSIGN1_H_
#define INTR_ASSIGN1_H_

#include "stm32f4xx.h"

#define GPIO_SWITCH				GPIOA
#define SWITCH_PIN				0
#define SWITCH_GPIO_CLKEN		0

#define SWITCH_EXTI				0

void SwitchInit(void);
void EXTI0_IRQHandler(void);

extern volatile uint32_t SwitchExtiFlag;


#endif /* INTR_ASSIGN1_H_ */
