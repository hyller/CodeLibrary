// AscanView.cpp : implementation file
//

#include "stdafx.h"
#include "RadarDataShow.h"
#include "AscanView.h"
#include "RadarDataShowDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAscanView

IMPLEMENT_DYNCREATE(CAscanView, CView)

CAscanView::CAscanView()
{
	v_scroll_Draw=0;
}

CAscanView::~CAscanView()
{
}


BEGIN_MESSAGE_MAP(CAscanView, CView)
	//{{AFX_MSG_MAP(CAscanView)
	ON_WM_ERASEBKGND()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAscanView drawing

void CAscanView::OnDraw(CDC* pDC)
{
	// TODO: add draw code here
	CRadarDataShowDoc* pDoc =(CRadarDataShowDoc*)GetDocument();
	int i;
	CPen pen;
	pen.CreatePen(PS_SOLID,0,RGB(12,12,200));
	pDC->SelectObject(&pen);
	pDC->MoveTo(pDoc->lpBufPtr_Ascan[0]+5,0);
	for(i=1+v_scroll_Draw;i<pDoc->data_head.rh_nsamp-1;i++)
	{
	  pDC->LineTo(pDoc->lpBufPtr_Ascan[i]+5,i-v_scroll_Draw);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAscanView diagnostics

#ifdef _DEBUG
void CAscanView::AssertValid() const
{
	CView::AssertValid();
}

void CAscanView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAscanView message handlers

BOOL CAscanView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnEraseBkgnd(pDC);
}

void CAscanView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	
}

BOOL CAscanView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (cs.lpszClass == NULL)
	{
		HBRUSH hBr=CreateSolidBrush(RGB(200,200,200));
		cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS|CS_BYTEALIGNWINDOW, NULL, hBr);
	}
	
	return CView::PreCreateWindow(cs);
}

void CAscanView::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	((CSplitterWnd*)GetParent())->SetActivePane(1, 1);	
}
