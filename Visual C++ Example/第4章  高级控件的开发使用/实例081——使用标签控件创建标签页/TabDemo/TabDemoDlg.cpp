// TabDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "TabDemoDlg.h"

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
// CTabDemoDlg dialog

CTabDemoDlg::CTabDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabDemoDlg)
	DDX_Control(pDX, IDC_TAB1, m_ctlTab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTabDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CTabDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabDemoDlg message handlers

BOOL CTabDemoDlg::OnInitDialog()
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
	TC_ITEM tcItem;//标签结构
    tcItem.mask=TCIF_TEXT;
    tcItem.pszText="标签1";
    m_ctlTab.InsertItem(0,&tcItem);//添加标签页
    tcItem.pszText="标签2";
    m_ctlTab.InsertItem(1,&tcItem);//添加标签页
	m_ctlTab.SetCurSel(0);//设置标签1为选中状态
	GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);//隐藏静态控件2
	GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);	//隐藏按钮控件2
	CRect rect1,rect2;
	GetClientRect(rect1);
	GetDlgItem(IDC_STATIC1)->GetClientRect(rect2);
	GetDlgItem(IDC_STATIC1)->MoveWindow((rect1.left+50),(rect1.top+80),rect2.Width(),rect2.Height());//移动静态控件1
	GetDlgItem(IDC_BUTTON1)->GetClientRect(rect2);
	GetDlgItem(IDC_BUTTON1)->MoveWindow((rect1.left+80),(rect1.top+120),rect2.Width(),rect2.Height());//移动按钮控件1


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTabDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTabDemoDlg::OnPaint() 
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
HCURSOR CTabDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTabDemoDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("按钮1响应成功！");
	
}

void CTabDemoDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
		AfxMessageBox("按钮2响应成功！");
	
}

void CTabDemoDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int 	i=m_ctlTab.GetCurSel();//所选标签号
	CRect rect1,rect2;
	GetClientRect(rect1);
	switch (i)
	{
		case 0://标签页1被激活
			GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_BUTTON1)->ShowWindow(TRUE);
			GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);	
			GetDlgItem(IDC_STATIC1)->GetClientRect(rect2);
			GetDlgItem(IDC_STATIC1)->MoveWindow((rect1.left+50),(rect1.top+80),rect2.Width(),rect2.Height());
			GetDlgItem(IDC_BUTTON1)->GetClientRect(rect2);
			GetDlgItem(IDC_BUTTON1)->MoveWindow((rect1.left+80),(rect1.top+120),rect2.Width(),rect2.Height());
			break;
		case 1://标签页2被激活
			GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
			GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_BUTTON2)->ShowWindow(TRUE);
			GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);	
			GetDlgItem(IDC_STATIC2)->GetClientRect(rect2);
			GetDlgItem(IDC_STATIC2)->MoveWindow((rect1.left+50),(rect1.top+80),rect2.Width(),rect2.Height());
			GetDlgItem(IDC_BUTTON2)->GetClientRect(rect2);
			GetDlgItem(IDC_BUTTON2)->MoveWindow((rect1.left+80),(rect1.top+120),rect2.Width(),rect2.Height());
			break;
	}
	
	*pResult = 0;
}
