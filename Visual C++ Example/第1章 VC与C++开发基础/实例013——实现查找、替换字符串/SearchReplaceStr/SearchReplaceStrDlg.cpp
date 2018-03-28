// SearchReplaceStrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SearchReplaceStr.h"
#include "SearchReplaceStrDlg.h"

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
// CSearchReplaceStrDlg dialog

CSearchReplaceStrDlg::CSearchReplaceStrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchReplaceStrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchReplaceStrDlg)
	m_strData = _T("");
	m_strFind = _T("");
	m_strReplace = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchReplaceStrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchReplaceStrDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strData);
	DDX_Text(pDX, IDC_EDIT2, m_strFind);
	DDX_Text(pDX, IDC_EDIT3, m_strReplace);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSearchReplaceStrDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchReplaceStrDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REPLACE, OnReplace)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchReplaceStrDlg message handlers

BOOL CSearchReplaceStrDlg::OnInitDialog()
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

void CSearchReplaceStrDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSearchReplaceStrDlg::OnPaint() 
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
HCURSOR CSearchReplaceStrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSearchReplaceStrDlg::OnReplace() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_strFind.IsEmpty())
	{
		AfxMessageBox("查找的字符串为空！");//判断编辑框字符串是否为空
		return;
	}
	int num;
	num=m_strData.Replace(m_strFind,m_strReplace);//替换字符串
	CString str;
	str.Format("共完成了%d处替换",num);
	AfxMessageBox(str);
	UpdateData(false);
}

void CSearchReplaceStrDlg::OnSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_strFind.IsEmpty())//判断编辑框字符串是否为空
	{
		AfxMessageBox("查找的字符串为空！");
		return;
	}
	int pos=0;//记录查找位置
	CString strpos,temp;
	strpos.Format("%s字符串在原字符串中的起始位置为：\n",m_strFind);
	while((pos>=0)&&(pos<m_strData.GetLength()))
	{
		pos=m_strData.Find(m_strFind,pos);//查找字符串
		if(pos>0)
		{
			temp.Format("%d ",pos);
			strpos+=temp;
			pos+=m_strFind.GetLength();//新的起始查找位置
		}
	}
	AfxMessageBox(strpos);
}
