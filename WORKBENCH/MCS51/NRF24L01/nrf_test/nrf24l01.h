/**
  *****************************************************************************
  * 
  * 2018.11.05
  * @freeysh
  */

#ifndef __NRF24L01_H
#define __NRF24L01_H

#define READ_REG 0x00 //读配置寄存器,低5位为寄存器地址

 #define WRITE_REG 0x20 //写配置寄存器,低5位为寄存器地址

 #define RD_RX_PLOAD 0x61 //读RX有效数据,1~32字节

 #define WR_TX_PLOAD 0xA0 //写TX有效数据,1~32字节

 #define FLUSH_TX 0xE1 //清除TX FIFO寄存器.发射模式下用

 #define FLUSH_RX 0xE2 //清除RX FIFO寄存器.接收模式下用

 #define REUSE_TX_PL 0xE3 //重新使用上一包数据,CE为高,数据包被不断发送.

 #define NOP 0xFF //空操作,可以用来读状态寄存器

// NRF24L01寄存器（一共24个）：

#define CONFIG 0x00 //配置寄存器地址

 #define EN_AA 0x01 //使能自动应答功能

 #define EN_RXADDR 0x02 //接收地址允许

 #define SETUP_AW 0x03 //设置地址宽度(所有数据通道)

 #define SETUP_RETR 0x04 //建立自动重发

 #define RF_CH 0x05 //RF通道

 #define RF_SETUP 0x06 //RF寄存器

 #define STATUS 0x07 //状态寄存器

 #define OBSERVE_TX 0x08 // 发送检测寄存器

 #define CD 0x09 // 载波检测寄存器

 #define RX_ADDR_P0 0x0A // 数据通道0接收地址

 #define RX_ADDR_P1 0x0B // 数据通道1接收地址

 #define RX_ADDR_P2 0x0C // 数据通道2接收地址

 #define RX_ADDR_P3 0x0D // 数据通道3接收地址

 #define RX_ADDR_P4 0x0E // 数据通道4接收地址

 #define RX_ADDR_P5 0x0F // 数据通道5接收地址

 #define TX_ADDR 0x10 // 发送地址寄存器

 #define RX_PW_P0 0x11 // 接收数据通道0有效数据宽度(1~32字节)

 #define RX_PW_P1 0x12 // 接收数据通道1有效数据宽度(1~32字节)

 #define RX_PW_P2 0x13 // 接收数据通道2有效数据宽度(1~32字节)

 #define RX_PW_P3 0x14 // 接收数据通道3有效数据宽度(1~32字节)

 #define RX_PW_P4 0x15 // 接收数据通道4有效数据宽度(1~32字节)

 #define RX_PW_P5 0x16 // 接收数据通道5有效数据宽度(1~32字节)

#define FIFO_STATUS 0x17 // FIFO状态寄存器

bit Test_24L01(void);
void nrf24l01_init(void);


#endif
