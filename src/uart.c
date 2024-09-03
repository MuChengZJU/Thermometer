/**
 * @file uart.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Serial port driver
 * @version 0.1
 * @date 2024-09-03
 * 
 * 
 */
#include "uart.h"
#include <stdio.h>

void uart_init()
{
    // ���ò�����
    SCON = 0x50; // 8λ���ݣ��ɱ䲨����
    TMOD = 0x20; // ��ʱ��1�����ڷ�ʽ2��8λ�Զ���װ��
    TH1 = 0xfd;  // ������9600
    TL1 = 0xfd;  // ������9600
    TR1 = 1;     // ������ʱ��1
    TI = 1;      // ���ͱ�־λ��1
}

void uart_send(char dat)
{
    SBUF = dat;
    while (!TI)
        ;
    TI = 0;
}

char uart_recv()
{
    while (!RI)
        ;
    RI = 0;
    return SBUF;
}

void uart_print(char *str)
{
    while (*str != '\0')
    {
        uart_send(*str);
        str++;
    }
}

void uart_println(char *str) // print with newline
{
    uart_print(str);
    uart_send('\r');
    uart_send('\n');
}

void uart_print_int(int num)
{
    char str[16];
    sprintf(str, "%d", num);
    uart_print(str);
}

void uart_println_int(int num)
{
    uart_print_int(num);
    uart_send('\r');
    uart_send('\n');
}

void uart_print_float(float num)
{
    char str[16];
    sprintf(str, "%f", num);
    uart_print(str);
}

void uart_println_float(float num)
{
    uart_print_float(num);
    uart_send('\r');
    uart_send('\n');
}





