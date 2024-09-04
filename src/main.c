/**
 * @file main.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Main program of Thermometer
 * @version 0.1
 * @date 2024-09-02
 *
 *
 */

#include <REG52.H>
#include "utils.h"
#include "lcd1602.h"
#include "uart.h"
#include "gy906.h"

#define TEMP_SENSOR 1 // 1 for TOBJ1, 0 for AMBIENT
#define AVE_TIMES   10

void main(void)
{
    char line1[16] = "Temperature:";
    char line2[16] = "114.514 .C";
    float temp = 0;
    int i      = 0;
    line2[8]   = DEGREE_SYMBOL;

    // Initialize
    P0 = 0x00; // Clear P0, reset buzzer
    lcd_init();
    uart_init();
    lcd_print("STARTING .........", "WELCOME!!!!!!");
    uart_println("Program Initialized Successfully!");
    lcd_clear();

    while (1) {
        temp = 0;
        for (i = 0; i < AVE_TIMES; i++) {
            temp += read_temp(TEMP_SENSOR);
        }
        temp /= AVE_TIMES;
        float2str(temp, line2);
        lcd_print(line1, line2);
        uart_print("Temperature: ");
        uart_println(line2);
        delay1s();
    }
}