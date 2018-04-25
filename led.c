#include "lpc11xx.h"
#include "led.h"

void LedOutputCfg(void)
{
  LPC_SYSCON->SYSAHBCLKCTRL = LPC_SYSCON->SYSAHBCLKCTRL | (1<<16) | (1<<6);

  LPC_IOCON->PIO1_9 = (0x0) + (1<<3) + (0<<5);

  // Set pin 9 as output
  LPC_GPIO1->DIR = LPC_GPIO1->DIR | (1<<9);

  return;
}
void led_on(void)
{
	LPC_GPIO1->DATA = (0<<9);
}
void led_off(void)
{
	LPC_GPIO1->DATA = (1<<9);
}
