#ifndef __TIME_H_
#define __TIME_H_
#include "lpc11xx.h"

void myDelay(uint32_t ulTime);

void TIMER16_0_Init(uint16_t uIMsTime);

void TIMER16_1_Init(uint16_t MsTime);
#endif
