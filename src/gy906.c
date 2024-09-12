/**
 * @file gy906.C
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Temperature sensor GY906 driver
 * @version 0.1
 * @date 2024-09-03
 *
 *
 */

#include "gy906.h"
#include <STDIO.H>

#define GY906_ADDR  0x5A // GY906 IIC Slave Address 地址
#define GY906_TA    0x06 // TA Address in RAM
#define GY906_TOBJ1 0x07 // TOBJ1 Address in RAM

float read_temp(uchar sensor)
{
    uchar temp_low, temp_high, pec, is_ack; // 0 for ACK, 1 for NACK
    uint temp_bin;
    float temp_float;
    start_bit();
    send_byte(GY906_ADDR << 1); // Slave Addr + Write
    is_ack = read_bit();
    if (sensor) {
        send_byte(GY906_TOBJ1); // Send RAM Address + Command
    } else {
        send_byte(GY906_TA);
    }
    is_ack = read_bit();
    start_bit();
    send_byte((GY906_ADDR << 1) | 0x01); // Slave Addr + Read
    is_ack   = read_bit();
    temp_low = read_byte();
    // send_bit(0);
    temp_high = read_byte();
    // send_bit(0);
    pec = read_byte();
    send_bit(0);
    stop_bit();
    temp_bin = (temp_high << 8) | temp_low;
    temp_float = (float)temp_bin * 0.02 - 273.15;
    return temp_float;
}
void float2str(float value, char *str)
{
    int integerPart = (int)value;
    int decimalPart = (int)((value - integerPart) * 100);

    sprintf(str, "%3d.%02d  C      ", integerPart, decimalPart);
    str[7] = DEGREE_SYMBOL;
}
void start_bit()
{
    SDA = 1;
    delay_10us();
    SCL = 1;
    delay_10us();
    SDA = 0;
    delay_10us(); // Timeout_H > 45 us
    SCL = 0;
    delay_10us();
}

void stop_bit()
{
    SCL = 0;
    delay_10us();
    SDA = 0;
    delay_10us();
    SCL = 1;
    delay_10us();
    SDA = 1;
    delay_10us();
}

uchar read_bit(void) // Timeout_L > 27 ms
{
    uchar bit_in;
    SCL = 0;
    delay_10us();
    SCL = 1;
    delay_10us();
    bit_in = SDA ? 1 : 0;
    delay_10us();
    SCL = 0;
    delay_10us();
    return bit_in;
}

uchar read_byte(void)
{
    uchar i, dat_byte = 0;
    for (i = 0; i < 8; i++) {
        dat_byte = dat_byte << 1;
        if (read_bit()) {
            dat_byte |= 0x01;
        }
        // delay_10us();
    }
    if (read_bit()) {
        // NACK
        SDA = 1;
    } else {
        // ACK
        SDA = 0;
    }
    return dat_byte;
}

void send_bit(uchar bit_out)
{
    SDA = bit_out ? 1 : 0;
    delay_10us();
    SCL = 1;
    delay_10us();
    SCL = 0;
    delay_10us();
    // SDA = 1; // 释放总线
}

void send_byte(uchar dat_byte)
{
    uchar i;
    uchar bit_out;
    SCL = 0;
    for (i = 0; i < 8; i++) {
        bit_out = dat_byte & 0x80;
        send_bit(bit_out);
        // delay_10us();
        dat_byte = dat_byte << 1;
    }
}
