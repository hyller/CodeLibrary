#ifndef ZB_SNIFFER_TRANSPORT_RB_H
#define ZB_SNIFFER_TRANSPORT_RB_H 1

#include "zb_ringbuffer.h"
#include "zb_sniffer_sys.h"
#include "zb_sniffer_time.h"

#define ZB_SNIFFER_TRANSPORT_RB_SIZE 24
#define ZB_SNIFFER_TRANSPORT_RB_RECORD_DATA_SIZE 128

typedef struct zb_sniffer_transport_rb_record_hdr_s
{
  zb_uint8_t len;
  zb_sniffer_timestamp_t timestamp;
} zb_sniffer_transport_rb_record_hdr_t;

#define ZB_SNIFFER_BUF_RECORD_HEADER_SIZE sizeof(zb_sniffer_transport_rb_record_hdr_t)

typedef struct zb_sniffer_transport_rb_record_s
{
  zb_sniffer_transport_rb_record_hdr_t header;
  zb_uint8_t data[ZB_SNIFFER_TRANSPORT_RB_RECORD_DATA_SIZE];
} zb_sniffer_transport_rb_record_t;

ZB_RING_BUFFER_DECLARE(zb_sniffer_transport_rb, zb_sniffer_transport_rb_record_t, ZB_SNIFFER_TRANSPORT_RB_SIZE);

extern zb_sniffer_transport_rb_t  transport_rb;

#endif /* ZB_SNIFFER_TRANSPORT_RB_H */
