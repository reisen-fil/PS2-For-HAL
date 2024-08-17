#ifndef __PS2_GET_H
#define __PS2_GET_H

#include "stm32f1xx_hal.h"

/*********************************************************
      
**********************************************************/	 

/* SPI四个引脚的宏配置 */

#define DI   HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)           //PA0  输入

#define DO_H 		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,SET)        //命令位高
#define DO_L 		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,RESET)         //命令位低

#define CS_H 		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET)       //CS拉高
#define CS_L 		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET)       //CS拉低

#define CLK_H 	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,SET)     //时钟拉高
#define CLK_L 	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET)      //时钟拉低


//手柄接口初始化    输入  DI->PC14 
//                 输出  DO->PC15    CS->PB3  CLK->PA15

#define u8  uint8_t
#define u16  uint16_t


//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2       /* 左摇杆按键 */
#define PSB_R3          3       /* 右摇杆按键 */
#define PSB_START       4       
#define PSB_PAD_UP      5       /* 靠左 上按键 */
#define PSB_PAD_RIGHT   6       /* 靠左 右按键 */
#define PSB_PAD_DOWN    7       /* 靠左 下按键 */
#define PSB_PAD_LEFT    8       /* 靠左 左按键 */
#define PSB_L2          9       /* 前置 左下按键 */
#define PSB_R2          10      /* 前置 右下按键 */               
#define PSB_L1          11      /* 前置 左上按键 */
#define PSB_R1          12      /* 前置 右上按键 */
#define PSB_GREEN       13      /* 三角 */
#define PSB_RED         14      /* 圆 */
#define PSB_BLUE        15      /* × */
#define PSB_PINK        16      /* 方形 */

#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      16

//#define WHAMMY_BAR		8

//These are stick values

//摇杆数据
#define PSS_RX 5                //右摇杆X轴数据
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

extern u8 Data[9];
extern u16 MASK[16];
extern u16 Handkey;
extern uint8_t Get_PS2key[16];

extern uint8_t Mode,PS2_Start;



//void PS2_Init(void);
u8 PS2_RedLight(void);   //判断是否为红灯模式
void PS2_ReadData(void); //读手柄数据
void PS2_Cmd(u8 CMD);		  //向手柄发送命令
void PS2_DataKey(void);		  //按键值读取
u8 PS2_AnologData(u8 button); //得到一个摇杆的模拟量
void PS2_ClearData(void);	  //清除数据缓冲区
void PS2_Vibration(u8 motor1, u8 motor2);//振动设置motor1  0xFF开，其他关，motor2  0x40~0xFF

void PS2_EnterConfing(void);	 //进入配置
void PS2_TurnOnAnalogMode(void); //发送模拟量
void PS2_VibrationMode(void);    //振动设置
void PS2_ExitConfing(void);	     //完成配置
void PS2_SetInit(void);		     //配置初始化

void PS2_Enable(void);

#endif



