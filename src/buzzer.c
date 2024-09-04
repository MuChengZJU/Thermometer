/**
 * @file buzzer.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-04
 * 
 * 
 */

#include "buzzer.h"

sbit BUZZER = P0 ^ 0;

void buzzer_pulse(uint duty_ratio)
{
    uint i = 0;
    BUZZER = 1;
    for (i = 0; i < duty_ratio; i++) {
        delay_10us();
    }
    BUZZER = 0;
}

void buzzer_off()
{
    BUZZER = 0;
}


