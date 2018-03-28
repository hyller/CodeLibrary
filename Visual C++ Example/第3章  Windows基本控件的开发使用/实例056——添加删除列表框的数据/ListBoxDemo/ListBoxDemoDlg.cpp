// ListBoxDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListBoxDemo.h"
#include "ListBoxDemoDlg.h"

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
// CListBoxDemoDlg dialog

CListBoxDemoDlg::CListBoxDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListBoxDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListBoxDemoDlg)
	m_unit = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListBoxDemoDlg)
	DDX_Control(pDX, IDC_IN, m_ctlIn);
	DDX_Control(pDX, IDC_OUT, m_ctlOut);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_EDIT1, m_unit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListBoxDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CListBoxDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_IN, OnIn)
	ON_BN_CLICKED(IDC_OUT, OnOut)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	ON_LBN_DBLCLK(IDC_LIST2, OnDblclkList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListBoxDemoDlg message handlers

BOOL CListBoxDemoDlg::OnInitDialog()
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
	m_ctlOut.EnableWindow (FALSE);//借出按钮无效
	m_ctlIn.EnableWindow (FALSE);//归还按钮无效
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListBoxDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListBoxDemoDlg::OnPaint() 
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
HCURSOR CListBoxDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CListBoxDemoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_unit.IsEmpty())								//如果装备名称为空
	{
		AfxMessageBox("装备名称不能为空！");
		return;
	}
	m_list1.AddString(m_unit);							//加入列表框
	m_unit="";									//清空编辑框
	UpdateData(false);
}

void CListBoxDemoDlg::OnIn() //单击归还按钮
{
	// TODO: Add your control notification handler code here
	int Count = m_list2.GetSelCount ();//获取外借列表框中选中的记录数
	if (!Count)//如果未选中，返回
		return;
	int *SelItems = new int [Count];
	m_list2.GetSelItems (Count, SelItems);//获取外借列表框中选中的记录
	for (int i = 0; i < Count; ++i)
	{
		CString strText;
		int	iIndex;
		m_list2.GetText (SelItems[i], strText);
		DWORD dwData = m_list2.GetItemData (SelItems[i]);
		iIndex = m_list1.AddString ((LPCSTR) strText);//添加到库存列表框
		m_list1.SetItemData (iIndex, dwData);
	}
	for (i = Count - 1; i >= 0; --i)
		m_list2.DeleteString (SelItems[i]);//从外借列表框中删除选中的列表项
	delete [] SelItems;
	m_list2.SetSel (-1, false);//取消列表框的选中项
	if (m_list1.GetSelCount ())//如果库存列表框中有选中项
		m_ctlOut.EnableWindow (true);//借出按钮生效
	else
		m_ctlOut.EnableWindow (false);
	if (m_list2.GetSelCount ())//如果外界列表框中有选中项
	{
		m_ctlIn.EnableWindow (true);//归还按钮生效
	}
	else
	{
		m_ctlIn.EnableWindow (false);
	}	
}

void CListBoxDemoDlg::OnOut() //单击借出按钮
{
	// TODO: Add your control notification handler code here
	int Count = m_list1.GetSelCount ();//获取库存列表框中选中的记录数
	if (!Count)//如果未选中，返回
		return;
	int *SelItems = new int [Count];
	m_list1.GetSelItems (Count, SelItems);//获取库存列表框中选中的记录
	for (int i = 0; i < Count; ++i)
	{
		CString strText;
		int	iIndex;
		m_list1.GetText (SelItems[i], strText);
		DWORD dwData = m_list2.GetItemData (SelItems[i]);
		iIndex = m_list2.AddString ((LPCSTR) strText);//添加到外借列表框
		m_list2.SetItemData (iIndex, dwData);
	}
	for (i = Count - 1; i >= 0; --i)
	{
		m_list1.DeleteString (SelItems[i]);//从库存列表框中删除选中的列表项
	}
	delete [] SelItems;
	m_list1.SetSel (-1, false);//取消列表框的选中项
	if (m_list1.GetSelCount ())//如果库存列表框中有选中项
		m_ctlIn.EnableWindow (true);//借出按钮生效
	else
		m_ctlIn.EnableWindow (false);
	if (m_list2.GetSelCount ())//如果外界列表框中有选中项
	{
		m_ctlOut.EnableWindow (true);//归还按钮生效
	}
	else
	{
		m_ctlOut.EnableWindow (false);
	}	
}

void CListBoxDemoDlg::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	if (m_list1.GetSelCount ())//库存列表框有列表项被选中
		m_ctlOut.EnableWindow (TRUE);//借出按钮生效
	else
		m_ctlOut.EnableWindow (FALSE);
	
}

void CListBoxDemoDlg::OnSelchangeList2() 
{
	// TODO: Add your control notification handler code here
	if (m_list2.GetSelCount ())//外借列表框有列表项被选中
		m_ctlIn.EnableWindow (TRUE);//归还按钮生效
	else
		m_ctlIn.EnableWindow (FALSE);
}

void CListBoxDemoDlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	OnOut();//调用OnOut函数	
}

void CListBoxDemoDlg::OnDblclkList2() 
{
	// TODO: Add your control notification handler code here
	OnIn();//调用OnIn函数	
}
