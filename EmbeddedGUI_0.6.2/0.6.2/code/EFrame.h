/*
    EmbeddedGUI Library version 0.6.2
    Copyright (C) 2011  WangChao

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation ,either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
	EFrame.h
*/

#ifndef EFRAME_H
#define EFRAME_H

#include "EGUIMacro.h"
#include "EComponent.h"
#include "ECursor.h"
#include "EControl.h"
#ifdef WIN32_SIMULATE
#include "ExtGDIplus.h"
#endif	//WIN32_SIMULATE

#ifdef DOT_MATRIX_LCD
#include "LCDDriver.h"
#endif  //DOT_MATRIX_LCD

class ESimpleWindow;

#ifdef EG_WINDOW_HOOK_FUNC
void EG_HookFunc_RedrawESimpleWindow(ESimpleWindow* wnd);
void EG_HookFunc_RedrawEWindow(ESimpleWindow* wnd);
#endif  //EG_WINDOW_HOOK_FUNC

class ESimpleWindow
{
public:
	ESimpleWindow();
	ESimpleWindow(char* title);
	~ESimpleWindow(void){}

	//return the control number.
	int AddControl(EControl* pControl){
		this->m_pcControlArray[this->m_uControlArrayCount]=pControl;
		return (++this->m_uControlArrayCount);
	}
	void RemoveAllControl();
	void RemoveLastControl();
	void RemoveControl(int controlNumber);

	//redraw functions
	//redraw all the controls1
	virtual void ForceRedrawAllControls();
	//only redraw the controls which need to be refresh.
	virtual void RedrawSelectedControls();
	//redraw the control with pos in its area.
	void RedrawControl(const EPosition& pos);
	// dispatch the event to the control which need to response.
	virtual void DispatchEvent(EEvent* curevent);
	virtual bool InWindowArea(EPosition curPos){
		//since the plainwindow represent all the space of LCD, always true.	
		return true;
	}
	virtual void RecoverWindow(){
		//do nothing
	}
	virtual unsigned char GetWindowState(){
		//always return 0, since SimpleWindow is always normal....
		return 0;
	}

	void SetWindowTitle(char* title){
		this->m_psTitle=title;
	}
	char* GetWindowTitle(){
		return this->m_psTitle;
	}
protected:
	EControl* SelectControl(EPosition curPos);

public:
	static const unsigned int UsualMaxControl=16;

protected:
	char* m_psTitle;
	unsigned int m_uControlArrayCount;
	EControl* m_pcControlArray[UsualMaxControl];
};

class EWindow: public ESimpleWindow{
public:
#ifdef EG_RGB_COLOR
	EWindow();
	EWindow(char* title,EPosition pos,ESize size,bool maxminWindow);
	EWindow(char* title,EPosition pos,ESize size,bool maxminWindow,EStyle* style);
#else
	EWindow();
	EWindow(char* title,EPosition pos,ESize size,bool maxminWindow);
#endif  //EG_RGB_COLOR
	~EWindow(){}

	//redraw all the controls
	virtual void ForceRedrawAllControls();
	//only redraw those controls which need to be updated. 
	virtual void RedrawSelectedControls();
	// dispatch the event to the control which need to response.
	virtual void DispatchEvent(EEvent* curevent);

	void MoveWindow(EPosition pos);
	void MaximizeWindow();
	void MaximizeWindow(ESize maximizeArea);
	void MinimizeWindow();
	virtual void RecoverWindow();

	void AppendToolBar(EToolBar* ptb,unsigned char dockState){
		this->m_pToolBar=ptb;
		this->m_pToolBar->SetDockState(dockState);
		this->AdjustBarPosition();
	}
	void AppendStatusBar(EStatusBar* psb,unsigned char dockState){
		this->m_pStatusBar=psb;
		this->m_pStatusBar->SetDockState(dockState);
		this->AdjustBarPosition();
	}
	void AppendPopupMenu(EPopupMenu* ppopmenu){
		this->m_pPopupMenu=ppopmenu;
	}

	//These Menu items belong to the window.
	unsigned int AddMenuItem(EMenu* pmenu);
	void RemoveMenuItem(unsigned int index);
	void RemoveAllMenuItems();

	EMenu* GetMenuItem(unsigned int index){
		return this->m_parrMenu[index];
	}
	EPosition* GetWindowPosition(){
		return &(this->m_pWindowPos);
	}
	ESize* GetWindowArea(){
		return &(this->m_zArea);
	}

#ifdef EG_RGB_COLOR
	void SetWindowStyle(EStyle* pstyle){
		this->m_pStyle=pstyle;
	}
	EStyle* GetWindowStyle(){
		return this->m_pStyle;
	}
#endif //EG_RGB_COLOR

	virtual unsigned char GetWindowState(){
		return this->m_uWindowState;
	}
	void ForceOpenNormalWindow(){
		this->m_uWindowState=0;
	}

public:
	static const unsigned int MaxMenuItem=6;

protected:
	virtual bool InWindowArea(EPosition curPos);
	bool InExitArea(EPosition curPos);
	bool InMaxArea(EPosition curPos);
	bool InMinArea(EPosition curPos);
	bool InTitleArea(EPosition curPos);

	void RedrawBaseWindow();

	//move the bar position if the window moves
	void AdjustBarPosition();
	//move the menu position if the window moves  
	void AdjustMenuPosition();
	//move all the controls
	void AdjustControlPosition(int deltaX,int deltaY);

protected:
#ifdef EG_RGB_COLOR
	EStyle* m_pStyle;
#endif
	bool m_bMaxMinButton;
	//  state  0 : normal
	//           1 : min
	//           2 : max
	unsigned char m_uWindowState;
#ifdef EG_RICH_STYLE
	unsigned char m_uWindowTitleHeight;
#endif  //EG_RICH_STYLE
	ESize m_zArea;
	ESize m_zOriginalArea;
	EPosition m_pWindowPos;
	EPosition m_pOriginalWindowPos;
	EToolBar* m_pToolBar;
	EStatusBar* m_pStatusBar;
	EPopupMenu* m_pPopupMenu;
	EMenu* m_parrMenu[MaxMenuItem];
	unsigned int m_uMenuItemCount;
};

#ifdef EG_DESKTOP_HOOK_FUNC
class ESimpleDesktop;
void EG_HookFunc_RedrawEDesktop(ESimpleDesktop* desk);
#endif //EG_DESKTOP_HOOK_FUNC

class ESimpleDesktop{
public:	
#ifdef WIN32_SIMULATE
#ifdef EG_SINGLE_COLOR
	ESimpleDesktop(EG_BinaryBufferDisplay* pBBDisp);
#else
	ESimpleDesktop(EG_RGBBufferDisplay* pRGBDisp);
#endif   //EG_SINGLE_COLOR
#else
	ESimpleDesktop();
#endif  //WIN32_SIMULATE
	
	//return the window index.
	int AddWindow(ESimpleWindow* pWindow);
	void AddWindow(ESimpleWindow* pWindow,unsigned char windowIndex);
	void RemoveAllWindow();
	void RemoveTopmostWindow();
	void RemoveWindow(unsigned char windowIndex);
	void SetWindowTopmost(unsigned char windowIndex);
	void SetWindowLayer(unsigned char windowIndex,unsigned char newLayer);

    // Flush buffer to RAM in LCD
	void RefreshLCD(){
#ifdef WIN32_SIMULATE
#ifdef EG_SINGLE_COLOR
		this->m_pBBDisplay->BufferDisplay();
#else
		this->m_pRGBDisplay->BufferDisplay();
#endif   //EG_SINGLE_COLOR
#else
		EG_LCDFlushBuffer();
#endif  //WIN32_SIMULATE
	}

	void GlobalRedraw();
	void SelectedRedraw();
	void ScheduleRedraw();
	virtual unsigned char DispatchEvent(EEvent* curevent);

//message  
//          1     LeftClick
//			 2     RightClick
//			 3     LeftDoubleClick
//			 4     RightDoubleClick
//			 5     MidClick
	void SetKeyboardEvent(const EPosition& cursorPos,unsigned int keyPressed);

#ifdef EG_CURSOR
	void SetCursorEvent(EEvent* e);
	void SetCursorEvent(const EPosition& cursorPos,unsigned int message);
	void SetCursorShape(const unsigned char* pcursor){
		this->m_cCursor.LoadCursorShape(pcursor);
	}
#endif //EG_CURSOR

	unsigned char GetWindowsCount(){
		return this->m_uWindowArrayCount;
	} 
	unsigned char GetWindowIndex(ESimpleWindow* pWindow);

	static void SetInstance(ESimpleDesktop* pInstance){
		m_pdInstance=pInstance;
	}
	static ESimpleDesktop* GetInstance(){
		return m_pdInstance;
	}

protected:
	virtual void RedrawDesktop(){
		EG_LCDClearBuffer();
	}	

public:

	static const unsigned char UsualMaxWindow=8;
	static const unsigned char SelectedRedrawRefreshThreshold=30;
	static const unsigned char ScheduleRedrawRefreshThreshold=100;

protected:

#ifdef WIN32_SIMULATE
#ifdef EG_SINGLE_COLOR
		
	EG_BinaryBufferDisplay* m_pBBDisplay;
#else
	EG_RGBBufferDisplay* m_pRGBDisplay;
#endif   //EG_SINGLE_COLOR
#endif  //WIN32_SIMULATE

#ifdef EG_CURSOR
	ECursor m_cCursor;
#endif //EG_CURSOR

	EPosition m_pCursorPosition;
	unsigned char m_uScheduleRedrawCount;
	unsigned char m_uSelectedRedrawCount;
	unsigned char m_uWindowArrayCount;
	//the last window added into this array will be the topmost.
	ESimpleWindow* m_pwWindowArray[UsualMaxWindow];
	static ESimpleDesktop* m_pdInstance;
};

class EDesktop: public ESimpleDesktop{
public:
#ifdef WIN32_SIMULATE
#ifdef EG_SINGLE_COLOR
	EDesktop(EG_BinaryBufferDisplay* pBBDisp);
#else
	EDesktop(EG_RGBBufferDisplay* pRGBDisp);
#endif  //EG_SINGLE_COLOR
#else
	EDesktop();
#endif //WIN32_SIMULATE

	unsigned int AddIconButton(EIconButton* pIconButton);
	void RemoveIconButton(unsigned int iconIndex);
	void RemoveAllIconButton();

#ifdef EG_RGB_COLOR
	EStyle* GetStyle(){
		return this->m_psStyle;
	}
	void SetStyle(EStyle* pStyle){
		this->m_psStyle=pStyle;
#ifdef EG_RICH_STYLE
		if(EG_FontHeight[this->m_psStyle->m_fFont.m_cFontNumber]<=10)
			this->m_zSystemStatusBar.m_uHeight=12;
		else
			this->m_zSystemStatusBar.m_uHeight=EG_FontHeight[this->m_psStyle->m_fFont.m_cFontNumber]+2;
#else
		this->m_zSystemStatusBar.m_uHeight=12;
#endif  //EG_RICH_STYLE
	}
#endif  //EG_RGB_COLOR

	ESize* GetSystemStatusBar(){
		return (&(this->m_zSystemStatusBar));
	}
	void SetSystemStatusBar(ESize systemBarSize){
		this->m_zSystemStatusBar=systemBarSize;	
	}

	void AppendPopupMenu(EPopupMenu* ppopupmenu){
		this->m_ppmBasePopupMenu=ppopupmenu;
		this->m_ppmBasePopupMenu->ClosePopupMenu();
	}
	void AppendStartMenu(EMenu* pMenu);
	void AppendClock(EClock* pClock);
	void AppendBackgroundBitmap(EBitmap* pBitmap){
		this->m_pBackgroundBitmap=pBitmap;	
	}
	void UpdateTime(unsigned char hour,unsigned char minute){
		if(this->m_ptTimeClock!=NULL){
			this->m_ptTimeClock->UpdateTime(hour,minute);
		}
	}
	void UpdateTime(unsigned char hour,unsigned char minute,unsigned char second){
		if(this->m_ptTimeClock!=NULL){
			this->m_ptTimeClock->UpdateTime(hour,minute,second);
		}
	}

	virtual unsigned char DispatchEvent(EEvent* curevent);

protected:
	void RecalculateWindowTitleCount();
	virtual void RedrawDesktop();
public:
	static const unsigned int MaxIconNumber=8;

protected:

#ifdef EG_RGB_COLOR
	EStyle* m_psStyle;
#endif  //EG_RGB_COLOR

	unsigned int m_uWindowTitleWidth;
	unsigned int m_uWindowTitleCount;
	EIconButton* m_pibIconArray[MaxIconNumber];
	unsigned int m_uIconArrayCount;
	ESize m_zSystemStatusBar;
	EMenu* m_pmStartMenu;
	EPopupMenu* m_ppmBasePopupMenu;
	EClock* m_ptTimeClock; 
	EBitmap* m_pBackgroundBitmap;
};

#endif  //EFRAME_H
