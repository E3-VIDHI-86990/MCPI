/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 30, 2024
*/


#include "timer.h"


void Timer_Init(uint32_t ms) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	TIM7->PSC = (PR-1);
	uint32_t cnt = (TCLK / 1000) * ms / PR;
	TIM7->ARR = (cnt-1);
	TIM7->CNT = 0;
	TIM7->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	TIM7->CR1 |= TIM_CR1_CEN;
}


volatile uint16_t count = 0 ;

uint32_t TIM7_DAC_IRQHandler(void) {
	if(TIM7->SR & TIM_SR_UIF)
	{
		TIM7->SR &= ~TIM_SR_UIF;
		count++;
		DelayMs(1000);
		return count ;
	}
}
