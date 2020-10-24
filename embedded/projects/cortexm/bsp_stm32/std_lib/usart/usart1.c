
#include "usart1.h"
/**
  ****************************************************************************
  * 串口1(USART1)初始化配置
  * 2018.10.29
  * @freeysh
  */
void usart_configure(void)
{
	/* configure the USART1 */
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_Non;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART1, &USART_InitStructure);
	/* Enable the USART1 */
	USART_Cmd(USART1, ENABLE);
}

int main(void)
{
	int i, data, Status;
	data = 'A';
	USART_SendData(USART1, data);
	
	for (i = 0; i < 30; i++) {
		data++;
		while (USART1_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	}
}



