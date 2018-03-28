// MultiDocDemoView.cpp : implementation of the CMultiDocDemoView class
//

#include "stdafx.h"
#include "MultiDocDemo.h"

#include "MultiDocDemoDoc.h"
#include "MultiDocDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiDocDemoView

IMPLEMENT_DYNCREATE(CMultiDocDemoView, CView)

BEGIN_MESSAGE_MAP(CMultiDocDemoView, CView)
	//{{AFX_MSG_MAP(CMultiDocDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiDocDemoView construction/destruction

CMultiDocDemoView::CMultiDocDemoView()
{
	// TODO: add construction code here

}

CMultiDocDemoView::~CMultiDocDemoView()
{
}

BOOL CMultiDocDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMultiDocDemoView drawing

void CMultiDocDemoView::OnDraw(CDC* pDC)
{
	CMultiDocDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CString str=pDoc->m_str;//获取输出文本
	LOGFONT lf=pDoc->m_lf;//获取字体结构
	CFont *pFont=new CFont;
	pFont->CreateFontIndirect(&lf);//创建字体
	CFont *poldFont=pDC->SelectObject(pFont);//载入DC
	pDC->TextOut(40,40,str);//输出文本
	pDC->SelectObject(poldFont);//恢复字体
}

/////////////////////////////////////////////////////////////////////////////
// CMultiDocDemoView printing

BOOL CMultiDocDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMultiDocDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMultiDocDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMultiDocDemoView diagnostics

#ifdef _DEBUG
void CMultiDocDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiDocDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiDocDemoDoc* CMultiDocDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiDocDemoDoc)));
	return (CMultiDocDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiDocDemoView message handlers
