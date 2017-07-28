// MultiViewDemoView.cpp : implementation of the CMultiViewDemoView class
//

#include "stdafx.h"
#include "MultiViewDemo.h"

#include "MultiViewDemoDoc.h"
#include "MultiViewDemoView.h"

#include "LeftFormView.h"
#include "TopListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoView

IMPLEMENT_DYNCREATE(CMultiViewDemoView, CView)

BEGIN_MESSAGE_MAP(CMultiViewDemoView, CView)
	//{{AFX_MSG_MAP(CMultiViewDemoView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoView construction/destruction

CMultiViewDemoView::CMultiViewDemoView()
{
	// TODO: add construction code here

}

CMultiViewDemoView::~CMultiViewDemoView()
{
}

BOOL CMultiViewDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoView drawing

void CMultiViewDemoView::OnDraw(CDC* pDC)
{
	CMultiViewDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoView printing

BOOL CMultiViewDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMultiViewDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMultiViewDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoView diagnostics

#ifdef _DEBUG
void CMultiViewDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiViewDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiViewDemoDoc* CMultiViewDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiViewDemoDoc)));
	return (CMultiViewDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoView message handlers

int CMultiViewDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	//获得窗口的创建信息指针
	CCreateContext *pContext = (CCreateContext*) lpCreateStruct->lpCreateParams;

	//产生二次静态切分
	m_wndSplitter2.CreateStatic(this,1, 2);
	//为第一个窗格产生视图
	m_wndSplitter2.CreateView(0,0,// 窗格的行、列序数
				RUNTIME_CLASS(CLeftFormView),//视图类 
				CSize(rect.Width()/4,rect.Height()),//初始化大小  
				pContext);//父窗口的创建参数	
	//为第二个窗格产生视图
	m_wndSplitter2.CreateView(0,1,
				RUNTIME_CLASS(CTopListView),
				CSize(1,1),
				pContext);
	return 0;
}
void CMultiViewDemoView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rect;
	GetClientRect(&rect);
	int x = rect.Width();
	int y = rect.Height();
	m_wndSplitter2.MoveWindow(-2,-2,x,y+3);
	m_wndSplitter2.SetColumnInfo(0, x/4,0);
	m_wndSplitter2.SetColumnInfo(1, x-x/4, 0);
	m_wndSplitter2.RecalcLayout();
	
}
