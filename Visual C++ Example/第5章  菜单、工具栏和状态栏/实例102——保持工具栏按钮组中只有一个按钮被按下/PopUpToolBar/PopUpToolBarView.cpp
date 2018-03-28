// PopUpToolBarView.cpp : implementation of the CPopUpToolBarView class
//

#include "stdafx.h"
#include "PopUpToolBar.h"

#include "PopUpToolBarDoc.h"
#include "PopUpToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarView

IMPLEMENT_DYNCREATE(CPopUpToolBarView, CView)

BEGIN_MESSAGE_MAP(CPopUpToolBarView, CView)
	//{{AFX_MSG_MAP(CPopUpToolBarView)
	ON_COMMAND(ID_BUTTONSTAR, OnButtonstar)
	ON_COMMAND(ID_BUTTONSTOP, OnButtonstop)
	ON_UPDATE_COMMAND_UI(ID_BUTTONSTAR, OnUpdateButtonstar)
	ON_UPDATE_COMMAND_UI(ID_BUTTONSTOP, OnUpdateButtonstop)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarView construction/destruction

CPopUpToolBarView::CPopUpToolBarView()
{
	// TODO: add construction code here

}

CPopUpToolBarView::~CPopUpToolBarView()
{
}

BOOL CPopUpToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarView drawing

void CPopUpToolBarView::OnDraw(CDC* pDC)
{
	CPopUpToolBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarView printing

BOOL CPopUpToolBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPopUpToolBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPopUpToolBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarView diagnostics

#ifdef _DEBUG
void CPopUpToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CPopUpToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPopUpToolBarDoc* CPopUpToolBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPopUpToolBarDoc)));
	return (CPopUpToolBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarView message handlers

void CPopUpToolBarView::OnButtonstar() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);										//获得DC
	dc.TextOut(30,40,"开始工具按钮响应成功!");			//输出文本
	m_radio=1;
	
}

void CPopUpToolBarView::OnButtonstop() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);										//获得DC
	dc.TextOut(30,40,"停止工具按钮响应成功!");			//输出文本
	m_radio=2;
	
}

void CPopUpToolBarView::OnUpdateButtonstar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_radio==1);
	
}

void CPopUpToolBarView::OnUpdateButtonstop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		pCmdUI->SetRadio(m_radio==2);
	
}
