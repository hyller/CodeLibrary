// ColorCombo.cpp : implementation file
//

#include "stdafx.h"
#include "ColorComboDemo.h"
#include "ColorCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorCombo

CColorCombo::CColorCombo()
{
	colors.Add(RGB(0, 0, 0));			// 黑色
	colors.Add(RGB(128, 0, 0));			// 深红色
	colors.Add(RGB(0, 128, 0));			// 深绿色
	colors.Add(RGB(128, 128, 0));		// 深黄色
	colors.Add(RGB(0, 0, 128));			// 深蓝色
	colors.Add(RGB(128, 0, 128));		// 深砖红色
	colors.Add(RGB(0, 128, 128));		// 深褐色	
	colors.Add(RGB(255, 0, 0));			// 红色
	colors.Add(RGB(0, 255, 0));			// 绿色
	colors.Add(RGB(255, 255, 0));		// 黄色
	colors.Add(RGB(0, 0, 255));			// 蓝色
	colors.Add(RGB(255, 0, 255));		// 砖红色
	colors.Add(RGB(0, 255, 255));		// 褐色
	colors.Add(RGB(255, 255, 255));		// 白色
}

CColorCombo::~CColorCombo()
{
}


BEGIN_MESSAGE_MAP(CColorCombo, CComboBox)
	//{{AFX_MSG_MAP(CColorCombo)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorCombo message handlers

void CColorCombo::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//获取DC
	CRect rect(&(lpDrawItemStruct->rcItem));//获取控件区域
	CBrush brush(colors[lpDrawItemStruct->itemID]);
	rect.InflateRect(-2, -2);
	dc.FillRect(rect, &brush);//填充矩形区域
	if (lpDrawItemStruct->itemState & ODS_SELECTED)//该项被选中
			dc.DrawFocusRect(rect);//显示选中项
	CBrush frameBrush(RGB(0, 0, 0));//黑色画刷
	dc.FrameRect(rect, &frameBrush);//绘制边界
	rect.InflateRect(-1, -1);//收缩1一个象素
	dc.Detach();//是否DC
	
}

void CColorCombo::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	for (int nColors = 0; nColors < colors.GetSize(); nColors++)//添加列表项
		AddString("");
	SetCurSel(0);//设置默认选中项
	CComboBox::PreSubclassWindow();
}
