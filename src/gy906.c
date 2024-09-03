/**
 * @file GY906.C
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Temperature sensor GY906 driver
 * @version 0.1
 * @date 2024-09-03
 * 
 * 
 */

#include "gy906.h"
#include "i2c.h"

#define GY906_ADDR 0x5A // GY906 IIC Slave Address µÿ÷∑

uint read_ambient_temp(void)
{
    uint temp = 0;
    start_bit();
    send_byte(GY906_ADDR << 1);
    send_byte(0x06);
    stop_bit();
    delay_ms(100);
    start_bit();
    send_byte((GY906_ADDR << 1) + 1);
    temp = read_byte();
    temp |= read_byte() << 8;
    stop_bit();
    return temp;
}

void temp2str(uint temp, char *str)
{
    str[0] = temp / 1000 + '0';
    str[1] = '.';
    str[2] = temp % 1000 / 100 + '0';
    str[3] = temp % 100 / 10 + '0';
    str[4] = temp % 10 + '0';
    str[5] = ' ';
    str[6] = 'C';
    str[7] = '\0';
}
