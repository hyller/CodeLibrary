// UseKeyHookView.cpp : implementation of the CUseKeyHookView class
//

#include "stdafx.h"
#include "UseKeyHook.h"

#include "UseKeyHookDoc.h"
#include "UseKeyHookView.h"
#include "KeyHook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookView

IMPLEMENT_DYNCREATE(CUseKeyHookView, CEditView)

BEGIN_MESSAGE_MAP(CUseKeyHookView, CEditView)
	//{{AFX_MSG_MAP(CUseKeyHookView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookView construction/destruction

CUseKeyHookView::CUseKeyHookView()
{
	// TODO: add construction code here

}

CUseKeyHookView::~CUseKeyHookView()
{
}

BOOL CUseKeyHookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CEditView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookView drawing

void CUseKeyHookView::OnDraw(CDC* pDC)
{
	CUseKeyHookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookView printing

BOOL CUseKeyHookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUseKeyHookView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUseKeyHookView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookView diagnostics

#ifdef _DEBUG
void CUseKeyHookView::AssertValid() const
{
	CEditView::AssertValid();
}

void CUseKeyHookView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CUseKeyHookDoc* CUseKeyHookView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseKeyHookDoc)));
	return (CUseKeyHookDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookView message handlers

void CUseKeyHookView::OnInitialUpdate() 
{
	
	CEditView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class	
	OutEv();
}
