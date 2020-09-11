#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
//#include "exti.h"
//#include "iwdg.h"
//#include "wwdg.h"
#include "timer.h"

void keydown(void);

int main()
{
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);		//延时初始化
	ledinit();
	LED0=0;
	delay_ms(500);
	tim3intinit(4999,7199);
	while(1)
	{
		LED0=!LED0;
		delay_ms(200);
	}
}

void keydown(void)
{
	u8 key;
	while(1)
	{
		key=keyscan(0);
		if(key)
		{
			switch(key)
			{
				case	KEY0PRES:
					LED0=!LED0;
					break;
				case	KEY1PRES:
					LED1=!LED1;
					break;
				case	WKUPPRES:
					BEEP=!BEEP;
					break;
			}
		}
		else delay_ms(10);
	}
}
