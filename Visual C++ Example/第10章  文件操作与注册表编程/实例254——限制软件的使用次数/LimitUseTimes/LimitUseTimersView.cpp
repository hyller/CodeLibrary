// LimitUseTimersView.cpp : implementation of the CLimitUseTimersView class
//

#include "stdafx.h"
#include "LimitUseTimers.h"

#include "LimitUseTimersDoc.h"
#include "LimitUseTimersView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersView

IMPLEMENT_DYNCREATE(CLimitUseTimersView, CView)

BEGIN_MESSAGE_MAP(CLimitUseTimersView, CView)
	//{{AFX_MSG_MAP(CLimitUseTimersView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersView construction/destruction

CLimitUseTimersView::CLimitUseTimersView()
{
	// TODO: add construction code here

}

CLimitUseTimersView::~CLimitUseTimersView()
{
}

BOOL CLimitUseTimersView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersView drawing

void CLimitUseTimersView::OnDraw(CDC* pDC)
{
	CLimitUseTimersDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersView printing

BOOL CLimitUseTimersView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLimitUseTimersView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLimitUseTimersView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersView diagnostics

#ifdef _DEBUG
void CLimitUseTimersView::AssertValid() const
{
	CView::AssertValid();
}

void CLimitUseTimersView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLimitUseTimersDoc* CLimitUseTimersView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLimitUseTimersDoc)));
	return (CLimitUseTimersDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersView message handlers
