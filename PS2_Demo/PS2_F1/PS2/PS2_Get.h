#ifndef __PS2_GET_H
#define __PS2_GET_H

#include "stm32f1xx_hal.h"

/*********************************************************
      
**********************************************************/	 

/* SPI�ĸ����ŵĺ����� */

#define DI   HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_15)           //PA0  ����

#define DO_H 		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,SET)        //����λ��
#define DO_L 		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,RESET)         //����λ��

#define CS_H 		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,SET)       //CS����
#define CS_L 		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,RESET)       //CS����

#define CLK_H 	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,SET)     //ʱ������
#define CLK_L 	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,RESET)      //ʱ������


//�ֱ��ӿڳ�ʼ��    ����  DI->PC14 
//                 ���  DO->PC15    CS->PB3  CLK->PA15

#define u8  uint8_t
#define u16  uint16_t


//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2       /* ��ҡ�˰��� */
#define PSB_R3          3       /* ��ҡ�˰��� */
#define PSB_START       4       
#define PSB_PAD_UP      5       /* ���� �ϰ��� */
#define PSB_PAD_RIGHT   6       /* ���� �Ұ��� */
#define PSB_PAD_DOWN    7       /* ���� �°��� */
#define PSB_PAD_LEFT    8       /* ���� �󰴼� */
#define PSB_L2          9       /* ǰ�� ���°��� */
#define PSB_R2          10      /* ǰ�� ���°��� */               
#define PSB_L1          11      /* ǰ�� ���ϰ��� */
#define PSB_R1          12      /* ǰ�� ���ϰ��� */
#define PSB_GREEN       13      /* ���� */
#define PSB_RED         14      /* Բ */
#define PSB_BLUE        15      /* �� */
#define PSB_PINK        16      /* ���� */

#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      16

//#define WHAMMY_BAR		8

//These are stick values

//ҡ������
#define PSS_RX 5                //��ҡ��X������
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

extern u8 Data[9];
extern u16 MASK[16];
extern u16 Handkey;
extern uint8_t Get_PS2key[16];

extern uint8_t Mode,PS2_Start;



//void PS2_Init(void);
u8 PS2_RedLight(void);   //�ж��Ƿ�Ϊ���ģʽ
void PS2_ReadData(void); //���ֱ�����
void PS2_Cmd(u8 CMD);		  //���ֱ���������
void PS2_DataKey(void);		  //����ֵ��ȡ
u8 PS2_AnologData(u8 button); //�õ�һ��ҡ�˵�ģ����
void PS2_ClearData(void);	  //������ݻ�����
void PS2_Vibration(u8 motor1, u8 motor2);//������motor1  0xFF���������أ�motor2  0x40~0xFF

void PS2_EnterConfing(void);	 //��������
void PS2_TurnOnAnalogMode(void); //����ģ����
void PS2_VibrationMode(void);    //������
void PS2_ExitConfing(void);	     //�������
void PS2_SetInit(void);		     //���ó�ʼ��

void PS2_Enable(void);

#endif



