// ClipBoardDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClipBoardDemo.h"
#include "ClipBoardDemoDlg.h"
#include "afxole.h"//COleDataSource
#include "afxadv.h"//CSharedFile

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
// CClipBoardDemoDlg dialog

CClipBoardDemoDlg::CClipBoardDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClipBoardDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClipBoardDemoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClipBoardDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClipBoardDemoDlg)
	DDX_Control(pDX, IDC_LIST2, m_booklist2);
	DDX_Control(pDX, IDC_LIST1, m_booklist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClipBoardDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CClipBoardDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	ON_BN_CLICKED(IDC_PLASTE, OnPlaste)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClipBoardDemoDlg message handlers

BOOL CClipBoardDemoDlg::OnInitDialog()
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
	m_booklist.AddString("数字信号处理");
	m_booklist.AddString("小波变换及工程实践");
	m_booklist.AddString("科学发展观与军队信息化建设");
	m_booklist.AddString("党的生活");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClipBoardDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClipBoardDemoDlg::OnPaint() 
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
HCURSOR CClipBoardDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



/*void CClipBoardDemoDlg::OnLoad() //载入
{
	// TODO: Add your control notification handler code here
	CString strFilter,fileName;
	char* strText;
	strText=new char[40];//存储从文件读取的数据
	strFilter="List Files(*.list)|*.list||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )//显示打开文件对话框
	{
		fileName=dlg.GetPathName();
		CFile openfile(fileName,CFile::modeRead);//构造CFile对象
		int i=0;
		openfile.SeekToBegin();
		while(openfile.Read(strText,40)!=0)//读出的文件不为空
		{	
			m_booklist.AddString((CString)strText);
			i++;
			openfile.Seek(40*i,CFile::begin);//定位文件指针	
		}
		openfile.Close();//关闭文件
	}	
}*/

/*void CClipBoardDemoDlg::OnSave() //保存
{
	// TODO: Add your control notification handler code here
	CString strFilter,fileName,strText;
	strFilter="List Files(*.list)|*.list||";
	CFileDialog dlg(FALSE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	if(dlg.DoModal() == IDOK )//显示保存文件对话框
	{
		fileName=dlg.GetPathName();
		CFile savefile(fileName,CFile::modeCreate|CFile::modeWrite);//构造CFile对象
		for(int i=0;i<m_booklist.GetCount();i++)
		{
			m_booklist.GetText(i,strText);//获取列表框数据
			savefile.Seek(40*i,CFile::begin);//定位文件指针
			savefile.Write(strText,40);//写文件数据
		}
		savefile.Close();//关闭文件
	}
}*/

void CClipBoardDemoDlg::OnCopy() 
{
	// TODO: Add your control notification handler code here
	COleDataSource* pSource=new COleDataSource();
	CSharedFile sf(GMEM_MOVEABLE|GMEM_DDESHARE|GMEM_ZEROINIT);
	char* strText;
	strText=new char[40];//存储从文件读取的数据
	for(int i=0;i<m_booklist.GetCount();i++)
	{
		m_booklist.GetText(i,strText);//获取列表框数据
		sf.Seek(40*i,CFile::begin);//定位文件指针
		sf.Write(strText,40);//写文件数据
	}
	HGLOBAL hMem=sf.Detach();
	if(!hMem)
		return;
	pSource->CacheGlobalData(CF_TEXT,hMem);
	pSource->SetClipboard();//添加到剪切板中
}

void CClipBoardDemoDlg::OnPlaste() 
{
	// TODO: Add your control notification handler code here
	COleDataObject obj;
	if(obj.AttachClipboard())
	{
		if(obj.IsDataAvailable(CF_TEXT))
		{
			HGLOBAL hmem=obj.GetGlobalData(CF_TEXT);
			CMemFile mf((BYTE*)::GlobalLock(hmem),::GlobalSize(hmem));
			char* strText;
			strText=new char[40];//存储从文件读取的数据
			int i=0;
			mf.SeekToBegin();
			while(mf.Read(strText,40)!=0)//读出的文件不为空
			{
				if((CString)strText=="")
					return;
				m_booklist2.AddString((CString)strText);
				i++;
				mf.Seek(40*i,CFile::begin);//定位文件指针
			}
			::GlobalUnlock(hmem);
		}
	}
	
}
