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
        for (j = 0; j < 1000; j++) // ����120��һ������ֵ�����ݾ���Ƶ�ʺͻ������ڼ���ó���
            ;                      // ��ѭ���壬������ʱ
}

void delay_us(uint xus)
{
    while (xus--)
        ;
}