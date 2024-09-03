/**
 * @file i2c.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-09-03
 *
 *
 */

#ifndef __I2C_H__
#define __I2C_H__

#include "utils.h"

// 51 IIC 接口
// 用于 GY906 温度传感器
sbit SDA = P2 ^ 0;
sbit SCL = P2 ^ 1;

void start_bit();
void stop_bit();
void read_bit(void);
uchar read_byte(void);
void send_bit(void);
void send_byte(uchar dat_byte);

#endif