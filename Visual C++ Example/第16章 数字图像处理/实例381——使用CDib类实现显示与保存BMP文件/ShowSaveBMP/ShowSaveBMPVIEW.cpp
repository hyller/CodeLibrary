// ShowSaveBMPView.cpp : implementation of the CShowSaveBMPView class
//

#include "stdafx.h"
#include "ShowSaveBMP.h"

#include "ShowSaveBMPDoc.h"
#include "ShowSaveBMPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPView

IMPLEMENT_DYNCREATE(CShowSaveBMPView, CView)

BEGIN_MESSAGE_MAP(CShowSaveBMPView, CView)
	//{{AFX_MSG_MAP(CShowSaveBMPView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPView construction/destruction

CShowSaveBMPView::CShowSaveBMPView()
{
	// TODO: add construction code here

}

CShowSaveBMPView::~CShowSaveBMPView()
{
}

BOOL CShowSaveBMPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPView drawing

void CShowSaveBMPView::OnDraw(CDC* pDC)
{
	CShowSaveBMPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	HGLOBAL hDIB = pDoc->GetHObject();	
	if (hDIB != NULL)							   	// 判断DIB是否为空
	{
		LPSTR lpDibSection = (LPSTR) ::GlobalLock(hDIB);				
		int cxDIB = (int) pDoc->m_dib.GetWidth(lpDibSection);	// 获取DIB宽度				
		int cyDIB = (int) pDoc->m_dib.GetHeight(lpDibSection);	// 获取DIB高度
		::GlobalUnlock(hDIB);		
		CRect rcDIB;
		rcDIB.top = rcDIB.left = 0;
		rcDIB.right = cxDIB;
		rcDIB.bottom = cyDIB;		
		CRect rcDest= rcDIB;			
		pDoc->m_dib.DrawDib(pDC->m_hDC, &rcDest, pDoc->GetHObject(),// 重画DIB
			&rcDIB, pDoc->GetDocPal());
	}
	else
	{
		pDC->TextOut(30,30,"可以通过文件菜单打开BMP文件，并显示，也可实现存储BMP文件！");
	}
}

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPView printing

BOOL CShowSaveBMPView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowSaveBMPView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowSaveBMPView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPView diagnostics

#ifdef _DEBUG
void CShowSaveBMPView::AssertValid() const
{
	CView::AssertValid();
}

void CShowSaveBMPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowSaveBMPDoc* CShowSaveBMPView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowSaveBMPDoc)));
	return (CShowSaveBMPDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPView message handlers
