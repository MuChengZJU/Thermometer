/**
 * @file lcd1602.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief LCD screen 1602A driver
 * @version 0.1
 * @date 2024-09-02
 *
 *
 */

#include "lcd1602.h"

// 1602A的连接51的针脚
sbit LCD_RS = P3 ^ 4;
sbit LCD_RW = P3 ^ 5;
sbit LCD_EN = P3 ^ 6;

// 1602A的数据总线D0~D7连接51的P1
#define LCD_BUS P1 // 此处P1可根据情况修改(若P0，需写1高电平)

void lcd_print(char *line1, char *line2)
{
    uchar i;         // 在函数开始处声明变量i
    clear();         // 清屏
    write_cmd(0x80); // 设置光标到第一行第一个字符位置
    for (i = 0; line1[i] != '\0'; i++) {
        write_data(line1[i]);
    }
    write_cmd(0xc0); // 设置光标到第二行第一个字符位置
    for (i = 0; line2[i] != '\0'; i++) {
        write_data(line2[i]);
    }
}

void lcd_init()
{
    delay(15);       // 上电后等待15ms，等待LCD电源稳定
    write_cmd(0x38); // 8位数据接口，2行显示，5*7点阵
    delay(5);
    write_cmd(0x0c); // 显示器开，光标关，光标闪烁关
    write_cmd(0x06); // 光标右移，字符不动
    write_cmd(0x01); // 清屏
}

void clear()
{
    wait_busy();
    write_cmd(0x01);
    delay(5);
}

void delay(uint xms)
{
    uint i, j;
    for (i = 0; i < xms; i++)
        for (j = 0; j < 1000; j++) // 这里120是一个经验值，根据晶振频率和机器周期计算得出的
            ;                      // 空循环体，用于延时
}

void wait_busy()
{
    uchar busy;
    // LCD_BUS = 0xff; // P0开漏需要
    LCD_RS = 0;
    LCD_RW = 1;
    do {
        LCD_EN = 1;
        delay(5);
        busy   = LCD_BUS;
        LCD_EN = 0;
    } while (busy & 0x80);
    // LCD_BUS = 0x00; // P0开漏需要
}

void write_data(uchar dat)
{
    wait_busy();

    LCD_EN = 0;
    LCD_RS = 1;
    LCD_RW = 0;

    LCD_BUS = dat; // data is reserved word, so use dat.
    delay(1);

    LCD_EN = 1;
    delay(5);
    LCD_EN = 0;
}

void write_cmd(uchar cmd)
{
    wait_busy();

    LCD_EN = 0;
    LCD_RS = 0;
    LCD_RW = 0;

    LCD_BUS = cmd;
    delay(1);

    LCD_EN = 1;
    delay(5);
    LCD_EN = 0;
}