// CMyOdbcExcelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CMyOdbcExcel.h"
#include "CMyOdbcExcelDlg.h"

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
// CCMyOdbcExcelDlg dialog

CCMyOdbcExcelDlg::CCMyOdbcExcelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCMyOdbcExcelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMyOdbcExcelDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCMyOdbcExcelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMyOdbcExcelDlg)
	DDX_Control(pDX, IDC_LISTEXCEL, m_nExcelList);
	DDX_Control(pDX, IDC_BUTTON_WRITE, m_nWrite);
	DDX_Control(pDX, IDC_BUTTON_READ, m_nRead);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCMyOdbcExcelDlg, CDialog)
	//{{AFX_MSG_MAP(CCMyOdbcExcelDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_READ, OnButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_WRITE, OnButtonWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMyOdbcExcelDlg message handlers

BOOL CCMyOdbcExcelDlg::OnInitDialog()
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

void CCMyOdbcExcelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCMyOdbcExcelDlg::OnPaint() 
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
HCURSOR CCMyOdbcExcelDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCMyOdbcExcelDlg::OnButtonRead() 
{
	// TODO: Add your control notification handler code here
	CDatabase database;
    CString sSql;
    CString sItem1, sItem2,sItem3;
    CString sDriver;
    CString sDsn;
    CString sFile,sPath;                              
	//获取主程序所在路径,存在sPath中
	GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
	sPath.ReleaseBuffer ();
    int nPos;
	nPos=sPath.ReverseFind ('\\');
	sPath=sPath.Left (nPos);
	sFile = sPath + "\\ExelDemo.xls"; 			// 将被读取的Excel文件名
    // 检索是否安装有Excel驱动 "Microsoft Excel Driver (*.xls)" 
    sDriver = GetExcelDriver();
    if (sDriver.IsEmpty())// 没有发现Excel驱动
    {
        AfxMessageBox("没有安装Excel驱动!");
        return;
    }
    // 创建进行存取的字符串
    sDsn.Format("ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);
    TRY
    {
        database.Open(NULL, false, false, sDsn); // 打开数据库(既Excel文件)
        CRecordset recset(&database);
        sSql = "SELECT Num,Name,Sex FROM Student ORDER BY Name";        
        // 执行查询语句
        recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);
        while (!recset.IsEOF())// 获取查询结果
        {
            //读取Excel内部数值
			recset.GetFieldValue("Num", sItem1);
            recset.GetFieldValue("Name", sItem2);
            recset.GetFieldValue("Sex", sItem3);
			m_nExcelList.AddString( sItem1 + "       "+sItem2+ "       "+sItem3);
            recset.MoveNext();// 移到下一行
        }
        database.Close();     // 关闭数据库                   
    }
    CATCH(CDBException, e)
    {
        AfxMessageBox("数据库错误: " + e->m_strError);
    }
    END_CATCH;
}

void CCMyOdbcExcelDlg::OnButtonWrite() 
{
	// TODO: Add your control notification handler code here
  CDatabase database;
  CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel安装驱动
  CString sExcelFile,sPath; 
  CString sSql;
  //获取主程序所在路径,存在sPath中
  GetModuleFileName(NULL,sPath.GetBufferSetLength (MAX_PATH+1),MAX_PATH);
  sPath.ReleaseBuffer ();
  int nPos;
  nPos=sPath.ReverseFind ('\\');
  sPath=sPath.Left (nPos);
  sExcelFile = sPath + "\\ExelDemo.xls"; 			// 要建立的Excel文件
  TRY
  {
    // 创建进行存取的字符串
    sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, sExcelFile, sExcelFile);
    if( database.OpenEx(sSql,CDatabase::noOdbcDialog) )// 创建数据库 (既Excel表格文件)
    {
      // 创建表结构(姓名、性别、年龄)
      sSql = "CREATE TABLE Student (Num TEXT,Name TEXT,Sex TEXT)";
      database.ExecuteSQL(sSql);
      // 插入数值
      sSql = "INSERT INTO Student (Num,Name,Sex) VALUES ('97001','小王','男')";
      database.ExecuteSQL(sSql);
      sSql = "INSERT INTO Student (Num,Name,Sex) VALUES ('97002','小红','女')";
      database.ExecuteSQL(sSql);
    }      
    // 关闭数据库
    database.Close();
	AfxMessageBox("Excel文件写入成功！");
  }
  CATCH_ALL(e)
  {
    TRACE1("Excel驱动没有安装: %s",sDriver);
  }
  END_CATCH_ALL;	
}

CString CCMyOdbcExcelDlg::GetExcelDriver()
{
	 char szBuf[2001];
    WORD cbBufMax = 2000;
    WORD cbBufOut;
    char *pszBuf = szBuf;
    CString sDriver;
    // 获取已安装驱动的名称(涵数在odbcinst.h里)
    if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))
        return "";
    // 检索已安装的驱动是否有Excel
    do
    {
        if (strstr(pszBuf, "Excel") != 0)
        {
            sDriver = CString(pszBuf);
            break;
        }
        pszBuf = strchr(pszBuf, '\0') + 1;
    }
    while (pszBuf[1] != '\0');
    return sDriver;
}
