// StringArrayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringArray.h"
#include "StringArrayDlg.h"

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
// CStringArrayDlg dialog

CStringArrayDlg::CStringArrayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStringArrayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStringArrayDlg)
	m_radio = 0;
	m_pos = 0;
	m_str = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStringArrayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStringArrayDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	DDX_Text(pDX, IDC_EDIT1, m_pos);
	DDX_Text(pDX, IDC_EDIT2, m_str);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStringArrayDlg, CDialog)
	//{{AFX_MSG_MAP(CStringArrayDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStringArrayDlg message handlers

BOOL CStringArrayDlg::OnInitDialog()
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

void CStringArrayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStringArrayDlg::OnPaint() 
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
HCURSOR CStringArrayDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CStringArrayDlg::OnCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	switch (m_radio)
	{
		int i;
		case 0://插入操作
			if(m_pos<0||m_pos>m_array.GetSize())//判断插入位置的有效性
			{
				AfxMessageBox("数组位置不正确！");
				return;
			}
			if(m_str.IsEmpty())//判断插入信息的有效性
			{
				AfxMessageBox("信息不能为空!");
				return;
			}
			m_array.InsertAt(m_pos,m_str);//在数组的指定位置插入字符串
			m_list.ResetContent();//清空列表框
			for(i=0;i<m_array.GetSize();i++)
			{
				m_list.AddString(m_array.GetAt(i));//按数组顺序添加列表项
			}
			m_str="";//清空信息编辑框
			m_pos=m_array.GetSize();
			UpdateData(false);
			break;
		case 1://删除操作
			if(m_pos<0||m_pos>=m_array.GetSize())//判断删除位置的有效性
			{
				AfxMessageBox("该位置没有数组元素！");
				return;
			}
			m_array.RemoveAt(m_pos);//在数组的指定位置删除字符串
			m_list.ResetContent();//清空列表框
			for(i=0;i<m_array.GetSize();i++)
			{
				m_list.AddString(m_array.GetAt(i));//按数组顺序添加列表项
			}
			m_str="";//清空信息编辑框
			m_pos=m_array.GetSize();
			UpdateData(false);
			break;
	}
	
}
