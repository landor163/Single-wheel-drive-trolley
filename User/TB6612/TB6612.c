/*
@接线说明：
		AIN1 接 A05 ;
		AIN2 接 A04 ;
		BIN1 接 B11 ;
		BIN2 接 B10 ;
		CIN1 接 A08 ;
		CIN2 接 B01 ;
*/


#include "TB6612.h"


void AIN1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(AIN1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=AIN1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(AIN1_GPIO_PORT,&GPIO_InitStruct);
}

void AIN2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(AIN2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=AIN2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(AIN2_GPIO_PORT,&GPIO_InitStruct);
}

void BIN1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(BIN1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=BIN1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(BIN1_GPIO_PORT,&GPIO_InitStruct);
}

void BIN2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(BIN2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=BIN2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(BIN2_GPIO_PORT,&GPIO_InitStruct);
}

void CIN1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(CIN1_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=CIN1_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(CIN1_GPIO_PORT,&GPIO_InitStruct);
}

void CIN2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(CIN2_GPIO_CLK,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin=CIN2_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(CIN2_GPIO_PORT,&GPIO_InitStruct);
}

void Motor_A_UP(int x)//左前轮子
{
	GENERAL_ccr1_Mode_Config(x);
	AIN1_ON;
	AIN2_OFF;
}

void Motor_A_BACK(int x)//左前轮子
{
	GENERAL_ccr1_Mode_Config(x);
	AIN1_OFF;
	AIN2_ON;
}

void Motor_A_STOP(void)//左前轮子
{
	GENERAL_ccr1_Mode_Config(0);
	AIN1_OFF;
	AIN2_OFF;
}


void Motor_B_UP(int x)//右前轮子
{
	GENERAL_ccr2_Mode_Config(x);
	BIN1_OFF;
	BIN2_ON;
}

void Motor_B_BACK(int x)//右前轮子
{
	GENERAL_ccr2_Mode_Config(x);
	BIN1_ON;
	BIN2_OFF;
}

void Motor_B_STOP(void)//右前轮子
{
	GENERAL_ccr2_Mode_Config(0);
	BIN1_OFF;
	BIN2_OFF;
}


void Motor_C_UP(int x)//后面轮子
{
	GENERAL_ccr3_Mode_Config(x);
	CIN1_OFF;
	CIN2_ON;
}

void Motor_C_BACK(int x)//后面轮子
{
	GENERAL_ccr3_Mode_Config(x);
	CIN1_ON;
	CIN2_OFF;
}

void Motor_C_STOP(void)//后面轮子
{
	GENERAL_ccr3_Mode_Config(0);
	CIN1_OFF;
	CIN2_OFF;
}

