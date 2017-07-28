// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "LimitUseTimers.h"

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
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};
int CMainFrame::usetimes=0;
const char CMainFrame::s_profile[]="Times";
const char CMainFrame::s_usedtimes[]="value";
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


void CMainFrame::ActivateFrame(int nCmdShow) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString strvalue;
	//从注册表中得到已经使用的次数
	strvalue=AfxGetApp()->GetProfileString(s_profile,s_usedtimes);
	CMainFrame::usetimes=atoi((const char *) strvalue);
	CMainFrame::usetimes++;
	//应用程序启动大于5次时，给出警告并退出应用程序
	if(CMainFrame::usetimes>5)
	{
		AfxMessageBox("使用次数已到，请联系购买一个正版使用",MB_OK);
		LPDWORD lpword;
		//得到当前进程
		GetExitCodeProcess(AfxGetInstanceHandle(),lpword);
		//终止进程而退出应用程序
		ExitProcess((UINT )lpword);
	}
	CFrameWnd::ActivateFrame(nCmdShow);
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	// TODO: Add your message handler code here
	CString strvalue;
	strvalue.Format("%d",CMainFrame::usetimes);
	AfxGetApp()->WriteProfileString(s_profile,s_usedtimes,strvalue);//将使用次数写入注册表	
}
