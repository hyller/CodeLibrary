/*
    EmbeddedGUI Library version 0.5.4
    Copyright (C) 2009  WangChao

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
	EFrame.cpp
*/

#include "EFrame.h"

#ifdef EG_WINDOW_HOOK_FUNC
void EG_HookFunc_RedrawESimpleWindow(ESimpleWindow* wnd){
	//user code here
}

void EG_HookFunc_RedrawEWindow(ESimpleWindow* wnd){
	//user code here
}
#endif  //EG_WINDOW_HOOK_FUNC

#ifdef EG_DESKTOP_HOOK_FUNC
void EG_HookFunc_RedrawEDesktop(ESimpleDesktop* desk){

}
#endif //EG_DESKTOP_HOOK_FUNC

ESimpleWindow::ESimpleWindow():m_uControlArrayCount(0){
	this->m_psTitle=NULL;
	for (int n=0;n<UsualMaxControl;n++){
		this->m_pcControlArray[n]=NULL;
	}
}

ESimpleWindow::ESimpleWindow(char* title):m_uControlArrayCount(0){
	this->m_psTitle=title;
	for (int n=0;n<UsualMaxControl;n++){
		this->m_pcControlArray[n]=NULL;
	}
}

void ESimpleWindow::RemoveAllControl(){
	for (unsigned int n=0;n<this->m_uControlArrayCount;n++)
		this->m_pcControlArray[n]=NULL;
	this->m_uControlArrayCount=0;
}

void ESimpleWindow::RemoveLastControl(){
	if (!this->m_uControlArrayCount){
		this->m_pcControlArray[this->m_uControlArrayCount-1]=NULL;
		this->m_uControlArrayCount--;
	}
}

void ESimpleWindow::RemoveControl(int controlNumber){
	if (this->m_uControlArrayCount!=0){//all the later control move to left.
		for(unsigned int n=controlNumber+1;n<this->m_uControlArrayCount;n++){
			this->m_pcControlArray[n-1]=this->m_pcControlArray[n];	
		}
		this->m_uControlArrayCount--;
	}
}

//redraw all the controls
void ESimpleWindow::ForceRedrawAllControls(){
#ifdef EG_WINDOW_HOOK_FUNC
	//draw the bottom window first
	EG_HookFunc_RedrawESimpleWindow(this);
#endif   //EG_WINDOW_HOOK_FUNC
	for (unsigned int n=0;n<this->m_uControlArrayCount;n++){
		this->m_pcControlArray[n]->RedrawControl();
	}
}

//only redraw the controls which need to be refresh.
void ESimpleWindow::RedrawSelectedControls(){
#ifdef EG_WINDOW_HOOK_FUNC
	//draw the bottom window first
	EG_HookFunc_RedrawESimpleWindow(this);
#endif   //EG_WINDOW_HOOK_FUNC
	for (unsigned int n=0;n<this->m_uControlArrayCount;n++){
		if(this->m_pcControlArray[n]->m_bNeedRedraw){
			//in the redraw function, m_bNeedRedraw will be set to false.
			this->m_pcControlArray[n]->RedrawControl();
		}
	}
}

void ESimpleWindow::RedrawControl(const EPosition& pos){
#ifdef EG_WINDOW_HOOK_FUNC
	//draw the bottom window first
	EG_HookFunc_RedrawESimpleWindow(this);
#endif   //EG_WINDOW_HOOK_FUNC
	for (unsigned int n=0;n<this->m_uControlArrayCount;n++){
		if(this->m_pcControlArray[n]->InControlArea(pos)){
			//in the redraw function, m_bNeedRedraw will be set to false.
			this->m_pcControlArray[n]->RedrawControl();
		}
	}
}

// dispatch the event to the control which need to response.
void ESimpleWindow::DispatchEvent(EEvent* curevent){
	//the position of event determine the control which receive the event.
	EControl* pControl=this->SelectControl(curevent->m_pPosition);
	if (pControl!=NULL){
		pControl->NoticeControl(curevent);
	}
}

EControl* ESimpleWindow::SelectControl(EPosition curPos){
	for (int n=this->m_uControlArrayCount-1;n>=0;n--){
		EControl* end=this->m_pcControlArray[n];
		if (end->InControlArea(curPos)){
			return end;
		}		
	}
	return NULL;
}

#ifdef EG_RGB_COLOR
EWindow::EWindow()
	:ESimpleWindow(),m_uWindowState(0),m_zArea(ESize(0,0)),m_pWindowPos(EPosition(0,0)){
	this->m_bMaxMinButton=true;
	this->m_pStyle=&EG_DefaultStyle;
	this->m_zOriginalArea.m_uHeight=0;
	this->m_zOriginalArea.m_uWidth=0;
	this->m_pOriginalWindowPos.m_uX=0;
	this->m_pOriginalWindowPos.m_uY=0;
#ifdef EG_RICH_STYLE
	if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
		this->m_uWindowTitleHeight=10;
	else
		this->m_uWindowTitleHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#endif  //EG_RICH_STYLE
	this->m_pToolBar=NULL;
	this->m_pStatusBar=NULL;
	this->m_pPopupMenu=NULL;
	this->RemoveAllMenuItems();
}

EWindow::EWindow(char* title,EPosition pos,ESize size,bool maxminWindow)
	:ESimpleWindow(title),m_uWindowState(0),m_zArea(size),m_pWindowPos(pos){
	this->m_bMaxMinButton=maxminWindow;
	this->m_pStyle=&EG_DefaultStyle;
	this->m_zOriginalArea.m_uHeight=size.m_uHeight;
	this->m_zOriginalArea.m_uWidth=size.m_uWidth;
	this->m_pOriginalWindowPos.m_uX=pos.m_uX;
	this->m_pOriginalWindowPos.m_uY=pos.m_uY;
#ifdef EG_RICH_STYLE
	if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
		this->m_uWindowTitleHeight=10;
	else
		this->m_uWindowTitleHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#endif  //EG_RICH_STYLE
	this->m_pToolBar=NULL;
	this->m_pStatusBar=NULL;
	this->m_pPopupMenu=NULL;
	this->RemoveAllMenuItems();
}

EWindow::EWindow(char* title,EPosition pos,ESize size,bool maxminWindow,EStyle* style)
	:ESimpleWindow(title),m_uWindowState(0),m_zArea(size),m_pWindowPos(pos){
	this->m_bMaxMinButton=maxminWindow;
	this->m_pStyle=style;
#ifdef EG_RICH_STYLE
	if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
		this->m_uWindowTitleHeight=10;
	else
		this->m_uWindowTitleHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#endif  //EG_RICH_STYLE
	this->m_zOriginalArea.m_uHeight=size.m_uHeight;
	this->m_zOriginalArea.m_uWidth=size.m_uWidth;
	this->m_pOriginalWindowPos.m_uX=pos.m_uX;
	this->m_pOriginalWindowPos.m_uY=pos.m_uY;
	this->m_pToolBar=NULL;
	this->m_pStatusBar=NULL;
	this->m_pPopupMenu=NULL;
	this->RemoveAllMenuItems();
}

#else
EWindow::EWindow()
	:ESimpleWindow(),m_uWindowState(0),m_zArea(ESize(0,0)),m_pWindowPos(EPosition(0,0)){
	this->m_bMaxMinButton=true;
	this->m_zOriginalArea.m_uHeight=0;
	this->m_zOriginalArea.m_uWidth=0;
	this->m_pOriginalWindowPos.m_uX=0;
	this->m_pOriginalWindowPos.m_uY=0;
	this->m_pToolBar=NULL;
	this->m_pStatusBar=NULL;
	this->m_pPopupMenu=NULL;
	this->RemoveAllMenuItems();
}
	
EWindow::EWindow(char* title,EPosition pos,ESize size,bool maxminWindow)
	:ESimpleWindow(title),m_uWindowState(0),m_zArea(size),m_pWindowPos(pos){
	this->m_bMaxMinButton=maxminWindow;
	this->m_zOriginalArea.m_uHeight=size.m_uHeight;
	this->m_zOriginalArea.m_uWidth=size.m_uWidth;
	this->m_pOriginalWindowPos.m_uX=0;
	this->m_pOriginalWindowPos.m_uY=0;
	this->m_pToolBar=NULL;
	this->m_pStatusBar=NULL;
	this->m_pPopupMenu=NULL;
	this->RemoveAllMenuItems();
}

#endif  //EG_RGB_COLOR

void EWindow::MoveWindow(EPosition pos){
	int dx,dy;
	dx=pos.m_uX-m_pWindowPos.m_uX;
	dy=pos.m_uY-m_pWindowPos.m_uY;
	this->AdjustControlPosition(dx,dy);
	this->m_pWindowPos=pos;
	this->m_pOriginalWindowPos=pos;
	this->AdjustBarPosition();
	this->AdjustMenuPosition();
	this->ForceRedrawAllControls();
}

void EWindow::MaximizeWindow(){
	int dx,dy;
	dx=-static_cast<int>(m_pOriginalWindowPos.m_uX);
	dy=-static_cast<int>(m_pOriginalWindowPos.m_uY);
	this->AdjustControlPosition(dx,dy);
	this->m_pOriginalWindowPos=this->m_pWindowPos;
	this->m_pWindowPos.m_uX=0;
	this->m_pWindowPos.m_uY=0;
	this->m_zArea.m_uHeight=EG_ROW-1;
	this->m_zArea.m_uWidth=EG_COLUMN-1;
	this->AdjustBarPosition();
	this->AdjustMenuPosition();
	this->m_uWindowState=2;
	this->ForceRedrawAllControls();
}

void EWindow::MaximizeWindow(ESize maximizeArea){
	int dx,dy;
	dx=-static_cast<int>(m_pOriginalWindowPos.m_uX);
	dy=-static_cast<int>(m_pOriginalWindowPos.m_uY);
	this->AdjustControlPosition(dx,dy);
	this->m_pOriginalWindowPos=this->m_pWindowPos;
	this->m_pWindowPos.m_uX=0;
	this->m_pWindowPos.m_uY=0;
	this->m_zArea=maximizeArea;
	this->AdjustBarPosition();
	this->AdjustMenuPosition();
	this->m_uWindowState=2;
	this->ForceRedrawAllControls();
}

void EWindow::MinimizeWindow(){
	this->m_zArea.m_uHeight=0;
	this->m_zArea.m_uWidth=0;
	this->m_uWindowState=1;
	this->ForceRedrawAllControls();
}

void EWindow::RecoverWindow(){
	int dx,dy;
	dx=m_pOriginalWindowPos.m_uX-m_pWindowPos.m_uX;
	dy=m_pOriginalWindowPos.m_uY-m_pWindowPos.m_uY;
	this->AdjustControlPosition(dx,dy);
	this->m_pWindowPos=this->m_pOriginalWindowPos;
	this->m_zArea=this->m_zOriginalArea;
	this->AdjustBarPosition();
	this->AdjustMenuPosition();
	this->m_uWindowState=0;
	this->ForceRedrawAllControls();
}

bool EWindow::InExitArea(EPosition curPos){
#ifdef EG_RICH_STYLE
	if(this->m_uWindowTitleHeight<=10){
		if ((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-7)&&(
			curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-4	
			)&&(curPos.m_uY<=this->m_pWindowPos.m_uY+7)&&(curPos.m_uY>=this->m_pWindowPos.m_uY+1)){
			return true;
		}else{
			return false;
		}
	}else{
		if((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-this->m_uWindowTitleHeight+3)&&
			(curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-4)&&
			(curPos.m_uY>=this->m_pWindowPos.m_uY+3)&&(curPos.m_uY<=this->m_pWindowPos.m_uY+this->m_uWindowTitleHeight-4)){
			return true;
		}else{
			return false;
		}
	}
#else
	if ((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-7)&&(
		curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-1	
		)&&(curPos.m_uY<=this->m_pWindowPos.m_uY+7)&&(curPos.m_uY>=this->m_pWindowPos.m_uY+1)){
		return true;
	}
	return false;
#endif  //EG_RICH_STYLE
}

bool EWindow::InMaxArea(EPosition curPos){
#ifdef EG_RICH_STYLE
	if(this->m_uWindowTitleHeight<=10){
		if ((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-14)
			&&(curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-8)
			&&(curPos.m_uY<=this->m_pWindowPos.m_uY+7)&&(curPos.m_uY>=this->m_pWindowPos.m_uY+1)){
			return true;
		}else{
			return false;
		}
	}else{
		if((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-(this->m_uWindowTitleHeight<<1)+10)&&
			(curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-this->m_uWindowTitleHeight+2)&&
			(curPos.m_uY>=this->m_pWindowPos.m_uY+3)&&(curPos.m_uY<=this->m_pWindowPos.m_uY+this->m_uWindowTitleHeight-4)){
			return true;
		}else{
			return false;
		}
	}	
#else
	if ((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-14)&&(
		curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-8	
		)&&(curPos.m_uY<=this->m_pWindowPos.m_uY+7)&&(curPos.m_uY>=this->m_pWindowPos.m_uY+1)){
		return true;
	}
	return false;	
#endif  //EG_RICH_STYLE
}

bool EWindow::InMinArea(EPosition curPos){
#ifdef EG_RICH_STYLE
	if(this->m_uWindowTitleHeight<=10){
		if ((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-21)
			&&(curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-15)
			&&(curPos.m_uY<=this->m_pWindowPos.m_uY+7)&&(curPos.m_uY>=this->m_pWindowPos.m_uY+1)){
			return true;
		}else{
			return false;
		}
	}else{
		if((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-(this->m_uWindowTitleHeight*3)+17)&&
			(curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-(this->m_uWindowTitleHeight<<1)+9)&&
			(curPos.m_uY>=this->m_pWindowPos.m_uY+3)&&(curPos.m_uY<=this->m_pWindowPos.m_uY+this->m_uWindowTitleHeight-4)){
			return true;
		}else{
			return false;
		}
	}	
#else
	if ((curPos.m_uX>=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-21)&&(
		curPos.m_uX<=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-15	
		)&&(curPos.m_uY<=this->m_pWindowPos.m_uY+7)&&(curPos.m_uY>=this->m_pWindowPos.m_uY+1)){
		return true;
	}
	return false;	
#endif  //EG_RICH_STYLE
}

bool EWindow::InTitleArea(EPosition curPos){
#ifdef EG_RICH_STYLE
	if((curPos.m_uX>=this->m_pWindowPos.m_uX)&&(curPos.m_uX<=this->m_pWindowPos.m_uX
		+this->m_zArea.m_uWidth)&&(curPos.m_uY>=this->m_pWindowPos.m_uY)&&(curPos.m_uY<=
		this->m_pWindowPos.m_uY+this->m_uWindowTitleHeight)){
		return true;
	}else{
		return false;
	}	
#else
	if((curPos.m_uX>=this->m_pWindowPos.m_uX)&&(curPos.m_uX<=this->m_pWindowPos.m_uX
		+this->m_zArea.m_uWidth)&&(curPos.m_uY>=this->m_pWindowPos.m_uY)&&(curPos.m_uY<=
		this->m_pWindowPos.m_uY+10)){
		return true;
	}else{
		return false;
	}	
#endif  //EG_RICH_STYLE
}

unsigned int EWindow::AddMenuItem(EMenu* pmenu){
	if(m_uMenuItemCount<MaxMenuItem){
		this->m_parrMenu[this->m_uMenuItemCount]=pmenu;
		this->m_uMenuItemCount++;
	}
	this->AdjustMenuPosition();
	return m_uMenuItemCount;
}

void EWindow::RemoveMenuItem(unsigned int index){
	unsigned int m=this->m_uMenuItemCount;
	for (unsigned int c=index;c<m;c++){
		this->m_parrMenu[c]=this->m_parrMenu[c+1];
	}
	this->m_uMenuItemCount--;
	this->AdjustMenuPosition();
}

void EWindow::RemoveAllMenuItems(){
	for(unsigned int n=0;n<m_uMenuItemCount;n++){
		this->m_parrMenu[n]=NULL;
	}	
	m_uMenuItemCount=0;
}

//redraw all the controls
void EWindow::ForceRedrawAllControls(){
	//draw window 
	RedrawBaseWindow();
#ifdef EG_WINDOW_HOOK_FUNC
	//draw the bottom window first
	EG_HookFunc_RedrawESimpleWindow(this);
#endif   //EG_WINDOW_HOOK_FUNC
	if(this->m_uWindowState!=1){
		if(this->m_pToolBar!=NULL)
			this->m_pToolBar->RedrawControl();
		if(this->m_pStatusBar!=NULL)
			this->m_pStatusBar->RedrawControl();
		if(this->m_pPopupMenu!=NULL)
			this->m_pPopupMenu->RedrawControl();
		for (unsigned int m=0;m<this->m_uMenuItemCount;m++){
			this->m_parrMenu[m]->RedrawControl();
		}
		for (unsigned int n=0;n<this->m_uControlArrayCount;n++){
			this->m_pcControlArray[n]->RedrawControl();
		}
	}
}

//only redraw the controls which need to be refresh.
void EWindow::RedrawSelectedControls(){
#ifdef EG_WINDOW_HOOK_FUNC
	//draw the bottom window first
	EG_HookFunc_RedrawESimpleWindow(this);
#endif   //EG_WINDOW_HOOK_FUNC

	if(this->m_uWindowState!=1){
		if(this->m_pToolBar!=NULL){
			if(this->m_pToolBar->m_bNeedRedraw){
				this->m_pToolBar->RedrawControl();
			}
		}
		if(this->m_pStatusBar!=NULL){
			if(this->m_pStatusBar->m_bNeedRedraw){
				this->m_pStatusBar->RedrawControl();
			}
		}
		for (unsigned int n=0;n<this->m_uControlArrayCount;n++){
			if(this->m_pcControlArray[n]->m_bNeedRedraw){
				//in the redraw function, m_bNeedRedraw will be set to false.
				this->m_pcControlArray[n]->RedrawControl();
			}
		}
	}
}

// dispatch the event to the control which need to response.
void EWindow::DispatchEvent(EEvent* curevent){
	bool inWork=true;
	if(this->m_uWindowState==1)
		return;   //  window is closed, no event dispatched.	
	//cursor left click on the exit area
	if((this->InExitArea(curevent->m_pPosition))&&(curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		ESimpleDesktop* ptemp;
		this->m_uWindowState=1;
		ptemp=ESimpleDesktop::GetInstance();
		if(ptemp!=NULL){
			ptemp->RemoveWindow(ptemp->GetWindowIndex(this));
		}
		return;
	}
	//cursor left click on min or max area
	if(this->m_bMaxMinButton){
		if((this->InMaxArea(curevent->m_pPosition))&&(curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
			if(this->m_uWindowState==2){
				//recover the window
				this->RecoverWindow();
			}else{  
#ifdef EG_RICH_STYLE
				if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
					this->MaximizeWindow(ESize(EG_COLUMN,EG_ROW-10));
				else
					this->MaximizeWindow(ESize(EG_COLUMN,EG_ROW-EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]));
#else
				this->MaximizeWindow(ESize(EG_COLUMN,EG_ROW-10));
#endif  //EG_RICH_STYLE
			}
			return;
		}
		if((this->InMinArea(curevent->m_pPosition))&&(curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
			this->MinimizeWindow();
			return;
		}
	}
	//send the message to tool bar 
	if(this->m_pToolBar!=NULL){
		if(this->m_pToolBar->InControlArea(curevent->m_pPosition)){
			this->m_pToolBar->NoticeControl(curevent);
			inWork=false;
		}	
	}
	if(this->m_pStatusBar!=NULL){
		if(this->m_pStatusBar->InControlArea(curevent->m_pPosition)){
			inWork=false;
		}	
	}
	if(this->m_pPopupMenu!=NULL){
		if(this->m_pPopupMenu->InControlArea(curevent->m_pPosition)){
			this->m_pPopupMenu->NoticeControl(curevent);
		}else{
			//if the popup menu is open,try to close it.
			if((curevent->m_uMessage==1)&&(curevent->m_uSource==1)){	
				if(this->m_pPopupMenu->GetPopupState()){
					this->m_pPopupMenu->ClosePopupMenu();
				}
			//  if right click occur....
			}else if((curevent->m_uMessage==2)&&(curevent->m_uSource==1)){
				// in the work area of window 
				if((!this->InTitleArea(curevent->m_pPosition))&&(inWork)){
					this->m_pPopupMenu->ShowPopupMenu(curevent->m_pPosition);			
				}		
			}
		}	
	}
	//send message to menu
	for(unsigned int n=0;n<this->m_uMenuItemCount;n++){
		if(this->m_parrMenu[n]->InControlArea(curevent->m_pPosition)){
			this->m_parrMenu[n]->NoticeControl(curevent);
		}
	}
	//the position of event determine the control which receive the event.
	EControl* pControl=this->SelectControl(curevent->m_pPosition);
	if (pControl!=NULL){
		pControl->NoticeControl(curevent);
	}
}

bool EWindow::InWindowArea(EPosition curPos){
	int dx=curPos.m_uX-this->m_pWindowPos.m_uX;
	int dy=curPos.m_uY-this->m_pWindowPos.m_uY;
	if ((dx>=0)&&(dx<=static_cast<int>(this->m_zArea.m_uWidth))&&
		(dy>=0)&&(dy<=static_cast<int>(this->m_zArea.m_uHeight)))
		return true;
	else
		return false;
}	

void EWindow::RedrawBaseWindow(){
	if (this->m_uWindowState!=1){ //only draw open window
#ifdef EG_RICH_STYLE
		if (this->m_zArea.m_uHeight<this->m_uWindowTitleHeight)
			this->m_zArea.m_uHeight=this->m_uWindowTitleHeight+4;   //set the min height
#else
		if (this->m_zArea.m_uHeight<10)
			this->m_zArea.m_uHeight=14;   //set the min height
#endif  //EG_RICH_STYLE
#ifdef EG_SINGLE_COLOR
		//	topmost frame
		EG_Graphic_DrawWhiteFilledRectangle(this->m_pWindowPos.m_uX,this->m_pWindowPos.m_uY,10,this->m_zArea.m_uWidth);
		EG_Graphic_DrawEmptyRectangle(this->m_pWindowPos.m_uX,this->m_pWindowPos.m_uY,10,this->m_zArea.m_uWidth);
		//window title
		EG_Graphic_DrawString(this->m_pWindowPos.m_uX+5,this->m_pWindowPos.m_uY+2,this->m_psTitle);
		//work space
		EG_Graphic_DrawWhiteFilledRectangle(this->m_pWindowPos.m_uX+1,this->m_pWindowPos.m_uY+12,
			this->m_zArea.m_uHeight-13,this->m_zArea.m_uWidth-1);
		//work space frame
		EG_Graphic_DrawEmptyRectangle(this->m_pWindowPos.m_uX,this->m_pWindowPos.m_uY+11,
			this->m_zArea.m_uHeight-12,this->m_zArea.m_uWidth);
		//exit box
		EG_Graphic_DrawEmptyRectangle(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9,
			this->m_pWindowPos.m_uY+2,6,7);
		EG_Graphic_DrawLine(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9,
			this->m_pWindowPos.m_uY+2,this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-2,this->m_pWindowPos.m_uY+8,0);
		EG_Graphic_DrawLine(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9,
			this->m_pWindowPos.m_uY+8,this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-2,this->m_pWindowPos.m_uY+2,0);
		if(this->m_bMaxMinButton){
			//maximize box
			EG_Graphic_DrawEmptyRectangle(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-15,
				this->m_pWindowPos.m_uY+2,6,6);
			EG_Graphic_DrawHorizonLine(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-13,
				this->m_pWindowPos.m_uY+4,4);
			EG_Graphic_DrawVerticalLine(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-13,
				this->m_pWindowPos.m_uY+4,4);
			//minimize box
			EG_Graphic_DrawEmptyRectangle(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-21,
				this->m_pWindowPos.m_uY+2,6,6);
			EG_Graphic_DrawHorizonLine(this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-19,
				this->m_pWindowPos.m_uY+5,3);
		}
#else
#ifdef EG_RICH_STYLE
		EPosition pos,pos2;
		ESize size;
		size.m_uHeight=this->m_uWindowTitleHeight;
		size.m_uWidth=this->m_zArea.m_uWidth;
		//	topmost frame
		EG_Graphic_DrawFilledRectangle(this->m_pWindowPos,size,EColor(255,255,255));
		EG_Graphic_DrawEmptyRectangle(this->m_pWindowPos,size,this->m_pStyle->m_cFrameColor);
		//window title
		pos.m_uX=this->m_pWindowPos.m_uX+5;
		if(this->m_uWindowTitleHeight<=10)
			pos.m_uY=this->m_pWindowPos.m_uY+2;
		else
			pos.m_uY=this->m_pWindowPos.m_uY;
		EG_Graphic_DrawFontString(pos,	this->m_psTitle,this->m_pStyle->m_cTextColor,this->m_pStyle->m_fFont);
		//work space
		pos.m_uX=this->m_pWindowPos.m_uX+1;
		pos.m_uY=this->m_pWindowPos.m_uY+2+this->m_uWindowTitleHeight;
		size.m_uHeight=this->m_zArea.m_uHeight-3-this->m_uWindowTitleHeight;
		size.m_uWidth=this->m_zArea.m_uWidth-1;
		EG_Graphic_DrawFilledRectangle(pos,size,this->m_pStyle->m_cBackgroundColor);
		//work space frame
		pos.m_uX=this->m_pWindowPos.m_uX;
		pos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight;
		size.m_uHeight=this->m_zArea.m_uHeight-2-this->m_uWindowTitleHeight;
		size.m_uWidth=this->m_zArea.m_uWidth;
		EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
		if(this->m_uWindowTitleHeight<=10){
			//exit box
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9;
			pos.m_uY=this->m_pWindowPos.m_uY+2;
			size.m_uHeight=6;
			size.m_uWidth=7;
			EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9;
			pos.m_uY=this->m_pWindowPos.m_uY+2;
			pos2.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-2;
			pos2.m_uY=this->m_pWindowPos.m_uY+8;
			EG_Graphic_DrawLine(pos,pos2,this->m_pStyle->m_cFrameColor,false);
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9;
			pos.m_uY=this->m_pWindowPos.m_uY+8;
			pos2.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-2;
			pos2.m_uY=this->m_pWindowPos.m_uY+2;
			EG_Graphic_DrawLine(pos,pos2,this->m_pStyle->m_cFrameColor,false);
			if(this->m_bMaxMinButton){
				//maximize box
				pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-15;
				pos.m_uY=this->m_pWindowPos.m_uY+2;
				size.m_uHeight=6;
				size.m_uWidth=6;
				EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
				pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-13;
				pos.m_uY=this->m_pWindowPos.m_uY+4;
				EG_Graphic_DrawHorizonLine(pos,4,this->m_pStyle->m_cFrameColor);
				EG_Graphic_DrawVerticalLine(pos,4,this->m_pStyle->m_cFrameColor);
				//minimize box
				pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-21;
				pos.m_uY=this->m_pWindowPos.m_uY+2;
				size.m_uHeight=6;
				size.m_uWidth=6;
				EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
				pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-19;
				pos.m_uY=this->m_pWindowPos.m_uY+5;
				EG_Graphic_DrawHorizonLine(pos,3,this->m_pStyle->m_cFrameColor);
			}
		}else{
			//exit box
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-this->m_uWindowTitleHeight+3;
			pos.m_uY=this->m_pWindowPos.m_uY+3;
			size.m_uHeight=this->m_uWindowTitleHeight-7;
			size.m_uWidth=this->m_uWindowTitleHeight-7;
			EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
			pos2.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-4;
			pos2.m_uY=this->m_pWindowPos.m_uY+this->m_uWindowTitleHeight-4;
			EG_Graphic_DrawLine(pos,pos2,this->m_pStyle->m_cFrameColor,false);
			pos.m_uX+=this->m_uWindowTitleHeight-7;
			pos2.m_uX-=this->m_uWindowTitleHeight-7;
			EG_Graphic_DrawLine(pos,pos2,this->m_pStyle->m_cFrameColor,false);
			if(this->m_bMaxMinButton){
				//maximize box
				pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-(this->m_uWindowTitleHeight<<1)+10;
				pos.m_uY=this->m_pWindowPos.m_uY+3;
				EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
				pos.m_uX+=3;
				pos.m_uY+=3;
				EG_Graphic_DrawHorizonLine(pos,this->m_uWindowTitleHeight-10,this->m_pStyle->m_cFrameColor);
				EG_Graphic_DrawVerticalLine(pos,this->m_uWindowTitleHeight-10,this->m_pStyle->m_cFrameColor);
				//minimize box
				pos.m_uX-=this->m_uWindowTitleHeight-4;
				pos.m_uY-=3;
				EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
				pos.m_uX+=2;
				pos.m_uY+=5;
				EG_Graphic_DrawHorizonLine(pos,6,this->m_pStyle->m_cFrameColor);
			}
		}
#else
		EPosition pos,pos2;
		ESize size;
		size.m_uHeight=10;
		size.m_uWidth=this->m_zArea.m_uWidth;
		//	topmost frame
		EG_Graphic_DrawFilledRectangle(this->m_pWindowPos,size,EColor(255,255,255));
		EG_Graphic_DrawEmptyRectangle(this->m_pWindowPos,size,this->m_pStyle->m_cFrameColor);
		//window title
		pos.m_uX=this->m_pWindowPos.m_uX+5;
		pos.m_uY=this->m_pWindowPos.m_uY+2;
		EG_Graphic_DrawString(pos,	this->m_psTitle,this->m_pStyle->m_cTextColor);
		//work space
		pos.m_uX=this->m_pWindowPos.m_uX+1;
		pos.m_uY=this->m_pWindowPos.m_uY+12;
		size.m_uHeight=this->m_zArea.m_uHeight-13;
		size.m_uWidth=this->m_zArea.m_uWidth-1;
		EG_Graphic_DrawFilledRectangle(pos,size,this->m_pStyle->m_cBackgroundColor);
		//work space frame
		pos.m_uX=this->m_pWindowPos.m_uX;
		pos.m_uY=this->m_pWindowPos.m_uY+11;
		size.m_uHeight=this->m_zArea.m_uHeight-12;
		size.m_uWidth=this->m_zArea.m_uWidth;
		EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
		//exit box
		pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9;
		pos.m_uY=this->m_pWindowPos.m_uY+2;
		size.m_uHeight=6;
		size.m_uWidth=7;
		EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
		pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9;
		pos.m_uY=this->m_pWindowPos.m_uY+2;
		pos2.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-2;
		pos2.m_uY=this->m_pWindowPos.m_uY+8;
		EG_Graphic_DrawLine(pos,pos2,this->m_pStyle->m_cFrameColor,false);
		pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-9;
		pos.m_uY=this->m_pWindowPos.m_uY+8;
		pos2.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-2;
		pos2.m_uY=this->m_pWindowPos.m_uY+2;
		EG_Graphic_DrawLine(pos,pos2,this->m_pStyle->m_cFrameColor,false);
		if(this->m_bMaxMinButton){
			//maximize box
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-15;
			pos.m_uY=this->m_pWindowPos.m_uY+2;
			size.m_uHeight=6;
			size.m_uWidth=6;
			EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-13;
			pos.m_uY=this->m_pWindowPos.m_uY+4;
			EG_Graphic_DrawHorizonLine(pos,4,this->m_pStyle->m_cFrameColor);
			EG_Graphic_DrawVerticalLine(pos,4,this->m_pStyle->m_cFrameColor);
			//minimize box
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-21;
			pos.m_uY=this->m_pWindowPos.m_uY+2;
			size.m_uHeight=6;
			size.m_uWidth=6;
			EG_Graphic_DrawEmptyRectangle(pos,size,this->m_pStyle->m_cFrameColor);
			pos.m_uX=this->m_pWindowPos.m_uX+this->m_zArea.m_uWidth-19;
			pos.m_uY=this->m_pWindowPos.m_uY+5;
			EG_Graphic_DrawHorizonLine(pos,3,this->m_pStyle->m_cFrameColor);
		}
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
	}
}

void EWindow::AdjustBarPosition(){
	unsigned char dock;
#ifdef EG_RICH_STYLE
	if(this->m_pToolBar!=NULL){
		dock=this->m_pToolBar->GetDockState();
		switch(dock){
			case 1:
				if(this->m_uMenuItemCount==0){
					//dock at the position of menu
					this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight;
				}else{
					this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight+this->m_parrMenu[0]->m_zArea.m_uHeight;
				}
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pToolBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
			case 2:
				if(this->m_pStatusBar!=NULL){
					if(this->m_pStatusBar->GetDockState()==2){
						this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+this->m_zArea.m_uHeight
							-2-this->m_pToolBar->m_zArea.m_uHeight-this->m_pStatusBar->m_zArea.m_uHeight;
					}else{
						this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+this->m_zArea.m_uHeight
							-2-this->m_pToolBar->m_zArea.m_uHeight;
					}
				}else{
					this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+this->m_zArea.m_uHeight
						-2-this->m_pToolBar->m_zArea.m_uHeight;
				}
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pToolBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
			case 3:
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight;
				if(this->m_pStatusBar!=NULL){
					this->m_pToolBar->m_zArea.m_uHeight=this->m_zArea.m_uHeight-this->m_uWindowTitleHeight-2-this->m_pStatusBar->m_zArea.m_uHeight;
				}else{
					this->m_pToolBar->m_zArea.m_uHeight=this->m_zArea.m_uHeight-this->m_uWindowTitleHeight-2;
				}
				break;
			case 4:
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+
					this->m_zArea.m_uWidth-5;
				this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight;
				if(this->m_pStatusBar!=NULL){
					this->m_pToolBar->m_zArea.m_uHeight=this->m_zArea.m_uHeight-this->m_uWindowTitleHeight-2-this->m_pStatusBar->m_zArea.m_uHeight;
				}else{
					this->m_pToolBar->m_zArea.m_uHeight=this->m_zArea.m_uHeight-this->m_uWindowTitleHeight-2;
				}
				break;
		}
		this->m_pToolBar->AdjustControlPosition();
	}
	if(this->m_pStatusBar!=NULL){
		dock=this->m_pStatusBar->GetDockState();
		switch(dock){
			case 1:
				if(this->m_uMenuItemCount==0){
					if(this->m_pToolBar!=NULL){
						if(this->m_pToolBar->GetDockState()!=1){
							//dock at the position of menu
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight;					
						}else{
							//dock at the position of toolbar
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight+
								this->m_pToolBar->m_zArea.m_uHeight;
						}							
					}else{
						//dock at the position of menu
						this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight;					
					}
				}else{
					if(this->m_pToolBar!=NULL){
						if(this->m_pToolBar->GetDockState()!=1){
							//dock at the position of toolbar
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight
								+this->m_parrMenu[0]->m_zArea.m_uHeight;
						}else{
							//dock normally
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight
								+this->m_parrMenu[0]->m_zArea.m_uHeight+this->m_pToolBar->m_zArea.m_uHeight;					
						}
					}else{
						//dock at the position of toolbar
						this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+1+this->m_uWindowTitleHeight
								+this->m_parrMenu[0]->m_zArea.m_uHeight;
					}
				}
				this->m_pStatusBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pStatusBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
			case 2:
				this->m_pStatusBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+
					this->m_zArea.m_uHeight-2-this->m_pStatusBar->m_zArea.m_uHeight;
				this->m_pStatusBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
		}
	}
#else
	if(this->m_pToolBar!=NULL){
		dock=this->m_pToolBar->GetDockState();
		switch(dock){
			case 1:
				if(this->m_uMenuItemCount==0){
					//dock at the position of menu
					this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+11;
				}else{
					this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+21;
				}
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pToolBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
			case 2:
				if(this->m_pStatusBar!=NULL){
					if(this->m_pStatusBar->GetDockState()==2){
						this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+this->m_zArea.m_uHeight
							-12-this->m_pToolBar->m_zArea.m_uHeight;
					}else{
						this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+this->m_zArea.m_uHeight
							-2-this->m_pToolBar->m_zArea.m_uHeight;
					}
				}else{
					this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+this->m_zArea.m_uHeight
						-2-this->m_pToolBar->m_zArea.m_uHeight;
				}
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pToolBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
			case 3:
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+11;
				this->m_pToolBar->m_zArea.m_uHeight=this->m_zArea.m_uHeight-22;
				break;
			case 4:
				this->m_pToolBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+
					this->m_zArea.m_uWidth-5;
				this->m_pToolBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+11;
				this->m_pToolBar->m_zArea.m_uHeight=this->m_zArea.m_uHeight-22;
				break;
		}
		this->m_pToolBar->AdjustControlPosition();
	}
	if(this->m_pStatusBar!=NULL){
		dock=this->m_pStatusBar->GetDockState();
		switch(dock){
			case 1:
				if(this->m_uMenuItemCount==0){
					if(this->m_pToolBar!=NULL){
						if(this->m_pToolBar->GetDockState()!=1){
							//dock at the position of menu
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+11;					
						}else{
							//dock at the position of toolbar
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+11+
								this->m_pToolBar->m_zArea.m_uHeight;
						}							
					}else{
						//dock at the position of menu
						this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+11;					
					}
				}else{
					if(this->m_pToolBar!=NULL){
						if(this->m_pToolBar->GetDockState()!=1){
							//dock at the position of toolbar
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+21;
						}else{
							//dock normally
							this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+21+
								this->m_pToolBar->m_zArea.m_uHeight;					
						}
					}else{
						//dock at the position of toolbar
						this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+21;
					}
				}
				this->m_pStatusBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pStatusBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
			case 2:
				this->m_pStatusBar->m_pControlPos.m_uX=this->m_pWindowPos.m_uX+1;
				this->m_pStatusBar->m_pControlPos.m_uY=this->m_pWindowPos.m_uY+
					this->m_zArea.m_uHeight-12;
				this->m_pStatusBar->m_zArea.m_uWidth=this->m_zArea.m_uWidth-2;
				break;
		}
	}
#endif  //EG_RICH_STYLE
}

void EWindow::AdjustMenuPosition(){
	unsigned int x=this->m_pWindowPos.m_uX+1;
#ifdef EG_RICH_STYLE
	unsigned int y=this->m_pWindowPos.m_uY+this->m_uWindowTitleHeight+1;
#else
	unsigned int y=this->m_pWindowPos.m_uY+11;
#endif  //EG_RICH_STYLE
	for(unsigned int n=0;n<this->m_uMenuItemCount;n++){
		this->m_parrMenu[n]->m_pControlPos.m_uX=x;
		this->m_parrMenu[n]->m_pControlPos.m_uY=y;
		x+=this->m_parrMenu[n]->m_zArea.m_uWidth;
	}
	this->AdjustBarPosition();
}

void EWindow::AdjustControlPosition(int deltaX,int deltaY){
	for(unsigned int n=0;n<this->m_uControlArrayCount;n++){
		this->m_pcControlArray[n]->m_pControlPos.m_uX+=deltaX;
		this->m_pcControlArray[n]->m_pControlPos.m_uY+=deltaY;
	}
}

ESimpleDesktop* ESimpleDesktop::m_pdInstance=NULL;

#ifdef WIN32_SIMULATE
#ifdef EG_SINGLE_COLOR
#ifdef EG_CURSOR
ESimpleDesktop::ESimpleDesktop(EG_BinaryBufferDisplay* pBBDisp):m_cCursor(){
	this->m_pBBDisplay=pBBDisp;
	this->m_uWindowArrayCount=0;
	this->m_uSelectedRedrawCount=0;
	this->m_uScheduleRedrawCount=0;
	for(int n=0;n<this->UsualMaxWindow;n++){
		this->m_pwWindowArray[n]=NULL;
	}	
}
#else
ESimpleDesktop::ESimpleDesktop(EG_BinaryBufferDisplay* pBBDisp){
	this->m_pBBDisplay=pBBDisp;
	this->m_uWindowArrayCount=0;
	this->m_uSelectedRedrawCount=0;
	this->m_uScheduleRedrawCount=0;
	for(int n=0;n<this->UsualMaxWindow;n++){
		this->m_pwWindowArray[n]=NULL;
	}	
}
#endif  //EG_CURSOR
#else
#ifdef EG_CURSOR
ESimpleDesktop::ESimpleDesktop(EG_RGBBufferDisplay* pRGBDisp):m_cCursor(){
	this->m_pRGBDisplay=pRGBDisp;
	this->m_uWindowArrayCount=0;
	this->m_uSelectedRedrawCount=0;
	this->m_uScheduleRedrawCount=0;
	for(int n=0;n<this->UsualMaxWindow;n++){
		this->m_pwWindowArray[n]=NULL;
	}	
}
#else
ESimpleDesktop::ESimpleDesktop(EG_RGBBufferDisplay* pRGBDisp){
	this->m_pRGBDisplay=pRGBDisp;
	this->m_uWindowArrayCount=0;
	this->m_uSelectedRedrawCount=0;
	this->m_uScheduleRedrawCount=0;
	for(int n=0;n<this->UsualMaxWindow;n++){
		this->m_pwWindowArray[n]=NULL;
	}	
}
#endif //EG_CURSOR
#endif   //EG_SINGLE_COLOR
#else
#ifdef EG_CURSOR
ESimpleDesktop::ESimpleDesktop():m_cCursor(){
	this->m_uWindowArrayCount=0;
	this->m_uSelectedRedrawCount=0;
	this->m_uScheduleRedrawCount=0;
	for(int n=0;n<this->UsualMaxWindow;n++){
		this->m_pwWindowArray[n]=NULL;
	}	
}
#else
ESimpleDesktop::ESimpleDesktop(){
	this->m_uWindowArrayCount=0;
	this->m_uSelectedRedrawCount=0;
	this->m_uScheduleRedrawCount=0;
	for(int n=0;n<this->UsualMaxWindow;n++){
		this->m_pwWindowArray[n]=NULL;
	}	
}
#endif  //EG_CURSOR
#endif  //WIN32_SIMULATE

//return the window index.
int ESimpleDesktop::AddWindow(ESimpleWindow* pWindow){
	if(this->m_uWindowArrayCount<this->UsualMaxWindow){
		this->m_pwWindowArray[this->m_uWindowArrayCount]=pWindow;
		return (this->m_uWindowArrayCount++);
	}else{
		return this->UsualMaxWindow;
	}
}

void ESimpleDesktop::AddWindow(ESimpleWindow* pWindow,unsigned char windowIndex){     
	if((windowIndex>=m_uWindowArrayCount)||(this->m_uWindowArrayCount>=this->UsualMaxWindow))
		return;
	for(unsigned char n=this->m_uWindowArrayCount;n>=windowIndex;n--){
		this->m_pwWindowArray[n+1]=this->m_pwWindowArray[n];
	}
	this->m_pwWindowArray[windowIndex]=pWindow;
	m_uWindowArrayCount++;
}

void ESimpleDesktop::RemoveAllWindow(){
	for (int n=0;n<this->m_uWindowArrayCount;n++)
		this->m_pwWindowArray[n]=NULL;
	this->m_uWindowArrayCount=0;
}

void ESimpleDesktop::RemoveTopmostWindow(){
	if (this->m_uWindowArrayCount!=0){
		this->m_pwWindowArray[this->m_uWindowArrayCount-1]=NULL;
		this->m_uWindowArrayCount--;
	}
}

void ESimpleDesktop::RemoveWindow(unsigned char windowIndex){
	if (this->m_uWindowArrayCount!=0){//all the later window move to left.
		for(unsigned char n=windowIndex+1;n<this->m_uWindowArrayCount;n++){
			this->m_pwWindowArray[n-1]=this->m_pwWindowArray[n];	
		}
		this->m_uWindowArrayCount--;
	}
}

void ESimpleDesktop::SetWindowTopmost(unsigned char windowIndex){
	ESimpleWindow* tempWindow=this->m_pwWindowArray[windowIndex];
	this->RemoveWindow(windowIndex);
	AddWindow(tempWindow);
}

void ESimpleDesktop::SetWindowLayer(unsigned char windowIndex,unsigned char newLayer){     
	ESimpleWindow* tempWindow=this->m_pwWindowArray[windowIndex];
	this->RemoveWindow(windowIndex);
	AddWindow(tempWindow,newLayer);
}

void ESimpleDesktop::GlobalRedraw(){
	//redraw the desktop first
	this->RedrawDesktop();
#ifdef EG_DESKTOP_HOOK_FUNC
	EG_HookFunc_RedrawEDesktop(this);
#endif  //EG_DESKTOP_HOOK_FUNC
	for (int n=0;n<this->m_uWindowArrayCount;n++){
		this->m_pwWindowArray[n]->ForceRedrawAllControls();
	}
#ifdef EG_CURSOR
	//draw the shape of cursor 
	this->m_cCursor.SetCursorPosition(this->m_pCursorPosition);
#endif //EG_CURSOR
	RefreshLCD();	
}

void ESimpleDesktop::SelectedRedraw(){
#ifdef EG_DESKTOP_HOOK_FUNC
	EG_HookFunc_RedrawEDesktop(this);
#endif  //EG_DESKTOP_HOOK_FUNC
	for (int n=0;n<this->m_uWindowArrayCount;n++){
		this->m_pwWindowArray[n]->RedrawSelectedControls();
	}
	if(this->m_uSelectedRedrawCount>=SelectedRedrawRefreshThreshold){
		RefreshLCD();	
		this->m_uSelectedRedrawCount=0;
	}else{
		this->m_uSelectedRedrawCount++;
	}
}

void ESimpleDesktop::ScheduleRedraw(){
	if(this->m_uScheduleRedrawCount<ScheduleRedrawRefreshThreshold){
		this->SelectedRedraw();  
		this->m_uScheduleRedrawCount++;
	}else{
		this->m_uScheduleRedrawCount=0;
		this->GlobalRedraw();
	}
}

unsigned char ESimpleDesktop::DispatchEvent(EEvent* curevent){
	for (int n=this->m_uWindowArrayCount-1;n>=0;n--){
		if(this->m_pwWindowArray[n]->InWindowArea(curevent->m_pPosition)){
			this->m_pwWindowArray[n]->DispatchEvent(curevent);	
			return 1;
		}
	}
	return 0;
}

#ifdef EG_CURSOR
void ESimpleDesktop::SetCursorEvent(EEvent* e){
	this->m_cCursor.SetCursorPosition(e->m_pPosition);
	this->DispatchEvent(e);
}

void ESimpleDesktop::SetCursorEvent(const EPosition& cursorPos,unsigned int message){
	EEvent temp;
	EPosition lastPos;
	temp.m_pPosition=cursorPos;
	temp.m_uMessage=message;
	temp.m_uSource=1;
	this->m_pCursorPosition=cursorPos;
	lastPos=this->m_cCursor.SetCursorPosition(cursorPos);
	this->DispatchEvent(&temp);
}
#endif //EG_CURSOR

void ESimpleDesktop::SetKeyboardEvent(const EPosition& cursorPos,unsigned int keyPressed){
	EEvent temp;
	temp.m_pPosition=cursorPos;
	temp.m_uMessage=keyPressed;
	temp.m_uSource=2;
	this->DispatchEvent(&temp);
}

unsigned char ESimpleDesktop::GetWindowIndex(ESimpleWindow* pWindow){
	unsigned char temp;
	for(temp=0;temp<this->m_uWindowArrayCount;temp++){
		if(this->m_pwWindowArray[temp]==pWindow){
			return temp;
		}
	}
	return UsualMaxWindow;
}

#ifdef WIN32_SIMULATE
#ifdef EG_SINGLE_COLOR
EDesktop::EDesktop(EG_BinaryBufferDisplay* pBBDisp):ESimpleDesktop(pBBDisp){
	this->m_uIconArrayCount=MaxIconNumber-1;
	this->RemoveAllIconButton();
	this->m_zSystemStatusBar.m_uHeight=12;
	this->m_zSystemStatusBar.m_uWidth=EG_COLUMN-2;
	this->m_pmStartMenu=NULL;
	this->m_ppmBasePopupMenu=NULL;
	this->m_ptTimeClock=NULL;
	this->m_pBackgroundBitmap=NULL;
	this->m_uWindowTitleWidth=EG_COLUMN-85;
	this->m_uWindowTitleWidth=this->m_uWindowTitleWidth>>2;
	this->m_uWindowTitleWidth+=2;
	//make sure it is not too wide or too narrow
	if(this->m_uWindowTitleWidth>82)
		this->m_uWindowTitleWidth=82;
	if(this->m_uWindowTitleWidth<42)
		this->m_uWindowTitleWidth=42;
	this->RecalculateWindowTitleCount();
}
#else
EDesktop::EDesktop(EG_RGBBufferDisplay* pRGBDisp):ESimpleDesktop(pRGBDisp){
	this->m_psStyle=&EG_DefaultStyle;
	this->m_uIconArrayCount=MaxIconNumber-1;
	this->RemoveAllIconButton();
#ifdef EG_RICH_STYLE
	if(EG_FontHeight[this->m_psStyle->m_fFont.m_cFontNumber]<=10)
		this->m_zSystemStatusBar.m_uHeight=12;
	else
		this->m_zSystemStatusBar.m_uHeight=EG_FontHeight[this->m_psStyle->m_fFont.m_cFontNumber]+2;
#else
	this->m_zSystemStatusBar.m_uHeight=12;
#endif  //EG_RICH_STYLE
	this->m_zSystemStatusBar.m_uWidth=EG_COLUMN-2;
	this->m_pmStartMenu=NULL;
	this->m_ppmBasePopupMenu=NULL;
	this->m_ptTimeClock=NULL;
	this->m_pBackgroundBitmap=NULL;
	this->m_uWindowTitleWidth=EG_COLUMN-85;
	this->m_uWindowTitleWidth=this->m_uWindowTitleWidth>>2;
	this->m_uWindowTitleWidth+=2;
	//make sure it is not too wide or too narrow
	if(this->m_uWindowTitleWidth>82)
		this->m_uWindowTitleWidth=82;
	if(this->m_uWindowTitleWidth<42)
		this->m_uWindowTitleWidth=42;
	this->RecalculateWindowTitleCount();
}
#endif  //EG_SINGLE_COLOR
#else
EDesktop::EDesktop():ESimpleDesktop(){
#ifndef EG_SINGLE_COLOR
	this->m_psStyle=&EG_DefaultStyle;
#endif  //EG_SINGLE_COLOR
	this->m_uIconArrayCount=MaxIconNumber-1;
	this->RemoveAllIconButton();
#ifdef EG_RICH_STYLE
	if(EG_FontHeight[this->m_psStyle->m_fFont.m_cFontNumber]<=10)
		this->m_zSystemStatusBar.m_uHeight=12;
	else
		this->m_zSystemStatusBar.m_uHeight=EG_FontHeight[this->m_psStyle->m_fFont.m_cFontNumber]+2;
#else
	this->m_zSystemStatusBar.m_uHeight=12;
#endif  //EG_RICH_STYLE
	this->m_zSystemStatusBar.m_uWidth=EG_COLUMN-2;
	this->m_pmStartMenu=NULL;
	this->m_ppmBasePopupMenu=NULL;
	this->m_ptTimeClock=NULL;	
	this->m_pBackgroundBitmap=NULL;
	this->m_uWindowTitleWidth=EG_COLUMN-85;
	this->m_uWindowTitleWidth=this->m_uWindowTitleWidth>>2;
	this->m_uWindowTitleWidth+=2;
	//make sure it is not too wide or too narrow
	if(this->m_uWindowTitleWidth>82)
		this->m_uWindowTitleWidth=82;
	if(this->m_uWindowTitleWidth<42)
		this->m_uWindowTitleWidth=42;
	this->RecalculateWindowTitleCount();
}
#endif //WIN32_SIMULATE

unsigned int EDesktop::AddIconButton(EIconButton* pIconButton){
	if (this->m_uIconArrayCount<this->MaxIconNumber){
		this->m_pibIconArray[this->m_uIconArrayCount]=pIconButton;
		this->m_uIconArrayCount++;
		return this->m_uIconArrayCount;
	}
	return this->MaxIconNumber;
}

void EDesktop::RemoveIconButton(unsigned int iconIndex){
	unsigned int m=this->m_uIconArrayCount;
	for (unsigned int c=iconIndex;c<m;c++){
		this->m_pibIconArray[c]=this->m_pibIconArray[c+1];
	}
	this->m_uIconArrayCount--;	
}

void EDesktop::RemoveAllIconButton(){
	for (unsigned int n=0;n<this->m_uIconArrayCount;n++)
		this->m_pibIconArray[n]=NULL;
	this->m_uIconArrayCount=0;
}

void EDesktop::AppendStartMenu(EMenu* pMenu){
	this->m_pmStartMenu=pMenu;
	this->m_pmStartMenu->SetControlPosition(EPosition(1,EG_ROW-this->m_zSystemStatusBar.m_uHeight));
	this->m_pmStartMenu->CollapseMenu();
	this->RecalculateWindowTitleCount();
}

void EDesktop::AppendClock(EClock* pClock){
	this->m_ptTimeClock=pClock;
	this->m_ptTimeClock->m_pControlPos.m_uX=EG_COLUMN-pClock->m_zArea.m_uWidth-1;
	this->m_ptTimeClock->m_pControlPos.m_uY=EG_ROW-this->m_zSystemStatusBar.m_uHeight;
	this->RecalculateWindowTitleCount();
}

unsigned char EDesktop::DispatchEvent(EEvent* curevent){
	unsigned int windowIndex=0;
	unsigned char temp;
	temp=ESimpleDesktop::DispatchEvent(curevent);
	if(temp!=0)
		return temp;
	if((curevent->m_uSource==1)&&(this->m_ppmBasePopupMenu!=NULL)){
		//right click to show the popup menu
		if((curevent->m_uMessage==2)&&(!(this->m_ppmBasePopupMenu->GetPopupState())))
			this->m_ppmBasePopupMenu->ShowPopupMenu(curevent->m_pPosition);
		if(curevent->m_uMessage==1){
			//left click in the popup menu.
			if(this->m_ppmBasePopupMenu->InControlArea(curevent->m_pPosition)){
				this->m_ppmBasePopupMenu->NoticeControl(curevent);
				return 2;
			}else{		//left click out of popup menu.
				this->m_ppmBasePopupMenu->ClosePopupMenu();
			}
		}
	}
	//check on the start menu
	if(this->m_pmStartMenu!=NULL){
		windowIndex=this->m_pmStartMenu->GetBaseWidth();
		if(this->m_pmStartMenu->InControlArea(curevent->m_pPosition)){
			this->m_pmStartMenu->NoticeControl(curevent);	
		}
	}
	//cursor left click on the system Status bar
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)
		&&(curevent->m_pPosition.m_uY>=EG_ROW-this->m_zSystemStatusBar.m_uHeight)){
		//calculate the window index
		windowIndex=curevent->m_pPosition.m_uX-windowIndex;
		windowIndex=windowIndex/m_uWindowTitleWidth;
		//this window exist..
		if(((windowIndex+1)<=this->m_uWindowTitleCount)
			&&((windowIndex+1)<=this->m_uWindowArrayCount)){
			//set it to topmost, if normal
			if(!(this->m_pwWindowArray[windowIndex]->GetWindowState()))
				this->SetWindowTopmost(windowIndex);
			else   //if it is minimized, recover it..
				this->m_pwWindowArray[windowIndex]->RecoverWindow();
		}
	}
	for(unsigned int n=0;n<this->m_uIconArrayCount;n++){
		if(this->m_pibIconArray[n]->InControlArea(curevent->m_pPosition)){
			this->m_pibIconArray[n]->NoticeControl(curevent);
			return 3;
		}
	}
	return 0;
}

void EDesktop::RecalculateWindowTitleCount(){
	unsigned int otherWidth=0;
	if(this->m_pmStartMenu!=NULL)
		otherWidth+=this->m_pmStartMenu->m_zArea.m_uWidth;
	if(this->m_ptTimeClock!=NULL)
		otherWidth+=this->m_ptTimeClock->m_zArea.m_uWidth;
	otherWidth=EG_COLUMN-otherWidth-1;
	this->m_uWindowTitleCount=otherWidth/this->m_uWindowTitleWidth;
}

void EDesktop::RedrawDesktop(){
	unsigned char currentTitle=0;
	unsigned char titleSize;
	unsigned int x,y;
	titleSize=(unsigned char)((this->m_uWindowTitleWidth-2)>>3);
	//draw the backgound
	if(this->m_pBackgroundBitmap==NULL){
		EG_LCDClearBuffer();		
	}else{
#ifdef EG_SINGLE_COLOR
		EG_Graphic_DrawBitmap(0,0,this->m_pBackgroundBitmap);			
#else
		EG_Graphic_DrawBitmap(EPosition(0,0),this->m_pBackgroundBitmap);
#endif  //EG_SINGLE_COLOR
	}
	//draw the icon buttons
	for(unsigned int n=0;n<m_uIconArrayCount;n++){
		this->m_pibIconArray[n]->RedrawControl();		
	}
	//draw the system status bar
#ifdef EG_SINGLE_COLOR
	EG_Graphic_DrawEmptyRectangle(0,EG_ROW-this->m_zSystemStatusBar.m_uHeight-1,
		this->m_zSystemStatusBar.m_uHeight,this->m_zSystemStatusBar.m_uWidth);
	if(this->m_pmStartMenu!=NULL){
		this->m_pmStartMenu->RedrawControl();
	}
	if(m_uWindowTitleCount<=(unsigned int)(this->m_uWindowArrayCount)){
		currentTitle=m_uWindowTitleCount;
		//draw other window icon
		if(this->m_ptTimeClock!=NULL){
			x=EG_COLUMN-this->m_ptTimeClock->m_zArea.m_uWidth-8;
		}else{
			x=EG_COLUMN-8;	
		}
		y=EG_ROW-9;
		EG_Graphic_DrawLine(x,y,x,y+5,0);
		EG_Graphic_DrawLine(x,y,x+5,y+3,0);
		EG_Graphic_DrawLine(x,y+5,x+5,y+3,0);
	}else{
		currentTitle=m_uWindowArrayCount;
	}
	if(this->m_pmStartMenu!=NULL)
		x=this->m_pmStartMenu->GetBaseWidth()+2;
	else
		x=1;
	y=EG_ROW-this->m_zSystemStatusBar.m_uHeight;
	for(unsigned char m=0;m<currentTitle;m++){
		EG_Graphic_DrawEmptyRectangle(x,y,10,this->m_uWindowTitleWidth);
		EG_Graphic_DrawConstString(x+2,y+1,this->m_pwWindowArray[m]->GetWindowTitle(),titleSize);
		x+=this->m_uWindowTitleWidth;
	}
	if(this->m_ptTimeClock!=NULL){
		this->m_ptTimeClock->RedrawControl();
	}
#else
	EG_Graphic_DrawEmptyRectangle(EPosition(0,EG_ROW-this->m_zSystemStatusBar.m_uHeight-1),
		ESize(this->m_zSystemStatusBar.m_uWidth,this->m_zSystemStatusBar.m_uHeight),this->m_psStyle->m_cFrameColor);
	if(this->m_pmStartMenu!=NULL){
		this->m_pmStartMenu->RedrawControl();
	}
	if(m_uWindowTitleCount<(unsigned int)(this->m_uWindowArrayCount)){
		currentTitle=m_uWindowTitleCount;
		//draw other window icon
		if(this->m_ptTimeClock!=NULL){
			x=EG_COLUMN-this->m_ptTimeClock->m_zArea.m_uWidth-8;
		}else{
			x=EG_COLUMN-8;	
		}
		y=EG_ROW-this->m_zSystemStatusBar.m_uHeight+1;
		EG_Graphic_DrawLine(EPosition(x,y),EPosition(x,y+5),this->m_psStyle->m_cFrameColor,false);
		EG_Graphic_DrawLine(EPosition(x,y),EPosition(x+5,y+3),this->m_psStyle->m_cFrameColor,false);
		EG_Graphic_DrawLine(EPosition(x,y+5),EPosition(x+5,y+3),this->m_psStyle->m_cFrameColor,false);
	}else{
		currentTitle=m_uWindowArrayCount;
	}
	if(this->m_pmStartMenu!=NULL)
		x=this->m_pmStartMenu->GetBaseWidth()+2;
	else
		x=1;
	y=EG_ROW-this->m_zSystemStatusBar.m_uHeight;
	for(unsigned char m=0;m<currentTitle;m++){
#ifndef EG_RICH_STYLE
		EG_Graphic_DrawEmptyRectangle(EPosition(x,y),ESize(this->m_uWindowTitleWidth,10),this->m_psStyle->m_cFrameColor);
		EG_Graphic_DrawConstString(EPosition(x+2,y+1),this->m_pwWindowArray[m]->GetWindowTitle(),
			titleSize,this->m_psStyle->m_cTextColor);
#else
		EG_Graphic_DrawEmptyRectangle(EPosition(x,y),ESize(this->m_uWindowTitleWidth,this->m_zSystemStatusBar.m_uHeight-2),this->m_psStyle->m_cFrameColor);
		if(this->m_zSystemStatusBar.m_uHeight<=10){
			EG_Graphic_DrawConstFontString(EPosition(x+2,y+1),this->m_pwWindowArray[m]->GetWindowTitle(),
				titleSize,this->m_psStyle->m_cTextColor,this->m_psStyle->m_fFont);
		}else{
			EG_Graphic_DrawConstFontString(EPosition(x+2,y),this->m_pwWindowArray[m]->GetWindowTitle(),
				titleSize,this->m_psStyle->m_cTextColor,this->m_psStyle->m_fFont);
		}
#endif  //EG_RICH_STYLE
		x+=this->m_uWindowTitleWidth;
	}
	if(this->m_ptTimeClock!=NULL){
		this->m_ptTimeClock->RedrawControl();
	}
#endif  //EG_SINGLE_COLOR
	//draw the popup menu
	if(this->m_ppmBasePopupMenu!=NULL){
		this->m_ppmBasePopupMenu->RedrawControl();		
	}
}
