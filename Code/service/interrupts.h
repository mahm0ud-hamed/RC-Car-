/*
 * interrupts.h
 *  Author: Mahmoud Hamed 
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3
/*Timer2 Compare Handler*/
#define TIM2_COMP __vector_4
/*Timer2 Overflow Handler */
#define TIM2_OVF __vector_5


// enable global interrupts
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// disable global interrupts
#define cei() __asm__ __volatile__ ("cei" ::: "memory")

/* Macro defines the ISR */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)





#endif /* INTERRUPTS_H_ */