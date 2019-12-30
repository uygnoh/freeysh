
#include "stm32f10x.h"
#include "pbdata.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
void LED_GPIO_Config(void);

int main(void)
{
	LED_GPIO_Config();
	while(1)
	{
		pcout(13) = 1;
		delay_ms(500);
		pcout(13) = 0;
		delay_ms(500);
	}
	
}

void LED_GPIO_Config(void)
{	
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_13;
				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}


