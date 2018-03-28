// ComboStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "StatusCombo.h"
#include "ComboStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboStatusBar

CComboStatusBar::CComboStatusBar()
{
}

CComboStatusBar::~CComboStatusBar()
{
}


BEGIN_MESSAGE_MAP(CComboStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CComboStatusBar)
	ON_CBN_SELCHANGE(IDC_COMBO,OnComboSelChange)//添加消息映射
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboStatusBar message handlers

int CComboStatusBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatusBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	BOOL bSuccess=FALSE;
	CRect PaneRect(0,0,0,0);
	PaneRect.bottom+=100;//设定展开框的大小
	bSuccess = m_Combo.Create(WS_CHILD|WS_VISIBLE|
		WS_VSCROLL|CBS_DROPDOWNLIST|CBS_AUTOHSCROLL,
		PaneRect, this, IDC_COMBO);//创建组合框
	if (!bSuccess)
		return 0;
	m_Combo.AddString("状态栏编程！");//添加列表项
	m_Combo.AddString("工具栏编程！");
	m_Combo.AddString("菜单编程！");
	m_Combo.AddString("其他编程！");
	m_Combo.SetCurSel(0);//设定默认选择项	
	return 0;
}

CComboBox &CComboStatusBar::GetCombo()
{
	return m_Combo;
}

void CComboStatusBar::OnComboSelChange()
{
	CString str;
	m_Combo.GetLBText(m_Combo.GetCurSel(),str);
	//将所选的项显示出来
	AfxMessageBox(str);
}

void CComboStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBar::OnSize(nType, cx, cy);
	UINT inx;
	CRect rect;
	//把组合框移动到ID_INDICATOR_NUM处
	inx=CommandToIndex(ID_SEPARATOR);
	GetItemRect(inx,&rect);
	rect.top-=2;//顶边位置
	rect.right=rect.left+150;//右边位置
	m_Combo.MoveWindow(rect);//移动组合框
}
