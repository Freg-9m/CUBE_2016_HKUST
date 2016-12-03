/**
  ******************************************************************************
  * @file 
  * @author  Freg
  * @date    11-Nov-2016
  * @brief   This file contains the headers of IO&Resources.
  ******************************************************************************
  * @attention
  *
  * This file is for educational purpose, the author will not take any sequences
	* caused by this file..
  * 
  * <h2><center>&copy; COPYRIGHT 2016 Freg_9m@gmail.com</center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IORES_H
#define __IORES_H
#include "stm32f10x.h"

void Device_Init   ( void );
void NVIC_Init_Freg( void );
void GPIO_Init_Freg( void );
void RCC_Init_Freg ( void );

#endif
