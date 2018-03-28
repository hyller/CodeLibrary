// DlgDateExchange2View.cpp : implementation of the CDlgDateExchange2View class
//

#include "stdafx.h"
#include "DlgDateExchange2.h"


#include "DlgDateExchange2Doc.h"
#include "DlgDateExchange2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_SET_COLOR WM_USER+100//自定义消息
/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2View

IMPLEMENT_DYNCREATE(CDlgDateExchange2View, CView)

BEGIN_MESSAGE_MAP(CDlgDateExchange2View, CView)
	//{{AFX_MSG_MAP(CDlgDateExchange2View)
	ON_WM_RBUTTONDOWN()
	ON_MESSAGE(WM_SET_COLOR,OnSetColor) 
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2View construction/destruction

CDlgDateExchange2View::CDlgDateExchange2View()
{
	// TODO: add construction code here
	r=128;
	g=200;
	b=0;
}

CDlgDateExchange2View::~CDlgDateExchange2View()
{
}

BOOL CDlgDateExchange2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	pDialog = new CTextColorDlg(this);							
   //Check if new succeeded and we got a valid pointer to a dialog object
   if(pDialog != NULL)
   {
	  BOOL ret = pDialog->Create(IDD_DIALOG1,this);				//创建非模态对话框
      if(!ret)   											//创建失败
      AfxMessageBox("创建对话框失败");	
   }
   else
      AfxMessageBox("对话框对象构造失败");
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2View drawing

void CDlgDateExchange2View::OnDraw(CDC* pDC)
{
	CDlgDateExchange2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CFont myfont;									//定义字体
	LOGFONT font;
	memset(&font,0,sizeof(LOGFONT));
	font.lfHeight=20;										//字体高度
	font.lfWeight=500;
	strcpy(font.lfFaceName,"Arial");							//字体样式
	myfont.CreateFontIndirect(&font);
	pDC->SelectObject(&myfont);							//DC载入字体
	COLORREF crColor=RGB(r,g,b);
	pDC->SetTextColor(crColor);							//设置文本颜色
	pDC->TextOut(20,20,"单击鼠标右键弹出非模态对话框！");	//输出文本
	pDC->TextOut(20,50,"实现非模态对话框的数据交换！");	//输出文本
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2View printing

BOOL CDlgDateExchange2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDlgDateExchange2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDlgDateExchange2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2View diagnostics

#ifdef _DEBUG
void CDlgDateExchange2View::AssertValid() const
{
	CView::AssertValid();
}

void CDlgDateExchange2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgDateExchange2Doc* CDlgDateExchange2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgDateExchange2Doc)));
	return (CDlgDateExchange2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2View message handlers

void CDlgDateExchange2View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	  pDialog->ShowWindow(SW_HIDE);						//隐藏对话框
	  CRect dlgRect;
	  pDialog->GetWindowRect(&dlgRect);				//获取对话框窗口大小
	  ClientToScreen(&point);//将鼠标位置转换为屏幕坐标
	  //移动对话框窗口
	  pDialog->MoveWindow(point.x, point.y,dlgRect.Width(),dlgRect.Height());
	  //将当前画刷的值赋予对话框变量
	  pDialog->m_blue=b;
	  pDialog->m_green=g;
	  pDialog->m_red=r;
	  pDialog->UpdateData(false);//更新控件
      pDialog->ShowWindow(SW_SHOW);						//显示对话框	
	CView::OnRButtonDown(nFlags, point);
}

void CDlgDateExchange2View::OnSetColor(WPARAM wP,LPARAM lP)
{
	//获取非模态对话框设置的颜色值
	r=pDialog->m_red;
	g=pDialog->m_green;
	b=pDialog->m_blue;
	Invalidate();//更新视图
}
