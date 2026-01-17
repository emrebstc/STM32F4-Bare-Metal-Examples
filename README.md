# STM32F4 Bare-Metal Examples

This repository contains **bare-metal STM32F4 examples** developed **without HAL and without CubeMX**.


- STM32F4 Series (tested on STM32F407VGT6)
- ARM Cortex-M4

---

## Development Tools

- STM32CubeIDE  
- ARM-GCC  
- Git & GitHub  

---

## Project List

---

## 1_LedBlinkTimerInt_NoHAL

**Purpose:**  
Basic timer + interrupt usage.

**Description:**  
This project configures a hardware timer to generate periodic interrupts.  
Inside the timer ISR, an LED is toggled.

**Features:**
- Timer-based interrupt generation  
- No delay loops  
- Fully interrupt-driven  
- Bare-metal register configuration  

**What is demonstrated:**
- RCC clock enabling  
- Timer prescaler & auto-reload calculation  
- NVIC interrupt enabling  
- Interrupt service routine design  

---

## 2_LedButtonInt_NoHAL

**Purpose:**  
External interrupt (EXTI) usage.

**Description:**  
A push button is connected to a GPIO pin.  
An external interrupt is generated on button press and the LED state is changed inside the EXTI ISR.

**Features:**
- GPIO input/output configuration  
- EXTI line configuration  
- NVIC interrupt handling  
- Edge-triggered interrupt control  

**What is demonstrated:**
- SYSCFG + EXTI mapping  
- Rising/Falling edge selection  
- Interrupt flag handling  
- Debounce-free event detection  

---

## 3_LedPwmDrive_NoHAL

**Purpose:**  
PWM signal generation using a timer.

**Description:**  
TIM4 Channel 1 is configured to generate a PWM signal on pin **PD12**.  
The duty cycle controls the LED brightness.

**Configuration:**
- Timer: TIM4  
- Channel: CH1  
- Pin: PD12  
- PWM Mode: 1  
- Frequency: 1 kHz  
- Duty Cycle: 25%  

**Features:**
- Timer PWM mode configuration  
- CCR/ARR based duty control  
- Alternate function GPIO usage  
- Hardware-based signal generation  

**What is demonstrated:**
- Timer compare mode registers  
- Output compare preload  
- PWM timing math  
- GPIO alternate function mapping  

---

## Philosophy

- No HAL  
- No abstraction layers  

---

**Author:**  
**Emre Bostancı**
