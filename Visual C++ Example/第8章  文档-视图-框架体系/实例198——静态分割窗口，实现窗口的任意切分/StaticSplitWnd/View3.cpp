// View3.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitWnd.h"
#include "View3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView3

IMPLEMENT_DYNCREATE(CView3, CView)

CView3::CView3()
{
}

CView3::~CView3()
{
}


BEGIN_MESSAGE_MAP(CView3, CView)
	//{{AFX_MSG_MAP(CView3)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView3 drawing

void CView3::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOut(10,10,"该窗格视图为CView3");
}

/////////////////////////////////////////////////////////////////////////////
// CView3 diagnostics

#ifdef _DEBUG
void CView3::AssertValid() const
{
	CView::AssertValid();
}

void CView3::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView3 message handlers
