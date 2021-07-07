#include "stm32f10x.h"

#include "Usart.h"
#include "Find_Num.h"
#include "GeneralTimer_3.h"
#include "TB6612.h"
#include "Switch.h"
#include "Encoder.h"


int main(void )
{
    USART_Config();

    Find_Nun_Init();

    GENERAL_TIM_Init();

    AIN1_GPIO_Config();
    AIN2_GPIO_Config();
    BIN1_GPIO_Config();
    BIN2_GPIO_Config();
    CIN1_GPIO_Config();
    CIN2_GPIO_Config();

    SWITCH_GPIO_Config();
    while(1)
    {
        if(SWITCH1_Scan(SWITCH1_GPIO_PORT,SWITCH1_GPIO_PIN)==SWITCH1_ON)		//当检测到 KEY1 被按下
        {
            Motor_A_UP(50);
        }
        
    }
}

