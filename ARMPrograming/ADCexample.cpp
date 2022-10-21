#include "main.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
	 uint16_t raw;
	 char msg[10];
   while (1)
   {
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET); //For oscilloscope debug

	  //Get ADC value
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	  raw = HAL_ADC_GetValue(&hadc1);

	  //Test: SET GPIO pin LOW
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET); //For oscilloscope debug

	  //Convert to string and print
	  sprintf(msg, "%hu\r\n", raw);
	  HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	  HAL_Delay(1);
   }
}
