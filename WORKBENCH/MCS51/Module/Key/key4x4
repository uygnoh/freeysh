#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
#define key_port P2
#define smg_port P0
void key_display();
void key_scan44();
 
uchar key_temp44,key_number;
uchar code table[]={ //共阴数码管编码表
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c, 
0x39,0x5e,0x79,0x71};
int main(void)
{
    while(1)
    {
        key_scan44();//键盘扫描子程序
        key_display();//键盘显示子程序
    }
    return 0;
}
void key_scan44()
{
    key_port=0xfe;//key_port端口松检测位
    key_temp44=key_port&0xf0;//有键按下，则key_port端口高四位会发生变化
    while(key_temp44!=0xf0)//有键按下，则执行下面语句
    {   
        key_temp44=key_port;//读回P2端口数据，在没有键按下，可以退出while
        switch(key_temp44)
        {
            case 0xee:
                key_number=0;
                break;
            case 0xde:
                key_number=1;
                break;
            case 0xbe:
                key_number=2;
                break;
            case 0x7e:
                key_number=3;
                break;
                 
        }
        while(key_temp44!=0xf0)//松手检测，有键按下，则执行下面语句
        {  
            key_temp44=key_port;
            key_temp44=key_temp44&0xf0;     
 
        }
    }
             
 
    key_port=0xfd;
    key_temp44=key_port&0xf0;
    while(key_temp44!=0xf0)
    {   
        key_temp44=key_port;
        switch(key_temp44)
        {
            case 0xed:
                key_number=4;
                break;
            case 0xdd:
                key_number=5;
                break;
            case 0xbd:
                key_number=6;
                break;
            case 0x7d:
                key_number=7;
                break;
                 
        }
     
        while(key_temp44!=0xf0)
        {
            key_temp44=key_port;
            key_temp44=key_temp44&0xf0;     
 
        }
    }
     
    key_port=0xfb;
    key_temp44=key_port&0xf0;
    while(key_temp44!=0xf0)
    {   
        key_temp44=key_port;
        switch(key_temp44)
        {
            case 0xeb:
                key_number=8;
                break;
            case 0xdb:
                key_number=9;
                break;
            case 0xbb:
                key_number=10;
                break;
            case 0x7b:
                key_number=11;
                break;
                 
        }
 
        while(key_temp44!=0xf0)
        {
            key_temp44=key_port;
            key_temp44=key_temp44&0xf0;     
        }
    }
    key_port=0xf7;
    key_temp44=key_port&0xf0;
    while(key_temp44!=0xf0)
    {   
        key_temp44=key_port;
        switch(key_temp44)
        {
            case 0xe7:
                key_number=12;
                break;
            case 0xd7:
                key_number=13;
                break;
            case 0xb7:
                key_number=14;
                break;
            case 0x77:
                key_number=15;
                break;
                 
        }
     
        while(key_temp44!=0xf0)
        {
            key_temp44=key_port;
            key_temp44=key_temp44&0xf0; 
        }
    }
}
void key_display()
{
    smg_port=table[key_number];
}

