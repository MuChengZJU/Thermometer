/**
 * @file i2c.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-03
 * 
 * 
 */

#include "i2c.h"

bdata uchar g_flag;
sbit g_bit_in = g_flag ^ 0;
sbit g_bit_out = g_flag ^ 1;

void start_bit()
{
    SDA = 1;
    delay_us(5);
    SCL = 1;
    delay_us(5);
    SDA = 0;
    delay_us(5);
    SCL = 0;
    delay_us(5);
}

void stop_bit()
{
    SCL = 0;
    delay_us(5);
    SDA = 0;
    delay_us(5);
    SCL = 1;
    delay_us(5);
    SDA = 1;
    delay_us(5);
}

void read_bit(void)
{
    SDA = 1;
    delay_us(5);
    SCL = 1;
    delay_us(5);
    g_bit_in = SDA;
    delay_us(5);
    SCL = 0;
    delay_us(5);
}

uchar read_byte(void)
{
    uchar i, dat_byte = 0;
    for (i = 0; i < 8; i++)
    {
        dat_byte = dat_byte << 1;
        read_bit();
        if (g_bit_in)
        {
            dat_byte += 1;
        }
    }
    send_bit();
    return dat_byte;
}

void send_bit(void)
{
    SDA = g_bit_out ? 1 : 0;
    delay_us(1);
    SCL = 1;
    delay_us(5);
    SCL = 0;
    delay_us(5);
}

void send_byte(uchar dat_byte)
{
    uchar i;
    for (i = 0; i < 8; i++)
    {
        g_bit_out = dat_byte & 0x80;
        send_bit();
        dat_byte = dat_byte << 1;
    }
    read_bit();
}