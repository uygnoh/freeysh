//GND  电源地
//VCC  接3.3v电源
//D0   接PA5  (SPI1_SCK===>LCD_SCK)   串行时钟线
//D1   接PA7  (SPI1_MOSI===>LCD_MOSI) 串行数据线
//RES  接PB0   硬复位 OLED
//DC   接PG15  命令/数据标志（写0—命令/写1—数据）；
//CS   接PA4   OLED片选信号



#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "config.h"



int main(void)
{
  oled_init();
  while(1)
  {
    oled_clear();
    delay_ms(500);
    oled_full();
    delay_ms(500);
  }
}



