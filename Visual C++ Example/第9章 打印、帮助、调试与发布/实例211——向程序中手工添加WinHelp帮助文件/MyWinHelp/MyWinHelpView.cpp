// MyWinHelpView.cpp : implementation of the CMyWinHelpView class
//

#include "stdafx.h"
#include "MyWinHelp.h"

#include "MyWinHelpDoc.h"
#include "MyWinHelpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpView

IMPLEMENT_DYNCREATE(CMyWinHelpView, CView)

BEGIN_MESSAGE_MAP(CMyWinHelpView, CView)
	//{{AFX_MSG_MAP(CMyWinHelpView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpView construction/destruction

CMyWinHelpView::CMyWinHelpView()
{
	// TODO: add construction code here

}

CMyWinHelpView::~CMyWinHelpView()
{
}

BOOL CMyWinHelpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpView drawing

void CMyWinHelpView::OnDraw(CDC* pDC)
{
	CMyWinHelpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpView printing

BOOL CMyWinHelpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyWinHelpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyWinHelpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpView diagnostics

#ifdef _DEBUG
void CMyWinHelpView::AssertValid() const
{
	CView::AssertValid();
}

void CMyWinHelpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyWinHelpDoc* CMyWinHelpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyWinHelpDoc)));
	return (CMyWinHelpDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpView message handlers
