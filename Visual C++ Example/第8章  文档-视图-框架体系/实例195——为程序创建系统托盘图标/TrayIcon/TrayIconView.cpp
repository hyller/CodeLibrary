// TrayIconView.cpp : implementation of the CTrayIconView class
//

#include "stdafx.h"
#include "TrayIcon.h"

#include "TrayIconDoc.h"
#include "TrayIconView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrayIconView

IMPLEMENT_DYNCREATE(CTrayIconView, CView)

BEGIN_MESSAGE_MAP(CTrayIconView, CView)
	//{{AFX_MSG_MAP(CTrayIconView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrayIconView construction/destruction

CTrayIconView::CTrayIconView()
{
	// TODO: add construction code here

}

CTrayIconView::~CTrayIconView()
{
}

BOOL CTrayIconView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTrayIconView drawing

void CTrayIconView::OnDraw(CDC* pDC)
{
	CTrayIconDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTrayIconView printing

BOOL CTrayIconView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTrayIconView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTrayIconView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTrayIconView diagnostics

#ifdef _DEBUG
void CTrayIconView::AssertValid() const
{
	CView::AssertValid();
}

void CTrayIconView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrayIconDoc* CTrayIconView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrayIconDoc)));
	return (CTrayIconDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrayIconView message handlers
