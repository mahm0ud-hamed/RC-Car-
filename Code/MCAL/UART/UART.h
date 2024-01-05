/*
 * UART.h
 *
 * Created: 
 *  Author: Mahmoud Hamed
 */ 


#ifndef UART_H_
#define UART_H_
#include "../../service/MCU_config.h"
#include "../../service/std_types_MT.h"
#include "../../service/external_interrupts.h"

#define BAUD_RATE 9600


//UART INIT FUNCITON 
void UART_Init( unsigned int baud );


void UART_Transmit( unsigned char data );

// this function will enable the RX complete interrupt 
// also enable global interrupt 
void UART_RXC_interruptEnable();

unsigned char UART_Receive( void );

void UART_sendString(sint8_t*str);

//call back function to the RX complete 
void UART_setCallBack( void (*p2f) (void) );


#endif /* UART_H_ */