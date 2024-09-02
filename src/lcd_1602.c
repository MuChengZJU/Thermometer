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

// 1602A������51�����
sbit LCD_RS = P2 ^ 4;
sbit LCD_RW = P2 ^ 5;
sbit LCD_EN = P2 ^ 6;

// 1602A����������D0~D7����51��P1
#define LCD_BUS P1 // �˴�P1�ɸ�������޸�(��P0����д1�ߵ�ƽ)


void lcd_print(uchar *line1, uchar *line2)
{
    clear();          // ����
    set_cursor(0, 0); // ���ù�굽��һ�е�һ���ַ�λ��
    for (uchar i = 0; line1[i] != '\0'; i++) {
        write_data(line1[i]);
    }
    set_cursor(1, 0); // ���ù�굽�ڶ��е�һ���ַ�λ��
    for (uchar i = 0; line2[i] != '\0'; i++) {
        write_data(line2[i]);
    }
}

void lcd_init()
{
    write_cmd(0x38); // 8λ���ݽӿڣ�2����ʾ��5*7����
    write_cmd(0x0c); // ��ʾ���������أ������˸��
    write_cmd(0x06); // ������ƣ��ַ�����
    write_cmd(0x01); // ����
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
        for (j = 0; j < 120; j++) // ����120��һ������ֵ�����ݾ���Ƶ�ʺͻ������ڼ���ó���
            ;                     // ��ѭ���壬������ʱ
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
    // LCD_BUS = 0xff; // P0��©��Ҫ
    LCD_RS = 0;
    LCD_RW = 1;
    do {
        LCD_EN = 1;
        delay(1);
        busy   = LCD_BUS;
        LCD_EN = 0;
    } while (busy & 0x80);
    // LCD_BUS = 0x00; // P0��©��Ҫ
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