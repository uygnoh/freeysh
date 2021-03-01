/* 
 * 0.96OLED-四线SPI1，SSD1306只支持向模块写数据不能读数据
 * Under serial mode, only write operations are allowed.
 * stm32-io     oled-io     说明
 * PA1          OLED_CS     OLED     片选信号, 0为选择
 * PA3	        OLED_DC     OLED     命令/数据标志(0写命令, 1写数据)
 * PA4	        OLED_RST    OLED     硬件复位 
 * PA5	        OLED_D0     D0(SCLK) 信号线作为串行时钟线 SPI_SCLK
 * PA7	        OLED_D1     D1(SDAT) 信号线作为串行数据线 SPI1_MOSI
 */

#define SPI1_SCLK       (GPIO_Pin_5)
#define SPI1_MISO       (GPIO_Pin_6)
#define SPI1_MOSI       (GPIO_Pin_7)

#define OLED_CS_PIN     GPIO_Pin_1      //OLED_CS
#define OLED_CS_LOW     GPIO_ResetBits(GPIOC, GPIO_Pin_1)						
#define OLED_CS_HIGH    GPIO_SetBits(GPIOC, GPIO_Pin_1)

#define OLED_DC_PIN     GPIO_Pin_3      //OLED_DC
#define OLED_DC_LOW     GPIO_ResetBits(OLED_PORT, OLED_DC_PIN)
#define OLED_DC_HIGH    GPIO_SetBits(OLED_PORT, OLED_DC_PIN)

#define OLED_RST_PIN    GPIO_Pin_4      //OLED_RST
#define OLED_RST_LOW    GPIO_ResetBits(OLED_PORT, OLED_RST_PIN)
#define OLED_RST_HIGH   GPIO_SetBits(OLED_PORT, OLED_RST_PIN)

#define MAX_COLUMN	128
#define MAX_ROW	64
#define SIZE 16 	//显示字体选择()

#define OLED_DATA	1
#define OLED_COMM	0

/* 使用外部高速晶体振荡器, 配置为72MHz */
void rcc_configure(void)
{
    RCC_DeInit();                                         /* 初始化为缺省值               */
    RCC_HSEConfig(RCC_HSE_ON);                            /* 使能外部高速时钟             */			
    while (RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);  /* 等待外部高速时钟稳定          */ 	
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); /* enable prefetch buffer     */
    FLASH_SetLatency(FLASH_Latency_2);                    /* flash 2 wait state         */
    RCC_HCLKConfig(RCC_SYSCLK_Div1);                      /* HCLK  ==  SYSCLK           */
    RCC_PCLK2Config(RCC_HCLK_Div1);                       /* PCLK2 ==  HCLK             */
    RCC_PCLK1Config(RCC_HCLK_Div2);                       /* PCLK1 ==  HCLK/2           */
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);  /* PLLCLK == 8MHz*9 ==72MHz   */
    RCC_PLLCmd(ENABLE);                                   /* enable PLLCLK              */
    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);  /* wait till  PLLCLK is ready */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);            /* select PPLL as system clock*/
    while (RCC_GetSYSCLKSource() != 0x08);                /* wait till PLL is used as system clock source */

    /* spi1_configuration */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
}


/* GPIOA端口配置 */
void spi1_gpio_init(void)
{
    GPIO_InitTypeDef gpio_conf;
    gpio_conf.GPIO_Pin      = SPIM1_CLK | SPIM1_MOSI;
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
    ret = str - ' ';//得到偏移后的值,对ASCLL码进行一个减法.即在二维数组里找它的位置  
	
    if (x > (MAX_COLUMN - 1))	//列超过最大,更换到下一行
    {
        x = 0;
        if (SIZE == 8 )
        {
            y = y + 1;//针对8号的字符
        }
        if (SIZE == 16 )
        {
            y = y + 2;//针对16号的字符
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
    for (i = 0; i < 16; i++)//数组行列寻址
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
	
    for (y = y0; y < y1; y++)	//每行(0 - 7 page)
    {
        oled_set_pos(x0, y);
		
        for (x = x0; x < x1; x++)	//0~128
        {
        oled_write_operate(OLED_DATA, bmp[i++]);
        }
    }
}


void oled_dis_num(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size_num)
{
    uint8_t i = 0;
    uint8_t temp = 0;
    uint8_t enshow = 0;
	
    for (i = 0; i < len; i++)
    {
        temp = (num / (oled_pow(10,len-i-1))) % 10;//把显示的数字一位一位取出来
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









