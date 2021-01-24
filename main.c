#include <stdio.h>
#include "stm32f10x.h"

#define DoNothing 

int main()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH |= GPIO_CRH_MODE13;
	GPIOC->CRH &= ~GPIO_CRH_CNF13;
	long counter = 0;
	while (1)
	{
		GPIOC->BSRR ^= GPIO_BSRR_BS13;
		while (counter <= 2000000)
		{
			counter++;
		}
		counter = 0;
		GPIOC->BSRR ^= GPIO_BSRR_BR13;
		while (counter <= 2000000)
		{
			counter++;
		}
		counter = 0;
	}
		return 0;
}
