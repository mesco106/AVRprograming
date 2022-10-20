#include "main.h"
#include <string.h>
#include <stdio.h>

static const uint8_t LM75A_ADDR = 0x48 << 1;
static const uint8_t REG_TEMP = 0x00;

int main(void) {
  /* USER CODE BEGIN 1 */
	HAL_StatusTypeDef ret;
	uint8_t buf[12];
	int16_t val;
	float temp_c;
}

while (1)
  {
	  // Tell LM75A that we want to read from the temperature sensor
	  buf[0] = REG_TEMP;
	  ret = HAL_I2C_Master_Transmit(&hi2c1, LM75A_ADDR, buf, 1, HAL_MAX_DELAY);
	  if ( ret != HAL_OK){
		  strcpy((char*)buf, "Error Tx\r\n");
	  } else {

		  //Read 2 bytes from the temperature register
		  ret = HAL_I2C_Master_Receive(&hi2c1, LM75A_ADDR, buf, 2, HAL_MAX_DELAY);
		  if (ret != HAL_OK){
			  strcpy((char*)buf, "Error Rx\r\n");
		  } else {

			  //Combine the bytes
			  val = ((int16_t)buf[0] << 4) | (buf[1] >> 4);

			  //Convert to 2's complement, since temperature can be negative
			  if ( val > 0x7FF) {
				  val |= 0xF000;
			  }

			  //Convert to float temperature value (Celsius)
			  temp_c = val * 0.0625;

			  //Convert temperature to decimal format
			  temp_c *= 100;
			  sprintf((char*)buf,
					  "%u.%02u C\r\n",
					  ((unsigned int)temp_c / 100),
					  ((unsigned int)temp_c % 100));
		  }
	  }

	  //strcpy((char*)buf, "Hello!\r\n");
	  HAL_UART_Transmit(&huart2, buf, strlen((char*)buf), HAL_MAX_DELAY);
	  HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
