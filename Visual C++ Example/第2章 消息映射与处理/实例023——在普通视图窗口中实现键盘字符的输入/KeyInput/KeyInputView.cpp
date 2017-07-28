// KeyInputView.cpp : implementation of the CKeyInputView class
//

#include "stdafx.h"
#include "KeyInput.h"

#include "KeyInputDoc.h"
#include "KeyInputView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyInputView

IMPLEMENT_DYNCREATE(CKeyInputView, CView)

BEGIN_MESSAGE_MAP(CKeyInputView, CView)
	//{{AFX_MSG_MAP(CKeyInputView)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyInputView construction/destruction

CKeyInputView::CKeyInputView()
{
	// TODO: add construction code here
	//初始位置设置在（0，0）
	ptCharacter.x=0;
	ptCharacter.y=0;


}

CKeyInputView::~CKeyInputView()
{
}

BOOL CKeyInputView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKeyInputView drawing

void CKeyInputView::OnDraw(CDC* pDC)
{
	CKeyInputDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CKeyInputView printing

BOOL CKeyInputView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKeyInputView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKeyInputView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CKeyInputView diagnostics

#ifdef _DEBUG
void CKeyInputView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyInputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyInputDoc* CKeyInputView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyInputDoc)));
	return (CKeyInputDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKeyInputView message handlers

void CKeyInputView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==13)										//按下了回车键
	{
		//换行
		ptCharacter.x=0;
		ptCharacter.y=ptCharacter.y+25;
	}
	else
	{
		CClientDC dc(this);
		dc.TextOut(ptCharacter.x,ptCharacter.y,(LPCTSTR)&nChar);		//输出显示字符
		CSize textsize;
		textsize=dc.GetTextExtent((LPCTSTR)&nChar);				//获取当前字符大小
		//前进到下一个字符位置
		ptCharacter.x=ptCharacter.x+textsize.cx;
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}

	