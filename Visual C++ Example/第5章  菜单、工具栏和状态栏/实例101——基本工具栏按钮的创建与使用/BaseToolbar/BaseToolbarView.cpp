// BaseToolbarView.cpp : implementation of the CBaseToolbarView class
//

#include "stdafx.h"
#include "BaseToolbar.h"

#include "BaseToolbarDoc.h"
#include "BaseToolbarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarView

IMPLEMENT_DYNCREATE(CBaseToolbarView, CView)

BEGIN_MESSAGE_MAP(CBaseToolbarView, CView)
	//{{AFX_MSG_MAP(CBaseToolbarView)
	ON_COMMAND(ID_BUTTONSTAR, OnButtonstar)
	ON_COMMAND(ID_BUTTONSTOP, OnButtonstop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarView construction/destruction

CBaseToolbarView::CBaseToolbarView()
{
	// TODO: add construction code here

}

CBaseToolbarView::~CBaseToolbarView()
{
}

BOOL CBaseToolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarView drawing

void CBaseToolbarView::OnDraw(CDC* pDC)
{
	CBaseToolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarView printing

BOOL CBaseToolbarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseToolbarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseToolbarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarView diagnostics

#ifdef _DEBUG
void CBaseToolbarView::AssertValid() const
{
	CView::AssertValid();
}

void CBaseToolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseToolbarDoc* CBaseToolbarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseToolbarDoc)));
	return (CBaseToolbarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarView message handlers

void CBaseToolbarView::OnButtonstar() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);										//获得DC
	dc.TextOut(30,40,"开始工具按钮响应成功!");			//输出文本
	
}

void CBaseToolbarView::OnButtonstop() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);										//获得DC
	dc.TextOut(30,40,"停止工具按钮响应成功!");			//输出文本
	
}
