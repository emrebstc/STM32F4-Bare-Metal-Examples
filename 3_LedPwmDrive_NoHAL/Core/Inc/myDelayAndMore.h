#ifndef INC_MYDELAYANDMORE_H_
#define INC_MYDELAYANDMORE_H_

#define HSI_VALUE 16000000U
#define HSE_VALUE 8000000U

#define RCC_BASE_reg   0x40023800UL
#define RCC_CR       (*(volatile uint32_t *)RCC_BASE_reg)         // Offset 0x00
#define RCC_PLLCFGR  (*(volatile uint32_t *)(RCC_BASE_reg + 0x04)) // Offset 0x04
#define RCC_CFGR     (*(volatile uint32_t *)(RCC_BASE_reg + 0x08)) // Offset 0x08
#define RCC_APB1ENR  (*(volatile uint32_t *)(RCC_BASE_reg + 0x40)) // Offset 0x40

#define RCC_CFGR_SWS          (0x3 << 2)
#define RCC_CFGR_SWS_HSI      (0x0 << 2)
#define RCC_CFGR_SWS_HSE      (0x1 << 2)
#define RCC_CFGR_SWS_PLL      (0x2 << 2)

#define RCC_PLLCFGR_PLLM_Pos  0
#define RCC_PLLCFGR_PLLM_Msk  (0x3F << RCC_PLLCFGR_PLLM_Pos)

#define RCC_PLLCFGR_PLLN_Pos  6
#define RCC_PLLCFGR_PLLN_Msk  (0x1FF << RCC_PLLCFGR_PLLN_Pos)

#define RCC_PLLCFGR_PLLP_Pos  16
#define RCC_PLLCFGR_PLLP_Msk  (0x3 << RCC_PLLCFGR_PLLP_Pos)

#define RCC_PLLCFGR_PLLSRC    (1 << 22)

#define SYST_CSR  (*(volatile uint32_t *)0xE000E010) // SysTick control status
#define SYST_RVR  (*(volatile uint32_t *)0xE000E014)
#define SYST_CVR  (*(volatile uint32_t *)0xE000E018)

#define MAX_RELOAD 0xFFFFFF

#include <stdint.h>

uint32_t GetPLLSourceFreq(void);
uint32_t GetSysClockFreq(void);
void mydelay(uint32_t ms);

#endif /* INC_MYDELAYANDMORE_H_ */
