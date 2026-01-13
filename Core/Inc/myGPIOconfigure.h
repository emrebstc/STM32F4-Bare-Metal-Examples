#ifndef INC_MYGPIOCONFIGURE_H_
#define INC_MYGPIOCONFIGURE_H_

#include "stdint.h"

#define GPIOD_Base 0x40020C00 //For Activate Internal Green LED's Port
#define GPIOD_MODER (*(volatile uint32_t *)(GPIOD_Base + 0x00)) // GPIOx_MODER PORTD Offset = 0x00
#define GPIOD_OTYPER (*(volatile uint32_t *)(GPIOD_Base + 0x04)) // Offset = 0x04
#define GPIOD_OSPEEDR (*(volatile uint32_t *)(GPIOD_Base + 0x08))
#define GPIOD_PUPDR (*(volatile uint32_t *)(GPIOD_Base + 0x0C))
#define GPIOD_ODR (*(volatile uint32_t *)(GPIOD_Base + 0x14))

#define HWREG(x) (*(volatile uint32_t *)(x))

void myGPIOinit(void);

#endif /* INC_MYGPIOCONFIGURE_H_ */
