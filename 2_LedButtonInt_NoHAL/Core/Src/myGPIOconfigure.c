#include "myGPIOconfigure.h"

//                                 You can use these 2 method
// 1) #define GPIOA_IDR (*(volatile uint32_t *)(0x40020010)) then GPIOA_IDR |= ......
//                                              OR
// 2) #define GPIOA_IDR_ADDR (0x40020010) then HWREG(GPIOA_IDR_ADDR) |= ......

void myGPIOinit(void)
{

//**********************************************************************************************************

	                     // GPIOD PD12 "Green Led" Output Configure

	RCC_AHB1ENR |= (1U << 3);  // GPIOD Clock Enable "1" AHB1ENR BUS on RCC
    for (volatile int i = 0; i < 1000; i++){}

	GPIOD_MODER &= ~(3U << 24); // Masking
	GPIOD_MODER |= (1U << 24); // choose Output Mode "01" for PD12

	// GPIOD_ODR >> >> GPIO port output data register, contain the output value of the corresponding I/O port.

	GPIOD_OTYPER &= ~(1U << 12); // 0: Output push-pull (reset state)

	GPIOD_OSPEEDR &= ~(3U << 24);
	GPIOD_OSPEEDR |= (1U << 24); // 01: Medium speed

	GPIOD_PUPDR &= ~(3U << 24); // 00: No pull-up and pull-down
//*********************************************************************************************************

                          // GPIOA PA0 "User Button" Input Configure

    RCC_AHB1ENR |= (1U << 0);  // GPIOA Clock Enable "1" AHB1ENR BUS
    for (volatile int i = 0; i < 1000; i++){}


    RCC_APB2ENR |= (1U << 14);  // SYSCFG Clock Enable "1" APB2 BUS on RCC
    for (volatile int i = 0; i < 1000; i++){}


    GPIOA_MODER &= ~(3U << 0); // 00: Input (reset state)

  // GPIOA_IDR >> GPIO port input data register, contain the input value of the corresponding I/O port.

    SYSCFG_EXTICR1 &= ~(15U << 0); // 0000: PA[x] pin and x=0 (PA0) then >> EXTIx[3:0] = EXTI0[3:0]

    EXTI_IMR |= (1U << 0); // 1: Interrupt request from line x is not masked

    EXTI_RTSR |= (1U << 0); // 1: Rising trigger enabled (for Event and Interrupt) for input line

    EXTI_FTSR |= (1U << 0); // 1: Falling trigger enabled (for Event and Interrupt) for input line.

  // EXTI_PR  >> 1: This bit is cleared by programming it to ‘1’, clear the flag of EXTI

    NVIC_ISER0 |= (1U << 6); // EXTI0 (position 6 on vector table) activate NVIC_ISER0 permission
//**********************************************************************************************************
}

void EXTI0_IRQHandler(void) // function on startup_stm32f407vgtx.s for PA0 "EXTI0"
{

    if (EXTI_PR & (1U << 0))
    {
        if (GPIOA_IDR & (1U << 0)) // Pushed?
        {
            GPIOD_ODR |= (1U << 12); // Turn on the LED
        }
        else // Released
        {
            GPIOD_ODR &= ~(1U << 12); // Turn on the LED
        }
        EXTI_PR |= (1U << 0); // Clear flag
    }
}
