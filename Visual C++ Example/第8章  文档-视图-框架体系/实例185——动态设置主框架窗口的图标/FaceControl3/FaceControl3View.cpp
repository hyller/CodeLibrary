// FaceControl3View.cpp : implementation of the CFaceControl3View class
//

#include "stdafx.h"
#include "FaceControl3.h"

#include "FaceControl3Doc.h"
#include "FaceControl3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3View

IMPLEMENT_DYNCREATE(CFaceControl3View, CView)

BEGIN_MESSAGE_MAP(CFaceControl3View, CView)
	//{{AFX_MSG_MAP(CFaceControl3View)
	ON_COMMAND(ID_CHAGEVIEWBK, OnChageviewbk)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_CHANGEFRAMEICON, OnChangeframeicon)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3View construction/destruction

CFaceControl3View::CFaceControl3View()
{
	// TODO: add construction code here
	m_rgbBack = RGB(128 , 128 , 128);

}

CFaceControl3View::~CFaceControl3View()
{
}

BOOL CFaceControl3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3View drawing

void CFaceControl3View::OnDraw(CDC* pDC)
{
	CFaceControl3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3View printing

BOOL CFaceControl3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFaceControl3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFaceControl3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3View diagnostics

#ifdef _DEBUG
void CFaceControl3View::AssertValid() const
{
	CView::AssertValid();
}

void CFaceControl3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFaceControl3Doc* CFaceControl3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFaceControl3Doc)));
	return (CFaceControl3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3View message handlers

void CFaceControl3View::OnChageviewbk() //改变背景色
{
	// TODO: Add your command handler code here
	m_rgbBack=RGB(0,128,128);
	Invalidate(true);
}

BOOL CFaceControl3View::OnEraseBkgnd(CDC* pDC) 
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

void CFaceControl3View::OnChangeframeicon() 
{
	// TODO: Add your command handler code here
	HICON hIcon=AfxGetApp() ->LoadIcon(IDI_ICON1);//加载图标资源
	ASSERT(hIcon);
	AfxGetMainWnd()->SendMessage(WM_SETICON ,TRUE,(LPARAM)hIcon);//向主框架发送消息更改图标	
}
