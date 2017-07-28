// BrushDemoView.cpp : implementation of the CBrushDemoView class
//

#include "stdafx.h"
#include "BrushDemo.h"

#include "BrushDemoDoc.h"
#include "BrushDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoView

IMPLEMENT_DYNCREATE(CBrushDemoView, CView)

BEGIN_MESSAGE_MAP(CBrushDemoView, CView)
	//{{AFX_MSG_MAP(CBrushDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoView construction/destruction

CBrushDemoView::CBrushDemoView()
{
	// TODO: add construction code here

}

CBrushDemoView::~CBrushDemoView()
{
}

BOOL CBrushDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoView drawing

void CBrushDemoView::OnDraw(CDC* pDC)
{
	CBrushDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBrush brush[8], *pOldBrush;
	//创建实心刷子
	brush[0].CreateSolidBrush(RGB(200, 0, 200));
	//创建一个具有样式HS_BDIAGONAL 的刷子
	brush[1].CreateHatchBrush(HS_BDIAGONAL, RGB(128, 0, 0));
	//创建一个具有样式HS_CROSS的刷子
	brush[2].CreateHatchBrush(HS_CROSS, RGB(0, 0, 128));
	//创建一个具有样式HS_DIAGCROSS的刷子
	brush[3].CreateHatchBrush(HS_DIAGCROSS, RGB(0, 128, 0));
	//创建一个具有样式HS_FDIAGONAL的刷子
	brush[4].CreateHatchBrush(HS_FDIAGONAL, RGB(128, 128, 0 ));
	//创建一个具有样式HS_VERTICAL的刷子
	brush[5].CreateHatchBrush(HS_VERTICAL, RGB(0, 128, 128));
	//创建一个具有样式HS_HORIZONTAL的刷子
	brush[6].CreateHatchBrush(HS_HORIZONTAL, RGB(128, 128, 128));
	//创建一个使用位图图案的刷子
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	brush[7].CreatePatternBrush(&bitmap);
	pOldBrush=pDC->SelectObject(&brush[0]);					//载入刷子1
	pDC->Rectangle(10, 10, 160, 110);
	pDC->TextOut(10, 115, "实心刷子");
	pDC->SelectObject(&brush[1]);							//载入刷子2
	pDC->Rectangle(180, 10, 330, 110);
	pDC->TextOut(180, 115, "HS_BDIAGONAL样式刷子");
	pDC->SelectObject(&brush[2]);							//载入刷子3
	pDC->Rectangle(350, 10, 500, 110);
	pDC->TextOut(350, 115, "HS_CROSS样式刷子");
	pDC->SelectObject(&brush[3]);							//载入刷子4
	pDC->Rectangle(520, 10, 670, 110);
	pDC->TextOut(520, 115, "HS_DIAGCROSS样式刷子");
	pDC->SelectObject(&brush[4]);							//载入刷子5
	pDC->Rectangle(10, 140, 160, 240);
	pDC->TextOut(10, 245, "HS_FDIAGONAL样式刷子");	
	pDC->SelectObject(&brush[5]);							//载入刷子6
	pDC->Rectangle(180, 140, 330, 240);
	pDC->TextOut(180, 245, "HS_VERTICAL样式刷子");
	pDC->SelectObject(&brush[6]);							//载入刷子7
	pDC->Rectangle(350, 140, 500, 240);
	pDC->TextOut(350, 245, "HS_VERTICAL样式刷子");
	pDC->SelectObject(&brush[7]);							//载入刷子8
	pDC->Rectangle(520, 140, 670, 240);
	pDC->TextOut(520, 245, "位图图案刷子");
	//恢复设备上下文的原有画刷
	pDC->SelectObject(pOldBrush);
	//删除所创建的画刷资源
	for (int i=0; i<9; i++)
	brush[i].DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoView printing

BOOL CBrushDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBrushDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBrushDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoView diagnostics

#ifdef _DEBUG
void CBrushDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBrushDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBrushDemoDoc* CBrushDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBrushDemoDoc)));
	return (CBrushDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoView message handlers
