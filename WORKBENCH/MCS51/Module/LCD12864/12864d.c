#include <reg51.h>

#define uchar unsigned char
#define Disp_On 0x3f	//开显示
#define Diap_off 0x3e	//关显示
#define Col_Add 0x40	//列地址
#define Page_Add oxb8	//页地址
#define Start_Line 0xc0	//起始行


sbit Di=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
sbit cs1=P1^3;
sbit cs2=P1^4;
sbit RST=P1^5;

uchar code Chinese[][32]={};
uchar code English[][16]={};

// cs=1,为左屏。否则为右半屏写入命令
void write_com(uchar cs, uchar com)
{
	if (cs == 1)
	{
		cs1=1;
		cs2=0;
	}
	else
	{
		cs1=0;
		cs2=1;
	}
	Di=0;
	RW=0;
	P0=com;
	delayms(1);
	EN=1;
	delayms(1);
	EN=0;
}


void write_dat(uchar cs, uchar dat)
{
	if (cs == 1)
	{
		cs1=1;
		cs2=0;
	}
	else
	{
		cs1=0;
		cs2=1;
	}
	Di=1;
	RW=0;
	P0=dat;
	delayms(1);
	EN=1;
	delayms(1);
	EN=0;
}

void clear(uchar cs)
{
	uchar j, k;
	if (cs == 1)
	{
		cs1=1;
		cs2=0;
	}
	else
	{
		cs1=0;
		cs2=1;
	}
	write_com(cs, Page_Add+0);
	write_com(cs,Col_Add+0);
	for (k=0; k<8; k++)
	{
		write_com(cs,Page_Add+k);
		for (j=0;j<64;j++)
			write_dat(cs,0x00);
	}
	
}

void init_lcd()
{
	RST=0;
	dalayms(50);
	RST=1;
	delayms(50);
	write_com(1,Disp_Off);	write_com(2,Disp_Off);
	write_com(1,Page_Add+0); write_com(2,Page_Add+0);	
	write_com(1,Start_Line+0); write_com(2,Start_Line+0);
	write_com(1,Col_Add); write_com(2,Col_Add);
	Write_com(1,Disp_On); Write_com(2,Disp_On);
}

void Chinese_disp(ucahr cs, uchar page, uchar col, uchar n)
{
	uchar i, j;
	if (cs == 1)
	{
		cs1=1;
		cs2=0;
	}
	else
	{
		cs1=0;
		cs2=1;
	}
	for (i=0; i<2; i++)
	{
		write_com(cs,Page_Add+page+i);
		write_com(cs,Col_Add+col);
		for(j=0; j<16; j++)
			write_dat(cs,Chinese[n][16*i+j);
	}
}



void English_disp(ucahr cs, uchar page, uchar col, uchar n)
{
	uchar i, j;
	if (cs == 1)
	{
		cs1=1;
		cs2=0;
	}
	else
	{
		cs1=0;
		cs2=1;
	}
	for (i=0; i<2; i++)
	{
		write_com(cs,Page_Add+page+i);
		write_com(cs,Col_Add+col);
		for(j=0; j<8; j++)
			write_dat(cs,English[n][8*i+j);
	}
}


void main()
{
	init_lcd();
	clear(1); clear(2);
	
	Chinese_disp(1, 0, 0, 0);
	Chinese_disp(1, 0, 16, 1);
	Chinese_disp(1, 0, 32, 2);
	Chinese_disp(1, 0, 48, 3);
	
	Chinese_disp(2, 0, 0, 4);
	Chinese_disp(2, 0, 16, 5);
	Chinese_disp(2, 0, 32, 6);
	Chinese_disp(2, 0, 48, 7);
	
	
	
	English_disp(1, 6, 24, 0);
	English_disp(1, 6, 32, 1);
	English_disp(1, 6, 40, 2);
	English_disp(1, 6, 48, 3);
	English_disp(1, 6, 56, 4);
	
	
	
	English_disp(2, 6, 0, 5);
	English_disp(2, 6, 8, 6);
	English_disp(2, 6, 16, 7);
	English_disp(2, 6, 24, 8);
	English_disp(2, 6, 32, 9);
	English_disp(2, 6, 40, 10);
		
	
}








