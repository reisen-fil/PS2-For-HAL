#include "delay.h"

/*
		系统时钟-->170MHz
		LOAD-->170000
*/

void Delay_us(uint32_t udelay)    //定义hal库us级延迟
{
	uint32_t startval, tickn, delays, wait;
 
	startval = SysTick->VAL;
	tickn = HAL_GetTick();
	delays = udelay * 170;
	if (delays > startval)
	{
		while (HAL_GetTick() == tickn)
		{
 
		}
		wait = 170000 + startval - delays;
		while (wait < SysTick->VAL)
		{
 
		}
	}
	else
	{
		wait = startval - delays;
		while (wait < SysTick->VAL && HAL_GetTick() == tickn)
		{
 
		}
	}
}


