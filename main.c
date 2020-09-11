#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
//#include "exti.h"
//#include "iwdg.h"
#include "wwdg.h"

void keydown(void);

int main()
{
	Stm32_Clock_Init(9);	//系统时钟设置
	delay_init(72);		//延时初始化
	ledinit();
	LED0=0;
	delay_ms(500);
	wwdginit(0x7f,0x5f,3);
	while(1)
	{
		LED0=1;
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
