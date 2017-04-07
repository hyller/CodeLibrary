#ifndef ZB_SNIFFER_INC_CMD_H
#define ZB_SNIFFER_INC_CMD_H 1

#include "zb_sniffer_sys.h"
#include "zb_ringbuffer.h"

#define ZB_SNIFFER_CMD_BUF_SIZE 8
#define ZB_SNIFFER_PAUSE_CMD 0xAA
#define ZB_SNIFFER_STOP_CMD  0xBB

typedef zb_uint8_t zb_sniffer_cmd_record_t;

ZB_RING_BUFFER_DECLARE(zb_sniffer_cmd_buf, zb_sniffer_cmd_record_t, ZB_SNIFFER_CMD_BUF_SIZE);

void zb_sniffer_process_incoming_cmds(void);

extern zb_sniffer_cmd_buf_t cmd_queue;

#endif	/* ZB_SNIFFER_INC_CMD_H */
