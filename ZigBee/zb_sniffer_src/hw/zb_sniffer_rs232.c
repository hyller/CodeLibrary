#include "zb_sniffer_transport.h"
#include "zb_sniffer_radio.h"

zb_bool_t tx_in_progress;

void zb_sniffer_rs232_init(void)
{
  /* Set P2 priority - USART0 over USART1 if both are defined. */
  P2DIR &= ~0xC;      /* 00 means priority USART0, USART1, TIMER1 */ 
  PERCFG &= ~0x01;    /* Set UART0 I/O location to P0.*/
  P0SEL  |= 0x0C;     /* Enable Tx and Rx peripheral functions on pins. */
  ADCCFG &= ~0x0C;    /* Make sure ADC doesnt use this. */
  U0CSR = 0x80;       /* Mode is UART Mode. */
  U0UCR = 0x80;       /* Flush it. */
  U0BAUD = 216;       /* 115200 */
  U0GCR = 11;         /* for 115200 mode, taken from sample code */
  U0UCR = 0x02;       /* stop UART */
  U0CSR |= 0x40;      /* receiver enabled, not sure it's really needed for now */
 
  ZB_SNIFFER_ENABLE_RS232_INTER();
  tx_in_progress = ZB_FALSE;
}

void zb_sniffer_rs232_iteration(void)
{
  if (!ZB_RING_BUFFER_IS_EMPTY(&transport_rb) && !tx_in_progress)
  {
    ZB_SNIFFER_RS232_SET_TX_FLAG();
  }
}

#ifdef ZB_SNIFFER_IAR
#pragma vector=ZB_SNIFFER_RS232_TX_INTERRUPT
#endif
__interrupt void zb_sniffer_rs232_tx_interrupt_handler(void)
{  
  if (ZB_SNIFFER_RS232_TX_FLAG)
  {
    zb_uint8_t nbytes = 0;
    zb_uint8_t *p = NULL;
    
    ZB_SNIFFER_RS232_CLEAR_TX_FLAG();
    ZB_SNIFFER_DISABLE_RS232_INTER();
    
    nbytes = zb_sniffer_get_next_block_for_host(&p, 1);
    if (nbytes)
    {
      U0DBUF = *p;
      tx_in_progress = ZB_TRUE;
    }
    else
    {
      tx_in_progress = ZB_FALSE;
    }
    
    ZB_SNIFFER_ENABLE_RS232_INTER();  
  }
  
}

#ifdef ZB_SNIFFER_IAR
#pragma vector=ZB_SNIFFER_RS232_RX_INTERRUPT
#endif
__interrupt void zb_sniffer_rs232_rx_interrupt_handler(void)
{
  zb_sniffer_cmd_record_t cmd;
    
  ZB_SNIFFER_DISABLE_ALL_INTER();
  
  cmd = U0DBUF;
  /* Receives by UART and sets the transciever's channel for sniffing */
  if (!ZB_RING_BUFFER_IS_FULL(&cmd_rb))
  {
    ZB_RING_BUFFER_PUT(&cmd_rb, cmd);
  }
  
  ZB_SNIFFER_ENABLE_ALL_INTER();
}
