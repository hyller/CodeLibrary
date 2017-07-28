// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "OpenURL.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_OPENURL, OnOpenurl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnOpenurl() 
{
	// TODO: Add your command handler code here
	HKEY hkRoot,hSubKey;
	char ValueName[256];
	unsigned char DataValue[256];
	unsigned long chValueName=256;
	unsigned long chDataValue=256;
	char ShellChar[256];//定义命令行
	DWORD dwType;
	if(RegOpenKey(HKEY_CLASSES_ROOT,NULL,&hkRoot)==ERROR_SUCCESS)
	{
		if(RegOpenKeyEx( hkRoot, "htmlfile\\shell\\open\\command", 	//子目录
					0L,											//必须取0
					KEY_ALL_ACCESS,
					&hSubKey )==ERROR_SUCCESS)
		{
			//获取键值，即默认浏览器程序的路径
			RegEnumValue(hSubKey,0,ValueName,&chValueName,NULL,&dwType,DataValue,&chDataValue);
			strcpy(ShellChar,(char*)DataValue);
			strcat(ShellChar,(char*)"http://127.0.0.1");
			WinExec(ShellChar,SW_SHOW);//执行命令
		}
		else
			AfxMessageBox("Web浏览器打开错误！");
	}
	else
			AfxMessageBox("Web浏览器打开错误！");
	RegCloseKey(hSubKey);//关闭子键
	RegCloseKey(hkRoot);//关闭主键
}
