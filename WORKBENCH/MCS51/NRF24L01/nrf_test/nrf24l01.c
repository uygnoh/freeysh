/**
  *****************************************************************************
  * 
  * 2018.11.05
  * @freeysh
  */

uint8_t TX_ADDRESS[5] = {0xe7, 0xe7, 0xe7, 0xe7, 0x01};
  
void nrf24l01_init(void)
{
	CE = 1;
	SS = 1;
	SPI_Init;
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


int main(void)
{
	nrf24l01_init();
	
	if (Test_24L01())
		T_buff(0xff);	//工作正常
	else
		T_buff(0xf0);	//工作不正常
	
	
	
	
}
