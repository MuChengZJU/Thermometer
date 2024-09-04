/**
 * @file buzzer.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-04
 * 
 * 
 */

#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "utils.h"

/**
 * @brief 1ms 的占空比可调的蜂鸣器脉冲
 * 
 * @param duty_ratio 占空比，取值范围 0-100
 */
void buzzer_pulse(uint duty_ratio);

/**
 * @brief 单纯的蜂鸣器关闭
 * 
 */
void buzzer_off();

#endif