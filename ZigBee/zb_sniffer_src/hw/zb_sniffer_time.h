#ifndef ZB_SNIFFER_TIME_H
#define ZB_SNIFFER_TIME_H 1

#include "zb_sniffer_sys.h"

#define ZB_SNIFFER_TIMER_INTERRUPT T1_VECTOR   
#define ZB_SNIFFER_HW_START_TIMER()  (T1CC0L = 0,  T1CC0H = 0, T1CTL |= 0x01)
#define ZB_SNIFFER_HW_STOP_TIMER()   (T1CTL &=~(0x01))

#define ZB_SNIFFER_HW_TIMER_LOW T1CNTL
#define ZB_SNIFFER_HW_TIMER_HIGH T1CNTH

#define ZB_SNIFFER_TIMER_OVERFLOW_USEC  2048   
#define ZB_SNIFFER_TIMER_CHECK_OVERFLOW()  (T1STAT & 0x20)
#define ZB_SNIFFER_TIMER_CLEAR_OVERFLOW()  (T1STAT &= 0x20)

#include "zb_sniffer_sys.h"

typedef zb_uint32_t zb_sniffer_timer_t;
typedef struct zb_sniffer_timestamp_s
{
  zb_sniffer_timer_t mcrsec_cnt;
  zb_uint8_t low;
  zb_uint8_t high;
} zb_sniffer_timestamp_t;
   
void zb_sniffer_timer_init(void);
void zb_sniffer_start_timer(void);
void zb_sniffer_stop_timer(void);

extern zb_sniffer_timer_t timer;

#endif /* ZB_SNIFFER_TIME_H */
