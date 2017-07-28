// PropertySheetDemoView.cpp : implementation of the CPropertySheetDemoView class
//

#include "stdafx.h"
#include "PropertySheetDemo.h"

#include "PropertySheetDemoDoc.h"
#include "PropertySheetDemoView.h"

#include "ShapePage.h"
#include "ColorPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoView

IMPLEMENT_DYNCREATE(CPropertySheetDemoView, CView)

BEGIN_MESSAGE_MAP(CPropertySheetDemoView, CView)
	//{{AFX_MSG_MAP(CPropertySheetDemoView)
	ON_COMMAND(ID_MENUSET, OnMenuset)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoView construction/destruction

CPropertySheetDemoView::CPropertySheetDemoView()
{
	// TODO: add construction code here
	m_r=100;
	m_g=0;
	m_b=128;
	m_type=0;
}

CPropertySheetDemoView::~CPropertySheetDemoView()
{
}

BOOL CPropertySheetDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoView drawing

void CPropertySheetDemoView::OnDraw(CDC* pDC)
{
	CPropertySheetDemoDoc* pDoc = GetDocument();
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
// CPropertySheetDemoView printing

BOOL CPropertySheetDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPropertySheetDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPropertySheetDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoView diagnostics

#ifdef _DEBUG
void CPropertySheetDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CPropertySheetDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropertySheetDemoDoc* CPropertySheetDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropertySheetDemoDoc)));
	return (CPropertySheetDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoView message handlers

void CPropertySheetDemoView::OnMenuset() 
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
