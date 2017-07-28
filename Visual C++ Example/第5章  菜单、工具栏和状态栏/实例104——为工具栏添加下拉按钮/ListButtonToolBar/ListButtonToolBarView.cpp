// ListButtonToolBarView.cpp : implementation of the CListButtonToolBarView class
//

#include "stdafx.h"
#include "ListButtonToolBar.h"

#include "ListButtonToolBarDoc.h"
#include "ListButtonToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarView

IMPLEMENT_DYNCREATE(CListButtonToolBarView, CView)

BEGIN_MESSAGE_MAP(CListButtonToolBarView, CView)
	//{{AFX_MSG_MAP(CListButtonToolBarView)
	ON_COMMAND(ID_MENUITEM32775, OnMenuitem32775)
	ON_COMMAND(ID_MENUITEM32777, OnMenuitem32777)
	ON_COMMAND(ID_MENUITEM32778, OnMenuitem32778)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarView construction/destruction

CListButtonToolBarView::CListButtonToolBarView()
{
	// TODO: add construction code here

}

CListButtonToolBarView::~CListButtonToolBarView()
{
}

BOOL CListButtonToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarView drawing

void CListButtonToolBarView::OnDraw(CDC* pDC)
{
	CListButtonToolBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarView printing

BOOL CListButtonToolBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CListButtonToolBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CListButtonToolBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarView diagnostics

#ifdef _DEBUG
void CListButtonToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CListButtonToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CListButtonToolBarDoc* CListButtonToolBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListButtonToolBarDoc)));
	return (CListButtonToolBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarView message handlers

void CListButtonToolBarView::OnMenuitem32775() 
{
	// TODO: Add your command handler code here
	AfxMessageBox("绘制正方形！");
	
}

void CListButtonToolBarView::OnMenuitem32777() 
{
	// TODO: Add your command handler code here
		AfxMessageBox("绘制矩形！");
	
}

void CListButtonToolBarView::OnMenuitem32778() 
{
	// TODO: Add your command handler code here
		AfxMessageBox("绘制圆角矩形！");
	
}
