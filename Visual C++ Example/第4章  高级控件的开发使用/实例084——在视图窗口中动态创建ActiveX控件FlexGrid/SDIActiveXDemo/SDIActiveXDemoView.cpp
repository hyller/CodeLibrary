// SDIActiveXDemoView.cpp : implementation of the CSDIActiveXDemoView class
//

#include "stdafx.h"
#include "SDIActiveXDemo.h"

#include "SDIActiveXDemoDoc.h"
#include "SDIActiveXDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSDIActiveXDemoView

IMPLEMENT_DYNCREATE(CSDIActiveXDemoView, CView)

BEGIN_MESSAGE_MAP(CSDIActiveXDemoView, CView)
	//{{AFX_MSG_MAP(CSDIActiveXDemoView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()
BEGIN_EVENTSINK_MAP(CSDIActiveXDemoView, CView)
    //{{AFX_EVENTSINK_MAP(CDlgActiveXDemoDlg)
	ON_EVENT(CSDIActiveXDemoView, IDC_FLEX_GRID, -600 /* Click */, OnClick, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSDIActiveXDemoView construction/destruction

CSDIActiveXDemoView::CSDIActiveXDemoView()
{
	// TODO: add construction code here

}

CSDIActiveXDemoView::~CSDIActiveXDemoView()
{
}

BOOL CSDIActiveXDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSDIActiveXDemoView drawing

void CSDIActiveXDemoView::OnDraw(CDC* pDC)
{
	CSDIActiveXDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10,10,"实现在视图窗口中动态创建ActiveX控件");
	pDC->TextOut(10,160,str);


}

/////////////////////////////////////////////////////////////////////////////
// CSDIActiveXDemoView printing

BOOL CSDIActiveXDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSDIActiveXDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSDIActiveXDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSDIActiveXDemoView diagnostics

#ifdef _DEBUG
void CSDIActiveXDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIActiveXDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIActiveXDemoDoc* CSDIActiveXDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIActiveXDemoDoc)));
	return (CSDIActiveXDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSDIActiveXDemoView message handlers

int CSDIActiveXDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	m_flexgrid.Create(NULL,WS_VISIBLE|WS_CHILD,CRect(0,0,425,105),this,IDC_FLEX_GRID);
	m_flexgrid.SetCols(0,6);//设置表格的列数
	m_flexgrid.SetRows(5);//设置表格的行数
	m_flexgrid.SetBackColor(RGB(0,200,255));				//设置表格背景色
	char* colHead[4]={"电话费","水电费","办公消耗","合计"};
	char* rowHead[5]={"一月","二月","三月","四月","五月"};
	m_flexgrid.SetRow(0);									//定位到表格第一行
	for(int nCol=0;nCol<5;nCol++)							//添加行头
	{
		m_flexgrid.SetCol(nCol+1);
		m_flexgrid.SetText(rowHead[nCol]);
	}
	m_flexgrid.SetCol(0);									//定位到表格第一列
	for(int nRow=0;nRow<4;nRow++)						//添加列头
	{
		m_flexgrid.SetRow(nRow+1);
		m_flexgrid.SetText(colHead[nRow]);
	}
	return 0;
}

void CSDIActiveXDemoView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	m_flexgrid.MoveWindow(50,50,415,95);	//设置控件的显示位置和区域	
}
void CSDIActiveXDemoView::OnClick()
{
		int m_nCurrentRow=m_flexgrid.GetRow();						//获取表格当前行
		int m_nCurrentCol=m_flexgrid.GetCol();						//获取表格当前列
		str.Format("当前选中了第%d行第%d列的单元格",m_nCurrentRow,m_nCurrentCol);
		m_flexgrid.SetCellBackColor(RGB(0,200,0));//设置当前单元格背景色
		Invalidate();//更新显示视图
}