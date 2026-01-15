#include "stdint.h"
#include "myDelayAndMore.h"


// PLL kaynağına göre giriş frekansını döner
uint32_t GetPLLSourceFreq(void)
{
    return (RCC_PLLCFGR & RCC_PLLCFGR_PLLSRC) ? HSE_VALUE : (HSI_VALUE / 2);
}

// Ana sistem clock frekansını hesaplar ve döner
uint32_t GetSysClockFreq(void)
{
    uint32_t sysclockfreq = 0;
    uint32_t pllm, plln, pllp;
    uint64_t pllvco;
    uint32_t sws = RCC_CFGR & RCC_CFGR_SWS;

    switch (sws)
    {
        case RCC_CFGR_SWS_HSI:
            sysclockfreq = HSI_VALUE;
            break;

        case RCC_CFGR_SWS_HSE:
            sysclockfreq = HSE_VALUE;
            break;

        case RCC_CFGR_SWS_PLL:
            pllm = (RCC_PLLCFGR & RCC_PLLCFGR_PLLM_Msk) >> RCC_PLLCFGR_PLLM_Pos;
            plln = (RCC_PLLCFGR & RCC_PLLCFGR_PLLN_Msk) >> RCC_PLLCFGR_PLLN_Pos;
            pllp = (((RCC_PLLCFGR & RCC_PLLCFGR_PLLP_Msk) >> RCC_PLLCFGR_PLLP_Pos) + 1) * 2;

            pllvco = ((uint64_t)GetPLLSourceFreq() * (uint64_t)plln) / pllm;

            sysclockfreq = (uint32_t)(pllvco / pllp);
            break;

        default:
            sysclockfreq = HSI_VALUE;
            break;
    }

    return sysclockfreq;
}

void mydelay(uint32_t ms)
{
    uint32_t tick_freq =  GetSysClockFreq();

    while (ms > 0)
    {
        uint32_t delay_ms = (ms > 100) ? 100 : ms;

        uint64_t tmp = (uint64_t)tick_freq * delay_ms;
        uint32_t reload_val = (uint32_t)(tmp / 1000) - 1;

        if (reload_val > MAX_RELOAD)
            reload_val = MAX_RELOAD;

        SYST_RVR = reload_val;
        SYST_CVR = 0;

        SYST_CSR = (1 << 0) | (1 << 2);

        while ((SYST_CSR & (1 << 16)) == 0);

        SYST_CSR &= ~(1 << 0);

        ms -= delay_ms;
    }
}
