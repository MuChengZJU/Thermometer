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

typedef unsigned char uchar;
typedef unsigned int uint;

void delay(uint ms);
void lcd_write_com(uchar com);
void lcd_init(void);
void lcd_write_data(uchar date);
void lcd_print(void);

#endif