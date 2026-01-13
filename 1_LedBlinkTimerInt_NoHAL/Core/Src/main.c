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


// if you dont wanna use timer you may use that codes below ( Configured for 144Mhz HCLK in mySystemclock(); )

//	  GPIOD_ODR |= (1U << 12); // GPIOx_ODR "output data register", GreenLed (PD12) Activate "1"
//    mydelay(500);
//	  GPIOD_ODR &= ~(1U << 12); // GreenLed (PD12) Deactivate "0"
//	  mydelay(500);

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
