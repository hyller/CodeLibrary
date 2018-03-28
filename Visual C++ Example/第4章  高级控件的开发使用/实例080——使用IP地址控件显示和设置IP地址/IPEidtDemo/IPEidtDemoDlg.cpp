// IPEidtDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IPEidtDemo.h"
#include "IPEidtDemoDlg.h"

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
// CIPEidtDemoDlg dialog

CIPEidtDemoDlg::CIPEidtDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIPEidtDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIPEidtDemoDlg)
	m_ipstr = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIPEidtDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIPEidtDemoDlg)
	DDX_Control(pDX, IDC_IPADDRESS1, m_ctlIpAddress);
	DDX_Text(pDX, IDC_STATIC1, m_ipstr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIPEidtDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CIPEidtDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_BN_CLICKED(IDC_SET, OnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIPEidtDemoDlg message handlers

BOOL CIPEidtDemoDlg::OnInitDialog()
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
	GetDlgItem(IDC_RESET)->EnableWindow(false);//重置按钮无效
	m_ctlIpAddress.SetWindowText("192.188.2.1");//设置默认Ip
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIPEidtDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIPEidtDemoDlg::OnPaint() 
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
HCURSOR CIPEidtDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CIPEidtDemoDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	m_ctlIpAddress.EnableWindow(true);//IP控件可以编辑
	m_ctlIpAddress.ClearAddress();//清空IP控件
	m_ctlIpAddress.SetFieldFocus(0);//设置输入焦点
	GetDlgItem(IDC_RESET)->EnableWindow(false);//重置按钮无效
	GetDlgItem(IDC_SET)->EnableWindow(true);//设置按钮生效
	
}

void CIPEidtDemoDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);

	if(m_ctlIpAddress.IsBlank())   //判断是否为空 
	{
		AfxMessageBox("IP地址为空!");
		return;
	}  

	BYTE nField0,nField1,nField2,nField3;
	if(m_ctlIpAddress.GetAddress(nField0,nField1,nField2,nField3) !=4)
	{
		AfxMessageBox("你输入的IP地址不完整!");
		m_ctlIpAddress.SetFieldFocus(0);
		return;
	}
	m_ctlIpAddress.EnableWindow(false);//IP控件不能编辑
	m_ipstr.Format("IP地址为：%d.%d.%d.%d",nField0,nField1,nField2,nField3);
	UpdateData(false);
	GetDlgItem(IDC_RESET)->EnableWindow(true);//重置按钮生效
	GetDlgItem(IDC_SET)->EnableWindow(false);//设置按钮无效
}
