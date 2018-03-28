// EnumRegValueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnumRegValue.h"
#include "EnumRegValueDlg.h"
#include "afxtempl.h"
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
// CEnumRegValueDlg dialog

CEnumRegValueDlg::CEnumRegValueDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnumRegValueDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnumRegValueDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnumRegValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnumRegValueDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnumRegValueDlg, CDialog)
	//{{AFX_MSG_MAP(CEnumRegValueDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ENUM, OnEnum)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumRegValueDlg message handlers

BOOL CEnumRegValueDlg::OnInitDialog()
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

void CEnumRegValueDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEnumRegValueDlg::OnPaint() 
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
HCURSOR CEnumRegValueDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEnumRegValueDlg::OnEnum() 
{
	// TODO: Add your control notification handler code here
	HKEY lKey;//定义一个键的句柄，用于存储被打开的键
	HKEY hKey;//初始的值
	CString psKey;//要打开的键的名称
	long lResult;//操作注册表函数的返回值
	CList<CString,CString&> listvalue;//定义链表存储枚举得到的键值名
	CString strList;
	DWORD numValues,maxLenValueName,maxLenValueData,lpType,lenValue;
	char *ValueName=new char[1024];//存储枚举得到的键值名
	BYTE *lpData=new BYTE[1024];//存储枚举得到的键值数据
	DWORD lenData;//存储键值的数据长度
	hKey=HKEY_CURRENT_USER;//初始根键
	psKey="SOFTWARE\\MICROSOFT\\INTERNET EXPLORER\\Main";//子键名称及位置
	lResult=RegOpenKeyEx(hKey,LPCSTR(psKey), 0, KEY_READ, &lKey);
	if(ERROR_SUCCESS!=lResult)
	{
		MessageBox("错误: 无法打开有关的注册表键!"); 
		return;
	}
	lResult=RegQueryInfoKey(lKey,NULL,NULL,0,NULL,NULL,NULL,&numValues,&maxLenValueName,&maxLenValueData,NULL,NULL);
	if(ERROR_SUCCESS!=lResult)
	{
		MessageBox("错误: 未能正确获取键的信息!"); 
		return;
	}
	for(int i=0;ERROR_SUCCESS==lResult,i<(int)numValues;i++)
	{
		lenValue=maxLenValueName;
		lenData=1024;
		//枚举键值
		lResult=RegEnumValue(lKey,i,ValueName,&lenValue,0,&lpType,lpData,&lenData);
		//将键值放到链表中
		strList=ValueName;
		listvalue.AddTail(strList);
	}
	//遍历链表，将其值添加到列表框中
	POSITION post=listvalue.GetHeadPosition();
	while(post!=NULL)
	{
		strList=listvalue.GetNext(post);
		m_ctlList.InsertString(-1,strList);
	}
	delete ValueName;
	delete lpData;
}
