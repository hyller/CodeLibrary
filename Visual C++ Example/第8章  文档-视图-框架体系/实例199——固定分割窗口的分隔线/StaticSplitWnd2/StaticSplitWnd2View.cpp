// StaticSplitWnd2View.cpp : implementation of the CStaticSplitWnd2View class
//

#include "stdafx.h"
#include "StaticSplitWnd2.h"

#include "StaticSplitWnd2Doc.h"
#include "StaticSplitWnd2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2View

IMPLEMENT_DYNCREATE(CStaticSplitWnd2View, CView)

BEGIN_MESSAGE_MAP(CStaticSplitWnd2View, CView)
	//{{AFX_MSG_MAP(CStaticSplitWnd2View)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2View construction/destruction

CStaticSplitWnd2View::CStaticSplitWnd2View()
{
	// TODO: add construction code here

}

CStaticSplitWnd2View::~CStaticSplitWnd2View()
{
}

BOOL CStaticSplitWnd2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2View drawing

void CStaticSplitWnd2View::OnDraw(CDC* pDC)
{
//	CStaticSplitWnd2Doc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"该窗格视图为CStaticSplitWnd2View,该窗格大小不能通过拖动改变");
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2View printing

BOOL CStaticSplitWnd2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStaticSplitWnd2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStaticSplitWnd2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2View diagnostics

#ifdef _DEBUG
void CStaticSplitWnd2View::AssertValid() const
{
	CView::AssertValid();
}

void CStaticSplitWnd2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

/*CStaticSplitWnd2Doc* CStaticSplitWnd2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticSplitWnd2Doc)));
	return (CStaticSplitWnd2Doc*)m_pDocument;
}*/
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2View message handlers

void CStaticSplitWnd2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}

void CStaticSplitWnd2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
}

BOOL CStaticSplitWnd2View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnSetCursor(pWnd, nHitTest, message);
}
