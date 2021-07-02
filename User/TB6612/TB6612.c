#include "TB6612.h"


void AIN1_GPIO_Config(void)
{
	GPIO_InitTypeDef		GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(AIN1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = AIN1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(AIN1_GPIO_PORT,&GPIO_InitStruct);
}

void AIN2_GPIO_Config(void)
{
	GPIO_InitTypeDef		GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(AIN2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = AIN2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(AIN2_GPIO_PORT,&GPIO_InitStruct);
}

void BIN1_GPIO_Config(void)
{
	GPIO_InitTypeDef		GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(BIN1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = BIN1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(BIN1_GPIO_PORT,&GPIO_InitStruct);
}

void BIN2_GPIO_Config(void)
{
	GPIO_InitTypeDef		GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(BIN2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = BIN2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(BIN2_GPIO_PORT,&GPIO_InitStruct);
}

void CIN1_GPIO_Config(void)
{
	GPIO_InitTypeDef		GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(CIN1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = CIN1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(CIN1_GPIO_PORT,&GPIO_InitStruct);
}

void CIN2_GPIO_Config(void)
{
	GPIO_InitTypeDef		GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(CIN2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = CIN2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(CIN2_GPIO_PORT,&GPIO_InitStruct);
}

