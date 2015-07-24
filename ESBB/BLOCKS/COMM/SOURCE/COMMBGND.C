/*
*********************************************************************************************************
*                                     Embedded Systems Building Blocks
*                                  Complete and Ready-to-Use Modules in C
*
*                                    Asynchronous Serial Communications
*                                          Buffered Serial I/O
*                                     (Foreground/Background Systems)
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* Filename   : COMMBGND.C
* Programmer : Jean J. Labrosse
*
* Notes      : The functions (actually macros) OS_ENTER_CRITICAL() and OS_EXIT_CRITICAL() are used to
*              disable and enable interrupts, respectively.  If using the Borland C++ compiler V3.1,
*              all you need to do is to define these macros as follows:
*
*                   #define OS_ENTER_CRITICAL()  disable()
*                   #define OS_EXIT_CRITICAL()   enable()
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
    INT16U  RingBufRxCtr;                   /* Number of characters in the Rx ring buffer              */
    INT8U  *RingBufRxInPtr;                 /* Pointer to where next character will be inserted        */
    INT8U  *RingBufRxOutPtr;                /* Pointer from where next character will be extracted     */
    INT8U   RingBufRx[COMM_RX_BUF_SIZE];    /* Ring buffer character storage (Rx)                      */
    INT16U  RingBufTxCtr;                   /* Number of characters in the Tx ring buffer              */
    INT8U  *RingBufTxInPtr;                 /* Pointer to where next character will be inserted        */
    INT8U  *RingBufTxOutPtr;                /* Pointer from where next character will be extracted     */
    INT8U   RingBufTx[COMM_TX_BUF_SIZE];    /* Ring buffer character storage (Tx)                      */
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
*               channel.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*               'err'   is a pointer to where an error code will be placed:
*                           *err is set to COMM_NO_ERR   if a character is available
*                           *err is set to COMM_RX_EMPTY if the Rx buffer is empty
*                           *err is set to COMM_BAD_CH   if you have specified an invalid channel
* Returns     : The character in the buffer (or NUL if the buffer is empty)
*********************************************************************************************************
*/

INT8U  CommGetChar (INT8U ch, INT8U *err)
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
    OS_ENTER_CRITICAL();
    if (pbuf->RingBufRxCtr > 0) {                          /* See if buffer is empty                   */
        pbuf->RingBufRxCtr--;                              /* No, decrement character count            */
        c = *pbuf->RingBufRxOutPtr++;                      /* Get character from buffer                */
        if (pbuf->RingBufRxOutPtr == &pbuf->RingBufRx[COMM_RX_BUF_SIZE]) {     /* Wrap OUT pointer     */
            pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];
        }
        OS_EXIT_CRITICAL();
        *err = COMM_NO_ERR;
        return (c);
    } else {
        OS_EXIT_CRITICAL();
        *err = COMM_RX_EMPTY;
        c    = NUL;                                        /* Buffer is empty, return NUL              */
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
*                           *err is set to COMM_NO_ERR         if at least one character was left in the
*                                                              buffer.
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
    pbuf->RingBufTxCtr    = 0;
    pbuf->RingBufTxInPtr  = &pbuf->RingBufTx[0];
    pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];

    pbuf                  = &Comm2Buf;                     /* Initialize the ring buffer for COMM2     */
    pbuf->RingBufRxCtr    = 0;
    pbuf->RingBufRxInPtr  = &pbuf->RingBufRx[0];
    pbuf->RingBufRxOutPtr = &pbuf->RingBufRx[0];
    pbuf->RingBufTxCtr    = 0;
    pbuf->RingBufTxInPtr  = &pbuf->RingBufTx[0];
    pbuf->RingBufTxOutPtr = &pbuf->RingBufTx[0];
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  SEE IF RX CHARACTER BUFFER IS EMPTY
*
*
* Description : This function is called by your application to see if any character is available from the
*               communications channel.  If at least one character is available, the function returns
*               FALSE otherwise, the function returns TRUE.
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
* Returns     : TRUE    if the buffer IS empty.
*               FALSE   if the buffer IS NOT empty or you have specified an incorrect channel
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
*               FALSE   if the buffer IS NOT full or you have specified an incorrect channel
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
*               channel.  The character to send is first inserted into the Tx buffer and will be sent by
*               the Tx ISR.  If this is the first character placed into the buffer, the Tx ISR will be
*               enabled.  If the Tx buffer is full, the character will not be sent (i.e. it will be lost)
* Arguments   : 'ch'    is the COMM port channel number and can either be:
*                           COMM1
*                           COMM2
*               'c'     is the character to send.
* Returns     : COMM_NO_ERR   if the function was successful (the buffer was not full)
*               COMM_TX_FULL  if the buffer was full
*               COMM_BAD_CH   if you have specified an incorrect channel
*********************************************************************************************************
*/

INT8U  CommPutChar (INT8U ch, INT8U c)
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
             return (COMM_BAD_CH);
    }
    OS_ENTER_CRITICAL();
    if (pbuf->RingBufTxCtr < COMM_TX_BUF_SIZE) {           /* See if buffer is full                    */
        pbuf->RingBufTxCtr++;                              /* No, increment character count            */
        *pbuf->RingBufTxInPtr++ = c;                       /* Put character into buffer                */
        if (pbuf->RingBufTxInPtr == &pbuf->RingBufTx[COMM_TX_BUF_SIZE]) { /* Wrap IN pointer           */
            pbuf->RingBufTxInPtr = &pbuf->RingBufTx[0];
        }
        if (pbuf->RingBufTxCtr == 1) {                     /* See if this is the first character       */
            CommTxIntEn(ch);                               /* Yes, Enable Tx interrupts                */
            OS_EXIT_CRITICAL();
        } else {
            OS_EXIT_CRITICAL();
        }
        return (COMM_NO_ERR);
    } else {
        OS_EXIT_CRITICAL();
        return (COMM_TX_FULL);
    }
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
    }
}
