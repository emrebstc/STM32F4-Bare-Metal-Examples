\# STM32F4 Bare-Metal Examples



This repository contains \*\*bare-metal STM32F4 examples\*\* developed \*\*without HAL or CubeMX\*\*.

All peripherals are configured using \*\*direct register-level programming\*\*.



\##  # Target MCU

\- STM32F4 series (e.g. STM32F407)

\- ARM Cortex-M4



\##  # Project Structure



\###  Led Blink (Timer Interrupt)

\*\*Path:\*\* `1\_LedBlinkTimerInt\_NoHAL`

\- Timer-based LED blinking

\- No HAL

\- Interrupt-driven



\###  Button Interrupt

\*\*Path:\*\* `2\_LedButtonInt\_NoHAL`

\- External interrupt (EXTI)

\- Button-controlled LED

\- Bare-metal configuration



\###  PWM LED Driver (TIM4)

\*\*Path:\*\* `3\_LedPwmDrive\_NoHAL`

\- Timer: TIM4

\- Channel: CH1

\- Pin: PD12

\- Frequency: 1 kHz

\- Duty Cycle: 25%

\- PWM Mode 1

\- Fully bare-metal (no HAL)



\##  # Tools

\- STM32CubeIDE

\- ARM-GCC

\- Git \& GitHub



---



&nbsp;Author: \*\*Emre Bostancı\*\*



