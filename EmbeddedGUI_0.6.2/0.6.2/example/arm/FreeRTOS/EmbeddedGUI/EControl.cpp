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
	EControl.cpp   
*/

#include "EControl.h"

#ifndef EG_EXTERN_DEFAULT_STYLE
#ifdef EG_RGB_COLOR
	EStyle EG_DefaultStyle;
#endif
#endif  //EG_EXTERN_DEFAULT_STYLE

	void EControl::NoticeControl(EEvent* pevent){
		if(m_fpCallbackFunc!=NULL){
			m_fpCallbackFunc(this,pevent);
			if(this->m_bNeedRedraw){
				this->RedrawControl();
			}
		}	
	}

	bool EControl::InControlArea(EPosition curPos){
		int dx=curPos.m_uX-this->m_pControlPos.m_uX;
		int dy=curPos.m_uY-this->m_pControlPos.m_uY;
		if ((dx>=0)&&(dx<=static_cast<int>(this->m_zArea.m_uWidth))&&
			(dy>=0)&&(dy<=static_cast<int>(this->m_zArea.m_uHeight)))
			return true;
		else
			return false;
	}

	ELabel::ELabel(EPosition pos,char* pstring,unsigned int labelWidth)
		:EControl(NULL,EG_RedrawFunc_DefaultELabel,ESize(),pos),m_pLableString(pstring){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=8;
#else
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#endif  //EG_RICH_STYLE
			this->m_zArea.m_uWidth=labelWidth;
	}

	ELabel::ELabel(EG_CallbackFunc cf,EG_RedrawFunc rf,EPosition pos,char* pstring,unsigned int labelWidth)
		:EControl(cf,rf,ESize(),pos),m_pLableString(pstring){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=8;
#else
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#endif  //EG_RICH_STYLE
			this->m_zArea.m_uWidth=labelWidth;
	}

	EButton::EButton(EG_CallbackFunc cf,EPosition pos,char* pstring,unsigned int buttonWidth)
		:EControl(cf,EG_RedrawFunc_DefaultEButton,ESize(),pos),m_pButtonString(pstring){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=14;
#else
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+3;
#endif  //EG_RICH_STYLE
			this->m_zArea.m_uWidth=buttonWidth+6;
	}

	ECheckButton::ECheckButton(bool check,EPosition pos,char* pstring,unsigned int checkButtonWidth)
		:EControl(EG_CallbackFunc_DefaultECheckButton,EG_RedrawFunc_DefaultECheckButton,ESize(),pos){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=10;
			this->m_zArea.m_uWidth=10+checkButtonWidth;
#else
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
			this->m_zArea.m_uWidth=12+checkButtonWidth;
#endif  //EG_RICH_STYLE
			this->m_bCheckButtonChecked=check;
			this->m_pCheckButtonString=pstring;
	}

	ECheckButton::ECheckButton(EG_CallbackFunc cf,bool check,EPosition pos,char* pstring,unsigned int checkButtonWidth)
		:EControl(cf,EG_RedrawFunc_DefaultECheckButton,ESize(),pos){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=10;
			this->m_zArea.m_uWidth=10+checkButtonWidth;
#else
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
			this->m_zArea.m_uWidth=12+checkButtonWidth;
#endif  //EG_RICH_STYLE
			this->m_bCheckButtonChecked=check;
			this->m_pCheckButtonString=pstring;
	}

	EEdit::EEdit(bool password,EPosition pos,unsigned int editWidth)  
		:EControl(EG_CallbackFunc_DefaultEEdit,EG_RedrawFunc_DefaultEEdit,ESize(editWidth,0),pos){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=12;
#else
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
				this->m_zArea.m_uHeight=12;
			else
				this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
#endif  //EG_RICH_STYLE
			for(int n=0;n<MaxStringLength+1;n++)
				m_saString[n]='\0';
			this->m_ulength=0;
			this->m_bPassword=password;
	}

	EEdit::EEdit(char* pstring,bool password,EPosition pos,unsigned int editWidth)
		:EControl(EG_CallbackFunc_DefaultEEdit,EG_RedrawFunc_DefaultEEdit,ESize(editWidth,0),pos){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=12;
#else
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
				this->m_zArea.m_uHeight=12;
			else
				this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
#endif  //EG_RICH_STYLE
			for(int n=0;n<MaxStringLength+1;n++)
				m_saString[n]='\0';
			this->m_ulength=0;
			this->m_bPassword=password;
			this->SetString(pstring);
	}

	EEdit::EEdit(EG_CallbackFunc cf,char* pstring,bool password,EPosition pos,unsigned int editWidth)
		:EControl(cf,EG_RedrawFunc_DefaultEEdit,ESize(editWidth,0),pos){	
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=12;
#else
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
				this->m_zArea.m_uHeight=12;
			else
				this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
#endif  //EG_RICH_STYLE
			for(int n=0;n<MaxStringLength+1;n++)
				m_saString[n]='\0';
			this->m_ulength=0;
			this->m_bPassword=password;
			this->SetString(pstring);
	}

	void EEdit::AddCharToString(char str){
		if (this->m_ulength>=MaxStringLength)
			return;
		this->m_saString[this->m_ulength]=str;
		this->m_ulength++;
		this->RedrawControl();
	}

	void EEdit::SetString(char* string){
		int n=0;
		while(n<=MaxStringLength){
			if(string[n]!='\0'){
				this->m_saString[n]=string[n];
			}else{
				this->m_saString[n]='\0';
				this->m_ulength=n;
				break;
			}		
			n++;
		}	
		this->RedrawControl();
	}

	void EEdit::SetString(char string[],int length){
		int l,n=0;
		if (length>MaxStringLength)
			l=MaxStringLength;
		else
			l=length;
		for(;n<l;n++){
			this->m_saString[n]=string[n];
		}
		this->m_saString[n]='\0';
		this->m_ulength=l;
        this->RedrawControl();                    
	}

	EExtLabel::EExtLabel()
		:ELabel(EG_CallbackFunc_DefaultEExtLabel,EG_RedrawFunc_DefaultEExtLabel,EPosition(),NULL,0),m_bState(false){
#ifdef EG_RICH_STYLE
			this->m_uUnderlineCount=0;
#endif  //EG_RICH_STYLE
	}

	EExtLabel::EExtLabel(EPosition pos,char* pstring,unsigned int labelWidth)
		:ELabel(EG_CallbackFunc_DefaultEExtLabel,EG_RedrawFunc_DefaultEExtLabel,pos,pstring,labelWidth){	
#ifdef EG_RICH_STYLE
			this->m_uUnderlineCount=0;
#endif  //EG_RICH_STYLE
			this->m_bState=false;
	}

	EExtLabel::EExtLabel(EG_CallbackFunc cf,EPosition pos,char* pstring,unsigned int labelWidth)
		:ELabel(cf,EG_RedrawFunc_DefaultEExtLabel,pos,pstring,labelWidth){	
#ifdef EG_RICH_STYLE
			this->m_uUnderlineCount=0;
#endif  //EG_RICH_STYLE
			this->m_bState=false;
	}

	void EExtLabel::ChangeState(){
		if (this->m_bState)
			this->m_bState=false;
		else
			this->m_bState=true;
		this->RedrawControl();
	}

	EComboBox::EComboBox()
		:EControl(EG_CallbackFunc_DefaultEComboBox,EG_RedrawFunc_DefaultEComboBox){
		this->m_bOpen=false;
		for(int m=0;m<this->MaxItem;m++){
			for(int n=0;n<MaxStringLength+1;n++){
				m_saString[m][n]='\0';
			}
		}
		this->m_uItem=0;
		this->m_uSelectItem=0;
#ifdef EG_RICH_STYLE
		this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
		this->m_uHoverItem=0;
#else
		this->m_zArea.m_uHeight=10;
#endif  //EG_RICH_STYLE
	}

	EComboBox::EComboBox(EPosition pos,unsigned int comboBoxWidth)
		:EControl(EG_CallbackFunc_DefaultEComboBox,EG_RedrawFunc_DefaultEComboBox,ESize(comboBoxWidth,0),pos){	
		this->m_bOpen=false;
		for(int m=0;m<this->MaxItem;m++){
			for(int n=0;n<MaxStringLength+1;n++){
				m_saString[m][n]='\0';
			}
		}
#ifndef EG_RICH_STYLE
		this->m_zArea.m_uHeight=10;
#else
		this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
		this->m_uHoverItem=0;
#endif  //EG_RICH_STYLE
		this->m_uItem=0;
		this->m_uSelectItem=0;
	}

	void EComboBox::SetIemString(unsigned int index,char str[]){
		for(int n=0;n<MaxStringLength+1;n++){
			this->m_saString[index][n]=str[n];
		}
		this->RedrawControl();
	}

	void EComboBox::AddItem(char str[]){
		for(int n=0;n<MaxStringLength+1;n++){
			this->m_saString[this->m_uItem][n]=str[n];
		}
		this->m_uItem++;
		this->RedrawControl();
	}

	void EComboBox::RemoveItem(unsigned int index){
		int m=this->m_uItem;
		for (int c=index;c<m;c++){
			for(int n=0;n<MaxStringLength+1;n++){
				this->m_saString[c][n]=this->m_saString[c+1][n];
			}
		}
		this->m_uItem--;
		this->RedrawControl();
	}

	void EComboBox::SwitchOpenState(){
		if (this->m_bOpen){
			this->m_bOpen=false;
#ifdef EG_RICH_STYLE
			m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2;
#else
			m_zArea.m_uHeight=10;
#endif  //EG_RICH_STYLE
		}else{
#ifdef EG_RICH_STYLE
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10){
				m_zArea.m_uHeight=(this->m_uItem+1)*(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]+2);
			}else{
				m_zArea.m_uHeight=(this->m_uItem+1)*(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber])+2;
			}
#else
			this->m_zArea.m_uHeight=(this->m_uItem+1)*10;
#endif  //EG_RICH_STYLE
			this->m_bOpen=true;
		}
		this->RedrawControl();
	}

#ifdef EG_DEFAULT_ICON
	EIcon::EIcon(EG_CallbackFunc cf,EPosition pos,unsigned int iconIndex)
		:EControl(cf,EG_RedrawFunc_DefaultEIcon,ESize(0,0),pos),m_pbIcon(0,0){
		this->SetIconBuffer(iconIndex);
#ifdef EG_SINGLE_COLOR
		this->m_zArea.m_uWidth=16;
		this->m_zArea.m_uHeight=2;
#else
		this->m_zArea.m_uWidth=17;
		this->m_zArea.m_uHeight=17;
#endif //EG_SINGLE_COLOR
	}
#endif //EG_DEFAULT_ICON

#ifdef EG_DEFAULT_ICON
	void EIcon::SetIconBuffer(unsigned int iconIndex){
#ifdef EG_SINGLE_COLOR
		unsigned char* temp=(unsigned char*)EG_DefaultIcon;
		temp+=iconIndex*32;
		this->m_pbIcon.m_pImageBuffer=temp;
		this->m_pbIcon.m_uWidth=16;
		this->m_pbIcon.m_uHeight=2;
#else
		switch(iconIndex){
			case 0:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultFileBuffer;
				break;
			case 1:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultFolderBuffer;
				break;
			case 2:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultOpenFolderBuffer;
				break;
			case 3:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultQuestionBuffer;
				break;
			case 4:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultRightArrowBuffer;
				break;
			case 5:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultLeftArrowBuffer;
				break;
			case 6:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultErrorBuffer;
				break;
			case 7:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultWarningBuffer;
				break;
			case 8:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultCorrectBuffer;
				break;
			case 9:
				this->m_pbIcon.m_pImageBuffer=(unsigned char*)EG_DefaultSaveBuffer;
				break;
			default:
				this->m_pbIcon.m_pImageBuffer=NULL;
				break;
		}
		this->m_pbIcon.m_uWidth=17;
		this->m_pbIcon.m_uHeight=17;
#endif //EG_SINGLE_COLOR
	}
#endif  //EG_DEFAULT_ICON

	EIconButton::EIconButton(EG_CallbackFunc cf,EPosition pos,ESize buttonSize,ESize iconSize,unsigned char* pBuffer,
		char* pString,bool rightString)
		:EIcon(cf,pos,buttonSize,pBuffer){
			m_bRightString=rightString;
			m_pIconButtonString=pString;
			this->m_pbIcon.m_uHeight=iconSize.m_uHeight;
			this->m_pbIcon.m_uWidth=iconSize.m_uWidth;
			this->SetRedrawFunction(EG_RedrawFunc_DefaultEIconButton);
	}

	EIconButton::EIconButton(EG_CallbackFunc cf,EPosition pos,ESize buttonSize,unsigned int iconIndex,
		char* pString,bool rightString)
		:EIcon(cf,pos,iconIndex){
			m_bRightString=rightString;
			m_pIconButtonString=pString;
			this->m_zArea.m_uHeight=buttonSize.m_uHeight;
			this->m_zArea.m_uWidth=buttonSize.m_uWidth;
#ifdef EG_SINGLE_COLOR
			this->m_pbIcon.m_uHeight=2;
			this->m_pbIcon.m_uWidth=16;
#else
			this->m_pbIcon.m_uHeight=17;
			this->m_pbIcon.m_uWidth=17;
#endif //EG_SINGLE_COLOR
			this->SetRedrawFunction(EG_RedrawFunc_DefaultEIconButton);
	}

	EMessageBox::EMessageBox(unsigned char type,EPosition pos,char* pstring,unsigned int messageBoxWidth)
		:EControl(EG_CallbackFunc_DefaultEMessageBox,EG_RedrawFunc_DefaultEMessageBox,ESize(messageBoxWidth,0),pos){
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=22;
#else
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10){
				this->m_zArea.m_uHeight=(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<<1)+4;
			}else{
				this->m_zArea.m_uHeight=(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<<1);
			}
#endif  //EG_RICH_STYLE
			this->m_pMessageString=pstring;
			this->m_uMessageBoxType=type;	
			this->m_bOpen=true;
	}

	bool EMessageBox::InCloseArea(const EPosition& pos){
#ifdef EG_RICH_STYLE
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10){
			if((pos.m_uX>this->m_pControlPos.m_uX+this->m_zArea.m_uWidth-8)&&(pos.m_uY>this->m_pControlPos.m_uY+1)
				&&(pos.m_uX<this->m_pControlPos.m_uX+this->m_zArea.m_uWidth-1)&&(pos.m_uY<this->m_pControlPos.m_uY+8)){
				return true;
			}else{
				return false;
			}
		}else{
			if((pos.m_uX>this->m_pControlPos.m_uX+this->m_zArea.m_uWidth-12)&&(pos.m_uY>this->m_pControlPos.m_uY+2)
				&&(pos.m_uX<this->m_pControlPos.m_uX+this->m_zArea.m_uWidth-2)&&(pos.m_uY<this->m_pControlPos.m_uY+12)){
				return true;
			}else{
				return false;
			}
		}
#else
		if((pos.m_uX>this->m_pControlPos.m_uX)&&(pos.m_uY>this->m_pControlPos.m_uY+9)
			&&(pos.m_uX<this->m_pControlPos.m_uX+this->m_zArea.m_uWidth)
			&&(pos.m_uY<this->m_pControlPos.m_uY+this->m_zArea.m_uHeight)){
			return true;
		}else{
			return false;
		}
#endif  //EG_RICH_STYLE
	}
	
	void EMessageBox::SwitchState(){
		if(this->m_bOpen){
			this->m_bOpen=false;	
		}else{
			this->m_bOpen=true;
		}
		this->RedrawControl();
	}

	EDialogBox::EDialogBox(unsigned char type,EPosition pos,char* pstring,unsigned int dialogBoxWidth)
		:EControl(EG_CallbackFunc_DefaultEDialogBox,EG_RedrawFunc_DefaultEDialogBox,ESize(dialogBoxWidth,0),pos){
			this->m_pMessageString=pstring;
			this->m_uDialogBoxType=type;	
			this->m_uDialogState=0;
#ifndef EG_RICH_STYLE
			this->m_zArea.m_uHeight=34;
#else
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10){
				this->m_zArea.m_uHeight=34;
			}else{
				this->m_zArea.m_uHeight=(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]*3)+5;
			}
#endif  //EG_RICH_STYLE
			if(this->m_zArea.m_uWidth<115)
				this->m_zArea.m_uWidth=115;
	}

	void EDialogBox::UpdataState(const EPosition& pos){
#ifdef EG_RICH_STYLE
		unsigned char charHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
		if(charHeight<=10){
			if((pos.m_uX>=m_pControlPos.m_uX+5)&&(pos.m_uX<=m_pControlPos.m_uX+55)
				&&(pos.m_uY>=m_pControlPos.m_uY+22)&&(pos.m_uY<=m_pControlPos.m_uY+32)){
					this->m_uDialogState=1;
			}else if((pos.m_uX>=m_pControlPos.m_uX+60)&&(pos.m_uX<=m_pControlPos.m_uX+110)
				&&(pos.m_uY>=m_pControlPos.m_uY+22)&&(pos.m_uY<=m_pControlPos.m_uY+32)){
					this->m_uDialogState=2;
			}
		}else{
			if((pos.m_uX>=m_pControlPos.m_uX+5)&&(pos.m_uX<=m_pControlPos.m_uX+55)
				&&(pos.m_uY>=this->m_pControlPos.m_uY+(charHeight<<1)+2)
				&&(pos.m_uY<=this->m_pControlPos.m_uY+(charHeight<<1)+18)){
					this->m_uDialogState=1;
			}else if((pos.m_uX>=m_pControlPos.m_uX+60)&&(pos.m_uX<=m_pControlPos.m_uX+110)
				&&(pos.m_uY>=this->m_pControlPos.m_uY+(charHeight<<1)+2)
				&&(pos.m_uY<=this->m_pControlPos.m_uY+(charHeight<<1)+18)){
					this->m_uDialogState=2;
			}		
		}
#else
		if((pos.m_uX>=m_pControlPos.m_uX+5)&&(pos.m_uX<=m_pControlPos.m_uX+55)
			&&(pos.m_uY>=m_pControlPos.m_uY+22)&&(pos.m_uY<=m_pControlPos.m_uY+32)){
				this->m_uDialogState=1;
		}else if((pos.m_uX>=m_pControlPos.m_uX+60)&&(pos.m_uX<=m_pControlPos.m_uX+110)
			&&(pos.m_uY>=m_pControlPos.m_uY+22)&&(pos.m_uY<=m_pControlPos.m_uY+32)){
				this->m_uDialogState=2;
		}
#endif  //EG_RICH_STYLE
	}

	EScroll::EScroll():EControl(EG_CallbackFunc_DefaultEScroll,EG_RedrawFunc_DefaultEScroll){
		this->m_uCurPosition=8;
		this->m_uStepValue=5;
#ifdef EG_RICH_STYLE
		this->m_bWideScroll=false;
#endif //EG_RICH_STYLE
	}

#ifdef EG_RICH_STYLE
	EScroll::EScroll(EPosition pos,unsigned int height,unsigned int step,bool wideScroll)
		:EControl(EG_CallbackFunc_DefaultEScroll,EG_RedrawFunc_DefaultEScroll,ESize(8,height),pos){
		this->m_uStepValue=step;
		this->m_bWideScroll=wideScroll;
		if(wideScroll){
			this->m_uCurPosition=12;
			this->m_zArea.m_uWidth=12;		
		}else{
			this->m_uCurPosition=8;
		}
	}
#else 
	EScroll::EScroll(EPosition pos,unsigned int height,unsigned int step)
		:EControl(EG_CallbackFunc_DefaultEScroll,EG_RedrawFunc_DefaultEScroll,ESize(8,height),pos){
		this->m_uCurPosition=8;
		this->m_uStepValue=step;
	}
#endif  //EG_RICH_STYLE

	void EScroll::SetCurrentPosition(unsigned int pos){
#ifdef EG_RICH_STYLE
		if(this->m_bWideScroll){
			if(pos<12){
				this->m_uCurPosition=12;
			}else if(pos>=this->m_zArea.m_uHeight-24){
				this->m_uCurPosition=this->m_zArea.m_uHeight-24;			
			}else{
				this->m_uCurPosition=pos;			
			}
		}else{
			if(pos<8){
				this->m_uCurPosition=8;
			}else if(pos>=this->m_zArea.m_uHeight-16){
				this->m_uCurPosition=this->m_zArea.m_uHeight-16;			
			}else{
				this->m_uCurPosition=pos;			
			}
		}
#else
		if(pos<8){
			this->m_uCurPosition=8;
		}else if(pos>=this->m_zArea.m_uHeight-16){
			this->m_uCurPosition=this->m_zArea.m_uHeight-16;			
		}else{
			this->m_uCurPosition=pos;			
		}
#endif  //EG_RICH_STYLE
	}

	void EList::AddItem(EListItem* pitem){
		if(m_uItemCount<MaxRow){
			this->m_parrItem[this->m_uItemCount]=pitem;
			this->m_uItemCount++;
		}
#ifdef EG_RICH_STYLE
		unsigned int delta;
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
			delta=9;
		else
			delta=16;
		//reset the height
		if(m_uItemCount>=1)
			this->m_zArea.m_uHeight=1+delta*m_uItemCount;
		else
			this->m_zArea.m_uHeight=0;
#else
		//reset the height
		if(m_uItemCount>=1)
			this->m_zArea.m_uHeight=10+9*(m_uItemCount-1);
		else
			this->m_zArea.m_uHeight=0;
#endif  //EG_RICH_STYLE
	}

	void EList::RemoveItem(int index){
		int m=this->m_uItemCount;
		for (int c=index;c<m;c++){
			this->m_parrItem[c]=this->m_parrItem[c+1];
		}
		this->m_uItemCount--;
#ifdef EG_RICH_STYLE
		unsigned int delta;
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
			delta=9;
		else
			delta=16;
		//reset the height
		if(m_uItemCount>=1)
			this->m_zArea.m_uHeight=1+delta*m_uItemCount;
		else
			this->m_zArea.m_uHeight=0;
#else
		//reset the height
		if(m_uItemCount>=1)
			this->m_zArea.m_uHeight=10+9*(m_uItemCount-1);
		else
			this->m_zArea.m_uHeight=0;
#endif  //EG_RICH_STYLE
	}
	
	void EList::RemoveAllItems(){
		//note the base item could not be removed.
		for(unsigned int n=1;n<m_uItemCount;n++){
			m_parrItem[n]=NULL;
		}	
#ifdef EG_RICH_STYLE
		unsigned int delta;
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
			delta=10;
		else
			delta=17;
		//reset the height
		this->m_zArea.m_uHeight=delta;
#else
		//reset the height
		this->m_zArea.m_uHeight=10;
#endif  //EG_RICH_STYLE
		m_uItemCount=0;
	}

	void EList::AddColumn(unsigned int width){
		if(m_uColumnCount>=MaxColumn)
			return;
		this->m_uarrColumnWidth[m_uColumnCount]=width;		
		m_uColumnCount++;
		//reset the width
		this->m_zArea.m_uWidth=0;
		for(unsigned int n=0;n<m_uColumnCount;n++){
			this->m_zArea.m_uWidth+=this->m_uarrColumnWidth[n];	
		}
	}

	void EList::SetColumnWidth(unsigned int columnIndex,unsigned int width){
		if(m_uColumnCount<=columnIndex)
			return;
		this->m_uarrColumnWidth[columnIndex]=width;		
		//reset the width
		this->m_zArea.m_uWidth=0;
		for(unsigned int n=0;n<m_uColumnCount;n++){
			this->m_zArea.m_uWidth+=this->m_uarrColumnWidth[n];	
		}
	}

	void EList::SetItem(unsigned int itemIndex,unsigned int columnIndex,char* pstring){
		unsigned int n=0;
		if((itemIndex<m_uItemCount)&&(columnIndex<MaxColumn)){
			while((pstring[n]!='\0')&&(n<=MaxStringLength)){
				m_parrItem[itemIndex]->m_saString[columnIndex][n]=pstring[n];
				n++;
			}
			m_parrItem[itemIndex]->m_saString[columnIndex][n]=pstring[n];
		}	
	}

	void EList::SetItem(unsigned int itemIndex,unsigned int columnIndex,char* pstring,EG_CallbackFunc cbfHandler){
		unsigned int n=0;
		if((itemIndex<m_uItemCount)&&(columnIndex<MaxColumn)){
			while((pstring[n]!='\0')&&(n<=MaxStringLength)){
				m_parrItem[itemIndex]->m_saString[columnIndex][n]=pstring[n];
				n++;
			}
			m_parrItem[itemIndex]->m_saString[columnIndex][n]=pstring[n];
			m_parrItem[itemIndex]->m_pcbListHandler=cbfHandler;
		}	
	}

	EMenu::EMenu():EControl(){
		for(int n=0;n<this->MaxMenuItem;n++){
			this->m_parrMenuItemArray[n]=NULL;
		}
		this->m_uBaseMenuWidth=0;
		this->m_zArea.m_uWidth=0;
		this->m_uTempWidth=0;
		this->m_uOriginalY=0;
		this->m_zArea.m_uHeight=0;
		this->m_uItemNumber=0;
		this->m_bDisplay=false;
		this->m_bUpperExtend=false;
		this->m_uItemSelect=0;
		this->m_pMenuString=NULL;
	}

	EMenu::EMenu(char* pString,unsigned int menuWidth,EPosition pos,bool upperExtend)
		:EControl(EG_CallbackFunc_DefaultEMenu,EG_RedrawFunc_DefaultEMenu,ESize(0,0),pos){	
			for(int n=0;n<this->MaxMenuItem;n++){
				this->m_parrMenuItemArray[n]=NULL;
			}
			this->m_uBaseMenuWidth=menuWidth;
			this->m_zArea.m_uWidth=m_uBaseMenuWidth;
			this->m_uTempWidth=m_uBaseMenuWidth;
			this->m_uOriginalY=pos.m_uY;
#ifdef EG_RICH_STYLE
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
				this->m_zArea.m_uHeight=10;
			else
				this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#else
			this->m_zArea.m_uHeight=10;
#endif  //EG_RICH_STYLE
			this->m_uItemNumber=0;
			this->m_bDisplay=false;
			this->m_bUpperExtend=upperExtend;
			this->m_uItemSelect=0;
			this->m_pMenuString=pString;
	}

	int EMenu::AddItem(EMenuItem* pItem){
		unsigned int n=0;
		unsigned int m=0;
		if (this->m_uItemNumber<this->MaxMenuItem){
			while((pItem->m_pcLabel[n]!='\0')&&(n<=MaxStringLength)){
				n++;
			}
#ifdef EG_RICH_STYLE
			if(pItem->m_piIcon!=0)
				m=pItem->m_piIcon->m_uWidth+1;
#endif  //EG_RICH_STYLE
			if(this->m_zArea.m_uWidth<((n<<3)+4+m)){
				this->m_zArea.m_uWidth=((n<<3)+4+m);
				this->m_uTempWidth=m_zArea.m_uWidth;
			}
			this->m_parrMenuItemArray[this->m_uItemNumber]=pItem;
			this->m_uItemNumber++;
			return this->m_uItemNumber;
		}
		return -1;
	}

	void EMenu::RemovedAllItems(){
		for(int n=0;n<this->MaxMenuItem;n++){
			this->m_parrMenuItemArray[n]=NULL;
		}
		this->m_uItemNumber=0;
#ifdef EG_RICH_STYLE
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
			this->m_zArea.m_uHeight=10;
		else
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#else
		this->m_zArea.m_uHeight=10;
#endif  //EG_RICH_STYLE
		this->m_zArea.m_uWidth=m_uBaseMenuWidth;
	}

	void EMenu::SetMenuItemState(unsigned int index,unsigned char state){
		if (index<this->m_uItemNumber){
			this->m_parrMenuItemArray[index]->m_uState=state;
		    m_bNeedRedraw=true;
		}	
	}

	void EMenu::SetMenuItem(unsigned int index,char* label,unsigned char state){
		unsigned int n=0;
		unsigned int m=0;
		if((index<this->MaxMenuItem)&&(index<this->m_uItemNumber)){
			while((label[n]!='\0')&&(n<=MaxStringLength)){
				this->m_parrMenuItemArray[index]->m_pcLabel[n]=label[n];
				n++;
			}
#ifdef EG_RICH_STYLE
			if(this->m_parrMenuItemArray[index]->m_piIcon!=0)
				m=this->m_parrMenuItemArray[index]->m_piIcon->m_uWidth+1;
#endif  //EG_RICH_STYLE
			if(this->m_zArea.m_uWidth<((n<<3)+4+m)){
				this->m_zArea.m_uWidth=((n<<3)+4+m);
				this->m_uTempWidth=m_zArea.m_uWidth;
			}
			this->m_parrMenuItemArray[index]->m_pcLabel[n]='\0';
			this->m_parrMenuItemArray[index]->m_uState=state;
		}	
        m_bNeedRedraw=true;
	}

#ifndef EG_RICH_STYLE
	void EMenu::SetMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback){
		unsigned int n=0;
		if((index<this->MaxMenuItem)&&(index<this->m_uItemNumber)){
			while((label[n]!='\0')&&(n<=MaxStringLength)){
				this->m_parrMenuItemArray[index]->m_pcLabel[n]=label[n];
				n++;
			}
			if(this->m_zArea.m_uWidth<((n<<3)+4)){
				this->m_zArea.m_uWidth=((n<<3)+4);
				this->m_uTempWidth=m_zArea.m_uWidth;
			}
			this->m_parrMenuItemArray[index]->m_pcLabel[n]='\0';
			this->m_parrMenuItemArray[index]->m_uState=state;
			this->m_parrMenuItemArray[index]->m_fpCallbackFunc=fpCallback;
		}	
        m_bNeedRedraw=true;
	}
#else
	void EMenu::SetMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback,EBitmap* pIcon){
		unsigned int n=0;
		unsigned int m=0;
		if((index<this->MaxMenuItem)&&(index<this->m_uItemNumber)){
			while((label[n]!='\0')&&(n<=MaxStringLength)){
				this->m_parrMenuItemArray[index]->m_pcLabel[n]=label[n];
				n++;
			}
			if(pIcon!=0)
				m=pIcon->m_uWidth+1;
			if(this->m_zArea.m_uWidth<((n<<3)+4+m)){
				this->m_zArea.m_uWidth=((n<<3)+4+m);
				this->m_uTempWidth=m_zArea.m_uWidth;
			}
			this->m_parrMenuItemArray[index]->m_pcLabel[n]='\0';
			this->m_parrMenuItemArray[index]->m_uState=state;
			this->m_parrMenuItemArray[index]->m_fpCallbackFunc=fpCallback;
			this->m_parrMenuItemArray[index]->m_piIcon=pIcon;
		}	
        m_bNeedRedraw=true;
	}
#endif  //EG_RICH_STYLE

	void EMenu::SwitchShowState(){
		if (this->m_bDisplay){
			this->m_uTempWidth=m_zArea.m_uWidth;
			m_zArea.m_uWidth=this->m_uBaseMenuWidth;
			this->m_bDisplay=false;
		}else{
			this->m_zArea.m_uWidth=m_uTempWidth;
			this->m_zArea.m_uHeight=(this->m_uItemNumber+1)*10;
			this->m_bDisplay=true;
		}
		if(this->m_bUpperExtend==false){
#ifdef EG_RICH_STYLE
			unsigned int delta;
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
				delta=10;
			else
				delta=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
			if(this->m_bDisplay){
				this->m_zArea.m_uHeight=delta*(1+this->m_uItemNumber);
			}else{
				this->m_zArea.m_uHeight=delta;
			}
#else
			if(this->m_bDisplay){
				this->m_zArea.m_uHeight=10*(1+this->m_uItemNumber);
			}else{
				this->m_zArea.m_uHeight=10;
			}
#endif  //EG_RICH_STYLE
		}else{
			this->UpdateHeightAndPosition();
		}
		this->RedrawControl();
	}

	void EMenu::CollapseMenu(){
		if (this->m_bDisplay){
#ifdef EG_RICH_STYLE
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
				this->m_zArea.m_uHeight=10;
			else
				this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#else
			this->m_zArea.m_uHeight=10;
#endif  //EG_RICH_STYLE
			this->m_uTempWidth=m_zArea.m_uWidth;
			m_zArea.m_uWidth=this->m_uBaseMenuWidth;
			this->m_bDisplay=false;
		}
	}

	void EMenu::UpdateHeightAndPosition(){
#ifdef EG_RICH_STYLE
		unsigned int delta;
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
			delta=10;
		else
			delta=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
		if(!this->m_bDisplay){
			this->m_pControlPos.m_uY=this->m_uOriginalY;
			this->m_zArea.m_uHeight=delta;
		}else{
			this->m_pControlPos.m_uY=this->m_uOriginalY-delta*this->m_uItemNumber;
			this->m_zArea.m_uHeight=delta*(1+this->m_uItemNumber);
		}
#else
		if(!this->m_bDisplay){
			this->m_pControlPos.m_uY=this->m_uOriginalY;
			this->m_zArea.m_uHeight=10;
		}else{
			this->m_pControlPos.m_uY=this->m_uOriginalY-10*this->m_uItemNumber;
			this->m_zArea.m_uHeight=10*(1+this->m_uItemNumber);
		}
#endif  //EG_RICH_STYLE
	}

	EPopupMenu::EPopupMenu():EControl(EG_CallbackFunc_DefaultEPopupMenu,EG_RedrawFunc_DefaultEPopupMenu){
			for(int n=0;n<this->MaxMenuItem;n++){
				this->m_parrPopupMenuItemArray[n]=NULL;
			}
			this->m_uItemNumber=0;
			this->m_bDisplay=false;
			this->m_uItemSelect=0;
			this->m_zDisplayArea.m_uWidth=0;
			this->m_zDisplayArea.m_uHeight=0;
	}

	int EPopupMenu::AddItem(EPopupMenuItem* pItem){
		unsigned int n=0;
		if (this->m_uItemNumber<this->MaxMenuItem){
			while((pItem->m_pcLabel[n]!='\0')&&(n<=MaxStringLength)){
				n++;
			}
#ifdef EG_RICH_STYLE
			unsigned int m=0;
			if(pItem->m_piIcon!=0)
				m=pItem->m_piIcon->m_uWidth+1;
			if(this->m_zDisplayArea.m_uWidth<((n<<3)+4+m)){
				this->m_zDisplayArea.m_uWidth=((n<<3)+4+m);
			}
			if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10)
				this->m_zDisplayArea.m_uHeight+=10;
			else
				this->m_zDisplayArea.m_uHeight+=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#else
			if(this->m_zDisplayArea.m_uWidth<((n<<3)+4)){
				this->m_zDisplayArea.m_uWidth=((n<<3)+4);
			}
			this->m_zDisplayArea.m_uHeight+=10;
#endif  //EG_RICH_STYLE
			this->m_parrPopupMenuItemArray[this->m_uItemNumber]=pItem;
			this->m_uItemNumber++;
			return this->m_uItemNumber;
		}
		return -1;
	}

	void EPopupMenu::RemovedAllItems(){
		for(int n=0;n<this->MaxMenuItem;n++){
			this->m_parrPopupMenuItemArray[n]=NULL;
		}
		this->m_uItemNumber=0;
		this->m_zDisplayArea.m_uHeight=0;
		this->m_zDisplayArea.m_uWidth=0;
	}

	void EPopupMenu::SetPopupMenuItemState(unsigned int index,unsigned char state){
		if (index<this->m_uItemNumber){
			this->m_parrPopupMenuItemArray[index]->m_uState=state;
		    m_bNeedRedraw=true;
		}	
	}

	void EPopupMenu::SetPopupMenuItem(unsigned int index,char* label,unsigned char state){
		unsigned int n=0;
		if((index<this->MaxMenuItem)&&(index<this->m_uItemNumber)){
			while((label[n]!='\0')&&(n<=MaxStringLength)){
				this->m_parrPopupMenuItemArray[index]->m_pcLabel[n]=label[n];
				n++;
			}
#ifdef EG_RICH_STYLE
			unsigned int m=0;
			if(m_parrPopupMenuItemArray[index]->m_piIcon!=0)
				m=m_parrPopupMenuItemArray[index]->m_piIcon->m_uWidth+1;
			if(this->m_zDisplayArea.m_uWidth<((n<<3)+4+m)){
				this->m_zDisplayArea.m_uWidth=((n<<3)+4+m);
			}
#else
			if(this->m_zDisplayArea.m_uWidth<((n<<3)+4)){
				this->m_zDisplayArea.m_uWidth=((n<<3)+4);
			}
#endif  //EG_RICH_STYLE
			this->m_parrPopupMenuItemArray[index]->m_pcLabel[n]='\0';
			this->m_parrPopupMenuItemArray[index]->m_uState=state;
		}	
        m_bNeedRedraw=true;
	}

#ifndef EG_RICH_STYLE
	void EPopupMenu::SetPopupMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback){
		unsigned int n=0;
		if((index<this->MaxMenuItem)&&(index<this->m_uItemNumber)){
			while((label[n]!='\0')&&(n<=MaxStringLength)){
				this->m_parrPopupMenuItemArray[index]->m_pcLabel[n]=label[n];
				n++;
			}
			if(this->m_zDisplayArea.m_uWidth<((n<<3)+4)){
				this->m_zDisplayArea.m_uWidth=((n<<3)+4);
			}
			this->m_parrPopupMenuItemArray[index]->m_pcLabel[n]='\0';
			this->m_parrPopupMenuItemArray[index]->m_uState=state;
			this->m_parrPopupMenuItemArray[index]->m_fpCallbackFunc=fpCallback;
		}	
        m_bNeedRedraw=true;
	}
#else
	void EPopupMenu::SetPopupMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback,EBitmap* pIcon){
		unsigned int n=0;
		unsigned int m=0;
		if((index<this->MaxMenuItem)&&(index<this->m_uItemNumber)){
			while((label[n]!='\0')&&(n<=MaxStringLength)){
				this->m_parrPopupMenuItemArray[index]->m_pcLabel[n]=label[n];
				n++;
			}
			if(pIcon!=0)
				m=pIcon->m_uWidth+1;
			if(this->m_zDisplayArea.m_uWidth<((n<<3)+4+m)){
				this->m_zDisplayArea.m_uWidth=((n<<3)+4+m);
			}
			this->m_parrPopupMenuItemArray[index]->m_pcLabel[n]='\0';
			this->m_parrPopupMenuItemArray[index]->m_uState=state;
			this->m_parrPopupMenuItemArray[index]->m_fpCallbackFunc=fpCallback;
			this->m_parrPopupMenuItemArray[index]->m_piIcon=pIcon;
		}	
        m_bNeedRedraw=true;
	}
#endif  //EG_RICH_STYLE

	void EPopupMenu::ShowPopupMenu(const EPosition& pos){
		if (this->m_bDisplay)
			return;
		this->m_pControlPos=pos;
		this->m_zArea=this->m_zDisplayArea;
		this->m_bDisplay=true;
		this->RedrawControl();
	}

	void EPopupMenu::ClosePopupMenu(){
		this->m_zArea.m_uHeight=0;
		this->m_zArea.m_uWidth=0;
		this->m_bDisplay=false;
	}

	ETree::ETreeSubItem::ETreeSubItem(){
		m_pTreeItem=NULL;
		m_pFather=NULL;
		for(unsigned int n=0;n<MaxStringLength;n++){
			m_saString[n]='\0';
		}
	}

	unsigned int ETree::ETreeSubItem::GetOpenSubItemCount(){
		if(m_pTreeItem==NULL){
			return 0;
		}else{
			return m_pTreeItem->GetOpenSubItemCount();
		}	
	}

	ETree::ETreeSubItem* ETree::ETreeSubItem::GetOpenSubItem(unsigned int& index){
		if(index==0)
			return this;
		else
			index--;
		if(m_bOpen){
			if(m_pTreeItem==NULL){
				return NULL;				
			}else{
				return m_pTreeItem->GetOpenSubItem(index);
			}
		}else{
			return NULL;
		}
	}

	void ETree::ETreeSubItem::SetSubItemString(char* pString){
		for(unsigned int n=0;n<MaxStringLength;n++){
			if(pString[n]!='\0')
				this->m_saString[n]=pString[n];
			else{
				this->m_saString[n]='\0';
				return;
			}
		}
	}

	ETree::ETreeItem::ETreeItem(){
		m_uSubItemCount=0;
		m_uDepth=0;
		for(unsigned int n=0;n<MaxSubItem;n++){
			m_pTreeSubItem[n]=NULL;
		}
	}

	unsigned int ETree::ETreeItem::AddSubItem(ETreeSubItem* psubitem){
		if(m_uSubItemCount<MaxSubItem){
			psubitem->m_pFather=this;
			m_pTreeSubItem[m_uSubItemCount]=psubitem;
			m_uSubItemCount++;
			return m_uSubItemCount-1;
		}
		return MaxSubItem;
	}
	
	unsigned int ETree::ETreeItem::GetOpenSubItemCount(){
		unsigned int res=0;
		for(unsigned int n=0;n<m_uSubItemCount;n++){
			if(m_pTreeSubItem[n]->m_bOpen){
				res+=1;
				res+=m_pTreeSubItem[n]->GetOpenSubItemCount();
			}
		}
		return res;
	}

	void ETree::ETreeItem::OpenAllSubItem(){
		for(unsigned int n=0;n<m_uSubItemCount;n++){
			m_pTreeSubItem[n]->OpenSubItem();
			m_pTreeSubItem[n]->m_bOpen=true;
		}
	}

	void ETree::ETreeItem::CloseAllSubItem(){
		for(unsigned int n=0;n<m_uSubItemCount;n++){
			m_pTreeSubItem[n]->CloseSubItem();
			m_pTreeSubItem[n]->m_bOpen=false;
		}
	}

	ETree::ETreeSubItem* ETree::ETreeItem::GetOpenSubItem(unsigned int& index){
		ETreeSubItem* temp=NULL;
		for(unsigned int n=0;n<m_uSubItemCount;n++){
			if(m_pTreeSubItem[n]->m_bOpen){
				temp=m_pTreeSubItem[n]->GetOpenSubItem(index);
				if(temp!=NULL){
					return temp;
				}
			}
		}
		return NULL;
	}

	unsigned int ETree::AddRoot(ETreeSubItem* pSubItem,char* rootString){
		unsigned int temp;
		temp=this->m_tiTreeStruct.AddSubItem(pSubItem);
		if(temp<MaxSubItem){
			for(unsigned int n=0;n<MaxStringLength;n++){
				if(rootString[n]!='\0')
					this->m_tiTreeStruct.m_pTreeSubItem[temp]->m_saString[n]=rootString[n];
				else{
					this->m_tiTreeStruct.m_pTreeSubItem[temp]->m_saString[n]='\0';
					break;
				}
			}
			return temp;
		}
		return MaxSubItem;
	}

	void ETree::AddBranch(ETreeItem* pleaf,unsigned int rootIndex){
		if(this->m_tiTreeStruct.m_uSubItemCount>rootIndex){
			pleaf->m_uDepth=1;
			this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem=pleaf;
		}
	}

	void ETree::AddBranch(ETreeItem* pleaf,unsigned int rootIndex,unsigned int leafIndex){
		if(this->m_tiTreeStruct.m_uSubItemCount>rootIndex){
			pleaf->m_uDepth=2;
			if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_uSubItemCount>leafIndex){
				this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_pTreeSubItem[leafIndex]->m_pTreeItem=pleaf;
			}
		}
	}

	unsigned int ETree::AddLeaf(unsigned int rootIndex,ETreeSubItem* pSubItem,char* pString){
		unsigned int temp;
		if(rootIndex<this->m_tiTreeStruct.m_uSubItemCount){
			if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem!=NULL){
				temp=this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->AddSubItem(pSubItem);
				if(temp<MaxSubItem){
					for(unsigned int n=0;n<MaxStringLength;n++){
						if(pString[n]!='\0')
							this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->
							m_pTreeItem->m_pTreeSubItem[temp]->m_saString[n]=pString[n];
						else{
							this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->
							m_pTreeItem->m_pTreeSubItem[temp]->m_saString[n]='\0';
							break;
						}
					}
					return temp;
				}
			}
		}
		return MaxSubItem;
	}

	unsigned int ETree::AddLeaf(unsigned int rootIndex,unsigned int leafIndex,ETreeSubItem* pSubItem,char* pString){
		unsigned int temp;
		if(rootIndex<this->m_tiTreeStruct.m_uSubItemCount){
			if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem!=NULL){
				if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_pTreeSubItem[leafIndex]!=NULL){
					temp=this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->
						m_pTreeSubItem[leafIndex]->m_pTreeItem->AddSubItem(pSubItem);
					if(temp<MaxSubItem){
						this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->
							m_pTreeSubItem[leafIndex]->m_pTreeItem->m_pTreeSubItem[temp]->SetSubItemString(pString);								
						return temp;
					}
				}
			}
		}
		return MaxSubItem;
	}

	void ETree::RemoveAllRoots(){
		this->m_tiTreeStruct.m_uSubItemCount=0;
		for(unsigned int n=0;n<MaxSubItem;n++){
			this->m_tiTreeStruct.m_pTreeSubItem[n]=NULL;
		}
	}

	void ETree::RemoveRoot(unsigned int rootIndex){
		unsigned int m=this->m_tiTreeStruct.m_uSubItemCount;
		for (unsigned int c=rootIndex;c<m;c++){
			this->m_tiTreeStruct.m_pTreeSubItem[c]=this->m_tiTreeStruct.m_pTreeSubItem[c+1];
		}
		this->m_tiTreeStruct.m_uSubItemCount--;			
	}

	void ETree::ToggleRootState(unsigned int rootIndex){
		if(rootIndex<this->m_tiTreeStruct.m_uSubItemCount){
			if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_bOpen)
				this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_bOpen=false;
			else
				this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_bOpen=true;
		}
		this->RedrawControl();
	}

	void ETree::ToggleLeafState(unsigned int rootIndex,unsigned int leafIndex){
		if(rootIndex<this->m_tiTreeStruct.m_uSubItemCount){
			if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem!=NULL){
				if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_pTreeSubItem[leafIndex]->m_bOpen){
					this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_pTreeSubItem[leafIndex]->m_bOpen=false;
				}else{
					this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_pTreeSubItem[leafIndex]->m_bOpen=true;
				}
			}
		}
		this->RedrawControl();
	}

	void ETree::DrawExtendIcon(const EPosition& pos,bool open){
#ifdef EG_SINGLE_COLOR
		EG_Graphic_DrawEmptyRectangle(pos.m_uX,pos.m_uY,6,6);
		EG_Graphic_DrawHorizonLine(pos.m_uX+1,pos.m_uY+3,5);
		if(!open){
			EG_Graphic_DrawVerticalLine(pos.m_uX+3,pos.m_uY+1,5);
		}
#else
		EPosition temppos;
		temppos.m_uX=pos.m_uX+1;
		temppos.m_uY=pos.m_uY+3;
		EG_Graphic_DrawEmptyRectangle(pos,ESize(6,6),this->m_pStyle->m_cContentColor);
		EG_Graphic_DrawHorizonLine(temppos,5,this->m_pStyle->m_cContentColor);
		if(!open){
			temppos.m_uX=pos.m_uX+3;
			temppos.m_uY=pos.m_uY+1;
			EG_Graphic_DrawVerticalLine(temppos,5,this->m_pStyle->m_cContentColor);
		}
#endif  //EG_SINGLE_COLOR
	}

	EToolBar::EToolBar():EControl(EG_CallbackFunc_DefaultEToolBar,EG_RedrawFunc_DefaultEToolBar){
		m_cDockState=0;
		m_bPositionAdjust=false;
		this->RemoveAllItems();
	}
	
	EToolBar::EToolBar(EPosition pos):EControl(EG_CallbackFunc_DefaultEToolBar,EG_RedrawFunc_DefaultEToolBar,ESize(0,10),pos){
		m_cDockState=0;
		m_bPositionAdjust=false;
		this->RemoveAllItems();
	}

	unsigned int EToolBar::AddItem(EControl* pitem){
		if(m_uItemCount<MaxItem){
			this->m_parrToolBarItem[this->m_uItemCount]=pitem;
			this->m_uItemCount++;
		}
		this->m_zArea.m_uWidth+=1;
		this->m_zArea.m_uWidth+=pitem->m_zArea.m_uWidth;
		if(this->m_zArea.m_uHeight<pitem->m_zArea.m_uHeight+1)
			this->m_zArea.m_uHeight=pitem->m_zArea.m_uHeight+1;
		m_bPositionAdjust=false;
		return m_uItemCount;
	}

	void EToolBar::RemoveItem(unsigned int index){
		unsigned int m=this->m_uItemCount;
		//reset the width
		if(m_uItemCount>=1){
			this->m_zArea.m_uWidth-=1;
			this->m_zArea.m_uWidth-=this->m_parrToolBarItem[index]->m_zArea.m_uWidth;
		}else{
			this->m_zArea.m_uWidth=0;
		}
		for (unsigned int c=index;c<m;c++){
			this->m_parrToolBarItem[c]=this->m_parrToolBarItem[c+1];
		}
		this->m_uItemCount--;
		UpdateToolBarHeight();
		m_bPositionAdjust=false;
	}

	void EToolBar::RemoveAllItems(){
		for(unsigned int n=0;n<m_uItemCount;n++){
			m_parrToolBarItem[n]=NULL;
		}	
		this->m_zArea.m_uHeight=0;
		this->m_zArea.m_uWidth=0;
		m_uItemCount=0;
	}

	void EToolBar::AdjustControlPosition(){
		unsigned int curPosX=this->m_pControlPos.m_uX+1;
		for(unsigned int n=0;n<this->m_uItemCount;n++){
			this->m_parrToolBarItem[n]->m_pControlPos.m_uX=curPosX;
			this->m_parrToolBarItem[n]->m_pControlPos.m_uY=this->m_pControlPos.m_uY+1;
			curPosX+=this->m_parrToolBarItem[n]->m_zArea.m_uWidth;
			curPosX+=1;
		}
		m_bPositionAdjust=true;
	}

	void EToolBar::SetDockState(unsigned char state){
		unsigned int temp;
		if(state<=4){
			if(this->m_cDockState<=2){  //change the shape.
				if(state>=3){
					temp=this->m_zArea.m_uWidth;
					this->m_zArea.m_uWidth=this->m_zArea.m_uHeight;
					this->m_zArea.m_uHeight=temp;
				}
			}else{
				if((state==2)||(state==1)){  //change the shape.
					temp=this->m_zArea.m_uWidth;
					this->m_zArea.m_uWidth=this->m_zArea.m_uHeight;
					this->m_zArea.m_uHeight=temp;
				}			
			}
			this->m_cDockState=state;
		}
	}

	void EToolBar::UpdateToolBarHeight(){
		this->m_zArea.m_uHeight=0;
		for(unsigned int n=0;n<this->m_uItemCount;n++){
			if(this->m_zArea.m_uHeight<this->m_parrToolBarItem[n]->m_zArea.m_uHeight+1)
				this->m_zArea.m_uHeight=this->m_parrToolBarItem[n]->m_zArea.m_uHeight+1;
		}
	}

	void EStatusBar::SetLabelString(char* string){
		int n=0;
		while(n<=MaxStatusLabelLength){
			if(string[n]!='\0'){
				this->m_carrLabelString[n]=string[n];
			}else{
				this->m_carrLabelString[n]='\0';
				break;
			}		
			n++;
		}
		this->m_uStatusString1Position=(n<<3)+5;
	}

	void EStatusBar::SetStatusString(char* string,unsigned char index){
		int n=0;
		char* temp;
		if(index==1){
			temp=m_carrStatusString1;
		}else if(index==2){
			temp=m_carrStatusString2;
		}else{
			return;
		}
		while(n<=MaxStatusString){
			if(string[n]!='\0'){
				temp[n]=string[n];
			}else{
				temp[n]='\0';
				break;
			}		
			n++;
		}			
		if(index==1){
			this->m_uStatusString2Position=(n<<3)+5;
		}
	}

	char* EStatusBar::GetStatusString(unsigned char index){
		if(index==1){
			return (char*)(&(this->m_carrStatusString1[0]));
		}else if(index==2){
			return (char*)(&(this->m_carrStatusString2[0]));
		}else{
			return NULL;
		}
	}

	void EStatusBar::ClearLabelString(){
		for(unsigned int n=0;n<MaxStatusLabelLength;n++){
			m_carrLabelString[n]='\0';
		}
	}

	void EStatusBar::ClearStatusString(unsigned char index){
		if(index==1){
			for(unsigned int n=0;n<MaxStatusString;n++){
				m_carrStatusString1[n]='\0';
			}
		}
		if(index==2){
			for(unsigned int n=0;n<MaxStatusString;n++){
				m_carrStatusString2[n]='\0';
			}
		}
	}

	void EStatusBar::SetStatusPosition(unsigned char index,unsigned int position){
		if(index==1){
			this->m_uStatusString1Position=position;
		}
		if(index==2){
			this->m_uStatusString2Position=position;
		}
	}

	unsigned int EBarChart::CheckSelectItem(unsigned int x,unsigned int y){
		unsigned int barLeftX,barRightX,barTopY,barBottomY;
		if(this->m_uItemCount==0){
			return this->MaxBarItem;
		}
		if(this->m_uYAxisRange==0){
			barLeftX=14;
		}else{
			barLeftX=25;
		}
		barRightX=barLeftX+this->m_parrBarArray[0]->m_uBarWidth;
		barBottomY=this->m_zArea.m_uHeight-13;
		barTopY=barBottomY-this->m_parrBarArray[0]->m_uBarHeight;
		for(unsigned int n=0;n<this->m_uItemCount;n++){
			if((x>=barLeftX)&&(x<=barRightX)&&(y<=barBottomY)&&(y>=barTopY)){
				return n;
			}
			if((n+1)==this->m_uItemCount){
				return this->MaxBarItem;
			}
			barLeftX+=this->m_parrBarArray[n]->m_uBarWidth+this->m_uBlankWidth;
			barRightX+=this->m_parrBarArray[n+1]->m_uBarWidth+this->m_uBlankWidth;
			barTopY=barBottomY-this->m_parrBarArray[n+1]->m_uBarHeight;
		}
		return this->MaxBarItem;
	}

void EG_RedrawFunc_DefaultELabel(EControl* control){
	ELabel* currentControl=(ELabel*)control;
#ifdef EG_SINGLE_COLOR
	EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_pLableString);
#else
#ifdef EG_RICH_STYLE
	EG_Graphic_DrawFontString(currentControl->m_pControlPos,currentControl->m_pLableString,
		currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
#else
	EG_Graphic_DrawString(currentControl->m_pControlPos,
		currentControl->m_pLableString,currentControl->m_pStyle->m_cTextColor);
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
    currentControl->m_bNeedRedraw=false;
}

void EG_RedrawFunc_DefaultEButton(EControl* control){
	EButton* currentControl=(EButton*)control;    
#ifdef EG_SINGLE_COLOR
	//draw frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	//draw string
	EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+3,
		currentControl->m_pControlPos.m_uY+3,currentControl->m_pButtonString);
#else
#ifdef EG_RICH_STYLE
	EPosition pos;
	//draw 4 arc
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-3;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,4);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,1);
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,2);
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,3);
	//draw string
	pos.m_uY=currentControl->m_pControlPos.m_uY+2;
	EG_Graphic_DrawFontString(pos,currentControl->m_pButtonString,
		currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
	//draw frame
	pos.m_uY=currentControl->m_pControlPos.m_uY;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);
#else
	//draw frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,
		currentControl->m_zArea,currentControl->m_pStyle->m_cFrameColor);
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	//draw string
	EG_Graphic_DrawString(pos,currentControl->m_pButtonString,currentControl->m_pStyle->m_cTextColor);
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
    currentControl->m_bNeedRedraw=false;
}

void EG_CallbackFunc_DefaultECheckButton(EControl* control,EEvent* curevent){
	ECheckButton* currentControl=(ECheckButton*)control;   
	if ((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){//cursor left click
		//topple check state
		if(currentControl->m_bCheckButtonChecked){
			currentControl->m_bCheckButtonChecked=false;
		}else{
			currentControl->m_bCheckButtonChecked=true;
		}
	}
    currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultECheckButton(EControl* control){
	ECheckButton* currentControl=(ECheckButton*)control;   
	EPosition pos;
#ifdef EG_SINGLE_COLOR
	pos.m_uX=currentControl->m_pControlPos.m_uX+1;
	pos.m_uY=currentControl->m_pControlPos.m_uY+1;
	if (currentControl->m_bCheckButtonChecked){
		//non-selected check box
		EG_Graphic_DrawFilledRectangle(pos.m_uX,pos.m_uY,6,6);  
	}else{
		//selected check box
        EG_Graphic_DrawEmptyRectangle(pos.m_uX,pos.m_uY,6,6);
        EG_Graphic_DrawWhiteFilledRectangle(pos.m_uX+1,pos.m_uY+1,5,5);
	}
	pos.m_uX=currentControl->m_pControlPos.m_uX+9;
	EG_Graphic_DrawString(pos.m_uX,pos.m_uY,currentControl->m_pCheckButtonString);
#else
#ifdef EG_RICH_STYLE
	EPosition pos2;
	if(currentControl->m_zArea.m_uHeight<=10){
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		//non-selected check box
		EG_Graphic_DrawEmptyRectangle(pos,ESize(6,6),currentControl->m_pStyle->m_cContentColor);
		if (currentControl->m_bCheckButtonChecked){
			//draw select token
			pos.m_uX=currentControl->m_pControlPos.m_uX+2;
			pos.m_uY=currentControl->m_pControlPos.m_uY+4;
			pos2.m_uX=currentControl->m_pControlPos.m_uX+4;
			pos2.m_uY=currentControl->m_pControlPos.m_uY+8;
			EG_Graphic_DrawWidthLine(pos,pos2,currentControl->m_pStyle->m_cSelectColor,3);
			pos.m_uX=currentControl->m_pControlPos.m_uX+10;
			pos.m_uY=currentControl->m_pControlPos.m_uY+1;
			EG_Graphic_DrawWidthLine(pos2,pos,currentControl->m_pStyle->m_cSelectColor,3);
		}
		pos.m_uX=currentControl->m_pControlPos.m_uX+9;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
	}else{
		unsigned int bias=((currentControl->m_zArea.m_uHeight-8)>>1);
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+bias+4;
		//non-selected check box
		EG_Graphic_DrawEmptyRectangle(pos,ESize(8,8),currentControl->m_pStyle->m_cContentColor);
		if (currentControl->m_bCheckButtonChecked){
			//draw select token
			pos.m_uX=currentControl->m_pControlPos.m_uX;
			pos.m_uY=currentControl->m_pControlPos.m_uY+bias+7;
			pos2.m_uX=currentControl->m_pControlPos.m_uX+3;
			pos2.m_uY=currentControl->m_pControlPos.m_uY+bias+13;
			EG_Graphic_DrawWidthLine(pos,pos2,currentControl->m_pStyle->m_cSelectColor,4);
			pos.m_uX=currentControl->m_pControlPos.m_uX+11;
			pos.m_uY=currentControl->m_pControlPos.m_uY+bias+3;
			EG_Graphic_DrawWidthLine(pos2,pos,currentControl->m_pStyle->m_cSelectColor,4);
		}
		pos.m_uX=currentControl->m_pControlPos.m_uX+11;
		pos.m_uY=currentControl->m_pControlPos.m_uY+bias;
	}
	EG_Graphic_DrawFontString(pos,currentControl->m_pCheckButtonString,
		currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
#else
	pos.m_uX=currentControl->m_pControlPos.m_uX+1;
	pos.m_uY=currentControl->m_pControlPos.m_uY+1;
	if (currentControl->m_bCheckButtonChecked){
		//selected check box
		EG_Graphic_DrawFilledRectangle(pos,ESize(6,6),currentControl->m_pStyle->m_cContentColor);  
	}else{
		//non-selected check box
		EG_Graphic_DrawEmptyRectangle(pos,ESize(6,6),currentControl->m_pStyle->m_cContentColor);
        EG_Graphic_DrawFilledRectangle(EPosition(pos.m_uX+1,pos.m_uY+1),ESize(5,5),EColor(255,255,255));
	}
	pos.m_uX=currentControl->m_pControlPos.m_uX+9;
	EG_Graphic_DrawString(pos,currentControl->m_pCheckButtonString,currentControl->m_pStyle->m_cTextColor);
#endif  //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
    currentControl->m_bNeedRedraw=false;
}

void EG_CallbackFunc_DefaultEEdit(EControl* control,EEvent* curevent){
	EEdit* currentControl=(EEdit*)control;   
	if(curevent->m_uSource==2){   //keyboard event
		currentControl->AddCharToString((char)curevent->m_uMessage);
	}
	currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEEdit(EControl* control){
	EEdit* currentControl=(EEdit*)control;   
#ifdef EG_SINGLE_COLOR
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	if (currentControl->m_bPassword){
		const char str='#';   //password text  display '#' only
		for (int n=0;n<currentControl->m_ulength;n++){
			EG_Graphic_DrawChar(pos.m_uX,pos.m_uY,str);
			pos.m_uX+=8;
		}
	}else{
		EG_Graphic_DrawConstString(pos.m_uX,pos.m_uY,(char*)(currentControl->m_saString),currentControl->m_ulength);		
	}
#else
#ifdef EG_RICH_STYLE
	EPosition pos;
	//draw 4 arc
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-3;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,4);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,1);
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,2);
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,3);
	//draw frame
	pos.m_uY=currentControl->m_pControlPos.m_uY;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);	
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10)
		pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	else
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
	if (currentControl->m_bPassword){
		const char str='*';   //password text  display '*' only
		for (int n=0;n<currentControl->m_ulength;n++){
			EG_Graphic_DrawFontChar(pos,str,
				currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
			pos.m_uX+=8;
		}
	}else{
		EG_Graphic_DrawConstFontString(pos,(char*)(currentControl->m_saString),currentControl->m_ulength,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);		
	}
#else
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,
		currentControl->m_zArea,currentControl->m_pStyle->m_cFrameColor);
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	if (currentControl->m_bPassword){
		const char str='#';   //password text  display '#' only
		for (int n=0;n<currentControl->m_ulength;n++){
			EG_Graphic_DrawChar(pos,str,currentControl->m_pStyle->m_cTextColor);
			pos.m_uX+=8;
		}
	}else{
		EG_Graphic_DrawConstString(pos,(char*)(currentControl->m_saString),currentControl->m_ulength,currentControl->m_pStyle->m_cTextColor);		
	}
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
    currentControl->m_bNeedRedraw=false;
}

void EG_RedrawFunc_DefaultEProgress(EControl* control){
	EProgress* currentControl=(EProgress*)control;  
#ifdef EG_SINGLE_COLOR
	// draw the frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+2;
	pos.m_uY=currentControl->m_pControlPos.m_uY+2;
	unsigned int l=currentControl->GetProgress();
	if (l>currentControl->m_zArea.m_uWidth-3)   // the progress variable may over max range.
		l=currentControl->m_zArea.m_uWidth-3;
	EG_Graphic_DrawFilledRectangle(pos.m_uX,pos.m_uY,currentControl->m_zArea.m_uHeight-3,l);
#else
#ifdef EG_RICH_STYLE
	EPosition pos;
	//draw 4 arc
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-3;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,4);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,1);
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,2);
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,3);
	//draw frame
	pos.m_uY=currentControl->m_pControlPos.m_uY;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);	
	if(currentControl->m_bBarStyle){
		//configurate block 
		unsigned int l;
		if (currentControl->m_uProgress>currentControl->m_zArea.m_uWidth-3)   // the progress variable may over max range.
			l=currentControl->m_zArea.m_uWidth-4;
		else
			l=currentControl->m_uProgress;
		unsigned char blockNumber;
		unsigned char extraBlock;
		unsigned char blockLength=10;
		unsigned char totalBlock=(currentControl->m_zArea.m_uWidth-4)/10;
		if(totalBlock<=6){
			blockLength=6;
			totalBlock=(currentControl->m_zArea.m_uWidth-4)/6;
			blockNumber=l/6;
			extraBlock=l%6;
		}else{
			blockNumber=l/10;
			extraBlock=l%10;
		}
		ESize size;
		if(blockNumber==0){
			currentControl->m_bNeedRedraw=false;
			return;
		}
		//draw the first block
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+3;
		EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-5,currentControl->m_pStyle->m_cSelectColor);
		pos.m_uX+=1;
		pos.m_uY-=1;
		EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-3,currentControl->m_pStyle->m_cSelectColor);
		pos.m_uX+=1;
		size.m_uWidth=blockLength-2;
		size.m_uHeight=currentControl->m_zArea.m_uHeight-3;
		EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);
		if(blockNumber==1){
			currentControl->m_bNeedRedraw=false;
			return;
		}
		//draw middle block
		pos.m_uX=currentControl->m_pControlPos.m_uX+blockLength+4;
		pos.m_uY=currentControl->m_pControlPos.m_uY+2;
		size.m_uWidth=blockLength;
		unsigned char para1,para2,para3;
		if(blockLength==6){
			para1=3;
			para2=6;
		}else{
			para1=4;
			para2=6;
		}
		if(extraBlock<para1){
			if(blockNumber<3)
				para3=0;
			else
				para3=blockNumber-3;
			if(blockLength==6){
				extraBlock+=3;
			}else{
				extraBlock+=7;
			}
		}else{
			if(blockNumber<2)
				para3=0;
			else
				para3=blockNumber-2;
		}
		for(unsigned char n=0;n<para3;n++){
			EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);
			pos.m_uX+=blockLength+2;
		}
		//draw last block
		if(blockNumber>=totalBlock){
			if((extraBlock>=para1)&&(extraBlock<para2)){
				if(l<=currentControl->m_zArea.m_uWidth-5){
					currentControl->m_bNeedRedraw=false;
					return;
				}
				if(blockLength==6){
					extraBlock-=3;
				}else{
					extraBlock-=3;
				}
				pos.m_uX-=2;
				for(;extraBlock>1;extraBlock--){
					EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-3,
						currentControl->m_pStyle->m_cSelectColor);
					pos.m_uX+=1;
				}
				pos.m_uY+=1;
				EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-5,
					currentControl->m_pStyle->m_cSelectColor);
			}else if(extraBlock>=para2){
				if(blockLength==6){
					extraBlock-=3;
				}else{
					extraBlock-=1;
				}
				for(;extraBlock>1;extraBlock--){
					EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-3,
						currentControl->m_pStyle->m_cSelectColor);
					pos.m_uX+=1;
				}
				pos.m_uY+=1;
				EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-5,
					currentControl->m_pStyle->m_cSelectColor);
			}
		}
	}else{
		unsigned int l=currentControl->GetProgress();
		if (l>currentControl->m_zArea.m_uWidth-2)   // the progress variable may over max range.
			l=currentControl->m_zArea.m_uWidth-2;
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+2;
		EPosition pos2;
		pos2.m_uY=currentControl->m_pControlPos.m_uY+3;
		for(;l>1;l--){
			if(pos.m_uX==currentControl->m_pControlPos.m_uX+2){
				pos2.m_uX=currentControl->m_pControlPos.m_uX+2;
				EG_Graphic_DrawVerticalLine(pos2,currentControl->m_zArea.m_uHeight-5,currentControl->m_pStyle->m_cSelectColor);			
			}else if(pos.m_uX==currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-2){
				pos2.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-2;
				EG_Graphic_DrawVerticalLine(pos2,currentControl->m_zArea.m_uHeight-5,currentControl->m_pStyle->m_cSelectColor);			
			}else{
				EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-3,currentControl->m_pStyle->m_cSelectColor);
			}		
			pos.m_uX++;
		}
	}
	
#else
	// draw the frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,currentControl->m_pStyle->m_cContentColor);
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+2;
	pos.m_uY=currentControl->m_pControlPos.m_uY+2;
	unsigned int l=currentControl->GetProgress();
	if (l>currentControl->m_zArea.m_uWidth-3)   // the progress variable may over max range.
		l=currentControl->m_zArea.m_uWidth-3;
	EG_Graphic_DrawFilledRectangle(pos,ESize(l,currentControl->m_zArea.m_uHeight-3),currentControl->m_pStyle->m_cContentColor);
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
    currentControl->m_bNeedRedraw=false;
}

void EG_CallbackFunc_DefaultEExtLabel(EControl* control,EEvent* curevent){
	EExtLabel* currentControl=(EExtLabel*)control;  
#ifdef EG_RICH_STYLE
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){  //cursor left click
		currentControl->m_uUnderlineCount=0;
		currentControl->ChangeState();
	}else{
		//other event 
		currentControl->m_uUnderlineCount+=1;
	}
#else
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){  //cursor left click
		currentControl->ChangeState();
	}
#endif  //EG_RICH_STYLE
    currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEExtLabel(EControl* control){
	EExtLabel* currentControl=(EExtLabel*)control;  
#ifdef EG_SINGLE_COLOR
	if (currentControl->GetState()){
		EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			currentControl->m_pLableString);
	}else{
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			currentControl->m_pLableString);
	}
#else
#ifdef EG_RICH_STYLE
	if (currentControl->GetState()){
		EG_Graphic_DrawFontString(currentControl->m_pControlPos,currentControl->m_pLableString,
			currentControl->m_pStyle->m_cSelectColor,currentControl->m_pStyle->m_fFont);
	}else{
		EG_Graphic_DrawFontString(currentControl->m_pControlPos,currentControl->m_pLableString,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
	}
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-1;
	if(currentControl->m_uUnderlineCount>0){
		currentControl->m_uUnderlineCount--;
		EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth,currentControl->m_pStyle->m_cFrameColor);
	}
#else
	if (currentControl->GetState()){
		EG_Graphic_DrawString(currentControl->m_pControlPos,
			currentControl->m_pLableString,currentControl->m_pStyle->m_cSelectColor);
	}else{
		EG_Graphic_DrawString(currentControl->m_pControlPos,
			currentControl->m_pLableString,currentControl->m_pStyle->m_cTextColor);
	}
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;
}

void EG_CallbackFunc_DefaultEComboBox(EControl* control,EEvent* curevent){
	EComboBox* currentControl=(EComboBox*)control;  
	if(curevent->m_uSource!=1)// not cursor event
		return;
	EPosition pos=curevent->m_pPosition;  //cursor pos
	EPosition cpos=currentControl->m_pControlPos;   //combo pos
#ifdef EG_RICH_STYLE
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=8)
		delta=10;
	else
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
	if(curevent->m_uMessage!=1){  //not cursor left click event
		if ((currentControl->GetOpenState())&&(pos.m_uY-cpos.m_uY>delta)){
			currentControl->m_uHoverItem=((pos.m_uY-cpos.m_uY- delta-1)/delta)+1; 
			if(currentControl->m_uHoverItem>currentControl->m_uItem){
				currentControl->m_uHoverItem=currentControl->m_uItem;
			}
		}
	}else{
		unsigned int temp;
		if (currentControl->GetOpenState()){
			if (pos.m_uY-cpos.m_uY<=delta){  //cursor is at current select index
				currentControl->SetSelectIndex(currentControl->m_uSelectItem);
			}else{
				temp=(pos.m_uY-cpos.m_uY- delta-1)/delta;
				if(temp>=currentControl->m_uItem)
					temp=currentControl->m_uItem-1;
				currentControl->SetSelectIndex(temp);  //change select index
			}
			currentControl->SwitchOpenState();  //close the box
		}else{
			//open the combo box
			currentControl->SwitchOpenState();
		}
	}
#else
	if(curevent->m_uMessage==1){
		if (currentControl->GetOpenState()){
			if (pos.m_uY-cpos.m_uY<=10)  //cursor is at current select index
				currentControl->SetSelectIndex(currentControl->m_uSelectItem);
			else
				currentControl->SetSelectIndex((pos.m_uY-cpos.m_uY- 11)/10);  //change select index
			currentControl->SwitchOpenState();  //close the box
		}else{
			//open the combo box
			currentControl->SwitchOpenState();
		}
	}
#endif  //EG_RICH_STYLE
    currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEComboBox(EControl* control){
	EComboBox* currentControl=(EComboBox*)control;  
#ifdef EG_SINGLE_COLOR
	//Draw background
	EG_Graphic_DrawWhiteFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	EG_Graphic_DrawVerticalLine(currentControl->m_zArea.m_uWidth+currentControl->m_pControlPos.m_uX-9,
		currentControl->m_pControlPos.m_uY+1,9);
	EG_Graphic_DrawLine(currentControl->m_pControlPos.m_uX-6+currentControl->m_zArea.m_uWidth,currentControl->m_pControlPos.m_uY+4,
		currentControl->m_pControlPos.m_uX-4+currentControl->m_zArea.m_uWidth,currentControl->m_pControlPos.m_uY+8,0);
	EG_Graphic_DrawLine(currentControl->m_pControlPos.m_uX-2+currentControl->m_zArea.m_uWidth,currentControl->m_pControlPos.m_uY+4,
		currentControl->m_pControlPos.m_uX-4+currentControl->m_zArea.m_uWidth,currentControl->m_pControlPos.m_uY+8,0);
	EG_Graphic_DrawHorizonLine(currentControl->m_pControlPos.m_uX-6+currentControl->m_zArea.m_uWidth,
		currentControl->m_pControlPos.m_uY+4,4);
	if (currentControl->GetOpenState()){
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
		EG_Graphic_DrawHorizonLine(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY+10,
			currentControl->m_zArea.m_uWidth);
		for (unsigned int n=0;n<currentControl->GetItemNumber();n++){		
			EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+1,currentControl->m_pControlPos.m_uY+1+(n+1)*10,
				currentControl->GetItemString(n));
		}
	}else{
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			10,currentControl->m_zArea.m_uWidth);		
	}
	if (currentControl->GetItemNumber()>=1){
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+1,currentControl->m_pControlPos.m_uY+1,
			currentControl->GetItemString(currentControl->GetSelectIndex()));
	}
#else
#ifdef EG_RICH_STYLE
	//Draw background
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cBackgroundColor);
	//Draw Arrow Box
	EColor cwhite(255,255,255);
	EPosition pos,pos1;
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=8){
		delta=10;
		pos.m_uX=currentControl->m_zArea.m_uWidth+currentControl->m_pControlPos.m_uX-9;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		if (!currentControl->GetOpenState())
			EG_Graphic_DrawFilledRectangle(pos,ESize(9,9),currentControl->m_pStyle->m_cFrameColor);
		else
			EG_Graphic_DrawFilledRectangle(pos,ESize(9,9),currentControl->m_pStyle->m_cSelectColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX-6+currentControl->m_zArea.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+4;
		pos1.m_uX=currentControl->m_pControlPos.m_uX-4+currentControl->m_zArea.m_uWidth;
		pos1.m_uY=currentControl->m_pControlPos.m_uY+8;
		EG_Graphic_DrawLine(pos,pos1,cwhite,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX-2+currentControl->m_zArea.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+4;
		EG_Graphic_DrawLine(pos,pos1,cwhite,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX-6+currentControl->m_zArea.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+4;
		EG_Graphic_DrawHorizonLine(pos,4,cwhite);
	}else{
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
		pos.m_uX=currentControl->m_zArea.m_uWidth+currentControl->m_pControlPos.m_uX-12;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		if (!currentControl->GetOpenState())
			EG_Graphic_DrawFilledRectangle(pos,ESize(12,delta+1),currentControl->m_pStyle->m_cFrameColor);
		else
			EG_Graphic_DrawFilledRectangle(pos,ESize(12,delta+1),currentControl->m_pStyle->m_cSelectColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX-10+currentControl->m_zArea.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+(delta>>1);
		pos1.m_uX=currentControl->m_pControlPos.m_uX-6+currentControl->m_zArea.m_uWidth;
		pos1.m_uY=currentControl->m_pControlPos.m_uY+delta-1;
		EG_Graphic_DrawLine(pos,pos1,cwhite,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX-2+currentControl->m_zArea.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+(delta>>1);
		EG_Graphic_DrawLine(pos,pos1,cwhite,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX-10+currentControl->m_zArea.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+(delta>>1);
		EG_Graphic_DrawHorizonLine(pos,8,cwhite);
	}
	if (currentControl->GetOpenState()){
		//comboBox open
		//Draw Box Frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,
			currentControl->m_zArea,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX;
		if(delta<=10)
			pos.m_uY=currentControl->m_pControlPos.m_uY+delta;
		else
			pos.m_uY=currentControl->m_pControlPos.m_uY+delta+2;
		EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth,
			currentControl->m_pStyle->m_cFrameColor);
		for (unsigned int n=0;n<currentControl->GetItemNumber();n++){		
			//String List
			pos.m_uX=currentControl->m_pControlPos.m_uX+1;
			pos.m_uY=currentControl->m_pControlPos.m_uY+1+(n+1)*delta;
			if((n+1)!=currentControl->m_uHoverItem)
				EG_Graphic_DrawFontString(pos,currentControl->GetItemString(n),
					currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
			else
				EG_Graphic_DrawFontString(pos,currentControl->GetItemString(n),
					currentControl->m_pStyle->m_cSelectColor,currentControl->m_pStyle->m_fFont);
		}
	}else{
		//Draw Box Frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,
			ESize(currentControl->m_zArea.m_uWidth,EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]+2),currentControl->m_pStyle->m_cFrameColor);		
	}
	if (currentControl->GetItemNumber()>=1){
		//draw selected item
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		EG_Graphic_DrawFontString(pos,currentControl->GetItemString(currentControl->GetSelectIndex()),
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
	}

#else
	//Draw background
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cBackgroundColor);
	//Draw Arrow Box
	EColor cwhite(255,255,255);
	EPosition pos,pos1;
	pos.m_uX=currentControl->m_zArea.m_uWidth+currentControl->m_pControlPos.m_uX-9;
	pos.m_uY=currentControl->m_pControlPos.m_uY+1;
	EG_Graphic_DrawFilledRectangle(pos,ESize(9,9),currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX-6+currentControl->m_zArea.m_uWidth;
	pos.m_uY=currentControl->m_pControlPos.m_uY+4;
	pos1.m_uX=currentControl->m_pControlPos.m_uX-4+currentControl->m_zArea.m_uWidth;
	pos1.m_uY=currentControl->m_pControlPos.m_uY+8;
	EG_Graphic_DrawLine(pos,pos1,cwhite,false);
	pos.m_uX=currentControl->m_pControlPos.m_uX-2+currentControl->m_zArea.m_uWidth;
	pos.m_uY=currentControl->m_pControlPos.m_uY+4;
	EG_Graphic_DrawLine(pos,pos1,cwhite,false);
	pos.m_uX=currentControl->m_pControlPos.m_uX-6+currentControl->m_zArea.m_uWidth;
	pos.m_uY=currentControl->m_pControlPos.m_uY+4;
	EG_Graphic_DrawHorizonLine(pos,4,cwhite);
	if (currentControl->GetOpenState()){
		//comboBox open
		//Draw Box Frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,
			currentControl->m_zArea,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX;
		pos.m_uY=currentControl->m_pControlPos.m_uY+10;
		EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth,
			currentControl->m_pStyle->m_cFrameColor);
		for (unsigned int n=0;n<currentControl->GetItemNumber();n++){		
			//String List
			pos.m_uX=currentControl->m_pControlPos.m_uX+1;
			pos.m_uY=currentControl->m_pControlPos.m_uY+1+(n+1)*10;
			EG_Graphic_DrawString(pos,currentControl->GetItemString(n),currentControl->m_pStyle->m_cTextColor);
		}
	}else{
		//Draw Box Frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,ESize(currentControl->m_zArea.m_uWidth,10),
			currentControl->m_pStyle->m_cFrameColor);		
	}
	if (currentControl->GetItemNumber()>=1){
		//draw selected item
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		EG_Graphic_DrawString(pos,currentControl->GetItemString(currentControl->GetSelectIndex()),
			currentControl->m_pStyle->m_cTextColor);
	}
#endif //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
    currentControl->m_bNeedRedraw=false;
}

void EG_RedrawFunc_DefaultEIcon(EControl* control){
	EIcon* currentControl=(EIcon*)control;
#ifdef EG_SINGLE_COLOR
	EG_Graphic_DrawBitmap(currentControl->m_pControlPos.m_uX,
		currentControl->m_pControlPos.m_uY,currentControl->GetBitmap());
#else
	EG_Graphic_DrawBitmap(currentControl->m_pControlPos,currentControl->GetBitmap());
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;
}

void EG_RedrawFunc_DefaultEIconButton(EControl* control){
	EIconButton* currentControl=(EIconButton*)control;    
#ifdef EG_SINGLE_COLOR
	//draw frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	EG_Graphic_DrawBitmap(currentControl->m_pControlPos.m_uX+1,
		currentControl->m_pControlPos.m_uY+1,currentControl->GetBitmap());
	//draw string
	if(currentControl->m_bRightString){
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+3+currentControl->m_pbIcon.m_uWidth,
			currentControl->m_pControlPos.m_uY+6,currentControl->m_pIconButtonString);
	}else{
		//draw the string under the icon
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,
			currentControl->m_pControlPos.m_uY+3+(currentControl->m_pbIcon.m_uHeight<<3),currentControl->m_pIconButtonString);
	}
#else
#ifdef EG_RICH_STYLE
	EPosition pos;
	//draw 4 arc
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-3;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,4);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,1);
	pos.m_uX=currentControl->m_pControlPos.m_uX+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,2);
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawQuarterArc(pos,3,currentControl->m_pStyle->m_cFrameColor,3);
	//draw frame
	pos.m_uY=currentControl->m_pControlPos.m_uY;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+3;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth;
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-6,currentControl->m_pStyle->m_cFrameColor);	
	if(currentControl->m_bRightString){
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+
			((currentControl->m_zArea.m_uHeight-currentControl->m_pbIcon.m_uHeight)>>1)+1;
		EG_Graphic_DrawBitmap(pos,(&currentControl->m_pbIcon));
		pos.m_uX=currentControl->m_pControlPos.m_uX+3+currentControl->m_pbIcon.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+6;
		//draw string
		EG_Graphic_DrawFontString(pos,currentControl->m_pIconButtonString,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);	
	}else{
		pos.m_uX=currentControl->m_pControlPos.m_uX+
			((currentControl->m_zArea.m_uWidth-currentControl->m_pbIcon.m_uWidth)>>1)+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		EG_Graphic_DrawBitmap(pos,(&currentControl->m_pbIcon));
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+3+currentControl->m_pbIcon.m_uHeight;
		//draw string
		EG_Graphic_DrawFontString(pos,currentControl->m_pIconButtonString,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);	
	}
#else
	EPosition pos;
	if(currentControl->m_bRightString){
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,
			currentControl->m_zArea,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+
			((currentControl->m_zArea.m_uHeight-currentControl->m_pbIcon.m_uHeight)>>1)+1;
		EG_Graphic_DrawBitmap(pos,(&currentControl->m_pbIcon));
		pos.m_uX=currentControl->m_pControlPos.m_uX+3+currentControl->m_pbIcon.m_uWidth;
		pos.m_uY=currentControl->m_pControlPos.m_uY+6;
		//draw string
		EG_Graphic_DrawString(pos,currentControl->m_pIconButtonString,currentControl->m_pStyle->m_cTextColor);	
	}else{
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,
			currentControl->m_zArea,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX+
			((currentControl->m_zArea.m_uWidth-currentControl->m_pbIcon.m_uWidth)>>1)+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		EG_Graphic_DrawBitmap(pos,(&currentControl->m_pbIcon));
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+3+currentControl->m_pbIcon.m_uHeight;
		//draw string
		EG_Graphic_DrawString(pos,currentControl->m_pIconButtonString,currentControl->m_pStyle->m_cTextColor);	
	}
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
    currentControl->m_bNeedRedraw=false;
}

void EG_CallbackFunc_DefaultEMessageBox(EControl* control,EEvent* curevent){
	EMessageBox* currentControl=(EMessageBox*)control;  
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		if((currentControl->InCloseArea(curevent->m_pPosition))&&(currentControl->m_bOpen)){
			currentControl->m_bOpen=false;	
		}	
	}
    currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEMessageBox(EControl* control){
	EMessageBox* currentControl=(EMessageBox*)control;  
#ifdef EG_SINGLE_COLOR
	if(currentControl->m_bOpen){
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
		//draw title frame
		EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			10,currentControl->m_zArea.m_uWidth);
		//draw title 
		if(currentControl->m_uMessageBoxType==1)
			EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1,"Error\0");
		else if(currentControl->m_uMessageBoxType==2)
			EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1,"Warning\0");
		else if(currentControl->m_uMessageBoxType==3)
			EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1,"Info\0");
		//draw message
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+12,
			currentControl->m_pMessageString);
	}
#else
#ifdef EG_RICH_STYLE
	unsigned int temp;
	EPosition pos,pos2;
	EColor cwhite(255,255,255);
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10){
		temp=10;
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+1;
		pos2.m_uX=pos.m_uX;
		pos2.m_uY=currentControl->m_pControlPos.m_uY+temp+2;
	}else{
		temp=16;
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY;
		pos2.m_uX=pos.m_uX;
		pos2.m_uY=currentControl->m_pControlPos.m_uY+temp;
	}
	if(currentControl->m_bOpen){
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
			currentControl->m_pStyle->m_cFrameColor);
		//draw title frame
		EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,
			ESize(currentControl->m_zArea.m_uWidth,temp),currentControl->m_pStyle->m_cFrameColor);
		//draw title 
		if(currentControl->m_uMessageBoxType==1)
			EG_Graphic_DrawFontString(pos,"Error\0",cwhite,currentControl->m_pStyle->m_fFont);
		else if(currentControl->m_uMessageBoxType==2)
			EG_Graphic_DrawFontString(pos,"Warning\0",cwhite,currentControl->m_pStyle->m_fFont);
		else if(currentControl->m_uMessageBoxType==3)
			EG_Graphic_DrawFontString(pos,"Info\0",cwhite,currentControl->m_pStyle->m_fFont);
		//draw message
		EG_Graphic_DrawFontString(pos2,currentControl->m_pMessageString,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
		//draw close box
		if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10){
			pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-8;
			pos.m_uY=currentControl->m_pControlPos.m_uY+1;
			EG_Graphic_DrawEmptyRectangle(pos,ESize(7,7),cwhite);
			pos2.m_uX=pos.m_uX+7;
			pos2.m_uY=pos.m_uY+7;
			EG_Graphic_DrawLine(pos,pos2,cwhite,false);
			pos.m_uX+=7;
			pos2.m_uX-=7;
			EG_Graphic_DrawLine(pos,pos2,cwhite,false);
		}else{
			pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-12;
			pos.m_uY=currentControl->m_pControlPos.m_uY+2;
			EG_Graphic_DrawEmptyRectangle(pos,ESize(10,10),cwhite);
			pos2.m_uX=pos.m_uX+10;
			pos2.m_uY=pos.m_uY+10;
			EG_Graphic_DrawLine(pos,pos2,cwhite,false);
			pos.m_uX+=10;
			pos2.m_uX-=10;
			EG_Graphic_DrawLine(pos,pos2,cwhite,false);
		}
	}
#else
	EPosition pos(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1);
	EColor cwhite(255,255,255);
	if(currentControl->m_bOpen){
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
			currentControl->m_pStyle->m_cFrameColor);
		//draw title frame
		EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,ESize(currentControl->m_zArea.m_uWidth,10),
			currentControl->m_pStyle->m_cFrameColor);
		//draw title 
		if(currentControl->m_uMessageBoxType==1)
			EG_Graphic_DrawString(pos,const_cast<char*>("Error\0"),cwhite);
		else if(currentControl->m_uMessageBoxType==2)
			EG_Graphic_DrawString(pos,const_cast<char*>("Warning\0"),cwhite);
		else if(currentControl->m_uMessageBoxType==3)
			EG_Graphic_DrawString(pos,const_cast<char*>("Info\0"),cwhite);
		//draw message
		pos.m_uY=currentControl->m_pControlPos.m_uY+12;
		EG_Graphic_DrawString(pos,currentControl->m_pMessageString,currentControl->m_pStyle->m_cTextColor);
	}
#endif //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;
}

void EG_CallbackFunc_DefaultEDialogBox(EControl* control,EEvent* curevent){
	EDialogBox* currentControl=(EDialogBox*)control;  
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		//the dialog box is open
		if(currentControl->m_uDialogState==0){
			currentControl->UpdataState(curevent->m_pPosition);	
		}	
	}
	// still open
	if(currentControl->m_uDialogState==0)
		return;   //do not redraw here
    currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEDialogBox(EControl* control){
	EDialogBox* currentControl=(EDialogBox*)control;  
#ifdef EG_SINGLE_COLOR
	if(currentControl->m_uDialogState==0){
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
		//draw title frame
		EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			10,currentControl->m_zArea.m_uWidth);
		//draw title 
		if(currentControl->m_uDialogBoxType==1)
			EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1,"Error\0");
		else if(currentControl->m_uDialogBoxType==2)
			EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1,"Warning\0");
		else if(currentControl->m_uDialogBoxType==3)
			EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1,"Info\0");
		//draw message
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+12,currentControl->m_pMessageString);
		//draw button
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX+5,currentControl->m_pControlPos.m_uY+22,10,50);
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX+60,currentControl->m_pControlPos.m_uY+22,10,50);
		//draw string
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+22,currentControl->m_pControlPos.m_uY+24,"OK\0");
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+62,currentControl->m_pControlPos.m_uY+24,"Cancel\0");
	}
#else
#ifdef EG_RICH_STYLE
	unsigned char charHeight=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
	EPosition pos;
	EColor cwhite(255,255,255);
	ESize butsize;
	if(currentControl->m_uDialogState==0){
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
			currentControl->m_pStyle->m_cFrameColor);
		//draw title frame
		if(charHeight<=10){
			EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,ESize(currentControl->m_zArea.m_uWidth,10),
				currentControl->m_pStyle->m_cFrameColor);
			pos.m_uX=currentControl->m_pControlPos.m_uX+2;
			pos.m_uY=currentControl->m_pControlPos.m_uY+1;
			butsize.m_uWidth=50;
			butsize.m_uHeight=10;
		}else{
			EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,ESize(currentControl->m_zArea.m_uWidth,charHeight),
				currentControl->m_pStyle->m_cFrameColor);
			pos.m_uX=currentControl->m_pControlPos.m_uX+2;
			pos.m_uY=currentControl->m_pControlPos.m_uY;
			butsize.m_uWidth=50;
			butsize.m_uHeight=16;
		}
		//draw title 
		if(currentControl->m_uDialogBoxType==1)
			EG_Graphic_DrawFontString(pos,const_cast<char*>("Error\0"),cwhite,currentControl->m_pStyle->m_fFont);
		else if(currentControl->m_uDialogBoxType==2)
			EG_Graphic_DrawFontString(pos,const_cast<char*>("Warning\0"),cwhite,currentControl->m_pStyle->m_fFont);
		else if(currentControl->m_uDialogBoxType==3)
			EG_Graphic_DrawFontString(pos,const_cast<char*>("Info\0"),cwhite,currentControl->m_pStyle->m_fFont);
		//draw message
		if(charHeight<=10)
			pos.m_uY=currentControl->m_pControlPos.m_uY+12;
		else
			pos.m_uY=currentControl->m_pControlPos.m_uY+charHeight;
		EG_Graphic_DrawFontString(pos,currentControl->m_pMessageString,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
		//draw button
		pos.m_uX=currentControl->m_pControlPos.m_uX+5;
		if(charHeight<=10)
			pos.m_uY=currentControl->m_pControlPos.m_uY+22;
		else
			pos.m_uY=currentControl->m_pControlPos.m_uY+(charHeight<<1)+2;
		EG_Graphic_DrawEmptyRectangle(pos,butsize,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX+60;
		EG_Graphic_DrawEmptyRectangle(pos,butsize,currentControl->m_pStyle->m_cFrameColor);
		//draw string
		pos.m_uX=currentControl->m_pControlPos.m_uX+22;
		if(charHeight<=10)
			pos.m_uY+=2;
		EG_Graphic_DrawFontString(pos,const_cast<char*>("OK\0"),
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
		pos.m_uX=currentControl->m_pControlPos.m_uX+62;
		EG_Graphic_DrawFontString(pos,const_cast<char*>("Cancel\0"),
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
	}
#else
	EPosition pos(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+1);
	EColor cwhite(255,255,255);
	ESize butsize(50,10);
	if(currentControl->m_uDialogState==0){
		//draw frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
			currentControl->m_pStyle->m_cFrameColor);
		//draw title frame
		EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,ESize(currentControl->m_zArea.m_uWidth,10),
			currentControl->m_pStyle->m_cFrameColor);
		//draw title 
		if(currentControl->m_uDialogBoxType==1)
			EG_Graphic_DrawString(pos,const_cast<char*>("Error\0"),cwhite);
		else if(currentControl->m_uDialogBoxType==2)
			EG_Graphic_DrawString(pos,const_cast<char*>("Warning\0"),cwhite);
		else if(currentControl->m_uDialogBoxType==3)
			EG_Graphic_DrawString(pos,const_cast<char*>("Info\0"),cwhite);
		//draw message
		pos.m_uY=currentControl->m_pControlPos.m_uY+12;
		EG_Graphic_DrawString(pos,currentControl->m_pMessageString,currentControl->m_pStyle->m_cTextColor);
		//draw button
		pos.m_uX=currentControl->m_pControlPos.m_uX+5;
		pos.m_uY=currentControl->m_pControlPos.m_uY+22;
		EG_Graphic_DrawEmptyRectangle(pos,butsize,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX+60;
		EG_Graphic_DrawEmptyRectangle(pos,butsize,currentControl->m_pStyle->m_cFrameColor);
		//draw string
		pos.m_uX=currentControl->m_pControlPos.m_uX+22;
		pos.m_uY=currentControl->m_pControlPos.m_uY+24;
		EG_Graphic_DrawString(pos,const_cast<char*>("OK\0"),currentControl->m_pStyle->m_cTextColor);
		pos.m_uX=currentControl->m_pControlPos.m_uX+62;
		EG_Graphic_DrawString(pos,const_cast<char*>("Cancel\0"),currentControl->m_pStyle->m_cTextColor);
	}
#endif //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;
}

void EG_CallbackFunc_DefaultEScroll(EControl* control,EEvent* curevent){
	EScroll* currentControl=(EScroll*)control;  
	unsigned int relheight;
	// do nothing, if it is not the cursor left click event.
	if((curevent->m_uSource!=1)||(curevent->m_uMessage!=1))
		return;   
	relheight=curevent->m_pPosition.m_uY-currentControl->m_pControlPos.m_uY;
#ifdef EG_RICH_STYLE
	unsigned int deltaheight;
	if(currentControl->m_bWideScroll)
		deltaheight=12;
	else
		deltaheight=8;
	//within the up arrow
	if(relheight<=deltaheight){
		if(currentControl->m_uCurPosition<currentControl->m_uStepValue)
			currentControl->m_uCurPosition=deltaheight;
		else
			currentControl->SetCurrentPosition(currentControl->m_uCurPosition-currentControl->m_uStepValue);	
	}else if(relheight>=currentControl->m_zArea.m_uHeight-deltaheight){//in the down arrow
		currentControl->SetCurrentPosition(currentControl->m_uCurPosition+currentControl->m_uStepValue);	
	}else{
		currentControl->m_uCurPosition=relheight;
	}
	if(currentControl->m_uCurPosition>currentControl->m_zArea.m_uHeight-(deltaheight<<1))
		currentControl->m_uCurPosition=currentControl->m_zArea.m_uHeight-(deltaheight<<1);
#else
	//within the up arrow
	if(relheight<=8){
		if(currentControl->m_uCurPosition<currentControl->m_uStepValue)
			currentControl->m_uCurPosition=8;
		else
			currentControl->m_uCurPosition-=currentControl->m_uStepValue;	
	}else if(relheight>=currentControl->m_zArea.m_uHeight-8){//in the down arrow
		currentControl->m_uCurPosition+=currentControl->m_uStepValue;	
	}else{
		currentControl->m_uCurPosition=relheight;
	}
	if(currentControl->m_uCurPosition>currentControl->m_zArea.m_uHeight-16)
		currentControl->m_uCurPosition=currentControl->m_zArea.m_uHeight-16;
#endif  //EG_RICH_STYLE
    currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEScroll(EControl* control){
	EScroll* currentControl=(EScroll*)control;  
#ifdef EG_SINGLE_COLOR
	//draw scroll frame
	EG_Graphic_DrawWhiteFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);  //erase the old position
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	//draw up & down arrow frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,8,8);
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,
		currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-8,8,8);
	//draw up arrow
	EG_Graphic_DrawLine(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+6,
		currentControl->m_pControlPos.m_uX+4,currentControl->m_pControlPos.m_uY+2,0);
	EG_Graphic_DrawLine(currentControl->m_pControlPos.m_uX+6,currentControl->m_pControlPos.m_uY+6,
		currentControl->m_pControlPos.m_uX+4,currentControl->m_pControlPos.m_uY+2,0);
	EG_Graphic_DrawHorizonLine(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+6,4);
	//draw down arrow
	EG_Graphic_DrawLine(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6,
		currentControl->m_pControlPos.m_uX+4,currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-2,0);
	EG_Graphic_DrawLine(currentControl->m_pControlPos.m_uX+6,currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6,
		currentControl->m_pControlPos.m_uX+4,currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-2,0);
	EG_Graphic_DrawHorizonLine(currentControl->m_pControlPos.m_uX+2,currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6,4);
	//draw pos
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY+currentControl->m_uCurPosition,8,8);
#else
#ifdef EG_RICH_STYLE
	EColor whitec(255,255,255);
	ESize box;
	unsigned int delta;
	if(currentControl->m_bWideScroll){
		box.m_uHeight=12;
		box.m_uWidth=12;
		delta=12;
	}else{
		box.m_uHeight=8;
		box.m_uWidth=8;
		delta=8;
	}
	EPosition pos,pos1;
	//draw scroll frame
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,currentControl->m_zArea,whitec);  //erase the old position
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cFrameColor);
	//draw up & down arrow frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,box,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-delta;
	EG_Graphic_DrawEmptyRectangle(pos,box,currentControl->m_pStyle->m_cFrameColor);
	if(currentControl->m_bWideScroll){
		//draw up arrow
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+9;
		pos1.m_uX=currentControl->m_pControlPos.m_uX+6;
		pos1.m_uY=currentControl->m_pControlPos.m_uY+2;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+10;
		pos.m_uY=currentControl->m_pControlPos.m_uY+9;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+9;
		EG_Graphic_DrawHorizonLine(pos,8,currentControl->m_pStyle->m_cFrameColor);
		//draw down arrow
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-9;
		pos1.m_uX=currentControl->m_pControlPos.m_uX+6;
		pos1.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-2;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+10;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-9;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-9;
		EG_Graphic_DrawHorizonLine(pos,8,currentControl->m_pStyle->m_cFrameColor);
	}else{
		//draw up arrow
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+6;
		pos1.m_uX=currentControl->m_pControlPos.m_uX+4;
		pos1.m_uY=currentControl->m_pControlPos.m_uY+2;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+6;
		pos.m_uY=currentControl->m_pControlPos.m_uY+6;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+6;
		EG_Graphic_DrawHorizonLine(pos,4,currentControl->m_pStyle->m_cFrameColor);
		//draw down arrow
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6;
		pos1.m_uX=currentControl->m_pControlPos.m_uX+4;
		pos1.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-2;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+6;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6;
		EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6;
		EG_Graphic_DrawHorizonLine(pos,4,currentControl->m_pStyle->m_cFrameColor);
	}
	//draw pos
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_uCurPosition;
	EG_Graphic_DrawFilledRectangle(pos,box,currentControl->m_pStyle->m_cContentColor);
#else
	EColor whitec(255,255,255);
	ESize box(8,8);
	EPosition pos,pos1;
	//draw scroll frame
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,currentControl->m_zArea,whitec);  //erase the old position
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cFrameColor);
	//draw up & down arrow frame
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,box,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-8;
	EG_Graphic_DrawEmptyRectangle(pos,box,currentControl->m_pStyle->m_cFrameColor);
	//draw up arrow
	pos.m_uX=currentControl->m_pControlPos.m_uX+2;
	pos.m_uY=currentControl->m_pControlPos.m_uY+6;
	pos1.m_uX=currentControl->m_pControlPos.m_uX+4;
	pos1.m_uY=currentControl->m_pControlPos.m_uY+2;
	EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
	pos.m_uX=currentControl->m_pControlPos.m_uX+6;
	pos.m_uY=currentControl->m_pControlPos.m_uY+6;
	EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
	pos.m_uX=currentControl->m_pControlPos.m_uX+2;
	pos.m_uY=currentControl->m_pControlPos.m_uY+6;
	EG_Graphic_DrawHorizonLine(pos,4,currentControl->m_pStyle->m_cFrameColor);
	//draw down arrow
	pos.m_uX=currentControl->m_pControlPos.m_uX+2;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6;
	pos1.m_uX=currentControl->m_pControlPos.m_uX+4;
	pos1.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-2;
	EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
	pos.m_uX=currentControl->m_pControlPos.m_uX+6;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6;
	EG_Graphic_DrawLine(pos,pos1,currentControl->m_pStyle->m_cFrameColor,false);
	pos.m_uX=currentControl->m_pControlPos.m_uX+2;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-6;
	EG_Graphic_DrawHorizonLine(pos,4,currentControl->m_pStyle->m_cFrameColor);
	//draw pos
	pos.m_uX=currentControl->m_pControlPos.m_uX;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_uCurPosition;
	EG_Graphic_DrawFilledRectangle(pos,box,currentControl->m_pStyle->m_cContentColor);
#endif  //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_CallbackFunc_DefaultEList(EControl* control,EEvent* curevent){
	EList* currentControl=(EList*)control;  
	unsigned int n;
	if((curevent->m_uSource!=1)||(curevent->m_uMessage!=1))
		return;
	n=curevent->m_pPosition.m_uY-currentControl->m_pControlPos.m_uY;
#ifdef EG_RICH_STYLE
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10){
		delta=9;
	}else{
		delta=16;
	}
	if(n<(delta+1)){
		return;
	}else{
		n-=delta+1;
		n=n/delta;
	}
#else
	if(n<=10)	//cursor at the base item,omit
		return;
	else{
		n-=10;
		n=n/9;
	}
#endif  //EG_RICH_STYLE
	//invoke the callback function
	if(currentControl->m_parrItem[n]->m_pcbListHandler!=NULL)
		currentControl->m_parrItem[n]->m_pcbListHandler(currentControl,curevent);
	// already selected, no need to redraw
	if(n==currentControl->m_uItemSelect)	
		return;
	if(n==currentControl->m_uItemCount-1)
		return;
	currentControl->m_uItemSelect=n;
    currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEList(EControl* control){
	EList* currentControl=(EList*)control;  
#ifdef EG_SINGLE_COLOR
	unsigned int nx,ny;
	if(currentControl->m_uItemCount>=1){
		//erase old select frame
		EG_Graphic_DrawWhiteFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
		//draw frame 
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
		//draw base item frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
			10,currentControl->m_zArea.m_uWidth);
		//draw all the items
		nx=currentControl->m_pControlPos.m_uX+2;
		for(unsigned int col=0;col<currentControl->m_uColumnCount;col++){
			ny=currentControl->m_pControlPos.m_uY+2;
			for(unsigned int row=0;row<currentControl->m_uItemCount;row++){
				EG_Graphic_DrawString(nx,ny,(char*)(&currentControl->m_parrItem[row]->m_saString[col][0]));
				ny+=9;		
			}
			nx+=currentControl->m_uarrColumnWidth[col];
		}
		//draw select frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,
			currentControl->m_pControlPos.m_uY+10+currentControl->m_uItemSelect*9,8,currentControl->m_zArea.m_uWidth);
	}	
#else
	if(currentControl->m_uItemCount>=1){
		EPosition pos;
		ESize area;
		//erase old select frame
		EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
			currentControl->m_pStyle->m_cBackgroundColor);
		//draw frame 
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
			currentControl->m_pStyle->m_cFrameColor);
#ifdef EG_RICH_STYLE
		unsigned int delta;
		if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10){
			delta=9;
		}else{
			delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
		}
		//draw base item frame
		area.m_uHeight=delta+1;
		area.m_uWidth=currentControl->m_zArea.m_uWidth;
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,area,currentControl->m_pStyle->m_cFrameColor);
		//draw select frame
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+delta+2+currentControl->m_uItemSelect*delta;
		area.m_uHeight=delta-1;
		area.m_uWidth=currentControl->m_zArea.m_uWidth-1;
		EG_Graphic_DrawFilledRectangle(pos,area,currentControl->m_pStyle->m_cSelectColor);
		//draw all the items
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		for(unsigned int col=0;col<currentControl->m_uColumnCount;col++){
			if(delta<=9)
				pos.m_uY=currentControl->m_pControlPos.m_uY+2;
			else
				pos.m_uY=currentControl->m_pControlPos.m_uY;
			for(unsigned int row=0;row<currentControl->m_uItemCount;row++){
				EG_Graphic_DrawFontString(pos,(char*)(&currentControl->m_parrItem[row]->m_saString[col][0]),
					currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
				pos.m_uY+=delta;		
			}
			pos.m_uX+=currentControl->m_uarrColumnWidth[col];
		}
	}
#else
		//draw base item frame
		area.m_uHeight=10;
		area.m_uWidth=currentControl->m_zArea.m_uWidth;
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,area,currentControl->m_pStyle->m_cFrameColor);
		//draw select frame
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		pos.m_uY=currentControl->m_pControlPos.m_uY+11+currentControl->m_uItemSelect*9;
		area.m_uHeight=8;
		area.m_uWidth=currentControl->m_zArea.m_uWidth-1;
		EG_Graphic_DrawFilledRectangle(pos,area,currentControl->m_pStyle->m_cSelectColor);
		//draw all the items
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		for(unsigned int col=0;col<currentControl->m_uColumnCount;col++){
			pos.m_uY=currentControl->m_pControlPos.m_uY+2;
			for(unsigned int row=0;row<currentControl->m_uItemCount;row++){
				EG_Graphic_DrawString(pos,(char*)(&currentControl->m_parrItem[row]->m_saString[col][0]),
					currentControl->m_pStyle->m_cTextColor);
				pos.m_uY+=9;		
			}
			pos.m_uX+=currentControl->m_uarrColumnWidth[col];
		}
	}
#endif  //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_CallbackFunc_DefaultEMenu(EControl* control,EEvent* curevent){
	EMenu* currentControl=(EMenu*)control;  
#ifdef EG_RICH_STYLE
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10)
		delta=10;
	else
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
#else
	unsigned int delta=10;
#endif  //EG_RICH_STYLE
	unsigned int n;
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		unsigned int relHeight=curevent->m_pPosition.m_uY-currentControl->m_pControlPos.m_uY;
		if(currentControl->m_bUpperExtend==false){
			if(relHeight<=delta){  //cursor at the base menu
				if(curevent->m_pPosition.m_uX-currentControl->m_pControlPos.m_uX<=currentControl->m_uBaseMenuWidth){
					currentControl->SwitchShowState();			
				}		
			}else{
				n=(relHeight-delta)/delta;
				if(n>=currentControl->m_uItemNumber)
					n=currentControl->m_uItemNumber-1;
				currentControl->SetSelectItem(n);
				if(currentControl->m_parrMenuItemArray[n]->m_fpCallbackFunc!=NULL){
					(*currentControl->m_parrMenuItemArray[n]->m_fpCallbackFunc)(control,curevent);
				}
				if(currentControl->m_parrMenuItemArray[currentControl->m_uItemSelect]->m_uState&EMenu::MenuSelect){
					currentControl->m_parrMenuItemArray[currentControl->m_uItemSelect]->m_uState&=!(EMenu::MenuSelect);
				}else{
					currentControl->m_parrMenuItemArray[currentControl->m_uItemSelect]->m_uState|=	EMenu::MenuSelect;	
				}
			}
			currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
			currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
		}else{
			if(relHeight>=(currentControl->m_zArea.m_uHeight-delta)){//cursor at the base menu
				if(curevent->m_pPosition.m_uX-currentControl->m_pControlPos.m_uX<=currentControl->m_uBaseMenuWidth){
					currentControl->SwitchShowState();			
				}		
			}else{
				n=(relHeight)/delta;
				if(n<currentControl->m_uItemNumber){
					currentControl->SetSelectItem(n);
					if(currentControl->m_parrMenuItemArray[n]->m_fpCallbackFunc!=NULL){
						(*currentControl->m_parrMenuItemArray[n]->m_fpCallbackFunc)(control,curevent);
					}
					if(currentControl->m_parrMenuItemArray[currentControl->m_uItemSelect]->m_uState&EMenu::MenuSelect){
						currentControl->m_parrMenuItemArray[currentControl->m_uItemSelect]->m_uState&=!(EMenu::MenuSelect);
					}else{
						currentControl->m_parrMenuItemArray[currentControl->m_uItemSelect]->m_uState|=	EMenu::MenuSelect;	
					}
				}
			}
			currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
			currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
		}
	}
}

void EG_RedrawFunc_DefaultEMenu(EControl* control){
	EMenu* currentControl=(EMenu*)control;  
#ifdef EG_SINGLE_COLOR
	unsigned int ny;
	if(currentControl->m_bUpperExtend==false){
		//draw base frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,
			currentControl->m_pControlPos.m_uY,10,currentControl->m_uBaseMenuWidth);
		//draw base string
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,
			currentControl->m_pControlPos.m_uY+2,currentControl->m_pMenuString);
		if(currentControl->m_bDisplay){
			//draw menu frame
			EG_Graphic_DrawWhiteFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY+10,
				currentControl->m_zArea.m_uHeight-9,currentControl->m_zArea.m_uWidth);
			EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY+10,
				currentControl->m_zArea.m_uHeight-9,currentControl->m_zArea.m_uWidth);
			//draw menu item
			ny=currentControl->m_pControlPos.m_uY+11;
			for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
				if(currentControl->m_parrMenuItemArray[n]->m_uState&EMenu::MenuSelect){
					EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos.m_uX+1,ny,10,currentControl->m_zArea.m_uWidth-1);	
					EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,ny,currentControl->m_parrMenuItemArray[n]->m_pcLabel);	
				}else{
					EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,ny,currentControl->m_parrMenuItemArray[n]->m_pcLabel);	
				}
				ny+=10;
			}
		}
	}else{
		//draw base frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,
			currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-10
			,10,currentControl->m_uBaseMenuWidth);
		//draw base string
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,
			currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-8,
			currentControl->m_pMenuString);
		if(currentControl->m_bDisplay){
			//draw menu frame
			EG_Graphic_DrawWhiteFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
				currentControl->m_zArea.m_uHeight-9,currentControl->m_zArea.m_uWidth);
			EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
				currentControl->m_zArea.m_uHeight-9,currentControl->m_zArea.m_uWidth);
			//draw menu item
			ny=currentControl->m_pControlPos.m_uY+1;
			for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
				if(currentControl->m_parrMenuItemArray[n]->m_uState&EMenu::MenuSelect){
					EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos.m_uX+1,ny,10,currentControl->m_zArea.m_uWidth-1);	
					EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,ny,currentControl->m_parrMenuItemArray[n]->m_pcLabel);	
				}else{
					EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,ny,currentControl->m_parrMenuItemArray[n]->m_pcLabel);	
				}
				ny+=10;
			}
		}	
	}
#else
#ifdef EG_RICH_STYLE
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10)
		delta=10;
	else
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
	EPosition pos;
	ESize size;
	size.m_uHeight=delta;
	size.m_uWidth=currentControl->m_uBaseMenuWidth;
	if(currentControl->m_bUpperExtend==false){
		//draw base frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,size,
			currentControl->m_pStyle->m_cFrameColor);
		//draw base string
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		if(delta<=10)
			pos.m_uY=currentControl->m_pControlPos.m_uY+2;
		else
			pos.m_uY=currentControl->m_pControlPos.m_uY;
		EG_Graphic_DrawFontString(pos,currentControl->m_pMenuString,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
		if(currentControl->m_bDisplay){
			//draw menu frame
			pos.m_uX=currentControl->m_pControlPos.m_uX;
			pos.m_uY=currentControl->m_pControlPos.m_uY+delta;
			size.m_uWidth=currentControl->m_zArea.m_uWidth;
			size.m_uHeight=currentControl->m_zArea.m_uHeight-delta+1;
			EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cBackgroundColor);
			EG_Graphic_DrawEmptyRectangle(pos,size,currentControl->m_pStyle->m_cFrameColor);
			//draw menu item
			pos.m_uY=currentControl->m_pControlPos.m_uY+delta+1;
			size.m_uWidth=currentControl->m_zArea.m_uWidth-1;
			size.m_uHeight=delta;
			for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
				pos.m_uX=currentControl->m_pControlPos.m_uX+1;
				if(currentControl->m_parrMenuItemArray[n]->m_uState&EMenu::MenuSelect){
					EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);	
				}
				if(currentControl->m_parrMenuItemArray[n]->m_piIcon!=NULL){
					EG_Graphic_DrawBitmap(pos,currentControl->m_parrMenuItemArray[n]->m_piIcon);
					pos.m_uX+=currentControl->m_parrMenuItemArray[n]->m_piIcon->m_uWidth+1;
				}
				EG_Graphic_DrawFontString(pos,currentControl->m_parrMenuItemArray[n]->m_pcLabel,
					currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);		
				pos.m_uY+=delta;
			}
		}
	}else{
		pos.m_uX=currentControl->m_pControlPos.m_uX;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-delta;
		size.m_uHeight=delta;
		size.m_uWidth=currentControl->m_uBaseMenuWidth;
		//draw base frame
		EG_Graphic_DrawEmptyRectangle(pos,size,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX+=2;
		if(delta<=10)
			pos.m_uY+=2;
		//draw base string
		EG_Graphic_DrawFontString(pos,currentControl->m_pMenuString,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
		if(currentControl->m_bDisplay){
			size.m_uHeight=currentControl->m_zArea.m_uHeight-delta+1;
			size.m_uWidth=currentControl->m_zArea.m_uWidth;
			//draw menu frame
			EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,size,EColor(255,255,255));
			EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,size,
				currentControl->m_pStyle->m_cFrameColor);
			//draw menu item
			pos.m_uY=currentControl->m_pControlPos.m_uY+1;
			size.m_uWidth=currentControl->m_zArea.m_uWidth-1;
			size.m_uHeight=delta;
			for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
				pos.m_uX=currentControl->m_pControlPos.m_uX+1;
				if(currentControl->m_parrMenuItemArray[n]->m_uState&EMenu::MenuSelect){
					EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);	
				}
				if(currentControl->m_parrMenuItemArray[n]->m_piIcon!=NULL){
					EG_Graphic_DrawBitmap(pos,currentControl->m_parrMenuItemArray[n]->m_piIcon);
					pos.m_uX+=currentControl->m_parrMenuItemArray[n]->m_piIcon->m_uWidth+1;
				}
				if(delta>10)
					pos.m_uY-=1;
				EG_Graphic_DrawFontString(pos,currentControl->m_parrMenuItemArray[n]->m_pcLabel,
					currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);			
				if(delta<=10)
					pos.m_uY+=delta;
				else
					pos.m_uY+=delta+1;
			}
		}
	}
#else
	EPosition pos;
	ESize size;
	size.m_uHeight=10;
	size.m_uWidth=currentControl->m_uBaseMenuWidth;
	if(currentControl->m_bUpperExtend==false){
		//draw base frame
		EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,size,
			currentControl->m_pStyle->m_cFrameColor);
		//draw base string
		pos.m_uX=currentControl->m_pControlPos.m_uX+2;
		pos.m_uY=currentControl->m_pControlPos.m_uY+2;
		EG_Graphic_DrawString(pos,currentControl->m_pMenuString,currentControl->m_pStyle->m_cTextColor);
		if(currentControl->m_bDisplay){
			//draw menu frame
			pos.m_uX=currentControl->m_pControlPos.m_uX;
			pos.m_uY=currentControl->m_pControlPos.m_uY+10;
			size.m_uWidth=currentControl->m_zArea.m_uWidth;
			size.m_uHeight=currentControl->m_zArea.m_uHeight-9;
			EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cBackgroundColor);
			EG_Graphic_DrawEmptyRectangle(pos,size,currentControl->m_pStyle->m_cFrameColor);
			//draw menu item
			pos.m_uX=currentControl->m_pControlPos.m_uX+1;
			pos.m_uY=currentControl->m_pControlPos.m_uY+11;
			size.m_uWidth=currentControl->m_zArea.m_uWidth-1;
			size.m_uHeight=10;
			for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
				if(currentControl->m_parrMenuItemArray[n]->m_uState&EMenu::MenuSelect){
					EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);	
				}
				EG_Graphic_DrawString(pos,currentControl->m_parrMenuItemArray[n]->m_pcLabel,
					currentControl->m_pStyle->m_cTextColor);			
				pos.m_uY+=10;
			}
		}
	}else{
		pos.m_uX=currentControl->m_pControlPos.m_uX;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-10;
		size.m_uHeight=10;
		size.m_uWidth=currentControl->m_uBaseMenuWidth;
		//draw base frame
		EG_Graphic_DrawEmptyRectangle(pos,size,currentControl->m_pStyle->m_cFrameColor);
		pos.m_uX+=2;
		pos.m_uY+=2;
		//draw base string
		EG_Graphic_DrawString(pos,currentControl->m_pMenuString,currentControl->m_pStyle->m_cTextColor);
		if(currentControl->m_bDisplay){
			size.m_uHeight=currentControl->m_zArea.m_uHeight-9;
			size.m_uWidth=currentControl->m_zArea.m_uWidth;
			//draw menu frame
			EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,size,EColor(255,255,255));
			EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,size,
				currentControl->m_pStyle->m_cFrameColor);
			//draw menu item
			pos.m_uX=currentControl->m_pControlPos.m_uX+1;
			pos.m_uY=currentControl->m_pControlPos.m_uY+1;
			size.m_uWidth=currentControl->m_zArea.m_uWidth-1;
			size.m_uHeight=10;
			for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
				if(currentControl->m_parrMenuItemArray[n]->m_uState&EMenu::MenuSelect){
					EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);	
				}
				EG_Graphic_DrawString(pos,currentControl->m_parrMenuItemArray[n]->m_pcLabel,
					currentControl->m_pStyle->m_cTextColor);			
				pos.m_uY+=10;
			}
		}
	}
#endif  //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_CallbackFunc_DefaultEPopupMenu(EControl* control,EEvent* curevent){
	EPopupMenu* currentControl=(EPopupMenu*)control;  
	unsigned int n;
#ifdef EG_RICH_STYLE
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10)
		delta=10;
	else
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
#else
	unsigned int delta=10;
#endif  //EG_RICH_STYLE
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		unsigned int relHeight=curevent->m_pPosition.m_uY-currentControl->m_pControlPos.m_uY;		
		n=relHeight/delta;
		if(n>=currentControl->m_uItemNumber)
			n=currentControl->m_uItemNumber-1;
		currentControl->SetSelectItem(n);
		if(currentControl->m_parrPopupMenuItemArray[n]->m_fpCallbackFunc!=NULL){
			(*currentControl->m_parrPopupMenuItemArray[n]->m_fpCallbackFunc)(control,curevent);
		}
		if(currentControl->m_parrPopupMenuItemArray[currentControl->m_uItemSelect]->m_uState&EMenu::MenuSelect){
			currentControl->m_parrPopupMenuItemArray[currentControl->m_uItemSelect]->m_uState&=!(EMenu::MenuSelect);
		}else{
			currentControl->m_parrPopupMenuItemArray[currentControl->m_uItemSelect]->m_uState|=	EMenu::MenuSelect;	
		}		
		currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
		currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
	}
}

void EG_RedrawFunc_DefaultEPopupMenu(EControl* control){
	EPopupMenu* currentControl=(EPopupMenu*)control;  
#ifdef EG_SINGLE_COLOR
	if(!currentControl->m_bDisplay)
		return;
	unsigned int width=currentControl->m_zArea.m_uWidth;
	unsigned int height=currentControl->m_zArea.m_uHeight+1;
	//draw base frame
	EG_Graphic_DrawWhiteFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,height,width);
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,height,width);
	//draw menu item
	unsigned int ny=currentControl->m_pControlPos.m_uY+1;
	for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
		if(currentControl->m_parrPopupMenuItemArray[n]->m_uState&EMenu::MenuSelect){
			EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos.m_uX+1,ny,10,currentControl->m_zArea.m_uWidth-1);	
			EG_Graphic_DrawNotString(currentControl->m_pControlPos.m_uX+2,ny,currentControl->m_parrPopupMenuItemArray[n]->m_pcLabel);			
		}else{
			EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+2,ny,currentControl->m_parrPopupMenuItemArray[n]->m_pcLabel);			
		}
		ny+=10;
	}
#else
#ifdef EG_RICH_STYLE
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10)
		delta=10;
	else
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
	if(!currentControl->m_bDisplay)
		return;
	EPosition pos;
	ESize size;
	size.m_uWidth=currentControl->m_zArea.m_uWidth;
	size.m_uHeight=currentControl->m_zArea.m_uHeight+1;
	//draw base frame
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,size,
		currentControl->m_pStyle->m_cBackgroundColor);
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,size,
		currentControl->m_pStyle->m_cFrameColor);
	//draw menu item
	pos.m_uY=currentControl->m_pControlPos.m_uY+1;
	size.m_uWidth=currentControl->m_zArea.m_uWidth-1;
	size.m_uHeight=delta;
	for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
		pos.m_uX=currentControl->m_pControlPos.m_uX+1;
		if(currentControl->m_parrPopupMenuItemArray[n]->m_uState&EMenu::MenuSelect){
			EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);	
		}
		if(currentControl->m_parrPopupMenuItemArray[n]->m_piIcon!=NULL){
			EG_Graphic_DrawBitmap(pos,currentControl->m_parrPopupMenuItemArray[n]->m_piIcon);
			pos.m_uX+=currentControl->m_parrPopupMenuItemArray[n]->m_piIcon->m_uWidth+1;
		}
		EG_Graphic_DrawFontString(pos,currentControl->m_parrPopupMenuItemArray[n]->m_pcLabel,
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);			
		pos.m_uY+=delta;
	}
#else
	if(!currentControl->m_bDisplay)
		return;
	EPosition pos;
	ESize size;
	size.m_uWidth=currentControl->m_zArea.m_uWidth;
	size.m_uHeight=currentControl->m_zArea.m_uHeight+1;
	//draw base frame
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,size,
		currentControl->m_pStyle->m_cBackgroundColor);
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,size,
		currentControl->m_pStyle->m_cFrameColor);
	//draw menu item
	pos.m_uX=currentControl->m_pControlPos.m_uX+1;
	pos.m_uY=currentControl->m_pControlPos.m_uY+1;
	size.m_uWidth=currentControl->m_zArea.m_uWidth-1;
	size.m_uHeight=10;
	for (unsigned int n=0;n<currentControl->m_uItemNumber;n++){
		if(currentControl->m_parrPopupMenuItemArray[n]->m_uState&EMenu::MenuSelect){
			EG_Graphic_DrawFilledRectangle(pos,size,currentControl->m_pStyle->m_cSelectColor);	
		}
		EG_Graphic_DrawString(pos,currentControl->m_parrPopupMenuItemArray[n]->m_pcLabel,
			currentControl->m_pStyle->m_cTextColor);			
		pos.m_uY+=10;
	}
#endif  //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_CallbackFunc_DefaultETree(EControl* control,EEvent* curevent){
	ETree* currentControl=(ETree*)control;
	ETree::ETreeSubItem* temp=NULL;
	unsigned int relheight=0;
#ifdef EG_RICH_STYLE
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10){
		delta=10;
	}else{
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
	}
#endif  //EG_RICH_STYLE
	//left click on the tree
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		relheight=curevent->m_pPosition.m_uY-currentControl->m_pControlPos.m_uY;
#ifdef EG_RICH_STYLE
		relheight=relheight/delta;
#else
		relheight=relheight/10;
#endif  //EG_RICH_STYLE
		//close the leaf
		temp=currentControl->m_tiTreeStruct.GetOpenSubItem(relheight);
		if(temp!=NULL){
			if(temp->m_pTreeItem!=NULL){
				if(temp->m_pTreeItem->m_uSubItemCount>0){
					if(temp->m_pTreeItem->m_pTreeSubItem[0]->m_bOpen){
						temp->CloseSubItem();				
					}else{
						temp->OpenSubItem();
					}
				}				
			}
		}
		currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
		currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
	}
}

void EG_RedrawFunc_DefaultETree(EControl* control){
	ETree* currentControl=(ETree*)control;  
	ETree::ETreeSubItem* temp=NULL;
#ifdef EG_SINGLE_COLOR
	EPosition pos;
	unsigned int templine;
	unsigned int lastDepth=0;
	//draw frame
	EG_Graphic_DrawWhiteFilledRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	for(unsigned int n=0;n<currentControl->GetOpenLeafCount();n++){
		temp=currentControl->GetOpenLeaf(n);
		if(temp->m_pTreeItem!=NULL){
			//draw the extend icon
			pos.m_uX=currentControl->m_pControlPos.m_uX+4+temp->m_pFather->m_uDepth*10;
			pos.m_uY=currentControl->m_pControlPos.m_uY+4+n*10;
			if(temp->m_pTreeItem->m_uSubItemCount>0)
				currentControl->DrawExtendIcon(pos,temp->m_pTreeItem->m_pTreeSubItem[0]->m_bOpen);
			else
				currentControl->DrawExtendIcon(pos,true);
			//draw relation line
			templine=temp->m_pFather->m_uDepth*10;
			if(templine!=0){
				EG_Graphic_DrawHorizonLine(currentControl->m_pControlPos.m_uX-2+temp->m_pFather->m_uDepth*10,
					currentControl->m_pControlPos.m_uY+7+n*10,templine-5);
			}
		}else{
			//draw relation line
			if(temp->m_pFather->m_uDepth!=0){
				EG_Graphic_DrawHorizonLine(currentControl->m_pControlPos.m_uX-2+temp->m_pFather->m_uDepth*10,
					currentControl->m_pControlPos.m_uY+7+n*10,14);
			}
		}
		//draw vertical relation line
		if(temp->m_pFather->m_uDepth>lastDepth){
			EG_Graphic_DrawVerticalLine(currentControl->m_pControlPos.m_uX+temp->m_pFather->m_uDepth*10-3,
				currentControl->m_pControlPos.m_uY+n*10+2,6);
			lastDepth=temp->m_pFather->m_uDepth;
		}else if(temp->m_pFather->m_uDepth==lastDepth){
			if(lastDepth!=0){
				EG_Graphic_DrawVerticalLine(currentControl->m_pControlPos.m_uX+lastDepth*10-3,
					currentControl->m_pControlPos.m_uY+n*10-2,10);
			}
		}else{
			lastDepth=temp->m_pFather->m_uDepth;
		}
		//draw string
		EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+13+temp->m_pFather->m_uDepth*10,
			currentControl->m_pControlPos.m_uY+4+n*10,(char*)(&temp->m_saString[0]));
	}
	
#else
#ifdef EG_RICH_STYLE
	EPosition pos;
	unsigned int templine;
	unsigned int lastDepth=0;
//	unsigned int lastPos=0;
	unsigned int delta;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10){
		delta=10;
	}else{
		delta=EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber];
	}
	//draw frame
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cBackgroundColor);
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cFrameColor);
	for(unsigned int n=0;n<currentControl->GetOpenLeafCount();n++){
		temp=currentControl->GetOpenLeaf(n);
		if(temp->m_pTreeItem!=NULL){
			//draw the extend icon
			pos.m_uX=currentControl->m_pControlPos.m_uX+4+temp->m_pFather->m_uDepth*10;
			pos.m_uY=currentControl->m_pControlPos.m_uY+n*delta+(delta>>1);
			if(delta>10)
				pos.m_uY-=2;
			if(temp->m_pTreeItem->m_uSubItemCount>0)
				currentControl->DrawExtendIcon(pos,temp->m_pTreeItem->m_pTreeSubItem[0]->m_bOpen);
			else
				currentControl->DrawExtendIcon(pos,true);
			//draw relation line
			templine=temp->m_pFather->m_uDepth*10;
			if(templine!=0){
				pos.m_uX=currentControl->m_pControlPos.m_uX-2+temp->m_pFather->m_uDepth*10;
				pos.m_uY=currentControl->m_pControlPos.m_uY+1+n*delta+(delta>>1);
				EG_Graphic_DrawHorizonLine(pos,templine-5,currentControl->m_pStyle->m_cContentColor);
			}
		}else{
			//draw relation line
			if(temp->m_pFather->m_uDepth!=0){
				pos.m_uX=currentControl->m_pControlPos.m_uX-2+temp->m_pFather->m_uDepth*10;
				pos.m_uY=currentControl->m_pControlPos.m_uY+1+n*delta+(delta>>1);
				EG_Graphic_DrawHorizonLine(pos,14,currentControl->m_pStyle->m_cContentColor);
			}
		}
		//draw vertical relation line
		if(temp->m_pFather->m_uDepth>lastDepth){
			pos.m_uX=currentControl->m_pControlPos.m_uX+temp->m_pFather->m_uDepth*10-3;
			if(delta<=10){
				pos.m_uY=currentControl->m_pControlPos.m_uY+n*delta+2;
				EG_Graphic_DrawVerticalLine(pos,6,currentControl->m_pStyle->m_cContentColor);
		}else{
				pos.m_uY=currentControl->m_pControlPos.m_uY+n*delta;
				EG_Graphic_DrawVerticalLine(pos,10,currentControl->m_pStyle->m_cContentColor);
			}
			lastDepth=temp->m_pFather->m_uDepth;
		}else if(temp->m_pFather->m_uDepth==lastDepth){
			if(lastDepth!=0){
				pos.m_uX=currentControl->m_pControlPos.m_uX+lastDepth*10-3;
				if(delta<=10){
					pos.m_uY=currentControl->m_pControlPos.m_uY+n*delta-2;
					EG_Graphic_DrawVerticalLine(pos,10,currentControl->m_pStyle->m_cContentColor);
			}else{
					pos.m_uY=currentControl->m_pControlPos.m_uY+n*delta-5;
					EG_Graphic_DrawVerticalLine(pos,13,currentControl->m_pStyle->m_cContentColor);
				}
			}
		}else{
			lastDepth=temp->m_pFather->m_uDepth;
		}
		//draw string
		pos.m_uX=currentControl->m_pControlPos.m_uX+13+temp->m_pFather->m_uDepth*10;
		if(delta<=10)
			pos.m_uY=currentControl->m_pControlPos.m_uY+4+n*delta;
		else
			pos.m_uY=currentControl->m_pControlPos.m_uY+n*delta;
		EG_Graphic_DrawFontString(pos,(char*)(&temp->m_saString[0]),
			currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
	}
#else
	EPosition pos;
	unsigned int templine;
	unsigned int lastDepth=0;
	//draw frame
	EG_Graphic_DrawFilledRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cBackgroundColor);
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cFrameColor);
	for(unsigned int n=0;n<currentControl->GetOpenLeafCount();n++){
		temp=currentControl->GetOpenLeaf(n);
		if(temp->m_pTreeItem!=NULL){
			//draw the extend icon
			pos.m_uX=currentControl->m_pControlPos.m_uX+4+temp->m_pFather->m_uDepth*10;
			pos.m_uY=currentControl->m_pControlPos.m_uY+4+n*10;
			if(temp->m_pTreeItem->m_uSubItemCount>0)
				currentControl->DrawExtendIcon(pos,temp->m_pTreeItem->m_pTreeSubItem[0]->m_bOpen);
			else
				currentControl->DrawExtendIcon(pos,true);
			//draw relation line
			templine=temp->m_pFather->m_uDepth*10;
			if(templine!=0){
				pos.m_uX=currentControl->m_pControlPos.m_uX-2+temp->m_pFather->m_uDepth*10;
				pos.m_uY=currentControl->m_pControlPos.m_uY+7+n*10;
				EG_Graphic_DrawHorizonLine(pos,templine-5,currentControl->m_pStyle->m_cContentColor);
			}
		}else{
			//draw relation line
			if(temp->m_pFather->m_uDepth!=0){
				pos.m_uX=currentControl->m_pControlPos.m_uX-2+temp->m_pFather->m_uDepth*10;
				pos.m_uY=currentControl->m_pControlPos.m_uY+7+n*10;
				EG_Graphic_DrawHorizonLine(pos,14,currentControl->m_pStyle->m_cContentColor);
			}
		}
		//draw vertical relation line
		if(temp->m_pFather->m_uDepth>lastDepth){
			pos.m_uX=currentControl->m_pControlPos.m_uX+temp->m_pFather->m_uDepth*10-3;
			pos.m_uY=currentControl->m_pControlPos.m_uY+n*10+2;
			EG_Graphic_DrawVerticalLine(pos,6,currentControl->m_pStyle->m_cContentColor);
			lastDepth=temp->m_pFather->m_uDepth;
		}else if(temp->m_pFather->m_uDepth==lastDepth){
			if(lastDepth!=0){
				pos.m_uX=currentControl->m_pControlPos.m_uX+lastDepth*10-3;
				pos.m_uY=currentControl->m_pControlPos.m_uY+n*10-2;
				EG_Graphic_DrawVerticalLine(pos,10,currentControl->m_pStyle->m_cContentColor);
			}
		}else{
			lastDepth=temp->m_pFather->m_uDepth;
		}
		//draw string
		pos.m_uX=currentControl->m_pControlPos.m_uX+13+temp->m_pFather->m_uDepth*10;
		pos.m_uY=currentControl->m_pControlPos.m_uY+4+n*10;
		EG_Graphic_DrawString(pos,(char*)(&temp->m_saString[0]),currentControl->m_pStyle->m_cTextColor);
	}
#endif  //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_CallbackFunc_DefaultEToolBar(EControl* control,EEvent* curevent){
	EToolBar* currentControl=(EToolBar*)control;
	for(unsigned int n=0;n<currentControl->m_uItemCount;n++){
		if(currentControl->m_parrToolBarItem[n]->InControlArea(curevent->m_pPosition)){
			if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
				currentControl->m_parrToolBarItem[n]->NoticeControl(curevent);
			}
		}
	}
	currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
	currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
}

void EG_RedrawFunc_DefaultEToolBar(EControl* control){
	EToolBar* currentControl=(EToolBar*)control; 
	if(!currentControl->m_bPositionAdjust){
		currentControl->AdjustControlPosition();
	}
#ifdef EG_SINGLE_COLOR
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	for(unsigned int n=0;n<currentControl->m_uItemCount;n++){
		currentControl->m_parrToolBarItem[n]->RedrawControl();
	}
#else
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cFrameColor);
	for(unsigned int n=0;n<currentControl->m_uItemCount;n++){
		currentControl->m_parrToolBarItem[n]->RedrawControl();
	}
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_RedrawFunc_DefaultEStatusBar(EControl* control){
	EStatusBar* currentControl=(EStatusBar*)control; 
#ifdef EG_SINGLE_COLOR
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos.m_uX,currentControl->m_pControlPos.m_uY,
		currentControl->m_zArea.m_uHeight,currentControl->m_zArea.m_uWidth);
	EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+1,currentControl->m_pControlPos.m_uY+2,
		currentControl->m_carrLabelString);
	EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+1+currentControl->m_uStatusString1Position,
		currentControl->m_pControlPos.m_uY+2,currentControl->m_carrStatusString1);
	EG_Graphic_DrawString(currentControl->m_pControlPos.m_uX+1+currentControl->m_uStatusString1Position
		+currentControl->m_uStatusString2Position,currentControl->m_pControlPos.m_uY+2,currentControl->m_carrStatusString2);
#else
#ifdef EG_RICH_STYLE
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+1;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10)
		pos.m_uY=currentControl->m_pControlPos.m_uY+2;
	else
		pos.m_uY=currentControl->m_pControlPos.m_uY;
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cFrameColor);
	EG_Graphic_DrawFontString(pos,currentControl->m_carrLabelString,
		currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
	pos.m_uX=pos.m_uX+currentControl->m_uStatusString1Position;
	EG_Graphic_DrawFontString(pos,currentControl->m_carrStatusString1,
		currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
	pos.m_uX=pos.m_uX+currentControl->m_uStatusString2Position;
	EG_Graphic_DrawFontString(pos,currentControl->m_carrStatusString2,
		currentControl->m_pStyle->m_cTextColor,currentControl->m_pStyle->m_fFont);
#else
	EPosition pos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+1;
	pos.m_uY=currentControl->m_pControlPos.m_uY+2;
	EG_Graphic_DrawEmptyRectangle(currentControl->m_pControlPos,currentControl->m_zArea,
		currentControl->m_pStyle->m_cFrameColor);
	EG_Graphic_DrawString(pos,currentControl->m_carrLabelString,
		currentControl->m_pStyle->m_cTextColor);
	pos.m_uX=pos.m_uX+currentControl->m_uStatusString1Position;
	EG_Graphic_DrawString(pos,currentControl->m_carrStatusString1,
		currentControl->m_pStyle->m_cTextColor);
	pos.m_uX=pos.m_uX+currentControl->m_uStatusString2Position;
	EG_Graphic_DrawString(pos,currentControl->m_carrStatusString2,
		currentControl->m_pStyle->m_cTextColor);
#endif  //EG_RICH_STYLE
#endif //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_CallbackFunc_DefaultEBarChart(EControl* control,EEvent* curevent){
	EBarChart* currentControl=(EBarChart*)control;
	unsigned int x,y;
	unsigned int sel;
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		x=curevent->m_pPosition.m_uX-currentControl->m_pControlPos.m_uX;
		y=curevent->m_pPosition.m_uY-currentControl->m_pControlPos.m_uY;
		sel=currentControl->CheckSelectItem(x,y);
		if(sel!=currentControl->MaxBarItem){
			//cursor in the bar area
			currentControl->m_uSelectedItem=sel;			
		}
		currentControl->m_bNeedRedraw=true;
#ifdef EG_REDRAW_IN_CALLBACK_FUNC
		currentControl->RedrawControl();
#endif //EG_REDRAW_IN_CALLBACK_FUNC
	}
}

void EG_RedrawFunc_DefaultEBarChart(EControl* control){
	EBarChart* currentControl=(EBarChart*)control; 
#ifdef EG_SINGLE_COLOR
	unsigned int x,y,tempx,tempy;
	x=currentControl->m_pControlPos.m_uX+4;
	y=currentControl->m_pControlPos.m_uY+12;
	//draw the y axis first
	EG_Graphic_DrawVerticalLine(x,y,currentControl->m_zArea.m_uHeight-25);
	tempx=x-3;
	tempy=y+3;
	EG_Graphic_DrawLine(x,y,tempx,tempy,0);
	tempx=x+3;
	EG_Graphic_DrawLine(x,y,tempx,tempy,0);
	if(currentControl->m_uYAxisRange!=0){
		//draw the y axis range
		//full scale        
		x=currentControl->m_pControlPos.m_uX+9;
		y=currentControl->m_pControlPos.m_uY+15;
		EG_Graphic_DrawNumber(x,y,currentControl->m_uYAxisRange);
		tempx=currentControl->m_pControlPos.m_uX+1;
		tempy=currentControl->m_pControlPos.m_uY+19;
		EG_Graphic_DrawHorizonLine(tempx,tempy,7);
		//half scale
		x=currentControl->m_pControlPos.m_uX+9;
		y=currentControl->m_pControlPos.m_uY+12+((currentControl->m_zArea.m_uHeight-25)>>1);
		EG_Graphic_DrawNumber(x,y,currentControl->m_uYAxisRange>>1);
		tempx=currentControl->m_pControlPos.m_uX+1;
		tempy=currentControl->m_pControlPos.m_uY+16+((currentControl->m_zArea.m_uHeight-25)>>1);
		EG_Graphic_DrawHorizonLine(tempx,tempy,7);
	}
	//draw the x axis then
	x=currentControl->m_pControlPos.m_uX+4;
	y=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-14;
	EG_Graphic_DrawHorizonLine(x,y,currentControl->m_zArea.m_uWidth-10);
	x=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-7;
	y=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-14;
	tempx=x-3;
	tempy=y-3;
	EG_Graphic_DrawLine(x,y,tempx,tempy,0);
	tempy=y+3;
	EG_Graphic_DrawLine(x,y,tempx,tempy,0);
	if(currentControl->m_uXAxisRange!=0){
		//draw the x axis range
		//full scale        
		x=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-28;
		y=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-11;
		EG_Graphic_DrawNumber(x,y,currentControl->m_uXAxisRange);
		tempx=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-20;
		tempy=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-17;
		EG_Graphic_DrawVerticalLine(tempx,tempy,7);
		//half scale
		x=currentControl->m_pControlPos.m_uX+(currentControl->m_zArea.m_uWidth>>1)-20;
		y=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-11;
		EG_Graphic_DrawNumber(x,y,currentControl->m_uXAxisRange>>1);
		tempx=currentControl->m_pControlPos.m_uX+(currentControl->m_zArea.m_uWidth>>1)-11;
		tempy=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-17;
		EG_Graphic_DrawVerticalLine(tempx,tempy,7);
		//zero
		x=currentControl->m_pControlPos.m_uX+4;
		y=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-11;
		EG_Graphic_DrawChar(x,y,'0');
	}
	if(currentControl->m_uYAxisRange==0){
		x=currentControl->m_pControlPos.m_uX+14;
	}else{
		x=currentControl->m_pControlPos.m_uX+25;
	}
	//draw the bars
	for(unsigned int n=0;n<currentControl->m_uItemCount;n++){
		y=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-14
			-currentControl->m_parrBarArray[n]->m_uBarHeight;
		if(currentControl->m_bUpperWord){
			tempx=x-5;
			tempy=y-9;
		}else{
			tempx=x-5;
			tempy=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-9;
		}
		if(n!=currentControl->m_uSelectedItem){
			EG_Graphic_DrawEmptyRectangle(x,y,currentControl->m_parrBarArray[n]->m_uBarHeight,
				currentControl->m_parrBarArray[n]->m_uBarWidth);
		}else{
			EG_Graphic_DrawFilledRectangle(x,y,currentControl->m_parrBarArray[n]->m_uBarHeight,
				currentControl->m_parrBarArray[n]->m_uBarWidth);
		}
		EG_Graphic_DrawString(tempx,tempy,currentControl->m_parrBarArray[n]->m_pItemText);
		x+=currentControl->m_parrBarArray[n]->m_uBarWidth+currentControl->m_uBlankWidth;
	}
#else
	EPosition pos,temppos;
	pos.m_uX=currentControl->m_pControlPos.m_uX+4;
	pos.m_uY=currentControl->m_pControlPos.m_uY+12;
	//draw the y axis first
	EG_Graphic_DrawVerticalLine(pos,currentControl->m_zArea.m_uHeight-25,
		currentControl->m_pStyle->m_cFrameColor);
	temppos.m_uX=pos.m_uX-3;
	temppos.m_uY=pos.m_uY+3;
	EG_Graphic_DrawLine(pos,temppos,currentControl->m_pStyle->m_cFrameColor,false);
	temppos.m_uX=pos.m_uX+3;
	EG_Graphic_DrawLine(pos,temppos,currentControl->m_pStyle->m_cFrameColor,false);
	if(currentControl->m_uYAxisRange!=0){
		//draw the y axis range
		//full scale        
		pos.m_uX=currentControl->m_pControlPos.m_uX+9;
		pos.m_uY=currentControl->m_pControlPos.m_uY+15;
		EG_Graphic_DrawNumber(pos,currentControl->m_uYAxisRange,currentControl->m_pStyle->m_cContentColor);
		temppos.m_uX=currentControl->m_pControlPos.m_uX+1;
		temppos.m_uY=currentControl->m_pControlPos.m_uY+19;
		EG_Graphic_DrawHorizonLine(temppos,7,currentControl->m_pStyle->m_cFrameColor);
		//half scale
		pos.m_uX=currentControl->m_pControlPos.m_uX+9;
		pos.m_uY=currentControl->m_pControlPos.m_uY+12+((currentControl->m_zArea.m_uHeight-25)>>1);
		EG_Graphic_DrawNumber(pos,currentControl->m_uYAxisRange>>1,currentControl->m_pStyle->m_cContentColor);
		temppos.m_uX=currentControl->m_pControlPos.m_uX+1;
		temppos.m_uY=currentControl->m_pControlPos.m_uY+16+((currentControl->m_zArea.m_uHeight-25)>>1);
		EG_Graphic_DrawHorizonLine(temppos,7,currentControl->m_pStyle->m_cFrameColor);
	}
	//draw the x axis then
	pos.m_uX=currentControl->m_pControlPos.m_uX+4;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-14;
	EG_Graphic_DrawHorizonLine(pos,currentControl->m_zArea.m_uWidth-10,currentControl->m_pStyle->m_cFrameColor);
	pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-7;
	pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-14;
	temppos.m_uX=pos.m_uX-3;
	temppos.m_uY=pos.m_uY-3;
	EG_Graphic_DrawLine(pos,temppos,currentControl->m_pStyle->m_cFrameColor,false);
	temppos.m_uY=pos.m_uY+3;
	EG_Graphic_DrawLine(pos,temppos,currentControl->m_pStyle->m_cFrameColor,false);
	if(currentControl->m_uXAxisRange!=0){
		//draw the x axis range
		//full scale        
		pos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-28;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-11;
		EG_Graphic_DrawNumber(pos,currentControl->m_uXAxisRange,currentControl->m_pStyle->m_cContentColor);
		temppos.m_uX=currentControl->m_pControlPos.m_uX+currentControl->m_zArea.m_uWidth-20;
		temppos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-17;
		EG_Graphic_DrawVerticalLine(temppos,7,currentControl->m_pStyle->m_cFrameColor);
		//half scale
		pos.m_uX=currentControl->m_pControlPos.m_uX+(currentControl->m_zArea.m_uWidth>>1)-20;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-11;
		EG_Graphic_DrawNumber(pos,currentControl->m_uXAxisRange>>1,currentControl->m_pStyle->m_cContentColor);
		temppos.m_uX=currentControl->m_pControlPos.m_uX+(currentControl->m_zArea.m_uWidth>>1)-11;
		temppos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-17;
		EG_Graphic_DrawVerticalLine(temppos,7,currentControl->m_pStyle->m_cFrameColor);
		//zero
		pos.m_uX=currentControl->m_pControlPos.m_uX+4;
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-11;
		EG_Graphic_DrawChar(pos,'0',currentControl->m_pStyle->m_cContentColor);
	}
	if(currentControl->m_uYAxisRange==0){
		pos.m_uX=currentControl->m_pControlPos.m_uX+14;
	}else{
		pos.m_uX=currentControl->m_pControlPos.m_uX+25;
	}
	//draw the bars
	for(unsigned int n=0;n<currentControl->m_uItemCount;n++){
		pos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-14
			-currentControl->m_parrBarArray[n]->m_uBarHeight;
		if(currentControl->m_bUpperWord){
			temppos.m_uX=pos.m_uX-5;
			temppos.m_uY=pos.m_uY-9;
		}else{
			temppos.m_uX=pos.m_uX-5;
			temppos.m_uY=currentControl->m_pControlPos.m_uY+currentControl->m_zArea.m_uHeight-9;
		}
		if(n!=currentControl->m_uSelectedItem){
			EG_Graphic_DrawFilledRectangle(pos,ESize(currentControl->m_parrBarArray[n]->m_uBarWidth,
				currentControl->m_parrBarArray[n]->m_uBarHeight),currentControl->m_parrBarArray[n]->m_cBarColor);
			EG_Graphic_DrawString(temppos,currentControl->m_parrBarArray[n]->m_pItemText,
				currentControl->m_pStyle->m_cTextColor);
		}else{
			EG_Graphic_DrawFilledRectangle(pos,ESize(currentControl->m_parrBarArray[n]->m_uBarWidth,
				currentControl->m_parrBarArray[n]->m_uBarHeight),currentControl->m_pStyle->m_cSelectColor);
			EG_Graphic_DrawString(temppos,currentControl->m_parrBarArray[n]->m_pItemText,
				currentControl->m_pStyle->m_cSelectColor);
		}
		pos.m_uX=pos.m_uX+currentControl->m_parrBarArray[n]->m_uBarWidth+currentControl->m_uBlankWidth;
	}
#endif  //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}

void EG_RedrawFunc_DefaultEClock(EControl* control){
	EClock* currentControl=(EClock*)control; 
#ifdef EG_SINGLE_COLOR
	unsigned int x,y;
	x=currentControl->m_pControlPos.m_uX+1;
	y=currentControl->m_pControlPos.m_uY+1;
	EG_Graphic_DrawNumber(x,y,(int)currentControl->m_ucHour);
	x+=16;
	EG_Graphic_DrawChar(x,y,':');
	x+=8;
	if(currentControl->m_ucMinute<=10){
		EG_Graphic_DrawChar(x,y,'0');
		x+=8;
	}
	EG_Graphic_DrawNumber(x,y,(int)currentControl->m_ucMinute);
	if(currentControl->m_bShowSecond){
		if(currentControl->m_ucMinute<=10)
			x+=8;
		else
			x+=16;
		EG_Graphic_DrawChar(x,y,':');
		x+=8;
		if(currentControl->m_ucSecond<=10){
			EG_Graphic_DrawChar(x,y,'0');
			x+=8;
		}
		EG_Graphic_DrawNumber(x,y,(int)currentControl->m_ucSecond);
	}
#else
#ifdef EG_RICH_STYLE
	EPosition pos=currentControl->m_pControlPos;
	pos.m_uX+=1;
	if(EG_FontHeight[currentControl->m_pStyle->m_fFont.m_cFontNumber]<=10)
		pos.m_uY+=1;
	EG_Graphic_DrawFontNumber(pos,(int)currentControl->m_ucHour,
		currentControl->m_pStyle->m_cContentColor,currentControl->m_pStyle->m_fFont);
	pos.m_uX+=16;
	EG_Graphic_DrawFontChar(pos,':',currentControl->m_pStyle->m_cContentColor,currentControl->m_pStyle->m_fFont);
	pos.m_uX+=8;
	if(currentControl->m_ucMinute<=10){
		EG_Graphic_DrawFontChar(pos,'0',currentControl->m_pStyle->m_cContentColor,currentControl->m_pStyle->m_fFont);
		pos.m_uX+=8;
	}
	EG_Graphic_DrawFontNumber(pos,(int)currentControl->m_ucMinute,
		currentControl->m_pStyle->m_cContentColor,currentControl->m_pStyle->m_fFont);
	if(currentControl->m_bShowSecond){
		if(currentControl->m_ucMinute<=10)
			pos.m_uX+=8;
		else
			pos.m_uX+=16;
		EG_Graphic_DrawFontChar(pos,':',currentControl->m_pStyle->m_cContentColor,currentControl->m_pStyle->m_fFont);
		pos.m_uX+=8;
		if(currentControl->m_ucSecond<=10){
			EG_Graphic_DrawFontChar(pos,'0',currentControl->m_pStyle->m_cContentColor,currentControl->m_pStyle->m_fFont);
			pos.m_uX+=8;
		}
		EG_Graphic_DrawFontNumber(pos,(int)currentControl->m_ucSecond,
			currentControl->m_pStyle->m_cContentColor,currentControl->m_pStyle->m_fFont);
	}
#else
	EPosition pos=currentControl->m_pControlPos;
	pos.m_uX+=1;
	pos.m_uY+=1;
	EG_Graphic_DrawNumber(pos,(int)currentControl->m_ucHour,
		currentControl->m_pStyle->m_cContentColor);
	pos.m_uX+=16;
	EG_Graphic_DrawChar(pos,':',currentControl->m_pStyle->m_cContentColor);
	pos.m_uX+=8;
	if(currentControl->m_ucMinute<=10){
		EG_Graphic_DrawChar(pos,'0',currentControl->m_pStyle->m_cContentColor);
		pos.m_uX+=8;
	}
	EG_Graphic_DrawNumber(pos,(int)currentControl->m_ucMinute,
		currentControl->m_pStyle->m_cContentColor);
	if(currentControl->m_bShowSecond){
		if(currentControl->m_ucMinute<=10)
			pos.m_uX+=8;
		else
			pos.m_uX+=16;
		EG_Graphic_DrawChar(pos,':',currentControl->m_pStyle->m_cContentColor);
		pos.m_uX+=8;
		if(currentControl->m_ucSecond<=10){
			EG_Graphic_DrawChar(pos,'0',currentControl->m_pStyle->m_cContentColor);
			pos.m_uX+=8;
		}
		EG_Graphic_DrawNumber(pos,(int)currentControl->m_ucSecond,
			currentControl->m_pStyle->m_cContentColor);
	}
#endif  //EG_RICH_STYLE
#endif  //EG_SINGLE_COLOR
	currentControl->m_bNeedRedraw=false;	
}
