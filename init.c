#include "LPC11XX.h"

/*数码管引脚初始化*/

void DigitSeg_Init(void)
{
  LPC_SYSCON->SYSAHBCLKCTRL = LPC_SYSCON->SYSAHBCLKCTRL | (1<<16) | (1<<6);

  LPC_IOCON->PIO2_0 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_1 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_2 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_3 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_4 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_5 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_6 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_7 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_8 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_9 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_10 = (0x0) + (0x2<<3);
	LPC_IOCON->PIO2_11 = (0x0) + (0x2<<3);

  // Set pin 0-11 as output
  LPC_GPIO2->DIR = 0xfff;

  return;
}



void LedOutputCfg(void)
{
  LPC_SYSCON->SYSAHBCLKCTRL = LPC_SYSCON->SYSAHBCLKCTRL | (1<<16) | (1<<6);

  LPC_IOCON->PIO1_9 = (0x0) + (1<<3) + (0<<5);

  // Set pin 9 as output
  LPC_GPIO1->DIR = LPC_GPIO1->DIR | (1<<9);

  return;
}
