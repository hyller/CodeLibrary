// SolidFontDemoView.cpp : implementation of the CSolidFontDemoView class
//

#include "stdafx.h"
#include "SolidFontDemo.h"

#include "SolidFontDemoDoc.h"
#include "SolidFontDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoView

IMPLEMENT_DYNCREATE(CSolidFontDemoView, CView)

BEGIN_MESSAGE_MAP(CSolidFontDemoView, CView)
	//{{AFX_MSG_MAP(CSolidFontDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoView construction/destruction

CSolidFontDemoView::CSolidFontDemoView()
{
	// TODO: add construction code here

}

CSolidFontDemoView::~CSolidFontDemoView()
{
}

BOOL CSolidFontDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoView drawing

void CSolidFontDemoView::OnDraw(CDC* pDC)
{
	CSolidFontDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CFont m_font;	
	CFont*oldfont;
	m_font.CreateFont(48,0,0,0,FW_BOLD,true,false,0,0,0,0,0,0,"Arial");//创建字体
	CString str;
	str="创建简单的立体字效果";
	oldfont=pDC->SelectObject(&m_font);//将字体载入DC
	COLORREF oldcolor=pDC->SetTextColor(::GetSysColor(COLOR_3DHILIGHT));
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(rect,::GetSysColor(COLOR_3DFACE));
	pDC->SetBkMode(TRANSPARENT);				//文本采用透明背景色
	pDC->DrawText(str,rect,DT_SINGLELINE|DT_LEFT|DT_VCENTER);//先画亮色的字
	pDC->SetTextColor(::GetSysColor(COLOR_3DSHADOW));
	pDC->DrawText(str,rect+CPoint(3,3),DT_SINGLELINE|DT_LEFT|DT_VCENTER);//偏移一些再画暗色的字
	pDC->SetTextColor(oldcolor);//恢复文本颜色
	pDC->SelectObject(oldfont);//恢复字体
}

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoView printing

BOOL CSolidFontDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSolidFontDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSolidFontDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoView diagnostics

#ifdef _DEBUG
void CSolidFontDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSolidFontDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSolidFontDemoDoc* CSolidFontDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSolidFontDemoDoc)));
	return (CSolidFontDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoView message handlers
