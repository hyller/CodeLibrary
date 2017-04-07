#ifndef ZB_SNIFFER_CMD_RB_H
#define ZB_SNIFFER_CMD_RB_H 1

#include "zb_ringbuffer.h"
#include "zb_sniffer_sys.h"

#define ZB_SNIFFER_CMD_BUF_SIZE 8

typedef zb_uint8_t zb_sniffer_cmd_record_t;

ZB_RING_BUFFER_DECLARE(zb_sniffer_cmd_rb, zb_sniffer_cmd_record_t, ZB_SNIFFER_CMD_BUF_SIZE);

extern zb_sniffer_cmd_rb_t cmd_rb;

#endif	/* ZB_SNIFFER_CMD_RB_H */
