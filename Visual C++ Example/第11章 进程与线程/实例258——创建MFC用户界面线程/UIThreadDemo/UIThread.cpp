// UIThread.cpp : implementation file
//

#include "stdafx.h"
#include "UIThreadDemo.h"
#include "UIThread.h"
#include "UIDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIThread

IMPLEMENT_DYNCREATE(CUIThread, CWinThread)

CUIThread::CUIThread()
{
}

CUIThread::~CUIThread()
{
}

BOOL CUIThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	CUIDlg  *pDlg=new CUIDlg;
	pDlg->Create(IDD_DIALOG1);								//创建非模态对话框
	pDlg->ShowWindow(SW_SHOW);							//显示对话
	m_pMainWnd = pDlg;										//将对话框设为主窗口
	return TRUE;
}

int CUIThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	if(m_pMainWnd!= NULL)
		delete m_pMainWnd;	//删除动态指针
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CUIThread, CWinThread)
	//{{AFX_MSG_MAP(CUIThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIThread message handlers
