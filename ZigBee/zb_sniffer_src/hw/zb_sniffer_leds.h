#ifndef ZB_SNIFFER_LEDS_H
#define ZB_SNIFFER_LEDS_H 1

#include "zb_sniffer_sys.h"

#ifdef ZB_SNIFFER_CC2531

#include "hal_board.h"
#define ZB_SNIFFER_GREEN_LED 2
#define ZB_SNIFFER_RED_LED   1

#define ZB_SNIFFER_GREEN_LED_SET() HAL_LED_SET_2()
#define ZB_SNIFFER_GREEN_LED_CLR() HAL_LED_CLR_2()
#define ZB_SNIFFER_GREEN_LED_TGL() HAL_LED_TGL_2()

#define ZB_SNIFFER_RED_LED_SET()   HAL_LED_SET_1()
#define ZB_SNIFFER_RED_LED_CLR()   HAL_LED_CLR_1()
#define ZB_SNIFFER_RED_LED_TGL()   HAL_LED_TGL_1()

#elif defined ZB_SNIFFER_CC2530

#include "hal_srf05_eb_board.h"
#define ZB_SNIFFER_GREEN_LED 1
#define ZB_SNIFFER_RED_LED   2

#define ZB_SNIFFER_GREEN_LED_SET() HAL_LED_SET_1()
#define ZB_SNIFFER_GREEN_LED_CLR() HAL_LED_CLR_1()
#define ZB_SNIFFER_GREEN_LED_TGL() HAL_LED_TGL_1()

#define ZB_SNIFFER_RED_LED_SET()   HAL_LED_SET_2()
#define ZB_SNIFFER_RED_LED_CLR()   HAL_LED_CLR_2()
#define ZB_SNIFFER_RED_LED_TGL()   HAL_LED_TGL_2()

#define ZB_SNIFFER_YELLOW_LED_CLR() HAL_LED_CLR_3()
#define ZB_SNIFFER_ORANGE_LED_CLR() HAL_LED_CLR_4()

#endif  /* ZB_SNIFFER_CC2530 || ZB_SNIFFER_CC2531 */

void zb_sniffer_leds_init();
void zb_sniffer_leds_iteration(
  zb_bool_t is_sniffing, zb_bool_t fifo_overflow, zb_bool_t buf_overflow);

#endif  /* ZB_SNIFFER_LEDS_H */
