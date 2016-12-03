/**
  ******************************************************************************
  * @file    IORES.C
  * @author  Freg
  * @date    3-Dec-2016
  * @brief   This file is the init step of an APP. IORES means IO&Resource, so 
  *          this file provide init step for IO and other resouces
  ******************************************************************************
  * @attention
  *
  * This file is for educational purpose, the author will not take any sequences
	* caused by this file..
  * 
  * <h2><center>&copy; COPYRIGHT 2016 Freg_9m@gmail.com</center></h2>
  ******************************************************************************
  */
#include "Include.h"


void Device_Init ( void )
{	
	RCC_Init_Freg ();
	NVIC_Init_Freg();	
	GPIO_Init_Freg();
	/********TIMER********/	
	//TIM3_PWM_Init(1999,719);//20MS
	//TIM_SetCompare2(TIM3,1949);	
	/********UART*********/
	UARTInit(115200);
	/********Ecoder*******/
	TIM2_Ecoder_Init();
	TIM1_Init(99,1799);
}

void NVIC_Init_Freg( void )
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//TIM1_IRQn NVIC ÅäÖÃ
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//TIM2_IRQn NVIC ÅäÖÃ
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//TIM3_IRQn NVIC ÅäÖÃ
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//Usart1 NVIC ÅäÖÃ
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			
	NVIC_Init(&NVIC_InitStructure);	
}

void GPIO_Init_Freg( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/********LED**********/
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void RCC_Init_Freg( void )
{	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
}

