// BaseComboBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaseComboBox.h"
#include "BaseComboBoxDlg.h"

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
// CBaseComboBoxDlg dialog

CBaseComboBoxDlg::CBaseComboBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBaseComboBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBaseComboBoxDlg)
	m_edit = _T("");
	m_static = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaseComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseComboBoxDlg)
	DDX_Control(pDX, IDC_COMBO1, m_ctlCombo);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_STATIC1, m_static);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBaseComboBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CBaseComboBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseComboBoxDlg message handlers

BOOL CBaseComboBoxDlg::OnInitDialog()
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
	m_ctlCombo.SetCurSel(0);									//组合框设置默认选项
	int nselect=m_ctlCombo.GetCurSel();							//获取当前组合框选项的索引
	m_ctlCombo.GetLBText(nselect,m_static);						//静态文本显示当前组合框选项的标题
	UpdateData(false);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBaseComboBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBaseComboBoxDlg::OnPaint() 
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
HCURSOR CBaseComboBoxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBaseComboBoxDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int nselect=m_ctlCombo.GetCurSel();							//获取当前组合框选项的索引
	m_ctlCombo.GetLBText(nselect,m_static);						//静态文本显示当前组合框选项的标题
	UpdateData(false);											//更新显示
}

void CBaseComboBoxDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_edit.IsEmpty())										//如果用户名为空
	{
		AfxMessageBox("添加项不能为空！");
		return;
	}
	if(CB_ERR==m_ctlCombo.FindString(-1,(LPCTSTR)m_edit))//判断该项是否已经在组合框中存在
	{
		m_ctlCombo.AddString(m_edit);								//加入组合框
	}
	else
	{
		AfxMessageBox("该添加项已经存在！");
	}
	m_edit="";											//编辑框置空
	UpdateData(FALSE);
}
