#include "myTimerconfigure.h"
#include "myGPIOconfigure.h"


// Configure Timer 4 CH1 "16 bit" for generate PWM signal on PD12 (Green Led)
void myTimerinit(void)
{

	HWREG(0x40023800 + 0x40) |= (1U << 2);  // RCC_APB1ENR BUS TIMER4 Clock Enable "1"
    for (volatile int i = 0; i < 1000; i++);

    // T = ((PSC + 1) / F_clk)  *  (ARR + 1)

    TIM4_PSC = (83U << 0);

    TIM4_ARR = (999U << 0); // 1000000 / (ARR + 1) = 1000

    // Duty = CCR1 / (ARR + 1)

    TIM4_CCR1 = (249U << 0); // %25 PWM on CH1

    TIM4_CR1 |= (1U << 2);   // URS: Only overflow generates update event

    TIM4_CCMR1 &= ~(7U << 4); // Mask OC1M in CCMR1
    TIM4_CCMR1 |= (6U << 4); // Set "110" as PWM mode 1 in OC1M

    TIM4_CCMR1 |= (1U << 3); // OC1PE = 1 , 1: Preload register on TIMx_CCR1 enabled

    TIM4_CR1 |= (1U << 7); // ARPE: Auto-reload preload enable ,   1: TIMx_ARR register is buffered

    TIM4_EGR |= (1U << 0); // UG:Update generation,1: Re-initialize the counter and generates an update of the register.

    TIM4_CCER &= ~(1U << 1); // CC1P: Capture/Compare 1 output Polarity , 0: OC1 active high

    TIM4_CCER |= (1U << 0); // CC1E = 1 , CH1 output enable

    TIM4_CR1 &= ~(3U << 5); // CMS: Center-aligned mode selection, 00: Edge-aligned mode.

    TIM4_CR1 &= ~(1U << 4); // DIR bit = 0 , Up Counter
    TIM4_CR1 &= ~(1U << 3); // Continues Mode

    TIM4_CR1 |= (1U << 0); // Timer4 Enable
}

