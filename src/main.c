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

int main(void)
{
    char line1[16] = "Temperature:";
    char line2[16] = "114.514 C";
    uint temp = 0;

    // Initialize
    P0 = 0x00;   // Clear P0, reset buzzer
    lcd_init();  // LCD Initialize
    lcd_print(line1, line2);
    uart_init(); // UART Initialize
    

    // Debug UART
    uart_println("Program Initialized Successfully!");

    // Main Loop

    while (1)
    {
        // Temperature Reading
        temp = read_ambient_temp();
        temp2str(temp, line2);
        lcd_print(line1, line2);
        uart_print("Temperature: ");
        uart_println(line2);
        delay_ms(1000);
    }

    return 0;
}