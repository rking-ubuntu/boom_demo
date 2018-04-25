#include "adc.h"
#include "lpc11xx.h"
void ADCInit( void )
{
    LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 16);
	  LPC_IOCON->R_PIO1_0 &=  ~0x07; 
	  LPC_IOCON->R_PIO1_0 |=  0x02; 
    LPC_IOCON->R_PIO1_0 &= ~(3<<3);                                
	  LPC_IOCON->R_PIO1_0 &= ~(1<<7);
                                    
    
    LPC_SYSCON->PDRUNCFG &= ~(0x01 << 4);                               /* ADC????                  */
    LPC_SYSCON->SYSAHBCLKCTRL |=  (0x01 << 13);                         /* ??ADC????              */

    LPC_ADC->CR = ( 0x02 << 0 ) |                                       /* SEL=1,??ADC0               */
                  ((48000000 / 1000000 - 1) << 8 ) |             /* ????1MHz                 */
                  ( 0 << 16 ) |                                         /* ????????             */
                  ( 0 << 17 ) |                                         /* ??11 clocks??            */
                  ( 0 << 24 ) |                                         /* ADC????                  */
                  ( 0 << 27 );                                          /* ????ADC??,????    */
	  LPC_SYSCON->SYSAHBCLKCTRL &= ~(1 << 16);
}
