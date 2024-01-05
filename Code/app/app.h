/*
 * app.h
 *
 * 
 *  Author: Mahmoud Hamed 
 */ 


#ifndef APP_H_
#define APP_H_

#include "../MCAL/DIO/DIO.h"
#include "../service/std_types_MT.h"
#include "../service/MCU_config.h"
#include "../service/std_types_MT.h"
#include "../HAL/CAR/car.h"
#include "../MCAL/UART/UART.h"

void app_init();
void app_start();
uint8_t sens_comp(uint8_t s1,uint8_t s2);


#endif /* APP_H_ */