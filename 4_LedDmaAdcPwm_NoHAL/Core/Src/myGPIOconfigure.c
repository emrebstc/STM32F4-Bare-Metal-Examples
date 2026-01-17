#include "myGPIOconfigure.h"


void myGPIOinit(void)
{

//*********************************************************************
	                     // GPID PD12 (Timer4 CH1) "Green Led" Configure
	HWREG(0x40023800 + 0x30) |= (1U << 3);  // RCC_AHB1ENR BUS GPIOD Clock Enable "1"
    for (volatile int i = 0; i < 1000; i++){};

	GPIOD_MODER &= ~(3U << 24); // Masking
	GPIOD_MODER |= (2U << 24); // choose Output Mode as Alternate Function "10" for PD12

	GPIOD_AFRH  &= ~(15U << 16); // Masking
	GPIOD_AFRH  |= (2U << 16); // choose Output Mode as Alternate Function  AF2 for PD12

	GPIOD_OTYPER &= ~(1U << 12); // 0: Output push-pull (reset state)

	GPIOD_OSPEEDR &= ~(3U << 24);
	GPIOD_OSPEEDR |= (1U << 24); // 01: Medium speed

	GPIOD_PUPDR &= ~(3U << 24); // 00: No pull-up and pull-down
//*********************************************************************
                  // GPIA PA0 (ADC1 CH0)  Configure
    HWREG(0x40023800 + 0x30) |= (1U << 0);  // RCC_AHB1ENR BUS GPIOA Clock Enable "1"
    for (volatile int i = 0; i < 1000; i++){};

    GPIOA_MODER &= ~(3U << 0); // Masking
    GPIOA_MODER |= (3U << 0); // 11: Analog mode for PA0

    GPIOA_PUPDR &= ~(3U << 0); // 00: No pull-up and pull-down

}
