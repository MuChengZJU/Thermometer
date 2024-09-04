/**
 * @file utils.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-03
 * 
 * 
 */

#include "utils.h"

void delay_ms(uint xms)
{
    uint i, j;
    for (i = 0; i < xms; i++)
        for (j = 0; j < 1000; j++) // 这里120是一个经验值，根据晶振频率和机器周期计算得出的
            ;                      // 空循环体，用于延时
}

void delay_us(uint xus)
{
    while (xus--)
        ;
}