// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TextButtonTool.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static TCHAR *TextTips[]={"新建","打开","存盘","",
							"剪切","复制","粘贴","",
							"打印","",
							"关于","矩形",""};
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_TOOL_TEXTTIPS, OnToolTexttips)
	ON_UPDATE_COMMAND_UI(ID_TOOL_TEXTTIPS, OnUpdateToolTexttips)
	ON_WM_SETTINGCHANGE()
	ON_COMMAND(ID_BUTTON32772, OnButton32772)
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
//	m_bTextTips=AfxGetApp()->GetProfileInt("setting","m_bTextTips",1);
	
}

CMainFrame::~CMainFrame()
{
	//AfxGetApp()->GetProfileInt("setting","m_bTextTips",m_bTextTips);
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
	///调整工具条尺寸
	UpdateToolBar();

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

void CMainFrame::OnUpdateToolTexttips(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(m_bTextTips);
}

void CMainFrame::OnToolTexttips()
{
	m_bTextTips=!m_bTextTips;
	UpdateToolBar(FALSE);
}

////当系统调整后修改按钮尺寸
void CMainFrame::OnSettingChange(UINT uFlags, LPCTSTR lpszSection) 
{
	CFrameWnd::OnSettingChange(uFlags, lpszSection);
	UpdateToolBar();
}

void CMainFrame::UpdateToolBar(BOOL bRecalc) //bRecalc用于指示是否重新计算尺寸
{
	CRect rect;
	SIZE sizeButton,sizeImage;
	if(bRecalc)//重新计算
	{
		m_sizeMax.cx = 0;
		m_sizeMax.cy = 0;
		for (int i=0;i<m_wndToolBar.GetCount();i++)//取得按钮控件最大尺寸
		{
			m_wndToolBar.SetButtonText(i,TextTips[i]);
			m_wndToolBar.GetItemRect(i,rect);
			m_sizeMax.cx = __max(rect.Size().cx, m_sizeMax.cx);
			m_sizeMax.cy = __max(rect.Size().cy, m_sizeMax.cy);
		}
	}
	//设置按钮尺寸
	sizeButton.cx = m_bTextTips ? m_sizeMax.cx : 23;
	sizeButton.cy = m_bTextTips ? m_sizeMax.cy : 22;
	sizeImage.cx = 16;
	sizeImage.cy = 15;
	m_wndToolBar.SetSizes(sizeButton,sizeImage);//设置按钮大小以及其上位图大小
	ShowControlBar(&m_wndToolBar,TRUE,FALSE);//显示工具栏
	m_wndToolBar.RedrawWindow();//重绘工具栏
}

void CMainFrame::OnButton32772() 
{
	// TODO: Add your command handler code here
	
}
