#include "delay.h"

void delay_us(uint32_t us) //利用CPU循环实现的非精准应用的微秒延时函数(仅适用于F1系列72M)
{
    uint32_t delay = (HAL_RCC_GetHCLKFreq() / 4000000 * us); //使用HAL_RCC_GetHCLKFreq()函数获取主频值，经算法得到1微秒的循环次数
    while (delay--); //循环delay次，达到1微秒延时
}


//微秒延时
//void delay_us(uint32_t nus)
//{
// uint32_t temp;
// SysTick->LOAD = 9*nus;
// SysTick->VAL=0X00;//清空计数器
// SysTick->CTRL=0X01;//使能，减到零是无动作，采用外部时钟源
// do
// {
//  temp=SysTick->CTRL;//读取当前倒计数值
// }while((temp&0x01)&&(!(temp&(1<<16))));//等待时间到达
//     SysTick->CTRL=0x00; //关闭计数器
//    SysTick->VAL =0X00; //清空计数器
//}

/**
* @brief 延时 nus
* * @note 无论是否使用 OS, 都是用时钟摘取法来做 us 延时
* @param nus: 要延时的 us 数
* @note nus 取值范围: 0 ~ (2^32 / fac_us) (fac_us 一般等于系统主频, 自行套入计算)
* @retval 无
*/
//void delay_us(uint32_t nus)
//{
// uint32_t ticks;
// uint32_t told, tnow, tcnt = 0;
// uint32_t reload = SysTick->LOAD; /* LOAD 的值 */
// ticks = nus * 72000000; /* 需要的节拍数 */
// 
//#if SYS_SUPPORT_OS /* 如果需要支持 OS */
// delay_osschedlock(); /* 锁定 OS 的任务调度器 */
//#endif
// told = SysTick->VAL; /* 刚进入时的计数器值 */
// while (1)
// {
// tnow = SysTick->VAL;
// if (tnow != told)
// {
// if (tnow < told)
// {
// tcnt += told - tnow; 
///* 这里注意一下 SYSTICK 是一个递减的计数器就可以了 */
// }
// else
// {
// tcnt += reload - tnow + told;
// }
// told = tnow;
// if (tcnt >= ticks)
// {
// break; /* 时间超过/等于要延迟的时间,则退出 */
// }
// }
// }
//#if SYS_SUPPORT_OS /* 如果需要支持 OS */
// delay_osschedunlock(); /* 恢复 OS 的任务调度器 */
//#endif 
//}


/////////////////////////////////////////////////////////////


/*
		系统时钟-->80MHz
		LOAD-->80000
*/

void Delay_us(uint32_t udelay)    //定义hal库us级延迟
{
	uint32_t startval, tickn, delays, wait;
 
	startval = SysTick->VAL;
	tickn = HAL_GetTick();
	delays = udelay * 72;
	if (delays > startval)
	{
		while (HAL_GetTick() == tickn)
		{
 
		}
		wait = 72000 + startval - delays;
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


