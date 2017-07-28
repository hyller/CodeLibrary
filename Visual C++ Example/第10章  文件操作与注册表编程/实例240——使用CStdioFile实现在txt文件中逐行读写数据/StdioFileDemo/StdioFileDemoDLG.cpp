// StdioFileDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StdioFileDemo.h"
#include "StdioFileDemoDlg.h"

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
// CStdioFileDemoDlg dialog

CStdioFileDemoDlg::CStdioFileDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStdioFileDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStdioFileDemoDlg)
	m_bookname = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStdioFileDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStdioFileDemoDlg)
	DDX_Control(pDX, IDC_LIST1, m_booklist);
	DDX_Text(pDX, IDC_EDIT1, m_bookname);
	DDV_MaxChars(pDX, m_bookname, 30);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStdioFileDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CStdioFileDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_LOAD, OnLoad)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStdioFileDemoDlg message handlers

BOOL CStdioFileDemoDlg::OnInitDialog()
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

void CStdioFileDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStdioFileDemoDlg::OnPaint() 
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
HCURSOR CStdioFileDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStdioFileDemoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_bookname.IsEmpty())//编辑框为空
	{
		AfxMessageBox("添加的书名不能为空！");
		return;
	}
	m_booklist.AddString(m_bookname);//加入列表框
	m_bookname="";
	UpdateData(false);//清空编辑框
}

void CStdioFileDemoDlg::OnLoad() //载入
{
	// TODO: Add your control notification handler code here
	CString strFilter,fileName;
	strFilter="Text Files(*.txt)|*.txt||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )//显示打开文件对话框
	{
		fileName=dlg.GetPathName();
		CStdioFile openfile(fileName,CFile::modeRead);				//构造CStdioFile对象
		CString str;
		while(openfile.ReadString(str))							//读一行数据
		{
			m_booklist.AddString(str);//加入列表框
		}
		openfile.Close();										//关闭文件
	}	
}

void CStdioFileDemoDlg::OnSave() //保存
{
	// TODO: Add your control notification handler code here
	CString strFilter,fileName,strText;
	strFilter="Text Files(*.txt)|*.txt||";
	CFileDialog dlg(FALSE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )//显示保存文件对话框
	{
		fileName=dlg.GetPathName();
		CStdioFile savefile(fileName,CFile::modeCreate|CFile::modeWrite);		//构造CStdioFile对象
		for(int i=0;i<m_booklist.GetCount();i++)
		{
			m_booklist.GetText(i,strText);							//获取列表框数据
			strText=strText+"\n";									//添加回车符
			savefile.WriteString(strText);							//写文件数据
		}
		savefile.Close();//关闭文件
	}
}
