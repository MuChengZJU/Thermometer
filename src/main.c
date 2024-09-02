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

int main (void)
{
    // MCU Init
    P0 &= 0x00; // Clear P0, reset buzzer


    // Temperature Reading
    float temp;
    SMBus_Init();
    while(1)
    {
        temp = SMBus_ReadTemp();
    }
    return 0;
}