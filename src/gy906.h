/**
 * @file gy906.h
 * @author MuChengZJU (MuChengZJU@qq.com)
 * @brief Temperature sensor GY906 driver header file
 * @version 0.1
 * @date 2024-09-03
 * 
 * 
 */

#ifndef __GY906_H__
#define __GY906_H__

#include "utils.h"

uint read_ambient_temp(void);
void temp2str(uint temp, char *str);

#endif