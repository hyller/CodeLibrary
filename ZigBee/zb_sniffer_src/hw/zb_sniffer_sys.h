#ifndef ZB_SNIFFER_GENERAL_H
#define ZB_SNIFFER_GENERAL_H 1

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ioCC2530.h"

#define ZB_SNIFFER_ENABLE_ALL_INTER()  (EA = 1)
#define ZB_SNIFFER_DISABLE_ALL_INTER() (EA = 0, EA = 0)
#define ZB_SNIFFER_CHECK_MSB(_byte) (_byte & 0x80)

typedef char               zb_char_t;
typedef unsigned char      zb_uchar_t;
typedef unsigned char      zb_uint8_t;
typedef signed char        zb_int8_t;
typedef unsigned short     zb_uint16_t;
typedef signed short       zb_int16_t;
typedef unsigned long      zb_uint32_t;
typedef signed long        zb_int32_t;

typedef enum zb_bool_e
{
  ZB_FALSE = 0,
  ZB_TRUE = 1
} zb_bool_t;
    
#endif /* ZB_SNIFFER_GENERAL_H */
