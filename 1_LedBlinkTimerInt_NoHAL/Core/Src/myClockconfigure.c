#include "myClockconfigure.h"
#include "stdint.h"

//1) PWR clock ON
//2) VOS Config
//3) HSE ON + wait
//4) PLL Config (M N P Q)
//5) FLASH latency + cache
//6) AHB / APB prescaler settings
//7) PLL ON + wait
//8) SYSCLK = PLL choose PLL
//9) SYSCLK switch wait

static inline void __disable_irq(void)
{
    __asm volatile ("cpsid i" : : : "memory");
}

void Error_Handler(void)
{
    __disable_irq();   // Kesmeleri kapat (opsiyonel)
    while (1)
    {
        // Sonsuz döngüde kal, hata durumunu işaretlemek için buraya LED yakma kodu da ekleyebilirsin
    }
}


void mySystemclock(void)
{
//Configure	for SYSCLK (HCLK) to 144MHZ

	uint32_t timeout = 1000000;


	RCC_APB1ENR |= (1U << 28); // APB1 BUS on for PWR

	PWR_CR |= (1U << 14); // VOS = 1 "Scale 1"

	while (!(PWR_CSR & (1U << 14)))  // while VOSRDY's not equal to 1
	{
	    if (--timeout == 0)
	    {
	    	Error_Handler();
	    }
	}


	 timeout = 1000000;


	RCC_CR |= (1U << 16); // HSEON = 1;

	while (!(RCC_CR & (1U << 17))) // while HSERDY's not equal to 1
	{
	    if (--timeout == 0)
	    {
	    	Error_Handler();
	    }
	}

	RCC_PLLCFGR |= (1U << 22); // PLLSRC = HSE

	RCC_PLLCFGR &= ~(0x3FU << 0); // Clear from 0 to 5th bits , PLLM[5:0] = 0
	RCC_PLLCFGR |= (4U << 0);      // PLLM = 4

	RCC_PLLCFGR &= ~(0x1FFU << 6);   // Clear from 6 to 14th bits (9 bit total) , PLLN[14:6] = 0
	RCC_PLLCFGR |= (144U << 6);     // PLLN = 144

	RCC_PLLCFGR &= ~(0x03U << 16);   // Clear from 16 to 17th bits (2 bit total) , PLLP[17:16] = 0 , 00 for
	                                 // PLLP = 2

	RCC_PLLCFGR &= ~(0x0FU << 24);   // Clear from 24 to 27th bits (4 bit total) , PLLQ[27:24] = 0
	RCC_PLLCFGR |= (6U << 24);      // PLLQ = 6


	FLASH_ACR &= ~(0x07 << 0);  // Wait for 4 Wait State
	FLASH_ACR |= (4 << 0);

	RCC_CFGR  &= ~(0x0F << 4);  // HPRE (AHB) Prescaler for /1 = 0 x x x

	RCC_CFGR &= ~(0x07 << 10);  // PPRE1: APB Low speed prescaler (APB1)
	RCC_CFGR |= (5 << 10);     //  APB1 prescaler =  /4

	RCC_CFGR &= ~(0x07 << 13);  // PPRE2: APB Low speed prescaler (APB2)
    RCC_CFGR |= (4 << 13);     //  APB2 prescaler =  /2


	RCC_CR |= (1U << 24); // PLLON

	 timeout = 1000000;

	while (!(RCC_CR & (1U << 25))) // while PLLRDY's not equal to 1
		{
		    if (--timeout == 0)
		    {
		      Error_Handler();
		    }
		}

	RCC_CFGR &= ~(0x03 << 0); // System clock switch
	RCC_CFGR |= (2U << 0);    // Choose PLL for Source Clock

	 timeout = 1000000;

	 while (!((RCC_CFGR & (0x3 << 2)) == (0x2 << 2)))
	 {
	     if (--timeout == 0)
	     {
	    	 Error_Handler();
	     }
	 }


}


