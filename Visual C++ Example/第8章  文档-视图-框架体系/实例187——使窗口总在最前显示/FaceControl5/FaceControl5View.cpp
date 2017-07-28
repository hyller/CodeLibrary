// FaceControl5View.cpp : implementation of the CFaceControl5View class
//

#include "stdafx.h"
#include "FaceControl5.h"

#include "FaceControl5Doc.h"
#include "FaceControl5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5View

IMPLEMENT_DYNCREATE(CFaceControl5View, CView)

BEGIN_MESSAGE_MAP(CFaceControl5View, CView)
	//{{AFX_MSG_MAP(CFaceControl5View)
	ON_COMMAND(ID_CHAGEVIEWBK, OnChageviewbk)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_CHANGEFRAMEICON, OnChangeframeicon)
	ON_COMMAND(ID_CHANGECHILDICON, OnChangechildicon)
	ON_COMMAND(ID_ALMOSTTOP, OnAlmosttop)
	ON_UPDATE_COMMAND_UI(ID_ALMOSTTOP, OnUpdateAlmosttop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5View construction/destruction

CFaceControl5View::CFaceControl5View()
{
	// TODO: add construction code here
	m_rgbBack = RGB(128 , 128 , 128);
	m_bTop=false;

}

CFaceControl5View::~CFaceControl5View()
{
}

BOOL CFaceControl5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5View drawing

void CFaceControl5View::OnDraw(CDC* pDC)
{
	CFaceControl5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5View printing

BOOL CFaceControl5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFaceControl5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFaceControl5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5View diagnostics

#ifdef _DEBUG
void CFaceControl5View::AssertValid() const
{
	CView::AssertValid();
}

void CFaceControl5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFaceControl5Doc* CFaceControl5View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFaceControl5Doc)));
	return (CFaceControl5Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5View message handlers

void CFaceControl5View::OnChageviewbk() //改变背景色
{
	// TODO: Add your command handler code here
	m_rgbBack=RGB(0,128,128);
	Invalidate(true);
}

BOOL CFaceControl5View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CBrush Brush (m_rgbBack);	// 创建一个新的刷子
	CBrush* pOldBrush = pDC->SelectObject (&Brush);	// 把刷子选入设备环境
	//获得需要檫除背景的区域
	CRect reClip;
	GetClientRect(&reClip);
	//重绘该区域
	pDC->PatBlt(reClip.left , reClip.top , reClip.Width () , reClip.Height() , PATCOPY);
	//释放刷子
	pDC->SelectObject (pOldBrush);
	return TRUE;//必须返回TURE
	//return CView::OnEraseBkgnd(pDC);
}

void CFaceControl5View::OnChangeframeicon() 
{
	// TODO: Add your command handler code here
	HICON hIcon=AfxGetApp() ->LoadIcon(IDI_ICON1);//加载图标资源
	ASSERT(hIcon);
	AfxGetMainWnd()->SendMessage(WM_SETICON ,TRUE,(LPARAM)hIcon);//向主框架发送消息更改图标	
}

void CFaceControl5View::OnChangechildicon() 
{
	// TODO: Add your command handler code here
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);//加载图标资源
	ASSERT(hIcon);
	GetParent()->SendMessage(WM_SETICON,TRUE,(LPARAM)hIcon);//向子框架发送消息更改图标	
}

void CFaceControl5View::OnAlmosttop() //菜单命令函数
{
	// TODO: Add your command handler code here
	if (!m_bTop)
	{
		AfxGetMainWnd()->SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
		m_bTop = TRUE;
	}
	else
	{
		AfxGetMainWnd()->SetWindowPos(&wndNoTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
		m_bTop = FALSE;
	}	
}

void CFaceControl5View::OnUpdateAlmosttop(CCmdUI* pCmdUI) //菜单更新函数
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bTop);		
}
