#include "stm32f10x.h"

#include "Usart.h"
#include "Find_Num.h"
#include "GeneralTimer_3.h"


int test_led;


int main(void )
{
	USART_Config();

    Find_Nun_Init();

    GENERAL_TIM_Init();
    while(1)
    {
        //printf("Usart Test. \n");

        //test_led = LED_1_out;

        //GENERAL_ccr4_Mode_Config(10);
    }
}

