#ifndef ZB_SNIFFER_TRANSPORT_H
#define ZB_SNIFFER_TRANSPORT_H 1

#ifdef ZB_SNIFFER_CC2530

#include "zb_sniffer_rs232.h"

#define zb_sniffer_hw_transport_init   zb_sniffer_rs232_init
#define zb_sniffer_transport_iteration zb_sniffer_rs232_iteration

#elif defined ZB_SNIFFER_CC2531

#include "zb_sniffer_usb.h"

#define zb_sniffer_hw_transport_init   zb_sniffer_usb_init
#define zb_sniffer_transport_iteration zb_sniffer_usb_iteration

#else

#error Port me!

#endif /* ZB_SNIFFER_CC2530 */

#include "zb_sniffer_transport_rb.h"
#include "zb_sniffer_cmd_rb.h"

typedef struct zb_sniffer_transport_ctx_s
{
  zb_uint8_t *ptr;
  zb_uint8_t left_len;
  zb_bool_t is_preamble;
} zb_sniffer_transport_ctx_t;

void zb_sniffer_transport_init(void);
void zb_sniffer_transport_clear(void);
void zb_sniffer_process_incoming_cmds(void);
zb_uint8_t zb_sniffer_get_next_block_for_host(zb_uint8_t **ptr, zb_uint8_t max_len);

#endif	/* ZB_SNIFFER_TRANSPORT_H */
