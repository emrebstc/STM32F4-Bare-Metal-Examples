#include "myTimerconfigure.h"
#include "myGPIOconfigure.h"


// Configure Timer 4 "16 bit" for generate event "Toggle led" for every 1ms using interrupt
void myTimerinit(void)
{
	HWREG(0x40023800 + 0x40) |= (1U << 2);  // RCC_APB1ENR BUS TIMER4 Clock Enable "1"
    for (volatile int i = 0; i < 1000; i++);

    TIM4_CR1 &= ~(1U << 4); // Up Counter
    TIM4_CR1 &= ~(1U << 3); // Continues Mode

    // T = ((PSC + 1) / F_clk)  *  (ARR + 1)

    TIM4_PSC = (7199U << 0); // APB2 prescaler =  "/2"= 144/72 = 72Mhz" / (7199 + 1) = 10000 , 10000 cycle per second

    TIM4_ARR = (4999U << 0); // 10000 / (ARR + 1) = 0.5 second for toggle led

    TIM4_DIER |= (1U << 0); // UIE: Update interrupt enable

    NVIC_ISER0 |= (1U << 30); // Activate Timer 4 interrupt (IRQ 30)

    TIM4_CR1 |= (1U << 0); // Timer4 Enable
}

void TIM4_IRQHandler(void)
{
    if (TIM4_SR & (1U << 0))
    {
        TIM4_SR &= ~(1U << 0); // UIF: Update interrupt flag clear "0"

        GPIOD_ODR ^= (1U << 12); // Toggle Green LED PD12
    }
}
