#include "myDMAconfigure.h"
#include "myADCconfigure.h"
#include "myTimerconfigure.h"

uint16_t adc_buffer[ADC_BUF_LEN];

void myDMAinit(void){

	HWREG(0x40023800 + 0x30) |= (1U << 22);  // RCC_AHB1ENR BUS DMA2 Clock Enable "1" for ADC1
    for (volatile int i = 0; i < 1000; i++){};

    NVIC_ISER1 = (1U << (56 - 32));   // bit 24

    NVIC_IPR56 = 1 << 4;   // Priority = 1

    DMA2_SxCR &= ~(1U << 0); // EN: Stream enable , 0 : Stream disable
    while (DMA2_SxCR & 1);

    DMA2_SxCR &= ~(7U << 25); // CHSEL[2:0]: Channel selection , 000: channel 0 selected

    DMA2_SxCR &= ~(3U << 6); // DIR[1:0]: Data transfer direction, 00: Peripheral-to-memory

    DMA2_SxCR |= (1U << 4);   // TCIE: Transfer complete interrupt enable

    DMA2_SxCR |=  (1U << 8); // CIRC: Circular mode, 1: Circular mode enabled

    DMA2_SxCR &= ~(3U << 21); // PBURST[1:0]: Peripheral burst transfer configuration , 00: single transfer

    DMA2_SxCR &= ~(3U << 11);
    DMA2_SxCR |=  (1U << 11); // PSIZE[1:0]: Peripheral data size , 01: Half-word (16-bit) , "data value of ADC"

    DMA2_SxCR &= ~(3U << 13);
    DMA2_SxCR |=  (1U << 13);   // MSIZE[1:0]: Memory data size , 01: half-word (16-bit)

    DMA2_SxCR &= ~(1U << 10); // MINC: Memory increment mode , 0: Memory address pointer is fixed (1 element overwrite)

    DMA2_SxCR &= ~(1U << 5); // PFCTRL: Peripheral flow controller , 0: The DMA is the flow controller

    DMA2_SxPAR = (uint32_t)(ADC_Base + 0x4C); // DMA stream x peripheral address register , PAR[31:0]: Peripheral address

    DMA2_SxM0AR = (uint32_t)adc_buffer; // DMA stream x memory 0 address register , M0A[31:0]: Memory 0 address

    DMA2_SxNDTR = ADC_BUF_LEN; // DMA stream x number of data register , NDT[15:0]: Number of data items to transfer

    DMA2_SxCR |=  (1U << 0); // EN: Stream enable / flag stream ready when read low , 1: Stream enabled

}

void DMA2_Stream0_IRQHandler(void)
{
    if(DMA2_LISR & (1<<5))   // TCIF0
    {
        DMA2_LIFCR = (1<<5); // flag clear

        TIM4_CCR1 = (adc_buffer[0] * (TIM4_ARR + 1)) / 4095;
    }
}
