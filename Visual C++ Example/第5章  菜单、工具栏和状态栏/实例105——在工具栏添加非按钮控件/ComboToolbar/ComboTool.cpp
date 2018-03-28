// ComboTool.cpp : implementation file
//

#include "stdafx.h"
#include "ComboToolbar.h"
#include "ComboTool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboTool

CComboTool::CComboTool()
{
}

CComboTool::~CComboTool()
{
}


BEGIN_MESSAGE_MAP(CComboTool, CToolBar)
	//{{AFX_MSG_MAP(CComboTool)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboTool message handlers
BOOL CComboTool::CreateCombo( DWORD dwStyle, CComboBox *pComboBox, UINT nID,
							 int nWidth, int nHeight )
{
	//设置组合框的尺寸
	CRect pRect(-nWidth, -nHeight, 0, 0);
	pRect.right -= 2;
	//根据组合框的宽度重新设计分割条的位置
	ASSERT(CommandToIndex(nID) >= 0); 					//对应工具栏上的ID是否有效
	SetButtonInfo(CommandToIndex(nID), nID, TBBS_SEPARATOR, nWidth );
	//创建组合框并在工具栏上相应的位置显示
	if (!pComboBox->Create( dwStyle, pRect, this, nID ))
	{
		  TRACE("Failed to create the combo-box %p .\n", nID);
		  return FALSE;
	}
	GetItemRect( CommandToIndex(nID), &pRect );						//获取空按钮的位置
	pRect.left += 4;
	pRect.right = pRect.left + nWidth;
	pComboBox->SetWindowPos(0, pRect.left, pRect.top+1, 0, 0,
	SWP_NOZORDER | SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOCOPYBITS );	//设置列表框的位置
	pComboBox->ShowWindow( SW_SHOW );							//显示列表框
	return TRUE;
}
