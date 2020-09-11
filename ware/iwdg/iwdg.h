#ifndef _IWDG_H
#define _IWDG_H
#include "sys.h"

void iwdginit(u8 prer,u16 rlr);
void iwdgfeed(void);
#endif
