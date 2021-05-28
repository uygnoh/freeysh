#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

/* 定义数码管位段 */
sbit WEI0=p1^0
sbit WEI1=p1^1
sbit WEI2=p1^2
sbit WEI3=p1^3
sbit beep = P1^7;

DQ = P1^6;		//ds18b20温度总线(1-wire)


uint temp_value;	//ds18b20温度值
bit temp_flag;		//ds18b20置温度标志位

uchar TH = 20;		//高温报警
uchar TL = 13;		//低温报警
/* 共阳极数码管编码表 */
uchar code table[] = { 0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
                       0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e };
/* 共阴极数码管编码表 
uchar code table[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                       0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71 };
*/







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



/* 
 * DS18B20芯片复位
 */
void ds18b20_reset()
{
    DQ = 1;
    delayms(5);     /* 增加抗干扰 */
    DQ = 0;         /* 拉低总线 */
    delay_us(400);  /* 延时400us */
    DQ = 1;         /* 释放总线 */
    delay_us(50);   /* 延时50us */
}


/* DS18B20读一个字节
 * 串行通信，一次传一位
 * 低位在前，高位在后
 */
uchar ds18b20_read()
{
    uchar number = 0;
    uchar dat = 0;      /* 用dat把读出的数据存储起来 */
    for (number = 0; number < 8; number++)
    {
        DQ = 0;         /* 主机拉低总线 */
        dat >>= 1;      /* dat不但右移，还起到延时1US */
        DQ = 1;         /* 释放总线 */
        if (DQ == 1)    /* 判断 DQ */
        {
            dat |= 0x80;
        }
        delay_us(15);   /* 在15us内判断数据线上是0还是1 */
    }
    return(dat);
}

/* DS18B20写一个字节
 * 低位在前，高位在后
 */
void ds18b20_write_com(uchar com)
{
    uchar number;
    for(number = 0; number < 8; number++)
    {
        DQ = 0;         /* 主机拉低总线 */
        DQ = com & 0x01;
        delay_us(15);   /* 保持15us并采样 */
        DQ = 1;         /* 释放总线 */
        com >>= 1;
    }
}


/** DS18B20读取温度数据
  * 
  */
uint ds18b20_read_temp()
{
	uchar a, b;              //存储读取的温度值
	ds18b20_reset();         //复位 
	ds18b20_write_com(0xCC); //跳过ROM
	ds18b20_write_com(0x44); //发送温度转换指令
	
	ds18b20_reset();         //复位
	ds18b20_write_com(0xCC); //跳过ROM
	ds18b20_write_com(0xBE); //读暂存器
	
	a = ds18b20_read();      //暂存器低8位
	b = ds18b20_read();      //暂存器高8位
	
	temp_value = b;
	temp_value <<= 8;        //b中的数据放入temp_value的高8位
	temp_value |= a;         //完整的16进制温度

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
void ds18b20_display(uint temp_value)
{
	uchar qian, bai, shi, ge;
	qian = temp_value/1000;
	bai  = temp_value%1000/100;
	shi  = temp_value%100/10;
	ge   = temp_value%10;
	
	/* 4位数码管动态扫描 */
	WEI0 = 0;
	P0 = table[qian];
	delay_ms(2);
	
	WEI0 = 1;
	WEI1 = 0;
	P0 = table[bai];
	delay_ms(2);
	
	WEI1 = 1;
	WEI2 = 0;
	P0 = table[shi];
	delay_ms(2);

	WEI2 = 1;
	WEI3 = 0;
	P0 = table[ge];
	delay_ms(2);
	WEI3 = 1;
	
	lcd1602_write_cmd(0x80+0x40+5);
	lcd1602_write_dat(0x30+qian);
	lcd1602_write_dat(0x30+bai);
	lcd1602_write_dat(0x30+shi);
	lcd1602_write_dat('.');
	lcd1602_write_dat(0x30+ge);
	lcd1602_write_dat(0xdf);
	lcd1602_write_dat('C');
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


