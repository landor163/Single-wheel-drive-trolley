#include "Find_Num.h"


void Find_Nun_Init()
{
	GPIO_InitTypeDef  GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(LED_1_GPIO_CLK|LED_2_GPIO_CLK|LED_3_GPIO_CLK|LED_4_GPIO_CLK|LED_5_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED_1_GPIO_PIN|LED_2_GPIO_PIN|LED_3_GPIO_PIN|LED_4_GPIO_PIN|LED_5_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(LED_2_GPIO_PORT,&GPIO_InitStruct);
}

