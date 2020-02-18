#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
//---DS1302写入和读取时分秒的地址命令---//
//---秒分时日月周年 最低位读写位;-------//
uchar code read_rtc_address[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; 
uchar code write_rtc_address[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};
 
 
//---DS1302时钟初始化2013年1月1日星期二12点00分00秒。---//
//---存储顺序是秒分时日月周年,存储格式是用BCD码---//
uchar ds1302_time[7] = {0, 0, 0x12, 0x01, 0x01, 0x02, 0x13};
 
uchar code table[]={ //共阴数码管编码表
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c, 
0x39,0x5e,0x79,0x71};
 
void delayms(uint z);
void write_com(uchar com);
void write_dat(uchar dat);
void lcd1602_display();
void lcd1602_init();
void ds1302_write(uchar address, uchar dat);
uchar ds1302_read(uchar address);
void ds1302_init();
sbit SCLK=P3^6;
sbit CE=P3^5;
sbit DSIO=P3^4;
sbit RS=P2^6;
sbit RW=P2^5;
sbit EN=P2^7;
 
/************************************************
* 函 数 名         : ds1302_write
* 函数功能         : 向ds1302命令（地址+数据）
* 输    入         : address,dat
* 输    出         : 无
************************************************/
void ds1302_write(uchar address, uchar dat)
{
    uchar number;
    CE=0;
    _nop_();
    _nop_();
    SCLK = 0;
    _nop_();
    _nop_();
 
    CE=1;
    _nop_();
    _nop_();
    for(number=0;number<8;number++)//开始传送八位地址命令
    {
        DSIO=address&0x01;//数据从低位开始传送
        dat>>=1;
        _nop_();
        _nop_();
        SCLK=1;//数据在上升沿时，DS1302读取数据
        _nop_();
        _nop_();
        SCLK=0;
        _nop_();
        _nop_();
    }
    for(number=0;number<8;number++)//写入8位数据
    {
        DSIO=dat&0x01;//数据从低位开始写入
        dat>>=1;
         
        SCLK=1;//数据在上升沿时，DS1302读取数据
        _nop_();
        _nop_();
        SCLK=0;
        _nop_();
        _nop_();
    }
 
    CE=0;//传送数据结束
 
 
}
/*******************************************
* 函 数 名         : ds1302_read
* 函数功能         : 读取一个地址的数据
* 输    入         : address
* 输    出         : dat
********************************************/
uchar ds1302_read(uchar address)
{
    uchar number,dat,dat1;
    CE=0;
    _nop_();
    _nop_();
    SCLK = 0;
    _nop_();
    _nop_();
 
    CE=1;
    _nop_();
    _nop_();
     
    for(number=0;number<8;number++)//开始传送八位地址命令
    {
        DSIO=address&0x01;//数据从低位开始传送
        address >>= 1;
        SCLK=1;//数据在上升沿时，DS1302读取数据
        _nop_();
        _nop_();
        SCLK=0; //DS1302下降沿时，放置数据
        _nop_();
        _nop_();
    }
    for(number=0;number<8;number++)
    {
        dat1=DSIO;
        dat = (dat>>1) | (dat1<<7);
        SCLK=1;
        _nop_();
        _nop_();
        SCLK=0;
        _nop_();
        _nop_();
    }
    CE=0;
    _nop_();    
    _nop_();    
 
    return dat;
}
/******************************************
* 函 数 名         : ds1302_init
* 函数功能         : 初始化ds1302.
* 输    入         : 无
* 输    出         : 无
*******************************************/
void ds1302_init()
{
    uchar number;
 
    ds1302_write(0x8E,0x00);//禁止写保护，就是关闭写保护功能
    for(number=0;number<8;number++)
    {
        ds1302_write(write_rtc_address[number],ds1302_time[number]);    
    }
    ds1302_write(0x8E,0x80); //打开写保护功能
}
void ds1302_read_ds1302_time()
{
    uchar number;
    for (number=0; number<7; number++)//读取7个字节的时钟信号：分秒时日月周年
    {
        ds1302_time[number] = ds1302_read(read_rtc_address[number]);
    }
         
}
 
void write_com(uchar com)//lcd1602写命令
{   
    RS=0;
    RW=0;
    EN=0;
    P0=com;
    delayms(1);
    EN=1;
    delayms(1);
    EN=0;
    delayms(1);
     
 
}
void write_dat(uchar dat)//lcd1602写数据
{   
    RS=1;
    RW=0;
    EN=0;
    P0=dat;
    delayms(1);
    EN=1;
    delayms(1);
    EN=0;
    delayms(1);
}
void lcd1602_init()
{
    write_com(0x38);
    write_com(0x0c);
    write_com(0x06);
    write_com(0x01);
    write_com(0x80+40);
 
 
 
}
void lcd1602_display()
{
    write_com(0x80+0X40);
    write_dat('0'+ds1302_time[2]/16);               //时
    write_dat('0'+(ds1302_time[2]&0x0f));                
    write_dat('-');
    write_dat('0'+ds1302_time[1]/16);               //分
    write_dat('0'+(ds1302_time[1]&0x0f));   
    write_dat('-');
    write_dat('0'+ds1302_time[0]/16);               //秒
    write_dat('0'+(ds1302_time[0]&0x0f));
 
    write_com(0x80);
    write_dat('2');
    write_dat('0');
    write_dat('0'+ds1302_time[6]/16);           //年
    write_dat('0'+(ds1302_time[6]&0x0f));
    write_dat('-');
    write_dat('0'+ds1302_time[4]/16);           //月
    write_dat('0'+(ds1302_time[4]&0x0f));
    write_dat('-');
    write_dat('0'+ds1302_time[3]/16);           //日
    write_dat('0'+(ds1302_time[3]&0x0f));
    write_com(0x8D);
    write_dat('0'+(ds1302_time[5]&0x07));   //星期             
}
int main(void)
{
    P1 = 0xF0;
    lcd1602_init();
    ds1302_init();
    while(1)
    {   
        ds1302_read_ds1302_time();
        lcd1602_display();
    }
    return 0;
}
