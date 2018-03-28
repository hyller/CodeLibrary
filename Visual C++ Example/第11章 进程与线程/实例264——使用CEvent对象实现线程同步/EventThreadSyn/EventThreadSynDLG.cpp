// EventThreadSynDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EventThreadSyn.h"
#include "EventThreadSynDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
CEvent g_Event;	//事件对象
char g_str[] = "how to use the CEvent synchronization classes";
UINT ThreadFun(LPVOID  pParam)
{
	WaitForSingleObject(g_Event.m_hObject, INFINITE);			//无限期等待
	//获取主窗口指针
	CWnd* pMainWnd = AfxGetMainWnd();
	if(NULL == pParam)
	{
		//如果参数为空，提示错误
		AfxMessageBox("参数传递出错，线程终止!", MB_OK|MB_ICONERROR);
		AfxEndThread(2);
	}
	//强制转换类型
	char* pString = (char*)pParam;
	//将小写字母转换为大写字母
	while(*pString)
	{
		if(*pString >= 'a' && *pString <= 'z')
		{
			*pString -= 32;
		}
		pString++;
	}
	//字符串转换完成，设置事件对象变成有信号状态
	g_Event.SetEvent();
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
// CEventThreadSynDlg dialog

CEventThreadSynDlg::CEventThreadSynDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEventThreadSynDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEventThreadSynDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEventThreadSynDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEventThreadSynDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEventThreadSynDlg, CDialog)
	//{{AFX_MSG_MAP(CEventThreadSynDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EVENT, OnEvent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEventThreadSynDlg message handlers

BOOL CEventThreadSynDlg::OnInitDialog()
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

void CEventThreadSynDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEventThreadSynDlg::OnPaint() 
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
HCURSOR CEventThreadSynDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEventThreadSynDlg::OnEvent() //开始
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EVENT)->EnableWindow(false);
	char* temp=(char*)g_str;
	int i=0;
	g_Event.SetEvent();									//设置为有信号状态
	WaitForSingleObject(g_Event.m_hObject, INFINITE);			//无限期等待
	while(*temp)//模拟读文件数据
	{
		if(i==5)
		{
			char* pStr = g_str;
			//产生一个工作线程来转换字符串
			AfxBeginThread(ThreadFun, (LPVOID)pStr);
		}
		if(i==7)
		{ 
			g_str[i]='7';	//修改字符
		}
		Sleep(10);//模拟耗时计算
		temp++;
		i++;
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText(CString(g_str));
	g_Event.SetEvent();									//设置为有信号状态
	WaitForSingleObject(g_Event.m_hObject, INFINITE);			//无限期等待
	GetDlgItem(IDC_EDIT2)->SetWindowText(CString(g_str));	
}
