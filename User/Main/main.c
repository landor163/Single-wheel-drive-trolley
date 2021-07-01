#include "stm32f10x.h"
#include "Usart.h"
#include "Find_Num.h"


int test_led;


int main(void )
{
	USART_Config();
    Find_Nun_Init();
    while(1)
    {
        //printf("Usart Test. \n");

        //test_led = LED_1_out;
    }
}

