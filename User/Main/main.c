#include "stm32f10x.h"
#include "Usart.h"


int main(void )
{
	USART_Config();
    while(1)
    {
        printf("Usart Test. \n");
    }
}

