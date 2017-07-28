// MSCommProDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MSCommPro.h"
#include "MSCommProDlg.h"

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
// CMSCommProDlg dialog

CMSCommProDlg::CMSCommProDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMSCommProDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMSCommProDlg)
	m_strReceive = _T("");
	m_strSend = _T("");
	m_Port=0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMSCommProDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMSCommProDlg)
	DDX_Control(pDX, IDC_COMBO1, m_ctlList);
	DDX_Control(pDX, IDC_MSCOMM1, m_Comm);
	DDX_Text(pDX, IDC_EDIT1, m_strReceive);
	DDX_Text(pDX, IDC_EDIT2, m_strSend);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMSCommProDlg, CDialog)
	//{{AFX_MSG_MAP(CMSCommProDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENPORT, OnOpenport)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_CLOSEPORT, OnCloseport)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSCommProDlg message handlers

BOOL CMSCommProDlg::OnInitDialog()
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

void CMSCommProDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMSCommProDlg::OnPaint() 
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
HCURSOR CMSCommProDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMSCommProDlg::OnOpenport() 
{
	// TODO: Add your control notification handler code here
	m_Comm.SetCommPort(m_Port);//设置串口
	m_Comm.SetInputMode(1);//设置数据读取格式为二进制
	m_Comm.SetSettings("9600,n,8,1");//传输参数
	m_Comm.SetRThreshold(1);//缓冲区内有一个字符就可以接收
	m_Comm.SetInBufferSize(2048);//接收缓冲区的大小
	m_Comm.SetOutBufferSize(2048);//发送缓冲区大小
	m_Comm.SetInBufferCount(0);//清空接收缓冲区
	if(!m_Comm.GetPortOpen())
	{
		m_Comm.SetPortOpen(true);//打开串口
	}	
}

void CMSCommProDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int ncount=m_strSend.GetLength();
	CByteArray m_Array;//二进制数组
	m_Array.SetSize(ncount);
	for(int i=0;i<ncount;i++)//为数组赋值
	{
		m_Array.SetAt(i,m_strSend[i]);
	}
	m_Comm.SetOutput(COleVariant(m_Array));//发送数据
	m_strSend="";
	UpdateData(false);	
}

void CMSCommProDlg::OnCloseport() //关闭串口
{
	// TODO: Add your control notification handler code here
	if(m_Comm.GetPortOpen())
	{
		m_Comm.SetPortOpen(false);//关闭串口
	}	
}

void CMSCommProDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CString str;
	int nselect=m_ctlList.GetCurSel();				//获取当前组合框选项的索引
	m_ctlList.GetLBText(nselect,str);		
	m_Port=atoi(LPCTSTR(str));	
}

BEGIN_EVENTSINK_MAP(CMSCommProDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CMSCommProDlg)
	ON_EVENT(CMSCommProDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CMSCommProDlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here
	char *str,*str1;
	CString str2;
	int i,k;
	VARIANT m_input;
	int nEvent=m_Comm.GetCommEvent();//得到事件
	switch(nEvent)
	{
	case 2://接收数据事件
		k=m_Comm.GetInBufferCount();//接收缓冲区字符数
		if(k>0)
		{
			m_input=m_Comm.GetInput();
			str=(char*)(unsigned char*)m_input.parray->pvData;
		}
		i=0;
		str1=str;
		while(i<k)
		{
			i++;
			str1++;
		}
		*str1='\0';
		str2=(const char*)str;
		m_strReceive=m_strReceive+str2+"\r\n";
	default:
		break;
	}
	UpdateData(false);		
}
