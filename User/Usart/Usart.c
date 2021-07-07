/*
@接线说明：
		TX 接 A09 ；
		RX 接 A10 ；
@通信注释：
		变量 Cx 为 去掉帧头帧尾后的；
		0 为 除了黑色、红色 以外的所有情况；
		1 为 看到红灯；
		识别到门框的偏移量；
*/


#include "Usart.h"


int Cx;


static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitStructure.NVIC_IRQChannel=DEBUG_USART_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;

    NVIC_Init(&NVIC_InitStructure);
}

void USART_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);

	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;

	GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl=
	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(DEBUG_USARTx,&USART_InitStructure);

	NVIC_Configuration();

	USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);

	USART_Cmd(DEBUG_USARTx,ENABLE);
}

void Usart_SendByte(USART_TypeDef *pUSARTx,uint8_t ch)
{
	USART_SendData(pUSARTx,ch);

	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
}

void Usart_SendArray(USART_TypeDef *pUSARTx,uint8_t *array,uint16_t num)
{
    uint8_t i;

	for(i=0;i<num;i++)
    {
	    Usart_SendByte(pUSARTx,array[i]);
    }

	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}

void Usart_SendString(USART_TypeDef *pUSARTx,char *str)
{
    unsigned int k=0;

    do
    {
		Usart_SendByte(pUSARTx,*(str+k));
        k++;
    }while(*(str+k)!='\0');

    while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}

void Usart_SendHalfWord(USART_TypeDef *pUSARTx,uint16_t ch)
{
	uint8_t temp_h,temp_l;

	temp_h=(ch&0XFF00)>>8;
	temp_l=ch&0XFF;

	USART_SendData(pUSARTx,temp_h);	
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);

	USART_SendData(pUSARTx,temp_l);	
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);	
}

int fputc(int ch,FILE *f)
{
    USART_SendData(DEBUG_USARTx,(uint8_t)ch);

    while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_TXE)==RESET);

    return(ch);
}

int fgetc(FILE *f)
{
    while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_RXNE)==RESET);

    return(int)USART_ReceiveData(DEBUG_USARTx);
}

//USART1 全局中断服务函数；
void Openmv_Receive_Data(int16_t com_data)
{
	u8 i;

	static u8  RxCounter1=0;
	static u16 RxBuffer1[7]={0};
	static u8  RxState=0;
	static u8  RxFlag1=0;

	if(RxState==0 && com_data==0x2C)//0x2c帧头；
	{
		RxState=1;

		RxBuffer1[RxCounter1++]=com_data;
	}
	else if(RxState==1 && com_data==0x12)//0x12针尾；
			{
				RxState=2;

				RxBuffer1[RxCounter1++]=com_data;
			}
			else if(RxState==2)
			{
				RxBuffer1[RxCounter1++]=com_data;

				if(RxCounter1>=7 || com_data==0x5E)       //RxBuffer1 接收满了，接收数据结束；
				{
					RxState=3;
					RxFlag1=1;

					Cx=(uint8_t)(RxBuffer1[RxCounter1-2]);
					//Cy=RxBuffer1[RxCounter1-4];
					//Cw=RxBuffer1[RxCounter1-3];
					//Ch=RxBuffer1[RxCounter1-2];
				}
			}
			else if(RxState==3)//检测 是否 接收到 结束标志；
			{
				if(RxBuffer1[RxCounter1-1] == 0x5E)
				{
					USART_ITConfig(USART1,USART_IT_RXNE,DISABLE);//关中断；

					if(RxFlag1)
					{
						//OLED_Refresh();
						//OLED_ShowNum(0, 0,Cx,2,16,1);
						//OLED_ShowNum(0,17,Cy,3,16,1);
						//OLED_ShowNum(0,33,Cw,3,16,1);
						//OLED_ShowNum(0,49,Ch,3,16,1);
					}
					RxFlag1=0;
					RxCounter1=0;
					RxState=0;
					USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
				}
				else//接受错误；
				{
					RxState=0;
					RxCounter1=0;

					for(i=0;i<7;i++)
					{
						RxBuffer1[i]=0x00;//将存放数据数组清零；
					}
				}
			} 
			else//接收异常；
			{
				RxState=0;
				RxCounter1=0;

				for(i=0;i<7;i++)
				{
					RxBuffer1[i]=0x00;//将存放数据数组清零；
				}
			}	
}

