#ifndef __TIMER_H
#define __TIMER_H
#include "stm32f10x.h"
#include "include.h"

typedef enum
{
	Timer1 = 1,
	Timer2,
	Timer3
}TimerDefine;

void TIM3_Init(u16 Period,u16 Prescaler);
void TIM3_PWM_Init(u16 Period,u16 Prescaler);
void TIM2_Ecoder_Init(void);
 
#endif
