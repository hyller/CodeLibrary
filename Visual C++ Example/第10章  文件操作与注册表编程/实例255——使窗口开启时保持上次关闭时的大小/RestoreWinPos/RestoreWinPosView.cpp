// RestoreWinPosView.cpp : implementation of the CRestoreWinPosView class
//

#include "stdafx.h"
#include "RestoreWinPos.h"

#include "RestoreWinPosDoc.h"
#include "RestoreWinPosView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosView

IMPLEMENT_DYNCREATE(CRestoreWinPosView, CView)

BEGIN_MESSAGE_MAP(CRestoreWinPosView, CView)
	//{{AFX_MSG_MAP(CRestoreWinPosView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosView construction/destruction

CRestoreWinPosView::CRestoreWinPosView()
{
	// TODO: add construction code here

}

CRestoreWinPosView::~CRestoreWinPosView()
{
}

BOOL CRestoreWinPosView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosView drawing

void CRestoreWinPosView::OnDraw(CDC* pDC)
{
	CRestoreWinPosDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(20,20,"关闭窗口后，重新运行程序，窗口的大小与上次关闭时相同");
}

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosView printing

BOOL CRestoreWinPosView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRestoreWinPosView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRestoreWinPosView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosView diagnostics

#ifdef _DEBUG
void CRestoreWinPosView::AssertValid() const
{
	CView::AssertValid();
}

void CRestoreWinPosView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRestoreWinPosDoc* CRestoreWinPosView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRestoreWinPosDoc)));
	return (CRestoreWinPosDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosView message handlers
