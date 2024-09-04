/**
 * @file gy906.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Temperature sensor GY906 driver header file
 * @version 0.1
 * @date 2024-09-03
 *
 *
 */

#ifndef __GY906_H__
#define __GY906_H__

#include "utils.h"

// 51 IIC �ӿ�
// ���� GY906 �¶ȴ�����
sbit SDA = P2 ^ 0;
sbit SCL = P2 ^ 1;

// // ���� IIC ͨ�ŵı�־λ
// // bdata uchar g_flag;
// sbit g_bit_in = P2 ^ 3;
// sbit g_bit_out = P2 ^ 4;

void start_bit();
void stop_bit();
uchar read_bit(void);
uchar read_byte(void);
void send_bit(uchar bit_out);
void send_byte(uchar dat_byte);


// �ӿں���
float read_temp(uchar sensor);

void float2str(float value, char *str);


#endif