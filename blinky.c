#include "LPC11XX.h"
#include "timer.h"
#include "led.h"
#include "adc.h"
#include "key.h"
#include "system_init.h"
#include "digitSeg.h"
#include "beep.h"
/*片选定义*/
#define D0 0x01
#define D1 0x02
#define D2 0x04
#define D3 0x08

#define key  LPC_GPIO3->DATA 
/*
数码管显示
cs:D0~D3的逻辑或
num:0~0xf
*/

uint8_t cs;
uint8_t digit[4];
uint8_t min;
uint8_t s;
uint8_t val = 1;


void TIMER16_1_IRQHandler(void)
{	
	int i = 0;						   
	if(cs == 0)	 
		Seg_Display(D0,digit[0]);	
	else if(cs == 1)
		Seg_Display(D1,digit[1]);
	else if(cs == 2)
	  	Seg_Display(D2,digit[2]);
	else if(cs == 3)
	  	Seg_Display(D3,digit[3]);
	cs++;
	cs %= 4;
	LPC_TMR16B1->IR = 1;


	for(i=0;i<3;i++)
	{
		LPC_GPIO3->DATA &= ~(0x01<<(i+3));
//		tmp = key;
//		tmp = 	  (key&0x07);
//		tmp = 	   (key&0x07)^0x07;
		switch((key&0x07)^0x07)
		{
			case (0x01):          val=1+i;break;
			case (0x02):          val=4+i;break;
			case (0x04):          val=7+i;break;

		}
		LPC_GPIO3->DATA |= (0x01<<(i+3));
	}
}

void TIMER16_0_IRQHandler(void)
{
	s++;
	if(s %60 == 0)
	{
		s = 0;
		min++;
	}
	if(min >= 60)
		min = 0;
	LPC_TMR16B0->IR = 1;
}

int main(void)
{
  int i = 0;
	int k = 0;
	int dir = 1;
	uint32_t  ulADCData; 
  uint32_t  ulADCBuf;
	
	LedOutputCfg();
	Key3_3_Init();
	DigitSeg_Init();
	Beep_Init();
  ADCInit();
	
	TIMER16_1_Init(5);
	TIMER16_0_Init(100);
	

  while(1)
	{
		  ulADCData = 0;
      for (i = 0; i < 10; i++) {
				LPC_ADC->CR |= (1 << 24);                                   /* ????                     */
				while((LPC_ADC->DR[1] & 0x80000000) == 0);                  /* ??AD0DR0?Done             */
				LPC_ADC->CR |= (1 <<24);                                    /* ?????????           */
				while((LPC_ADC->DR[1] & 0x80000000) == 0);                  /* ??AD0DR0?Done             */
				ulADCBuf = LPC_ADC->DR[1];                                  /* ???????               */
				ulADCBuf = (ulADCBuf >> 6) & 0x3ff;
				ulADCData += ulADCBuf;
      }
      ulADCData = ulADCData / 10;                                     /* ??10???????         */
      ulADCData = (ulADCData * 3300) / 1024;
			digit[0] = ulADCData%10;
		  digit[1] = ulADCData/10-ulADCData/100*10;
		  digit[2] = ulADCData/100-ulADCData/1000*10;
		  digit[3] = ulADCData/1000;
      myDelay(200);
			if(k)
				led_on();
			else
				led_off();
			k = ~k;
  	}
}
