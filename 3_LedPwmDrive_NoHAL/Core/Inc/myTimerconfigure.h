
// Conf Timer 4
#ifndef INC_MYTIMERCONFIGURE_H_
#define INC_MYTIMERCONFIGURE_H_

#include "stdint.h"

#define TIM4_Base 0x40000800 //TIMx_Base for timer 4
#define TIM4_CR1 (*(volatile uint32_t*)(TIM4_Base + 0x00))
#define TIM4_PSC (*(volatile uint32_t*)(TIM4_Base + 0x28)) //TIMx_PSC for timer 4
#define TIM4_ARR (*(volatile uint32_t*)(TIM4_Base + 0x2C))
#define TIM4_CCR1 (*(volatile uint32_t*)(TIM4_Base + 0x34)) //Set the PWM Duty Value of Channel 1 of Timer
#define TIM4_CCMR1 (*(volatile uint32_t*)(TIM4_Base + 0x18)) // OC2M[2:0]: Output compare 2 mode = "110" PWM mode1
#define TIM4_EGR (*(volatile uint32_t*)(TIM4_Base + 0x14))
#define TIM4_CCER (*(volatile uint32_t*)(TIM4_Base + 0x20))
#define TIM4_DIER (*(volatile uint32_t*)(TIM4_Base + 0x0C))
#define TIM4_SR (*(volatile uint32_t*)(TIM4_Base + 0x10))
#define NVIC_ISER0 (*(volatile uint32_t*)(0xE000E100)) // Timer4 is 30th in IRQ list

#define HWREG(x) (*((volatile uint32_t *)(x)))

void myTimerinit(void);
void TIM4_IRQHandler(void);

#endif /* INC_MYTIMERCONFIGURE_H_ */
