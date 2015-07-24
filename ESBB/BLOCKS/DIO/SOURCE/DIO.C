/*
*********************************************************************************************************
*                                   Embedded Systems Building Blocks
*                                Complete and Ready-to-Use Modules in C
*
*                                         Discrete I/O Module
*
*                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
*                                          All Rights Reserved
*
* Filename   : DIO.C
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           INCLUDE FILES
*********************************************************************************************************
*/

#define  DIO_GLOBALS
#include "includes.h"

/*
*********************************************************************************************************
*                                          LOCAL VARIABLES
*********************************************************************************************************
*/

static  OS_STK      DIOTaskStk[DIO_TASK_STK_SIZE];

/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/


static  void        DIIsTrig(DIO_DI *pdi);

static  void        DIOTask(void *data);

static  void        DIUpdate(void);

static  BOOLEAN     DOIsBlinkEn(DIO_DO *pdo);
static  void        DOUpdate(void);

/*$PAGE*/
/*
*********************************************************************************************************
*                               CONFIGURE DISCRETE INPUT EDGE DETECTION
*
* Description : This function is used to configure the edge detection capability of the discrete input
*               channel.
* Arguments   : n     is the discrete input channel to configure (0..DIO_MAX_DI-1).
*               fnct  is a pointer to a function that will be executed if the desired edge has been
*                     detected.
*               arg   is a pointer to arguments that are passed to the function called.
* Returns     : None.
*********************************************************************************************************
*/

#if  DI_EDGE_EN
void  DICfgEdgeDetectFnct (INT8U n, void (*fnct)(void *), void *arg)
{
    DIO_DI  *pdi;


    if (n < DIO_MAX_DI) {
        pdi                = &DITbl[n];
        OS_ENTER_CRITICAL();
        pdi->DITrigFnct    = fnct;
        pdi->DITrigFnctArg = arg;
        OS_EXIT_CRITICAL();
    }
}
#endif
/*$PAGE*/
/*
*********************************************************************************************************
*                                   CONFIGURE DISCRETE INPUT MODE
*
* Description : This function is used to configure the mode of a discrete input channel.
* Arguments   : n     is the discrete input channel to configure (0..DIO_MAX_DI-1).
*               mode  is the desired mode and can be:
*                     DI_MODE_LOW               input is forced LOW
*                     DI_MODE_HIGH              input is forced HIGH
*                     DI_MODE_DIRECT            input is based on state of physical sensor (default)
*                     DI_MODE_INV               input is based on the complement of physical sensor
*                     DI_MODE_EDGE_LOW_GOING    a LOW-going  transition is detected
*                     DI_MODE_EDGE_HIGH_GOING   a HIGH-going transition is detected
*                     DI_MODE_EDGE_BOTH         both a LOW-going and a HIGH-going transition are detected
*                     DI_MODE_TOGGLE_LOW_GOING  a LOW-going  transition is detected in toggle mode
*                     DI_MODE_TOGGLE_HIGH_GOING a HIGH-going transition is detected in toggle mode
* Returns     : None.
* Notes       : Edge detection is only available if the configuration constant DI_EDGE_EN is set to 1.
*********************************************************************************************************
*/

void  DICfgMode (INT8U n, INT8U mode)
{
    if (n < DIO_MAX_DI) {
        OS_ENTER_CRITICAL();
        DITbl[n].DIModeSel = mode;
        OS_EXIT_CRITICAL();
    }
}
/*$PAGE*/
/*
*********************************************************************************************************
*                                     CLEAR A DISCRETE INPUT CHANNEL
*
* Description : This function clears the number of edges detected if the discrete input channel is
*               configured to count edges.
* Arguments   : n     is the discrete input channel (0..DIO_MAX_DI-1) to clear.
* Returns     : none
*********************************************************************************************************
*/

#if  DI_EDGE_EN
void  DIClr (INT8U n)
{
    DIO_DI  *pdi;


    if (n < DIO_MAX_DI) {
        pdi = &DITbl[n];
        OS_ENTER_CRITICAL();
        if (pdi->DIModeSel == DI_MODE_EDGE_LOW_GOING  ||        /* See if edge detection mode selected */
            pdi->DIModeSel == DI_MODE_EDGE_HIGH_GOING ||
            pdi->DIModeSel == DI_MODE_EDGE_BOTH) {
            pdi->DIVal = 0;                                     /* Clear the number of edges detected  */
        }
        OS_EXIT_CRITICAL();
    }
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                GET THE STATE OF A DISCRETE INPUT CHANNEL
*
* Description : This function is used to get the current state of a discrete input channel.  If the input
*               mode is set to one of the edge detection modes, the number of edges detected is returned.
* Arguments   : n     is the discrete input channel (0..DIO_MAX_DI-1).
* Returns     : 0     if the discrete input is negated  or, if an edge has not been detected
*               1     if the discrete input is asserted
*               > 0   if edges have been detected
*********************************************************************************************************
*/

INT16U  DIGet (INT8U n)
{
    INT16U  val;


    if (n < DIO_MAX_DI) {
        OS_ENTER_CRITICAL();
        val = DITbl[n].DIVal;                              /* Get state of DI channel                  */
        OS_EXIT_CRITICAL();
        return (val);
    } else {
        return (0);                                        /* Return negated for invalid channel       */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         DETECT EDGE ON INPUT
*
* Description : This function is called to detect an edge (low-going, high-going or both) on the selected
*               discrete input.
* Arguments   : pdi    is a pointer to the discrete input data structure.
* Returns     : none
*********************************************************************************************************
*/

#if DI_EDGE_EN
static  void  DIIsTrig (DIO_DI *pdi)
{
    BOOLEAN  trig;


    trig = FALSE;
    switch (pdi->DIModeSel) {
        case DI_MODE_EDGE_LOW_GOING:                       /* Negative going edge                      */
             if (pdi->DIPrev == 1 && pdi->DIIn == 0) {
                 trig = TRUE;
             }
             break;

        case DI_MODE_EDGE_HIGH_GOING:                      /* Positive going edge                      */
             if (pdi->DIPrev == 0 && pdi->DIIn == 1) {
                 trig = TRUE;
             }
             break;

        case DI_MODE_EDGE_BOTH:                            /* Both positive and negative going         */
             if ((pdi->DIPrev == 1 && pdi->DIIn == 0) ||
                 (pdi->DIPrev == 0 && pdi->DIIn == 1)) {
                 trig = TRUE;
             }
             break;
    }
    if (trig == TRUE) {                                    /* See if edge detected                     */
        if (pdi->DITrigFnct != NULL) {                     /* Yes, see used defined a function         */
            (*pdi->DITrigFnct)(pdi->DITrigFnctArg);        /* Yes, execute the user function           */
        }
        if (pdi->DIVal < 255) {                            /* Increment number of edges counted        */
            pdi->DIVal++;
        }
    }
    pdi->DIPrev = pdi->DIIn;                               /* Memorize previous input state            */
}
#endif

/*$PAGE*/
/*$PAGE*/
/*
*********************************************************************************************************
*                                    UPDATE DISCRETE IN CHANNELS
*
* Description : This function processes all of the discrete input channels.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

static  void  DIUpdate (void)
{
    INT8U    i;
    DIO_DI  *pdi;


    pdi = &DITbl[0];
    for (i = 0; i < DIO_MAX_DI; i++) {
        if (pdi->DIBypassEn == FALSE) {          /* See if discrete input channel is bypassed          */
            switch (pdi->DIModeSel) {            /* No, process channel                                */
                case DI_MODE_LOW:                /* Input is forced low                                */
                     pdi->DIVal = 0;
                     break;

                case DI_MODE_HIGH:               /* Input is forced high                               */
                     pdi->DIVal = 1;
                     break;

                case DI_MODE_DIRECT:                  /* Input is based on state of physical input     */
                     pdi->DIVal = (INT8U)pdi->DIIn;   /* Obtain the state of the sensor                */
                     break;

                case DI_MODE_INV:                /* Input is based on the complement state of input    */
                     pdi->DIVal = (INT8U)(pdi->DIIn ? 0 : 1);
                     break;

#if DI_EDGE_EN
                case DI_MODE_EDGE_LOW_GOING:
                case DI_MODE_EDGE_HIGH_GOING:
                case DI_MODE_EDGE_BOTH:
                     DIIsTrig(pdi);              /* Handle edge triggered mode                         */
                     break;
#endif
/*$PAGE*/
                case DI_MODE_TOGGLE_LOW_GOING:
                     if (pdi->DIPrev == 1 && pdi->DIIn == 0) {
                         pdi->DIVal = pdi->DIVal ? 0 : 1;
                     }
                     pdi->DIPrev = pdi->DIIn;
                     break;

                case DI_MODE_TOGGLE_HIGH_GOING:
                     if (pdi->DIPrev == 0 && pdi->DIIn == 1) {
                         pdi->DIVal = pdi->DIVal ? 0 : 1;
                     }
                     pdi->DIPrev = pdi->DIIn;
                     break;
            }
        }
        pdi++;                                   /* Point to next DIO_DO element                       */
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  DISCRETE I/O MANAGER INITIALIZATION
*
* Description : This function initializes the discrete I/O manager module.
* Arguments   : None
* Returns     : None.
*********************************************************************************************************
*/

void  DIOInit (void)
{
    INT8U    err;
    INT8U    i;
    DIO_DI  *pdi;
    DIO_DO  *pdo;


    pdi = &DITbl[0];
    for (i = 0; i < DIO_MAX_DI; i++) {
        pdi->DIVal         = 0;
        pdi->DIBypassEn    = FALSE;
        pdi->DIModeSel     = DI_MODE_DIRECT;     /* Set the default mode to direct input               */
#if DI_EDGE_EN
        pdi->DITrigFnct    = (void *)0;          /* No function to execute when transition detected    */
        pdi->DITrigFnctArg = (void *)0;
#endif
        pdi++;
    }
    pdo = &DOTbl[0];
    for (i = 0; i < DIO_MAX_DO; i++) {
        pdo->DOOut        = 0;
        pdo->DOBypassEn   = FALSE;
        pdo->DOModeSel    = DO_MODE_DIRECT;      /* Set the default mode to direct output              */
        pdo->DOInv        = FALSE;
#if DO_BLINK_MODE_EN
        pdo->DOBlinkEnSel = DO_BLINK_EN_NORMAL;  /* Blinking is enabled by direct user request         */
        pdo->DOA          = 1;
        pdo->DOB          = 2;
        pdo->DOBCtr       = 2;
#endif
        pdo++;
    }
#if DO_BLINK_MODE_EN
    DOSyncCtrMax = 100;
#endif
    DIOInitIO();
    OSTaskCreate(DIOTask, (void *)0, &DIOTaskStk[DIO_TASK_STK_SIZE], DIO_TASK_PRIO);
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                    DISCRETE I/O MANAGER TASK
*
* Description : This task is created by DIOInit() and is responsible for updating the discrete inputs and
*               discrete outputs.
*               DIOTask() executes every DIO_TASK_DLY_TICKS.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

static  void  DIOTask (void *data)
{
    data = data;                                      /* Avoid compiler warning (uC/OS requirement)    */
    for (;;) {
        OSTimeDly(DIO_TASK_DLY_TICKS);                /* Delay between execution of DIO manager        */
        DIRd();                                       /* Read physical inputs and map to DI channels   */
        DIUpdate();                                   /* Update all DI channels                        */
        DOUpdate();                                   /* Update all DO channels                        */
        DOWr();                                       /* Map DO channels to physical outputs           */
    }
}
/*$PAGE*/

/*
*********************************************************************************************************
*                                  SET THE STATE OF THE BYPASSED SENSOR
*
* Description : This function is used to set the state of the bypassed sensor.  This function is used to
*               simulate the presence of the sensor.  This function is only valid if the bypass 'switch'
*               is open.
* Arguments   : n     is the discrete input channel (0..DIO_MAX_DI-1).
*               val   is the state of the bypassed sensor:
*                         0     indicates a  negated  sensor
*                         1     indicates an asserted sensor
*                         > 0   indicates the number of edges detected in edge mode
* Returns     : None.
*********************************************************************************************************
*/

void  DISetBypass (INT8U n, INT16U val)
{
    DIO_DI  *pdi;


    if (n < DIO_MAX_DI) {
        pdi = &DITbl[n];
        OS_ENTER_CRITICAL();
        if (pdi->DIBypassEn == TRUE) {           /* See if sensor is bypassed                          */
            pdi->DIVal = val;                    /* Yes, then set the new state of the DI channel      */
        }
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                               SET THE STATE OF THE SENSOR BYPASS SWITCH
*
* Description : This function is used to set the state of the sensor bypass switch.  The sensor is
*               bypassed when the 'switch' is open (i.e. DIBypassEn is set to TRUE).
* Arguments   : n     is the discrete input channel (0..DIO_MAX_DI-1).
*               state is the state of the bypass switch:
*                         FALSE disables sensor bypass (i.e. the bypass 'switch' is closed)
*                         TRUE  enables  sensor bypass (i.e. the bypass 'switch' is open)
* Returns     : None.
*********************************************************************************************************
*/

void  DISetBypassEn (INT8U n, BOOLEAN state)
{
    if (n < DIO_MAX_DI) {
        OS_ENTER_CRITICAL();
        DITbl[n].DIBypassEn = state;
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                             CONFIGURE THE DISCRETE OUTPUT BLINK MODE
*
* Description : This function is used to configure the blink mode of the discrete output channel.
* Arguments   : n     is the discrete output channel (0..DIO_MAX_DO-1).
*               mode  is the desired blink mode:
*                     DO_BLINK_EN         Blink is always enabled
*                     DO_BLINK_EN_NORMAL  Blink depends on user request's state
*                     DO_BLINK_EN_INV     Blink depends on the complemented user request's state
*               a     is the ON  time relative to how often the DIO task executes  (1..250)
*               b     is the period (in DO_MODE_BLINK_ASYNC mode) (1..250)
* Returns     : None.
*********************************************************************************************************
*/

#if  DO_BLINK_MODE_EN
void  DOCfgBlink (INT8U n, INT8U mode, INT8U a, INT8U b)
{
    DIO_DO  *pdo;


    if (n < DIO_MAX_DO) {
        pdo               = &DOTbl[n];
        OS_ENTER_CRITICAL();
        pdo->DOBlinkEnSel = mode;
        pdo->DOA          = a;
        pdo->DOB          = b;
        pdo->DOBCtr       = 0;
        OS_EXIT_CRITICAL();
    }
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                   CONFIGURE DISCRETE OUTPUT MODE
*
* Description : This function is used to configure the mode of a discrete output channel.
* Arguments   : n     is the discrete output channel to configure (0..DIO_MAX_DO-1).
*               mode  is the desired mode and can be:
*                     DO_MODE_LOW              output is forced LOW
*                     DO_MODE_HIGH             output is forced HIGH
*                     DO_MODE_DIRECT           output is based on state of DOBypass
*                     DO_MODE_BLINK_SYNC       output will be blinking synchronously with DOSyncCtr
*                     DO_MODE_BLINK_ASYNC      output will be blinking based on DOA and DOB
*               inv   indicates whether the output will be inverted:
*                     TRUE   forces the output to be inverted
*                     FALSE  does not cause any inversion
* Returns     : None.
*********************************************************************************************************
*/

void  DOCfgMode (INT8U n, INT8U mode, BOOLEAN inv)
{
    DIO_DO  *pdo;
    
    
    if (n < DIO_MAX_DO) {
        pdo            = &DOTbl[n];
        OS_ENTER_CRITICAL();
        pdo->DOModeSel = mode;
        pdo->DOInv     = inv;
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                 GET THE STATE OF THE DISCRETE OUTPUT
*
* Description : This function is used to obtain the state of the discrete output.
* Arguments   : n     is the discrete output channel (0..DIO_MAX_DO-1).
* Returns     : TRUE  if the output is asserted.
*               FALSE if the output is negated.
*********************************************************************************************************
*/

BOOLEAN  DOGet (INT8U n)
{
    BOOLEAN  out;


    if (n < DIO_MAX_DO) {
        OS_ENTER_CRITICAL();
        out = DOTbl[n].DOOut;
        OS_EXIT_CRITICAL();
        return (out);
    } else {
        return (FALSE);
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                         SEE IF BLINK IS ENABLED
*
* Description : See if blink mode is enabled.
* Arguments   : pdo    is a pointer to the discrete output data structure.
* Returns     : TRUE   if blinking is enabled
*               FALSE  otherwise
*********************************************************************************************************
*/

#if DO_BLINK_MODE_EN
static  BOOLEAN  DOIsBlinkEn (DIO_DO *pdo)
{
    BOOLEAN  en;


    en = FALSE;
    switch (pdo->DOBlinkEnSel) {
        case DO_BLINK_EN:                   /* Blink is always enabled                                 */
             en = TRUE;
             break;

        case DO_BLINK_EN_NORMAL:            /* Blink depends on user request's state                   */
             en = pdo->DOBypass;
             break;

        case DO_BLINK_EN_INV:               /* Blink depends on the complemented user request's state  */
             en = pdo->DOBypass ? FALSE : TRUE;
             break;
    }
    return (en);
}
#endif

/*$PAGE*/
/*
*********************************************************************************************************
*                                 SET THE STATE OF THE DISCRETE OUTPUT
*
* Description : This function is used to set the state of the discrete output.
* Arguments   : n     is the discrete output channel (0..DIO_MAX_DO-1).
*               state is the desired state of the output:
*                         FALSE indicates a  negated  output
*                         TRUE  indicates an asserted output
* Returns     : None.
* Notes       : The actual output will be complemented if 'DIInv' is set to TRUE.
*********************************************************************************************************
*/

void  DOSet (INT8U n, BOOLEAN state)
{
    if (n < DIO_MAX_DO) {
        OS_ENTER_CRITICAL();
        DOTbl[n].DOCtrl = state;
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  SET THE STATE OF THE BYPASSED OUTPUT
*
* Description : This function is used to set the state of the bypassed output.  This function is used to
*               override (or bypass) the application software and allow the output to be controlled
*               directly.  This function is only valid if the bypass switch is open.
* Arguments   : n       is the discrete output channel (0..DIO_MAX_DO-1).
*               state   is the desired state of the output:
*                         FALSE indicates a  negated  output
*                         TRUE  indicates an asserted output
* Returns     : None.
* Notes       : 1) The actual output will be complemented if 'DIInv' is set to TRUE.
*               2) In blink mode, this allows blinking to be enabled or not.
*********************************************************************************************************
*/

void  DOSetBypass (INT8U n, BOOLEAN state)
{
    DIO_DO  *pdo;
    
    
    if (n < DIO_MAX_DO) {
        pdo = &DOTbl[n];
        OS_ENTER_CRITICAL();
        if (pdo->DOBypassEn == TRUE) {
            pdo->DOBypass = state;
        }
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/
/*
*********************************************************************************************************
*                                  SET THE STATE OF THE OUTPUT BYPASS
*
* Description : This function is used to set the state of the output bypass switch.  The output is
*               bypassed when the 'switch' is open (i.e. DOBypassEn is set to TRUE).
* Arguments   : n     is the discrete output channel (0..DIO_MAX_DO-1).
*               state is the state of the bypass switch:
*                         FALSE disables output bypass (i.e. the switch is closed)
*                         TRUE  enables  output bypass (i.e. the switch is open)
* Returns     : None.
*********************************************************************************************************
*/

void  DOSetBypassEn (INT8U n, BOOLEAN state)
{
    if (n < DIO_MAX_DO) {
        OS_ENTER_CRITICAL();
        DOTbl[n].DOBypassEn = state;
        OS_EXIT_CRITICAL();
    }
}

/*$PAGE*/

/*
*********************************************************************************************************
*                            SET THE MAXIMUM VALUE FOR THE SYNCHRONOUS COUNTER
*
* Description : This function is used to set the maximum value taken by the synchronous counter which is
*               used in the synchronous blink mode.
* Arguments   : val   is the maximum value for the counter (1..255)
* Returns     : None.
*********************************************************************************************************
*/

#if  DO_BLINK_MODE_EN
void  DOSetSyncCtrMax (INT8U val)
{
    OS_ENTER_CRITICAL();
    DOSyncCtrMax = val;
    DOSyncCtr    = val;
    OS_EXIT_CRITICAL();
}
#endif
/*$PAGE*/
/*
*********************************************************************************************************
*                                    UPDATE DISCRETE OUT CHANNELS
*
* Description : This function is called to process all of the discrete output channels.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

static  void  DOUpdate (void)
{
    INT8U     i;
    BOOLEAN   out;
    DIO_DO   *pdo;


    pdo = &DOTbl[0];
    for (i = 0; i < DIO_MAX_DO; i++) {           /* Process all discrete output channels               */
        if (pdo->DOBypassEn == FALSE) {          /* See if DO channel is enabled                       */
            pdo->DOBypass = pdo->DOCtrl;         /* Obtain control state from application              */
        }
        out = FALSE;                             /* Assume that the output will be low unless changed  */
        switch (pdo->DOModeSel) {
            case DO_MODE_LOW:                    /* Output will in fact be low                         */
                 break;

            case DO_MODE_HIGH:                   /* Output will be high                                */
                 out = TRUE;
                 break;

            case DO_MODE_DIRECT:                 /* Output is based on state of user supplied state    */
                 out = pdo->DOBypass;
                 break;
/*$PAGE*/
#if DO_BLINK_MODE_EN
            case DO_MODE_BLINK_SYNC:                       /* Sync. Blink mode                         */
                 if (DOIsBlinkEn(pdo)) {                   /* See if Blink is enabled ...              */
                     if (pdo->DOA >= DOSyncCtr) {          /* ... yes, High when below threshold       */
                         out = TRUE;
                     }
                 }
                 break;

            case DO_MODE_BLINK_ASYNC:                      /* Async. Blink mode                        */
                 if (DOIsBlinkEn(pdo)) {                   /* See if Blink is enabled ...              */
                     if (pdo->DOA >= pdo->DOBCtr) {        /* ... yes, High when below threshold       */
                         out = TRUE;
                     }
                 }
                 if (pdo->DOBCtr < pdo->DOB) {             /* Update the threshold counter             */
                     pdo->DOBCtr++;
                 } else {
                     pdo->DOBCtr = 0;
                 }
                 break;
#endif
        }
        if (pdo->DOInv == TRUE) {                          /* See if output needs to be inverted ...   */
            pdo->DOOut = out ? FALSE : TRUE;               /* ... yes, complement output               */
        } else {
            pdo->DOOut = out;                              /* ... no,  no inversion!                   */
        }
        pdo++;                                             /* Point to next DIO_DO element             */
    }
#if DO_BLINK_MODE_EN
    if (DOSyncCtr < DOSyncCtrMax) {                        /* Update the synchronous free running ctr  */
        DOSyncCtr++;
    } else {
        DOSyncCtr = 0;
    }
#endif
}
/*$PAGE*/
#ifndef CFG_C
/*
*********************************************************************************************************
*                                      INITIALIZE PHYSICAL I/Os
*
* Description : This function is by DIOInit() to initialze the physical I/O used by the DIO driver.
* Arguments   : None.
* Returns     : None.
* Notes       : The physical I/O is assumed to be an 82C55 chip initialized as follows:
*                   Port A = OUT  (Discrete outputs)
*                   Port B = IN   (Discrete inputs)
*                   Port C = OUT  (not used)
*********************************************************************************************************
*/

void  DIOInitIO (void)
{
    outp(0x0303, 0x82);                          /* Port A = OUT, Port B = IN, Port C = OUT            */
}

/*
*********************************************************************************************************
*                                         READ PHYSICAL INPUTS
*
* Description : This function is called to read and map all of the physical inputs used for discrete
*               inputs and map these inputs to their appropriate discrete input data structure.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

void  DIRd (void)
{
    DIO_DI  *pdi;
    INT8U    i;
    INT8U    in;
    INT8U    msk;


    pdi = &DITbl[0];                                       /* Point at beginning of discrete inputs    */
    msk = 0x01;                                            /* Set mask to extract bit 0                */
    in  = inp(0x0301);                                     /* Read the physical port (8 bits)          */
    for (i = 0; i < 8; i++) {                              /* Map all 8 bits to first 8 DI channels    */
        pdi->DIIn   = (BOOLEAN)(in & msk) ? 1 : 0;
        msk       <<= 1;
        pdi++;
    }
}
/*$PAGE*/
/*
*********************************************************************************************************
*                                       UPDATE PHYSICAL OUTPUTS
*
* Description : This function is called to map all of the discrete output channels to their appropriate
*               physical destinations.
* Arguments   : None.
* Returns     : None.
*********************************************************************************************************
*/

void  DOWr (void)
{
    DIO_DO  *pdo;
    INT8U    i;
    INT8U    out;
    INT8U    msk;


    pdo = &DOTbl[0];                        /* Point at first discrete output channel                  */
    msk = 0x01;                             /* First DO will be mapped to bit 0                        */
    out = 0x00;                             /* Local 8 bit port image                                  */
    for (i = 0; i < 8; i++) {               /* Map first 8 DO to 8 bit port image                      */
        if (pdo->DOOut == TRUE) {
            out |= msk;
        }
        msk <<= 1;
        pdo++;
    }
    outp(0x0300, out);                      /* Output port image to physical port                      */
}
#endif
