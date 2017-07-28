// PtrListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PtrList.h"
#include "PtrListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
struct CAccount
{
	CString m_name;//名目	
	double m_count;//费用
};


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
// CPtrListDlg dialog

CPtrListDlg::CPtrListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPtrListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPtrListDlg)
	m_name = _T("");
	m_count = 0.0;
	m_total = 0.0;
	m_radio = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPtrListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPtrListDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_count);
	DDX_Text(pDX, IDC_EDIT3, m_total);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPtrListDlg, CDialog)
	//{{AFX_MSG_MAP(CPtrListDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPtrListDlg message handlers

BOOL CPtrListDlg::OnInitDialog()
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

void CPtrListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPtrListDlg::OnPaint() 
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
HCURSOR CPtrListDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPtrListDlg::OnCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);//获取编辑框数据
	CAccount* m_pAccount = new CAccount;//创建结构体对象指针
	switch(m_radio)
	{
		case 0:											//插入操作
			if(m_name.IsEmpty()||m_count<=0)								//判断插入信息的有效性
			{
				AfxMessageBox("输入的费用信息不正确!");
				return;
			}
			m_pAccount->m_name = m_name;//将用户输入信息赋值给结构体对象
			m_pAccount->m_count=m_count;
			m_accountlist.AddTail(m_pAccount);//将结构体对象加入到链表尾
			m_name="";//编辑框复位
			m_count=0.0;
			UpdateData(false);
			Reflesh();//更新显示
			break;
		case 1:											//去除表头操作
			if(m_accountlist.GetCount())//链表不为空
			{
				m_accountlist.RemoveHead();//去除表头
			}
			m_name="";//复位
			m_count=0.0;
			UpdateData(false);
			Reflesh();//更新显示
			break;
		case 2:	//去除表尾操作
			if(m_accountlist.GetCount())//链表不为空
			{
				m_accountlist.RemoveTail();//去除表尾
			}
			m_name="";
			m_count=0;
			UpdateData(false);
			Reflesh();//更新显示
			break;
	}
	
}

void CPtrListDlg::Reflesh()
{
	CString str,str1;
	m_total=0;//总量赋值0
	m_list.ResetContent();										//清空列表框
	if(!m_accountlist.IsEmpty())									//链表不为空
	{
		POSITION pos = m_accountlist.GetHeadPosition();					//获取链表头的位置
		for (int i=0;i<m_accountlist.GetCount();i++)						//遍历链表
		{
			
			CAccount* m_pAccount = (CAccount*)m_accountlist.GetNext(pos);
			str1.Format("%.2f",m_pAccount->m_count);					//格式化费用
			str="名目："+m_pAccount->m_name+"   支出费用："+str1;
			m_list.AddString(str);									//添加列表框数据
			m_total+=m_pAccount->m_count;						//计算总费用
		}
	}
	UpdateData(false);										//更新总费用编辑框
}

