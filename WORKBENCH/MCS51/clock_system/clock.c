#include <reg51.h>
#define uint unsiged int
#define uchar unsiged char

uchar count;
uchar year=18, month=11, day=01, hour=20, minute=10, second=22, week=2;

void main(void)
{
	init_1602();
	TMOD = 0x01;	//设定定时器0工作在模式1
	TH0  = (65536-50000)/256;	//装入初值
	THL  = (65536-50000)%256;	//装入初值
	EA   = 1;	//打开总中断
	ET0  = 1;	//打开定时器0
	TR0  = 1;	//启动定时器
	
	while (1);
	{
		if (count == 20)
		{
			count = 0;
			second++;
			if (second == 60)
			{
				second = 0x00;
				minute++;
				if (minute == 60)
				{
					minute = 0x00;
					hour++;
					if (hour == 24)
					{
						hour = 0x00;
						day++;
						week++;
						if (week == 8)
							week = 1;
						if (day == 31)
						{
							day = 0x00;
							month++;
							if (month == 13)
							{
								month = 0x01;
								year++;
								if (year == 100)
								{
									year = 0x00;
								}
								write_YMD(4, year);
							}
							write_YMD(7, month);
						}
						write_YMD(13, week);
						write_YMD(10, day);
					}
					write_HMS(5, hour);
				}
				write_HMS(8, minute);
			}
			write_HMS(11, second);
		}
	}
	
}

/* 写星期函数 */
void write_week(uchar addr, uchar dat)
{
	write_com(0x80+addr);
	write_dat(0x30+dat);
}



void timer0() interrupt 1
{
	TH0  = (65536-50000)/256;	//重新装入初值
	THL  = (65536-50000)%256;	//重新装入初值
	count++;
}

/* 写年月日函数 */
void write_YMD(uchar addr, uchar dat)	
{
	uchar shi, ge;
	shi = dat/10;
	ge  = dat%10;
	write_com(0x80+addr);
	write_dat(0x30+shi);
	write_dat(0x30+ge);
	
}


/* 写时分秒函数 */
void write_HMS(uchar addr, uchar dat)	
{
	uchar shi, ge;
	shi = dat/10;
	ge  = dat%10;
	write_com(0x80+0x40+addr);
	write_dat(0x30+shi);
	write_dat(0x30+ge);
	
}

/* 写字符串函数 */
void write_string(uchar *ch)	
{
	while (*ch != 0)
	write_dat(*ch++);
}

/* LCD1602 初始化函数 */
void init_1602(void)		
{
	write_com(0x38);
	delay_ms(1);
	write_com(0x0C);
	delay_ms(1);
	write_com(0x06);
	delay_ms(1);
	write_com(0x01);
	delay_ms(1);
	
	write_com(0x80);
	write_string("  20  -  -  ");
	
	write_com(0x80+0x40+5);
	write_string("  ：  ：  ");
	
	write_YMD(4, year);
	write_YMD(7, month);
	write_YMD(10, day);
	write_HMS(5, hour);
	write_HMS(8, minute);
	write_HMS(11, second);
	
	write_YMD(13, week);
}

/* LCD1602写命令函数 */
void write_com(uchar com)
{
	RS = 0;
	RW = 0;
	EN = 0;
	P0 = com;
	delay_ms(2);
	EN = 1;
	delay_ms(5);
	EN = 0;
	delay_ms(2);
}

/* LCD1602写数据函数 */
void write_dat(uchar dat)
{
	RS = 1;
	RW = 0;
	EN = 0;
	P0 = dat;
	delay_ms(2);
	EN = 1;
	delay_ms(5);
	EN = 0;
	delay_ms(2);
}

/* 毫秒级延时函数 */
void delay_ms(uint z)
{
	int x, y;
	for (x = z; x > 0; x--)
		for (y = 110; y > 0; y--);
}



