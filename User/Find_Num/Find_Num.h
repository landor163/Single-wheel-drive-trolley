#ifndef  Find_Num_H
#define  Find_Num_H


#include "stm32f10x.h"


#define LED_1_GPIO_PORT   GPIOB
#define LED_1_GPIO_CLK    RCC_APB2Periph_GPIOB
#define LED_1_GPIO_PIN    GPIO_Pin_4

#define LED_2_GPIO_PORT   GPIOB
#define LED_2_GPIO_CLK    RCC_APB2Periph_GPIOB
#define LED_2_GPIO_PIN    GPIO_Pin_8

#define LED_3_GPIO_PORT   GPIOB
#define LED_3_GPIO_CLK    RCC_APB2Periph_GPIOB
#define LED_3_GPIO_PIN    GPIO_Pin_9

#define LED_4_GPIO_PORT   GPIOC
#define LED_4_GPIO_CLK    RCC_APB2Periph_GPIOB
#define LED_4_GPIO_PIN    GPIO_Pin_8

#define LED_5_GPIO_PORT   GPIOC
#define LED_5_GPIO_CLK    RCC_APB2Periph_GPIOB
#define LED_5_GPIO_PIN    GPIO_Pin_9

#define LED_1_out  GPIO_ReadInputDataBit( LED_1_GPIO_PORT, LED_1_GPIO_PIN);
#define LED_2_out  GPIO_ReadInputDataBit( LED_2_GPIO_PORT, LED_2_GPIO_PIN);
#define LED_3_out  GPIO_ReadInputDataBit( LED_3_GPIO_PORT, LED_3_GPIO_PIN);
#define LED_4_out  GPIO_ReadInputDataBit( LED_4_GPIO_PORT, LED_4_GPIO_PIN);
#define LED_5_out  GPIO_ReadInputDataBit( LED_5_GPIO_PORT, LED_5_GPIO_PIN);


void Find_Nun_Init(void);

#endif /*Find_Num_H*/
