// DialogBarDemoView.cpp : implementation of the CDialogBarDemoView class
//

#include "stdafx.h"
#include "DialogBarDemo.h"

#include "DialogBarDemoDoc.h"
#include "DialogBarDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoView

IMPLEMENT_DYNCREATE(CDialogBarDemoView, CView)

BEGIN_MESSAGE_MAP(CDialogBarDemoView, CView)
	//{{AFX_MSG_MAP(CDialogBarDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoView construction/destruction

CDialogBarDemoView::CDialogBarDemoView()
{
	// TODO: add construction code here

}

CDialogBarDemoView::~CDialogBarDemoView()
{
}

BOOL CDialogBarDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoView drawing

void CDialogBarDemoView::OnDraw(CDC* pDC)
{
	CDialogBarDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,30,"创建和使用对话条");
}

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoView printing

BOOL CDialogBarDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDialogBarDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDialogBarDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoView diagnostics

#ifdef _DEBUG
void CDialogBarDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogBarDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogBarDemoDoc* CDialogBarDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogBarDemoDoc)));
	return (CDialogBarDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoView message handlers
