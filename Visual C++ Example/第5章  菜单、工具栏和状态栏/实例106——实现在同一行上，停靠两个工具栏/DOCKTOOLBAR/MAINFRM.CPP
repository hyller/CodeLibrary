// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DockToolbar.h"

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
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
	//标准工具栏
	if (!m_wndToolBar.CreateEx(this, 
		TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP 
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) || 
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME)) 
	{ 
		TRACE0("Failed to create toolbar\n"); 
		return -1; // fail to create 
	} 
	//创建添加的工具栏
	if (!m_wndToolBar1.CreateEx(this, TBSTYLE_FLAT, 
		WS_CHILD | WS_VISIBLE | CBRS_TOP 
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) || 
		!m_wndToolBar1.LoadToolBar(IDR_TOOLBAR1)) 
	{ 
		
		TRACE0("Failed to create toolbar\n"); 
		return -1; // fail to create 
	} 

	//状态栏
	if (!m_wndStatusBar.Create(this) || 
		!m_wndStatusBar.SetIndicators(indicators, 
		sizeof(indicators)/sizeof(UINT))) 
	{ 
		TRACE0("Failed to create status bar\n"); 
		return -1; // fail to create 
	} 

	m_wndToolBar.EnableDocking(CBRS_ALIGN_TOP); 
	EnableDocking(CBRS_ALIGN_TOP); 
	DockControlBar(&m_wndToolBar);
	m_wndToolBar1.EnableDocking(CBRS_ALIGN_TOP); 
	EnableDocking(CBRS_ALIGN_ANY); 

	//找到要停靠的框架窗口 
	CControlBar* pDockedBar=&m_wndToolBar; 
	CFrameWnd* pFrame = pDockedBar->GetDockingFrame(); 
	//计算停靠工具栏的位置 
	pFrame->RecalcLayout(); 
	//计算已经停靠控制栏的矩形 
	CRect rcDock; 
	pDockedBar->GetWindowRect( &rcDock ); 
	//将矩形沿x,y轴偏移一个单位，这样新的控制栏可以停靠在已经已有控制栏 
	//的右边和底部 
	rcDock.OffsetRect(1,1); 
	//停靠新的工具栏 
	pFrame->DockControlBar( &m_wndToolBar1, AFX_IDW_DOCKBAR_TOP,&rcDock ); 

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

