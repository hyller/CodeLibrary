// TopListView.cpp : implementation file
//

#include "stdafx.h"
#include "MultiViewDemo.h"
#include "TopListView.h"
#include "MultiViewDemoDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTopListView

IMPLEMENT_DYNCREATE(CTopListView, CListView)



CTopListView::CTopListView()
{
}

CTopListView::~CTopListView()
{
}


BEGIN_MESSAGE_MAP(CTopListView, CListView)
	//{{AFX_MSG_MAP(CTopListView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTopListView drawing



void CTopListView::OnDraw(CDC* pDC)
{
}

/////////////////////////////////////////////////////////////////////////////
// CTopListView diagnostics

#ifdef _DEBUG
void CTopListView::AssertValid() const
{
	CListView::AssertValid();
}

void CTopListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTopListView message handlers

void CTopListView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	CString m_ColumnLabelStr[] ={"学号","姓名","专业","籍贯"};//表头字段
	// TODO: Add your specialized code here and/or call the base class
	CListCtrl& listctrl=GetListCtrl();//获取列表视控件
	listctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_UNDERLINEHOT);
	int width[6]={80,80,110,150};//各列的初始宽度
	for(int i=0; i<4; i++)
	{
		listctrl.InsertColumn(i, m_ColumnLabelStr[i], LVCFMT_LEFT, width[i]);//设置表头
	}	
}

BOOL CTopListView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.style=cs.style|LVS_REPORT;//设置成报告列表显示
	return CListView::PreCreateWindow(cs);
}

void CTopListView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CMultiViewDemoDoc* pDoc =(CMultiViewDemoDoc*)GetDocument();//获取文档指针
	if(pDoc->add)//添加了数据
	{
		CListCtrl& listctrl=GetListCtrl();//获取列表控件
		listctrl.DeleteAllItems();//删除所有项	
		for(int i=0;i<pDoc->infoArray[0].GetSize();i++)//列表框中插入数据
		{
			listctrl.InsertItem(i,pDoc->infoArray[0].GetAt(i));
			listctrl.SetItemText(i,1,pDoc->infoArray[1].GetAt(i));
			listctrl.SetItemText(i,2,pDoc->infoArray[2].GetAt(i));
			listctrl.SetItemText(i,3,pDoc->infoArray[3].GetAt(i));
		}
	}	
}
