#include "exti.h"

void EXTI0_IRQHandler(void)		//在startup_stm32f10x_hd.s中定义好了
{
	delay_ms(10);
	if(WKUP==1) BEEP=!BEEP;
	EXTI->PR=1<<0;			 //清除 LINE0 上的中断标志位
}

void EXTI3_IRQHandler(void)		//在startup_stm32f10x_hd.s中定义好了
{
	delay_ms(10);
	if(KEY1==0) LED1=!LED1;
	EXTI->PR=1<<3;			 //清除 LINE3 上的中断标志位
}

void EXTI4_IRQHandler(void)		//在startup_stm32f10x_hd.s中定义好了
{
	delay_ms(10);
	if(KEY0==0) LED0=!LED0;
	EXTI->PR=1<<4;			 //清除 LINE4 上的中断标志位
}

void extixinit(void)
{
	keyinit();
	Ex_NVIC_Config(GPIO_A,0,RTIR); 	//上升沿触发
	Ex_NVIC_Config(GPIO_E,3,FTIR); 	//下降沿触发
	Ex_NVIC_Config(GPIO_E,4,FTIR); 	//下降沿触发
	MY_NVIC_Init(2,3,EXTI0_IRQn,2);	//抢占 2,子优先级 3,组 2
	MY_NVIC_Init(2,1,EXTI3_IRQn,2);	//抢占 2,子优先级 1,组 2
	MY_NVIC_Init(2,0,EXTI4_IRQn,2);	//抢占 2,子优先级 0,组 2
}
