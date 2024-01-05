/*
 * external_interrupts.h
 *
 *  Author: Mahmoud Hamed
 */ 


#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#include "MCU_config.h"
#include "interrupts.h"

typedef enum{
	low_level_sense,
	anyLogicChange_sense,
	falling_edge_sense,
	rising_edge_sense
	}EN_interrupt_sense_t;

// external interrupt 0 initialization 
void EXT_INT_0_init(EN_interrupt_sense_t sense);
// external interrupt 1 initialization
void EXT_INT_1_init(EN_interrupt_sense_t sense);
// external interrupt 2 initialization
void EXT_INT_2_init(EN_interrupt_sense_t sense);




#endif /* EXTERNAL_INTERRUPTS_H_ */