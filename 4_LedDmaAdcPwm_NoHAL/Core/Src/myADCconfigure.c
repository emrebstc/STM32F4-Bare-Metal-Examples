#include "myADCconfigure.h"


void myADCinit(void){

	HWREG(0x40023800 + 0x44) |= (1U << 8);  // ADC1 Clock Enable "1" on RCC_APB2ENR BUS
    for (volatile int i = 0; i < 1000; i++);

    ADC_CR2 &= ~(3U << 28); // EXTEN = 00 (disabled)

    ADC_CR2 &= ~(1U << 11); // Bit 11 ALIGN: Data alignment , 0: Right alignment

    ADC_CR2 |= (1U << 9); //  Bit 9 DDS: DMA disable selection (for single ADC mode) ,1: DMA requests are issued

    ADC_CR2 |= (1U << 8);  // DMA Enable

    ADC_CR2 |= (1U << 1);  // Bit 1 CONT: Continuous conversion

	ADC_SMPR2 &= ~(7U << 0); // CH0 Mask
    ADC_SMPR2 |= (4U << 0); // 100: 84 cycles ,  sample time register 2

    ADC_SQR1 &= ~(15U << 20); // L = 0 > 1 conversion (CH0 only)

    ADC_SQR3 &= ~(31U << 0); // SQ1 = CH0

    ADC_CR2 |= (1U << 0); // ADON = 1 , A/D Converter ON
    for(volatile int i=0;i<1000;i++);

    ADC_CR2 |= (1U << 30); // 1: Continuous conversion Bit 30 SWSTART: Start conversion of regular channels.
}
