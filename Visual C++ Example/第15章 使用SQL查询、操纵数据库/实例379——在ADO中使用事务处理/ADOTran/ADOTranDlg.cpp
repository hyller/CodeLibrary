// ADOTranDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOTran.h"
#include "ADOTranDlg.h"

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
// CADOTranDlg dialog

CADOTranDlg::CADOTranDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOTranDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADOTranDlg)
	m_CNO = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CADOTranDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOTranDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT2, m_CNO);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOTranDlg, CDialog)
	//{{AFX_MSG_MAP(CADOTranDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOTranDlg message handlers

BOOL CADOTranDlg::OnInitDialog()
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
		::CoInitialize(NULL); 										//初始化COM环境
	HRESULT hr; 
	try
	{
		hr=m_pConnection.CreateInstance(__uuidof(Connection));
		if(SUCCEEDED(hr))
		{
			m_pConnection->ConnectionString="File Name=LinkDatabase.udl";
			m_pConnection->ConnectionTimeout=20;//等待连接的时间为20s
			hr=m_pConnection->Open("","","",adConnectUnspecified);
			if(FAILED(hr))
			{
				AfxMessageBox("打开数据库失败！");
				return false;
			}
		}
		else
		{
			AfxMessageBox("创建连接对象失败！");
			return false;
		}
	}
	catch(_com_error e)
	{
		AfxMessageBox("数据库连接失败!");
		return FALSE;
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOTranDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CADOTranDlg::OnPaint() 
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
HCURSOR CADOTranDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CADOTranDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_ctlList.ResetContent();//清空列表框
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	_variant_t RecordsAffected; 
	CString vSQL;
	vSQL.Format("update COURSE set CNO='%s' where CNO='C04'",m_CNO);
	try
	{
		m_pConnection->BeginTrans();//开始事务
		m_pConnection->Execute(_bstr_t(vSQL),&RecordsAffected,adCmdText);//更新COURSE表
		vSQL.Format("update SC set CNO='%s' where CNO='C04'",m_CNO);
		m_pConnection->Execute(_bstr_t(vSQL),&RecordsAffected,adCmdText);//更新SC表
		m_pConnection->CommitTrans();//提交事务	
	}
	catch(_com_error e)
	{
		m_pConnection->RollbackTrans();//回滚事务
		AfxMessageBox(e.ErrorMessage());
	}
	vSQL.Format("SELECT * FROM SC WHERE CNO='%s'",m_CNO);
	m_pRecordset=m_pConnection->Execute(_bstr_t(vSQL),&RecordsAffected,adCmdText); 
	if((m_pRecordset->BOF)&&(m_pRecordset->adoEOF))
	{
		AfxMessageBox("得到的记录集为空!");
		m_pRecordset->Close();
		return;
	}
	while(VARIANT_FALSE ==m_pRecordset->adoEOF)//将得到的记录集添加到列表框中
	{
		_variant_t vFieldValue;
		CString strID,strCNO,strGrade;
		vFieldValue = m_pRecordset->GetCollect("SNO");
		strID = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		vFieldValue = m_pRecordset->GetCollect("CNO");
		strCNO = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		vFieldValue = m_pRecordset->GetCollect("GRADE");
		strGrade = (char*)_bstr_t(vFieldValue);
		vFieldValue.Clear();
		CString strItem;
		strItem.Format("学号:%s课程号:%s成绩:%s",strID,strCNO,strGrade);
		m_ctlList.AddString(strItem);
		m_pRecordset->MoveNext();//下一条记录
		}
	
}
