/**
 * @file main.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Main program of Thermometer
 * @version 0.1
 * @date 2024-09-02
 * 
 * 
 */

#include "REG52.H"
#include "mlx90614.h"
#include "lcd_1602.h"

int main (void)
{
    // MCU Init
    P0 &= 0x00; // Clear P0, reset buzzer
    // lcd_init(); // Initialize LCD

    // Temperature Reading

    // LCD Print
    lcd_print();

    return 0;
}