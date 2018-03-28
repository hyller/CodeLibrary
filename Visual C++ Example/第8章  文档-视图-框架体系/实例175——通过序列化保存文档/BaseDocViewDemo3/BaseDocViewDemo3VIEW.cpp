// BaseDocViewDemo3View.cpp : implementation of the CBaseDocViewDemo3View class
//

#include "stdafx.h"
#include "BaseDocViewDemo3.h"

#include "BaseDocViewDemo3Doc.h"
#include "BaseDocViewDemo3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo3View

IMPLEMENT_DYNCREATE(CBaseDocViewDemo3View, CView)

BEGIN_MESSAGE_MAP(CBaseDocViewDemo3View, CView)
	//{{AFX_MSG_MAP(CBaseDocViewDemo3View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo3View construction/destruction

CBaseDocViewDemo3View::CBaseDocViewDemo3View()
{
	// TODO: add construction code here
	m_bDraw=FALSE;
	m_Hcursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);	//载入"十字"光标
}

CBaseDocViewDemo3View::~CBaseDocViewDemo3View()
{
}

BOOL CBaseDocViewDemo3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo3View drawing

void CBaseDocViewDemo3View::OnDraw(CDC* pDC)
{
	CBaseDocViewDemo3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int index;
	index=pDoc->GetTotalLine();								//获取线条数目
	while(index--)
	{
		pDoc->GetLine(index)->Draw(pDC);						//绘制线条
	}
	pDC->TextOut(20,20,"能够实现保存和打开绘制图形文件！");
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo3View printing

BOOL CBaseDocViewDemo3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseDocViewDemo3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseDocViewDemo3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo3View diagnostics

#ifdef _DEBUG
void CBaseDocViewDemo3View::AssertValid() const
{
	CView::AssertValid();
}

void CBaseDocViewDemo3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDocViewDemo3Doc* CBaseDocViewDemo3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDocViewDemo3Doc)));
	return (CBaseDocViewDemo3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo3View message handlers

void CBaseDocViewDemo3View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCursor(m_Hcursor);									//使用新光标
	m_bDraw=TRUE;											//进入绘图状态
	m_pOld=point;
	SetCapture();											//捕捉鼠标
	CRect rect;
	GetClientRect(&rect);										//获取客户窗口矩形区域
	ClientToScreen(&rect);									//转换为屏幕坐标
	ClipCursor(rect);										//限定鼠标不能移出客户窗口
	
	CView::OnLButtonDown(nFlags, point);
}

void CBaseDocViewDemo3View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bDraw=FALSE;											//取消绘图状态
	ReleaseCapture();										//释放鼠标捕捉
	ClipCursor(NULL);										//取消鼠标区域的限制
	CView::OnLButtonUp(nFlags, point);
}

void CBaseDocViewDemo3View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bDraw)
	{
		CBaseDocViewDemo3Doc *pDoc=GetDocument();						//获取文档指针
		CClientDC dc(this);										//获取客户窗口DC
		dc.MoveTo(m_pOld);										//绘图
		dc.LineTo(point);
		pDoc->AddLine(m_pOld,point);				//存储线条
		m_pOld=point;		
	}
	CView::OnMouseMove(nFlags, point);
}


