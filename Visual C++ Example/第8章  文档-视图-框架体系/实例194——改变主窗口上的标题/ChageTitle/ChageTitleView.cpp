// ChageTitleView.cpp : implementation of the CChageTitleView class
//

#include "stdafx.h"
#include "ChageTitle.h"

#include "ChageTitleDoc.h"
#include "ChageTitleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChageTitleView

IMPLEMENT_DYNCREATE(CChageTitleView, CView)

BEGIN_MESSAGE_MAP(CChageTitleView, CView)
	//{{AFX_MSG_MAP(CChageTitleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChageTitleView construction/destruction

CChageTitleView::CChageTitleView()
{
	// TODO: add construction code here

}

CChageTitleView::~CChageTitleView()
{
}

BOOL CChageTitleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChageTitleView drawing

void CChageTitleView::OnDraw(CDC* pDC)
{
	CChageTitleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"更改窗口标题");
}

/////////////////////////////////////////////////////////////////////////////
// CChageTitleView printing

BOOL CChageTitleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChageTitleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChageTitleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChageTitleView diagnostics

#ifdef _DEBUG
void CChageTitleView::AssertValid() const
{
	CView::AssertValid();
}

void CChageTitleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChageTitleDoc* CChageTitleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChageTitleDoc)));
	return (CChageTitleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChageTitleView message handlers
