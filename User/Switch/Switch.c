/*
@接线说明：
		SW1 接 A0 ;
		SW2 接 C13 ;
		SW3 接 B5 ;
*/


#include "Switch.h"


void SWITCH_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(SWITCH1_GPIO_CLK|SWITCH2_GPIO_CLK|SWITCH3_GPIO_CLK,ENABLE);
	//Switch1
	GPIO_InitStructure.GPIO_Pin=SWITCH1_GPIO_PIN ; 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING ;		//设置为 浮空输入
	GPIO_Init(SWITCH1_GPIO_PORT,&GPIO_InitStructure);
	//Switch2
	GPIO_InitStructure.GPIO_Pin=SWITCH2_GPIO_PIN ; 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING ; 
	GPIO_Init(SWITCH2_GPIO_PORT,&GPIO_InitStructure);	
    //Switch3
    GPIO_InitStructure.GPIO_Pin=SWITCH3_GPIO_PIN ; 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING ; 
	GPIO_Init(SWITCH3_GPIO_PORT,&GPIO_InitStructure);	
}

/*
@函数功能：检测是否有按键按下；
@输入：
    GPIOx：x可以是A、B、C、D、E；
    GPIO_Pin：等待读取的端口位；
@输出：
    KEY_ON：有按键按下；
    KEY_OFF：没有按键按下；
*/
uint8_t SWITCH1_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==SWITCH1_ON)				//检测 是否 有按键按下
	{	 
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==SWITCH1_ON);		//等待释放
		return 	SWITCH1_ON;	 
	}
	else
		return SWITCH1_OFF;
}

