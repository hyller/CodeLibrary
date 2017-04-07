#ifndef ZB_SNIFFER_USB_H
#define ZB_SNIFFER_USB_H 1

#include "hal_board.h"
#include "hal_uart.h"
#include "usb_uart.h"

#define ZB_SNIFFER_UART_BAUDRATE HAL_UART_BAUDRATE_115200 /* 0x06 */
#define zb_sniffer_usb_iteration usbUartProcess                       

void zb_sniffer_usb_init(void);

#endif	/* ZB_SNIFFER_USB_H */
