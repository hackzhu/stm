#ifndef _KEY_H
#define _KEY_H
#include "sys.h"
#include "delay.h"

#define KEY0 PEin(4)
#define KEY1 PEin(3)
#define WKUP PAin(0)

#define KEY0PRES 1
#define KEY1PRES 2
#define WKUPPRES 3

void keyinit(void);
u8 keyscan(u8 mode);
#endif
