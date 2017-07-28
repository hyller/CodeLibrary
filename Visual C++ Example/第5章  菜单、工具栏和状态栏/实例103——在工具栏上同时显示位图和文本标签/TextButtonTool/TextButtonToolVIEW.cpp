// TextButtonToolView.cpp : implementation of the CTextButtonToolView class
//

#include "stdafx.h"
#include "TextButtonTool.h"

#include "TextButtonToolDoc.h"
#include "TextButtonToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolView

IMPLEMENT_DYNCREATE(CTextButtonToolView, CView)

BEGIN_MESSAGE_MAP(CTextButtonToolView, CView)
	//{{AFX_MSG_MAP(CTextButtonToolView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolView construction/destruction

CTextButtonToolView::CTextButtonToolView()
{
	// TODO: add construction code here

}

CTextButtonToolView::~CTextButtonToolView()
{
}

BOOL CTextButtonToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATextButtonToolRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolView drawing

void CTextButtonToolView::OnDraw(CDC* pDC)
{
	CTextButtonToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolView printing

BOOL CTextButtonToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextButtonToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextButtonToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolView diagnostics

#ifdef _DEBUG
void CTextButtonToolView::AssertValid() const
{
	CView::AssertValid();
}

void CTextButtonToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextButtonToolDoc* CTextButtonToolView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextButtonToolDoc)));
	return (CTextButtonToolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolView message handlers
