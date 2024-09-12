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

void delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void delay1s()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



void delay_us(uint xus)
{
    while (xus--);
}

void delay_5us(void)
{
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
}

void delay_10us(void)
{
    delay_5us();
    delay_5us();
}