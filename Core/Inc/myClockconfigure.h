#ifndef INC_MYCLOCKCONFIGURE_H_
#define INC_MYCLOCKCONFIGURE_H_

#define RCC_BASE_reg   0x40023800UL //RCC Control Register Base Address
#define RCC_CR       (*(volatile uint32_t *)RCC_BASE_reg) // Offset = 0x00
#define RCC_APB1ENR  (*(volatile uint32_t *)(RCC_BASE_reg + 0x40)) // For give permission to PWR BUS
#define RCC_PLLCFGR  (*(volatile uint32_t *)(RCC_BASE_reg + 0x04))
#define RCC_CFGR     (*(volatile uint32_t *)(RCC_BASE_reg + 0x08))

#define PWR_BASE_reg    0x40007000
#define PWR_CR	   (*(volatile uint32_t *)PWR_BASE_reg) // Offset = 0x00
#define	PWR_CSR	   (*(volatile uint32_t *)(PWR_BASE_reg+0x04)) // Offset = 0x04

#define FLASH_BASE_reg 0x40023C00
#define FLASH_ACR  (*(volatile uint32_t *)(FLASH_BASE_reg)) //Offset = 0x00

void mySystemclock(void);

#endif /* INC_MYCLOCKCONFIGURE_H_ */
