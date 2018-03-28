// NewListBox.cpp : implementation file
//

#include "stdafx.h"
#include "TabListDemo.h"
#include "NewListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NewListBox

NewListBox::NewListBox()
{
}

NewListBox::~NewListBox()
{
}


BEGIN_MESSAGE_MAP(NewListBox, CListBox)
	//{{AFX_MSG_MAP(NewListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NewListBox message handlers

void NewListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//获取列表框的DC
	CRect rect(lpDrawItemStruct->rcItem);//获取列表框的矩形区域
	COLORREF bk = dc.GetBkColor();//背景颜色
	COLORREF fg = dc.GetTextColor();//系统文本颜色
	if(lpDrawItemStruct->itemState & ODS_SELECTED)//该项被选中
	{
		bk =  RGB(180,180,0 );//背景颜色
		fg = RGB(255,0,0 );//红色文本
	}
	dc.SetTextColor(fg);
	CBrush brush(bk);
	dc.FillRect(&rect,&brush);
	if (lpDrawItemStruct->itemState&ODS_SELECTED)
	rect.left +=25;//缩进25个象素
	int nBkMode = dc.SetBkMode( TRANSPARENT );
	CString str;
	GetText(lpDrawItemStruct->itemID,str) ;
	dc.DrawText(str, &rect, DT_LEFT|DT_VCENTER);//显示文本
	dc.SetTextColor(fg);
	dc.SetBkMode( nBkMode );
	dc.Detach() ;	
}
