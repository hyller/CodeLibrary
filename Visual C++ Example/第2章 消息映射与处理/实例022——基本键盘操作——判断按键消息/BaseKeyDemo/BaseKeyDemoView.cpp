// BaseKeyDemoView.cpp : implementation of the CBaseKeyDemoView class
//

#include "stdafx.h"
#include "BaseKeyDemo.h"

#include "BaseKeyDemoDoc.h"
#include "BaseKeyDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoView

IMPLEMENT_DYNCREATE(CBaseKeyDemoView, CView)

BEGIN_MESSAGE_MAP(CBaseKeyDemoView, CView)
	//{{AFX_MSG_MAP(CBaseKeyDemoView)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoView construction/destruction

CBaseKeyDemoView::CBaseKeyDemoView()
{
	// TODO: add construction code here
	bShiftdown=bShiftup=bShiftB=FALSE;//赋初值

}

CBaseKeyDemoView::~CBaseKeyDemoView()
{
}

BOOL CBaseKeyDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoView drawing

void CBaseKeyDemoView::OnDraw(CDC* pDC)
{
	CBaseKeyDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if(bShiftdown)										//按下了Shift键
	{
		pDC->TextOut(20,20,"用户按下了Shift键!");
	}
	if(bShiftup)											//释放了Shift键
	{
		pDC->TextOut(20,20,"用户释放了Shift键!");
	}
	if(bShiftB)										//同时按下了Shift键和B键
	{
		pDC->TextOut(20,20,"用户同时按下Shift键和B键!");
		bShiftB=FALSE;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoView printing

BOOL CBaseKeyDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseKeyDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseKeyDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoView diagnostics

#ifdef _DEBUG
void CBaseKeyDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBaseKeyDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseKeyDemoDoc* CBaseKeyDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseKeyDemoDoc)));
	return (CBaseKeyDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoView message handlers

void CBaseKeyDemoView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==VK_SHIFT)								//判断Shift键是否被按下
	{
		//AfxMessageBox("dd");
		bShiftdown=TRUE;
		bShiftup=FALSE;
		Invalidate(TRUE);										//显示信息
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CBaseKeyDemoView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==VK_SHIFT)								//判断Shift键是否被释放
	{
		//AfxMessageBox("dd");
		bShiftup=TRUE;
		Invalidate(TRUE);										//显示信息
		bShiftdown=FALSE;
	}	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CBaseKeyDemoView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if((nChar==98)||(nChar==66))						//判断是否敲击了字符键B键或b键
	{
		if(bShiftdown)
		{
			bShiftB=TRUE;
			bShiftdown=FALSE;
			Invalidate(TRUE);								//显示信息
		}	
	}	
	CView::OnChar(nChar, nRepCnt, nFlags);
}
