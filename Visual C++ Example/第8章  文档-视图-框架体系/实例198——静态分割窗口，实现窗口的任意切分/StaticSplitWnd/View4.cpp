// View4.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitWnd.h"
#include "View4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView4

IMPLEMENT_DYNCREATE(CView4, CView)

CView4::CView4()
{
}

CView4::~CView4()
{
}


BEGIN_MESSAGE_MAP(CView4, CView)
	//{{AFX_MSG_MAP(CView4)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView4 drawing

void CView4::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOut(10,10,"该窗格视图为CView4");
}

/////////////////////////////////////////////////////////////////////////////
// CView4 diagnostics

#ifdef _DEBUG
void CView4::AssertValid() const
{
	CView::AssertValid();
}

void CView4::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView4 message handlers
