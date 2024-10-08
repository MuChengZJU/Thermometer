/**
 * @file utils.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-09-03
 *
 *
 */

#ifndef __UTILS_H
#define __UTILS_H

#include <reg52.h>
#include "intrins.h"

#define DEGREE_SYMBOL 0xDF

typedef unsigned char uchar;
typedef unsigned int uint;

/**
 * @brief ��ʱxms����
 *
 * @param xms
 */
void delay_ms(uint xms);

/**
 * @brief ��ʱxus΢��
 *
 * @param xus
 */
void delay_us(uint xus);

void delay1ms();
void delay1s();
void delay500ms();
void delay_5us(void);
void delay_10us(void);

#endif