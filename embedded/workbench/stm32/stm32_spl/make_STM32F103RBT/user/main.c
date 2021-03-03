#include "stm32f10x.h"
#include "stm32f10x_conf.h"

int main(void)
{
	
	while (1) 
	{
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
		delay_ms(500);
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
		delay_ms(500);

	}

	return 0;
}




