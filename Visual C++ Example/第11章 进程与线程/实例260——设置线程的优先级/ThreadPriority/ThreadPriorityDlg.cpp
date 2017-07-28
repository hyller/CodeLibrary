// ThreadPriorityDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ThreadPriority.h"
#include "ThreadPriorityDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static UINT g_uCount1 = 0;
static UINT g_uCount2 = 0;
static UINT g_uCount3 = 0;
static UINT g_uCount4 = 0;          // 用来控制各个线程的循环计数
static UINT g_uCount5 = 0;
static UINT g_uCount6 = 0;
static UINT g_uCount7 = 0;

CProgressCtrl* g_ptrProgress1 = NULL;
CProgressCtrl* g_ptrProgress2 = NULL;
CProgressCtrl* g_ptrProgress3 = NULL;     //用来保存指向各个进度条的指针
CProgressCtrl* g_ptrProgress4 = NULL;
CProgressCtrl* g_ptrProgress5 = NULL;
CProgressCtrl* g_ptrProgress6 = NULL;
CProgressCtrl* g_ptrProgress7 = NULL;

UINT Thread1(LPVOID)//线程1
{
	while (g_uCount1 < 100000000 )
	{
		g_uCount1++;
		if (g_uCount1 % 10000000 == 0)
		{
			if (g_ptrProgress1)
			{
				g_ptrProgress1->SetPos(g_uCount1/1000000);//设定进度条
			}	
		}	
	}
	return 0;
}

UINT Thread2(LPVOID)
{
	while (g_uCount2 < 100000000 )
	{
		g_uCount2++;
		if (g_uCount2 % 10000000 == 0)
		{
			if (g_ptrProgress2)
			{
				g_ptrProgress2->SetPos(g_uCount2/1000000);
			}	
		}	
	}

	return 0;
}

UINT Thread3(LPVOID)
{
	while (g_uCount3 < 100000000 )
	{
		g_uCount3++;
		if (g_uCount3 % 10000000 == 0)
		{
			if (g_ptrProgress3)
			{
				g_ptrProgress3->SetPos(g_uCount3/1000000);
			}	
		}	
	}

	return 0;
}

UINT Thread4(LPVOID)
{
	while (g_uCount4 < 100000000 )
	{
		g_uCount4++;
		if (g_uCount4 % 10000000 == 0)
		{
			if (g_ptrProgress4)
			{
				g_ptrProgress4->SetPos(g_uCount4/1000000);
			}	
		}	
	}

	return 0;
}

UINT Thread5(LPVOID)
{
	while (g_uCount5 < 100000000 )
	{
		g_uCount5++;
		if (g_uCount5 % 10000000 == 0)
		{
			if (g_ptrProgress5)
			{
				g_ptrProgress5->SetPos(g_uCount5/1000000);
			}	
		}	
	}

	return 0;
}

UINT Thread6(LPVOID)
{
	while (g_uCount6 < 100000000 )
	{
		g_uCount6++;
		if (g_uCount6 % 10000000 == 0)
		{
			if (g_ptrProgress6)
			{
				g_ptrProgress6->SetPos(g_uCount6/1000000);
			}	
		}	
	}

	return 0;
}

UINT Thread7(LPVOID)
{
	while (g_uCount7 < 100000000 )
	{
		g_uCount7++;
		if (g_uCount7 % 10000000 == 0)
		{
			if (g_ptrProgress7)
			{
				g_ptrProgress7->SetPos(g_uCount7/1000000);
			}	
		}	
	}

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
// CThreadPriorityDlg dialog

CThreadPriorityDlg::CThreadPriorityDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadPriorityDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadPriorityDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadPriorityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadPriorityDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadPriorityDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadPriorityDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadPriorityDlg message handlers

BOOL CThreadPriorityDlg::OnInitDialog()
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
	g_ptrProgress1 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
	g_ptrProgress2 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS2);
	g_ptrProgress3 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS3);
	g_ptrProgress4 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS4);
	g_ptrProgress5 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS5);
	g_ptrProgress6 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS6);
	g_ptrProgress7 = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS7);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CThreadPriorityDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThreadPriorityDlg::OnPaint() 
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
HCURSOR CThreadPriorityDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CThreadPriorityDlg::OnStart() 
{
	
	//创建7个不同优先级别的线程
	AfxBeginThread(Thread1,NULL,THREAD_PRIORITY_TIME_CRITICAL);	
	AfxBeginThread(Thread2,NULL,THREAD_PRIORITY_HIGHEST);	
	AfxBeginThread(Thread3,NULL,THREAD_PRIORITY_ABOVE_NORMAL);	
	AfxBeginThread(Thread4,NULL,THREAD_PRIORITY_NORMAL);	
	AfxBeginThread(Thread5,NULL,THREAD_PRIORITY_BELOW_NORMAL);	
	AfxBeginThread(Thread6,NULL,THREAD_PRIORITY_LOWEST);	
	AfxBeginThread(Thread7,NULL,THREAD_PRIORITY_IDLE);	
}
