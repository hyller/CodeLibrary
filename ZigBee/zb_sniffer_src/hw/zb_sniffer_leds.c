#include "zb_sniffer_leds.h"

/* Len in cycles */
#define NOT_SNIFFING_TGL_LEN    30000
#define BUF_OVERFLOW_LEN        10000
#define FIFO_OVERFLOW_LEN       3000
#define FIFO_OVERFLOW_TGL_STEPS 3

zb_bool_t is_not_sniffing;
zb_bool_t is_in_fifo_overflow;
zb_bool_t is_in_buf_overflow;
zb_uint8_t  steps;
zb_uint16_t cycles;

void zb_sniffer_leds_init()
{
  MCU_IO_OUTPUT(HAL_BOARD_IO_LED_1_PORT, HAL_BOARD_IO_LED_1_PIN, 0);
  MCU_IO_OUTPUT(HAL_BOARD_IO_LED_2_PORT, HAL_BOARD_IO_LED_2_PIN, 0);

  /* Need to clr other 2 leds on SRF05EB */
#ifdef ZB_SNIFFER_CC2530
  MCU_IO_OUTPUT(HAL_BOARD_IO_LED_3_PORT, HAL_BOARD_IO_LED_3_PIN, 0);
  MCU_IO_OUTPUT(HAL_BOARD_IO_LED_3_PORT, HAL_BOARD_IO_LED_3_PIN, 0);

  ZB_SNIFFER_YELLOW_LED_CLR();
  ZB_SNIFFER_ORANGE_LED_CLR();
#endif

  is_not_sniffing = ZB_TRUE;
  is_in_fifo_overflow = ZB_FALSE;
  is_in_buf_overflow = ZB_FALSE;
  steps = 0;
  cycles = 0;
}

void zb_sniffer_leds_iteration(
  zb_bool_t is_sniffing, zb_bool_t fifo_overflow, zb_bool_t buf_overflow)
{
  if (is_not_sniffing)
  {
    /* Turn on green LED if we started sniffing */
    if (is_sniffing)
    {
      is_not_sniffing = ZB_FALSE;
      cycles = 0;
      ZB_SNIFFER_GREEN_LED_SET();
    }
    /* Toogle green LED every NOT_SNIFFING_TGL_LEN cycles when not sniffing */
    else if(++cycles >= NOT_SNIFFING_TGL_LEN)
    {
      cycles = 0;
      ZB_SNIFFER_GREEN_LED_TGL();
    }
  }

  /* We might have started sniffer earlier so do double check */
  if(!is_not_sniffing)
  {
    /* CLR all LEDs when stop sniffing*/
    if (!is_sniffing)
    {
      is_not_sniffing = ZB_TRUE;
      ZB_SNIFFER_GREEN_LED_CLR();
      ZB_SNIFFER_RED_LED_CLR();
      cycles = 0;
    }
    /* Indicate errors only when sniffing */
    else
    {
      if(is_in_buf_overflow || is_in_fifo_overflow)
      {
        cycles++;

        if (is_in_buf_overflow && cycles >= BUF_OVERFLOW_LEN)
        {
          cycles = 0;
          is_in_buf_overflow = ZB_FALSE;
          ZB_SNIFFER_RED_LED_CLR();
        }
        else if (is_in_fifo_overflow && cycles >= FIFO_OVERFLOW_LEN)
        {
          cycles = 0;
          steps++;

          if (steps >= FIFO_OVERFLOW_TGL_STEPS)
          {
            steps = 0;
            ZB_SNIFFER_RED_LED_CLR();
            is_in_fifo_overflow = ZB_FALSE;
          }
          else
          {
            ZB_SNIFFER_RED_LED_TGL();
          }
        }
      }
      /*
         If buf overflow and fifo overflow occur simultaneously,
         indicate buf overflow
      */
      else
      {
        if (buf_overflow)
        {
          is_in_buf_overflow = ZB_TRUE;
          ZB_SNIFFER_RED_LED_SET();
        }

        if (!buf_overflow && fifo_overflow)
        {
          is_in_fifo_overflow = ZB_TRUE;
          ZB_SNIFFER_RED_LED_SET();
        }
      }
    }
  }
}
