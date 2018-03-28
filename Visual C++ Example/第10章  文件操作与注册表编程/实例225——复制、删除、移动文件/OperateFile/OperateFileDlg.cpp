// OperateFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OperateFile.h"
#include "OperateFileDlg.h"

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
// COperateFileDlg dialog

COperateFileDlg::COperateFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COperateFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COperateFileDlg)
	m_strSrcFile = _T("");
	m_strDstFile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COperateFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COperateFileDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strSrcFile);
	DDX_Text(pDX, IDC_EDIT2, m_strDstFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COperateFileDlg, CDialog)
	//{{AFX_MSG_MAP(COperateFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_OPEN1, OnOpen1)
	ON_BN_CLICKED(IDC_MOVE, OnMove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COperateFileDlg message handlers

BOOL COperateFileDlg::OnInitDialog()
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

void COperateFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COperateFileDlg::OnPaint() 
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
HCURSOR COperateFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COperateFileDlg::OnCopy() //复制
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strMsg;
	if(CopyFile(m_strSrcFile,m_strDstFile,FALSE))
		strMsg.Format("文件%s已经拷贝到文件%s了！",m_strSrcFile,m_strDstFile);
	else
		strMsg.Format("文件%s拷贝到文件%s失败！",m_strSrcFile,m_strDstFile);
	AfxMessageBox(strMsg);
}

void COperateFileDlg::OnDelete() //删除
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strMsg;
	if(DeleteFile(m_strSrcFile))
		strMsg.Format("删除文件%s成功！",m_strSrcFile);
	else
		strMsg.Format("删除文件%s失败！",m_strSrcFile);
	AfxMessageBox(strMsg);
}

void COperateFileDlg::OnOpen1() 
{
	// TODO: Add your control notification handler code here
	CString strFilter="All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示打开文件对话框
	{
		m_strSrcFile=dlg.GetPathName();
		UpdateData(false);
	}
}


void COperateFileDlg::OnMove() //移动
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strMsg;
	if(MoveFile(m_strSrcFile,m_strDstFile))
		strMsg.Format("文件%s已经移动到文件%s了！",m_strSrcFile,m_strDstFile);
	else
		strMsg.Format("文件%s移动到文件%s失败！",m_strSrcFile,m_strDstFile);
	AfxMessageBox(strMsg);
}
