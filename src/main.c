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

void main(void)
{
    char line1[16] = "Temperature:";
    char line2[16] = "114.514 C";
    uint temp = 0;

    // Initialize
    P0 = 0x00;   // Clear P0, reset buzzer
    lcd_init();
    uart_init();
    lcd_print("Sit back and relax", "STARTING .........");
    lcd_print(line1, line2);
    uart_println("Program Initialized Successfully!");

    // Main Loop

    while (1)
    {
        // Temperature Reading
        temp = read_temp(1);
        temp2str(temp, line2);
        lcd_print(line1, line2);
        uart_print("Temperature: ");
        uart_print_int(temp);
        uart_println(line2);
        delay_ms(1000);
    }

}