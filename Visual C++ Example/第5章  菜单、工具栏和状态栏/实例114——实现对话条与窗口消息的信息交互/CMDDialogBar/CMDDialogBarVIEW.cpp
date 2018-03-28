// CMDDialogBarView.cpp : implementation of the CCMDDialogBarView class
//

#include "stdafx.h"
#include "CMDDialogBar.h"

#include "CMDDialogBarDoc.h"
#include "CMDDialogBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarView

IMPLEMENT_DYNCREATE(CCMDDialogBarView, CView)

BEGIN_MESSAGE_MAP(CCMDDialogBarView, CView)
	//{{AFX_MSG_MAP(CCMDDialogBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarView construction/destruction

CCMDDialogBarView::CCMDDialogBarView()
{
	// TODO: add construction code here

}

CCMDDialogBarView::~CCMDDialogBarView()
{
}

BOOL CCMDDialogBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarView drawing

void CCMDDialogBarView::OnDraw(CDC* pDC)
{
	CCMDDialogBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,30,"创建和使用对话条");
}

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarView printing

BOOL CCMDDialogBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCMDDialogBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCMDDialogBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarView diagnostics

#ifdef _DEBUG
void CCMDDialogBarView::AssertValid() const
{
	CView::AssertValid();
}

void CCMDDialogBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCMDDialogBarDoc* CCMDDialogBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCMDDialogBarDoc)));
	return (CCMDDialogBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarView message handlers
