/*
*********************************************************************************************************
*                                          Analog I/O Module
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
* Filename   : AIO.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

#ifdef   AIO_GLOBALS
#define  AIO_EXT
#else
#define  AIO_EXT extern
#endif

/*
*********************************************************************************************************
*                                        CONFIGURATION CONSTANTS
*********************************************************************************************************
*/

#ifndef  CFG_H

#define  AIO_TASK_PRIO             40
#define  AIO_TASK_DLY             100       /* Task execution period in milliseconds                   */
#define  AIO_TASK_STK_SIZE        512

#define  AIO_MAX_AI                 8       /* Maximum number of Analog Input  Channels (1..250)       */
#define  AIO_MAX_AO                 8       /* Maximum number of Analog Output Channels (1..250)       */

#endif
/*$PAGE*/
/*
*********************************************************************************************************
*                                            DATA TYPES
*********************************************************************************************************
*/

typedef struct aio {                        /* ANALOG I/O CHANNEL DATA STRUCTURE                       */
    BOOLEAN   AIOBypassEn;                  /* Bypass enable switch (Bypass when TRUE)                 */
    INT16S    AIORaw;                       /* Raw counts of ADC or DAC                                */
    FP32      AIOEU;                        /* Engineering units of AI channel                         */
    FP32      AIOGain;                      /* Total gain   (AIOCalGain   * AIOConvGain)               */
    FP32      AIOOffset;                    /* Total offset (AIOCalOffset + AIOConvOffset)             */
    INT16S    AIOLim;                       /* Maximum count of an analog output channel               */
    INT8U     AIOPassCnts;                  /* Pass counts                                             */
    INT8U     AIOPassCtr;                   /* Pass counter (loaded from PassCnts)                     */
    FP32      AIOCalGain;                   /* Calibration gain                                        */
    FP32      AIOCalOffset;                 /* Calibration offset                                      */
    FP32      AIOConvGain;                  /* Conversion gain                                         */
    FP32      AIOConvOffset;                /* Conversion offset                                       */
    FP32      AIOScaleIn;                   /* Input  to   scaling function                            */
    FP32      AIOScaleOut;                  /* Output from scaling function                            */
    void    (*AIOScaleFnct)(struct aio *paio);   /* Function to execute for further processing         */
    void     *AIOScaleFnctArg;                   /* Pointer to argument to pass to 'AIOScaleFnct'      */
} AIO;

/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

AIO_EXT   AIO      AITbl[AIO_MAX_AI];
AIO_EXT   AIO      AOTbl[AIO_MAX_AO];

/*$PAGE*/
/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void     AIOInit(void);

INT8U    AICfgCal(INT8U n, FP32 gain, FP32 offset);
INT8U    AICfgConv(INT8U n, FP32 gain, FP32 offset, INT8U pass);
INT8U    AICfgScaling(INT8U n, void (*fnct)(AIO *paio), void *arg);
INT8U    AISetBypass(INT8U n, FP32 val);
INT8U    AISetBypassEn(INT8U n, BOOLEAN state);
INT8U    AIGet(INT8U n, FP32 *pval);

INT8U    AOCfgCal(INT8U n, FP32 gain, FP32 offset);
INT8U    AOCfgConv(INT8U n, FP32 gain, FP32 offset, INT16S lim, INT8U pass);
INT8U    AOCfgScaling(INT8U n, void (*fnct)(AIO *paio), void *arg);
INT8U    AOSet(INT8U n, FP32 val);
INT8U    AOSetBypass(INT8U n, FP32 val);
INT8U    AOSetBypassEn(INT8U n, BOOLEAN state);

void     AIOInitIO(void);                        /* Hardware dependant functions                       */
INT16S   AIRd(INT8U ch);
void     AOWr(INT8U ch, INT16S cnts);
