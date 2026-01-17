#  STM32F4 Bare-Metal Examples 

This repository contains **bare-metal STM32F4 examples** developed **without HAL and without CubeMX**.

All peripherals are configured using **direct register-level programming**.

Some code and the comment lines next to it may not match exactly; a few comment lines are sometimes overlooked during copy-paste, but the core logic is always correct.

* STM32F4 Series (tested on STM32F407VGT6)
* ARM Cortex-M4

---

##  Development Tools

* STM32CubeIDE
* ARM-GCC
* Git & GitHub

---

##  Project List

---

## 1_LedBlinkTimerInt_NoHAL

**Purpose:**
Basic timer and interrupt usage.

**Description:**
This project configures a hardware timer to generate periodic interrupts.
Inside the timer ISR, an LED is toggled.

**Features:**

* Timer-based interrupt generation
* No delay loops
* Fully interrupt-driven
* Bare-metal register configuration

**What is demonstrated:**

* RCC clock enabling
* Timer prescaler and auto-reload calculation
* NVIC interrupt enabling
* Interrupt service routine design

---

## 2_LedButtonInt_NoHAL

**Purpose:**
External interrupt (EXTI) usage.

**Description:**
A push button is connected to a GPIO pin.
An external interrupt is generated on button press and the LED state is changed inside the EXTI ISR.

**Features:**

* GPIO input and output configuration
* EXTI line configuration
* NVIC interrupt handling
* Edge-triggered interrupt control

**What is demonstrated:**

* SYSCFG and EXTI mapping
* Rising and falling edge selection
* Interrupt flag handling
* Debounce-free event detection

---

## 3_LedPwmDrive_NoHAL

**Purpose:**
PWM signal generation using a timer.

**Description:**
TIM4 Channel 1 is configured to generate a PWM signal on pin **PD12**.
The duty cycle controls the LED brightness.

**Configuration:**

* Timer: TIM4
* Channel: CH1
* Pin: PD12
* PWM Mode: 1
* Frequency: 1 kHz
* Duty Cycle: 25%

**Features:**

* Timer PWM mode configuration
* CCR and ARR based duty control
* Alternate function GPIO usage
* Hardware-based signal generation

**What is demonstrated:**

* Timer compare mode registers
* Output compare preload
* PWM timing calculations
* GPIO alternate function mapping

---

## 4_LedDmaAdcPwm_NoHAL

**Purpose:**
ADC, DMA and PWM interaction.

**Description:**
A potentiometer is connected to **ADC1 Channel 0 (PA0)**.
The ADC runs in continuous conversion mode and transfers data to memory using **DMA (Peripheral-to-Memory)**.

The converted analog value is used to update the **TIM4 PWM duty cycle in real time**, without CPU polling.

**Configuration:**

* ADC: ADC1
* Channel: CH0
* Pin: PA0
* DMA: DMA2 Stream 0
* DMA Mode: Circular
* Data Width: 16-bit
* Timer: TIM4
* PWM Output Pin: PD12

**Features:**

* ADC continuous conversion

* DMA circular buffering

* Peripheral-to-memory data transfer

* Hardware-driven PWM update

* No CPU blocking and no polling loop

**What is demonstrated:**

* ADC sampling configuration
* DMA stream and channel mapping
* Memory and peripheral data sizing
* Circular mode operation
* Real-time control using ADC, DMA and Timer

---

##  Philosophy

* No HAL
* No abstraction layers
* Full control of hardware
* Register-level understanding

---

**Author:**
**Emre Bostancı**
