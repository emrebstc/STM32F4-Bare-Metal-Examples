#ifndef INC_MYGPIOCONFIGURE_H_
#define INC_MYGPIOCONFIGURE_H_

#include "stdint.h"

#define HWREG(x) (*(volatile uint32_t *)(x))

#define GPIOD_Base 0x40020C00
#define GPIOD_MODER (*(volatile uint32_t *)(GPIOD_Base + 0x00))
#define GPIOD_OTYPER (*(volatile uint32_t *)(GPIOD_Base + 0x04))
#define GPIOD_OSPEEDR (*(volatile uint32_t *)(GPIOD_Base + 0x08))
#define GPIOD_AFRH (*(volatile uint32_t *)(GPIOD_Base +  0x24))
#define GPIOD_PUPDR (*(volatile uint32_t *)(GPIOD_Base + 0x0C))
#define GPIOD_ODR (*(volatile uint32_t *)(GPIOD_Base + 0x14))

#define GPIOA_Base 0x40020000
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_Base + 0x00))
#define GPIOA_AFRL (*(volatile uint32_t *)(GPIOA_Base +  0x20))
#define GPIOA_PUPDR (*(volatile uint32_t *)(GPIOA_Base + 0x0C))


void myGPIOinit(void);

#endif /* INC_MYGPIOCONFIGURE_H_ */
