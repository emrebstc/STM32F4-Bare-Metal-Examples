#include "main.h"
#include "myClockconfigure.h"
#include "myDelayAndMore.h"
#include "myTimerconfigure.h"
#include "myGPIOconfigure.h"


int main(void)
{

  mySystemclock();
  myGPIOinit();
  myTimerinit();

  while (1)
  {
	  // Configure Timer 4 CH1 "16 bit" for generate PWM signal on PD12 (Green Led)

		 /*
		     * Clock configuration:
		     * SYSCLK = 100 MHz
		     * APB1 prescaler = 4  → PCLK1 = 25 MHz
		     * TIM4 clock = 2 × PCLK1 = 50 MHz
		     *
		     * PWM frequency:
		     * Fpwm = TIM4_CLK / (PSC + 1) / (ARR + 1)
		     *      = 50 MHz / 100 / 500 = 1 kHz
		     */

  }

}





#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
