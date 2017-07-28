// ProgressbarStatusView.cpp : implementation of the CProgressbarStatusView class
//

#include "stdafx.h"
#include "ProgressbarStatus.h"

#include "ProgressbarStatusDoc.h"
#include "ProgressbarStatusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusView

IMPLEMENT_DYNCREATE(CProgressbarStatusView, CView)

BEGIN_MESSAGE_MAP(CProgressbarStatusView, CView)
	//{{AFX_MSG_MAP(CProgressbarStatusView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusView construction/destruction

CProgressbarStatusView::CProgressbarStatusView()
{
	// TODO: add construction code here

}

CProgressbarStatusView::~CProgressbarStatusView()
{
}

BOOL CProgressbarStatusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusView drawing

void CProgressbarStatusView::OnDraw(CDC* pDC)
{
	CProgressbarStatusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,30,"在状态栏中显示进度条，通过菜单命令模拟进度条的运行。");
}

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusView printing

BOOL CProgressbarStatusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProgressbarStatusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProgressbarStatusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusView diagnostics

#ifdef _DEBUG
void CProgressbarStatusView::AssertValid() const
{
	CView::AssertValid();
}

void CProgressbarStatusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProgressbarStatusDoc* CProgressbarStatusView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProgressbarStatusDoc)));
	return (CProgressbarStatusDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusView message handlers
