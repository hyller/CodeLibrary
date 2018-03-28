// BaseDocViewDemo4View.cpp : implementation of the CBaseDocViewDemo4View class
//

#include "stdafx.h"
#include "BaseDocViewDemo4.h"

#include "BaseDocViewDemo4Doc.h"
#include "BaseDocViewDemo4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4View

IMPLEMENT_DYNCREATE(CBaseDocViewDemo4View, CView)

BEGIN_MESSAGE_MAP(CBaseDocViewDemo4View, CView)
	//{{AFX_MSG_MAP(CBaseDocViewDemo4View)
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
// CBaseDocViewDemo4View construction/destruction

CBaseDocViewDemo4View::CBaseDocViewDemo4View()
{
	// TODO: add construction code here
	m_bDraw=FALSE;
	m_Hcursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);	//载入"十字"光标
}

CBaseDocViewDemo4View::~CBaseDocViewDemo4View()
{
}

BOOL CBaseDocViewDemo4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4View drawing

void CBaseDocViewDemo4View::OnDraw(CDC* pDC)
{
	CBaseDocViewDemo4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int index;
	index=pDoc->GetTotalLine();								//获取线条数目
	while(index--)
	{
		pDoc->GetLine(index)->Draw(pDC);						//绘制线条
	}
	pDC->TextOut(20,20,"当文档被修改时在标题上给出提醒！");
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4View printing

BOOL CBaseDocViewDemo4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseDocViewDemo4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseDocViewDemo4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4View diagnostics

#ifdef _DEBUG
void CBaseDocViewDemo4View::AssertValid() const
{
	CView::AssertValid();
}

void CBaseDocViewDemo4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDocViewDemo4Doc* CBaseDocViewDemo4View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDocViewDemo4Doc)));
	return (CBaseDocViewDemo4Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4View message handlers

void CBaseDocViewDemo4View::OnLButtonDown(UINT nFlags, CPoint point) 
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

void CBaseDocViewDemo4View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	m_bDraw=FALSE;											//取消绘图状态
	ReleaseCapture();										//释放鼠标捕捉
	ClipCursor(NULL);										//取消鼠标区域的限制
	CView::OnLButtonUp(nFlags, point);
}

void CBaseDocViewDemo4View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bDraw)
	{
		CBaseDocViewDemo4Doc *pDoc=GetDocument();						//获取文档指针
		CClientDC dc(this);										//获取客户窗口DC
		dc.MoveTo(m_pOld);										//绘图
		dc.LineTo(point);
		pDoc->AddLine(m_pOld,point);				//存储线条
		m_pOld=point;		
	}
	CView::OnMouseMove(nFlags, point);
}


