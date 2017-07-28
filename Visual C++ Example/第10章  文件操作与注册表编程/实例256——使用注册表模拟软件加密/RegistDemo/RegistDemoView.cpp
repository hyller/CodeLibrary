// RegistDemoView.cpp : implementation of the CRegistDemoView class
//

#include "stdafx.h"
#include "RegistDemo.h"

#include "RegistDemoDoc.h"
#include "RegistDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoView

IMPLEMENT_DYNCREATE(CRegistDemoView, CView)

BEGIN_MESSAGE_MAP(CRegistDemoView, CView)
	//{{AFX_MSG_MAP(CRegistDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoView construction/destruction

CRegistDemoView::CRegistDemoView()
{
	// TODO: add construction code here

}

CRegistDemoView::~CRegistDemoView()
{
}

BOOL CRegistDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoView drawing

void CRegistDemoView::OnDraw(CDC* pDC)
{
	CRegistDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoView printing

BOOL CRegistDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRegistDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRegistDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoView diagnostics

#ifdef _DEBUG
void CRegistDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CRegistDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRegistDemoDoc* CRegistDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRegistDemoDoc)));
	return (CRegistDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoView message handlers
