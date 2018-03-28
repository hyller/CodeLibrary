// View2.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitWnd3.h"
#include "View2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView2

IMPLEMENT_DYNCREATE(CView2, CView)

CView2::CView2()
{
}

CView2::~CView2()
{
}


BEGIN_MESSAGE_MAP(CView2, CView)
	//{{AFX_MSG_MAP(CView2)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView2 drawing

void CView2::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOut(10,10,"该窗格视图为CView2,该窗格大小不能通过拖动改变");
}

/////////////////////////////////////////////////////////////////////////////
// CView2 diagnostics

#ifdef _DEBUG
void CView2::AssertValid() const
{
	CView::AssertValid();
}

void CView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView2 message handlers
