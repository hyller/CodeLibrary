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
* Filename   : DIO.H
* Programmer : Jean J. Labrosse
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                        CONFIGURATION CONSTANTS
*********************************************************************************************************
*/

#ifndef  CFG_H

#define  DIO_TASK_PRIO             40
#define  DIO_TASK_DLY_TICKS         1
#define  DIO_TASK_STK_SIZE        512

#define  DIO_MAX_DI                 8       /* Maximum number of Discrete Input  Channels (1..255)     */
#define  DIO_MAX_DO                 8       /* Maximum number of Discrete Output Channels (1..255)     */

#define  DI_EDGE_EN                 1       /* Enable code generation to support edge trig. (when 1)   */

#define  DO_BLINK_MODE_EN           1       /* Enable code generation to support blink mode (when 1)   */

#endif

#ifdef   DIO_GLOBALS
#define  DIO_EXT
#else
#define  DIO_EXT  extern
#endif

/*
*********************************************************************************************************
*                                       DISCRETE INPUT CONSTANTS
*********************************************************************************************************
*/

                                            /* DI MODE SELECTOR VALUES                                 */
#define  DI_MODE_LOW                0       /* Input is forced low                                     */
#define  DI_MODE_HIGH               1       /* Input is forced high                                    */
#define  DI_MODE_DIRECT             2       /* Input is based on state of physical input               */
#define  DI_MODE_INV                3       /* Input is based on the complement of the physical input  */
#define  DI_MODE_EDGE_LOW_GOING     4       /* Low  going edge detection of input                      */
#define  DI_MODE_EDGE_HIGH_GOING    5       /* High going edge detection of input                      */
#define  DI_MODE_EDGE_BOTH          6       /* Both low and high going edge detection of input         */
#define  DI_MODE_TOGGLE_LOW_GOING   7       /* Low  going edge detection of input                      */
#define  DI_MODE_TOGGLE_HIGH_GOING  8       /* High going edge detection of input                      */

                                            /* DI EDGE TRIGGERING MODE SELECTOR VALUES                 */
#define  DI_EDGE_LOW_GOING          0       /* Negative going edge                                     */
#define  DI_EDGE_HIGH_GOING         1       /* Positive going edge                                     */
#define  DI_EDGE_BOTH               2       /* Both positive and negative going                        */

/*$PAGE*/
/*
*********************************************************************************************************
*                                       DISCRETE OUTPUT CONSTANTS
*********************************************************************************************************
*/

                                            /* DO MODE SELECTOR VALUES                                 */
#define  DO_MODE_LOW                0       /* Output will be low                                      */
#define  DO_MODE_HIGH               1       /* Output will be high                                     */
#define  DO_MODE_DIRECT             2       /* Output is based on state of user supplied state         */
#define  DO_MODE_BLINK_SYNC         3       /* Sync.  Blink mode                                       */
#define  DO_MODE_BLINK_ASYNC        4       /* Async. Blink mode                                       */

                                            /* DO BLINK MODE ENABLE SELECTOR VALUES                    */
#define  DO_BLINK_EN                0       /* Blink is always enabled                                 */
#define  DO_BLINK_EN_NORMAL         1       /* Blink depends on user request's state                   */
#define  DO_BLINK_EN_INV            2       /* Blink depends on the complemented user request's state  */

/*
*********************************************************************************************************
*                                            DATA TYPES
*********************************************************************************************************
*/

typedef struct dio_di {                /* DISCRETE INPUT CHANNEL DATA STRUCTURE                        */
    BOOLEAN   DIIn;                    /* Current state of sensor input                                */
    INT16U    DIVal;                   /* State of discrete input channel (or # of transitions)        */
    BOOLEAN   DIPrev;                  /* Previous state of DIIn for edge detection                    */
    BOOLEAN   DIBypassEn;              /* Bypass enable switch (Bypass when TRUE)                      */
    INT8U     DIModeSel;               /* Discrete input channel mode selector                         */
#if DI_EDGE_EN
    void    (*DITrigFnct)(void *);     /* Function to execute if edge triggered                        */
    void     *DITrigFnctArg;           /* arguments passed to function when edge detected              */
#endif
} DIO_DI;


typedef struct dio_do {                /* DISCRETE OUTPUT CHANNEL DATA STRUCTURE                       */
    BOOLEAN   DOOut;                   /* Current state of discrete output channel                     */
    BOOLEAN   DOCtrl;                  /* Discrete output control request                              */
    BOOLEAN   DOBypass;                /* Discrete output control bypass state                         */
    BOOLEAN   DOBypassEn;              /* Bypass enable switch (Bypass when TRUE)                      */
    INT8U     DOModeSel;               /* Discrete output channel mode selector                        */
    INT8U     DOBlinkEnSel;            /* Blink enable mode selector                                   */
    BOOLEAN   DOInv;                   /* Discrete output inverter selector (Invert when TRUE)         */
#if DO_BLINK_MODE_EN
    INT8U     DOA;                     /* Blink mode ON time                                           */
    INT8U     DOB;                     /* Asynchronous blink mode period                               */
    INT8U     DOBCtr;                  /* Asynchronous blink mode period counter                       */
#endif
} DIO_DO;
/*$PAGE*/
/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/

DIO_EXT  DIO_DI      DITbl[DIO_MAX_DI];
DIO_EXT  DIO_DO      DOTbl[DIO_MAX_DO];

#if      DO_BLINK_MODE_EN
DIO_EXT  INT8U       DOSyncCtr;
DIO_EXT  INT8U       DOSyncCtrMax;
#endif

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void     DIOInit(void);

void     DICfgMode(INT8U n, INT8U mode);
INT16U   DIGet(INT8U n);
void     DISetBypassEn(INT8U n, BOOLEAN state);
void     DISetBypass(INT8U n, INT16U val);

#if      DI_EDGE_EN
void     DIClr(INT8U n);
void     DICfgEdgeDetectFnct(INT8U n, void (*fnct)(void *), void *arg);
#endif


void     DOCfgMode(INT8U n, INT8U mode, BOOLEAN inv);
BOOLEAN  DOGet(INT8U n);
void     DOSet(INT8U n, BOOLEAN state);
void     DOSetBypass(INT8U n, BOOLEAN state);
void     DOSetBypassEn(INT8U n, BOOLEAN state);

#if      DO_BLINK_MODE_EN
void     DOCfgBlink(INT8U n, INT8U mode, INT8U a, INT8U b);
void     DOSetSyncCtrMax(INT8U val);
#endif

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*                                           HARDWARE SPECIFIC
*********************************************************************************************************
*/

void     DIOInitIO(void);
void     DIRd(void);
void     DOWr(void);
