/*
  LCD1602引脚定义(8051_12MHz)
  VCC   电源正 VDD
  GND   电源地 VSS
  VL    液晶显示偏压信号，调节对比度
  BL+   背光源正极 [BLA]
  BL-   背光源负极 [BLk]
  RS    数据/命令选择端(H/L)
  RW    读 / 写 选择端(H/L)
  EN    使能信号
  D1,D2,D3,D4,D5,D6,D7,D8,数据端口 [8个引脚接P0端口]
  注意： LCD1602共可以显示 2行，
        第一行起始地址为：0x80,
        第二行起始地址为：0x80+0x40. 
*/

#include<reg52.h>
#define uint16_t unsigned int
#define uint8_t unsigned char
#define DATA_1602   P0      /* 数据端口 */
#define BUSY        0x80    /* 检测忙状态 */
 
sbit RS = P2^6;
sbit RW = P2^5;
sbit EN = P2^7;


int main(void)
{
    lcd1602_init();
    lcd1602_write_cmd(0x80);        //给出地址指针，第一行的第1个字符位
    lcd1602_write_dat('y');         //写入数据
    lcd1602_write_cmd(0x80+5);      //给出地址指针,第一行第6个字符位
    lcd1602_write_dat('0');         //显示0
    lcd1602_write_dat(0x30);        //显示0
    lcd1602_write_cmd(0x80+0x40);   //给出地址指针，第二行的第1个字符
    lcd1602_write_dat(0x38);        //显示数字 8
    
    lcd1602_string_set(0,0,"hello,");
	lcd1602_string_set(4,1,"world!");
}


/* LCD1602写命令 */
void lcd1602_write_cmd(uint8_t cmd)
{   
    RS = 0;                         //RS为低电平表示要写入的是命令(command)
    RW = 0;                         //RW为低电平表示是写信号
    EN = 0;                         //EN为使能信号，开始为低电平
    P0 = cmd;                       //先送人(command数据)
    delay_ms(2);                    //稍作延时，等待数据稳定
    EN = 1;                         //然后在把使能信号拉高，数据开始写入LCD1602中
    delayms(5);                     //稍作延时，等待数据写入完成
    EN = 0;                         //之后再把使能信号拉低
    delayms(2);                     //稍作延时
}


/* LCD1602写数据 */
void lcd1602_write_dat(uint8_t dat)
{   
    RS = 1;                         //RS为低高电平表示要写入的是数据
    RW = 0;                         //RW为低电平表示是写信号
    EN = 0;                         //EN为使能信号，开始为低电平
    P0 = dat;                       //先送人(data数据)
    delay_ms(2);                    //稍作延时，等待数据稳定
    EN = 1;                         //然后在把使能信号拉高，数据开始写入LCD1602中
    delay_ms(5);                    //稍作延时，等待数据写入完成
    EN = 0;                         //之后再把使能信号拉低
    delay_ms(2);                    //稍作延时
}


/* LCD1602 初始化 */
void lcd1602_init(void)
{
    lcd1602_write_cmd(0x38);    //显示模式设置
    delay_ms(5);
    lcd1602_write_cmd(0x0f);    //光标显示[0x0E,光标不闪][0x0C，光标不显示]
    delay_ms(5);
    lcd1602_write_cmd(0x0c);    //显示开及光标设置
    delay_ms(5);
    lcd1602_write_cmd(0x06);    //显示光标移动设置(地址指针自动加1)
    delay_ms(5);
    lcd1602_write_cmd(0x01);    //显示清屏
    delay_ms(5);
}


/* LCD1602 清屏 */
void lcd1602_clear_all()
{
    lcd1602_write_cmd(0x01);
    lcd1602_write_cmd(0x80);
}


/* LCD1602 忙碌检测 */
/* 根据规定，RS为低电平，RW为高电平时，可以读状态 */
/* 返回值result为bit型，0闲 1忙 */
bit lcd1602_busy()
{
    bit result;
    RS = 0;                     //command
    RW = 1;                     //read_status
    EN = 1;                     //使能控制
    /* 空操作四个机器周期，给硬件反应时间 */
    _nop_(); _nop_(); _nop_(); _nop_();
    result = bit(P0 & BUSY);    //LCD的D0－D7中，D7＝1为忙碌，0为空闲
    EN ＝ 0;
    return result;
}


/* ms级延时子程序 
 * (8051, 12MHZ晶振)
 */
void delay_ms(uint16_t z)
{
    uint16_t x,y;
    for(x=z;x>0;x--)
        for(y=110;y>0;y--);
}


//set a character at the given position
//在指定坐标设置字符（p_x=0~15, p_y=0~1）
void lcd1602_char_set(uint8_t p_x, uint8_t p_y, char p_char)
{
    uint8_t t_cmd = 0x80;
    p_x &= 0x0f;
    p_y &= 0x01;
    t_cmd |= p_x;
    if (p_y)
    {
        t_cmd |= 0x40;
    }
    lcd1602_write_cmd(t_cmd);
    lcd1602_write_dat(p_char);
}


//write a string from the given position
//从指定位置开始设置字符串（p_x=0~15，p_y=0~1，p_string必须是以0结尾的字符串）
void lcd1602_string_set(uint8_t p_x, uint8_t p_y, const uint8_t* p_string)
{
    uint8_t t_x, t_y;
    p_x &= 0x0f;
    p_y &= 0x01;
    for (t_y = p_y; t_y < 2; t_y++)
    {
        for (t_x = p_x; t_x < 16 && (*p_string) != 0; t_x++)
        {
            lcd1602_char_set(t_x, t_y, *(p_string++));
        }
    }
}


