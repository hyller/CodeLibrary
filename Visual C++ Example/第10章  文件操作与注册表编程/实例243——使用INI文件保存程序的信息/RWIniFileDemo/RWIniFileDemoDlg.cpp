// RWIniFileDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RWIniFileDemo.h"
#include "RWIniFileDemoDlg.h"

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
// CRWIniFileDemoDlg dialog

CRWIniFileDemoDlg::CRWIniFileDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRWIniFileDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRWIniFileDemoDlg)
	m_bookname = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRWIniFileDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRWIniFileDemoDlg)
	DDX_Control(pDX, IDC_LIST1, m_booklist);
	DDX_Text(pDX, IDC_EDIT1, m_bookname);
	DDV_MaxChars(pDX, m_bookname, 30);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRWIniFileDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CRWIniFileDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_WRITE, OnWrite)
	ON_BN_CLICKED(IDC_READ, OnRead)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRWIniFileDemoDlg message handlers

BOOL CRWIniFileDemoDlg::OnInitDialog()
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

void CRWIniFileDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRWIniFileDemoDlg::OnPaint() 
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
HCURSOR CRWIniFileDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRWIniFileDemoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_bookname.IsEmpty())//编辑框为空
	{
		AfxMessageBox("添加的书名不能为空！");
		return;
	}
	m_booklist.AddString(m_bookname);//加入列表框
	m_bookname="";
	UpdateData(false);//清空编辑框
}


void CRWIniFileDemoDlg::OnWrite() //写INI文件“Book.ini”
{
	// TODO: Add your control notification handler code here
	//获得列表框中图书的数量
	int nCount = m_booklist.GetCount();
	for(int i=0;i<nCount;i++)
	{
		//将书名写入ini文件
		CString strKeyName,strBookName;
		m_booklist.GetText(i,strBookName);
		strKeyName.Format("Name%d",i);
		::WritePrivateProfileString("BookName",strKeyName,strBookName,".\\Book.ini");
	}
	//将图书的数量写入ini文件
	CString strCount;
	strCount.Format("%d",nCount);
	::WritePrivateProfileString("BookCount","Count",strCount,".\\Book.ini");
	
}

void CRWIniFileDemoDlg::OnRead() //读INI文件“Book.ini”
{
	// TODO: Add your control notification handler code here
	m_booklist.ResetContent();//清除列表框中的所有行
	//从ini文件中获得图书数量
	int nCount =::GetPrivateProfileInt("BookCount","Count",0,".\\Book.ini");
	if(nCount)
	{
		for(int i=0;i<nCount;i++)
		{
			//从ini文件中获得书名，并加到列表框中
			CString strKeyName,strBookName;
			strKeyName.Format("Name%d",i);
			::GetPrivateProfileString("BookName",strKeyName,NULL,strBookName.GetBuffer(128),128,".\\Book.ini");
			m_booklist.AddString(strBookName);
		}
	}	
}
