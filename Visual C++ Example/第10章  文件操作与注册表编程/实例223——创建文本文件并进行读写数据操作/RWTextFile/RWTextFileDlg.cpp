// RWTextFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RWTextFile.h"
#include "RWTextFileDlg.h"

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
// CRWTextFileDlg dialog

CRWTextFileDlg::CRWTextFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRWTextFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRWTextFileDlg)
	m_strWrite = _T("");
	m_strRead = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRWTextFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRWTextFileDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strWrite);
	DDX_Text(pDX, IDC_EDIT2, m_strRead);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRWTextFileDlg, CDialog)
	//{{AFX_MSG_MAP(CRWTextFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_READ, OnRead)
	ON_BN_CLICKED(IDC_WRITE, OnWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRWTextFileDlg message handlers

BOOL CRWTextFileDlg::OnInitDialog()
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

void CRWTextFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRWTextFileDlg::OnPaint() 
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
HCURSOR CRWTextFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRWTextFileDlg::OnRead() 
{
	// TODO: Add your control notification handler code here
	CString strFilter,fileName;
	strFilter="Text Files(*.txt)|*.txt||";	
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示打开文件对话框
	{
	fileName=dlg.GetPathName();
	CFile openfile(fileName,CFile::modeRead);				//构造CFile对象
	int length=openfile.GetLength();						//获取文件长度
	char *strText;
	strText=new char[length];	
	openfile.Read(strText,length);
	openfile.Close();										//关闭文件
	m_strRead=(CString)strText;
	delete [] strText;
	UpdateData(false);
	}
}

void CRWTextFileDlg::OnWrite() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CString strFilter,fileName,strText;
	strFilter="Text Files(*.txt)|*.txt||";
	CFileDialog dlg(FALSE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )								//显示保存文件对话框
	{
		fileName=dlg.GetPathName();
		CFile savefile(fileName,CFile::modeCreate|CFile::modeWrite);		//构造CFile对象
		savefile.Write(m_strWrite,m_strWrite.GetLength());							//写文件数据
		savefile.Close();										//关闭文件
	}
		
}
