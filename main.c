#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"

int main()
{
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);		//延时初始化
	ledinit();
	beepinit();
	while(1)
	{
	LED0=0;
	LED1=1;
	BEEP=1;
	delay_ms(300);
	LED0=1;
	LED1=0;
	BEEP=0;
	delay_ms(300);
	}
}
