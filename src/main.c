/**
 * @file main.c
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Main program of Thermometer
 * @version 0.1
 * @date 2024-09-02
 *
 *
 */

#include "utils.h"
#include "lcd1602.h"
#include "uart.h"
#include "gy906.h"
#include "buzzer.h"

#define TEMP_SENSOR   1 // 1 for TOBJ1, 0 for AMBIENT
#define AVE_TIMES     10
#define BUZZER_VOLUME 100
#define TL0_RELOAD    0xF0
#define TH0_RELOAD    0xD8

uint g_timer0_cnt     = 0;
uint g_timer0_cnt_max = 100;
sbit BUZZER = P0 ^ 0;

void Timer0_Init(void) // 10毫秒@11.0592MHz
{
    TMOD &= 0xF0; // 设置定时器模式
    TMOD |= 0x01; // 设置定时器模式
    TH0 = TH0_RELOAD;
    TL0 = TL0_RELOAD;
    TF0 = 0; // 清除TF0标志
    TR0 = 1; // 定时器0开始计时
}

void Timer0_ISR(void) interrupt 1
{
    TH0 = TH0_RELOAD;
    TL0 = TL0_RELOAD;
    g_timer0_cnt++;
    // lcd_print("timerinterrupt", ""); // DEBUG
    if (g_timer0_cnt >= g_timer0_cnt_max) {
        g_timer0_cnt = 0;
        // lcd_print("timercnt", ""); // DEBUG
        buzzer_pulse(BUZZER_VOLUME);
    }
}

void main(void)
{
    // Variables
    char line1[16]   = "Temperature:";
    char line2[16]   = "114.514 .C";
    float temp       = 0;
    int i            = 0;

    // Initialize
    line2[8] = DEGREE_SYMBOL;
    buzzer_off();
    lcd_init();
    uart_init();
    Timer0_Init(); // 初始化定时器0
    EA = 1;        // 使能全局中断
    ET0 = 1;       // 设置INT0中断类型

    // Start Information
    lcd_print("STARTING .........", "WELCOME!!!!!!");
    uart_println("Program Initialized Successfully!");
    lcd_clear();

    // Main Loop
    while (1) {
        // 测温并显示
        temp = 0;
        for (i = 0; i < AVE_TIMES; i++) {
            temp += read_temp(TEMP_SENSOR);
        }
        temp /= AVE_TIMES;
        float2str(temp, line2);
        lcd_print(line1, line2);

        // 串口输出温度
        uart_print("Temperature: ");
        uart_println(line2);

        // 蜂鸣器脉冲
        if (temp <= 1) {
            g_timer0_cnt_max = 500;
        } else if (temp > 1 && temp <= 37) {
            g_timer0_cnt_max = (int)(-13.61 * temp + 513.61);
        } else if (temp > 37 && temp <= 100) {
            g_timer0_cnt_max = (int)(-0.1428 * temp + 15.29);
        } else {
            g_timer0_cnt_max = 1;
        }

        delay1s();
    }
}
