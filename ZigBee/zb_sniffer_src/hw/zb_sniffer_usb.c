#include "zb_sniffer_usb.h"

void zb_sniffer_usb_init(void)
{
  usbUartInit(HAL_UART_BAUDRATE_115200);
}
