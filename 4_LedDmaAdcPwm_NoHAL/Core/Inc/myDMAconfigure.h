#ifndef INC_MYDMACONFIGURE_H_
#define INC_MYDMACONFIGURE_H_

#include "stdint.h"
#define HWREG(x) (*(volatile uint32_t *)(x))
#define DMA2_Base 0x40026400
#define DMA2_LISR (*(volatile uint32_t*)(DMA2_Base + 0x00))
#define DMA2_LIFCR (*(volatile uint32_t*)(DMA2_Base + 0x08))
#define DMA2_SxCR (*(volatile uint32_t*)(DMA2_Base + 0x10)) // for Stream 0
#define DMA2_SxPAR (*(volatile uint32_t*)(DMA2_Base + 0x18)) // for Stream 0
#define DMA2_SxM0AR (*(volatile uint32_t*)(DMA2_Base + 0x1C)) // for Stream 0
#define DMA2_SxNDTR (*(volatile uint32_t*)(DMA2_Base + 0x14)) // for Stream 0
#define NVIC_ISER1   (*(volatile uint32_t*)0xE000E104)
#define NVIC_IPR_BASE 0xE000E400
#define NVIC_IPR56 (*(volatile uint8_t*)(NVIC_IPR_BASE + 56))

void myDMAinit(void);

#endif /* INC_MYDMACONFIGURE_H_ */
