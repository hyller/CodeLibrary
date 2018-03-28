// AutoHelpView.cpp : implementation of the CAutoHelpView class
//

#include "stdafx.h"
#include "AutoHelp.h"

#include "AutoHelpDoc.h"
#include "AutoHelpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpView

IMPLEMENT_DYNCREATE(CAutoHelpView, CView)

BEGIN_MESSAGE_MAP(CAutoHelpView, CView)
	//{{AFX_MSG_MAP(CAutoHelpView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpView construction/destruction

CAutoHelpView::CAutoHelpView()
{
	// TODO: add construction code here

}

CAutoHelpView::~CAutoHelpView()
{
}

BOOL CAutoHelpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpView drawing

void CAutoHelpView::OnDraw(CDC* pDC)
{
	CAutoHelpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpView printing

BOOL CAutoHelpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAutoHelpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAutoHelpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpView diagnostics

#ifdef _DEBUG
void CAutoHelpView::AssertValid() const
{
	CView::AssertValid();
}

void CAutoHelpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAutoHelpDoc* CAutoHelpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoHelpDoc)));
	return (CAutoHelpDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpView message handlers
