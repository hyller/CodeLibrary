// RadioMenuDemoView.cpp : implementation of the CRadioMenuDemoView class
//

#include "stdafx.h"
#include "RadioMenuDemo.h"

#include "RadioMenuDemoDoc.h"
#include "RadioMenuDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoView

IMPLEMENT_DYNCREATE(CRadioMenuDemoView, CView)

BEGIN_MESSAGE_MAP(CRadioMenuDemoView, CView)
	//{{AFX_MSG_MAP(CRadioMenuDemoView)
	ON_COMMAND(ID_MENUCIRCLE, OnMenucircle)
	ON_UPDATE_COMMAND_UI(ID_MENUCIRCLE, OnUpdateMenucircle)
	ON_COMMAND(ID_MENURECT, OnMenurect)
	ON_UPDATE_COMMAND_UI(ID_MENURECT, OnUpdateMenurect)
	ON_COMMAND(ID_MENUTRIANGLE, OnMenutriangle)
	ON_UPDATE_COMMAND_UI(ID_MENUTRIANGLE, OnUpdateMenutriangle)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoView construction/destruction

CRadioMenuDemoView::CRadioMenuDemoView()
{
	// TODO: add construction code here

}

CRadioMenuDemoView::~CRadioMenuDemoView()
{
}

BOOL CRadioMenuDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoView drawing

void CRadioMenuDemoView::OnDraw(CDC* pDC)
{
	CRadioMenuDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoView printing

BOOL CRadioMenuDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRadioMenuDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRadioMenuDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoView diagnostics

#ifdef _DEBUG
void CRadioMenuDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CRadioMenuDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRadioMenuDemoDoc* CRadioMenuDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRadioMenuDemoDoc)));
	return (CRadioMenuDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoView message handlers

void CRadioMenuDemoView::OnMenucircle() 
{
	// TODO: Add your command handler code here
	m_radiomode=1;
	CClientDC dc(this);											//获得DC
	dc.TextOut(30,40,"绘制圆形!");								//输出文本
	
}

void CRadioMenuDemoView::OnUpdateMenucircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_radiomode==1);
	
}

void CRadioMenuDemoView::OnMenurect() 
{
	// TODO: Add your command handler code here
	m_radiomode=2;
	CClientDC dc(this);											//获得DC
	dc.TextOut(30,40,"绘制矩形!");								//输出文本
	
}

void CRadioMenuDemoView::OnUpdateMenurect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_radiomode==2);
}

void CRadioMenuDemoView::OnMenutriangle() 
{
	// TODO: Add your command handler code here
	m_radiomode=3;
	CClientDC dc(this);											//获得DC
	dc.TextOut(30,40,"绘制三角!");								//输出文本	
}

void CRadioMenuDemoView::OnUpdateMenutriangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetRadio(m_radiomode==3);	
}
