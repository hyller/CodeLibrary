// EventThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EventThread.h"
#include "EventThreadDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_USER_ENDED WM_USER + 1

struct ThreadInfo
{
	CDialog* pDialog;//对话框对象
	CProgressCtrl* pProgress;//进度条对象
} threadInfo;

CEvent eventKill, eventBegin, eventStop;//事件对象

UINT ThreadProc(LPVOID pParam)
{
	ThreadInfo* pInfo = (ThreadInfo*)pParam;
	BOOL bKeepRunning = TRUE;
	while(bKeepRunning)
	{
		if(WaitForSingleObject(eventBegin.m_hObject, 0) == WAIT_OBJECT_0)//开始计算
		{
			for(int i = 0; i<100; i++)
			{
			    pInfo->pProgress->SetPos(i);
			    if(WaitForSingleObject(eventKill.m_hObject, 0)== WAIT_OBJECT_0)//结束线程
			    {
				    bKeepRunning = FALSE;
				    break;
			    }
			   if(WaitForSingleObject(eventStop.m_hObject, 0) == WAIT_OBJECT_0)//停止计算
				    break;
			    Sleep(100);
		    }
		    pInfo->pProgress->SetPos(0);
		    CEventThreadDlg* pThreadDlg = (CEventThreadDlg*)pInfo->pDialog;
		    pThreadDlg->m_bBegin = FALSE;
		    pThreadDlg->m_bStopped = FALSE;
	    }
	    if(WaitForSingleObject(eventKill.m_hObject, 0) == WAIT_OBJECT_0)
		    bKeepRunning = FALSE;
    }
    ::PostMessage (pInfo->pDialog->GetSafeHwnd(), WM_USER_ENDED, 0, 0);//发送消息
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEventThreadDlg dialog

CEventThreadDlg::CEventThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEventThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEventThreadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hCreated = AfxGetApp()->LoadIcon(IDI_CREATED);
	m_hNotCreated = AfxGetApp()->LoadIcon(IDI_NOTCREATED);
}

void CEventThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEventThreadDlg)
	DDX_Control(pDX, IDC_STATIC_INDICATOR, m_ctrlIndicator);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEventThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CEventThreadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BEGIN, OnBegin)
	ON_BN_CLICKED(IDC_CREATE_THREAD, OnCreateThread)
	ON_BN_CLICKED(IDC_KILL_THREAD, OnKillThread)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_USER_ENDED, OnThreadEnded)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEventThreadDlg message handlers

BOOL CEventThreadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_bCreated = FALSE;
	m_bBegin = FALSE;
	m_bStopped = FALSE;
	m_ctrlIndicator.SetIcon(m_hNotCreated);
	GetDlgItem(IDC_BEGIN)->EnableWindow(false);
	GetDlgItem(IDC_STOP)->EnableWindow(false);
	//m_ctrlProgress.SetPos(70);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEventThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEventThreadDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEventThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEventThreadDlg::OnBegin() //开始
{
	// TODO: Add your control notification handler code here
	if (m_bCreated)
		if (!m_bBegin)
		{
			m_bBegin = TRUE;
			eventBegin.SetEvent();//开始事件对象设置为有信号状态
		}
}

void CEventThreadDlg::OnCreateThread() //创建线程
{
	// TODO: Add your control notification handler code here
	if (m_bCreated)
		MessageBox("线程已经被创建！");
	else
	{
		threadInfo.pDialog = this;
		threadInfo.pProgress = &m_ctrlProgress;
		AfxBeginThread(ThreadProc, &threadInfo);//开启线程
		m_ctrlIndicator.SetIcon(m_hCreated);//更改图标
		m_bCreated = TRUE;
		GetDlgItem(IDC_BEGIN)->EnableWindow(true);
		GetDlgItem(IDC_STOP)->EnableWindow(true);
	}
}

void CEventThreadDlg::OnKillThread() //结束线程
{
	// TODO: Add your control notification handler code here
	if (m_bCreated)
	{
		eventKill.SetEvent();//设置事件
		m_ctrlIndicator.SetIcon(m_hNotCreated);//更改图标
		m_bCreated=false;
		GetDlgItem(IDC_BEGIN)->EnableWindow(false);
		GetDlgItem(IDC_STOP)->EnableWindow(false);
	}
	else
		MessageBox("线程还没有被创建！\n应该先创建线程。");
}

void CEventThreadDlg::OnStop() //停止
{
	// TODO: Add your control notification handler code here
	if (m_bBegin)
		if (!m_bStopped)
		{
			m_bStopped = TRUE;
			eventStop.SetEvent();
		}
}

void CEventThreadDlg::OnThreadEnded() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("辅助线程已经结束！");
}
