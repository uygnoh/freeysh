/******************************************************************************
  * 1. 128*64 OLED_0.96 IIC总线通信方式
  * 2. 长128个点，宽64个点
  * 3. 英文和数字最小可用 8x8像素，但屏幕小看不清楚，所以通常使用 8x16像素
  * 4. 汉字最小显示单位是 16x16像素
  * 5. 将 128x64像素划分为：8x8的小区块，共 16x8个区块。
  */
  
  
#define OLED096_ADD	0x78	//OLED的IIC地址
#define COM		0x00	//OLED指令
#define DAT		0x40	//OLED数据


void oled096_init(void);	//OLED屏幕初始化
void oled096_display_on(void);	//OLED屏幕打开
void oled096_display_off(void);	//OLED屏幕关闭
void oled096_display_light(u8 x);	//OLED屏幕亮度设置(0~255)
void oled096_display_clear(void);	//OLED清屏操作
void oled096_display_8x16(u8 x, u8 y, u16 w);		//显示 8x16 单个字符
void oled096_display_8x16_buffer(u8 row, u8 *str);	//显示 8x16 字符串
  



  
void oled096_init(void)
{
	oled096_display_off();
	oled096_display_clear();
	oled096_display_on(); 
}  


/* OLED屏幕初始化设置并开显示 */  
void oled096_display_on(void) 
{
	u8 buf[28] = {
	0xae,		//0xae关显示，0xaf开显示
	0x00, 0x10,	//开始地址，双字节
	
	0xd5, 0x80,	//显示时钟频率？
	0xa8, 0x3f,	//复用率？
	0xd3, 0x00,	//显示偏移？
	0xB0,		//写入页位置(0xB0~0xB7)
	0x40,		//显示开始线
	0x8d, 0x14,	//VCC电源
	0xa1,		//设置段重映射？
	0xc8,		//COM输出方式？
	0xda, 0x12,	//COM输出方式？
	0x81, 0xff,	//对比度， 指令：0x81, 数据：0~255(255最高)
	0xd9, 0xf1,	//充电周期?
	0xdb, 0x30,	//VCC电压输出
	0x20, 0x00,	//水平寻址设置
	0xa4,		//0xa4,正常显示。0xa5,整体点亮
	0xa6,		//0xa6,正常显示。0xa7,反色显示
	0xaf		//0xae:关显示    0xaf:开显示
	};
	
	i2c_send_buffer(OLED096_ADD, COM, buf, 28);
} 


void oled096_display_off(void)
{
	u8 buf[3] = {
	0xae,		//关闭显示
	0x8d, 0x10	//关闭VCC电源
	};
	i2c_send_buffer(OLED096_ADD, COM, buf, 3);
}

/* OLED096 清屏操作 */
void oled096_display_clear(void)
{
	u8 j, t;
	for (t = 0xB0; t < 0xB8; t++)	//设置起始页地址
	{
		i2c_send_byte(OLED096_ADD, COM, t);	//页地址(0xB0~0xB7)
		i2c_send_byte(OLED096_ADD, COM, 0x10);	//起始页地址高4位
		i2c_send_byte(OLED096_ADD, COM, 0x00);	//起始页地址低4位
		for (j = 0; j < 132; j++)		//整页内容填充
			i2c_send_byte(OLED096_ADD, DAT, 0x00);
	}
}


void oled096_display_light(u8 x)  
{
	i2c_send_byte(OLED096_ADD, COM, 0x81);
	i2c_send_byte(OLED096_ADD, COM, x);	//x:亮度值设定： 0~255
}


/******************************************************************************
  * 1. 显示英文与数字 8x16 ASCII码
  * 2. 取模大小为 8*16, 取模方式为 "从左到右，从上到下，" "纵向8点，下高位"
  * 3. 
  */
void oled096_display_8x16(u8 x,		//显示英文或数字的页坐标(从0到7)
			  u8 y, 	//显示英文或数字的列坐标(从0到127)
			  u16 w		//要显示英文或数字的编号
			  )
{
	u8 j, t, c=0;
	y = y+2;	//因为OLED屏幕的内置驱动芯片是从 0x02列作为屏幕上最左一列的，所以要加上偏移量
	for (t = 0; t < 2; t++)
	{
		i2c_send_byte(OLED096_ADD, COM, 0xB0+x);	//页地址(0xB0~0xB7)
		i2c_send_byte(OLED096_ADD, COM, y/16+0x10);	//起始列地址的高4位
		i2c_send_byte(OLED096_ADD, COM, y%16);		//起始列地址的低4位
		for (j = 0; j < 8; j++)
		{
			i2c_send_byte(OLED096_ADD, DAT, ASCII_8x16[(w*16)+c-512]); //为了和ASCII码表对应
			c++;
		}
		x++;	//页地址加1
	}
}

//向OLED发送一个字符串，长度位 64给字符之内
//
void oled096_display_8x16_buffer(u8 row, u8 *str)
{
	u8 r = 0;
	while(*str != '\0')
	{
		oled096_display_8x16(row, r*8, *str++);
		r++;
	}
}  
int main(void)
{
	u8 buffer[3];
	delay_ms(100);		//上电等待其他器件就绪
	rcc_configure();	//系统时钟初始化
	iic_configure();	//IIC初始化
	ds18b20_get_temp(buffer);//读取ds18b20的数据

	oled096_init();				//OLED初始化
	oled096_display_8x16_buffer(0, "freeysh");	//显示字符串
	oled096_didplay_8x16_buffer(6, " Temp: ");	//显示字符串
  	
  	while (1)
  	{
  		ds18b20_get_temp(buffer);	//读取ds18b20的数据
  		if (buffer[0])			//如果第一组为1即为负温度
  			oled096_display_8x16(6, 7*8, '-');
  		oled096_didplay_8x16(6, 8*8, buffer[1]/10+0x30);	//显示十位温度值
  		oled096_didplay_8x16(6, 9*8, buffer[1]%10+0x30);	//显示个位温度值
  		oled096_didplay_8x16(6, 10*8, '.');
  		oled096_didplay_8x16(6, 11*8, buffer[2]/10+0x30);
  		oled096_didplay_8x16(6, 12*8, buffer[2]%10+0x30);
  		oled096_didplay_8x16(6, 13*8, 'C');
  		
  		delay_ms(200);
  	}
}
  
  
  
  

