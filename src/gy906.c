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

#define GY906_ADDR  0x5A // GY906 IIC Slave Address ��ַ
#define GY906_TA    0x06 // TA Address in RAM
#define GY906_TOBJ1 0x07 // TOBJ1 Address in RAM

uint read_temp(uchar sensor)
{
    uchar temp_low, temp_high, pec, is_ack; // 0 for ACK, 1 for NACK
    start_bit();
    send_byte(GY906_ADDR << 1); // Slave Addr + Write
    is_ack = read_bit();
    if (sensor) {
        send_byte(GY906_TA); // Send RAM Address + Command
    } else {
        send_byte(GY906_TOBJ1);
    }
    is_ack = read_bit();
    start_bit();
    send_byte((GY906_ADDR << 1) | 0x01); // Slave Addr + Read
    is_ack        = read_bit();
    temp_low = read_byte();
    send_bit(0);
    temp_high = read_byte();
    send_bit(0);
    pec = read_byte();
    send_bit(0);
    stop_bit();
    return (temp_high << 8) | temp_low;
}

void temp2str(uint temp, char *str)
{
    char *ptr     = str;  // ָ���ַ�����ָ��
    uint quotient = temp; // ��
    char digit;           // ���ڴ洢ת���������ַ�
    char *start = str;    // �ַ�����ʼλ��
    char tempChar;

    // ѭ������ֱ����Ϊ0
    while (quotient != 0) {
        digit  = quotient % 10; // ��������
        *ptr++ = '0' + digit;   // ������ת��Ϊ��Ӧ���ַ����洢
        quotient /= 10;         // ������
    }

    // �ַ�����ת����Ϊ����ļ����õ����������
    *ptr = '\0'; // �ַ���������
    ptr--;       // �ص��ַ��������һ������

    // ��ת�ַ���
    while (start < ptr) {
        tempChar = *start;
        *start   = *ptr;
        *ptr     = tempChar;
        start++;
        ptr--;
    }
}

void start_bit()
{
    SDA = 1;
    SCL = 1;
    delay_us(5);
    SDA = 0;
    delay_us(50); // Timeout_H > 45 us
    SCL = 0;
}

void stop_bit()
{
    SDA = 0;
    SCL = 1;
    delay_us(5);
    SDA = 1;
}

uchar read_bit(void) // Timeout_L > 27 ms
{
    uchar bit_in;
    SDA = 1; // �ͷ�����
    SCL = 1;
    delay_us(5);
    bit_in = SDA ? 1 : 0;
    delay_us(50);
    SCL = 0;
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
        delay_ms(30);
    }
    return dat_byte;
}

void send_bit(uchar bit_out)
{
    SDA = bit_out ? 1 : 0;
    delay_us(5);
    SCL = 1;
    delay_us(50);
    SCL = 0;
    // delay_us(5);
    // SDA = 1; // �ͷ�����
}

void send_byte(uchar dat_byte)
{
    uchar i;
    uchar bit_out;
    for (i = 0; i < 8; i++) {
        bit_out = dat_byte & 0x80;
        send_bit(bit_out);
        delay_ms(30);
        dat_byte = dat_byte << 1;
    }
}
