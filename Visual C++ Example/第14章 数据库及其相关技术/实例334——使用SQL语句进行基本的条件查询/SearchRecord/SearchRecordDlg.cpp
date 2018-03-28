// SearchRecordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SearchRecord.h"
#include "SearchRecordDlg.h"
#include "atlbase.h"
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
// CSearchRecordDlg dialog

CSearchRecordDlg::CSearchRecordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchRecordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchRecordDlg)
	m_strSex = _T("");
	m_strHome = _T("");
	m_bFullMatch = FALSE;
	m_bAnd = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchRecordDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT1, m_strSex);
	DDX_Text(pDX, IDC_EDIT2, m_strHome);
	DDX_Check(pDX, IDC_FULLMATCH, m_bFullMatch);
	DDX_Check(pDX, IDC_ADN, m_bAnd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSearchRecordDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchRecordDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchRecordDlg message handlers

BOOL CSearchRecordDlg::OnInitDialog()
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
	//初始化环境
	::CoInitialize(NULL);
	//创建并打开数据库连接对象
	_variant_t vFieldValue;
	CString strFieldValue;
	m_pCon.CreateInstance(__uuidof(Connection));
	m_pCon->Open("studb","","",NULL);
	//创建并打开记录集对象
	m_pRs.CreateInstance(__uuidof(Recordset));
	m_pRs->Open("select* from stuinfo",m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSearchRecordDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSearchRecordDlg::OnPaint() 
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
HCURSOR CSearchRecordDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSearchRecordDlg::OnSearch() 
{
	// TODO: Add your control notification handler code here
	m_ctlList.ResetContent();									//清空列表框
	UpdateData(TRUE);
	//关闭上一次查询的记录集
	m_pRs->Close();
	//构造SQL检索语句
	CString strSql;
	if(m_bFullMatch)
	{//完全匹配
		if(m_bAnd)
		{//与条件
			strSql.Format("select * from stuinfo where sex = '%s' and home = '%s'",m_strSex,m_strHome);
		}
		else//或条件
		{
			strSql.Format("select * from stuinfo where sex = '%s' or home = '%s'",m_strSex,m_strHome);
		}
	}
	else
	{//模糊查询
		if(m_bAnd)
		{//与条件
			strSql = "select * from stuinfo where sex like '%" + m_strSex + "%'"
				+ "and home like '%" + m_strHome + "%'";
		}
		else
		{
			strSql = "select * from stuinfo where sex like '%" + m_strSex + "%'"
				+ "or home like '%" + m_strHome + "%'";
		}
	}
	//检索
	BSTR bsSql = strSql.AllocSysString();
	m_pRs->Open((CComVariant)bsSql,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

	//将查询结果在列表框中显示出来
	while(VARIANT_FALSE == m_pRs->EndOfFile)
	{
		_variant_t vFieldValue;
		CString strID,strName,strSex,strHome;
		vFieldValue = m_pRs->GetCollect("id");
		strID = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		vFieldValue = m_pRs->GetCollect("name");
		strName = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		vFieldValue = m_pRs->GetCollect("sex");
		strSex = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		vFieldValue = m_pRs->GetCollect("Home");
		strHome = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		CString strItem;
		strItem.Format("学号: %s  姓名: %s  性别: %s  藉贯: %s",strID,strName,strSex,strHome);
		m_ctlList.AddString(strItem);
		m_pRs->MoveNext();
	}	
	
}
