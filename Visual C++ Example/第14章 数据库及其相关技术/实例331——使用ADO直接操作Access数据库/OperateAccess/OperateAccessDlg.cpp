// OperateAccessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OperateAccess.h"
#include "OperateAccessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern COperateAccessApp theApp;       // 在此引用应用类中的theApp来获取库连接指针
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
// COperateAccessDlg dialog

COperateAccessDlg::COperateAccessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COperateAccessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COperateAccessDlg)
	m_strNo = _T("");
	m_strName = _T("");
	m_strSex = _T("");
	m_strAddress = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COperateAccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COperateAccessDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT1, m_strNo);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	DDX_Text(pDX, IDC_EDIT3, m_strSex);
	DDX_Text(pDX, IDC_EDIT4, m_strAddress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COperateAccessDlg, CDialog)
	//{{AFX_MSG_MAP(COperateAccessDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_READ, OnRead)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COperateAccessDlg message handlers

BOOL COperateAccessDlg::OnInitDialog()
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
	// 使用ADO创建数据库记录集
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	try
	{
		m_pRecordset->Open("SELECT * FROM studentinfo",                // 查询studentinfo表中所有字段
							theApp.m_pConnection.GetInterfacePtr(),	 // 获取库接库的IDispatch指针
							adOpenDynamic,
							adLockOptimistic,
							adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COperateAccessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COperateAccessDlg::OnPaint() 
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
HCURSOR COperateAccessDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COperateAccessDlg::OnRead() 
{
	// TODO: Add your control notification handler code here
	_variant_t var;
	CString strNo,strName,strSex,strAddress;
	m_ctlList.ResetContent();// 清空列表框
	try
	{
		if(!m_pRecordset->BOF)
			m_pRecordset->MoveFirst();
		else
		{
			AfxMessageBox("表内数据为空");
			return;
		}
		// 读入库中各字段并加入列表框中
		while(!m_pRecordset->adoEOF)
		{
			var = m_pRecordset->GetCollect("stuNo");
			if(var.vt != VT_NULL)
				strNo = (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("stuName");
			if(var.vt != VT_NULL)
				strName = (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("stuSex");
			if(var.vt != VT_NULL)
				strSex= (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("stuAddress");
			if(var.vt != VT_NULL)
				strAddress= (LPCSTR)_bstr_t(var);
			m_ctlList.AddString( strNo+"----->"+strName + "----->"+strSex+ "----->"+strAddress );
			m_pRecordset->MoveNext();
		}
		// 默认列表指向第一项，同时移动记录指针并显示
		m_ctlList.SetCurSel(0);
		OnSelchangeList1();
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	
}

void COperateAccessDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData();        // 更新对话框数据
	if(m_ctlList.GetCount()==0||m_strName == ""||m_strNo == ""||m_strSex == "")
	{
		AfxMessageBox("表中记录数为空或相关信息没有设置!");
		return;
	}
	else if(m_ctlList.GetCurSel() < 0 || m_ctlList.GetCurSel() > m_ctlList.GetCount())
		m_ctlList.SetCurSel(0);
	// 修改当前记录的字段值
	try
	{
		m_pRecordset->PutCollect("stuNo", _variant_t(m_strNo));
		m_pRecordset->PutCollect("stuName", _variant_t(m_strName));
		m_pRecordset->PutCollect("stuSex", _variant_t(m_strSex));
		m_pRecordset->PutCollect("stuAddress", _variant_t(m_strAddress));
		m_pRecordset->Update();
		// 重新读入库记录更新显示
		int nCurSel = m_ctlList.GetCurSel();
		OnRead();
		m_ctlList.SetCurSel(nCurSel);
		// 移动记录指针到新的位置
		OnSelchangeList1() ;
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void COperateAccessDlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
	if(m_ctlList.GetCount() == 0)
		return;
	else if(m_ctlList.GetCurSel() < 0 || m_ctlList.GetCurSel() > m_ctlList.GetCount())
		m_ctlList.SetCurSel(0);
	try
	{
		// 删除当前行记录
		m_pRecordset->Delete(adAffectCurrent);
		m_pRecordset->Update();
		// 删除列表中当前值
		int nCurSel = m_ctlList.GetCurSel();
		m_ctlList.DeleteString(nCurSel);
		if(nCurSel == 0 && (m_ctlList.GetCount() != 0))
			m_ctlList.SetCurSel(nCurSel);
		else if(m_ctlList.GetCount() != 0)
			m_ctlList.SetCurSel(nCurSel-1);
		// 移动记录指针到新的位置
		OnSelchangeList1();
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void COperateAccessDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_strName == ""||m_strNo == ""||m_strSex == "")
	{
		AfxMessageBox("姓名、学号、性别信息不能为空!");
		return;
	}
	try
	{
		// 写入各字段值
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("stuNo", _variant_t(m_strNo));
		m_pRecordset->PutCollect("stuName", _variant_t(m_strName));
		m_pRecordset->PutCollect("stuSex", _variant_t(m_strSex));
		m_pRecordset->PutCollect("stuAddress", _variant_t(m_strAddress));
		m_pRecordset->Update();
		AfxMessageBox("添加数据成功!");
		// 更新显示其库内容
		int nCurSel = m_ctlList.GetCurSel();
		OnRead();
		m_ctlList.SetCurSel(nCurSel);
		// 移动记录指针到新的位置
		OnSelchangeList1();
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
	
}

void COperateAccessDlg::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	int curSel = m_ctlList.GetCurSel();		
	_variant_t var,varIndex;
	if(curSel < 0)
		return;
	try
	{
		// 先将指针移向第一条记录，然后就可以相对第一条记录来随意移动记录指针
		m_pRecordset->MoveFirst();
		m_pRecordset->Move(long(curSel));
		var = m_pRecordset->GetCollect("stuNo");
			if(var.vt != VT_NULL)
				m_strNo = (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("stuName");
			if(var.vt != VT_NULL)
				m_strName = (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("stuSex");
			if(var.vt != VT_NULL)
				m_strSex= (LPCSTR)_bstr_t(var);
			var = m_pRecordset->GetCollect("stuAddress");
			if(var.vt != VT_NULL)
				m_strAddress= (LPCSTR)_bstr_t(var);
		
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}
