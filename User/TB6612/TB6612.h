#ifndef TB6612_H
#define TB6612_H


#include "stm32f10x.h"
#include "GeneralTimer_3.h"


/*A4端口*/
#define AIN1_GPIO_PIN		GPIO_Pin_4
#define AIN1_GPIO_PORT  	GPIOA
#define AIN1_GPIO_CLK		RCC_APB2Periph_GPIOB

/*输出高电平*/
#define AIN1_ON			GPIO_SetBits(AIN1_GPIO_PORT,AIN1_GPIO_PIN)
/*输出低电平*/
#define AIN1_OFF		GPIO_ResetBits(AIN1_GPIO_PORT,AIN1_GPIO_PIN)


/*B1端口*/
#define AIN2_GPIO_PIN		GPIO_Pin_1
#define AIN2_GPIO_PORT	GPIOB
#define AIN2_GPIO_CLK		RCC_APB2Periph_GPIOB

/*输出高电平*/
#define AIN2_ON			GPIO_SetBits(AIN2_GPIO_PORT,AIN2_GPIO_PIN)
/*输出低电平*/
#define AIN2_OFF		GPIO_ResetBits(AIN2_GPIO_PORT,AIN2_GPIO_PIN)


/*B10端口*/
#define BIN1_GPIO_PIN		GPIO_Pin_10
#define BIN1_GPIO_PORT	GPIOB
#define BIN1_GPIO_CLK		RCC_APB2Periph_GPIOB

/*输出高电平*/
#define BIN1_ON			GPIO_SetBits(BIN1_GPIO_PORT,BIN1_GPIO_PIN)
/*输出低电平*/
#define BIN1_OFF		GPIO_ResetBits(BIN1_GPIO_PORT,BIN1_GPIO_PIN)


/*B11端口*/
#define BIN2_GPIO_PIN		GPIO_Pin_11
#define BIN2_GPIO_PORT	GPIOB
#define BIN2_GPIO_CLK		RCC_APB2Periph_GPIOB

/*输出高电平*/
#define BIN2_ON			GPIO_SetBits(BIN2_GPIO_PORT,BIN2_GPIO_PIN)
/*输出低电平*/
#define BIN2_OFF		GPIO_ResetBits(BIN2_GPIO_PORT,BIN2_GPIO_PIN)


/*A5端口*/
#define CIN1_GPIO_PIN		GPIO_Pin_5
#define CIN1_GPIO_PORT	    GPIOA
#define CIN1_GPIO_CLK		RCC_APB2Periph_GPIOB

/*输出高电平*/
#define CIN1_ON			GPIO_SetBits(CIN1_GPIO_PORT,CIN1_GPIO_PIN)
/*输出低电平*/
#define CIN1_OFF		GPIO_ResetBits(CIN1_GPIO_PORT,CIN1_GPIO_PIN)


/*A8端口*/
#define CIN2_GPIO_PIN		GPIO_Pin_8
#define CIN2_GPIO_PORT	    GPIOA
#define CIN2_GPIO_CLK		RCC_APB2Periph_GPIOB

/*输出高电平*/
#define CIN2_ON			GPIO_SetBits(CIN2_GPIO_PORT,CIN2_GPIO_PIN)
/*输出低电平*/
#define CIN2_OFF		GPIO_ResetBits(CIN2_GPIO_PORT,CIN2_GPIO_PIN)


void AIN1_GPIO_Config(void);
void AIN2_GPIO_Config(void);

void BIN1_GPIO_Config(void);
void BIN2_GPIO_Config(void);

void CIN1_GPIO_Config(void);
void CIN2_GPIO_Config(void);

#endif
