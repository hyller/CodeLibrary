// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ProgressbarStatus.h"

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
	ON_COMMAND(ID_MENUTEST, OnMenutest)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_PROGRESS,//显示进度条窗格
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bCreated=false;
	
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


void CMainFrame::OnMenutest() 
{
	// TODO: Add your command handler code here
	//获得该格子的矩形区域
	CRect rect;
	m_wndStatusBar.GetItemRect(1, &rect);  
	//如果进度条控件尚未创建则先创建它
	if (m_bCreated == FALSE)
	{
		//创建进度条控件
		m_ProgressBar.Create(WS_VISIBLE|WS_CHILD, rect, &m_wndStatusBar, 1); 
		//设置进度条的数值范围
		m_ProgressBar.SetRange(0,100); 
		//设置进度条的步进数目
		m_ProgressBar.SetStep(1); 
		//进度条控件现在已经创建，把m_bProgressBarCreated置成TRUE
		m_bCreated = TRUE;
	}
	// 模拟一个耗时的运算过程
	for (int i = 0; i < 100; i++)
	{
		Sleep(50);
		m_ProgressBar.StepIt();
	}
	AfxMessageBox("运行结束！");	
}



void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
	//如果进度条已经创建了则调整它的尺寸，否则不作处理
	if (m_bCreated)
	{
		RECT rc;
		//获得显示区矩形
		m_wndStatusBar.GetItemRect(1, &rc);
		// 重新安排进度条控件的位置
		m_ProgressBar.SetWindowPos(&wndTop, rc.left, rc.top, rc.right - rc.left,rc.bottom - rc.top, 0); 
	}		
}
