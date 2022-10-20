 
#include <string.h>

int main(void)
{
  /* USER CODE BEGIN 1 */
	bool buttonState;
	char buffer[100];
	uint8_t i;
}

while (1)
  {
	  i += 1;
	  sprintf(buffer, "Hello World\r\n");
	  //sprintf(buffer, "%d\r\n", i);
	  HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 1000);
	  sprintf(buffer, "%d\r\n", i);
	  HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 1000);
	  buttonState = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	  if (buttonState == 1) {
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	  } else {
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		  i = 0;
	  }
	  HAL_Delay(100);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
