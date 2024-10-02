/*
 * timer.c
 *
 *  Created on: Oct 1, 2024
 *      Author: sunbeam
 */
#include"timer.h"


void Timer_init(void){
	RCC -> APB1ENR |= RCC_APB1ENR_TIM6EN;
    TIM6 -> PSC = (PR-1);
}

void Timer_delay(uint32_t ms)
{
	uint32_t count = (TCLK/1000)* ms/PR;
    TIM6 ->ARR = count - 1 ;
    TIM6 -> CNT = 0 ;
    TIM6->CR1 |= TIM_CR1_CEN;
    while(!(TIM6 -> SR & TIM_SR_UIF));
    TIM6 -> SR &= ~ TIM_SR_UIF;
    TIM6 -> CR1 &= ~TIM_CR1_CEN;
}
