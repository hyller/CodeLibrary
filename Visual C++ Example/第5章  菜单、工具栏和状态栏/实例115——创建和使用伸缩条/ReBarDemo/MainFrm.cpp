// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ReBarDemo.h"

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

	// 取消工具栏的停靠风格
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);
	//创建对话条，ID为创建的对话条IDD_DIALOGBAR，但并不在主框架上显示 
	if (!m_WzdDialogBar.Create(this, IDD_DIALOGBAR,WS_CHILD|WS_VISIBLE,-1))
	{
		TRACE0( "Failed to create dialog bar\n" );
		return -1; // fail to create
	}
	if(!m_wndReBar.Create(this))
	{
			return -1;
	}
	//将创建的对话条载入到伸缩条
	m_wndReBar.AddBar( &m_WzdDialogBar,"对话条", NULL,  RBBS_GRIPPERALWAYS | RBBS_FIXEDBMP);
	//将工具栏添加到伸缩条
	m_wndReBar.AddBar(&m_wndToolBar,"工具栏");
	//
	pEdit=new CEdit();
	CRect rect(0,0,100,20);						//编辑控件的大小位置
	if(!pEdit->Create(WS_CHILD|WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,rect,this, ID_EDIT))
	{
		AfxMessageBox("创建编辑框控件失败！");
		return false;
	}
	//将编辑控件2加载到伸缩条
	m_wndReBar.AddBar( pEdit,"控件", NULL,  RBBS_GRIPPERALWAYS | RBBS_FIXEDBMP);			
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


