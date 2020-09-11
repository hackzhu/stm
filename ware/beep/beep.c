#include "beep.h"

void beepinit(void)
{
	RCC->APB2ENR|=1<<3;
	GPIOB->CRH&=0XFFFFFFF0;
	GPIOB->CRH|=0X00000003;
	BEEP=0;			//BEEP低电平时关闭
}
