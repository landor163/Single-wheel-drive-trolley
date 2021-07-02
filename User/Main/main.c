#include "stm32f10x.h"

#include "Usart.h"
#include "Find_Num.h"
#include "GeneralTimer_3.h"
#include "TB6612.h"


int test_led;


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
    while(1)
    {
        //printf("Usart Test. \n");

        //test_led = LED_1_out;

        //GENERAL_ccr4_Mode_Config(10);

        AIN1_ON;
    }
}

