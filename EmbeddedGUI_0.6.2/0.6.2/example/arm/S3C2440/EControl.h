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
	EControl.h   
*/
#ifndef ECONTROL_H
#define ECONTROL_H

#include "GraphicFunc.h"
#include "EComponent.h"

#define EG_CONTROL
#ifdef EG_CONTROL

class EControl;	

typedef void (*EG_CallbackFunc)(EControl* control,EEvent* curevent);
typedef void (*EG_RedrawFunc)(EControl* control);

void EG_RedrawFunc_DefaultELabel(EControl* control);
void EG_RedrawFunc_DefaultEButton(EControl* control);
void EG_CallbackFunc_DefaultECheckButton(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultECheckButton(EControl* control);
void EG_CallbackFunc_DefaultEEdit(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEEdit(EControl* control);
void EG_RedrawFunc_DefaultEProgress(EControl* control);
void EG_CallbackFunc_DefaultEExtLabel(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEExtLabel(EControl* control);
void EG_CallbackFunc_DefaultEComboBox(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEComboBox(EControl* control);
void EG_RedrawFunc_DefaultEIcon(EControl* control);
void EG_RedrawFunc_DefaultEIconButton(EControl* control);
void EG_CallbackFunc_DefaultEMessageBox(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEMessageBox(EControl* control);
void EG_CallbackFunc_DefaultEDialogBox(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEDialogBox(EControl* control);
void EG_CallbackFunc_DefaultEList(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEList(EControl* control);
void EG_CallbackFunc_DefaultEScroll(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEScroll(EControl* control);
void EG_CallbackFunc_DefaultEMenu(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEMenu(EControl* control);
void EG_CallbackFunc_DefaultEPopupMenu(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEPopupMenu(EControl* control);
void EG_CallbackFunc_DefaultETree(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultETree(EControl* control);
void EG_CallbackFunc_DefaultEToolBar(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEToolBar(EControl* control);
void EG_RedrawFunc_DefaultEStatusBar(EControl* control);
void EG_CallbackFunc_DefaultEBarChart(EControl* control,EEvent* curevent);
void EG_RedrawFunc_DefaultEBarChart(EControl* control);
void EG_RedrawFunc_DefaultEClock(EControl* control);

#ifdef EG_RGB_COLOR
	extern EStyle EG_DefaultStyle;
#endif

class EControl
{
public:

#ifdef EG_RGB_COLOR
	EControl():m_fpRedrawFunc(NULL),m_fpCallbackFunc(NULL),m_zArea(),m_pControlPos(),m_bNeedRedraw(true),m_pStyle(NULL){}
	EControl(EG_CallbackFunc cf,EG_RedrawFunc rf)
		:m_fpRedrawFunc(rf),m_fpCallbackFunc(cf),m_zArea(),m_pControlPos(),m_bNeedRedraw(true),m_pStyle(&EG_DefaultStyle){}
	EControl(EG_CallbackFunc cf,EG_RedrawFunc rf,ESize area,EPosition pos)
		:m_fpRedrawFunc(rf),m_fpCallbackFunc(cf),m_zArea(area),m_pControlPos(pos),m_bNeedRedraw(true),m_pStyle(&EG_DefaultStyle){}
#else
	EControl():m_fpRedrawFunc(NULL),m_fpCallbackFunc(NULL),m_zArea(),m_pControlPos(),m_bNeedRedraw(true){}
	EControl(EG_CallbackFunc cf,EG_RedrawFunc rf):m_fpRedrawFunc(rf),m_fpCallbackFunc(cf),m_zArea(),m_pControlPos(),m_bNeedRedraw(true){}
	EControl(EG_CallbackFunc cf,EG_RedrawFunc rf,ESize area,EPosition pos)
		:m_fpRedrawFunc(rf),m_fpCallbackFunc(cf),m_zArea(area),m_pControlPos(pos),m_bNeedRedraw(true){}
#endif

	~EControl(void){}

	void RedrawControl(){
		if(m_fpRedrawFunc!=NULL){
			m_fpRedrawFunc(this);
		}	
	}

	void NoticeControl(EEvent* pevent);
	bool InControlArea(EPosition curPos);

	void SetCallbackFunction(void(*cf)(EControl* control,EEvent* curevent)){
		this->m_fpCallbackFunc=cf;
	}
	void SetRedrawFunction(void(*rf)(EControl* control)){
		this->m_fpRedrawFunc=rf;
	}

protected:
	EG_RedrawFunc m_fpRedrawFunc;
	EG_CallbackFunc m_fpCallbackFunc;

public:
	ESize m_zArea;
	EPosition m_pControlPos;
	bool m_bNeedRedraw;

#ifdef EG_RGB_COLOR
	EStyle* m_pStyle;
#endif

};

class ELabel:public EControl{
public:
	ELabel():EControl(NULL,EG_RedrawFunc_DefaultELabel),m_pLableString(NULL){}
	ELabel(EPosition pos,char* pstring,unsigned int labelWidth);
	ELabel(EG_CallbackFunc cf,EG_RedrawFunc rf,EPosition pos,char* pstring,unsigned int labelWidth);

	friend void EG_RedrawFunc_DefaultELabel(EControl* control);

	void SetLableString(char* pstring){
		this->m_pLableString=pstring;
	}

protected:
	char* m_pLableString;
};

class EButton:public EControl{
public:
	EButton():EControl(NULL,EG_RedrawFunc_DefaultEButton),m_pButtonString(NULL){}
	EButton(EG_CallbackFunc cf,EPosition pos,char* pstring,unsigned int buttonWidth);

	friend void EG_RedrawFunc_DefaultEButton(EControl* control);

	void SetButtonString(char* pstring){
		this->m_pButtonString=pstring;
	}

protected:
	char* m_pButtonString;
};

class ECheckButton:public EControl{
public:
	ECheckButton():EControl(NULL,EG_RedrawFunc_DefaultECheckButton),m_pCheckButtonString(NULL){}
	ECheckButton(bool check,EPosition pos,char* pstring,unsigned int checkButtonWidth);
	ECheckButton(EG_CallbackFunc cf,bool check,EPosition pos,char* pstring,unsigned int checkButtonWidth);

	friend void EG_CallbackFunc_DefaultECheckButton(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultECheckButton(EControl* control);

	bool GetCheckState(){
		return m_bCheckButtonChecked;
	}
	void SetCheckState(bool checkState){
		this->m_bCheckButtonChecked=checkState;
	}
	void SetCheckButtonString(char* pstring){
		m_pCheckButtonString=pstring;
	}

protected:
	char* m_pCheckButtonString;
	bool m_bCheckButtonChecked;
};

class EEdit:public EControl{
public:
	EEdit():EControl(NULL,EG_RedrawFunc_DefaultEEdit),m_bPassword(false),m_ulength(0){
		for(int n=0;n<MaxStringLength+1;n++)
			m_saString[n]='\0';	
	}
	EEdit(bool password,EPosition pos,unsigned int editWidth);
	EEdit(char* pstring,bool password,EPosition pos,unsigned int editWidth);
	EEdit(EG_CallbackFunc cf,char* pstring,bool password,EPosition pos,unsigned int editWidth);

	friend void EG_CallbackFunc_DefaultEEdit(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEEdit(EControl* control);

	void AddCharToString(char str);
	void SetString(char* string);
	void SetString(char string[],int length);
	char* GetString(){
		return (char*)(&m_saString[0]);
	}
	int GetStringLength(){
		return m_ulength;
	}
	bool IsPasswordEdit(){
		return m_bPassword;
	}

protected:
	static const int MaxStringLength=20;

	bool m_bPassword;
	char m_saString[MaxStringLength+1];
	int m_ulength;
};

class EProgress:public EControl{
public:
#ifdef EG_RICH_STYLE
	EProgress():EControl(NULL,EG_RedrawFunc_DefaultEProgress),m_uProgress(0),m_bBarStyle(false){}
	EProgress(EPosition pos,ESize size,bool barStyle=false)
		:EControl(NULL,EG_RedrawFunc_DefaultEProgress,size,pos),m_uProgress(0),m_bBarStyle(barStyle){}
	EProgress(unsigned int progress,EPosition pos,ESize size,bool barStyle=false)
		:EControl(NULL,EG_RedrawFunc_DefaultEProgress,size,pos),m_uProgress(progress),m_bBarStyle(barStyle){}
#else
	EProgress():EControl(NULL,EG_RedrawFunc_DefaultEProgress),m_uProgress(0){}
	EProgress(EPosition pos,ESize size)
		:EControl(NULL,EG_RedrawFunc_DefaultEProgress,size,pos),m_uProgress(0){}
	EProgress(unsigned int progress,EPosition pos,ESize size)
		:EControl(NULL,EG_RedrawFunc_DefaultEProgress,size,pos),m_uProgress(progress){}
#endif  //EG_RICH_STYLE

	friend void EG_RedrawFunc_DefaultEProgress(EControl* control);

	void SetProgress(unsigned int pro){
		this->m_uProgress=pro;
		this->RedrawControl();
	}
	unsigned int GetProgress(){
		return this->m_uProgress;
	}

protected:
	unsigned int m_uProgress;

#ifdef EG_RICH_STYLE
	bool m_bBarStyle;
#endif  //EG_RICH_STYLE
};

class EExtLabel:public ELabel{
public:
	EExtLabel();
	EExtLabel(EPosition pos,char* pstring,unsigned int labelWidth);
	EExtLabel(EG_CallbackFunc cf,EPosition pos,char* pstring,unsigned int labelWidth);

	friend void EG_CallbackFunc_DefaultEExtLabel(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEExtLabel(EControl* control);

	void ChangeState();
	void SetState(bool state){
		this->m_bState=state;
		this->RedrawControl();
	}
	bool GetState(){
		return this->m_bState;
	}

protected:
#ifdef EG_RICH_STYLE
	unsigned char m_uUnderlineCount;
#endif  //EG_RICH_STYLE
	bool m_bState;
};

class EComboBox:public EControl{
public:
	EComboBox();
	EComboBox(EPosition pos,unsigned int comboBoxWidth);

	friend void EG_CallbackFunc_DefaultEComboBox(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEComboBox(EControl* control);

	char* GetItemString(unsigned int index){
		return (char*)(&(this->m_saString[index][0]));
	}
	void SetIemString(unsigned int index,char str[]);
	void AddItem(char str[]);
	void RemoveItem(unsigned int index);
	unsigned int GetSelectIndex(){
		return this->m_uSelectItem;
	}
	void SetSelectIndex(unsigned int index){
		this->m_uSelectItem=index;
		this->RedrawControl();
	}
	bool GetOpenState(){
		return this->m_bOpen;	
	}
	void SwitchOpenState();
	unsigned int GetItemNumber(){
		return m_uItem;
	}

	static const int MaxItem=6;
	static const int MaxStringLength=20;

protected:
#ifdef EG_RICH_STYLE
	unsigned char m_uHoverItem;
#endif  //EG_RICH_STYLE

	char m_saString[MaxItem][MaxStringLength+1];
	unsigned int m_uSelectItem;
	unsigned int m_uItem;
	bool m_bOpen;
};

class EIcon:public EControl{
public:
	EIcon():EControl(NULL,EG_RedrawFunc_DefaultEIcon),m_pbIcon(0,0){}
#ifdef EG_RGB_COLOR
	EIcon(EG_CallbackFunc cf,EPosition pos,ESize size,unsigned char* pBuffer)
		:EControl(cf,EG_RedrawFunc_DefaultEIcon,size,pos),m_pbIcon(size.m_uWidth,size.m_uHeight,pBuffer){}
#else
	EIcon(EG_CallbackFunc cf,EPosition pos,ESize size,unsigned char* pBuffer)
		:EControl(cf,EG_RedrawFunc_DefaultEIcon,size,pos),m_pbIcon(size.m_uWidth,(size.m_uHeight>>3),pBuffer){}
#endif //EG_RGB_COLOR
#ifdef EG_DEFAULT_ICON
	EIcon(EG_CallbackFunc cf,EPosition pos,unsigned int iconIndex);
#endif //EG_DEFAULT_ICON

	friend void EG_RedrawFunc_DefaultEIcon(EControl* control);

	void SetIconBuffer(unsigned char* pBuf){
		this->m_pbIcon.m_pImageBuffer=pBuf;
	}
	EBitmap* GetBitmap(){
		return &m_pbIcon;
	}

#ifdef EG_DEFAULT_ICON
	void SetIconBuffer(unsigned int iconIndex);
#endif  //EG_DEFAULT_ICON

protected:
	EBitmap m_pbIcon;
};

class EIconButton:public EIcon{
public:
	EIconButton():EIcon(),m_pIconButtonString(NULL){}
	EIconButton(EG_CallbackFunc cf,EPosition pos,ESize buttonSize,ESize iconSize,unsigned char* pBuffer,
		char* pString,bool rightString);
	EIconButton(EG_CallbackFunc cf,EPosition pos,ESize buttonSize,unsigned int iconIndex,
		char* pString,bool rightString);

	friend void EG_RedrawFunc_DefaultEIconButton(EControl* control);

	void SetButtonString(char* pstring){
		this->m_pIconButtonString=pstring;
	}
protected:
	bool m_bRightString;
	char* m_pIconButtonString;
};

class EMessageBox:public EControl{
public:
	EMessageBox(unsigned char type,EPosition pos,char* pstring,unsigned int messageBoxWidth);

	friend void EG_CallbackFunc_DefaultEMessageBox(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEMessageBox(EControl* control);

	bool InCloseArea(const EPosition& pos);
	void SwitchState();
	bool GetMessageBoxState(){
		return m_bOpen;
	}
	void SetMessageBoxType(unsigned char type){
		m_uMessageBoxType=type;
	}
	unsigned char GetMessageBoxType(){
		return m_uMessageBoxType;
	}

protected:
	char* m_pMessageString;
	bool m_bOpen;

	// MessageBox Type:
	//  0   No Title String 
	//  1   Error 
	//  2   Warning
	//  3   Info
	unsigned char m_uMessageBoxType;
};

class EDialogBox:public EControl{
public:
	EDialogBox(unsigned char type,EPosition pos,char* pstring,unsigned int dialogBoxWidth);

	friend void EG_CallbackFunc_DefaultEDialogBox(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEDialogBox(EControl* control);

	void UpdataState(const EPosition& pos);

	void SetDialogBoxState(unsigned char state){
		if(state<=2){
			m_uDialogState=state;
		}
	}
	unsigned char GetDialogBoxState(){
		return m_uDialogState;
	}
	void SetDialogBoxType(unsigned char type){
		this->m_uDialogBoxType=type;
	}

protected:
	char* m_pMessageString;
	
	//Dialog State:
	//   0  Opening
	//   1  Exit with OK
	//   2  Exit with Cancel 
	unsigned char m_uDialogState;

	// DialogBox Type:
	//  0   No Title String 
	//  1   Error 
	//  2   Warning
	//  3   Info
	unsigned char m_uDialogBoxType;
};

class EScroll:public EControl{
public:
	EScroll();
#ifdef EG_RICH_STYLE
	EScroll(EPosition pos,unsigned int height,unsigned int step,bool wideScroll=false);
#else 
	EScroll(EPosition pos,unsigned int height,unsigned int step);
#endif  //EG_RICH_STYLE

	friend void EG_CallbackFunc_DefaultEScroll(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEScroll(EControl* control);

	void SetStepValue(unsigned int step){
		this->m_uStepValue=step;
	}
	void SetCurrentPosition(unsigned int pos);
	unsigned int GetCurrentPosition(){
		return this->m_uCurPosition;
	}
protected:
	//range :  8 to Area.height-16
	unsigned int m_uCurPosition;
	unsigned int m_uStepValue;
#ifdef EG_RICH_STYLE
	bool m_bWideScroll;
#endif  //EG_RICH_STYLE
};

class EList:public EControl{
public:
	static const unsigned int MaxColumn=5;
	static const unsigned int MaxRow=15;
	static const unsigned int MaxStringLength=20;

	struct EListItem{
		char m_saString[MaxColumn][MaxStringLength+1];
		EG_CallbackFunc m_pcbListHandler;
	};	

public:
	EList():EControl(EG_CallbackFunc_DefaultEList,EG_RedrawFunc_DefaultEList){
		RemoveAllItems();
	}
	EList(EPosition pos):EControl(EG_CallbackFunc_DefaultEList,EG_RedrawFunc_DefaultEList,ESize(0,0),pos){
		RemoveAllItems();
	}
	
	friend void EG_CallbackFunc_DefaultEList(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEList(EControl* control);

	void SelectItem(unsigned int index){
		if(index<this->m_uItemCount){
			m_uItemSelect=index;
			this->RedrawControl();
		}
	}
	unsigned int GetSelectIndex(){
		return this->m_uItemSelect;
	}
	unsigned int GetColumnWidth(unsigned int columnIndex){
		if(columnIndex<m_uColumnCount)
			return m_uarrColumnWidth[columnIndex];
		else
			return 0;	
	}
	void RemoveAllColumns(){
		m_uColumnCount=0;
		this->m_zArea.m_uWidth=0;
	}

	void AddItem(EListItem* pitem);
	void RemoveItem(int index);
	void RemoveAllItems();
	void AddColumn(unsigned int width);
	void SetColumnWidth(unsigned int columnIndex,unsigned int width);
	void SetItem(unsigned int itemIndex,unsigned int columnIndex,char* pstring);
	void SetItem(unsigned int itemIndex,unsigned int columnIndex,char* pstring,EG_CallbackFunc cbfHandler);

protected:
	unsigned int m_uColumnCount;
	unsigned int m_uarrColumnWidth[MaxColumn];
	unsigned int m_uItemSelect;
	unsigned int m_uItemCount;
	EListItem* m_parrItem[MaxRow];
};

class EMenu:public EControl{
public:
	static const unsigned int MaxStringLength=20;

	struct EMenuItem{
		char m_pcLabel[MaxStringLength];
		unsigned char m_uState;
		EG_CallbackFunc m_fpCallbackFunc;
#ifdef EG_RICH_STYLE
		EBitmap* m_piIcon;  //the height of icon must be less than height of font.
#endif  //EG_RICH_STYLE
	};

public:
	EMenu();
	EMenu(char* pString,unsigned int menuWidth,EPosition pos,bool upperExtend=false);

	static const unsigned int MaxMenuItem=10;
	static const unsigned char MenuSelect=0x01;
	
	friend void EG_CallbackFunc_DefaultEMenu(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEMenu(EControl* control);

	//return the item index
	int AddItem(EMenuItem* pItem);
	void RemovedAllItems();
	void SetMenuItemState(unsigned int index,unsigned char state);
	void SetMenuItem(unsigned int index,char* label,unsigned char state);
#ifdef EG_RICH_STYLE
	void SetMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback,EBitmap* pIcon=NULL);
#else
	void SetMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback);
#endif  //EG_RICH_STYLE
	void SwitchShowState();
	void CollapseMenu();

	void SetSelectItem(unsigned int index){
		if(index<this->m_uItemNumber){
			this->m_uItemSelect=index;
			m_bNeedRedraw=true;
		}
	}
	unsigned int GetSelectItemIndex(){
		return this->m_uItemSelect;
	}
	void SetControlPosition(EPosition pos){
		this->m_pControlPos=pos;
		this->m_uOriginalY=pos.m_uY;
	}
	unsigned int GetBaseWidth(){
		return this->m_uBaseMenuWidth;
	}
	//true : extend to up
	void SetExtendDirection(bool direction){
		this->m_bUpperExtend=direction;
	}
	EMenuItem* GetMenuItem(unsigned int index){
		if(index<this->m_uItemNumber){
			return this->m_parrMenuItemArray[index];
		}
		return NULL;
	}
	unsigned int GetMenuItemCount(){
		return this->m_uItemNumber;
	}

protected:
	void UpdateHeightAndPosition();

protected:
	EMenuItem* m_parrMenuItemArray[MaxMenuItem];
	unsigned int m_uItemNumber;
	unsigned int m_uItemSelect;
	unsigned int m_uBaseMenuWidth;
	unsigned int m_uTempWidth;
	unsigned int m_uOriginalY;  //only used when upperExtend == true
	char* m_pMenuString;
	bool m_bDisplay;
	bool m_bUpperExtend;
};

class EPopupMenu:public EControl{
public:
	static const unsigned int MaxStringLength=20;

	struct EPopupMenuItem{
		char m_pcLabel[MaxStringLength];
		unsigned char m_uState;
		EG_CallbackFunc m_fpCallbackFunc;
#ifdef EG_RICH_STYLE
		EBitmap* m_piIcon;  //the height of icon must be less than height of font.
#endif  //EG_RICH_STYLE
	};

public:
	EPopupMenu();

	static const unsigned int MaxMenuItem=10;

	friend void EG_CallbackFunc_DefaultEPopupMenu(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEPopupMenu(EControl* control);

	//return the lable index
	int AddItem(EPopupMenuItem* pItem);
	void RemovedAllItems();
	void SetPopupMenuItemState(unsigned int index,unsigned char state);
	void SetPopupMenuItem(unsigned int index,char* label,unsigned char state);
#ifdef EG_RICH_STYLE
	void SetPopupMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback,EBitmap* pIcon=NULL);
#else
	void SetPopupMenuItem(unsigned int index,char* label,unsigned char state,EG_CallbackFunc fpCallback);
#endif  //EG_RICH_STYLE
	void ShowPopupMenu(const EPosition& pos);
	void ClosePopupMenu();

	void SetSelectItem(unsigned int index){
		if(index<this->m_uItemNumber){
			this->m_uItemSelect=index;
			m_bNeedRedraw=true;
		}
	}
	int GetSelectItemIndex(){
		return this->m_uItemSelect;
	}
	bool GetPopupState(){
		return this->m_bDisplay;
	}
	EPopupMenuItem* GetPopupMenuItem(unsigned int index){
		if(index<this->m_uItemNumber){
			return this->m_parrPopupMenuItemArray[index];
		}
		return NULL;
	}
	unsigned int GetPopupMenuItemCount(){
		return this->m_uItemNumber;
	}

protected:
	EPopupMenuItem* m_parrPopupMenuItemArray[MaxMenuItem];
	unsigned int m_uItemNumber;
	unsigned int m_uItemSelect;
	bool m_bDisplay;
	ESize m_zDisplayArea;
};

class ETree:public EControl{
public:
	static const unsigned int MaxStringLength=20;
	static const unsigned int MaxSubItem=10;

	struct ETreeItem;
	struct ETreeSubItem{
		ETreeSubItem();
		ETreeSubItem* GetOpenSubItem(unsigned int& index);
		unsigned int GetOpenSubItemCount();
		void SetSubItemString(char* pString);
		void OpenSubItem(){
			if(m_pTreeItem!=NULL){
				m_pTreeItem->OpenAllSubItem();
			}
		}
		void CloseSubItem(){
			if(m_pTreeItem!=NULL){
				m_pTreeItem->CloseAllSubItem();
			}
		}

		bool m_bOpen;
		char m_saString[MaxStringLength];
		ETreeItem* m_pTreeItem;
		ETreeItem* m_pFather;
	};

	struct ETreeItem{
		ETreeItem();
		unsigned int AddSubItem(ETreeSubItem* psubitem);
		void OpenAllSubItem();
		void CloseAllSubItem();
		ETreeSubItem* GetOpenSubItem(unsigned int& index);
		unsigned int GetOpenSubItemCount();

		unsigned char m_uDepth;
		unsigned int m_uSubItemCount;
		ETreeSubItem* m_pTreeSubItem[MaxSubItem];
	};

public:	
	ETree():EControl(EG_CallbackFunc_DefaultETree,EG_RedrawFunc_DefaultETree){}
	ETree(ESize area,EPosition pos)
		:EControl(EG_CallbackFunc_DefaultETree,EG_RedrawFunc_DefaultETree,area,pos){}

	friend void EG_CallbackFunc_DefaultETree(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultETree(EControl* control);

	//return root index
	unsigned int AddRoot(ETreeSubItem* pSubItem,char* rootString);
	void AddBranch(ETreeItem* pleaf,unsigned int rootIndex);
	void AddBranch(ETreeItem* pleaf,unsigned int rootIndex,unsigned int leafIndex);
	//return leaf index
	unsigned int AddLeaf(unsigned int rootIndex,ETreeSubItem* pSubItem,char* pString);
	unsigned int AddLeaf(unsigned int rootIndex,unsigned int leafIndex,ETreeSubItem* pSubItem,char* pString);
	void RemoveAllRoots();
	void RemoveRoot(unsigned int rootIndex);
	void ToggleRootState(unsigned int rootIndex);
	void ToggleLeafState(unsigned int rootIndex,unsigned int leafIndex);

	void RemoveAllLeafs(unsigned int rootIndex){
		if(rootIndex>=this->m_tiTreeStruct.m_uSubItemCount)
			return;
		if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem!=NULL){
			this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]	->m_pTreeItem=NULL;
		}
	}

	void RemoveLeaf(unsigned int rootIndex,unsigned int leafIndex){
		if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem!=NULL){
			this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_uSubItemCount--;
			this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]	->m_pTreeItem->m_pTreeSubItem[leafIndex]=NULL;
		}
	}

	ETreeSubItem* GetRoot(unsigned int rootIndex){
		return this->m_tiTreeStruct.m_pTreeSubItem[rootIndex];
	}

	ETreeSubItem* GetLeaf(unsigned int rootIndex,unsigned int leafIndex){
		if(this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem!=NULL){
			return this->m_tiTreeStruct.m_pTreeSubItem[rootIndex]->m_pTreeItem->m_pTreeSubItem[leafIndex];
		}else{
			return NULL;
		}
	}

	ETreeSubItem* GetOpenLeaf(unsigned int index){
		return this->m_tiTreeStruct.GetOpenSubItem(index);
	}

	unsigned int GetOpenLeafCount(){
		return this->m_tiTreeStruct.GetOpenSubItemCount();
	}

	unsigned char GetOpenLeafDepth(unsigned int index){
		ETreeSubItem* temp=this->m_tiTreeStruct.GetOpenSubItem(index);
		if(temp!=NULL)
			return temp->m_pFather->m_uDepth;
		else
			return 0xFF;
	}

	void OpenAllLeafs(){
		this->m_tiTreeStruct.OpenAllSubItem();	
		this->RedrawControl();
	}

	void CollapseAllLeafs(){
		this->m_tiTreeStruct.CloseAllSubItem();
		this->RedrawControl();
	}

protected:
	void DrawExtendIcon(const EPosition& pos,bool open);

protected:
	ETreeItem m_tiTreeStruct;
};

class EToolBar:public EControl{
public:
	EToolBar();
	EToolBar(EPosition pos);

	friend void EG_CallbackFunc_DefaultEToolBar(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEToolBar(EControl* control);

	unsigned int AddItem(EControl* pitem);
	void RemoveItem(unsigned int index);
	void RemoveAllItems();
	void AdjustControlPosition();
	void SetDockState(unsigned char state);

	EControl* GetItem(unsigned int index){
		return this->m_parrToolBarItem[index];
	}
	unsigned char GetDockState(){
		return this->m_cDockState;
	}

protected:
	void UpdateToolBarHeight();

public:
	static const unsigned int MaxItem=10;

protected:
	bool m_bPositionAdjust;
	//  0 not in dock
	//  1  top  2  buttom  3  left   4  right
	unsigned char m_cDockState;
	unsigned int m_uItemCount;
	EControl* m_parrToolBarItem[MaxItem];
};

class EStatusBar:public EControl{
public:
	EStatusBar():EControl(NULL,EG_RedrawFunc_DefaultEStatusBar){
		m_cDockState=0;
#ifndef EG_RICH_STYLE
		this->m_zArea.m_uHeight=10;
#else
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10){
			this->m_zArea.m_uHeight=10;		
		}else{
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
		}
#endif  //EG_RICH_STYLE
		this->ClearLabelString();
		this->ClearStatusString(1);
		this->ClearStatusString(2);
	}
	EStatusBar(ESize area,EPosition pos):EControl(NULL,EG_RedrawFunc_DefaultEStatusBar,area,pos){
		m_cDockState=0;
#ifndef EG_RICH_STYLE
		this->m_zArea.m_uHeight=10;
#else
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]<=10){
			this->m_zArea.m_uHeight=10;		
		}else{
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
		}
#endif  //EG_RICH_STYLE
		this->ClearLabelString();
		this->ClearStatusString(1);
		this->ClearStatusString(2);
	}
	
	friend void EG_RedrawFunc_DefaultEStatusBar(EControl* control);

	void SetLabelString(char* string);
	void SetStatusString(char* string,unsigned char index);
	char* GetStatusString(unsigned char index);
	void ClearLabelString();
	void ClearStatusString(unsigned char index);
	void SetStatusPosition(unsigned char index,unsigned int position);

	void SetDockState(unsigned char state){
		if(state<=4){
			this->m_cDockState=state;
		}
	}
	unsigned char GetDockState(){
		return this->m_cDockState;
	}
	char* GetLabelString(){
		return (char*)(&(this->m_carrLabelString[0]));
	}

	static const unsigned int MaxStatusLabelLength=20;	
	static const unsigned int MaxStatusString=6;
protected:
	//  0 not in dock
	//  1  top  2  buttom
	unsigned char m_cDockState;
	char m_carrLabelString[MaxStatusLabelLength];
	char m_carrStatusString1[MaxStatusString];
	char m_carrStatusString2[MaxStatusString];
	unsigned int m_uStatusString1Position;	
	unsigned int m_uStatusString2Position;	
};

class EBarChart:public EControl{
public:
	struct EBarChartItem{
		char* m_pItemText;
		unsigned int m_uBarHeight;
		unsigned int m_uBarWidth;
#ifdef EG_RGB_COLOR
		EColor m_cBarColor;
#endif  //EG_RGB_COLOR
	};

public:
	EBarChart():EControl(EG_CallbackFunc_DefaultEBarChart,EG_RedrawFunc_DefaultEBarChart){
		this->m_bUpperWord=false;
		this->m_uBlankWidth=10;
		this->m_pXAxisString=NULL;
		this->m_pYAxisString=NULL;
		this->m_uYAxisRange=0;
		this->m_uSelectedItem=0;
		this->RemoveAllItems();
	}
	EBarChart(char* xAxisString,char* yAxisString,int XAxisRange,int YAxisRange,
		ESize area,EPosition pos,bool upperWord,unsigned int blankWidth)
		:EControl(EG_CallbackFunc_DefaultEBarChart,EG_RedrawFunc_DefaultEBarChart,area,pos){
		this->m_bUpperWord=upperWord;
		this->m_uBlankWidth=blankWidth;
		this->m_pXAxisString=xAxisString;
		this->m_pYAxisString=yAxisString;
		this->m_uXAxisRange=XAxisRange;
		this->m_uYAxisRange=YAxisRange;
		this->m_uSelectedItem=0;
		this->RemoveAllItems();
	}

	friend void EG_CallbackFunc_DefaultEBarChart(EControl* control,EEvent* curevent);
	friend void EG_RedrawFunc_DefaultEBarChart(EControl* control);

	unsigned int AddBarItem(EBarChart::EBarChartItem* pBarChart){
		if(m_uItemCount<MaxBarItem){
			this->m_parrBarArray[this->m_uItemCount]=pBarChart;
			this->m_uItemCount++;
		}
		return m_uItemCount;
	}	

	void RemoveItem(unsigned int index){
		unsigned int m=this->m_uItemCount;
		for (unsigned int c=index;c<m;c++){
			this->m_parrBarArray[c]=this->m_parrBarArray[c+1];
		}
		this->m_uItemCount--;
	}

	void RemoveAllItems(){
		for(unsigned int n=0;n<m_uItemCount;n++){
			this->m_parrBarArray[n]=NULL;
		}	
		m_uItemCount=0;
	}

	int GetYAxisRange(){
		return this->m_uYAxisRange;
	}
	void SetYAxisRange(int YAxisRange){
		this->m_uYAxisRange=YAxisRange;
	}
	int GetXAxisRange(){
		return this->m_uXAxisRange;
	}
	void SetXAxisRange(int XAxisRange){
		this->m_uXAxisRange=XAxisRange;
	}
	char* GetAxisString(unsigned char xAxis){
		if(xAxis)
			return this->m_pXAxisString;
		else
			return this->m_pYAxisString;
	}
	void SetAxisString(char* pstring,unsigned char xAxis){
		if(xAxis)
			this->m_pXAxisString=pstring;
		else
			this->m_pYAxisString=pstring;
	}
	void SelectItem(unsigned int index){
		this->m_uSelectedItem=index;
		this->RedrawControl();
	}

protected:
	unsigned int CheckSelectItem(unsigned int x,unsigned int y);

public:
	static const unsigned int MaxBarItem = 8;

protected:
	bool m_bUpperWord;
	char* m_pXAxisString;
	char* m_pYAxisString;
	int m_uBlankWidth;
	// not to draw the range value if equals to 0.
	int m_uXAxisRange;
	int m_uYAxisRange;
	unsigned int m_uSelectedItem;
	unsigned int m_uItemCount;
	EBarChartItem* m_parrBarArray[MaxBarItem];
};

class EClock :public EControl{
public:
	EClock():EControl(NULL,EG_RedrawFunc_DefaultEClock){}
	EClock(EPosition pos,bool showSecond)
		:EControl(NULL,EG_RedrawFunc_DefaultEClock,ESize(0,10),pos){
		if(showSecond){
			this->m_zArea.m_uWidth=68;
		}else{
			this->m_zArea.m_uWidth=43;
		}
#ifdef EG_RICH_STYLE
		if(EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber]>10)
			this->m_zArea.m_uHeight=EG_FontHeight[this->m_pStyle->m_fFont.m_cFontNumber];
#endif  //EG_RICH_STYLE
		m_bShowSecond=showSecond;
	}

	friend void EG_RedrawFunc_DefaultEClock(EControl* control);

	void AccumulateMinute(){
		++(this->m_ucMinute);
		if(this->m_ucMinute==60){
			++(this->m_ucHour);
			this->m_ucMinute=0;
			if(this->m_ucHour==24){
				this->m_ucHour=0;
			}
		}
		this->RedrawControl();
	}
	void AccumulateSecond(){
		++(this->m_ucSecond);
		if(this->m_ucSecond==60){
			this->m_ucSecond=0;
			this->AccumulateMinute();
			return;
		}
		this->RedrawControl();
	}
	void UpdateTime(unsigned char hour,unsigned char minute,unsigned char second){
		this->m_ucHour=hour;
		this->m_ucMinute=minute;
		this->m_ucSecond=second;
		this->RedrawControl();
	}
	void UpdateTime(unsigned char hour,unsigned char minute){
		this->m_ucHour=hour;
		this->m_ucMinute=minute;
		this->RedrawControl();
	}
	unsigned char GetHour(){
		return this->m_ucHour;
	}
	unsigned char GetMinute(){
		return this->m_ucMinute;
	}
	unsigned char GetSecond(){
		return this->m_ucSecond;
	}
protected:
	bool m_bShowSecond;
	unsigned char m_ucHour;
	unsigned char m_ucMinute;
	unsigned char m_ucSecond;
};

#endif

#endif //ECONTROL_H
