/**
 * @file lcd_1602.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief LCD screen 1602A driver header file
 * @version 0.1
 * @date 2024-09-02
 * 
 * 
 */

#ifndef __1602_H
#define __1602_H

#include <reg52.h>

// LCD �����������õĽӿں���
void lcd_print(uchar *line1, uchar *line2);
void lcd_init();

// LCD �ڲ�����
void write_cmd(uchar cmd);
void write_data(uchar dat);
void set_cursor(uchar x, uchar y);
void clear();
void delay(uint xms);


#endif