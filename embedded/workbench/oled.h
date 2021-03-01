#ifndef __OLED_H__
#define __OLED_H__

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

