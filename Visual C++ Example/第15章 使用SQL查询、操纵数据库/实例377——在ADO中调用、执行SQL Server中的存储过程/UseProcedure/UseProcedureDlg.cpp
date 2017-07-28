// UseProcedureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UseProcedure.h"
#include "UseProcedureDlg.h"

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
// CUseProcedureDlg dialog

CUseProcedureDlg::CUseProcedureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUseProcedureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUseProcedureDlg)
	m_DName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUseProcedureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUseProcedureDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT1, m_DName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUseProcedureDlg, CDialog)
	//{{AFX_MSG_MAP(CUseProcedureDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXCUTE, OnExcute)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseProcedureDlg message handlers

BOOL CUseProcedureDlg::OnInitDialog()
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

void CUseProcedureDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUseProcedureDlg::OnPaint() 
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
HCURSOR CUseProcedureDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUseProcedureDlg::OnExcute() 
{
	UpdateData(true);
	m_ctlList.ResetContent();//清空列表框
	//通过ADO的COMMAND对象调用、执行存储过程
	_CommandPtr pCommand;
	pCommand.CreateInstance(__uuidof(Command));
	_bstr_t storeproc("stuinfo");//存储过程名

	_RecordsetPtr pRecordset;
	try
	{
		pCommand->ActiveConnection=m_pConnection;//连接对象
		pCommand->CommandText=storeproc;
		pCommand->CommandType=adCmdStoredProc;//设定CommandType属性为存储过程类型
		pCommand->Parameters->Refresh();
		pCommand->Parameters->Item[_variant_t((long)1)]->Value=_variant_t((LPCTSTR)m_DName);
		pRecordset.CreateInstance(__uuidof(Recordset));
		
		pRecordset=pCommand->Execute(NULL,NULL,adCmdStoredProc);
		if((pRecordset->BOF)&&(pRecordset->adoEOF))
		{
			AfxMessageBox("得到的记录集为空!");
			pRecordset->Close();
			return;
		}
		while(VARIANT_FALSE ==pRecordset->adoEOF)//将得到的记录集添加到列表框中
		{
			_variant_t vFieldValue;
			CString strID,strName,strDName,strAvg;
			vFieldValue = pRecordset->GetCollect("SNO");
			strID = (char*)_bstr_t(vFieldValue);
			vFieldValue.Clear();
			vFieldValue = pRecordset->GetCollect("SNAME");
			strName = (char*)_bstr_t(vFieldValue);
			vFieldValue.Clear();
			vFieldValue = pRecordset->GetCollect("DNAME");
			strDName = (char*)_bstr_t(vFieldValue);
			vFieldValue.Clear();
			vFieldValue = pRecordset->GetCollect("平均成绩");
			strAvg = (char*)_bstr_t(vFieldValue);
			vFieldValue.Clear();
			CString strItem;
			strItem.Format("学号:%s姓名:%s单位:%s平均成绩:%s",strID,strName,strDName,strAvg);
			m_ctlList.AddString(strItem);
			pRecordset->MoveNext();//下一条记录
		}
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.ErrorMessage());
		return;
	}
	
}
