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
File        : XEye.c
Purpose     : Demonstrates the use of transparent windows
Requirements: WindowManager - (x)
              MemoryDevices - (x)
              AntiAliasing  - (x)
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
----------------------------------------------------------------------
*/

#include <math.h>
#include <stdlib.h>
#include "GUI.h"
#include "FRAMEWIN.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define FACTOR          5
#define EYE_X1         18
#define EYE_X2         54
#define EYE_Y          26
#define EYE_RX         16
#define EYE_RY         24
#define MIN_VISIBILITY 50    // Make sure at least this many pixels stay visible when moved */

//
// Recommended memory to run the sample with adequate performance
//
#define RECOMMENDED_MEMORY (1024L * 20)

/*********************************************************************
*
*       Static code, helper functions
*
**********************************************************************
*/
/*******************************************************************
*
*       _Min
*/
static int _Min(int a, int b) {
  return (a < b) ? a : b;
}

/*******************************************************************
*
*       _DrawEye
*/
static void _DrawEye(int xPos0, int yPos0, int xPos1, int yPos1, int rx, int ry) {
  int Hyp;
  int dx;
  int dy;
  int x;
  int y;

  GUI_SetColor(GUI_WHITE);
  GUI_FillEllipse(xPos0, yPos0, rx, ry);
  GUI_SetColor(GUI_BLACK);
  GUI_DrawEllipse(xPos0, yPos0, rx, ry);
  //
  // Calculate the coordinates
  //
  dx  = xPos1 - xPos0 + 1;
  dy  = yPos1 - yPos0 + 1;
  Hyp = GUI__sqrt32(dx * dx + dy * dy);
  x   = (dx * _Min(rx - 5, abs(dx)) * FACTOR / Hyp) + xPos0 * FACTOR;
  y   = (dy * _Min(ry - 5, abs(dy)) * FACTOR / Hyp) + yPos0 * FACTOR;
  //
  // Draw the pupil
  //
  GUI_AA_SetFactor(FACTOR);
  GUI_AA_EnableHiRes();
  GUI_SetColor(0xD00000);
  GUI_AA_FillCircle(x, y, (int)(5.75 * FACTOR));
  GUI_SetColor(GUI_BLACK);
  GUI_AA_FillCircle(x, y, (int)(3.75 * FACTOR));
  GUI_SetColor(GUI_GRAY);
  GUI_AA_FillCircle(x - (int)(1.25 * FACTOR), y - (int)(1.25 * FACTOR), (int)(1.25 * FACTOR));
  GUI_AA_DisableHiRes();
}

/*********************************************************************
*
*       _ClickedOutsideArea
*/
static int _ClickedOutsideArea(int mx, int my) {
  int ry;
  int x;
  int r;
  I32 Sum;
  int SumY;
  I32 OutConst;

  r        = 1;
  OutConst = (U32)(EYE_RX * EYE_RX) * (U32)(EYE_RY * EYE_RY) + (U32)(EYE_RX * EYE_RX * EYE_RY) / 2;
  ry       = (my < EYE_Y) ? (EYE_Y - my) : (my - EYE_Y);
  if (ry >= 0 && ry <= EYE_RY) {
    int y;
    x = EYE_RX;
    for (y = 0; y <= ry; y++) {
      SumY =((I32)(EYE_RX * EYE_RX)) * ((I32)(y * y));
      while (Sum = SumY + ((I32)(EYE_RY * EYE_RY)) * ((I32)(x * x)), (x > 0) && (Sum > OutConst)) {
        x--;
      }
    }
    if (((mx >= EYE_X1 - x) && (mx <= EYE_X1 + x)) || ((mx >= EYE_X2 - x) && (mx <= EYE_X2 + x))) {
      r = 0;
    }
  }
  return r;
}

/*********************************************************************
*
*       Static code, callbacks
*
**********************************************************************
*/
/*********************************************************************
*
*       _cbTransWindow
*/
static void _cbTransWindow(WM_MESSAGE* pMsg) {
  static GUI_PID_STATE   StateOld;
  GUI_PID_STATE        * pState;
  GUI_PID_STATE          StateNew;
  GUI_PID_STATE          State;
  WM_HWIN                hBelow;
  WM_HWIN                hWin;
  
  hWin = pMsg->hWin;
  GUI_PID_GetState(&StateNew);
  State    = ((StateNew.x == -1) && (StateNew.y == -1)) ? StateOld : StateNew;
  StateOld = State;
  switch (pMsg->MsgId) {
  case WM_PAINT:
    State.x -= WM_GetWindowOrgX(hWin);
    State.y -= WM_GetWindowOrgY(hWin);
    _DrawEye(EYE_X1, EYE_Y, State.x, State.y, EYE_RX, EYE_RY);
    _DrawEye(EYE_X2, EYE_Y, State.x, State.y, EYE_RX, EYE_RY);
    break;
  case WM_TOUCH:
    if (pMsg->Data.p) {
      pState = (GUI_PID_STATE *)pMsg->Data.p;
      if (pState->Pressed) {
        if (!_ClickedOutsideArea(pState->x, pState->y) || WM_HasCaptured(hWin)) {
          WM_SetCaptureMove(hWin, pState, MIN_VISIBILITY, 0);
        } else {
          //
          // Transfer the message to the underlying window, since the transparent area has been clicked
          //
          hBelow = WM_Screen2hWinEx(hWin, State.x, State.y);
          if (hBelow) {
            pState->x = State.x - WM_GetWindowOrgX(hBelow);
            pState->y = State.y - WM_GetWindowOrgY(hBelow);
            WM_SendMessage(hBelow, pMsg);
          }
        }
      }
    }
    break;
  default:
    WM_DefaultProc(pMsg);
  }
}


/*******************************************************************
*
*       _DemoTransWindow
*/
static void _DemoTransWindow(void) {
  WM_HWIN hTransWin;
  WM_HWIN hFrameWin;

  WM_SetDesktopColor(GUI_RED);
  hTransWin = WM_CreateWindow(10, 10, 72, 52, WM_CF_SHOW | WM_CF_HASTRANS | WM_CF_STAYONTOP, _cbTransWindow, 0);
  hFrameWin = FRAMEWIN_Create("Framewin", 0, WM_CF_SHOW, 100, 70, 120, 100);
  FRAMEWIN_SetActive(hFrameWin, 1);
  FRAMEWIN_SetMoveable(hFrameWin, 1);
  GUI_CURSOR_Show();
  while (1) {
    WM_InvalidateWindow(hTransWin);
    GUI_Delay(20);
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
  WM_SetCreateFlags(WM_CF_MEMDEV);
  GUI_Init();
  //
  // Check if recommended memory for the sample is available
  //
  if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {
    GUI_ErrorOut("Not enough memory available."); 
    return;
  }
  _DemoTransWindow();
}

/*************************** End of file ****************************/
