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
Purpose     : Self executing emWin demo for VGA resolutions
---------------------------END-OF-HEADER------------------------------
*/

#include <stddef.h>

#ifdef WIN32
  #include "SIM.h"
#endif

#include "DIALOG.h"

/*********************************************************************
*
*       Forward declaration
*
**********************************************************************
*/
int    AppDashBoard(void);
int    AppCashTerminal(void);

/*********************************************************************
*
*       Externals
*
**********************************************************************
*/
extern GUI_CONST_STORAGE GUI_FONT GUI_FontAA2_21;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontAA2_32;
extern GUI_CONST_STORAGE GUI_BITMAP bmBlueBlack;
extern GUI_CONST_STORAGE GUI_BITMAP bmCashTerminal;
extern GUI_CONST_STORAGE GUI_BITMAP bmDashboard;
extern GUI_CONST_STORAGE GUI_BITMAP bmSeggerLogo;

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define APP_DASHBOARD    1
#define APP_CASHTERMINAL 2

//
// Recommended memory to run the sample with adequate performance
//
#define RECOMMENDED_MEMORY (1024L * 1000)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static int _AppSelection;
static int _AppSelectionOld;
static int _Break;

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _cbBkWin
*/
static void _cbBkWin(WM_MESSAGE * pMsg) {
  const WM_KEY_INFO * pKeyInfo;
  int                 NCode;
  int                 Id;

  switch (pMsg->MsgId) {
  case WM_KEY:
    pKeyInfo = (const WM_KEY_INFO*)pMsg->Data.p;
    if (pKeyInfo->PressedCnt > 0) {
      switch (pKeyInfo->Key) {
      case GUI_KEY_TAB:
        WM_SetFocusOnNextChild(pMsg->hWin);
        break;
      case GUI_KEY_BACKTAB:
        WM_SetFocusOnPrevChild(pMsg->hWin);
        break;
      case GUI_KEY_ESCAPE:
        _Break = 1;
        break;
      }
    }
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);    // Id of widget
    NCode = pMsg->Data.v;               // Notification code
    switch (NCode) {
    case WM_NOTIFICATION_RELEASED:      // React only if released
      switch (Id) {
      case GUI_ID_BUTTON0:
        _AppSelection = APP_DASHBOARD;
        break;
      case GUI_ID_BUTTON1:
        _AppSelection = APP_CASHTERMINAL;
        break;
      }
      break;
    }
    break;
  case WM_PAINT:
    GUI_DrawGradientV(0, 0, 639, 479, GUI_BLUE, GUI_BLACK);
    GUI_SetFont(&GUI_FontAA2_32);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringHCenterAt("emWin VGA Demonstration\n", 400, 44);
    GUI_SetFont(&GUI_FontAA2_21);
    GUI_DispStringHCenterAt("Press the 'Dashboard' or the 'Cash Terminal'\nbutton to start one of the applications\n", 320, 150);
    GUI_DrawBitmap(&bmSeggerLogo, 30, 30);
    break;
  }
}

/*********************************************************************
*
*       _CreateButton
*/
static WM_HWIN _CreateButton(int x, int y, int w, int h, int bx, int by, const char * pText, GUI_CONST_STORAGE GUI_BITMAP * pBm, int Id) {
  WM_HWIN hWin;

  hWin = BUTTON_CreateEx(x, y, w, h, WM_HBKWIN, WM_CF_SHOW, 0, Id);
  BUTTON_SetBitmapEx(hWin, 0, pBm, bx + 0, by + 0);
  BUTTON_SetBitmapEx(hWin, 1, pBm, bx + 1, by + 0);
  BUTTON_SetFont(hWin, &GUI_FontAA2_21);
  BUTTON_SetTextAlign(hWin, GUI_TA_TOP | GUI_TA_HCENTER);
  BUTTON_SetText(hWin, pText);
  BUTTON_SetBkColor(hWin, 0, GUI_LIGHTBLUE);
  return hWin;
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
void MainTask(void);
void MainTask(void) {
  static GUI_PID_STATE OldState;
  GUI_PID_STATE        CurrentState;
  int                  tEnd;

  GUI_Init();
  BUTTON_SetReactOnLevel();
  //
  // Check if recommended memory for the sample is available
  //
  if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {
    GUI_ErrorOut("Not enough memory available."); 
    return;
  }
  do {
    WM_HWIN hButton0, hButton1;
    WM_SetCallback(WM_HBKWIN, _cbBkWin);
    hButton0 = _CreateButton(100, 220, 170, 150, 5, 25, "Dashboard"    , &bmDashboard   , GUI_ID_BUTTON0);
    hButton1 = _CreateButton(370, 220, 170, 150, 5, 25, "Cash Terminal", &bmCashTerminal, GUI_ID_BUTTON1);
    WM_SetFocus(hButton0);
    tEnd = GUI_GetTime() + 4000;
    do {
      GUI_PID_GetState(&CurrentState);
      if ((OldState.x != CurrentState.x) || (OldState.y != CurrentState.y)) {
        tEnd = GUI_GetTime() + 10000;
      }
      OldState = CurrentState;
      GUI_Delay(100);
      if (GUI_GetTime() >= tEnd) {
        if (_AppSelectionOld) {
          _AppSelection = ((_AppSelectionOld - 1) ^ 1) + 1;
        } else {
          _AppSelection = APP_DASHBOARD;
        }
      }
    } while (!_AppSelection && !_Break);
    WM_DeleteWindow(hButton0);
    WM_DeleteWindow(hButton1);
    if (!_Break) {
      switch (_AppSelection) {
      case APP_DASHBOARD:
        AppDashBoard();
        break;
      case APP_CASHTERMINAL:
        AppCashTerminal();
        break;
      }
      GUI_CURSOR_Hide();
      _AppSelectionOld = _AppSelection;
      _AppSelection    = 0;
    }
  } while (!_Break);
}

/*************************** End of file ****************************/
