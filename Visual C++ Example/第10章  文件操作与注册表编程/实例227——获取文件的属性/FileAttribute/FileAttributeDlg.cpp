// FileAttributeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileAttribute.h"
#include "FileAttributeDlg.h"
#include "ExecImageVersion.h"

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
// CFileAttributeDlg dialog

CFileAttributeDlg::CFileAttributeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileAttributeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileAttributeDlg)
	m_strFile = _T("");
	m_strATime = _T("");
	m_strCTime = _T("");
	m_strMTime = _T("");
	m_strSize = _T("");
	m_bArchive = FALSE;
	m_bReadOnly = FALSE;
	m_bSystem = FALSE;
	m_bHidden = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileAttributeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileAttributeDlg)
	DDX_Text(pDX, IDC_EDIT_FILE, m_strFile);
	DDX_Text(pDX, IDC_STATIC_ATIME, m_strATime);
	DDX_Text(pDX, IDC_STATIC_CTIME, m_strCTime);
	DDX_Text(pDX, IDC_STATIC_MTIME, m_strMTime);
	DDX_Text(pDX, IDC_STATIC_SIZE, m_strSize);
	DDX_Check(pDX, IDC_CHECK_ARCHIVE, m_bArchive);
	DDX_Check(pDX, IDC_CHECK_READONLY, m_bReadOnly);
	DDX_Check(pDX, IDC_CHECK_SYSTEM, m_bSystem);
	DDX_Check(pDX, IDC_CHECK_HIDDEN, m_bHidden);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileAttributeDlg, CDialog)
	//{{AFX_MSG_MAP(CFileAttributeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GETATTR, OnGetAttr)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileAttributeDlg message handlers

BOOL CFileAttributeDlg::OnInitDialog()
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

void CFileAttributeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileAttributeDlg::OnPaint() 
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
HCURSOR CFileAttributeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileAttributeDlg::OnGetAttr() 
{
	UpdateData(TRUE);
	CFileStatus rStatus;//结构体
	if(CFile::GetStatus(m_strFile,rStatus))
	{
		m_strSize.Format("%d字节",rStatus.m_size);//文件大小
		m_strCTime = rStatus.m_ctime.Format("%Y年%m月%d日 %H:%M:%S");//创建时间
		m_strMTime = rStatus.m_mtime.Format("%Y年%m月%d日 %H:%M:%S");//修改时间
		m_strATime = rStatus.m_atime.Format("%Y年%m月%d日 %H:%M:%S");//访问时间
		//判断是否只读
		if((rStatus.m_attribute & 0x01) == 0x01)
			m_bReadOnly = TRUE;
		else
			m_bReadOnly = FALSE;
		//判断是否隐藏
		if((rStatus.m_attribute & 0x02) == 0x02)
			m_bHidden = TRUE;
		else
			m_bHidden = FALSE;
		//判断是否存档
		if((rStatus.m_attribute & 0x20) == 0x20)
			m_bArchive = TRUE;
		else
			m_bArchive = FALSE;
		//判断是否是系统文件
		if((rStatus.m_attribute & 0x04) == 0x04)
			m_bSystem = TRUE;
		else
			m_bSystem = FALSE;
		UpdateData(FALSE);//更新显示
	}
}

void CFileAttributeDlg::OnOpen() //打开文件
{
	// TODO: Add your control notification handler code here
	CString strFilter="All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示打开文件对话框
	{
		m_strFile=dlg.GetPathName();
		UpdateData(false);
	}

}
