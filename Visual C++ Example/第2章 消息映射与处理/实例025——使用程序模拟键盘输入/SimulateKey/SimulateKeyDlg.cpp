// SimulateKeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimulateKey.h"
#include "SimulateKeyDlg.h"

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
// CSimulateKeyDlg dialog

CSimulateKeyDlg::CSimulateKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimulateKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimulateKeyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimulateKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimulateKeyDlg)
	DDX_Control(pDX, IDC_EDIT1, m_ctlEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSimulateKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CSimulateKeyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INPUT, OnInput)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimulateKeyDlg message handlers

BOOL CSimulateKeyDlg::OnInitDialog()
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

void CSimulateKeyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSimulateKeyDlg::OnPaint() 
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
HCURSOR CSimulateKeyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSimulateKeyDlg::OnInput() 
{
	// TODO: Add your control notification handler code here
	static BOOL bChangeFlag=TRUE;
	if(bChangeFlag)
	{
		SetTimer(1,500,NULL);//设置定时器
		bChangeFlag =bChangeFlag ? FALSE:TRUE;
		GetDlgItem(IDC_INPUT)->SetWindowText("停止输入");//设置按钮文本
	}
	else
	{	GetDlgItem(IDC_INPUT)->SetWindowText("模拟输入");//设置按钮文本
		KillTimer(1);//取消定时器
		bChangeFlag =bChangeFlag ? FALSE:TRUE;
	}
	
}

void CSimulateKeyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	static int count=0;
	BYTE keyname[11]={72,69,76,76,79,32,87,79,82,76,68};//按键序列的虚拟键码
	if(nIDEvent==1)
	{	
		m_ctlEdit.SetFocus();	//编辑框获得输入焦点
		keybd_event(keyname[count],0,0,0); //按键按下
		keybd_event(keyname[count],0,KEYEVENTF_KEYUP,0);//按键抬起
		count++;
		if(count==12)
		{
			m_ctlEdit.SetWindowText("");//情况编辑框
			UpdateData(FALSE);	
			count=0;
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}
