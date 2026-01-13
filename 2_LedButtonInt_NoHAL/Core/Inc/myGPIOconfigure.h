#ifndef INC_MYGPIOCONFIGURE_H_
#define INC_MYGPIOCONFIGURE_H_

#include "stdint.h"
#define HWREG(x) (*(volatile uint32_t *)(x))

#define RCC_BASE_reg   0x40023800UL // RCC ControlRegister Base Address
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE_reg + 0x30)) // PORTA and PORTD Clock Activate on AHB1ENR bus
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE_reg + 0x44)) // SYSCFG Clock Activate on APB2 bus

#define GPIOD_Base 0x40020C00 // Activate Internal Green LED's Port (PORTD)
#define GPIOD_MODER (*(volatile uint32_t *)(GPIOD_Base + 0x00)) // GPIOx_MODER PORTD Offset = 0x00
#define GPIOD_OTYPER (*(volatile uint32_t *)(GPIOD_Base + 0x04)) // Offset = 0x04
#define GPIOD_OSPEEDR (*(volatile uint32_t *)(GPIOD_Base + 0x08))
#define GPIOD_PUPDR (*(volatile uint32_t *)(GPIOD_Base + 0x0C))
#define GPIOD_ODR (*(volatile uint32_t *)(GPIOD_Base + 0x14))

#define GPIOA_Base 0x40020000 // Activate User Button's Port (PORTA)
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_Base + 0x00))
#define GPIOA_IDR (*(volatile uint32_t *)(GPIOA_Base + 0x10)) // GPIOx_IDR
#define SYSCFG_Base 0x40013800
#define SYSCFG_EXTICR1 (*(volatile uint32_t *)(SYSCFG_Base + 0x08)) // SYSCFG external interrupt configuration register 1
#define EXTI_Base 0x40013C00
#define EXTI_IMR (*(volatile uint32_t *)(EXTI_Base + 0x00))
#define EXTI_RTSR (*(volatile uint32_t *)(EXTI_Base + 0x08))
#define EXTI_FTSR (*(volatile uint32_t *)(EXTI_Base + 0x0C))
#define EXTI_PR (*(volatile uint32_t *)(EXTI_Base + 0x14))
#define NVIC_ISER0 (*(volatile uint32_t *)(0xE000E100)) // Set/Enable IRQs (0 - 31) on vector table



void EXTI0_IRQHandler(void);
void myGPIOinit(void);

#endif /* INC_MYGPIOCONFIGURE_H_ */
