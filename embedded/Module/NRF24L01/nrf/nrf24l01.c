/**
  *****************************************************************************
  * 
  * 2018.11.05
  * @freeysh
  */

uint8_t TX_ADDRESS[5] = {0xe7, 0xe7, 0xe7, 0xe7, 0x01};
 
bit nrf_irq_flag = 0;
bdata uint8_t status = 0;
sbit RX_DR  = status^6
sbit TX_DR  = status^5
sbit MAX_RT = status^4 
 
uint8_t xdata show_buf[128], txbuf[32], rxbuf[32]; 
void nrf24l01_init(void)
{
	CE = 1;
	SS = 1;
	SPI_Init;
	EX0 = 1;	//打开外部中断
	IT0 = 1;	//下降沿触发
}

uint8_t SPI_W_Reg(uint8_t reg_addr, uint8_t val)
{
	uint8_t status;
	SS = 0;
	status = SPI_W_R_byte(reg_addr);
	SPI_W_R_byte(val);
	SS = 1;
	return status;
}

uint8_t SPI_R_Reg(uint8_t reg_addr)
{
	uint8_t reg_val;
	SS = 0;
	SPI_W_R_byte(reg_addr);
	reg_val = SPI_W_R_byte(NOP);
	SS = 1;
	return reg_val;
}



uint8_t SPI_Write_buf(uint8_t reg_addr, uint8_t *buf, uint8_t len)
{
	uint8_t status, i;
	SS = 0;
	status = SPI_W_R_byte(reg_addr);
	for (i = 0; i < len; i++)
	{
		SPI_W_R_byte(*(buf+i));
	}
	SS = 1;
	return status;
}


uint8_t SPI_Read_buf(uint8_t reg_addr, uint8_t *buf, uint8_t len)
{
	uint8_t status, i;
	SS = 0;
	status = SPI_W_R_byte(reg_addr);
	for (i = 0; i < len; i++)
	{
		*(buf+i) = SPI_W_R_byte(NOP);
	}
	SS = 1;
	return status;
}




void SET_RX_Mode(void)
{
	CE = 0;
	
	SPI_W_Reg(W_REGISTER | EN_RXADDR, 0x01);//接收通道配置为   0通道
	SPI_W_Reg(W_REGISTER | EN_AA, 0x01);	//使能自动应答通道为 0通道
	SPI_W_Reg(W_REGISTER | SETUP_AW, 0x03);
	SPI_W_Reg(W_REGISTER | RF_CH, 0x03);	
	SPI_W_Reg(W_REGISTER | RF_SETUP, 0x0f);
	SPI_W_Reg(W_REGISTER | STATUS, 0xf0);
	SPI_W_Reg(W_REGISTER | RX_PW_P0, 32);	//通道0接收字节有效长度 32byte		
	SPI_Write_buf(W_REGISTER | RX_ADDR_P0, TX_ADDRESS, 5);
	SPI_W_Reg(W_REGISTER | CONFIG, 0x0f);	//设置成接收模式，上电，使能CRC16bit校验
	
	CE = 1;
		
	
}


void SET_TX_Mode(uint8_t *tx_buf)
{
	CE = 0;
	
	SPI_W_R_byte(FLUSH_TX);	//清空缓存区
	SPI_W_Reg(W_REGISTER | EN_RXADDR, 0x01);//接收通道配置为   0通道
	SPI_W_Reg(W_REGISTER | EN_AA, 0x01);	//使能自动应答通道为 0通道
	SPI_W_Reg(W_REGISTER | SETUP_AW, 0x03);
	SPI_W_Reg(W_REGISTER | SETUP_RETR, 0x8f);//重复发送次数
	SPI_W_Reg(W_REGISTER | RF_CH, 0x03);	
	SPI_W_Reg(W_REGISTER | RF_SETUP, 0x0f);
	SPI_W_Reg(W_REGISTER | STATUS, 0xf0);   
	SPI_Write_buf(W_REGISTER | RX_ADDR_P0, TX_ADDRESS, 5);
	SPI_Write_buf(W_REGISTER | TX_ADDR, TX_ADDRESS, 5);
	SPI_Write_buf(W_TX_PAYLOAD, tx_buf, 32);
	SPI_W_Reg(W_REGISTER | CONFIG, 0x0e);	//设置成发送模式，上电，使能CRC16bit校验
	CE = 1;
	delay_us(20);
	
	CE = 0;
	
}


/* 验证通信协议 */
bit Test_24L01(void)
{
	SPI_W_Reg(W_REGISTER | CONFIG, 0x50);
	if (0x50 != SPI_R_Reg(CONFIG)
		return 0;
	SPI_W_Reg(W_REGISTER | CONFIG, 0x05);
	if (0x05 != SPI_R_Reg(CONFIG)
		return 0;
	return 1;	
}

/* 外部中断0 处理程序*/
void exit0_handle(void) interrupt 0
{
	nrf_irq_flag = 1;
}



int main(void)
{
	nrf24l01_init();
	usart_init();
	T_sbuf(SPI_R_Reg(CD));	//读取CD的值，查看信号干扰度
	
	SET_RX_Mode();
	
	while (1)
	{
	//////////////////////////////////////////发送处理///////////////////////////////////////////
	if (Is_uart_rcv())
	{
		clear_uart_rcv();
		if (0 == Get_uart_rcv())
		{
			for (i = 0; i < 32; i++)
			{
				txbuf[i] = i;
			}
			nrf_irq_flag = 0;
			SET_TX_Mode(tx_buf);
			wait_tm = 100000;
			while (!nrf_irq_flag && wait_tm--);
			if (wait_tm < 0)
			{
				T_sbuf(0x01);	//发送超时
			}
			stauts = SPI_R_REG(R_REGISTER | STATUS);
			if (MAX_RT)
				SPI_W_R_byte(FLUSH_TX); //发送超过最大次数，把数据丢掉
			if (TX_DR)
				T_sbuf(0x02);		//发送成功
			SPI_W_Reg(W_REGISTER | STATUS, status);//清除状态寄存器
			SET_RX_Mode();
				
		}
	}
	
	
	
	/////////////////////////////////////////接收处理//////////////////////////////////////
		if (nrf_irq_flag)	//读操作
		{
			stauts = SPI_R_REG(R_REGISTER | STATUS);
			if (RX_DR)
			{
				SPI_Read_buf(R_RX_PAYLOAD, rxbuf, 32);
				for (i = 0; i < 32; i++)
				{
					T_sbuf(rxbuf[i]);
				}
			}
			SPI_W_Reg(W_REGISTER | STATUS, status);
			SPI_W_R_byte(FLUSH_RX);
			nrf_irq_flag = 0; 
		}
		
		///////////////////////////////////////////////////////////////////
	}
	
}
















