// ADODataBase2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADODataBase2.h"
#include "ADODataBase2Dlg.h"

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
// CADODataBase2Dlg dialog

CADODataBase2Dlg::CADODataBase2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADODataBase2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADODataBase2Dlg)
	m_strNumber = _T("");
	m_strName = _T("");
	m_strSex = _T("");
	m_strAddress = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADODataBase2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADODataBase2Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_strNumber);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	DDX_Text(pDX, IDC_EDIT3, m_strSex);
	DDX_Text(pDX, IDC_EDIT4, m_strAddress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADODataBase2Dlg, CDialog)
	//{{AFX_MSG_MAP(CADODataBase2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODataBase2Dlg message handlers

BOOL CADODataBase2Dlg::OnInitDialog()
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
	AfxEnableControlContainer();
	HRESULT hr; 
	try 
	{ 
		hr = m_pConnection.CreateInstance("ADODB.Connection");			//创建Connection对象 
		if(SUCCEEDED(hr)) 
		{ 
			hr = m_pConnection->Open("student","","",adModeUnknown);//连接数据库 
		}
	}
	catch(_com_error e)										//捕捉异常 
	{ 
		CString errormessage; 
		errormessage.Format("连接数据库失败!\r\n错误信息:%s",e.ErrorMessage()); 
		AfxMessageBox(errormessage);								//显示错误信息 
	} 
	
	_variant_t RecordsAffected; 
	m_pConnection->Execute("CREATE TABLE studentinfo(stuNo TEXT,stuName TEXT,stuSex TEXT,stuAddress TEXT)",&RecordsAffected,adCmdText); 						//创建表
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADODataBase2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CADODataBase2Dlg::OnPaint() 
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
HCURSOR CADODataBase2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CADODataBase2Dlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	_variant_t RecordsAffected; 
	UpdateData(true);
	if(m_strNumber.IsEmpty())
	{
		AfxMessageBox("学号不能为空！");
		return;
	}
	CString strSQL; 
	strSQL.Format("INSERT INTO studentinfo(stuNo,stuName,stuSex,stuAddress)VALUES ('%s', '%s','%s','%s')",m_strNumber,m_strName,m_strSex,m_strAddress); 
	m_pConnection->Execute((_bstr_t)strSQL,&RecordsAffected,adCmdText); //添加记录
	m_strNumber=m_strName=m_strSex=m_strAddress="";
	UpdateData(false);		
}
