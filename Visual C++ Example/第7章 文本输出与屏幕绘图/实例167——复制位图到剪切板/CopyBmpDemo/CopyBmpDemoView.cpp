// CopyBmpDemoView.cpp : implementation of the CCopyBmpDemoView class
//

#include "stdafx.h"
#include "CopyBmpDemo.h"

#include "CopyBmpDemoDoc.h"
#include "CopyBmpDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoView

IMPLEMENT_DYNCREATE(CCopyBmpDemoView, CView)

BEGIN_MESSAGE_MAP(CCopyBmpDemoView, CView)
	//{{AFX_MSG_MAP(CCopyBmpDemoView)
	ON_COMMAND(ID_MENUCOPY, OnMenucopy)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoView construction/destruction

CCopyBmpDemoView::CCopyBmpDemoView()
{
	// TODO: add construction code here
	bmp.LoadBitmap(IDB_BITMAP1);
}

CCopyBmpDemoView::~CCopyBmpDemoView()
{
}

BOOL CCopyBmpDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoView drawing

void CCopyBmpDemoView::OnDraw(CDC* pDC)
{
	CCopyBmpDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	BITMAP bm;
	bmp.GetBitmap(&bm);
	//获取位图的大小
	int nWidth,nHeight;
	nWidth=bm.bmWidth;
	nHeight=bm.bmHeight;
	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);							//创建兼容内存DC
	CBitmap* pOldBmp = MemDC.SelectObject(&bmp);
	pDC->BitBlt(20,20,nWidth,nHeight,&MemDC,0,0,SRCCOPY);		//显示位图
	MemDC.SelectObject(pOldBmp);
	MemDC.DeleteDC();
	pDC->TextOut(10,170,"通过菜单命令可复制位图到剪切板");
}

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoView printing

BOOL CCopyBmpDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCopyBmpDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCopyBmpDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoView diagnostics

#ifdef _DEBUG
void CCopyBmpDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CCopyBmpDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCopyBmpDemoDoc* CCopyBmpDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCopyBmpDemoDoc)));
	return (CCopyBmpDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoView message handlers

void CCopyBmpDemoView::OnMenucopy() 
{
	// TODO: Add your command handler code here
	::OpenClipboard(this->GetSafeHwnd());//打开剪切板
	::EmptyClipboard();//清空剪切板
	::SetClipboardData(CF_BITMAP,bmp.GetSafeHandle());
	::CloseClipboard();//关闭剪切板
}
