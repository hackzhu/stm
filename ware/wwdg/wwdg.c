#include "wwdg.h"

u8 WWDG_CNT=0x7f;

void wwdginit(u8 tr,u8 wr,u8 fprer)
{
	RCC->APB1ENR|=1<<11;			//使能wwdg时钟
	WWDG_CNT=tr&WWDG_CNT;			//初始化WWDG_CNT
	WWDG->CFR|=fprer<<7;			//(PCLK1/4096)/(2^fprer)
	WWDG->CFR&=0xff80;
	WWDG->CFR|=wr;				//设定窗口值
	WWDG->CR|=WWDG_CNT;			//设定计数器值
	WWDG->CR|=1<<7;				//开启看门狗
	MY_NVIC_Init(2,3,WWDG_IRQn,2);		//抢占 2,子优先级 3,组 2
	WWDG->SR=0X00;				//清除提前唤醒中断标志位
	WWDG->CFR|=1<<9;			//使能提前唤醒中断
}

void wwdgsetcounter(u8 cnt)
{
	WWDG->CR =(cnt&0x7F);			//重设置 7 位计数器
}

void WWDG_IRQHandler(void)
{
	wwdgsetcounter(WWDG_CNT);		//重设窗口看门狗的值!
	WWDG->SR=0X00;				//清除提前唤醒中断标志位
	LED1=!LED1;
}

