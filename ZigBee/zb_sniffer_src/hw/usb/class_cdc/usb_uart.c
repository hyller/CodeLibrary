/***********************************************************************************

    Filename:     usb_uart.h

    Description:  USB Virtual UART implementation.

***********************************************************************************/


/***********************************************************************************
 * INCLUDES
 */
#include "hal_types.h"
#include "hal_board.h"
#include "hal_int.h"

#include "usb_cdc.h"
#include "usb_firmware_library_config.h"
#include "usb_firmware_library_headers.h"

#include "usb_uart.h"
#include "zb_sniffer_transport.h"

/***********************************************************************************
 * MACROS and DEFINITIONS
 */

#define HAL_LED_DEBUG


/***********************************************************************************
 * EXTERNAL VARIABLES
 */

/* Ring buffers defined in hal_uart.c */

/*extern ringBuf_t rbTxBuf;*/


/***********************************************************************************
 * GLOBAL VARIABLES
 */

CDC_LINE_CODING_STRUCTURE __xdata currentLineCoding;
/*
uint16 cdcRTS;              // Request-To-Send modem control line
uint8  cdcCTS;              // Clear-To-Send   modem control line
*/

/***********************************************************************************
 * LOCAL DATA
 */
static uint8 __xdata buffer[USB_MAX_PACKET_SIZE];
static uint8 oldEndpoint;


/***********************************************************************************
 * LOCAL FUNCTIONS
 */
static void usbEventProcess(void);
static void usbOutProcess(void);
static void usbChannelProcess(void);


/******************************************************************************
 * FUNCTIONS
 */



/***********************************************************************************
* @fn           usbUartInit
*
* @brief        USB UART init function.
*               - Set initial line decoding to 8/NONE/1.
*               - Initialise the USB Firmware Library and the USB controller.
*
* @param        none
*
* @return       none
*/
void usbUartInit(uint32 baudrate)
{
    // Set default line coding.
    currentLineCoding.dteRate = baudrate;
    currentLineCoding.charFormat = CDC_CHAR_FORMAT_1_STOP_BIT;
    currentLineCoding.parityType = CDC_PARITY_TYPE_NONE;
    currentLineCoding.dataBits = 8;

    // Init USB library
    usbfwInit();

    // Initialize the USB interrupt handler with bit mask containing all processed USBIRQ events
    usbirqInit(0xFFFF);

    // Enable pullup on D+
    HAL_USB_PULLUP_ENABLE();

    // Enable global interrupts
    ZB_SNIFFER_ENABLE_ALL_INTER();
}



/***********************************************************************************
* @fn           usbUartProcess
*
* @brief        The USB UART main task function. Must be called from the
*               applications main loop.
*
* @param        none
*
* @return       none
*/
void usbUartProcess(void)
{
    // Process USB events
    usbEventProcess();
    // Check if new channel num is got
    usbChannelProcess();
    // Send packets to the host
    usbOutProcess();
}



/***********************************************************************************
* @fn           usbEventProcess
*
* @brief        Handle the USB events which are not directly related to the UART.
*
* @param        none
*
* @return       none
*/
static void usbEventProcess(void)
{
    // Handle reset signaling on the bus
    if (USBIRQ_GET_EVENT_MASK() & USBIRQ_EVENT_RESET) {
        USBIRQ_CLEAR_EVENTS(USBIRQ_EVENT_RESET);
        usbfwResetHandler();
    }

    // Handle packets on EP0
    if (USBIRQ_GET_EVENT_MASK() & USBIRQ_EVENT_SETUP) {
        USBIRQ_CLEAR_EVENTS(USBIRQ_EVENT_SETUP);
        usbfwSetupHandler();
    }

    // Handle USB suspend
    if (USBIRQ_GET_EVENT_MASK() & USBIRQ_EVENT_SUSPEND) {

        // Clear USB suspend interrupt
        USBIRQ_CLEAR_EVENTS(USBIRQ_EVENT_SUSPEND);

        // Take the chip into PM1 until a USB resume is deteceted.
        usbsuspEnter();

        // Running again; first clear RESUME interrupt
        USBIRQ_CLEAR_EVENTS(USBIRQ_EVENT_RESUME);
    }
}



/***********************************************************************************
* @fn           usbInProcess
*
* @brief        Handle traffic flow from RF to USB.
*
* @param        none
*
* @return       none
*/
static void usbOutProcess(void)
{
  HAL_USB_INT_DISABLE();
  /*
  // USB ready to accept new IN packet
  ZB_SNIFFER_DISABLE_ALL_INTER();
  */

  oldEndpoint = USBFW_GET_SELECTED_ENDPOINT();
  USBFW_SELECT_ENDPOINT(4);

  // The IN endpoint is ready to accept data
  if ( USBFW_IN_ENDPOINT_DISARMED() )
  {
    uint8 written = 0;

    while (!ZB_RING_BUFFER_IS_EMPTY(&transport_rb) && written < USB_MAX_PACKET_SIZE)
    {
      uint8 *p;
      uint8 length = zb_sniffer_get_next_block_for_host((zb_uint8_t **)&p, USB_MAX_PACKET_SIZE - written);

      if (length > 0)
      {
        memcpy(buffer + written, p, length);
        written += length;
      }
      else
      {
        break;
      }
    }

    if (written > 0)
    {
      usbfwWriteFifo(&USBF4, written, buffer);
      // Flag USB IN buffer as not ready (disarming EP4)
      USBFW_SELECT_ENDPOINT(4);
      USBFW_ARM_IN_ENDPOINT();   // Send data to the host
    }
  }

  USBFW_SELECT_ENDPOINT(oldEndpoint);
  HAL_USB_INT_ENABLE();
  /*
  ZB_SNIFFER_ENABLE_ALL_INTER();
  */
}


/***********************************************************************************
* @fn           usbOutProcess
*
* @brief        Handle traffic flow from USB to RF.
*
* @param        none
*
* @return       none
*/
static void usbChannelProcess(void)
{
    /* Set sniffing channel here */
    uint8 length;

    ZB_SNIFFER_DISABLE_ALL_INTER();

    oldEndpoint = USBFW_GET_SELECTED_ENDPOINT();
    USBFW_SELECT_ENDPOINT(4);

    if (USBFW_OUT_ENDPOINT_DISARMED() ) {

        // Get length of USB packet, this operation must not be interrupted.
        length = USBFW_GET_OUT_ENDPOINT_COUNT_LOW();
        length += USBFW_GET_OUT_ENDPOINT_COUNT_HIGH() >> 8;
        if (length)
        {
          uint8 i;

          usbfwReadFifo(&USBF4, length, buffer);

          for (i = 0; i < length; i++)
          {
            if (!ZB_RING_BUFFER_IS_FULL(&cmd_rb))
            {
              ZB_RING_BUFFER_PUT(&cmd_rb, buffer[i]);
            }
          }

          USBFW_SELECT_ENDPOINT(4);
          USBFW_ARM_OUT_ENDPOINT();
        }

    }

    USBFW_SELECT_ENDPOINT(oldEndpoint);
    ZB_SNIFFER_ENABLE_ALL_INTER();
}
/*
+------------------------------------------------------------------------------
|  Copyright 2004-2009 Texas Instruments Incorporated. All rights reserved.
|
|  IMPORTANT: Your use of this Software is limited to those specific rights
|  granted under the terms of a software license agreement between the user who
|  downloaded the software, his/her employer (which must be your employer) and
|  Texas Instruments Incorporated (the "License"). You may not use this Software
|  unless you agree to abide by the terms of the License. The License limits
|  your use, and you acknowledge, that the Software may not be modified, copied
|  or distributed unless embedded on a Texas Instruments microcontroller or used
|  solely and exclusively in conjunction with a Texas Instruments radio
|  frequency transceiver, which is integrated into your product. Other than for
|  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
|  works of, modify, distribute, perform, display or sell this Software and/or
|  its documentation for any purpose.
|
|  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
|  PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
|  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
|  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
|  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
|  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
|  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING
|  BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
|  CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
|  SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
|  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
|
|  Should you have any questions regarding your right to use this Software,
|  contact Texas Instruments Incorporated at www.TI.com.
|
+------------------------------------------------------------------------------
*/
