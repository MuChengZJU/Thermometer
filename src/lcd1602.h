/**
 * @file lcd1602.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief LCD screen 1602A driver header file
 * @version 0.1
 * @date 2024-09-02
 *
 *
 */

#ifndef __1602_H
#define __1602_H

#include "utils.h"


// LCD 供主函数调用的接口函数

/**
 * @brief 接口：刷新并显示两行文字
 *
 * @param line1 第一行文字，ASCII
 * @param line2 第二行文字，ASCII
 */
void lcd_print(char *line1, char *line2);

/**
 * @brief 接口：初始化LCD设置。用于主程序初始化阶段。
 *
 */
void lcd_init(void);

void lcd_clear();

// LCD 内部函数
void write_cmd(uchar cmd);
void write_data(uchar dat);
void wait_busy();

#endif