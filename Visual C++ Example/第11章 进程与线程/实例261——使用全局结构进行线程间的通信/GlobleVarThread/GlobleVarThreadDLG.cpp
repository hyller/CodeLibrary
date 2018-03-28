// GlobleVarThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GlobleVarThread.h"
#include "GlobleVarThreadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
volatile int SpeedControl;//定义全局变量
/////////////////////////////////////////////////////////////////////////////
UINT ThreadFunc(LPVOID lpParam)									//线程函数
{
  CEdit* pInfo=(CEdit*)lpParam;							//线程函数参数
  int i=0;
  CString str;
  while(true)
  {
	  if(SpeedControl==1)//低速计数
	  {
		  str.Format("%d",i);
		  pInfo->SetWindowText(str);
		  Sleep(2000);
		  i++;
	  }
	  if(SpeedControl==2)//高速计数
	  {
		  str.Format("%d",i);
		  pInfo->SetWindowText(str);
		  Sleep(250);
		  i++;
	  }
	  if(SpeedControl==0)//暂停
	  {
		  str.Format("%d",i);
		  pInfo->SetWindowText(str);
		  Sleep(250);
	  }
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
// CGlobleVarThreadDlg dialog

CGlobleVarThreadDlg::CGlobleVarThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGlobleVarThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGlobleVarThreadDlg)
	m_radio = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGlobleVarThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGlobleVarThreadDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Num);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGlobleVarThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CGlobleVarThreadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STAR, OnStar)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlobleVarThreadDlg message handlers

BOOL CGlobleVarThreadDlg::OnInitDialog()
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
	GetDlgItem(IDC_RADIO1)->EnableWindow(false);//单选按钮无效
	GetDlgItem(IDC_RADIO2)->EnableWindow(false);
	GetDlgItem(IDC_RADIO3)->EnableWindow(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGlobleVarThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGlobleVarThreadDlg::OnPaint() 
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
HCURSOR CGlobleVarThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGlobleVarThreadDlg::OnStar() 
{
	// TODO: Add your control notification handler code here
	SpeedControl=1;
	GetDlgItem(IDC_RADIO1)->EnableWindow(true);//单选按钮生效
	GetDlgItem(IDC_RADIO2)->EnableWindow(true);
	GetDlgItem(IDC_RADIO3)->EnableWindow(true);
	GetDlgItem(IDC_STAR)->EnableWindow(false);//开始按钮无效
	CWinThread* pThread=AfxBeginThread(ThreadFunc,&m_Num);//创建新的线程并开始执行	
}

void CGlobleVarThreadDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	SpeedControl=1;//低速
}

void CGlobleVarThreadDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	SpeedControl=2;//高速
}

void CGlobleVarThreadDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	SpeedControl=0;//暂停
}

