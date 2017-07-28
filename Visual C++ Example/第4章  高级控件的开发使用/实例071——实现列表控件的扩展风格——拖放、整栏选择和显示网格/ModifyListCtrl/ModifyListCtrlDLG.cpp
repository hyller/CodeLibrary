// ModifyListCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ModifyListCtrl.h"
#include "ModifyListCtrlDlg.h"

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
// CModifyListCtrlDlg dialog

CModifyListCtrlDlg::CModifyListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModifyListCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModifyListCtrlDlg)
	m_edit = _T("");
	m_radio = 0;
	m_static = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CModifyListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModifyListCtrlDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Text(pDX, IDC_STATIC1, m_static);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CModifyListCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CModifyListCtrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModifyListCtrlDlg message handlers

BOOL CModifyListCtrlDlg::OnInitDialog()
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
	DWORD liststyle=m_ctlList.GetExtendedStyle();//获取列表控件的扩展风格
	m_ctlList.SetExtendedStyle(liststyle|LVS_EX_HEADERDRAGDROP|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);//设置列表控件的新扩展风格


	m_pImageList.Create(16, 16, ILC_COLOR, 2, 2);//创建图像列表
	CBitmap bm;
	bm.LoadBitmap(IDB_BITMAP1);//载入Bitmap资源
	m_pImageList.Add(&bm, RGB(0, 0, 0));//添加到图像列表
	bm.DeleteObject();
	bm.LoadBitmap(IDB_BITMAP2);
	m_pImageList.Add(&bm, RGB(0, 0, 0));
	//初始化列表视
	m_ctlList.SetImageList(&m_pImageList,LVSIL_SMALL);				//设置ImageList
	CString Field[2]={"性别","姓名"};						//列表视的表头
	for(int j=0;j<2;j++)
	{
		m_ctlList.InsertColumn(j,Field[j],LVCFMT_LEFT,95);				//插入表头标题
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CModifyListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CModifyListCtrlDlg::OnPaint() 
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
HCURSOR CModifyListCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CModifyListCtrlDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_edit.IsEmpty())								//如果用户名为空
	{
		AfxMessageBox("姓名不能为空！");
		return;
	}
	int num=m_ctlList.GetItemCount();
	CString sex;
	int icoindex;//图标序号
	if(m_radio==0)
	{
		sex="男";
		icoindex=0;
	}
	else
	{
		sex="女";
		icoindex=1;
	}
	m_ctlList.InsertItem(num,sex,icoindex);							//插入行
	m_ctlList.SetItemText(num,1,m_edit);					//设置该行的不同列的显示字符
	m_edit="";
	UpdateData(false);	
}

void CModifyListCtrlDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	 for(int i=0; i<m_ctlList.GetItemCount(); i++)					//遍历整个列表视图
      {
           if( m_ctlList.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )	//获取选中行
           {
				CString str=m_ctlList.GetItemText(i,0);				//获取该行各列的信息
				CString str1=m_ctlList.GetItemText(i,1);
				m_static="性别："+str+"  姓名："+str1;
				UpdateData(false);	
           }
      }

	*pResult = 0;
}
