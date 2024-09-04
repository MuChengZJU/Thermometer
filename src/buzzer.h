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
 * @brief 1ms ��ռ�ձȿɵ��ķ���������
 * 
 * @param duty_ratio ռ�ձȣ�ȡֵ��Χ 0-100
 */
void buzzer_pulse(uint duty_ratio);

/**
 * @brief �����ķ������ر�
 * 
 */
void buzzer_off();

#endif