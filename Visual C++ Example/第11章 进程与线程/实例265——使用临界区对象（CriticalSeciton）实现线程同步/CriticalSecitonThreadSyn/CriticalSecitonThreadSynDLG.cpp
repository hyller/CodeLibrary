// CriticalSecitonThreadSynDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CriticalSecitonThreadSyn.h"
#include "CriticalSecitonThreadSynDlg.h"
#include <afxmt.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
CCriticalSection g_cs;		//临界区对象
int g_data = 0;					//全局资源
static HANDLE  g_ReadHnd;//读线程句柄
static HANDLE  g_WriteHnd;//写线程句柄
//用于写数据的线程,即第一个线程的回调函数
UINT ThreadProcWrite(LPVOID param)
{
	CEdit *pedit=(CEdit*)param;
	while(true)
	{
		CString str;
		g_cs.Lock();		//临界区锁定共享资源
		g_data++;			//数据加1
		str.Format("%d", g_data);
		pedit->SetWindowText(str);//编辑框显示数据
		Sleep(1000);		//阻塞线程一定时间
		g_cs.Unlock();		//临界区解锁
	}
	return 0;
}
//用于读数据的线程,即第二个线程的回调函数
UINT ThreadProcRead(LPVOID param)
{
	UINT retval;
	CEdit *pedit=(CEdit*)param;
	while(true)
	{
		g_cs.Lock();		//锁定共享资源
		retval = g_data;	//读数据
		g_cs.Unlock();		//解锁
		CString str;
		str.Format("%d", retval);
		pedit->SetWindowText(str);//编辑框显示数据

	
	}
	return 0;
}



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
// CCriticalSecitonThreadSynDlg dialog

CCriticalSecitonThreadSynDlg::CCriticalSecitonThreadSynDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCriticalSecitonThreadSynDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCriticalSecitonThreadSynDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCriticalSecitonThreadSynDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCriticalSecitonThreadSynDlg)
	DDX_Control(pDX, IDC_EDIT2, m_ReadEdit);
	DDX_Control(pDX, IDC_EDIT1, m_WriteEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCriticalSecitonThreadSynDlg, CDialog)
	//{{AFX_MSG_MAP(CCriticalSecitonThreadSynDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STARW, OnStarw)
	ON_BN_CLICKED(IDC_STOPR, OnStopr)
	ON_BN_CLICKED(IDC_STOPW, OnStopw)
	ON_BN_CLICKED(IDC_STARR, OnStarr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCriticalSecitonThreadSynDlg message handlers

BOOL CCriticalSecitonThreadSynDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCriticalSecitonThreadSynDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCriticalSecitonThreadSynDlg::OnPaint() 
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
HCURSOR CCriticalSecitonThreadSynDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCriticalSecitonThreadSynDlg::OnStarw() //启动写线程
{
	// TODO: Add your control notification handler code here
	CWinThread* pThread;
	pThread = AfxBeginThread(ThreadProcWrite, &m_WriteEdit);//开始写线程
	g_WriteHnd = pThread->m_hThread;//获取写线程句柄
	GetDlgItem(IDC_STARW)->EnableWindow(false);//启动按钮无效
	GetDlgItem(IDC_STOPW)->EnableWindow(true);//开始按钮生效	
}

void CCriticalSecitonThreadSynDlg::OnStopr() //销毁读线程
{
	// TODO: Add your control notification handler code here

	g_cs.Lock();//锁定资源
	TerminateThread(g_ReadHnd, 0);//终止读线程
	g_cs.Unlock();//释放资源
	m_ReadEdit.SetWindowText("终止读线程");
	GetDlgItem(IDC_STARR)->EnableWindow(true);//启动按钮生效
	GetDlgItem(IDC_STOPR)->EnableWindow(false);//停止按钮无效	
}

void CCriticalSecitonThreadSynDlg::OnStopw() //销毁写线程
{
	// TODO: Add your control notification handler code here

	g_cs.Lock();//锁定资源
	TerminateThread(g_WriteHnd, 0);//终止写线程
	g_cs.Unlock();//释放资源	
	m_WriteEdit.SetWindowText("终止写线程");
	GetDlgItem(IDC_STARW)->EnableWindow(true);//启动按钮生效
	GetDlgItem(IDC_STOPW)->EnableWindow(false);//停止按钮无效	
}

void CCriticalSecitonThreadSynDlg::OnStarr() //启动读线程
{
	// TODO: Add your control notification handler code here
	CWinThread* pThread;
	pThread = AfxBeginThread(ThreadProcRead, &m_ReadEdit);//开始读线程
	g_ReadHnd = pThread->m_hThread;//获取写线程句柄
	GetDlgItem(IDC_STARR)->EnableWindow(false);//启动按钮无效
	GetDlgItem(IDC_STOPR)->EnableWindow(true);//停止按钮生效		
}
