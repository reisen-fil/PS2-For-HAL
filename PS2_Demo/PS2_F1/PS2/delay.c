#include "delay.h"

void delay_us(uint32_t us) //����CPUѭ��ʵ�ֵķǾ�׼Ӧ�õ�΢����ʱ����(��������F1ϵ��72M)
{
    uint32_t delay = (HAL_RCC_GetHCLKFreq() / 4000000 * us); //ʹ��HAL_RCC_GetHCLKFreq()������ȡ��Ƶֵ�����㷨�õ�1΢���ѭ������
    while (delay--); //ѭ��delay�Σ��ﵽ1΢����ʱ
}


//΢����ʱ
//void delay_us(uint32_t nus)
//{
// uint32_t temp;
// SysTick->LOAD = 9*nus;
// SysTick->VAL=0X00;//��ռ�����
// SysTick->CTRL=0X01;//ʹ�ܣ����������޶����������ⲿʱ��Դ
// do
// {
//  temp=SysTick->CTRL;//��ȡ��ǰ������ֵ
// }while((temp&0x01)&&(!(temp&(1<<16))));//�ȴ�ʱ�䵽��
//     SysTick->CTRL=0x00; //�رռ�����
//    SysTick->VAL =0X00; //��ռ�����
//}

/**
* @brief ��ʱ nus
* * @note �����Ƿ�ʹ�� OS, ������ʱ��ժȡ������ us ��ʱ
* @param nus: Ҫ��ʱ�� us ��
* @note nus ȡֵ��Χ: 0 ~ (2^32 / fac_us) (fac_us һ�����ϵͳ��Ƶ, �����������)
* @retval ��
*/
//void delay_us(uint32_t nus)
//{
// uint32_t ticks;
// uint32_t told, tnow, tcnt = 0;
// uint32_t reload = SysTick->LOAD; /* LOAD ��ֵ */
// ticks = nus * 72000000; /* ��Ҫ�Ľ����� */
// 
//#if SYS_SUPPORT_OS /* �����Ҫ֧�� OS */
// delay_osschedlock(); /* ���� OS ����������� */
//#endif
// told = SysTick->VAL; /* �ս���ʱ�ļ�����ֵ */
// while (1)
// {
// tnow = SysTick->VAL;
// if (tnow != told)
// {
// if (tnow < told)
// {
// tcnt += told - tnow; 
///* ����ע��һ�� SYSTICK ��һ���ݼ��ļ������Ϳ����� */
// }
// else
// {
// tcnt += reload - tnow + told;
// }
// told = tnow;
// if (tcnt >= ticks)
// {
// break; /* ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳� */
// }
// }
// }
//#if SYS_SUPPORT_OS /* �����Ҫ֧�� OS */
// delay_osschedunlock(); /* �ָ� OS ����������� */
//#endif 
//}


/////////////////////////////////////////////////////////////


/*
		ϵͳʱ��-->80MHz
		LOAD-->80000
*/

void Delay_us(uint32_t udelay)    //����hal��us���ӳ�
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


