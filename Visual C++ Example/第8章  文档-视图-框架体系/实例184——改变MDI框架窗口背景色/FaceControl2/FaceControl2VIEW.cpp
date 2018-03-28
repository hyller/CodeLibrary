// FaceControl2View.cpp : implementation of the CFaceControl2View class
//

#include "stdafx.h"
#include "FaceControl2.h"

#include "FaceControl2Doc.h"
#include "FaceControl2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2View

IMPLEMENT_DYNCREATE(CFaceControl2View, CView)

BEGIN_MESSAGE_MAP(CFaceControl2View, CView)
	//{{AFX_MSG_MAP(CFaceControl2View)
	ON_COMMAND(ID_CHAGEVIEWBK, OnChageviewbk)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2View construction/destruction

CFaceControl2View::CFaceControl2View()
{
	// TODO: add construction code here
	m_rgbBack = RGB(128 , 128 , 128);

}

CFaceControl2View::~CFaceControl2View()
{
}

BOOL CFaceControl2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2View drawing

void CFaceControl2View::OnDraw(CDC* pDC)
{
	CFaceControl2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2View printing

BOOL CFaceControl2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFaceControl2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFaceControl2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2View diagnostics

#ifdef _DEBUG
void CFaceControl2View::AssertValid() const
{
	CView::AssertValid();
}

void CFaceControl2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFaceControl2Doc* CFaceControl2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFaceControl2Doc)));
	return (CFaceControl2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2View message handlers

void CFaceControl2View::OnChageviewbk() //改变背景色
{
	// TODO: Add your command handler code here
	m_rgbBack=RGB(0,128,128);
	Invalidate(true);
}

BOOL CFaceControl2View::OnEraseBkgnd(CDC* pDC) 
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
