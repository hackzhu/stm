#ifndef _WWDG_H
#define _WWDG_H
#include "sys.h"
#include "led.h"

void wwdginit(u8 tr,u8 wr,u8 fprer);
void wwdgsetcounter(u8 cnt);
#endif
