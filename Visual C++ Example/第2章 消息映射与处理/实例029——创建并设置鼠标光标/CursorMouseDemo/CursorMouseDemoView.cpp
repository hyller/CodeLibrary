// CursorMouseDemoView.cpp : implementation of the CCursorMouseDemoView class
//

#include "stdafx.h"
#include "CursorMouseDemo.h"
#include "MainFrm.h "
#include "CursorMouseDemoDoc.h"
#include "CursorMouseDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoView

IMPLEMENT_DYNCREATE(CCursorMouseDemoView, CView)

BEGIN_MESSAGE_MAP(CCursorMouseDemoView, CView)
	//{{AFX_MSG_MAP(CCursorMouseDemoView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoView construction/destruction

CCursorMouseDemoView::CCursorMouseDemoView()
{
	// TODO: add construction code here

}

CCursorMouseDemoView::~CCursorMouseDemoView()
{
}

BOOL CCursorMouseDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoView drawing

void CCursorMouseDemoView::OnDraw(CDC* pDC)
{
	CCursorMouseDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(5,5,"分别单击鼠标左键和右键，观察鼠标光标的变化!");

}

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoView printing

BOOL CCursorMouseDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCursorMouseDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCursorMouseDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoView diagnostics

#ifdef _DEBUG
void CCursorMouseDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CCursorMouseDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCursorMouseDemoDoc* CCursorMouseDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCursorMouseDemoDoc)));
	return (CCursorMouseDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoView message handlers

void CCursorMouseDemoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		CMainFrame* pMainframe;
	pMainframe=(CMainFrame*)AfxGetMainWnd();
	SetCursor(pMainframe->m_cursor);//设置光标为自绘光标
	
	CView::OnLButtonDown(nFlags, point);
}


void CCursorMouseDemoView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HCURSOR cusor=AfxGetApp( )->LoadStandardCursor(IDC_CROSS);		//获取系统标准光标
	SetCursor(cusor);											//设置光标
	CView::OnRButtonUp(nFlags, point);
}

void CCursorMouseDemoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame* pMainframe;
	pMainframe=(CMainFrame*)AfxGetMainWnd();
	SetCursor(pMainframe->m_cursor);//设置光标为自绘光标
	CView::OnLButtonUp(nFlags, point);
}
