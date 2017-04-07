#include "zb_sniffer_radio.h"
#include "zb_sniffer_time.h"
#include "zb_sniffer_leds.h"
#include "zb_sniffer_transport.h"

zb_bool_t is_sniffing;
zb_bool_t fifo_overflow;

void zb_sniffer_rf_init_radio(void)
{
  /* Auto CRC + append RSSI & LQI */
  FRMCTRL0 |= 0x30;
  /* Set promiscuous mode */
  FRMFILT0 = 0;
  SRCMATCH = 0;
  /* Recommended RX settings, copy/paste */
  TXFILTCFG = 0x09;
  AGCCTRL1  = 0x15;
  FSCAL1    = 0x00;
  /* Enable RX interrupt : RXPKTDONE interrupt 1 << 6 & SFD 1 << 1 */
  RFIRQM0 |= 0x42;
  /* ... general RF interrupts */
  IEN2 |= 0x01;
#ifdef DEBUG_RF
  /* Enable RFERR interrupt: RX over- under - flow and Strobe error */
  RFERRM |= 0x4C;
  /* RFERR */
  IEN0 |= 0x01;
#endif

  is_sniffing = ZB_FALSE;
  fifo_overflow = ZB_FALSE;
}

void zb_sniffer_rf_start_rx(zb_uint8_t channel)
{
  if (!is_sniffing)
  {
    ZB_SNIFFER_RF_ISRXON();
    ZB_SNIFFER_RF_SET_CHANNEL(channel);

    is_sniffing = ZB_TRUE;
  }
}

void zb_sniffer_rf_stop_rx()
{
  if (is_sniffing)
  {
    ZB_SNIFFER_RF_ISFLUSHRX();
    ZB_SNIFFER_RF_ISRFOFF();

    is_sniffing = ZB_FALSE;
  }
}

#ifdef ZB_SNIFFER_IAR
#pragma vector=ZB_SNIFFER_RF_INTERRUPT
#endif
__interrupt void zb_sniffer_rf_interrupt_handler(void)
{
  zb_sniffer_transport_rb_record_t *record;
  zb_bool_t need_flush;

  ZB_SNIFFER_DISABLE_ALL_INTER();

  /* FIXME: what if there is no space? */

  need_flush = ZB_FALSE;

  if (!ZB_RING_BUFFER_IS_FULL(&transport_rb))
  {
    record = ZB_RING_BUFFER_WRITE_PEEK(&transport_rb);
    /* Catch frame received time on SFD signal */
    if (ZB_SNIFFER_RF_CHECK_SFD())
    {
      record->header.timestamp.mcrsec_cnt = timer;
      record->header.timestamp.low = ZB_SNIFFER_HW_TIMER_LOW;
      record->header.timestamp.high = ZB_SNIFFER_HW_TIMER_HIGH;
    }

    if (ZB_SNIFFER_RF_CHECK_PACKET_RX())
    {
      zb_uint8_t *ptr = record->data;
      zb_uint8_t i;

      record->header.len = RXFIFOCNT;
      for (i = 0; i < record->header.len; i++)
      {
        ptr[i] = RFD;
      }
      ZB_RING_BUFFER_WRITTEN(&transport_rb);
    }
  }
  else
  {
    need_flush = (ZB_SNIFFER_RF_CHECK_PACKET_RX() ? ZB_TRUE : ZB_FALSE);
  }

  ZB_SNIFFER_RF_CLEAR_ISRSTS();
  if (ZB_SNIFFER_RF_CHECK_OVERFLOW() || need_flush)
  {
    ZB_SNIFFER_RF_ISFLUSHRX();
  }

  ZB_SNIFFER_ENABLE_ALL_INTER();
}

#ifdef ZB_SNIFFER_IAR
#pragma vector=ZB_SNIFFER_RFERR_INTERRUPT
#endif
__interrupt void zb_sniffer_rferr_interrupt_handler(void)
{
  TCON &= ~0x02;
  RFERRF = 0;
  ZB_SNIFFER_RF_ISFLUSHRX();
  ZB_SNIFFER_RF_ISRXON();

  fifo_overflow = ZB_TRUE;
}
