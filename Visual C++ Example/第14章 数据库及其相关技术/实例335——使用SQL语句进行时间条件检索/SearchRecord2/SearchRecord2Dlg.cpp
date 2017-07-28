// SearchRecord2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SearchRecord2.h"
#include "SearchRecord2Dlg.h"
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
// CSearchRecord2Dlg dialog

CSearchRecord2Dlg::CSearchRecord2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchRecord2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchRecord2Dlg)
	m_tmBegin = 0;
	m_tmEnd = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchRecord2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchRecord2Dlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tmBegin);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_tmEnd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSearchRecord2Dlg, CDialog)
	//{{AFX_MSG_MAP(CSearchRecord2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchRecord2Dlg message handlers

BOOL CSearchRecord2Dlg::OnInitDialog()
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

void CSearchRecord2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSearchRecord2Dlg::OnPaint() 
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
HCURSOR CSearchRecord2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSearchRecord2Dlg::OnSearch() 
{
	// TODO: Add your control notification handler code here
	m_ctlList.ResetContent();									//清空列表框
	UpdateData(TRUE);
	//关闭上一次查询的记录集
	m_pRs->Close();
		//格式化时间
	CString strBegin,strEnd;
	strBegin = m_tmBegin.Format("%Y-%m-%d %H:%M:%S");
	strEnd = m_tmEnd.Format("%Y-%m-%d %H:%M:%S");
	//构造SQL检索语句
	CString strSql;
	strSql.Format("select * from stuinfo where entertime >= CDate('%s') and entertime <= CDate('%s')",strBegin,strEnd);
	//检索
	BSTR bsSql = strSql.AllocSysString();
	m_pRs->Open((CComVariant)bsSql,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);

	//将查询结果在列表框中显示出来
	while(VARIANT_FALSE == m_pRs->EndOfFile)
	{
		_variant_t vFieldValue;
		CString strID,strName,strDate;
		vFieldValue = m_pRs->GetCollect("id");
		strID = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		vFieldValue = m_pRs->GetCollect("name");
		strName = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();	
		vFieldValue = m_pRs->GetCollect("entertime");
		strDate = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		CString strItem;
		strItem.Format("学号: %s  姓名: %s  入校时间: %s",strID,strName,strDate);
		m_ctlList.AddString(strItem);
		m_pRs->MoveNext();
	}
}

void CSearchRecord2Dlg::OnDestroy() 
{
	//关闭记录和连接
	m_pRs->Close();
	m_pCon->Close();
	//释放环境
	::CoUninitialize();
	CDialog::OnDestroy();
	// TODO: Add your message handler code here
	
}
