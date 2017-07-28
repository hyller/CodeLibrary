// PropertySheetDemo3View.cpp : implementation of the CPropertySheetDemo3View class
//

#include "stdafx.h"
#include "PropertySheetDemo3.h"

#include "PropertySheetDemo3Doc.h"
#include "PropertySheetDemo3View.h"

#include "ShapePage.h"
#include "ColorPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3View

IMPLEMENT_DYNCREATE(CPropertySheetDemo3View, CView)

BEGIN_MESSAGE_MAP(CPropertySheetDemo3View, CView)
	//{{AFX_MSG_MAP(CPropertySheetDemo3View)
	ON_COMMAND(ID_MENUSET, OnMenuset)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3View construction/destruction

CPropertySheetDemo3View::CPropertySheetDemo3View()
{
	// TODO: add construction code here
	m_r=100;
	m_g=0;
	m_b=128;
	m_type=0;
}

CPropertySheetDemo3View::~CPropertySheetDemo3View()
{
}

BOOL CPropertySheetDemo3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3View drawing

void CPropertySheetDemo3View::OnDraw(CDC* pDC)
{
	CPropertySheetDemo3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"通过执行图形|属性菜单，可以调用属性表设置图形属性！");
	CBrush mybrush(RGB(m_r,m_g,m_b));						//生成刷子
	CBrush *oldbrush;								//生成刷子指针
	oldbrush=pDC->SelectObject(&mybrush);				//把刷子选入设备环境
	switch (m_type)
	{
		case 0:
			pDC->Rectangle(50,50,220,220);			//绘制正方形
			break;
		case 1:
			pDC->Ellipse(50,50,220,220);						//绘制圆
			break;
	}
	pDC->SelectObject(oldbrush);						//恢复原有刷子
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3View printing

BOOL CPropertySheetDemo3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPropertySheetDemo3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPropertySheetDemo3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3View diagnostics

#ifdef _DEBUG
void CPropertySheetDemo3View::AssertValid() const
{
	CView::AssertValid();
}

void CPropertySheetDemo3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropertySheetDemo3Doc* CPropertySheetDemo3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropertySheetDemo3Doc)));
	return (CPropertySheetDemo3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3View message handlers

void CPropertySheetDemo3View::OnMenuset() 
{
	// TODO: Add your command handler code here
	CPropertySheet propsheet("图形对象设置");//CPropertySheet类对象
	CShapePage pageFirst; //图形属性页对象
	CColorPage pageSecond; //画刷色设置属性页对象
	//将当前图形画刷信息赋给属性页
	pageFirst.m_radio=m_type;
	pageSecond.m_r=m_r;
	pageSecond.m_g=m_g;
	pageSecond.m_b=m_b; 
	//添加属性页到CPropertySheet类对象
	propsheet.AddPage(&pageFirst);
	propsheet.AddPage(&pageSecond);
	
	propsheet.m_psh.dwFlags |= PSH_NOAPPLYNOW;//去除“应用”按钮
	propsheet.m_psh.nStartPage = 1;//设置初始活动页

	//创建模态属性表对话框
	if (propsheet.DoModal() == IDOK)
	{
		//获取各属性页设置的值
		m_type = pageFirst.m_radio;
		m_r=pageSecond.m_r;
		m_g=pageSecond.m_g;
		m_b=pageSecond.m_b; 
		Invalidate(true);//重绘客户窗口
	}	
}
