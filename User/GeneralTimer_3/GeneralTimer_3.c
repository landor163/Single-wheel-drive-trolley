/*
@接线说明：
		PWMA 接 A6 ;
		PWMB 接 A7 ;
		PWMC 接 B0 ;
*/


#include "GeneralTimer_3.h"


static void GENERAL_TIM_GPIO_Config(void) 
{
    GPIO_InitTypeDef GPIO_InitStructure;
	
    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK,ENABLE);
    GPIO_InitStructure.GPIO_Pin=GENERAL_TIM_CH1_PIN;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH1_PORT,&GPIO_InitStructure);
	
    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK,ENABLE);
    GPIO_InitStructure.GPIO_Pin=GENERAL_TIM_CH2_PIN;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH2_PORT,&GPIO_InitStructure);
	
    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK,ENABLE);
    GPIO_InitStructure.GPIO_Pin=GENERAL_TIM_CH3_PIN;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH3_PORT,&GPIO_InitStructure);
	
    RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK,ENABLE);
    GPIO_InitStructure.GPIO_Pin=GENERAL_TIM_CH4_PIN;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GENERAL_TIM_CH4_PORT,&GPIO_InitStructure);
}

static void GENERAL_TIM_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM_CLK,ENABLE);
	
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period;
	TIM_TimeBaseStructure.TIM_Prescaler=GENERAL_TIM_Prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;

	TIM_TimeBaseInit(GENERAL_TIM,&TIM_TimeBaseStructure);
}

void GENERAL_ccr1_Mode_Config(int a)
{
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	uint16_t CCR1_Val=a;
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=CCR1_Val;

	TIM_OC1Init(GENERAL_TIM,&TIM_OCInitStructure);

	TIM_OC1PreloadConfig(GENERAL_TIM,TIM_OCPreload_Enable);

	TIM_Cmd(GENERAL_TIM,ENABLE);
}

 void GENERAL_ccr2_Mode_Config(int a)
{
	TIM_OCInitTypeDef TIM_OCInitStructure;

	uint16_t CCR1_Val=a;

	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=CCR1_Val;

	TIM_OC2Init(GENERAL_TIM,&TIM_OCInitStructure);

	TIM_OC2PreloadConfig(GENERAL_TIM,TIM_OCPreload_Enable);

	TIM_Cmd(GENERAL_TIM,ENABLE);
}

void GENERAL_ccr3_Mode_Config(int a)
{
	TIM_OCInitTypeDef TIM_OCInitStructure;

	uint16_t CCR1_Val=a;

	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=CCR1_Val;

	TIM_OC3Init(GENERAL_TIM,&TIM_OCInitStructure);

	TIM_OC3PreloadConfig(GENERAL_TIM,TIM_OCPreload_Enable);

	TIM_Cmd(GENERAL_TIM,ENABLE);
}

void GENERAL_ccr4_Mode_Config(int a)
{
	TIM_OCInitTypeDef TIM_OCInitStructure;

	uint16_t CCR1_Val=a;
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse=CCR1_Val;

	TIM_OC4Init(GENERAL_TIM,&TIM_OCInitStructure);

	TIM_OC4PreloadConfig(GENERAL_TIM,TIM_OCPreload_Enable);

	TIM_Cmd(GENERAL_TIM,ENABLE);
}

void GENERAL_TIM_Init(void)
{
    GENERAL_TIM_GPIO_Config();
    GENERAL_TIM_Mode_Config();		
}

