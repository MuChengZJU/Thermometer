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

// LCD �����������õĽӿں���

/**
 * @brief �ӿڣ�ˢ�²���ʾ��������
 *
 * @param line1 ��һ�����֣�ASCII
 * @param line2 �ڶ������֣�ASCII
 */
void lcd_print(char *line1, char *line2);

/**
 * @brief �ӿڣ���ʼ��LCD���á������������ʼ���׶Ρ�
 *
 */
void lcd_init(void);

// LCD �ڲ�����
void write_cmd(uchar cmd);
void write_data(uchar dat);
void set_cursor(uchar x, uchar y);
void clear();
void delay(uint xms);
void wait_busy();

#endif