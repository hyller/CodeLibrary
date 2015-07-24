/*
*********************************************************************************************************
*                                          Analog I/O Module
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
* Filename   : AIO.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           INCLUDE FILES
*********************************************************************************************************
*/

#define   AIO_GLOBALS
#include "includes.h"

/*
*********************************************************************************************************
*                                          LOCAL VARIABLES
*********************************************************************************************************
*/

static  OS_STK      AIOTaskStk[AIO_TASK_STK_SIZE];
static  OS_EVENT   *AIOSem;

/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

        void        AIOTask(void *data);

static  void        AIInit(void);
static  void        AIUpdate(void);

static  void        AOInit(void);
static  void        AOUpdate(void);

/*$PAGE*/
/*
*********************************************************************************************************
*                 CONFIGURE THE CALIBRATION PARAMETERS OF AN ANALOG INPUT CHANNEL
*
* Description : This function is used to configure an analog input channel.
* Arguments   : n        is the analog input channel to configure:
*               gain     is the calibration gain
*               offset   is the calibration offset
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog input channel number.
*********************************************************************************************************
*/

INT8U  AICfgCal (INT8U n, FP32 gain, FP32 offset)
{
    INT8U err;
    AIO  *paio;


    if (n < AIO_MAX_AI) {
        paio               = &AITbl[n];               /* Point to Analog Input structure               */
        OSSemPend(AIOSem, 0, &err);                   /* Obtain exclusive access to AI channel         */
        paio->AIOCalGain   = gain;                    /* Store new cal. gain and offset into struct    */
        paio->AIOCalOffset = offset;
        paio->AIOGain      = paio->AIOCalGain   * paio->AIOConvGain;      /* Compute overall gain      */
        paio->AIOOffset    = paio->AIOCalOffset + paio->AIOConvOffset;    /* Compute overall offset    */
        OSSemPost(AIOSem);                                                /* Release AI channel        */
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                    CONFIGURE THE CONVERSION PARAMETERS OF AN ANALOG INPUT CHANNEL
*
* Description : This function is used to configure an analog input channel.
* Arguments   : n        is the analog channel to configure (0..AIO_MAX_AI-1).
*               gain     is the conversion gain
*               offset   is the conversion offset
*               pass     is the value for the pass counts
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog input channel number.
*********************************************************************************************************
*/

INT8U  AICfgConv (INT8U n, FP32 gain, FP32 offset, INT8U pass)
{
    INT8U err;
    AIO  *paio;


    if (n < AIO_MAX_AI) {
        paio                = &AITbl[n];              /* Point to Analog Input structure               */
        OSSemPend(AIOSem, 0, &err);                   /* Obtain exclusive access to AI channel         */
        paio->AIOConvGain   = gain;                   /* Store new conv. gain and offset into struct   */
        paio->AIOConvOffset = offset;
        paio->AIOGain       = paio->AIOCalGain   * paio->AIOConvGain;     /* Compute overall gain      */
        paio->AIOOffset     = paio->AIOCalOffset + paio->AIOConvOffset;   /* Compute overall offset    */
        paio->AIOPassCnts   = pass;
        OSSemPost(AIOSem);                                                /* Release AI channel        */
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                      CONFIGURE THE SCALING PARAMETERS OF AN ANALOG INPUT CHANNEL
*
* Description : This function is used to configure the scaling parameters associated with an analog
*               input channel.
* Arguments   : n        is the analog input channel to configure (0..AIO_MAX_AI-1).
*               arg      is a pointer to arguments needed by the scaling function
*               fnct     is a pointer to a scaling function
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog input channel number.
*********************************************************************************************************
*/

INT8U  AICfgScaling (INT8U n, void (*fnct)(AIO *paio), void *arg)
{
    AIO *paio;


    if (n < AIO_MAX_AI) {
        paio                  = &AITbl[n];            /* Faster to use a pointer to the structure      */
        OS_ENTER_CRITICAL();
        paio->AIOScaleFnct    = (void (*)())fnct;
        paio->AIOScaleFnctArg = arg;
        OS_EXIT_CRITICAL();
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                GET THE VALUE OF AN ANALOG INPUT CHANNEL
*
* Description : This function is used to get the currect value of an analog input channel (in engineering
*               units).
* Arguments   : n     is the analog input channel (0..AIO_MAX_AI-1).
*               pval  is a pointer to the destination engineering units of the analog input channel
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog input channel number.
*                        In this case, the destination is not changed.
*********************************************************************************************************
*/

INT8U  AIGet (INT8U n, FP32 *pval)
{
    AIO  *paio;


    if (n < AIO_MAX_AI) {
        paio  = &AITbl[n];
        OS_ENTER_CRITICAL();           /* Obtain exclusive access to AI channel                        */
        *pval = paio->AIOEU;           /* Get the engineering units of the analog input channel        */
        OS_EXIT_CRITICAL();            /* Release AI channel                                           */
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                     ANALOG INPUTS INITIALIZATION
*
* Description : This function initializes the analog input channels.
* Arguments   : None
* Returns     : None.
*********************************************************************************************************
*/

static  void  AIInit (void)
{
    INT8U   i;
    AIO    *paio;


    paio = &AITbl[0];
    for (i = 0; i < AIO_MAX_AI; i++) {
        paio->AIOBypassEn     =  FALSE;           /* Analog channel is not bypassed                     */
        paio->AIORaw          =  0x0000;          /* Raw counts of ADC or DAC                           */
        paio->AIOEU           = (FP32)0.0;        /* Engineering units of AI channel                    */
        paio->AIOGain         = (FP32)1.0;        /* Total gain                                         */
        paio->AIOOffset       = (FP32)0.0;        /* Total offset                                       */
        paio->AIOLim          =       0;
        paio->AIOPassCnts     =       1;          /* Pass counts                                        */
        paio->AIOPassCtr      =       1;          /* Pass counter                                       */
        paio->AIOCalGain      = (FP32)1.0;        /* Calibration gain                                   */
        paio->AIOCalOffset    = (FP32)0.0;        /* Calibration offset                                 */
        paio->AIOConvGain     = (FP32)1.0;        /* Conversion gain                                    */
        paio->AIOConvOffset   = (FP32)0.0;        /* Conversion offset                                  */
        paio->AIOScaleIn      = (FP32)0.0;        /* Input  to scaling function                         */
        paio->AIOScaleOut     = (FP32)0.0;        /* Output of scaling function                         */
        paio->AIOScaleFnct    = (void *)0;        /* No function to execute                             */
        paio->AIOScaleFnctArg = (void *)0;        /* No arguments to scale function                     */
        paio++;
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                   ANALOG I/O MANAGER INITIALIZATION
*
* Description : This function initializes the analog I/O manager module.
* Arguments   : None
* Returns     : None.
*********************************************************************************************************
*/

void  AIOInit (void)
{
    INT8U   err;


    AIInit();
    AOInit();
    AIOInitIO();
    AIOSem = OSSemCreate(1);                     /* Create a mutual exclusion semaphore for AIOs       */
    OSTaskCreateExt(AIOTask, (void *)0, &AIOTaskStk[AIO_TASK_STK_SIZE], AIO_TASK_PRIO,
                    AIO_TASK_PRIO, &AIOTaskStk[0], AIO_TASK_STK_SIZE, (void *)0, OS_TASK_OPT_SAVE_FP);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                      ANALOG I/O MANAGER TASK
*
* Description : This task is created by AIOInit() and is responsible for updating the analog inputs and
*               analog outputs.
*               AIOTask() executes every AIO_TASK_DLY milliseconds.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

void  AIOTask (void *data)
{
    INT8U err;


    data = data;                                 /* Avoid compiler warning                             */
    for (;;) {
        OSTimeDlyHMSM(0, 0, 0, AIO_TASK_DLY);    /* Delay between execution of AIO manager             */

        OSSemPend(AIOSem, 0, &err);              /* Obtain exclusive access to AI channels             */
        AIUpdate();                              /* Update all AI channels                             */
        OSSemPost(AIOSem);                       /* Release AI channels (Allow high prio. task to run) */

        OSSemPend(AIOSem, 0, &err);              /* Obtain exclusive access to AO channels             */
        AOUpdate();                              /* Update all AO channels                             */
        OSSemPost(AIOSem);                       /* Release AO channels (Allow high prio. task to run) */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                           SET THE STATE OF THE BYPASSED ANALOG INPUT CHANNEL
*
* Description : This function is used to set the engineering units of a bypassed analog input channel.
*               This function is used to simulate the presense of the sensor.  This function is only
*               valid if the bypass 'switch' is open.
* Arguments   : n     is the analog input channel (0..AIO_MAX_AI-1).
*               val   is the value of the bypassed analog input channel:
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog input channel number.
*               2        if AIOBypassEn was not set to TRUE
*********************************************************************************************************
*/

INT8U  AISetBypass (INT8U n, FP32 val)
{
    AIO   *paio;


    if (n < AIO_MAX_AI) {
        paio = &AITbl[n];                        /* Faster to use a pointer to the structure           */
        if (paio->AIOBypassEn == TRUE) {         /* See if the analog input channel is bypassed        */
            OS_ENTER_CRITICAL();
            paio->AIOEU = val;                   /* Yes, then set the new value of the channel         */
            OS_EXIT_CRITICAL();
            return (0);
        } else {
            return (2);
        }
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  SET THE STATE OF THE BYPASS SWITCH
*
* Description : This function is used to set the state of the bypass switch.  The analog input channel is
*               bypassed when the 'switch' is open (i.e. AIOBypassEn is set to TRUE).
* Arguments   : n      is the analog input channel (0..AIO_MAX_AI-1).
*               state  is the state of the bypass switch:
*                         FALSE disables the bypass (i.e. the bypass 'switch' is closed)
*                         TRUE  enables  the bypass (i.e. the bypass 'switch' is open)
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog input channel number.
*********************************************************************************************************
*/

INT8U  AISetBypassEn (INT8U n, BOOLEAN state)
{
    if (n < AIO_MAX_AI) {
        AITbl[n].AIOBypassEn = state;
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                   UPDATE ALL ANALOG INPUT CHANNELS
*
* Description : This function processes all of the analog input channels.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

static  void  AIUpdate (void)
{
    INT8U   i;
    AIO    *paio;


    paio = &AITbl[0];                            /* Point at first analog input channel                */
    for (i = 0; i < AIO_MAX_AI; i++) {           /* Process all analog input channels                  */
        if (paio->AIOBypassEn == FALSE) {        /* See if analog input channel is bypassed            */
            paio->AIOPassCtr--;                  /* Decrement pass counter                             */
            if (paio->AIOPassCtr == 0) {         /* When pass counter reaches 0, read and scale AI     */
                paio->AIOPassCtr = paio->AIOPassCnts;                /* Reload pass counter            */
                paio->AIORaw     = AIRd(i);                          /* Read ADC for this channel      */
                paio->AIOScaleIn = ((FP32)paio->AIORaw + paio->AIOOffset) * paio->AIOGain;
                if ((void *)paio->AIOScaleFnct != (void *)0) {       /* See if function defined        */
                    (*paio->AIOScaleFnct)(paio);                     /* Yes, execute function          */
                } else {
                    paio->AIOScaleOut = paio->AIOScaleIn;            /* No,  just copy data            */
                }
                paio->AIOEU = paio->AIOScaleOut;                     /* Output of scaling fnct to E.U. */
            }
        }
        paio++;                                                      /* Point at next AI channel       */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                 CONFIGURE THE CALIBRATION PARAMETERS OF AN ANALOG OUTPUT CHANNEL
*
* Description : This function is used to configure an analog output channel.
* Arguments   : n        is the analog output channel to configure (0..AIO_MAX_AO-1)
*               gain     is the calibration gain
*               offset   is the calibration offset
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog output channel number.
*********************************************************************************************************
*/

INT8U  AOCfgCal (INT8U n, FP32 gain, FP32 offset)
{
    INT8U  err;
    AIO   *paio;


    if (n < AIO_MAX_AO) {
        paio               = &AOTbl[n];               /* Point to Analog Output structure              */
        OSSemPend(AIOSem, 0, &err);                   /* Obtain exclusive access to AO channel         */
        paio->AIOCalGain   = gain;                    /* Store new cal. gain and offset into struct    */
        paio->AIOCalOffset = offset;
        paio->AIOGain      = paio->AIOCalGain   * paio->AIOConvGain;      /* Compute overall gain      */
        paio->AIOOffset    = paio->AIOCalOffset + paio->AIOConvOffset;    /* Compute overall offset    */
        OSSemPost(AIOSem);                                                /* Release AO channel        */
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                    CONFIGURE THE CONVERSION PARAMETERS OF AN ANALOG OUTPUT CHANNEL
*
* Description : This function is used to configure an analog output channel.
* Arguments   : n        is the analog channel to configure (0..AIO_MAX_AO-1).
*               gain     is the conversion gain
*               offset   is the conversion offset
*               pass     is the value for the pass counts
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog output channel number.
*********************************************************************************************************
*/

INT8U  AOCfgConv (INT8U n, FP32 gain, FP32 offset, INT16S lim, INT8U pass)
{
    INT8U err;
    AIO  *paio;


    if (n < AIO_MAX_AO) {
        paio                = &AOTbl[n];              /* Point to Analog Output structure              */
        OSSemPend(AIOSem, 0, &err);                   /* Obtain exclusive access to AO channel         */
        paio->AIOConvGain   = gain;                   /* Store new conv. gain and offset into struct   */
        paio->AIOConvOffset = offset;
        paio->AIOGain       = paio->AIOCalGain   * paio->AIOConvGain;     /* Compute overall gain      */
        paio->AIOOffset     = paio->AIOCalOffset + paio->AIOConvOffset;   /* Compute overall offset    */
        paio->AIOLim        = lim;
        paio->AIOPassCnts   = pass;
        OSSemPost(AIOSem);                                                /* Release AO channel        */
        return (0);
    } else {
        return (1);
    }
}
/*$PAGE*/
/*
*********************************************************************************************************
*                      CONFIGURE THE SCALING PARAMETERS OF AN ANALOG OUTPUT CHANNEL
*
* Description : This function is used to configure the scaling parameters associated with an analog
*               output channel.
* Arguments   : n        is the analog output channel to configure (0..AIO_MAX_AO-1).
*               arg      is a pointer to arguments needed by the scaling function
*               fnct     is a pointer to a scaling function
* Returns     : 0        if successfull.
*               1        if you specified an invalid analog output channel number.
*********************************************************************************************************
*/

INT8U  AOCfgScaling (INT8U n, void (*fnct)(AIO *paio), void *arg)
{
    AIO *paio;


    if (n < AIO_MAX_AO) {
        paio                  = &AOTbl[n];            /* Faster to use a pointer to the structure      */
        OS_ENTER_CRITICAL();
        paio->AIOScaleFnct    = (void (*)())fnct;
        paio->AIOScaleFnctArg = arg;
        OS_EXIT_CRITICAL();
        return (0);
    } else {
        return (1);
    }
}
/*$PAGE*/
/*
*********************************************************************************************************
*                                     ANALOG OUTPUTS INITIALIZATION
*
* Description : This function initializes the analog output channels.
* Arguments   : None
* Returns     : None.
*********************************************************************************************************
*/

static  void  AOInit (void)
{
    INT8U   i;
    AIO    *paio;


    paio = &AOTbl[0];
    for (i = 0; i < AIO_MAX_AO; i++) {
        paio->AIOBypassEn     = FALSE;           /* Analog channel is not bypassed                     */
        paio->AIORaw          = 0x0000;          /* Raw counts of ADC or DAC                           */
        paio->AIOEU           =  (FP32)0.0;      /* Engineering units of AI channel                    */
        paio->AIOGain         =  (FP32)1.0;      /* Total gain                                         */
        paio->AIOOffset       =  (FP32)0.0;      /* Total offset                                       */
        paio->AIOLim          =      0;          /* Maximum count of an analog output channel          */
        paio->AIOPassCnts     =      1;          /* Pass counts                                        */
        paio->AIOPassCtr      =      1;          /* Pass counter                                       */
        paio->AIOCalGain      =  (FP32)1.0;      /* Calibration gain                                   */
        paio->AIOCalOffset    =  (FP32)0.0;      /* Calibration offset                                 */
        paio->AIOConvGain     =  (FP32)1.0;      /* Conversion gain                                    */
        paio->AIOConvOffset   =  (FP32)0.0;      /* Conversion offset                                  */
        paio->AIOScaleIn      =  (FP32)0.0;      /* Input  to scaling function                         */
        paio->AIOScaleOut     =  (FP32)0.0;      /* Output of scaling function                         */
        paio->AIOScaleFnct    = (void *)0;       /* No function to execute                             */
        paio->AIOScaleFnctArg = (void *)0;       /* No arguments to scale function                     */
        paio++;
    }
}
/*$PAGE*/
/*
*********************************************************************************************************
*                                SET THE VALUE OF AN ANALOG OUTPUT CHANNEL
*
* Description : This function is used to set the currect value of an analog output channel
*               (in engineering units).
* Arguments   : n     is the analog output channel (0..AIO_MAX_AO-1).
*               val   is the desired analog output value in Engineering Units
* Returns     : 0     if successfull.
*               1     if you specified an invalid analog output channel number.
*********************************************************************************************************
*/

INT8U  AOSet (INT8U n, FP32 val)
{
    if (n < AIO_MAX_AO) {
        OS_ENTER_CRITICAL();
        AOTbl[n].AIOEU = val;          /* Set the engineering units of the analog output channel       */
        OS_EXIT_CRITICAL();
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                           SET THE STATE OF THE BYPASSED ANALOG OUTPUT CHANNEL
*
* Description : This function is used to set the engineering units of a bypassed analog output channel.
* Arguments   : n     is the analog output channel (0..AIO_MAX_AO-1).
*               val   is the value of the bypassed analog output channel:
* Returns     : 0     if successfull.
*               1     if you specified an invalid analog output channel number.
*               2     if AIOBypassEn is not set to TRUE
*********************************************************************************************************
*/

INT8U  AOSetBypass (INT8U n, FP32 val)
{
    AIO *paio;


    if (n < AIO_MAX_AO) {
        paio = &AOTbl[n];                        /* Faster to use a pointer to the structure           */
        if (paio->AIOBypassEn == TRUE) {         /* See if the analog output channel is bypassed       */
            OS_ENTER_CRITICAL();
            paio->AIOScaleIn = val;              /* Yes, then set the new value of the channel         */
            OS_EXIT_CRITICAL();
            return (0);
        } else {
            return (2);
        }
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  SET THE STATE OF THE BYPASS SWITCH
*
* Description : This function is used to set the state of the bypass switch.  The analog output channel
*               is bypassed when the 'switch' is open (i.e. AIOBypassEn is set to TRUE).
* Arguments   : n      is the analog output channel (0..AIO_MAX_AO-1).
*               state  is the state of the bypass switch:
*                         FALSE disables the bypass (i.e. the bypass 'switch' is closed)
*                         TRUE  enables  the bypass (i.e. the bypass 'switch' is open)
* Returns     : 0      if successfull.
*               1      if you specified an invalid analog output channel number.
*********************************************************************************************************
*/

INT8U  AOSetBypassEn (INT8U n, BOOLEAN state)
{
    INT8U err;


    if (n < AIO_MAX_AO) {
        AOTbl[n].AIOBypassEn = state;
        return (0);
    } else {
        return (1);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                   UPDATE ALL ANALOG OUTPUT CHANNELS
*
* Description : This function processes all of the analog output channels.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

static  void  AOUpdate (void)
{
    INT8U     i;
    AIO      *paio;
    INT16S    raw;


    paio = &AOTbl[0];                            /* Point at first analog output channel               */
    for (i = 0; i < AIO_MAX_AO; i++) {           /* Process all analog output channels                 */
        if (paio->AIOBypassEn == FALSE) {        /* See if analog output channel is bypassed           */
            paio->AIOScaleIn = paio->AIOEU;      /* No                                                 */
        }
        paio->AIOPassCtr--;                      /* Decrement pass counter                             */
        if (paio->AIOPassCtr == 0) {             /* When pass counter reaches 0, read and scale AI     */
            paio->AIOPassCtr = paio->AIOPassCnts;          /* Reload pass counter                      */
            if ((void *)paio->AIOScaleFnct != (void *)0) { /* See if function defined                  */
                (*paio->AIOScaleFnct)(paio);               /* Yes, execute function                    */
            } else {
                paio->AIOScaleOut = paio->AIOScaleIn;      /* No,  bypass scaling function             */
            }
            raw = (INT16S)(paio->AIOScaleOut * paio->AIOGain + paio->AIOOffset);
            if (raw > paio->AIOLim) {                      /* Never output > maximum DAC counts        */
                raw = paio->AIOLim;
            } else if (raw < 0) {                          /* DAC counts must always be >= 0           */
                raw = 0;
            }
            paio->AIORaw = raw;
            AOWr(i, paio->AIORaw);                         /* Write counts to DAC                      */
        }
        paio++;                                            /* Point at next AO channel                 */
    }
}

/*$PAGE*/
#ifndef CFG_C
/*
*********************************************************************************************************
*                                      INITIALIZE PHYSICAL I/Os
*
* Description : This function is called by AIOInit() to initialize the physical I/O used by the AIO
*               driver.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

void  AIOInitIO (void)
{
    /* This is where you will need to put you initialization code for the ADCs and DACs                */
    /* You should also consider initializing the contents of your DAC(s) to a known value.             */
}

/*
*********************************************************************************************************
*                                         READ PHYSICAL INPUTS
*
* Description : This function is called to read a physical ADC channel.  The function is assumed to
*               also control a multiplexer if more than one analog input is connected to the ADC.
* Arguments   : ch     is the ADC logical channel number (0..AIO_MAX_AI-1).
* Returns     : The raw ADC counts from the physical device.
*********************************************************************************************************
*/

INT16S  AIRd (INT8U ch)
{
    /* This is where you will need to provide the code to read your ADC(s).                            */
    /* AIRd() is passed a 'LOGICAL' channel number.  You will have to convert this logical channel     */
    /* number into actual physical port locations (or addresses) where your MUX. and ADCs are located. */
    /* AIRd() is responsible for:                                                                      */
    /*     1) Selecting the proper MUX. channel,                                                       */
    /*     2) Waiting for the MUX. to stabilize,                                                       */
    /*     3) Starting the ADC,                                                                        */
    /*     4) Waiting for the ADC to complete its conversion,                                          */
    /*     5) Reading the counts from the ADC and,                                                     */
    /*     6) Returning the counts to the calling function.                                            */

    return (ch);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                       UPDATE PHYSICAL OUTPUTS
*
* Description : This function is called to write the 'raw' counts to the proper analog output device
*               (i.e. DAC).  It is up to this function to direct the DAC counts to the proper DAC if more
*               than one DAC is used.
* Arguments   : ch     is  the DAC logical channel number (0..AIO_MAX_AO-1).
*               cnts   are the DAC counts to write to the DAC
* Returns     : None.
*********************************************************************************************************
*/

void  AOWr (INT8U ch, INT16S cnts)
{
    ch   = ch;
    cnts = cnts;

    /* This is where you will need to provide the code to update your DAC(s).                          */
    /* AOWr() is passed a 'LOGICAL' channel number.  You will have to convert this logical channel     */
    /* number into actual physical port locations (or addresses) where your DACs are located.          */
    /* AOWr() is responsible for writing the counts to the selected DAC based on a logical number.     */
}
#endif
