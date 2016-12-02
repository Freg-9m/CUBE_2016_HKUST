#include "Include.h"


void Device_Init ( void )
{
	/********LED**********/
	GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能PB,PE端口时钟
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	/********TIMER********/	
	TIM3_PWM_Init(1999,719);//20MS
	TIM_SetCompare2(TIM3,1949);	
	/********UART*********/
	UARTInit(115200);
}



