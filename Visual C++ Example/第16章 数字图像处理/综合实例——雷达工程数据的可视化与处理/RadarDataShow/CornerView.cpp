// CornerView.cpp : implementation file
//

#include "stdafx.h"
#include "RadarDataShow.h"
#include "CornerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCornerView

IMPLEMENT_DYNCREATE(CCornerView, CView)

CCornerView::CCornerView()
{
	A_Num=35;
}

CCornerView::~CCornerView()
{
}


BEGIN_MESSAGE_MAP(CCornerView, CView)
	//{{AFX_MSG_MAP(CCornerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCornerView drawing

void CCornerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	CString xx,xian;
	char X_char[8];
	sprintf(X_char,"%d",A_Num+1);
	xx = (CString)X_char;
	xian="µÚ"+xx+"µÀ";
	pDC->TextOut(20,0,xian);
}
void CCornerView::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	((CSplitterWnd*)GetParent())->SetActivePane(1, 1);	
	
}
/////////////////////////////////////////////////////////////////////////////
// CCornerView diagnostics

#ifdef _DEBUG
void CCornerView::AssertValid() const
{
	CView::AssertValid();
}

void CCornerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCornerView message handlers
