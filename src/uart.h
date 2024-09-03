/**
 * @file uart.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Serial port driver header file
 * @version 0.1
 * @date 2024-09-03
 *
 *
 */

#ifndef __UART_H
#define __UART_H

#include "utils.h"

// UART �����������õĽӿں���
void uart_init(void);
void uart_print(char *str);
void uart_println(char *str);
void uart_print_int(int num);
void uart_println_int(int num);
void uart_print_float(float num);
void uart_println_float(float num);

// UART �ڲ�����
void uart_send(char dat);
char uart_recv(void);

#endif