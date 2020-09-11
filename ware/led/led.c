#include "led.h"

void ledinit()
{
	RCC->APB2ENR|=1<<3;		//使能PORTB时钟
	GPIOB->CRL&=0XFF0FFFFF;		//x&0=0,其余不变;	|使PB.5
	GPIOB->CRL|=0X00300000;		//x|1=1,其余不变;	|推挽输出
	GPIOB->ODR|=1<<5;		//使PB.5高电平，即LED灭		因为默认下拉输出，灯亮


	RCC->APB2ENR|=1<<6;		//使能PORTE时钟
	GPIOE->CRL&=0XFF0FFFFF;		//x&0=0,其余不变;	|使PE.5
	GPIOE->CRL|=0X00300000;		//x|1=1,其余不变;	|推挽输出
	GPIOE->ODR|=1<<5;		//使PE.5高电平，即LED灭		因为默认下拉输出，灯亮
}
