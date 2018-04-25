#include "key.h"
#include "LPC11XX.h"
//¼üÅÌ³õÊ¼»¯
void Key3_3_Init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL = LPC_SYSCON->SYSAHBCLKCTRL | (1<<16) | (1<<6);

  LPC_IOCON->PIO3_0 = (0x0) + (0x1<<3);
	LPC_IOCON->PIO3_1 = (0x0) + (0x1<<3);
	LPC_IOCON->PIO3_2 = (0x0) + (0x1<<3);
	LPC_IOCON->PIO3_3 = (0x0) + (0x1<<3);
	LPC_IOCON->PIO3_4 = (0x0) + (0x1<<3);
	LPC_IOCON->PIO3_5 = (0x0) + (0x1<<3);
	
	LPC_GPIO3->DIR |= 0x7<<3;

}	 
