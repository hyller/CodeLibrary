// WebBrowseHttpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WebBrowseHttp.h"
#include "WebBrowseHttpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CWebBrowseHttpDlg dialog

CWebBrowseHttpDlg::CWebBrowseHttpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWebBrowseHttpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWebBrowseHttpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWebBrowseHttpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWebBrowseHttpDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_ctrlWeb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWebBrowseHttpDlg, CDialog)
	//{{AFX_MSG_MAP(CWebBrowseHttpDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MICROSOFT, OnMicrosoft)
	ON_BN_CLICKED(IDC_BUTTON_FORWARD, OnButtonForward)
	ON_BN_CLICKED(IDC_BUTTON_REFLESH, OnButtonReflesh)
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebBrowseHttpDlg message handlers

BOOL CWebBrowseHttpDlg::OnInitDialog()
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

void CWebBrowseHttpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWebBrowseHttpDlg::OnPaint() 
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
HCURSOR CWebBrowseHttpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWebBrowseHttpDlg::OnMicrosoft() //MSDN主页按钮
{
	// TODO: Add your control notification handler code here
	m_ctrlWeb.Navigate("msdn.microsoft.com",NULL,NULL,NULL,NULL);//链接微软MSDN	
}
void CWebBrowseHttpDlg::OnButtonForward() //前进按钮
{
	// TODO: Add your control notification handler code here
	m_ctrlWeb.GoForward();//前进	
}

void CWebBrowseHttpDlg::OnButtonReflesh() //刷新按钮
{
	// TODO: Add your control notification handler code here
	m_ctrlWeb.Refresh();//刷新	
}

void CWebBrowseHttpDlg::OnButtonBack() //后退按钮
{
	// TODO: Add your control notification handler code here
	m_ctrlWeb.GoBack();	//后退	
}

BEGIN_EVENTSINK_MAP(CWebBrowseHttpDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CWebBrowseHttpDlg)
	ON_EVENT(CWebBrowseHttpDlg, IDC_EXPLORER1, 105 /* CommandStateChange */, OnCommandStateChangeExplorer1, VTS_I4 VTS_BOOL)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CWebBrowseHttpDlg::OnCommandStateChangeExplorer1(long Command, BOOL Enable) 
{
	// TODO: Add your control notification handler code here
	switch(Command) 
	{ 
	case 1: 
		{
			GetDlgItem(IDC_BUTTON_FORWARD)->EnableWindow(Enable);//前进按钮无效
			break; 
		}
	case 2: 
		{ 
			GetDlgItem(IDC_BUTTON_BACK)->EnableWindow(Enable);//后退按钮无效
			break;
		}
	}	
}
