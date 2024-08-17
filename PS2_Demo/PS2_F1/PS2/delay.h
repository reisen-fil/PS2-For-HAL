#ifndef DELAY_DELAY_H_
#define DELAY_DELAY_H_
#include "stm32f1xx_hal.h" //HAL库文件声明

void delay_us(uint32_t us);

void Delay_us(uint32_t udelay);    //定义hal库us级延迟

//void delay_us(uint32_t nus); //C文件中的函数声明
//void delay_us(uint32_t nus);


#endif /* DELAY_DELAY_H_ */
