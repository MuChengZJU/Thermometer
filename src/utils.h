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

typedef unsigned char uchar;
typedef unsigned int uint;


/**
 * @brief —” ±xms∫¡√Î
 * 
 * @param xms 
 */
void delay_ms(uint xms);

/**
 * @brief —” ±xusŒ¢√Î
 * 
 * @param xus 
 */
void delay_us(uint xus);

#endif