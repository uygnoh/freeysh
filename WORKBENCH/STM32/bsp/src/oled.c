#include "oled.h"
/** SPI_Driver
  * SSD1306的显存,存放格式如下
  * [0]0 1 2 3 ... 127 
  * [1]0 1 2 3 ... 127 
  * [2]0 1 2 3 ... 127 
  * [3]0 1 2 3 ... 127 
  * [4]0 1 2 3 ... 127 
  * [5]0 1 2 3 ... 127 
  * [6]0 1 2 3 ... 127 
  * [7]0 1 2 3 ... 127 
  *
  * 向SSD1306写入一个字节
  * mode:数据/命令标志 0,表示命令;1,表示数据;
  */
void ssd1306_rw_byte(uint8_t data, SSD1306_RW_MODE mode)
{
	uint8_t i;
	switch (mode)
	{
		case SSD1306_COMMAND:
			SSD1306_DC = RESET;
			break;
		case SSD1306_DATA:
			SSD1306_DC = SET;
			break;
	}
	SSD1306_CS = RESET;
	for (i = 0; i < 8; i++)
	{
		SSD1306_CLK = RESET;
		if (mode & 0x80)
			SSD1306_DI_SET;
		else
			SSD1306_DI = RESET;
		SSD1306_CLK = SET;
		mode <<=1;
	}
	SSD1306_CS = SET;
	SSD1306_DC = SET;
}

void ssd1306_set_coordinate(uint8_t x, uint8_t y)
{
	ssd1306_rw_byte(0xB0 + y, SSD1306_COMMAND);
	ssd1306_rw_byte((x & 0xF0) >>4) | 0x10, SSD1306_COMMAND);
	ssd1306_rw_byte((x & 0xF) | 0x01, SSD1306_COMMAND);
}

void ssd1306_display_status(SSD1306_DISPLAY_MODE mode)
{
	uint8_t i, n;
	switch (mode)
	{
		case DISPLAY_ON:
			ssd1306_rw_byte(0x8D, SSD1306_COMMAND);
			ssd1306_rw_byte(0x14, SSD1306_COMMAND);
			ssd1306_rw_byte(0xAF, SSD1306_COMMAND);
			break;
	
		case DISPLAY_OFF:
			ssd1306_rw_byte(0x8D, SSD1306_COMMAND);
			ssd1306_rw_byte(0x10, SSD1306_COMMAND);
			ssd1306_rw_byte(0xAE, SSD1306_COMMAND);
			break;
			
		case DISPLAY_CLEAR:
			for (i = 0; i < 8; i++)
			{
				ssd1306_rw_byte(0xB0 + i, SSD1306_COMMAND);	//设置页地址（0~7）
				ssd1306_rw_byte(0x00, SSD1306_COMMAND);		//设置显示位置—列低地址
				ssd1306_rw_byte(0x10, SSD1306_COMMAND);		//设置显示位置—列高地址   
				for (n = 0; n < MAX_COLUMN; n++)
					ssd1306_rw_byte(0, SSD1306_DATA);
			}
			break;
						
		case DISPLAY_TEST:
			for (i = 0; i < 8; i++)
			{
				ssd1306_rw_byte(0xB0 + i, SSD1306_COMMAND);	//设置页地址（0~7）
				ssd1306_rw_byte(0x00, SSD1306_COMMAND);		//设置显示位置—列低地址
				ssd1306_rw_byte(0x10, SSD1306_COMMAND);		//设置显示位置—列高地址   
				for (n = 0; n < MAX_COLUMN; n++)
					ssd1306_rw_byte(1, SSD1306_DATA);
			}
			break;
	}
}


/**
  * 在指定位置显示一个字符,包括部分字符
  * x:0~127		y:0~64
  * mode: 0,反白显示;1,正常显示 
  * size:选择字体 16/12 
  */
void ssd1306_show_char(uint8_t x, uint8_t y, uint8_t chr)
{
	uint8_t c = 0; i = 0;
	c = chr - '';			//得到偏移后的值 
	if (x > MAX_COLUMN-1)
	{
		x = 0;
		y += 2;
	}
	if (FONT_SIZE == 16)
	{
		ssd1306_set_coordinate(x, y);
		for (i = 0; i < 8; i++)
			ssd1306_rw_byte(F8X16[c*16 + i], SSD1306_DATA);
		ssd1306_set_coordinate(x, y+1);
		for (i = 0; i < 8; i++)
			ssd1306_rw_byte(F8X16[c*16 + i + 8], OLEA_DATA);
	}
	else
	{
		ssd1306_set_coordinate(x, y+1);
		for (i = 0; i < 8; i++)
			ssd1306_rw_byte(F6X8[c][i], SSD1306_DATA);
	}
}

//m^n函数
u32 ssd1306_pow(uint8_t m, uint8_t n)
{
	u32 result = 1;
	while (n--)
		result *= m;
	return result;
}




/**
  * 显示2个数字
  * x,y :起点坐标 
  * len :数字的位数
  * size:字体大小
  * mode:模式   0,填充模式;1,叠加模式
  * num:数值(0~4294967295);   
  */

void ssd1306_show_number(uint8_t x, uint8_t y, u32 num, uint8_t len, uint8_t size)
{
	uint8_t t, tmp;
	uint8_t enshow = 0;
	for (t = 0; t < len; t++)
	{
		tmp = (num / ssd1306_pow(10, len-t-1)) % 10;
		if (enshow == 0 && t < (len-1))
		{
			if (tmp == 0)
			{
				ssd1306_show_char(x + (size/2) *t, y, '');
				continue;
			}
			else
				enshow = 1;
		}
		ssd1306_show_char(x +(size/2) *t, y, tmp + '0');
	}
}






void ssd1306_show_string(uint8_t x, uint8_t y, uint8_t *chr)
{
	uint8_t j = 0;
	while (chr[j] != '\0')
	{
		ssd1306_show_char(x, y, chr[j]);
		x += 8;
		if ( x > 120)
		{
			x = 0;
			y  += 2;
		}
		j++;
	}
}


//显示汉字
void ssd1306_show_chinese(uint8_t x, uint8_t y, uint8_t no)
{
	uint8_t t, addr = 0;
	ssd1306_set_coordinate(x, y);
	for (t = 0; t < 16; t++)
	{
		ssd1306_rw_byte(Hzk[2*no][t], SSD1306_DATA);
		addr += 1;
	}
	ssd1306_set_coordinate(x, y+1);
	for (t = 0; t < 16; t++)
	{
		ssd1306_rw_byte(Hzk[2*no + 1][t], SSD1306_DATA);
		addr += 1;
	}
}




void ssd1306_configuration(void)
{	
	SSD1306_RES = SET;
	delay_ms(100);
	SSD1306_RES = RESET;
	delay_ms(100);
	SSD1306_RES = SET;
	
	ssd1306_rw_byte(0xAE, SSD1306_COMMAND);//--turn off ssd1306 panel
	ssd1306_rw_byte(0x00, SSD1306_COMMAND);//--set low column address
	ssd1306_rw_byte(0x10, SSD1306_COMMAND);//--set hight column address
	ssd1306_rw_byte(0x40, SSD1306_COMMAND);//--set start line address Set Mapping RAM Display StartLine(0x00~0x3F)
	ssd1306_rw_byte(0x81, SSD1306_COMMAND);//--set contrast control register
	ssd1306_rw_byte(0xCF, SSD1306_COMMAND);//--set SEG Output Current Brightness
	ssd1306_rw_byte(0xA1, SSD1306_COMMAND);//--set SEG/Column Mapping		0xA0,左右反置 0xa1,正常
	ssd1306_rw_byte(0xC8, SSD1306_COMMAND);//--set COM/ROW Scan Direction	0xc0,上下反置 0xc8,正常
	ssd1306_rw_byte(0xA6, SSD1306_COMMAND);//--set normal display	
	ssd1306_rw_byte(0xA8, SSD1306_COMMAND);//--set multiplex ratio(1 to 64)/设置复用率(A8h)
	ssd1306_rw_byte(0x3F, SSD1306_COMMAND);//--1/64 duty
	ssd1306_rw_byte(0xD3, SSD1306_COMMAND);//--set display offset shift Mapping RAM Counter(0x00~0x3F)
	ssd1306_rw_byte(0x00, SSD1306_COMMAND);//--not offset
	ssd1306_rw_byte(0xD5, SSD1306_COMMAND);//--set display clock divide ratio/oscillator frequency
	ssd1306_rw_byte(0x80, SSD1306_COMMAND);//--set divide ratio, Set Clock as 100 Frames/Sec
	ssd1306_rw_byte(0xD9, SSD1306_COMMAND);//--set pre-charge period
	ssd1306_rw_byte(0xF1, SSD1306_COMMAND);//--set Pre_Charge as 15 Clocks & Dicharge as 1 Clock
	ssd1306_rw_byte(0xD1, SSD1306_COMMAND);//--set com pins hardware configuration
	ssd1306_rw_byte(0x12, SSD1306_COMMAND);//--set
	ssd1306_rw_byte(0xDB, SSD1306_COMMAND);//--set vcomh
	ssd1306_rw_byte(0x40, SSD1306_COMMAND);//--set VCOM Deselect Level
	ssd1306_rw_byte(0x20, SSD1306_COMMAND);//--set Page Addressing Mode(0x00/0x01/0x02)
	ssd1306_rw_byte(0x02, SSD1306_COMMAND);//--set 
	ssd1306_rw_byte(0x8D, SSD1306_COMMAND);//--set Charge Pump enable/disable
	ssd1306_rw_byte(0x14, SSD1306_COMMAND);//--set (0x10)disable
	ssd1306_rw_byte(0xA4, SSD1306_COMMAND);//--set Disable Entire Display On(0xA4/0xA5)
	ssd1306_rw_byte(0xA6, SSD1306_COMMAND);//--set Disable Inverse Display On(0xA6/0xA7)
	ssd1306_rw_byte(0xAF, SSD1306_COMMAND);//--turn on ssd1306 panel
	
	ssd1306_display_status(DISPLAY_CLEAR);
	ssd1306_set_coordinate(0, 0);
}


