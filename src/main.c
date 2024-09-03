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
#include "lcd1602.h"

int main(void)
{
    int i;
    char line1[16] = "Temperature:";
    char line2[16] = "114.514 C";
    // MCU Init
    P0 = 0x00; // Clear P0, reset buzzer
    // lcd_init(); // Initialize LCD
    lcd_init();

    // Temperature Reading

    // LCD Print
    for (i = 0; i < 100; i++) {
        
        lcd_print(line1, line2);
    }

    while (1); // Infinite loop

    return 0;
}