// UIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WorkThreadDemo.h"
#include "UIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIDlg dialog
UINT ThreadFunc(LPVOID lpParam)									//线程函数
{
  CProgressCtrl* pInfo=(CProgressCtrl*)lpParam;							//线程函数参数
  for(int pos=0;pos<30;pos++)
	{
		pInfo->SetPos(pos);//设置进度条进度
		Sleep(500);//停止0.5秒
	}	
  return 0;
}



CUIDlg::CUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUIDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUIDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUIDlg, CDialog)
	//{{AFX_MSG_MAP(CUIDlg)
	ON_BN_CLICKED(IDC_STAR, OnStar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIDlg message handlers

void CUIDlg::OnStar() 
{
	// TODO: Add your control notification handler code here
	CWinThread* pThread=AfxBeginThread(ThreadFunc,&m_progress);				//创建新的线程并开始执行
}

BOOL CUIDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	m_progress.SetRange(0,30);//设置进度条范围
	return TRUE;  
}
