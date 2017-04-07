#ifndef ZB_SNIFFER_RADIO_H
#define ZB_SNIFFER_RADIO_H 1

#include "zb_sniffer_sys.h"

#define ZB_SNIFFER_RF_INTERRUPT    RF_VECTOR
#define ZB_SNIFFER_RFERR_INTERRUPT RFERR_VECTOR

#define ZB_SNIFFER_RF_START_CHANNEL_NUMBER 11
#define ZB_SNIFFER_RF_MAX_CHANNEL_NUMBER   26

#define ZB_SNIFFER_RF_SET_CHANNEL(_ch) FREQCTRL = (ZB_SNIFFER_RF_START_CHANNEL_NUMBER + (_ch - ZB_SNIFFER_RF_START_CHANNEL_NUMBER) * 5)

#define ZB_SNIFFER_RF_ISFLUSHRX() (RFST = 0xED)
#define ZB_SNIFFER_RF_SFLUSHRX()  (RFST = 0xDD)
#define ZB_SNIFFER_RF_ISRXON()    (RFST = 0xE3)
#define ZB_SNIFFER_RF_ISRFOFF()   (RFST = 0xEF)

#define ZB_SNIFFER_RF_CHECK_SFD()       (RFIRQF0 & 0x02)
#define ZB_SNIFFER_RF_CHECK_PACKET_RX() (RFIRQF0 & 0x40)
#define ZB_SNIFFER_RF_CLEAR_ISRSTS()    (RFIRQF0 =0, S1CON = 0, RFIRQF1 = 0)
#define ZB_SNIFFER_RF_CLEAR_ERR()       (RFERRF = 0, TCON &= ~0x02)
#define ZB_SNIFFER_RF_CHECK_OVERFLOW()  (RFERRF & 0x04)

extern zb_bool_t is_sniffing;
/* FIXME: It's not overflow, it's RFERROR */
extern zb_bool_t fifo_overflow;

void zb_sniffer_rf_init_radio(void);
void zb_sniffer_rf_start_rx(zb_uint8_t channel);
void zb_sniffer_rf_stop_rx(void);

#endif /* ZB_SNIFFER_RADIO_H */
