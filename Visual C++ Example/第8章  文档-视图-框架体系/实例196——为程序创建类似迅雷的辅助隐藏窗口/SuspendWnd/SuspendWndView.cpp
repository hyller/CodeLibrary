// SuspendWndView.cpp : implementation of the CSuspendWndView class
//

#include "stdafx.h"
#include "SuspendWnd.h"

#include "SuspendWndDoc.h"
#include "SuspendWndView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndView

IMPLEMENT_DYNCREATE(CSuspendWndView, CView)

BEGIN_MESSAGE_MAP(CSuspendWndView, CView)
	//{{AFX_MSG_MAP(CSuspendWndView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndView construction/destruction

CSuspendWndView::CSuspendWndView()
{
	// TODO: add construction code here

}

CSuspendWndView::~CSuspendWndView()
{
}

BOOL CSuspendWndView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndView drawing

void CSuspendWndView::OnDraw(CDC* pDC)
{
	CSuspendWndDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndView printing

BOOL CSuspendWndView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSuspendWndView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSuspendWndView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndView diagnostics

#ifdef _DEBUG
void CSuspendWndView::AssertValid() const
{
	CView::AssertValid();
}

void CSuspendWndView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSuspendWndDoc* CSuspendWndView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSuspendWndDoc)));
	return (CSuspendWndDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndView message handlers
