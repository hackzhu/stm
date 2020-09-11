#include "sys.h"
#include "delay.h"
#include "led.h"

int main()
{
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);		//延时初始化
	ledinit();
	while(1)
	{
	LED0=0;
	LED1=1;
	delay_ms(300);
	LED0=1;
	LED1=0;
	delay_ms(300);
	}
}
