#ifndef Switch_H
#define Switch_H


#include "stm32f10x.h"


#define     SWITCH1_GPIO_CLK        RCC_APB2Periph_GPIOA
#define     SWITCH1_GPIO_PORT       GPIOA			   
#define     SWITCH1_GPIO_PIN        GPIO_Pin_0

#define     SWITCH2_GPIO_CLK        RCC_APB2Periph_GPIOC
#define     SWITCH2_GPIO_PORT       GPIOC		   
#define     SWITCH2_GPIO_PIN        GPIO_Pin_13

#define     SWITCH3_GPIO_CLK        RCC_APB2Periph_GPIOB
#define     SWITCH3_GPIO_PORT       GPIOB		   
#define     SWITCH3_GPIO_PIN        GPIO_Pin_5
//按键按下为高电平，如下；反之，互换；
#define     SWITCH1_ON      1
#define     SWITCH1_OFF     0


void SWITCH_GPIO_Config(void);
uint8_t SWITCH1_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif /*Switch_H*/

