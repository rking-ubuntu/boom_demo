#include "digitSeg.h"
#include "LPC11XX.h"

const char DIGIT[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92\
	,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

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

void Seg_Display(unsigned char cs, unsigned char num)
{
		if(num>0xf)
			return;
		LPC_GPIO2->DATA = cs<<(8) | DIGIT[num];
}

