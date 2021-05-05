#include "oled.h"



void gpio_init(void)
{
    GPIO_InitTypeDef gpio_conf;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //开启GPIOA时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  //开启GPIOA复用功能

    gpio_conf.GPIO_Pin      = SPI1_SCLK | SPIM_MOSI;
    gpio_conf.GPIO_Mode     = GPIO_Mode_AF_PP;  
    gpio_conf.GPIO_Speed    = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpio_conf);

    gpio_conf.GPIO_Pin      = SPI1_MISO;
    gpio_conf.GPIO_Mode     = GPIO_Mode_IN_FLOATING; 
    gpio_conf.GPIO_Speed    = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpio_conf);

    GPIO_SetBits(GPIOA, SPI1_SCLK | SPI1_MISO | SPI1_MOSI);
}



void spi1_init(void)
{
    SPI_InitTypeDef  spi_conf;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE); //开启SPI1时钟
        
    spi_conf.SPI_Direction         = SPI_Direction_2Lines_FullDuplex;//SPI设置为双线双向全双工
    spi_conf.SPI_Mode              = SPI_Mode_Master;//设置为主SPI
    spi_conf.SPI_DataSize          = SPI_DataSize_8b;//SPI发送接收8位帧结构
    spi_conf.SPI_CPOL              = SPI_CPOL_Low;//选择了串行时钟的稳态:空闲时钟低
    spi_conf.SPI_CPHA              = SPI_CPHA_1Edge;//数据捕获(采样)于第1个时钟沿
    spi_conf.SPI_NSS               = SPI_NSS_Soft;//SPI_NSS_Soft;
    spi_conf.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;//波特率预分频值为256
    spi_conf.SPI_FirstBit          = SPI_FirstBit_MSB;//数据传输从MSB位开始
    spi_conf.SPI_CRCPolynomial     = 7;//CRC值计算的多项式
    SPI_Init(SPI1, &spi_conf);         
    SPI_Cmd(SPI1, ENABLE);

} 


void spi1_send_byte(uint8_t spi_byte)
{		
    uint8_t time = 0;
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET)
    {
        time++;
        if (time > 200)
        {
            return false;
        }
	}
		  
    SPI_I2S_SendData(SPI1, spi_byte); 
    
    time = 0;
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET)
    {
        time++;
        if(time > 200)
        {
	        return false;
        }
    }
}



/*
 * 功能说明:    0.96OLED操作
 * 函数参数:    mod模式（数据&命令）， 要操作的数据
 */
static void oled_write_operate(uint8_t mode, uint8_t dat)
{
    OLED_CS_LOW;

    if (mode)//写入数据OLED_DATA = 1
        OLED_DC_HIGH;
    else     //写入命令OLED_COMM = 0
        OLED_DC_LOW;

    spi1_send_byte(dat);
    
    OLED_CS_HIGH;
}


/*
 * 功能说明:    0.96OLED设置坐标
 * 函数参数:    x:横坐标; y：纵坐标
 */
void oled_set_pos(uint8_t x, uint8_t y)
{
    oled_write_operate(OLED_COMM, 0xb0 + y);                    //设置页(page)地址
    oled_write_operate(OLED_COMM, ((x & 0xf0) >> 4) | 0x10);    //列高四位地址
    oled_write_operate(OLED_COMM, (x & 0x0f) | 0x01);           //列低四位地址
}




void oled_on(void)
{
    oled_write_operate(OLED_COMM, 0x8d);    //打开DCDC
    oled_write_operate(OLED_COMM, 0x14);    //打开DCDC
    oled_write_operate(OLED_COMM, 0xaf);    //打开OLED
}


void oled_off(void)
{
    oled_write_operate(OLED_COMM, 0x8d);    //设置DCDC
    oled_write_operate(OLED_COMM, 0x10);    //关闭DCDC
    oled_write_operate(OLED_COMM, 0xae);    //关闭OLED
}



void oled_dis_clear(void)
{
    uint8_t page = 0;
    uint8_t i = 0;
	
    for (page = 0; page < 8; page++)
    {
        oled_write_operate(OLED_COMM, 0xb0 + page); //设置页地址(0--7)
        oled_write_operate(OLED_COMM, 0x00);        //设置显示位置—列低地址
        oled_write_operate(OLED_COMM, 0x10);        //设置显示位置—列高地址

        for(i = 0; i < 128; i++)
        {
            oled_write_operate(OLED_DATA, 0x00);    //0x00清屏
        }
    }
}



void oled_dis_full(void)
{
    uint8_t page = 0;
    uint8_t i = 0;
	
    for (page = 0; page < 8; page++)
    {
        oled_write_operate(OLED_COMM, 0xb0 + page); //设置页地址(0--7)
        oled_write_operate(OLED_COMM, 0x00);        //设置显示位置—列低地址
        oled_write_operate(OLED_COMM, 0x10);        //设置显示位置—列高地址

        for(i = 0; i < 128; i++)
        {
            oled_write_operate(OLED_DATA, 0xff);    
        }
    }
}


void oled_dis_one_char(uint8_t x, uint8_t y, uint8_t str)
{
    uint8_t i = 0;
    uint8_t ret = 0;
	
    //ret = str -32;
    ret = str - ' ';            //得到偏移后的值,对ASCLL码进行一个减法.即在二维数组里找它的位置  
	
    if (x > (MAX_COLUMN - 1))   //列超过最大,更换到下一行
    {
        x = 0;
        if (SIZE == 8 )
        {
            y = y + 1;          //针对8号的字符
        }
        if (SIZE == 16 )
        {
            y = y + 2;          //针对16号的字符
        }
    }
    
    
    if (SIZE == 16 )
    {
        //16的字体分成两部分写入 ->1
        oled_set_pos(x, y);
        for (i = 0; i < 8; i++)
        {
            oled_write_operate(OLED_DATA, F8X16[ret*16+i]);
        }
        
        //16的字体分成两部分写入 ->2
        oled_set_pos(x, y + 1);
        for	(i = 0; i < 8; i++)
        {
            oled_write_operate(OLED_DATA, F8X16[ret*16+i+8]);
        }
    }
    else 
    {
        oled_set_pos(x, y + 1);
        for(i = 0; i < 6; i++)
        {
            oled_write_operate(OLED_DATA, F6x8[ret][i]);
        }
    }
}



void oled_dis_str(uint8_t x, uint8_t y, uint8_t *str)
{
    uint8_t i = 0;
	
    while(str[i] != '\0')
    {
        oled_dis_one_char(x, y, str[i]);
        x += 8;
		
        if(x > 120)
        {
            x = 0;
            y += 2;
        }
        i++;
    }
}


void oled_dis_chinese(uint8_t x, uint8_t y, uint8_t no)
{
    uint8_t i = 0;
    uint8_t addr = 0;
	
    oled_set_pos(x, y);
    for (i = 0; i < 16; i++)    //数组行列寻址
    {
        oled_write_operate(OLED_DATA, TEST[2*no][i]);
        addr += 1;
    }
	
    oled_set_pos(x, y + 1);
    for (i = 0; i < 16; i++)
    {
        oled_write_operate(OLED_DATA, TEST[2*no+1][i]);
        addr += 1;
    }
	
}


void oled_dis_picture(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *bmp)
{
    uint8_t x = 0;
    uint8_t y = 0;
    uint32_t i = 0;
	
    if ((y1 % 8) == 0)
    {
        y = y1 / 8;
    }
    else
    {
        y = y1 /8 + 1;
    }
	
    for (y = y0; y < y1; y++)	    //每行(0 - 7 page)
    {
        oled_set_pos(x0, y);
		
        for (x = x0; x < x1; x++)	//0~128
        {
        oled_write_operate(OLED_DATA, bmp[i++]);
        }
    }
}



uint32_t oled_pow(uint8_t m, uint8_t n)
{
    uint32_t ret = 1;

    while(n--)
    {
        ret *= m;
    }

    return ret;
}



//num：显示数字; len：数字长度; size_num：数字大小
void oled_dis_num(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size_num)
{
    uint8_t i = 0;
    uint8_t temp = 0;
    uint8_t enshow = 0;
	
    for (i = 0; i < len; i++)
    {
        temp = (num / (oled_pow(10,len-i-1))) % 10; //把显示的数字一位一位取出来
        if((enshow == 0) && (i < (len-1)))
        {
            if(temp == 0)
            {
                oled_dis_one_char(x + (size_num / 2) * i, y, ' ');
                continue;
            }
            else
            {
                enshow = 1;
            }
        }
        oled_dis_one_char(x + (size_num / 2) * i, y, temp + '0');
    }
}







void oled_init(void)
{
    oled_gpio_init();	//oled cs/dc/rst 三个io初始化

    OLED_RST_HIGH;
    delay_ms(200);
    OLED_RST_LOW;
    delay_ms(200);
    OLED_RST_HIGH; 
	    
    oled_write_operate(OLED_COMM, 0xAE);    //关闭OLED
    oled_write_operate(OLED_COMM, 0x00);    //设置列低位地址
    oled_write_operate(OLED_COMM, 0x10);    //设置列高位地址
    oled_write_operate(OLED_COMM, 0x40);    //设置起始行地址及映射RAM显示起始行 (0x00~0x3F)
    oled_write_operate(OLED_COMM, 0x81);    //对比度设置
    oled_write_operate(OLED_COMM, 0xCF);    // Set SEG Output Current Brightness
    oled_write_operate(OLED_COMM, 0xA1);    //--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
    oled_write_operate(OLED_COMM, 0xC8);    //Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
    oled_write_operate(OLED_COMM, 0xA8);    //设置驱动路数(1 to 64)
    oled_write_operate(OLED_COMM, 0x3f);    //--1/64 duty
    oled_write_operate(OLED_COMM, 0xD3);    //-设置显示偏移(0x00~0x3F)
    oled_write_operate(OLED_COMM, 0x00);    //-not offset
    oled_write_operate(OLED_COMM, 0xd5);    //--set display clock divide ratio/oscillator frequency
    oled_write_operate(OLED_COMM, 0x80);    //--set divide ratio, Set Clock as 100 Frames/Sec
    oled_write_operate(OLED_COMM, 0xD9);    //--set pre-charge period
    oled_write_operate(OLED_COMM, 0xF1);    //Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    oled_write_operate(OLED_COMM, 0xDA);    //--set com pins hardware configuration
    oled_write_operate(OLED_COMM, 0x12);
    oled_write_operate(OLED_COMM, 0xDB);    //--set vcomh
    oled_write_operate(OLED_COMM, 0x40);    //Set VCOM Deselect Level
    oled_write_operate(OLED_COMM, 0x20);    //设置页地址模式(0x00/0x01/0x02)
    oled_write_operate(OLED_COMM, 0x02);    //
    oled_write_operate(OLED_COMM, 0x8D);    //--set Charge Pump enable/disable
    oled_write_operate(OLED_COMM, 0x14);    //--set(0x10) disable
    oled_write_operate(OLED_COMM, 0xA4);    //显示开启(显示:A4;无显示:A5)
    oled_write_operate(OLED_COMM, 0xA7);    // 背景正反向显示 (0xa6:正显;a7:反显) 
    oled_write_operate(OLED_COMM, 0xAF);    //打开显示

    oled_write_operate(OLED_COMM, 0xAF);    //display ON(on:AF;off:AE)
    oled_dis_clear();
    oled_set_pos(0, 0); 	
}  





