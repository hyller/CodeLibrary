// MouseInfoTipDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MouseInfoTip.h"
#include "MouseInfoTipDlg.h"

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
// CMouseInfoTipDlg dialog

CMouseInfoTipDlg::CMouseInfoTipDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMouseInfoTipDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMouseInfoTipDlg)
	m_sName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMouseInfoTipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMouseInfoTipDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT1, m_sName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMouseInfoTipDlg, CDialog)
	//{{AFX_MSG_MAP(CMouseInfoTipDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseInfoTipDlg message handlers

BOOL CMouseInfoTipDlg::OnInitDialog()
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
	m_toolTip.Create( this );//创建提示框对象
	CStringArray straInfo;
	//“添加”按钮提示框
	straInfo.RemoveAll();
	straInfo.Add( "向列表框中添加记录" );
	m_toolTip.AddControlInfo( IDC_ADD, straInfo, RGB(220,174,208), RGB( 0,0,162) );
	//退出按钮提示框
	straInfo.RemoveAll();
	straInfo.Add( "关闭窗口" );
	m_toolTip.AddControlInfo( IDCANCEL, straInfo, RGB(220,174,208), RGB( 0,0,162) );
	//编辑框提示框
	straInfo.RemoveAll();
	straInfo.Add( "输入书籍名称" );
	m_toolTip.AddControlInfo( IDC_EDIT1, straInfo, RGB(220,174,208), RGB( 0,0,162) );
	//列表框提示框
	straInfo.RemoveAll();
	straInfo.Add( "显示添加的图书记录" );
	straInfo.Add( "实现自动排序:" );
	m_toolTip.AddControlInfo( IDC_LIST1, straInfo, RGB(220,174,208), RGB( 0,0,162)  );
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMouseInfoTipDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMouseInfoTipDlg::OnPaint() 
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
HCURSOR CMouseInfoTipDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMouseInfoTipDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(!m_sName.IsEmpty())
	{
		m_ctlList.AddString(m_sName);
		m_sName="";
		UpdateData(false);
	}

}

BOOL CMouseInfoTipDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if( pMsg->message == WM_MOUSEMOVE )//鼠标移动
	{
		POINT pt = pMsg->pt;	
		ScreenToClient( &pt );//转换为客户区坐标
		m_toolTip.ShowToolTip( (CPoint)pt );//显示提示框
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}
