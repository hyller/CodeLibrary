// HotkeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HotKeyDemo.h"
#include "HotkeyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHotkeyDlg dialog


CHotkeyDlg::CHotkeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHotkeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHotkeyDlg)
	//}}AFX_DATA_INIT
}


void CHotkeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHotkeyDlg)
	DDX_Control(pDX, IDC_HOTKEY1, m_ctlHotKey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHotkeyDlg, CDialog)
	//{{AFX_MSG_MAP(CHotkeyDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotkeyDlg message handlers

void CHotkeyDlg::OnOK() 
{
	// TODO: Add extra validation here
	WORD m_wVkCode;
	WORD m_wModifier;
	m_ctlHotKey.GetHotKey(m_wVkCode, m_wModifier);//获取热键控件设置的热键
	//发送一个带有以上所返回的热键值的WM_RETHOTKEY消息到主窗口
	AfxGetMainWnd()->SendMessage(WM_SETHOTKEY,(WPARAM)MAKEWORD(m_wVkCode,m_wModifier));
	//将由GetHotKey()函数返回的组合键(modifier)转换成RegisterHotKey()函数可以使用的值
	UINT mod = 0;
	if (m_wModifier&HOTKEYF_ALT)mod|=MOD_ALT;
	if (m_wModifier&HOTKEYF_CONTROL) mod|=MOD_CONTROL;
	if (m_wModifier&HOTKEYF_SHIFT) mod|=MOD_SHIFT;
	if (m_wModifier&HOTKEYF_EXT) mod|=MOD_WIN;
	m_wModifier=mod;
	//注册热键
	::RegisterHotKey(
	AfxGetMainWnd()->m_hWnd, //接收热键的窗口指针
	111 , // 热键标识
	m_wModifier, // 标志
	m_wVkCode //虚拟键码
	);

	CDialog::OnOK();
}
