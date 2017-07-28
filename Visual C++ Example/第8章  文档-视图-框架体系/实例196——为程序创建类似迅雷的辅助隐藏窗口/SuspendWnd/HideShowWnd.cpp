// HideShowWnd.cpp : implementation file
//

#include "stdafx.h"
#include "SuspendWnd.h"
#include "HideShowWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHideShowWnd dialog


CHideShowWnd::CHideShowWnd(CWnd* pParent /*=NULL*/)
	: CDialog(CHideShowWnd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHideShowWnd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	flag = true;
}


void CHideShowWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHideShowWnd)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHideShowWnd, CDialog)
	//{{AFX_MSG_MAP(CHideShowWnd)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHideShowWnd message handlers

void CHideShowWnd::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	flag = !flag;
	if(flag)
	{
		AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOW);//显示主窗口
		AfxGetApp()->m_pMainWnd->UpdateWindow();
	}
	else
	{
		AfxGetApp()->m_pMainWnd->ShowWindow(SW_HIDE);//因此主窗口
		AfxGetApp()->m_pMainWnd->UpdateWindow();
	}
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CHideShowWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//由于辅助窗口对话框没有标题栏，因此设置其任意位置可移动窗口
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION,MAKELPARAM(point.x, point.y));//使得辅助窗口能够移动
	CDialog::OnLButtonDown(nFlags, point);	
}
