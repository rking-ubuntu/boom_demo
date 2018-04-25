#include "lpc11xx.h"
#include "timer.h"

void myDelay(uint32_t ulTime)
{
    uint32_t i;

    i = 0;
    while (ulTime--) {
      for (i = 0; i < 5000; i++);
    }
}

void TIMER16_0_Init(uint16_t uIMsTime)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);
	LPC_TMR16B0->IR = 1;
	LPC_TMR16B0->PR = 48000000/1000;	 
	LPC_TMR16B0->MCR = 3;
	LPC_TMR16B0->MR0 = uIMsTime-1;
	LPC_TMR16B0->TCR = 0x01;
	NVIC_EnableIRQ(TIMER_16_0_IRQn);
	NVIC_SetPriority(TIMER_16_0_IRQn,1);
}

void TIMER16_1_Init(uint16_t MsTime)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<8);
	LPC_TMR16B1->IR = 1;
	LPC_TMR16B1->PR = 48000000/1000 - 1;
	LPC_TMR16B1->MCR = 3;
	LPC_TMR16B1->MR0 = MsTime;
	LPC_TMR16B1->TCR = 0x01;
	NVIC_EnableIRQ(TIMER_16_1_IRQn);
	NVIC_SetPriority(TIMER_16_1_IRQn,2);
}
