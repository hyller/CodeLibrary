// DockToolbarView.cpp : implementation of the CDockToolbarView class
//

#include "stdafx.h"
#include "DockToolbar.h"

#include "DockToolbarDoc.h"
#include "DockToolbarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarView

IMPLEMENT_DYNCREATE(CDockToolbarView, CView)

BEGIN_MESSAGE_MAP(CDockToolbarView, CView)
	//{{AFX_MSG_MAP(CDockToolbarView)
	ON_COMMAND(ID_BUTTON32771, OnButton32771)
	ON_COMMAND(ID_BUTTON32772, OnButton32772)
	ON_COMMAND(ID_BUTTON32773, OnButton32773)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarView construction/destruction

CDockToolbarView::CDockToolbarView()
{
	// TODO: add construction code here

}

CDockToolbarView::~CDockToolbarView()
{
}

BOOL CDockToolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarView drawing

void CDockToolbarView::OnDraw(CDC* pDC)
{
	CDockToolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarView printing

BOOL CDockToolbarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDockToolbarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDockToolbarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarView diagnostics

#ifdef _DEBUG
void CDockToolbarView::AssertValid() const
{
	CView::AssertValid();
}

void CDockToolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDockToolbarDoc* CDockToolbarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDockToolbarDoc)));
	return (CDockToolbarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarView message handlers

void CDockToolbarView::OnButton32771() 
{
	// TODO: Add your command handler code here
	
}

void CDockToolbarView::OnButton32772() 
{
	// TODO: Add your command handler code here
	
}

void CDockToolbarView::OnButton32773() 
{
	// TODO: Add your command handler code here
	
}
