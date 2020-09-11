#include "iwdg.h"

void iwdginit(u8 prer,u16 rlr)
{
	IWDG->KR=0x5555;	//使能对 IWDG->PR 和 IWDG->RLR 的写
	IWDG->PR=prer;		//设置分频系数
	IWDG->RLR=rlr;		//重装载的值
	IWDG->KR=0xaaaa;	//重装载IWDG->RLR
	IWDG->KR=0xcccc;	//使能看门狗
}

void iwdgfeed(void)
{
	IWDG->KR=0xaaaa;		//重装载IWDG->RLR
}
