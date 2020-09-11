#ifndef _LED_H
#define _LED_H
#include "sys.h"

#define LED0 PBout(5)
#define DS0  PBout(5)
#define LED1 PEout(5)
#define DS1  PEout(5)

void ledinit(void);
#endif
