// KeyMessageMenuView.cpp : implementation of the CKeyMessageMenuView class
//

#include "stdafx.h"
#include "KeyMessageMenu.h"

#include "KeyMessageMenuDoc.h"
#include "KeyMessageMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuView

IMPLEMENT_DYNCREATE(CKeyMessageMenuView, CView)

BEGIN_MESSAGE_MAP(CKeyMessageMenuView, CView)
	//{{AFX_MSG_MAP(CKeyMessageMenuView)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuView construction/destruction

CKeyMessageMenuView::CKeyMessageMenuView()
{
	// TODO: add construction code here

}

CKeyMessageMenuView::~CKeyMessageMenuView()
{
}

BOOL CKeyMessageMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuView drawing

void CKeyMessageMenuView::OnDraw(CDC* pDC)
{
	CKeyMessageMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,40,"双击鼠标左键或者使用Ctrl+Shift+S快捷键均可激发开始菜单项！");
}

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuView printing

BOOL CKeyMessageMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKeyMessageMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKeyMessageMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuView diagnostics

#ifdef _DEBUG
void CKeyMessageMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyMessageMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyMessageMenuDoc* CKeyMessageMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyMessageMenuDoc)));
	return (CKeyMessageMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuView message handlers

void CKeyMessageMenuView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	AfxGetMainWnd()->SendMessage(WM_COMMAND,ID_MENUSTAR);//激发菜单命令
	CView::OnLButtonDblClk(nFlags, point);
}
