// DecodeStringDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DecodeString.h"
#include "DecodeStringDlg.h"

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
// CDecodeStringDlg dialog

CDecodeStringDlg::CDecodeStringDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDecodeStringDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDecodeStringDlg)
	m_strOrigin = _T("<<Visual C++基础>>;<<数据库开发>>;<<数字图像处理>>;<<多媒体应用与开发>>;");
	m_strDivision = _T(";");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDecodeStringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDecodeStringDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT1, m_strOrigin);
	DDX_Text(pDX, IDC_EDIT2, m_strDivision);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDecodeStringDlg, CDialog)
	//{{AFX_MSG_MAP(CDecodeStringDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DECODE, OnDecode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDecodeStringDlg message handlers

BOOL CDecodeStringDlg::OnInitDialog()
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

void CDecodeStringDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDecodeStringDlg::OnPaint() 
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
HCURSOR CDecodeStringDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDecodeStringDlg::OnDecode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CStringArray dest;//CString数组类
	char division=m_strDivision.GetAt(0);//获取分割符
	StringDecode(m_strOrigin, dest, division);//分割字符串
	m_ctlList.ResetContent();//清空列表框
	for(int i=0;i<dest.GetSize();i++)
    {
       m_ctlList.AddString(dest[i]);//将分割后得到的字符串添加到列表框
    }
}

void CDecodeStringDlg::StringDecode(CString source, CStringArray& dest, char division)
{
/*	dest.RemoveAll();
   for(int i=0;i<source.GetLength();i++)//遍历字符串
   {
      if(source.GetAt(i)== division)//找到分割符
      {
         dest.Add(source.Left(i));         //去掉右边
         for(int j=0;j<(dest.GetSize()-1);j++)
         {
            dest[dest.GetSize()-1] = dest[dest.GetSize()-1].Right(dest[dest.GetSize()-1].GetLength()-dest[j].GetLength()-1);  //去掉左边
         }
      }   
   }*/

	dest.RemoveAll();
	int nStart = 0;
	int nEnd = source.Find(division);//查找分割符
	while(nEnd > nStart)
	{
		dest.Add(source.Mid(nStart,nEnd - nStart));
		nStart = nEnd + 1;//定位起始位置
		nEnd = source.Find(division,nStart);//查找分割符
	}
	nEnd = source.GetLength();
	if(nStart < nEnd) 
		dest.Add(source.Mid(nStart,nEnd - nStart));
}
