// BaseEditBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaseEditBox.h"
#include "BaseEditBoxDlg.h"

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
// CBaseEditBoxDlg dialog

CBaseEditBoxDlg::CBaseEditBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBaseEditBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBaseEditBoxDlg)
	m_user = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaseEditBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseEditBoxDlg)
	DDX_Text(pDX, IDC_USER, m_user);
	DDV_MaxChars(pDX, m_user, 12);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDV_MaxChars(pDX, m_password, 12);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBaseEditBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CBaseEditBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseEditBoxDlg message handlers

BOOL CBaseEditBoxDlg::OnInitDialog()
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

void CBaseEditBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBaseEditBoxDlg::OnPaint() 
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
HCURSOR CBaseEditBoxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBaseEditBoxDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);										//获取编辑控件的值
	if((m_user.IsEmpty())||(m_password.IsEmpty()))				//用户名、密码是否为空
	{
		AfxMessageBox("用户名、密码不能为空！");
		return;
	}
	CString str;
	str="用户："+m_user+" 密码："+m_password+"\r\n";
	CEdit *pEdit=(CEdit*)GetDlgItem(IDC_USERLIST);					//获取多行编辑控件窗口指针
	pEdit->SetSel(0,-1); 										//选择全部文本
	int nStart,nEnd;
	pEdit->GetSel(nStart,nEnd);
	pEdit->SetSel(nEnd,nEnd); 							//将插入符定位到最后的一个字符
	pEdit->ReplaceSel(str);									//插入需要的文本
	m_user=m_password="";
	UpdateData(FALSE);	//更新显示编辑控件内容
	GetDlgItem(IDC_USER)->SetFocus();//设置用户名编辑框输入焦点
}

void CBaseEditBoxDlg::OnChangeUser() 
{
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);										//获取编辑控件的值
	m_password=m_user;
	UpdateData(FALSE);	//更新显示编辑控件内容	
	
}
