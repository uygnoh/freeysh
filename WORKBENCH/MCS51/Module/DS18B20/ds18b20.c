#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

/* 定义数码管位段 */
sbit wei0=p1^0
sbit wei1=p1^1
sbit wei2=p1^2
sbit wei3=p1^3

uchar th = 20, tl = 13;
sbit beep = P1^7;
/* 共阳极数码管编码表 */
uchar code table[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
			0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

/* 共阴极数码管编码表 */
/**
uchar code table[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
			0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

***/





DQ=P1^6;		//ds18b20温度总线(1-wire)
uint temp_value;	//ds18b20温度值
bit temp_flag;		//ds18b20置温度标志位

TH = 20;		//高温报警
TL = 13;		//低温报警

void lcd1602_init(void)
{
	lcd1602_write_cmd(0x38);
	lcd1602_write_cmd(0x0C);
	lcd1602_write_cmd(0x06);
	lcd1602_write_cmd(0x01);
	
	lcd1602_write_cmd(0x80);
	lcd1602_write_string("TH")
	lcd1602_write_cmd(0x80+8);
	lcd1602_write_string("TL")
}
void write_TH(uchar th)
{
	uchar a, b;
	a = th/10;
	b = th%10;
	lcd1602_write_cmd(0x80+3);
	lcd1602_write_dat(0x30+a);
	lcd1602_write_dat(0x30+b);
}
void write_TL(uchar tl)
{
	uchar a, b;
	a = tl/10;
	b = tl%10;
	lcd1602_write_cmd(0x80+11);
	lcd1602_write_dat(0x30+a);
	lcd1602_write_dat(0x30+b);
}



----------------------------------------------------------

void main(void)
{
	while (1)
	{
		if ((temp_value/10) >= th || (temp_value/10) < tl)
			beep = 0;
		else
			beep = 1;	
	}
	return 0;
}



/** DS18B20芯片复位
  *
  */
void ds18b20_reset()
{
	DQ = 1;
	delayms(5);	/* 增加抗干扰 */

	DQ = 0;		/* 拉低总线 */
	delay_us(400);	/* 延时400us */
	DQ = 1;		/* 释放总线 */
	delay_us(50);	/* 延时50us */
}

/** DS18B20读一个字节
  * 串行通信，一次传一位
  * 低位在前，高位在后
  */
uchar ds18b20_read()
{
	uchar number = 0;
	uchar dat = 0;		/* 用dat把读出的数据存储起来 */
	for (number = 0; number < 8; number++)
	{
		DQ = 0;		/* 主机拉低总线 */
		dat >>= 1;	/* dat不但右移，还起到延时1US */
		DQ = 1;		/* 释放总线 */
		if (DQ == 1)	/* 判断 DQ */
		{
			dat |= 0x80;
		}
		delay_us(15);  /* 在15us内判断数据线上是0还是1 */
	}
	return(dat);
}

/** DS18B20写一个字节
  * 低位在前，高位在后
  */
void ds18b20_write_com(uchar com)
{
	uchar number;
	for(number = 0; number < 8; number++)
	{
		DQ = 0;			//主机拉低总线
		DQ = com & 0x01;
		delay_us(15);		//保持15us并采样
		DQ = 1;			//释放总线
		com >>= 1;
	}
}

/** DS18B20读取温度数据
  * 
  */
uint ds18b20_read_temp()
{
	uchar a, b;      //存储读取的温度值
	ds18b20_reset(); //复位 
	ds18b20_write_com(0xCC);//跳过ROM
	ds18b20_write_com(0x44);//发送温度转换指令
	
	ds18b20_reset(); 	//复位
	ds18b20_write_com(0xCC);//跳过ROM
	ds18b20_write_com(0xBE);//读暂存器
	
	a=ds18b20_read();	//暂存器低8位
	b=ds18b20_read();	//暂存器高8位
	
	temp_value = b;
	temp_value <<= 8;	//b中的数据放入temp_value的高8位
	temp_value |= a;	//完整的16进制温度

	/* 判断温度是正温度还是负温度 */
	if (b < 0xFF)
	{
		temp_flag = 0;
	}
	else
	{	/* 如果是负温度，它是以补码形式存放的，
		   所以要源码取反加 1.
		*/
		temp_value = ~temp_value+1;	
		temp_flag = 1;
	}
	
	
	/*把读到的值扩大10倍，便于显示(可以精确到小数点1位)
	  可以得到 4位整数。
	*/
	temp_value = temp_value*0.625;
	retrun(temp_value);
}

/** DS18B20显示温度数据
  *
  */
  
read/读		write/写	cmd/命令	data/数据


send/发送	receive/接收	byte/字节	buffer/缓冲区

  
start/开始	stop/停止	on/打开		off/关闭	begin/end

low/低的	high高的	max/最大值	min/小


display/显示	show/显示	temperature/温度	string/字符串	


address/地址	init/初始化

clear/清除	flag/标志位	status/状态	get/获得




X	横坐标

Y	纵坐标

Z	自定义

  
  
  
  
  
  
  
  
  
  
void ds18b20_display(uint temp_value)
{
	uchar qian, bai, shi, ge;
	qian = temp_value/1000;
	bai  = temp_value%1000/100;
	shi  = temp_value%100/10;
	ge   = temp_value%10;
	
	/* 4位数码管动态扫描 */
	wei0 = 0;
	P0 = table[qian];
	delay_ms(2);
	
	wei0 = 1;
	wei1 = 0;
	P0 = table[bai];
	delay_ms(2);
	
	wei1 = 1;
	wei2 = 0;
	P0 = table[shi];
	delay_ms(2);

	wei2 = 1;
	wei3 = 0;
	P0 = table[ge];
	delay_ms(2);
	wei3 = 1;
	
	
	########################################
	
	lcd1602_write_cmd(0x80+0x40+5);
	lcd1602_write_dat(0x30+qian);
	lcd1602_write_dat(0x30+bai);
	lcd1602_write_dat(0x30+shi);
	lcd1602_write_dat('.');
	lcd1602_write_dat(0x30+ge);
	lcd1602_write_dat(0xdf);
	lcd1602_write_dat('C');
	
	########################################
	
	
	
	
	
	
	

}

void delay_us(uint z)
{
	while(z--);
}

void delay_ms(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}


/******************************************************************************

DS18B20单总线工作方式

控制器对 DS18B20 操作流程：
	1. 复位，首先我们对 DS18B20 芯片进行复位，复位就是由控制器(单片机)给 DS18b20
           单总线至少 480us 的低电平信号。
           当 DS18B20接收到此复位信号后则会在 15~60us 后回发一个芯片存在脉冲。

	2. 芯片存在脉冲，在复位电平信号结束之后，控制器应该将数据单总线拉高，以便于在 15~60 us
           后接收脉冲，存在脉冲为一个 60~240 us的低电平信号。至此，通信双方已达成基本的通信协议。
	   接下来将会是控制器与 DS18B20间的数据通信。
	   如果复位的低电平的时间不足或是单总线的电路断路都不会接收到存在脉冲，在设计时要注意
           意外的情况处理。


	3. 控制器发送 ROM指令，双方打完了招呼之后就要进行数据交流了，ROM共有5条，每一个工作周期
           只能发一条， ROM指令分别是，读ROM数据，指定匹配芯片，跳过ROM，芯片搜索，报警芯片搜索
           ROM指令为 8位长度，功能是对芯片内的 64 位光刻ROM进行操作。其主要的目的是为了分辨一条
           总线上挂接的多个器件并做处理。诚然，单总线上可以挂多个器件，并通过每个器件上多独立的 ID
           号来区分，一般只挂单个 DS18B20芯片时可以跳过ROM指令(注意！此出跳过ROM指令并非不发送
           ROM指令，而是用特有的一条“跳过指令”)

	4. 控制器发送存储器操作指令，在 ROM指令发送之后给 DS18B20之后，紧接着(不间断)就是发送存储器
           操作指令了。 操作指令同样为 8位，共6条，存储器操作指令分别是，写RAM数据，读RAM数据，
           将RAM数据复制到 EEPROM，温度转换，将 EEPROM中的报警值复制到RAM，工作方式切换。
           存储器操作指令是的功能是命令 DS18B20做什么样的工作，是芯片控制的关键


	5. 执行或存储器读写，一个存储器操作指令结束后则将进行指令执行或数据读写，这个操作要是存储器操作指令二定。
           如果指令温度转换指令则控制器(单片机)必须等待 DS18b20指行其指令，一般转换时间为 500 us.
           如果执行数据读写指令则需要严格遵循 DS18B20的读写时序来操作。
*****************************************************************************************************
***/
