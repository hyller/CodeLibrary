// DlgActiveXDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DlgActiveXDemo.h"
#include "DlgActiveXDemoDlg.h"

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
// CDlgActiveXDemoDlg dialog

CDlgActiveXDemoDlg::CDlgActiveXDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgActiveXDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgActiveXDemoDlg)
	m_value = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgActiveXDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgActiveXDemoDlg)
	DDX_Control(pDX, IDC_VALUEEDIT, m_edit);
	DDX_Control(pDX, IDC_MSHFLEXGRID1, m_flexgrid);
	DDX_Text(pDX, IDC_VALUEEDIT, m_value);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgActiveXDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgActiveXDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CAL, OnCal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgActiveXDemoDlg message handlers

BOOL CDlgActiveXDemoDlg::OnInitDialog()
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
	m_bEditing=false;//初始化
	m_nRow=1;
	m_nCol=1;
	char* colHead[4]={"电话费","电费","煤气费","合计"};
	char* rowHead[4]={"一月","二月","三月","四月"};
	m_flexgrid.SetRow(0);//定位到表格第一行
	for(int nCol=0;nCol<4;nCol++)//添加行头
	{
		m_flexgrid.SetCol(nCol+1);
		m_flexgrid.SetText(rowHead[nCol]);
	}
	m_flexgrid.SetCol(0);//定位到表格第一列
	for(int nRow=0;nRow<4;nRow++)//添加列头
	{
		m_flexgrid.SetRow(nRow+1);
		m_flexgrid.SetText(colHead[nRow]);
	}
	m_edit.ShowWindow(SW_HIDE);//隐藏编辑框
	m_flexgrid.SetBackColor(RGB(255,200,255));//设置背景色
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgActiveXDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDlgActiveXDemoDlg::OnPaint() 
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
HCURSOR CDlgActiveXDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CDlgActiveXDemoDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CDlgActiveXDemoDlg)
	ON_EVENT(CDlgActiveXDemoDlg, IDC_MSHFLEXGRID1, -600 /* Click */, OnClickMshflexgrid1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDlgActiveXDemoDlg::OnClickMshflexgrid1() 
{
	// TODO: Add your control notification handler code here
	CString szText=m_flexgrid.GetText();
	if(!m_bEditing)
	{
		m_nRow=m_flexgrid.GetRow();//获取表格当前行
		m_nCol=m_flexgrid.GetCol();//获取表格当前列
		if(m_nRow<4)//不是最后一行
		{
			m_bEditing=true;//进入编辑状态
			szText=m_flexgrid.GetText();//获取表格原有值
			m_value=atof(szText);//转换为double型传给编辑框变量
			UpdateData(false);//编辑框显示表格值
			
	        long lRow = m_flexgrid.GetRowSel();//获取点击的行号
			long lCol = m_flexgrid.GetColSel();  //获取点击的列号
			CRect rect;
			m_flexgrid.GetWindowRect(rect);  //获取表格控件的窗口矩形
			ScreenToClient(rect);             //转换为客户区矩形
			// MSFlexGrid 控件的函数的长度单位是"缇(twips)"，
			//需要将其转化为像素，1440 缇 = 1 英寸
			CDC* pDC =GetDC();
			//计算象素点和缇的转换比例
			int nTwipsPerDotX = 1440 / pDC->GetDeviceCaps(LOGPIXELSX) ;
			int nTwipsPerDotY = 1440 / pDC->GetDeviceCaps(LOGPIXELSY) ;
			//计算选中格的左上角的坐标（象素为单位）
			long y = m_flexgrid.GetRowPos(lRow)/nTwipsPerDotY;
			long x = m_flexgrid.GetColPos(lCol)/nTwipsPerDotX;
			//计算选中格的尺寸（象素为单位）。加1是实际调试中，发现加1后效果更好
			// long width = m_flexgrid.GetColWidth(lCol)/nTwipsPerDotX+1;
			long height = m_flexgrid.GetRowHeight(lRow)/nTwipsPerDotY+1;
			//形成选中个所在的矩形区域
			CRect rc(x,y,x+70,y+height);
			//转换成相对对话框的坐标
			rc.OffsetRect(rect.left+1,rect.top+1);
			m_edit.ShowWindow(SW_SHOW);//显示编辑框
			m_edit.MoveWindow(rc,true);
			m_edit.SetFocus();//编辑框捕获焦点
			m_edit.SetSel(0,-1);
		}
	}
	else//编辑完毕
	{
		int m_nCurrentRow=m_flexgrid.GetRow();//获取表格当前行
		int m_nCurrentCol=m_flexgrid.GetCol();//获取表格当前列
		m_flexgrid.SetRow(m_nRow);
		m_flexgrid.SetCol(m_nCol);
		m_flexgrid.SetFocus();//表格捕获焦点
		UpdateData(true);//获取编辑框值
		CString str;
		str.Format("%01.2f",m_value);//格式化
		m_flexgrid.SetText(str);//编辑框数据输入相应表格
		m_edit.ShowWindow(SW_HIDE);//隐藏编辑框
		m_bEditing=false;//退出编辑状态

	}

}

void CDlgActiveXDemoDlg::OnCal() 
{
	// TODO: Add your control notification handler code here
	if(m_bEditing)//正在编辑
	{
		UpdateData(true);//获取编辑框值
		CString str;
		str.Format("%01.2f",m_value);//格式化
		m_flexgrid.SetText(str);//编辑框数据输入相应表格
		m_edit.ShowWindow(SW_HIDE);//隐藏编辑框
		m_bEditing=false;//退出编辑状态
	}
	for(int nCol=1;nCol<5;nCol++)
	{
		double dTotal=0;
		m_flexgrid.SetCol(nCol);
		for(int nRow=1;nRow<4;nRow++)
		{
			m_flexgrid.SetRow(nRow);
			CString szCell=m_flexgrid.GetText();
			dTotal+=atof(szCell);//对列求和
		}
		CString str;
		str.Format("%01.2f",dTotal);//格式化
		m_flexgrid.SetRow(4);//定位到最后一行
		m_flexgrid.SetText(str);//编辑框数据输入相应表格
	}
	
}
