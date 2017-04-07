#include "zb_sniffer_time.h"

zb_sniffer_timer_t timer;
zb_bool_t is_ticking;

void zb_sniffer_init_clock(void)
{
  CLKCONCMD &= ~0x80;
}

void zb_sniffer_clock_set_src(void)
{
  SLEEPCMD &= ~0x04; /* power up oscillators */
  while (!(SLEEPSTA & 0x20) || (SLEEPSTA & 0x04));
  CLKCONCMD =0;  /* mask slow 32k clock oscillator */
  while (CLKCONSTA != 0);
  SLEEPCMD |= 0x04; /* power down the unused oscillator*/
}

void zb_sniffer_timer_init(void)
{
  T1CTL = 0; /* Prescaler 1 with operation suspend */
  T1CCTL0 = 0x40; /* Enable interrupt (capture mode) */

  /* clear interrupt pending flag, disable interrupt */
  T1STAT &= ~0x01; /* T1STAT.CH1IF = 0 */
  IEN1   &= ~0x02; /* IEN1.T1EN = 0 */
    
  zb_sniffer_init_clock();
  zb_sniffer_clock_set_src();

  IEN1 |=  0x02; /* IEN1.T1EN = 1 */
  
  is_ticking = ZB_FALSE;
  timer = 0;
}
   
#ifdef ZB_SNIFFER_IAR
#pragma vector=ZB_SNIFFER_TIMER_INTERRUPT
#endif
__interrupt void zb_sniffer_timer_interrupt_handler(void)
{
  if (ZB_SNIFFER_TIMER_CHECK_OVERFLOW())
  {      
    ZB_SNIFFER_TIMER_CLEAR_OVERFLOW();
    timer++;
  }
}

void zb_sniffer_start_timer(void)
{
  if (!is_ticking)
  {
    is_ticking = ZB_TRUE;
    ZB_SNIFFER_HW_START_TIMER();
  }
}

void zb_sniffer_stop_timer(void)
{
  if (is_ticking)
  {
    is_ticking = ZB_FALSE;
    timer = 0;
    ZB_SNIFFER_HW_STOP_TIMER();
  }
}
