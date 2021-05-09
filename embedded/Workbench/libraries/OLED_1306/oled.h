#ifndef __OLED_H__
#define __OLED_H__
/* 
 * 0.96OLED-四线SPI1，SSD1306只支持向模块写数据不能读数据
 * Under serial mode, only write operations are allowed.
 * stm32-io     oled-io     说明
 * PA1          OLED_CS     OLED     片选信号, 0为选择
 * PA3	        OLED_DC     OLED     命令/数据标志(0写命令, 1写数据)
 * PA4	        OLED_RST    OLED     硬件复位 
 * PA5	        OLED_D0     D0(SCLK) 信号线作为串行时钟线 SPI1_SCLK
 * PA7	        OLED_D1     D1(SDAT) 信号线作为串行数据线 SPI1_MOSI
 */
#define SPI1_SCLK       (GPIO_Pin_5)    //SPI1时钟信号
#define SPI1_MISO       (GPIO_Pin_6)    //主机接收，从机发送
#define SPI1_MOSI       (GPIO_Pin_7)    //主机发送，从机接收

#define OLED_CS_PIN     GPIO_Pin_1      //OLED_CS选择端
#define OLED_CS_LOW     GPIO_ResetBits(GPIOC, GPIO_Pin_1)						
#define OLED_CS_HIGH    GPIO_SetBits(GPIOC, GPIO_Pin_1)

#define OLED_DC_PIN     GPIO_Pin_3      //OLED_DC数据命令
#define OLED_DC_LOW     GPIO_ResetBits(OLED_PORT, OLED_DC_PIN)
#define OLED_DC_HIGH    GPIO_SetBits(OLED_PORT, OLED_DC_PIN)

#define OLED_RST_PIN    GPIO_Pin_4      //OLED_RST复位
#define OLED_RST_LOW    GPIO_ResetBits(OLED_PORT, OLED_RST_PIN)
#define OLED_RST_HIGH   GPIO_SetBits(OLED_PORT, OLED_RST_PIN)

#define MAX_COLUMN	128                 //行数128
#define MAX_ROW	64                      //列数64
#define SIZE 16 	                    //显示字体选择()

#define OLED_DATA	1                   //数据
#define OLED_COMM	0                   //命令



void rcc_conf(void);
void gpio_init(void)
void spi1_init(void);
void spi1_send_byte(uint8_t spi_byte);
static void oled_write_operate(uint8_t mode, uint8_t dat);


void oled_set_pos(uint8_t x, uint8_t y);
void oled_on(void);
void oled_off(void);
void oled_dis_clear(void);
void oled_dis_full(void);
void oled_dis_one_char(uint8_t x, uint8_t y, uint8_t str);  //显示一个字符
void oled_dis_str(uint8_t x, uint8_t y, uint8_t *str);      //显示一个字符串
void oled_dis_chinese(uint8_t x, uint8_t y, uint8_t no);
void oled_dis_picture(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *bmp);
uint32_t oled_pow(uint8_t m, uint8_t n);
void oled_dis_num(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size_num);
void oled_init(void);

#endif

