#include "stm32f10x.h"
#include "stm32f10x_conf.h"

/**
 * @brief LED-PC13口，测试
 * @param  None
 * @retval None
 */
void test(void)
{
    uint8_t i;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    GPIO_InitTypeDef gpio_init;
    gpio_init.GPIO_Pin      = GPIO_Pin_13;
    gpio_init.GPIO_Speed    = GPIO_Speed_50MHz;
    gpio_init.GPIO_Mode     = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &gpio_init);
    
    for (i = 0; i < 9; i++)
    {
        pcout(13) = 0;
		delay_ms(1000);
        pcout(13) = 1;
		delay_ms(1000);
    }
    
}

int main(void)
{
    test();
    
	while (1) 
	{
	
	}
}




