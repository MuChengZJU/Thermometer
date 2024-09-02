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

// 1602A的连接51的针脚
sbit LCD_RS = P2 ^ 4;
sbit LCD_RW = P2 ^ 5;
sbit LCD_EN = P2 ^ 6;

// 1602A的数据总线D0~D7连接51的P1
#define LCD_BUS P1 // 此处P1可根据情况修改(若P0，需写1高电平)


void lcd_print(uchar *line1, uchar *line2)
{
    clear();          // 清屏
    set_cursor(0, 0); // 设置光标到第一行第一个字符位置
    for (uchar i = 0; line1[i] != '\0'; i++) {
        write_data(line1[i]);
    }
    set_cursor(1, 0); // 设置光标到第二行第一个字符位置
    for (uchar i = 0; line2[i] != '\0'; i++) {
        write_data(line2[i]);
    }
}

void lcd_init()
{
    write_cmd(0x38); // 8位数据接口，2行显示，5*7点阵
    write_cmd(0x0c); // 显示器开，光标关，光标闪烁关
    write_cmd(0x06); // 光标右移，字符不动
    write_cmd(0x01); // 清屏
}

void clear()
{
    wait_busy();
    write_cmd(0x01);
}

void delay(uint xms)
{
    uint i, j;
    for (i = 0; i < xms; i++)
        for (j = 0; j < 120; j++) // 这里120是一个经验值，根据晶振频率和机器周期计算得出的
            ;                     // 空循环体，用于延时
}

void set_cursor(uchar x, uchar y)
{
    uchar addr;
    if (y == 0) {
        addr = 0x00 + x;
    } else {
        addr = 0x40 + x;
    }
    write_cmd(0x80 + addr);
}

void wait_busy()
{
    uchar busy;
    // LCD_BUS = 0xff; // P0开漏需要
    LCD_RS = 0;
    LCD_RW = 1;
    do {
        LCD_EN = 1;
        delay(1);
        busy   = LCD_BUS;
        LCD_EN = 0;
    } while (busy & 0x80);
    // LCD_BUS = 0x00; // P0开漏需要
}

void write_data(uchar data)
{
    wait_busy();
    LCD_RS  = 1;
    LCD_RW  = 0;
    LCD_BUS = data;
    LCD_EN  = 1;
    delay(1);
    LCD_EN = 0;
}

void write_cmd(uchar cmd)
{
    wait_busy();
    LCD_RS  = 0;
    LCD_RW  = 0;
    LCD_BUS = cmd;
    LCD_EN  = 1;
    delay(1);
    LCD_EN = 0;
}