// TimerDemoView.cpp : implementation of the CTimerDemoView class
//

#include "stdafx.h"
#include "TimerDemo.h"

#include "TimerDemoDoc.h"
#include "TimerDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoView

IMPLEMENT_DYNCREATE(CTimerDemoView, CView)

BEGIN_MESSAGE_MAP(CTimerDemoView, CView)
	//{{AFX_MSG_MAP(CTimerDemoView)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoView construction/destruction

CTimerDemoView::CTimerDemoView()
{
	// TODO: add construction code here

}

CTimerDemoView::~CTimerDemoView()
{
}

BOOL CTimerDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoView drawing

void CTimerDemoView::OnDraw(CDC* pDC)
{
	CTimerDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoView printing

BOOL CTimerDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTimerDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTimerDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoView diagnostics

#ifdef _DEBUG
void CTimerDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTimerDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTimerDemoDoc* CTimerDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTimerDemoDoc)));
	return (CTimerDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoView message handlers

void CTimerDemoView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==2)
	{
	CClientDC dc(this);									//获得DC
	CFont myfont;	
	CFont*oldfont;	
	LOGFONT font;
	memset(&font,0,sizeof(LOGFONT));					//为字体结构赋初值，默认值
	font.lfHeight=50;								//字体高度为50
	font.lfWeight=600;
	strcpy(font.lfFaceName,"Arial");
	myfont.CreateFontIndirect(&font); 					//创建新字体
	oldfont=dc.SelectObject(&myfont);					//将新字体选入设备环境*/
	CTime m_time;
	m_time=CTime::GetCurrentTime();							//获取当前时间日期
	CString str=m_time.Format("当前时间：%H:%M:%S");		//格式化
	dc.TextOut(40,70,str);//显示时间
	dc.SelectObject(oldfont);							//恢复设备环境中的旧字体
	}
	CView::OnTimer(nIDEvent);
}

int CTimerDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	SetTimer(2,1000,NULL);//设置定时器，每秒触发一次	
	return 0;
}

void CTimerDemoView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	KillTimer(2);//销毁定时器
}
