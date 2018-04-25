#include "beep.h"
#include "lpc11xx.h"

//·äÃùÆ÷
void Beep_Init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL = LPC_SYSCON->SYSAHBCLKCTRL | (1<<16) | (1<<6);

  LPC_IOCON->PIO1_4 = (0x0) + (0x1<<3);
	LPC_GPIO1->DIR |= 1 << 4;
	LPC_GPIO1->DATA &= ~(1<<4);
}
void Beep(char sw)
{
	if(sw) LPC_GPIO1->DATA |= (1<<4);
	else LPC_GPIO1->DATA &= ~(1<<4);
}
