/***
	LCD1602共16个引脚
	VCC	电源正 VDD
	GND	电源地 VSS
	VL	液晶显示偏压信号，调节对比度
	BL+	背光源正极 [BLA]
	BL-	背光源负极 [BLk]

	RS	数据/命令选择端(H/L)
	RW	读 / 写 选择端(H/L)
	EN	使能信号
	D1,D2,D3,D4,D5,D6,D7,D8,数据端口 [8个引脚接P0端口]
	
	注意： LCD1602共可以显示 2行，第一行起始地址为：0x80,
					第二行起始地址为：0x80+0x40.

***/





#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
 
sbit RS=P2^6;
sbit RW=P2^5;
sbit EN=P2^7;

void lcd1602_write_string(void)
{
	
}

int main(void)
{
	lcd1602_init();
	lcd1602_write_cmd(0x80);	//给出地址指针，第一行的第1个字符位
	lcd1602_write_dat('y');		//写入数据
	lcd1602_write_cmd(0x80+5);	//给出地址指针,第一行第6个字符位
	lcd1602_write_dat('0');		//显示0
	lcd1602_write_dat(0x30);	//显示0
	
	lcd1602_write_cmd(0x80+0x40);	//给出地址指针，第二行的第1个字符
	lcd1602_write_dat(0x38);	//显示数字 8
}
void lcd1602_write_cmd(uchar cmd)
{   
    RS = 0;		//RS为低电平表示要写入的是 命令
    RW = 0;		//RW为低电平表示是 写信号
    EN = 0;		//EN为使能信号，开始为低电平
    P0 = cmd;		//先送人数据
    delay_ms(2);	//稍作延时，等待数据稳定
    EN = 1;		//然后在把使能信号拉高，数据开始写入 LCD1602中
    delayms(5);		//稍作延时，等待数据写入完成
    EN = 0;		//之后再把使能信号拉低
    delayms(2);		//稍作延时
}
 
void lcd1602_write_dat(uchar dat)
{   
    RS = 1;		//RS为低高电平表示要写入的是 数据
    RW = 0;
    EN = 0;
    P0 = dat;
    delay_ms(2);
    EN = 1;
    delay_ms(5);
    EN = 0;
    delay_ms(2);
}

/* LCD1602 初始化函数 */
void lcd1602_init(void)
{
    lcd1602_write_cmd(0x38);	//不检测忙信号
    delay_ms(5);
    lcd1602_write_cmd(0x0f);	//光标显示[0x0E,光标不闪][0x0C，光标不显示]
    delay_ms(5);
    lcd1602_write_cmd(0x0c);	//显示开及光标设置
    delay_ms(5);
    lcd1602_write_cmd(0x06);	//显示光标移动设置(地址指针自动加1)
    delay_ms(5);
    lcd1602_write_cmd(0x01);	//显示清屏
    delay_ms(5);
    
}
 
void delay_ms(uint z)
{
    uint x,y;
    for(x=z;x>0;x--)
        for(y=110;y>0;y--);
}

