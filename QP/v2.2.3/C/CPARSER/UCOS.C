/*
************************************************************
*                         UCOS.C
*                         KERNEL
************************************************************
*/
#include "INCLUDES.H"
#ifdef   TURBOC
#pragma  inline
#endif
/*
************************************************************
*                         TABLES
************************************************************
*/
UBYTE const OSMapTbl[]   = {0x01, 0x02, 0x04, 0x08,
                            0x10, 0x20, 0x40, 0x80};
UBYTE const OSUnMapTbl[] = {
    0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0};
/*
************************************************************
*                GLOBAL AND LOCAL VARIABLES
************************************************************
*/
        OS_TCB     *OSTCBCur;
        OS_TCB     *OSTCBHighRdy;
        OS_TCB     *OSTCBList;
        OS_TCB     *OSTCBPrioTbl[64];
        BOOLEAN     OSRunning;
        UBYTE       OSRdyGrp;
        UBYTE       OSRdyTbl[8];
        UBYTE       OSLockNesting;
        UBYTE       OSIntNesting;
        OS_TCB     *OSTCBFreeList;
/*
************************************************************
*                LOCAL FUNCTION PROTOTYPES
************************************************************
*/
static void  far   OSTaskIdle(void *data);
/*
************************************************************
*                   uCOS INITIALIZATION
************************************************************
*/
void OSInit(void *idle_task_stk, UBYTE maxtasks)
{
    UBYTE i;


    OSTCBCur      = (OS_TCB *)0;
    OSTCBList     = (OS_TCB *)0;
    OSIntNesting  = 0;
    OSLockNesting = 0;
    OSRunning     = 0;
    OSRdyGrp      = 0;
    for (i = 0; i < 8; i++) {
        OSRdyTbl[i] = 0;
    }
    for (i = 0; i < 64; i++) {
        OSTCBPrioTbl[i] = (OS_TCB *)0;
    }
    for (i = 0; i < (maxtasks - 1); i++) {
        OSTCBTbl[i].OSTCBNext = &OSTCBTbl[i+1];
    }
    OSTCBTbl[maxtasks-1].OSTCBNext = (OS_TCB *)0;
    OSTCBFreeList                  = &OSTCBTbl[0];
    OSTaskCreate(OSTaskIdle, (void *)0, idle_task_stk, OS_LO_PRIO);
}
/*
************************************************************
*                       IDLE TASK
************************************************************
*/
static void far OSTaskIdle(void *data)
{
    data = data;
    while (1)
        ;
}
/*
************************************************************
*                    START MULTITASKING
************************************************************
*/
void OSStart(void)
{
    UBYTE x, y, p;


    y            = OSUnMapTbl[OSRdyGrp];
    x            = OSRdyTbl[y];
    p            = (y << 3) + OSUnMapTbl[x];
    OSTCBHighRdy = OSTCBPrioTbl[p];
    OSTCBCur     = OSTCBHighRdy;
    OSRunning    = 1;
    OSStartHighRdy();
}
/*
************************************************************
*                RUN HIGHEST PRIORITY TASK
************************************************************
*/
void OSSched(void)
{
    UBYTE x, y, p;


    OS_ENTER_CRITICAL();
    if (OSLockNesting == 0 && OSIntNesting == 0) {
        y            = OSUnMapTbl[OSRdyGrp];
        x            = OSRdyTbl[y];
        p            = (y << 3) + OSUnMapTbl[x];
        OSTCBHighRdy = OSTCBPrioTbl[p];
        if (OSTCBHighRdy != OSTCBCur) {
            OS_TASK_SW();
        }
    }
    OS_EXIT_CRITICAL();
}
/*
************************************************************
*                        ENTER ISR
************************************************************
*/
void OSIntEnter(void)
{
    OS_ENTER_CRITICAL();
    OSIntNesting++;
    OS_EXIT_CRITICAL();
}
/*
************************************************************
*                        EXIT ISR
************************************************************
*/
void OSIntExit(void)
{
    UBYTE x, y, p;


    OS_ENTER_CRITICAL();
    if (--OSIntNesting == 0 && OSLockNesting == 0) {
        y            = OSUnMapTbl[OSRdyGrp];
        x            = OSRdyTbl[y];
        p            = (y << 3) + OSUnMapTbl[x];
        OSTCBHighRdy = OSTCBPrioTbl[p];
        if (OSTCBHighRdy != OSTCBCur) {
            OSIntCtxSw();
        }
    }
    OS_EXIT_CRITICAL();
}
/*
************************************************************
*          DELAY TASK 'n' TICKS   (n from 1 to 65535)
************************************************************
*/
void OSTimeDly(UWORD ticks)
{
    UBYTE p;


    OS_ENTER_CRITICAL();
    p = OSTCBCur->OSTCBPrio;
    if ((OSRdyTbl[p >> 3] &= ~OSMapTbl[p & 0x07]) == 0) {
        OSRdyGrp &= ~OSMapTbl[p >> 3];
    }
    OSTCBCur->OSTCBDly = ticks;
    OS_EXIT_CRITICAL();
    OSSched();
}
/*
************************************************************
*                  PROCESS SYSTEM TICK
************************************************************
*/
void OSTimeTick(void)
{
    UBYTE   p;
    OS_TCB *ptcb;


    ptcb = OSTCBList;
    while (ptcb->OSTCBPrio != OS_LO_PRIO) {
        OS_ENTER_CRITICAL();
        if (ptcb->OSTCBDly != 0) {
            if (--ptcb->OSTCBDly == 0) {
                p                 = ptcb->OSTCBPrio;
                OSRdyGrp         |= OSMapTbl[p >> 3];
                OSRdyTbl[p >> 3] |= OSMapTbl[p & 0x07];
            }
        }
        OS_EXIT_CRITICAL();
        ptcb = ptcb->OSTCBNext;
    }
}
/*
************************************************************
*                GET TCB FROM FREE TCB LIST
************************************************************
*/
OS_TCB *OSTCBGetFree(void)
{
    OS_TCB *ptcb;


    OS_ENTER_CRITICAL();
    ptcb          = OSTCBFreeList;
    OSTCBFreeList = ptcb->OSTCBNext;
    OS_EXIT_CRITICAL();
    return (ptcb);
}
/*
************************************************************
*                   PREVENT SCHEDULING
************************************************************
*/
void OSLock(void)
{
    OS_ENTER_CRITICAL();
    OSLockNesting++;
    OS_EXIT_CRITICAL();
}
/*
************************************************************
*                    ENABLE SCHEDULING
************************************************************
*/
void OSUnlock(void)
{
    OS_ENTER_CRITICAL();
    OSLockNesting--;
    OS_EXIT_CRITICAL();
    OSSched();
}
/*
************************************************************
*              CHANGE PRIORITY OF RUNNING TASK
************************************************************
*/
UBYTE OSChangePrio(UBYTE newp)
{
    UBYTE oldp;


    OS_ENTER_CRITICAL();
    if (OSTCBPrioTbl[newp] != (void *)0) {
        OS_EXIT_CRITICAL();
        return (OS_PRIO_EXIST);
    } else {
        oldp = OSTCBCur->OSTCBPrio;
        if ((OSRdyTbl[oldp >> 3] &= ~OSMapTbl[oldp & 0x07]) == 0) {
            OSRdyGrp &= ~OSMapTbl[oldp >> 3];
        }
        OSRdyGrp            |= OSMapTbl[newp >> 3];
        OSRdyTbl[newp >> 3] |= OSMapTbl[newp & 0x07];
        OSTCBCur->OSTCBPrio  = newp;
        OSTCBPrioTbl[newp]   = OSTCBCur;
        OSTCBPrioTbl[oldp]   = (void *)0;
        OS_EXIT_CRITICAL();
        OSSched();
        return (OS_NO_ERR);
    }
}
/*
************************************************************
*                    DELETE RUNNING TASK
************************************************************
*/
void OSTaskDelete(void)
{
    UBYTE p;


    OS_ENTER_CRITICAL();
    p               = OSTCBCur->OSTCBPrio;
    OSTCBPrioTbl[p] = (OS_TCB *)0;
    if ((OSRdyTbl[p >> 3] &= ~OSMapTbl[p & 0x07]) == 0) {
        OSRdyGrp &= ~OSMapTbl[p >> 3];
    }
    if (OSTCBCur->OSTCBPrev == (OS_TCB *)0) {
        OSTCBCur->OSTCBNext->OSTCBPrev = (OS_TCB *)0;
        OSTCBList                      =  OSTCBCur->OSTCBNext;  /* Rev. A, This line was missing   */
    } else {
        OSTCBCur->OSTCBPrev->OSTCBNext = OSTCBCur->OSTCBNext;
        OSTCBCur->OSTCBNext->OSTCBPrev = OSTCBCur->OSTCBPrev;
    }
    OSTCBCur->OSTCBNext = OSTCBFreeList;
    OSTCBFreeList       = OSTCBCur;
    OS_EXIT_CRITICAL();
    OSSched();
}
/*
************************************************************
*                   INITIALIZE SEMAPHORE
************************************************************
*/
UBYTE OSSemInit(OS_SEM *psem, WORD cnt)
{
    OS_ENTER_CRITICAL();
    if (cnt >= 0) {
        psem->OSSemCnt    = cnt;
        psem->OSSemGrp    = 0x00;
        psem->OSSemTbl[0] = 0x00;
        psem->OSSemTbl[1] = 0x00;
        psem->OSSemTbl[2] = 0x00;
        psem->OSSemTbl[3] = 0x00;
        psem->OSSemTbl[4] = 0x00;
        psem->OSSemTbl[5] = 0x00;
        psem->OSSemTbl[6] = 0x00;
        psem->OSSemTbl[7] = 0x00;
        OS_EXIT_CRITICAL();
        return (OS_NO_ERR);
    } else {
        OS_EXIT_CRITICAL();
        return (OS_SEM_ERR);
    }
}
/*
************************************************************
*                     PEND ON SEMAPHORE
************************************************************
*/
UBYTE OSSemPend(OS_SEM *psem, UWORD timeout)
{
    UBYTE x, y, bitx, bity;


    OS_ENTER_CRITICAL();
    if (psem->OSSemCnt-- > 0) {
        OS_EXIT_CRITICAL();
        return (OS_NO_ERR);
    } else {
        OSTCBCur->OSTCBStat |= OS_STAT_SEM;
        OSTCBCur->OSTCBDly   = timeout;
        y                    = OSTCBCur->OSTCBPrio >> 3;
        x                    = OSTCBCur->OSTCBPrio & 0x07;
        bity                 = OSMapTbl[y];
        bitx                 = OSMapTbl[x];
        if ((OSRdyTbl[y] &= ~bitx) == 0)
            OSRdyGrp &= ~bity;
        psem->OSSemTbl[y] |= bitx;
        psem->OSSemGrp    |= bity;
        OS_EXIT_CRITICAL();
        OSSched();
        OS_ENTER_CRITICAL();
        if (OSTCBCur->OSTCBStat & OS_STAT_SEM) {
            if ((psem->OSSemTbl[y] &= ~bitx) == 0) {
                psem->OSSemGrp &= ~bity;
            }
            OSTCBCur->OSTCBStat = OS_STAT_RDY;
            OS_EXIT_CRITICAL();
            return (OS_TIMEOUT);
        } else {
            OS_EXIT_CRITICAL();
            return (OS_NO_ERR);
        }
    }
}
/*
************************************************************
*                    POST TO A SEMAPHORE
************************************************************
*/
UBYTE OSSemPost(OS_SEM *psem)
{
    UBYTE x, y, bitx, bity, p;


    OS_ENTER_CRITICAL();
    if (psem->OSSemCnt < 32767) {
        if (psem->OSSemCnt++ >= 0) {
            OS_EXIT_CRITICAL();
        } else {
            if (psem->OSSemGrp != 0) {                          /* Rev. A, This line was missing   */
                y    = OSUnMapTbl[psem->OSSemGrp];
                x    = OSUnMapTbl[psem->OSSemTbl[y]];
                bity = OSMapTbl[y];
                bitx = OSMapTbl[x];
                if ((psem->OSSemTbl[y] &= ~bitx) == 0) {
                    psem->OSSemGrp &= ~bity;
                }
                p                           = (y << 3) + x;
                OSTCBPrioTbl[p]->OSTCBDly   =  0;
                OSTCBPrioTbl[p]->OSTCBStat &= ~OS_STAT_SEM;
                OSRdyGrp                   |=  bity;
                OSRdyTbl[y]                |=  bitx;
                OS_EXIT_CRITICAL();
                OSSched();
            } else {
                OS_EXIT_CRITICAL();
            }
        }
        return (OS_NO_ERR);
    } else {
        OS_EXIT_CRITICAL();
        return (OS_SEM_OVF);
    }
}
/*
************************************************************
*                   INITIALIZE MAILBOX
************************************************************
*/
UBYTE OSMboxInit(OS_MBOX *pmbox, void *msg)
{
    OS_ENTER_CRITICAL();
    pmbox->OSMboxMsg    = msg;
    pmbox->OSMboxGrp    = 0x00;
    pmbox->OSMboxTbl[0] = 0x00;
    pmbox->OSMboxTbl[1] = 0x00;
    pmbox->OSMboxTbl[2] = 0x00;
    pmbox->OSMboxTbl[3] = 0x00;
    pmbox->OSMboxTbl[4] = 0x00;
    pmbox->OSMboxTbl[5] = 0x00;
    pmbox->OSMboxTbl[6] = 0x00;
    pmbox->OSMboxTbl[7] = 0x00;
    OS_EXIT_CRITICAL();
    return (OS_NO_ERR);
}
/*
************************************************************
*                     PEND ON MAILBOX
************************************************************
*/
void *OSMboxPend(OS_MBOX *pmbox, UWORD timeout, UBYTE *err)
{
    UBYTE  x, y, bitx, bity;
    void  *msg;


    OS_ENTER_CRITICAL();
    if ((msg = pmbox->OSMboxMsg) != (void *)0) {
        pmbox->OSMboxMsg = (void *)0;
        OS_EXIT_CRITICAL();
        *err = OS_NO_ERR;
    } else {
        OSTCBCur->OSTCBStat |= OS_STAT_MBOX;
        OSTCBCur->OSTCBDly   = timeout;
        y                    = OSTCBCur->OSTCBPrio >> 3;
        x                    = OSTCBCur->OSTCBPrio & 0x07;
        bity                 = OSMapTbl[y];
        bitx                 = OSMapTbl[x];
        if ((OSRdyTbl[y] &= ~bitx) == 0) {
            OSRdyGrp &= ~bity;
        }
        pmbox->OSMboxTbl[y] |= bitx;
        pmbox->OSMboxGrp    |= bity;
        OS_EXIT_CRITICAL();
        OSSched();
        OS_ENTER_CRITICAL();
        if (OSTCBCur->OSTCBStat & OS_STAT_MBOX) {
            if ((pmbox->OSMboxTbl[y] &= ~bitx) == 0) {
                pmbox->OSMboxGrp &= ~bity;
            }
            OSTCBCur->OSTCBStat = OS_STAT_RDY;
            msg                 = (void *)0;
            OS_EXIT_CRITICAL();
            *err 		= OS_TIMEOUT;
        } else {
            msg                 = pmbox->OSMboxMsg;
            pmbox->OSMboxMsg    = (void *)0;
            OS_EXIT_CRITICAL();
            *err                = OS_NO_ERR;
        }
    }
    return (msg);
}
/*
************************************************************
*                    POST TO A MAILBOX
************************************************************
*/

UBYTE OSMboxPost(OS_MBOX *pmbox, void *msg)
{
    UBYTE x, y, bitx, bity, p;


    OS_ENTER_CRITICAL();
    if (pmbox->OSMboxMsg != (void *)0) {
        OS_EXIT_CRITICAL();
        return (OS_MBOX_FULL);
    } else {
        pmbox->OSMboxMsg = msg;
        if (pmbox->OSMboxGrp != 0) {                            /* Rev. A, This line was missing   */
            y                = OSUnMapTbl[pmbox->OSMboxGrp];
            x                = OSUnMapTbl[pmbox->OSMboxTbl[y]];
            bity             = OSMapTbl[y];
            bitx             = OSMapTbl[x];
            if ((pmbox->OSMboxTbl[y] &= ~bitx) == 0) {
                pmbox->OSMboxGrp &= ~bity;
            }
            p                           = (y << 3) + x;
            OSTCBPrioTbl[p]->OSTCBStat &= ~OS_STAT_MBOX;
            OSTCBPrioTbl[p]->OSTCBDly   =  0;
            OSRdyGrp                   |= bity;
            OSRdyTbl[y]                |= bitx;
            OS_EXIT_CRITICAL();
            OSSched();
        } else {
            OS_EXIT_CRITICAL();
        }
        return (OS_NO_ERR);
    }
}
/*
************************************************************
*                    INITIALIZE QUEUE
************************************************************
*/
UBYTE OSQInit(OS_Q *pq, void **start, UBYTE size)
{
    OS_ENTER_CRITICAL();
    pq->OSQStart   = start;
    pq->OSQEnd     = &start[size];
    pq->OSQIn      = start;
    pq->OSQOut     = start;
    pq->OSQSize    = size;
    pq->OSQEntries = 0;
    pq->OSQGrp     = 0x00;
    pq->OSQTbl[0]  = 0x00;
    pq->OSQTbl[1]  = 0x00;
    pq->OSQTbl[2]  = 0x00;
    pq->OSQTbl[3]  = 0x00;
    pq->OSQTbl[4]  = 0x00;
    pq->OSQTbl[5]  = 0x00;
    pq->OSQTbl[6]  = 0x00;
    pq->OSQTbl[7]  = 0x00;
    OS_EXIT_CRITICAL();
    return (OS_NO_ERR);
}
/*
************************************************************
*                     PEND ON A QUEUE
************************************************************
*/
void *OSQPend(OS_Q *pq, UWORD timeout, UBYTE *err)
{
    UBYTE  x, y, bitx, bity;
    void  *msg;


    OS_ENTER_CRITICAL();
    if (pq->OSQEntries != 0) {
        msg = *pq->OSQOut++;
        pq->OSQEntries--;
        if (pq->OSQOut == pq->OSQEnd) {
            pq->OSQOut = pq->OSQStart;
        }
        OS_EXIT_CRITICAL();
        *err = OS_NO_ERR;
    } else {
        OSTCBCur->OSTCBStat |= OS_STAT_Q;
        OSTCBCur->OSTCBDly   = timeout;
        y                    = OSTCBCur->OSTCBPrio >> 3;
        x                    = OSTCBCur->OSTCBPrio & 0x07;
        bity                 = OSMapTbl[y];
        bitx                 = OSMapTbl[x];
        if ((OSRdyTbl[y] &= ~bitx) == 0) {
            OSRdyGrp &= ~bity;
        }
        pq->OSQTbl[y] |= bitx;
        pq->OSQGrp    |= bity;
        OS_EXIT_CRITICAL();
        OSSched();
        OS_ENTER_CRITICAL();
        if (OSTCBCur->OSTCBStat & OS_STAT_Q) {
            if ((pq->OSQTbl[y] &= ~bitx) == 0) {
                pq->OSQGrp &= ~bity;
            }
            OSTCBCur->OSTCBStat = OS_STAT_RDY;
            msg                 = (void *)0;
            OS_EXIT_CRITICAL();
            *err 		= OS_TIMEOUT;
        } else {
            msg = *pq->OSQOut++;
            pq->OSQEntries--;
            if (pq->OSQOut == pq->OSQEnd) {
                pq->OSQOut = pq->OSQStart;
            }
            OS_EXIT_CRITICAL();
            *err = OS_NO_ERR;
        }
    }
    return (msg);
}
/*
************************************************************
*                     POST TO A QUEUE
************************************************************
*/

UBYTE OSQPost(OS_Q *pq, void *msg)
{
    UBYTE x, y, bitx, bity, p;


    OS_ENTER_CRITICAL();
    if (pq->OSQEntries >= pq->OSQSize) {
        OS_EXIT_CRITICAL();
        return (OS_Q_FULL);
    } else {
        *pq->OSQIn++ = msg;
        pq->OSQEntries++;
        if (pq->OSQIn == pq->OSQEnd) {
            pq->OSQIn = pq->OSQStart;
        }
        if (pq->OSQGrp != 0) {                                  /* Rev. A, This line was missing   */
            y    = OSUnMapTbl[pq->OSQGrp];
            x    = OSUnMapTbl[pq->OSQTbl[y]];
            bity = OSMapTbl[y];
            bitx = OSMapTbl[x];
            if ((pq->OSQTbl[y] &= ~bitx) == 0) {
                pq->OSQGrp &= ~bity;
            }
            p                           = (y << 3) + x;
            OSTCBPrioTbl[p]->OSTCBStat &= ~OS_STAT_Q;
            OSTCBPrioTbl[p]->OSTCBDly   = 0;
            OSRdyGrp                   |= bity;
            OSRdyTbl[y]                |= bitx;
            OS_EXIT_CRITICAL();
            OSSched();
        } else {
            OS_EXIT_CRITICAL();
        }
        return (OS_NO_ERR);
    }
}
