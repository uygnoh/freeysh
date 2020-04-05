/* 74HC595 串行到并行数据转换
*/
sbit LATCH = P3^5;   //存储器锁存口，又称为RCLK
sbit SRCLK = P3^6;   //串行数据时钟口
sbit SER   = P3^4;   //串行数据输入口

/* 发送1个字节程序 */
void send_byte(uchar dat)
{
	for (i = 0; i < 8; i++) {
		SRCLK = 0;       //先置为低	
		SER = dat&0x80;  //取数据在最高位
		dat <<= 1;       //再将数据在次高位移至最高位，为下一次取数据做准备
		SRCLK = 1;       //再置位为高，产生移位时钟上升沿，上升沿时在数据寄存器在数据进入移位寄存器
	}
	LATCH = 0;           //先置为低
	_nop_();
	LATCH = 1;          //再置位为高，产生移位时钟上升沿，
			            //上升沿时移位寄存器在数据进入数据存储器，更新数据
}
