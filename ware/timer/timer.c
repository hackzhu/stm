#include "timer.h"

void TIM3_IRQHandler(void)
{
	if(TIM3->SR&0x0001)	 	//溢出中断
	{
		LED1=!LED1;
	}
	TIM3->SR&=~(1<<0);		//清除中断标志位
}

void tim3intinit(u16 arr,u16 psc)
{
	RCC->APB1ENR|=1<<1; 		//TIM3 时钟使能
	TIM3->ARR=arr;			//设定计数器自动重装值//刚好 1ms
	TIM3->PSC=psc;			//预分频器 7200,得到 10Khz 的计数时钟
	TIM3->DIER|=1<<0;		//允许更新中断
	TIM3->CR1|=0x01;		//使能定时器 3
	MY_NVIC_Init(1,3,TIM3_IRQn,2);	//抢占 1,子优先级 3,组 2

}
