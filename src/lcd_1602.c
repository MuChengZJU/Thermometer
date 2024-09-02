/**
 * @file lcd_1602.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief LCD screen 1602A driver
 * @version 0.1
 * @date 2024-09-02
 *
 *
 */

#include "lcd_1602.h"
// #define uchar unsigned char

// 待打印的字符集
uchar code table0[] = "ZJU BME 2024";
uchar code table1[] = "Temp: ";

// 1602A的连接51的针脚
sbit rs = P2 ^ 4;
sbit rw = P2 ^ 5;
sbit en = P2 ^ 6;

// 1602A的数据线D0~D7连接51的P1
#define LCD_DATA P1

void delay(uint ms)
{
    uint x, y;
    for (x = ms; x > 0; x--)
        for (y = 110; y > 0; y--);
}

void lcd_write_com(uchar com)
{
    rs       = 0; //	写指令
    LCD_DATA = com;
    delay(5);
    //	高脉冲瞬间读入
    en = 1;
    en = 0;
}

void lcd_init()
{
    rw = 0;
    en = 0;
    //	使能端为0，写指令
    lcd_write_com(0x38); //	设置显示方式
    lcd_write_com(0x0c); //	开显示，包括光标和闪烁
    lcd_write_com(0x06); //	写一个字符后，地址指针自动加一
    lcd_write_com(0x01); //	显示请0，数据指针清0
}

void lcd_write_data(uchar date)
{
    rs       = 1;
    LCD_DATA = date;
    delay(5);
    en = 1;
    en = 0;
}

void lcd_print()
{
    uchar num = 0;
    // lcd_init();
    lcd_write_com(0x80);
    for (num = 0; num < 10; num++) {
        lcd_write_data(table0[num]);
        delay(5);
    }
    lcd_write_com(0x80 + 0x40);
    for (num = 0; num < 11; num++) {
        lcd_write_data(table1[num]);
        delay(5);
    }
    while (1);
}
