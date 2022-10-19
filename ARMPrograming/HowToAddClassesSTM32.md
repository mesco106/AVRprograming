How to add classes with headers in STM32IDE

1. Create the logic inside the src folder. For example led.cpp:

#include "led.h"
#include "main.h"

void LED::toggle(void){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

2. Create your header inside the Inc folder. For example led.h:

#ifndef INC_LED_H_
#define INC_LED_H_

class LED {
public:
	void toggle(void);
};

#endif /* INC_LED_H_ */

3. Add the header in your main.cpp:

#include "led.h"

4. Run and copile your code. It should work with no problems. In the case of errors, check if any headers is missing.
