#include "zb_sniffer_transport.h"

zb_sniffer_transport_ctx_t transport_ctx;
static const zb_uint16_t preamble = 0x13AD; /* very magic word */

void zb_sniffer_transport_init(void)
{
  ZB_RING_BUFFER_INIT(&cmd_rb);

  zb_sniffer_transport_clear();
  zb_sniffer_hw_transport_init();
}

void zb_sniffer_transport_clear(void)
{
  ZB_SNIFFER_DISABLE_ALL_INTER();

  ZB_RING_BUFFER_INIT(&transport_rb);
  transport_ctx.ptr = (zb_uint8_t *)&preamble;
  transport_ctx.left_len = sizeof(preamble);
  transport_ctx.is_preamble = ZB_TRUE;

  ZB_SNIFFER_ENABLE_ALL_INTER();
}

/* Be sure that transport rb is not empty when calling it */
zb_uint8_t zb_sniffer_get_next_block_for_host(zb_uint8_t **ptr, zb_uint8_t max_len)
{
  zb_uint8_t len = 0;

  if (!ZB_RING_BUFFER_IS_EMPTY(&transport_rb))
  {
    len = (transport_ctx.left_len < max_len ? transport_ctx.left_len : max_len);
    *ptr = transport_ctx.ptr;
    transport_ctx.left_len -= len;
    transport_ctx.ptr += len;

    if (transport_ctx.left_len == 0 && len > 0)
    {
      if (transport_ctx.is_preamble)
      {
        /* Here it is: we need to be sure, that the buf is not NULL */
        transport_ctx.ptr = (zb_uint8_t *)ZB_RING_BUFFER_READ_PEEK(&transport_rb);
        transport_ctx.left_len = ZB_SNIFFER_BUF_RECORD_HEADER_SIZE +
          ((zb_sniffer_transport_rb_record_hdr_t *)transport_ctx.ptr)->len;
      }
      else
      {
        ZB_RING_BUFFER_FLUSH_GET(&transport_rb);
        transport_ctx.ptr = (zb_uint8_t *)&preamble;
        transport_ctx.left_len = sizeof(preamble);
      }

      transport_ctx.is_preamble = (zb_bool_t)!transport_ctx.is_preamble;
    }
  }

  return len;
}
