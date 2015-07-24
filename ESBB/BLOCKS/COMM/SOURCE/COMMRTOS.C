/*
*********************************************************************************************************
*                                     Embedded Systems Building Blocks
*                                  Complete and Ready-to-Use Modules in C
*
*                                    Asynchronous Serial Communications
*                                           Buffered Serial I/O 
*                                                 (RTOS)
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : COMMRTOS.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               INCLUDES
*********************************************************************************************************
*/

#include "includes.h"

/*$PAGE*/
/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

typedef struct {
    INT16U     RingBufRxCtr;                /* Number of characters in the Rx ring buffer              */
    OS_EVENT  *RingBufRxSem;                /* Pointer to Rx semaphore                                 */
    INT8U     *RingBufRxInPtr;              /* Pointer to where next character will be inserted        */
    INT8U     *RingBufRxOutPtr;             /* Pointer from where next character will be extracted     */
    INT8U      RingBufRx[COMM_RX_BUF_SIZE]; /* Ring buffer character storage (Rx)                      */
    INT16U     RingBufTxCtr;                /* Number of characters in the Tx ring buffer              */
    OS_EVENT  *RingBufTxSem;                /* Pointer to Tx semaphore                                 */
    INT8U     *RingBufTxInPtr;              /* Pointer to where next character will be inserted        */
    INT8U     *RingBufTxOutPtr;             /* Pointer from where next character will be extracted     */
    INT8U      RingBufTx[COMM_TX_BUF_SIZE]; /* Ring buffer character storage (Tx)                      */
} COMM_RING_BUF;

/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/

COMM_RING_BUF  Comm1Buf;
COMM_RING_BUF  Comm2Buf;

/*$PAGE*/
/*
*********************************************************************************************************
*                                    REMOVE CHARACTER FROM RING BUFFER
*
*
* Description : This function is called by your application to obtain a character from the communications
*               channel.  The function will wait for a character to be received on the serial channel or
*               until the function times out.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*               'to'    is the amount of time (in clock ticks) that the calling function is willing to
*                       wait for a character to arrive.  If you specify a timeout of 0, the function will
*                       wait forever for a character to arrive.
*               'err'   is a pointer to where an error code will be placed:
*                           *err is set to COMM_NO_ERR     if a character has been received
*                           *err is set to COMM_RX_TIMEOUT if a timeout occurred
*                           *err is set to COMM_BAD_CH     if you specify an invalid channel number
* Returns     : The character in the buffer (or NUL if a timeout occurred)
*********************************************************************************************************
*/

INT8U  CommGetChar (INT8U ch, INT16U to, INT8U *err)
{
    INT8U          c;
    INT8U          oserr;
    COMM_RING_BUF *pbuf;


    switch (ch) {                                          /* Obtain pointer to communications channel */
        case COMM1:
             pbuf = &Comm1Buf;
             break;

        case COMM2:
             pbuf = &Comm2Buf;
             break;

        default:
             *err = COMM_BAD_CH;
             return (NUL);
    }
    OSSemPend(pbuf->RingBufRxSem, to, &oserr);             /* Wait for character to arrive             */
    if (oserr == OS_TIMEOUT) {                             /* See if characters received within timeout*/
        *err = COMM_RX_TIMEOUT;                            /* No, return error code                    */
        return (NUL);
    } else {
        OS_ENTER_CRITICAL();
        pbuf->RingBufRxCtr--;                              /* Yes, decrement character count           */
        c = *pbuf->RingBufRxOutPtr++;                      /* Get character from buffer                */
        if (pbuf->RingBufRxOutPtr == &pbuf->RingBufRx[COMM_RX_BUF_SIZE]) {     /* Wrap OUT pointer     */
            pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        *err = COMM_NO_ERR;
        return (c);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  GET TX CHARACTER FROM RING BUFFER
*
*
* Description : This function is called by the Tx ISR to extract the next character from the Tx buffer.
*               The function returns FALSE if the buffer is empty after the character is extracted from
*               the buffer.  This is done to signal the Tx ISR to disable interrupts because this is the
*               last character to send.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*               'err'   is a pointer to where an error code will be deposited:
*                           *err is set to COMM_NO_ERR         if at least one character was available
*                                                              from the buffer.
*                           *err is set to COMM_TX_EMPTY       if the Tx buffer is empty.
*                           *err is set to COMM_BAD_CH         if you have specified an incorrect channel
* Returns     : The next character in the Tx buffer or NUL if the buffer is empty.
*********************************************************************************************************
*/

INT8U  CommGetTxChar (INT8U ch, INT8U *err)
{
    INT8U          c;
    COMM_RING_BUF *pbuf;


    switch (ch) {                                          /* Obtain pointer to communications channel */
        case COMM1:
             pbuf = &Comm1Buf;
             break;

        case COMM2:
             pbuf = &Comm2Buf;
             break;

        default:
             *err = COMM_BAD_CH;
             return (NUL);
    }
    if (pbuf->RingBufTxCtr > 0) {                          /* See if buffer is empty                   */
        pbuf->RingBufTxCtr--;                              /* No, decrement character count            */
        c = *pbuf->RingBufTxOutPtr++;                      /* Get character from buffer                */
        if (pbuf->RingBufTxOutPtr == &pbuf->RingBufTx[COMM_TX_BUF_SIZE]) {     /* Wrap OUT pointer     */
            pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];
        }
        OSSemPost(pbuf->RingBufTxSem);                     /* Indicate that character will be sent     */
        *err = COMM_NO_ERR;
        return (c);                                        /* Characters are still available           */
    } else {
        *err = COMM_TX_EMPTY;
        return (NUL);                                      /* Buffer is empty                          */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  INITIALIZE COMMUNICATIONS MODULE
*
*
* Description : This function is called by your application to initialize the communications module.  You
*               must call this function before calling any other functions.
* Arguments   : none
*********************************************************************************************************
*/

void  CommInit (void)
{
    COMM_RING_BUF *pbuf;


    pbuf                  = &Comm1Buf;                     /* Initialize the ring buffer for COMM1     */
    pbuf->RingBufRxCtr    = 0;
    pbuf->RingBufRxInPtr  = &pbuf->RingBufRx[0];
    pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];
    pbuf->RingBufRxSem    = OSSemCreate(0);
    pbuf->RingBufTxCtr    = 0;
    pbuf->RingBufTxInPtr  = &pbuf->RingBufTx[0];
    pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];
    pbuf->RingBufTxSem    = OSSemCreate(COMM_TX_BUF_SIZE);

    pbuf                  = &Comm2Buf;                     /* Initialize the ring buffer for COMM2     */
    pbuf->RingBufRxCtr    = 0;
    pbuf->RingBufRxInPtr  = &pbuf->RingBufRx[0];
    pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];
    pbuf->RingBufRxSem    = OSSemCreate(0);
    pbuf->RingBufTxCtr    = 0;
    pbuf->RingBufTxInPtr  = &pbuf->RingBufTx[0];
    pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];
    pbuf->RingBufTxSem    = OSSemCreate(COMM_TX_BUF_SIZE);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                   SEE IF RX CHARACTER BUFFER IS EMPTY
*
*
* Description : This function is called by your application to see if any character is available from the
*               communications channel.  If at least one character is available, the function returns
*               FALSE otherwise, the function returns TRUE.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
* Returns     : TRUE    if the buffer IS empty.
*               FALSE   if the buffer IS NOT empty or you have specified an incorrect channel.
*********************************************************************************************************
*/

BOOLEAN  CommIsEmpty (INT8U ch)
{
    BOOLEAN        empty;
    COMM_RING_BUF *pbuf;


    switch (ch) {                                          /* Obtain pointer to communications channel */
        case COMM1:
             pbuf = &Comm1Buf;
             break;

        case COMM2:
             pbuf = &Comm2Buf;
             break;

        default:
             return (TRUE);
    }
    OS_ENTER_CRITICAL();
    if (pbuf->RingBufRxCtr > 0) {                          /* See if buffer is empty                   */
        empty = FALSE;                                     /* Buffer is NOT empty                      */
    } else {
        empty = TRUE;                                      /* Buffer is empty                          */
    }
    OS_EXIT_CRITICAL();
    return (empty);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                   SEE IF TX CHARACTER BUFFER IS FULL
*
*
* Description : This function is called by your application to see if any more characters can be placed
*               in the Tx buffer.  In other words, this function check to see if the Tx buffer is full.
*               If the buffer is full, the function returns TRUE otherwise, the function returns FALSE.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
* Returns     : TRUE    if the buffer IS full.
*               FALSE   if the buffer IS NOT full or you have specified an incorrect channel.
*********************************************************************************************************
*/

BOOLEAN  CommIsFull (INT8U ch)
{
    BOOLEAN        full;
    COMM_RING_BUF *pbuf;


    switch (ch) {                                          /* Obtain pointer to communications channel */
        case COMM1:
             pbuf = &Comm1Buf;
             break;

        case COMM2:
             pbuf = &Comm2Buf;
             break;

        default:
             return (TRUE);
    }
    OS_ENTER_CRITICAL();
    if (pbuf->RingBufTxCtr < COMM_TX_BUF_SIZE) {           /* See if buffer is full                    */
        full = FALSE;                                      /* Buffer is NOT full                       */
    } else {
        full = TRUE;                                       /* Buffer is full                           */
    }
    OS_EXIT_CRITICAL();
    return (full);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                            OUTPUT CHARACTER
*
*
* Description : This function is called by your application to send a character on the communications
*               channel.  The function will wait for the buffer to empty out if the buffer is full.
*               The function returns to your application if the buffer doesn't empty within the specified
*               timeout.  A timeout value of 0 means that the calling function will wait forever for the
*               buffer to empty out.  The character to send is first inserted into the Tx buffer and will
*               be sent by the Tx ISR.  If this is the first character placed into the buffer, the Tx ISR
*               will be enabled.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*               'c'     is the character to send.
*               'to'    is the timeout (in clock ticks) to wait in case the buffer is full.  If you
*                       specify a timeout of 0, the function will wait forever for the buffer to empty.
* Returns     : COMM_NO_ERR      if the character was placed in the Tx buffer
*               COMM_TX_TIMEOUT  if the buffer didn't empty within the specified timeout period
*               COMM_BAD_CH      if you specify an invalid channel number
*********************************************************************************************************
*/

INT8U  CommPutChar (INT8U ch, INT8U c, INT16U to)
{
    INT8U          oserr;
    COMM_RING_BUF *pbuf;


    switch (ch) {                                          /* Obtain pointer to communications channel */
        case COMM1:
             pbuf = &Comm1Buf;
             break;

        case COMM2:
             pbuf = &Comm2Buf;
             break;

        default:
             return (COMM_BAD_CH);
    }
    OSSemPend(pbuf->RingBufTxSem, to, &oserr);             /* Wait for space in Tx buffer              */
    if (oserr == OS_TIMEOUT) {
        return (COMM_TX_TIMEOUT);                          /* Timed out, return error code             */
    }
    OS_ENTER_CRITICAL();
    pbuf->RingBufTxCtr++;                                  /* No, increment character count            */
    *pbuf->RingBufTxInPtr++ = c;                           /* Put character into buffer                */
    if (pbuf->RingBufTxInPtr == &pbuf->RingBufTx[COMM_TX_BUF_SIZE]) {     /* Wrap IN pointer           */
        pbuf->RingBufTxInPtr = &pbuf->RingBufTx[0];
    }
    if (pbuf->RingBufTxCtr == 1) {                         /* See if this is the first character       */
        CommTxIntEn(ch);                                   /* Yes, Enable Tx interrupts                */
    }
    OS_EXIT_CRITICAL();
    return (COMM_NO_ERR);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                    INSERT CHARACTER INTO RING BUFFER
*
*
* Description : This function is called by the Rx ISR to insert a character into the receive ring buffer.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*               'c'     is the character to insert into the ring buffer.  If the buffer is full, the
*                       character will not be inserted, it will be lost.
*********************************************************************************************************
*/

void  CommPutRxChar (INT8U ch, INT8U c)
{
    COMM_RING_BUF *pbuf;


    switch (ch) {                                          /* Obtain pointer to communications channel */
        case COMM1:
             pbuf = &Comm1Buf;
             break;

        case COMM2:
             pbuf = &Comm2Buf;
             break;

        default:
             return;
    }
    if (pbuf->RingBufRxCtr < COMM_RX_BUF_SIZE) {           /* See if buffer is full                    */
        pbuf->RingBufRxCtr++;                              /* No, increment character count            */
        *pbuf->RingBufRxInPtr++ = c;                       /* Put character into buffer                */
        if (pbuf->RingBufRxInPtr == &pbuf->RingBufRx[COMM_RX_BUF_SIZE]) { /* Wrap IN pointer           */
            pbuf->RingBufRxInPtr = &pbuf->RingBufRx[0];
        }
        OSSemPost(pbuf->RingBufRxSem);                     /* Indicate that character was received     */
    }
}
