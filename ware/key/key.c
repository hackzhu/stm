#include "key.h"

void keyinit(void)
{
	RCC->APB2ENR|=1<<2;	//使能 PORTA 时钟
	RCC->APB2ENR|=1<<6;	//使能 PORTE 时钟
	GPIOA->CRL&=0XFFFFFFF0; //PA0 设置成输入,默认下拉
	GPIOA->CRL|=0X00000008;
	GPIOE->CRL&=0XFFF00FFF; //PE3/4 设置成输入
	GPIOE->CRL|=0X00088000;
	GPIOE->ODR|=3<<3;	//PE3/4 上拉
}

u8 keyscan(u8 mode)
{
	static u8 keyup=1;
	if(mode) keyup=1;
	if(keyup&&(KEY0==0||KEY1==0||WKUP==1))
	{
		delay_ms(10);
		keyup=0;
		if(KEY0==0) return 1;
		else if(KEY1==0) return 2;
		else if(WKUP==1) return 3;
	}
	else if(KEY0==1&&KEY1==1&&WKUP==0) keyup=1;
	return 0;
}
