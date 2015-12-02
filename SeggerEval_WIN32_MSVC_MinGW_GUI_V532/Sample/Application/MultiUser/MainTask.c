/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.32 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only  be used  in accordance  with  a license  and should  not be  re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : MainTask.c
Purpose     : Starts multitasking of the multiuser sample
----------------------------------------------------------------------
*/

#ifndef SKIP_TEST

#include "GUI.h"
#include <stddef.h>

#if GUI_OS == 0
  #error Multitasking sample requires task awareness (#define GUI_OS 1)
#endif

#if (GUI_NUM_LAYERS < 3)
  #error This sample needs a configuration with multiple layers!
#endif

#ifndef WIN32 
  #include "RTOS.h"    // Definitions for embOS
  #define CREATE_TASK(pTCB, pName, pFunc, Priority, pStack)  OS_CREATETASK(pTCB, pName, pFunc, Priority, pStack)
  #define START_MT()  OS_Terminate(0)
  #define DELAY(t)    OS_Delay(t)
#else
  #include "SIM.h"     // Definitions for the Win32 simulation
  #define CREATE_TASK(pTCB, pName, pFunc, Priority, pStack)   SIM_CreateTask(pName, pFunc)
  #define START_MT()  SIM_Start()
  #define DELAY(t)    SIM_Delay(t)
#endif

//
// Recommended memory to run the sample with adequate performance
//
#define RECOMMENDED_MEMORY (1024L * 50)

void Task_0(void);
void Task_1(void);
void Task_2(void);

/*******************************************************************
*
*       Static data
*
********************************************************************
*/
#ifndef WIN32
  //
  // Stacks
  //
  static OS_STACKPTR int Stack_0[1200];
  static OS_STACKPTR int Stack_1[1200];
  static OS_STACKPTR int Stack_2[1200];
  static OS_STACKPTR int Stack_3[1200];
  static OS_TASK aTCB[4];               // Task control blocks
#endif

/*******************************************************************
*
*       Static code
*
********************************************************************
*/
/*******************************************************************
*
*       _GUI_Task
*
* Function description
*   This task does the background processing.
*   The MainTask job is to update invalid windows, but other things such as
*   evaluating mouse or touch input may also be done.
*/
static void _GUI_Task(void) {
  DELAY(500);
  while(1) {
    GUI_Exec();           // Do the background work ... Update windows etc.)
    GUI_X_ExecIdle();     // Nothing left to do for the moment ... Idle processing
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
  //
  // Init GUI
  //
  GUI_Init();
  //
  // Check if recommended memory for the sample is available
  //
  if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {
    GUI_ErrorOut("Not enough memory available."); 
    return;
  }
  //
  // Create tasks
  //
  CREATE_TASK(&aTCB[0], "Task_0",   Task_0,    100, Stack_0);
  CREATE_TASK(&aTCB[1], "Task_1",   Task_1,     50, Stack_1);
  CREATE_TASK(&aTCB[2], "Task_2",   Task_2,     50, Stack_2);
  CREATE_TASK(&aTCB[3], "GUI_TASK", _GUI_Task,   1, Stack_3);
  //
  // Start multitasking
  //
  START_MT();
}

#endif

/*************************** End of file ****************************/
