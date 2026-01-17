#ifndef INC_MYADCCONFIGURE_H_
#define INC_MYADCCONFIGURE_H_

#include "stdint.h"
#define HWREG(x) (*(volatile uint32_t *)(x))
#define ADC_Base 0x40012000
#define ADC_CR2 (*(volatile uint32_t*)(ADC_Base + 0x08))
#define ADC_DR (*(volatile uint32_t*)(ADC_Base + 0x4C))
#define ADC_SMPR2 (*(volatile uint32_t*)(ADC_Base + 0x10))
#define ADC_SQR1 (*(volatile uint32_t*)(ADC_Base + 0x2C))
#define ADC_SQR3 (*(volatile uint32_t*)(ADC_Base + 0x34))


#define ADC_BUF_LEN   1
extern uint16_t adc_buffer[ADC_BUF_LEN];

void myADCinit(void);

#endif /* INC_MYADCCONFIGURE_H_ */
