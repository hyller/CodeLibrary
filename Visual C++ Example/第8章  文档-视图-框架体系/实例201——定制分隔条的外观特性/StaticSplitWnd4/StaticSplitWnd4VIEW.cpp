// StaticSplitWnd4View.cpp : implementation of the CStaticSplitWnd4View class
//

#include "stdafx.h"
#include "StaticSplitWnd4.h"

#include "StaticSplitWnd4Doc.h"
#include "StaticSplitWnd4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4View

IMPLEMENT_DYNCREATE(CStaticSplitWnd4View, CView)

BEGIN_MESSAGE_MAP(CStaticSplitWnd4View, CView)
	//{{AFX_MSG_MAP(CStaticSplitWnd4View)
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
// CStaticSplitWnd4View construction/destruction

CStaticSplitWnd4View::CStaticSplitWnd4View()
{
	// TODO: add construction code here

}

CStaticSplitWnd4View::~CStaticSplitWnd4View()
{
}

BOOL CStaticSplitWnd4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4View drawing

void CStaticSplitWnd4View::OnDraw(CDC* pDC)
{
//	CStaticSplitWnd4Doc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"该窗格视图为CStaticSplitWnd4View,该窗格大小不能通过拖动改变");
	pDC->TextOut(10,30,"可通过菜单命令动态改变大小");
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4View printing

BOOL CStaticSplitWnd4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStaticSplitWnd4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStaticSplitWnd4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4View diagnostics

#ifdef _DEBUG
void CStaticSplitWnd4View::AssertValid() const
{
	CView::AssertValid();
}

void CStaticSplitWnd4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

/*CStaticSplitWnd4Doc* CStaticSplitWnd4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticSplitWnd4Doc)));
	return (CStaticSplitWnd4Doc*)m_pDocument;
}*/
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4View message handlers

void CStaticSplitWnd4View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}

void CStaticSplitWnd4View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
}

BOOL CStaticSplitWnd4View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnSetCursor(pWnd, nHitTest, message);
}
