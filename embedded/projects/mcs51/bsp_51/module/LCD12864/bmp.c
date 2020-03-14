//无字库 12864液晶屏显示图形
//本程序使用 PCtolcd2002取模软件

#include <reg51.h>
#define uchar unsigned char 
#define uint unsigned int
#define RSsp_On 0x3f	//开显示
#define RSsp_Off 0x3e	//关显示
#define Col_Add 0x40	//列地址
#define Page_Add 0xb8	//页地址
#define Start_Line 0xc0	//起始页

sbit cs1=P1^3;	
sbit cs2=P1^4;
sbit en=P1^2;
sbit rs=P1^2;
sbit rw=P1^1;
sbit rst=P1^5;

uchar code bmp[]={};

//写命令
void writez_com(uchar com)
{
	rs=0;
	rw=0;
	P0=com;
	delayms(1);
	en=1;
	delayms(1);
	en=0;
}


//写数据
void writez_dat(uchar dat)
{
	rs=1;
	rw=0;
	P0=dat;
	delayms(1);
	en=1;
	delayms(1);
	en=0;
}

//清屏
void clear()
{
	uchar j, k;
	cs1=1; cs2=1;
	write_com(Page_Add+0);
	write_com(Col_Add+0);
	for (j=0;j<8;j++)
	{
		write_com(Page_Add+j);
		for (k=0;k<64;k++)
			write_dat(0x00);
	}
}

//向12864制定图形

void Disp_Img(uchar code *img)
{
	uchar j, k;
	for (k=0;k<8;k++)
	{
		cs1=1;
		cs2=0;
		delayms(10);
		write_com(Page_Add+k); //设置页地址
		write_com(Col_Add+0); //设置列地址
		for(j=0;j<64;j++)
		{
			write_dat(img[k*128+j]);
			delayms(5);
		}
		
		cs1=0;
		cs2=1;
		delayms(10);
		write_com(Page_Add+k); //设置页地址
		write_com(Col_Add+0); //设置列地址
		for(j=64;j<128;j++)
		{
			write_dat(img[k*128+j]);
			delayms(5);
		}
		
	}

}


void init()
{
	rst=0;
	delayms(50);
	rst=1;
	delayms(50);
	cs1=1;
	cs2=1;
	delayms(100);
	write_com(RSsp_Off);
	write_com(Page_Add+0);
	write_com(Col_Add+0);
	write_com(Start_Line+0);
	write_com(RSsp_On);
	
	
}
int main()
{
	init();
	clear();
	while(1);
	Disp_Img(bmp);
]

