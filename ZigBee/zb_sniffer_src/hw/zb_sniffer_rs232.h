#ifndef ZB_SNIFFER_RS232_H
#define ZB_SNIFFER_RS232_H 1

#include "zb_sniffer_sys.h"

#define ZB_SNIFFER_RS232_TX_INTERRUPT UTX0_VECTOR
#define ZB_SNIFFER_RS232_RX_INTERRUPT URX0_VECTOR

#define ZB_SNIFFER_ENABLE_RS232_RX_INTER()    (IEN0 |= 0x04)
#define ZB_SNIFFER_DISABLE_RS232_RX_INTER()   (IEN0 &=~0x04)
#define ZB_SNIFFER_ENABLE_RS232_TX_INTER()    (IEN2 |= 0x04)
#define ZB_SNIFFER_DISABLE_RS232_TX_INTER()   (IEN2 &=~0x04)

#define ZB_SNIFFER_DISABLE_RS232_INTER()      (IEN2 &=~0x04, IEN0 &=~0x04)
#define ZB_SNIFFER_ENABLE_RS232_INTER()       (IEN2 |= 0x04, IEN0 |= 0x04)

#define ZB_SNIFFER_RS232_SET_TX_FLAG()    (UTX0IF = 1)
#define ZB_SNIFFER_RS232_CLEAR_TX_FLAG()  (UTX0IF = 0)

#define ZB_SNIFFER_RS232_TX_FLAG UTX0IF

void zb_sniffer_rs232_init(void);
void zb_sniffer_rs232_iteration(void);

#endif /* ZB_SNIFFER_RS232_H */
