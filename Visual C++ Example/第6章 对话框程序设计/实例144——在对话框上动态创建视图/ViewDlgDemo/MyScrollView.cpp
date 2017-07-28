// MyScrollView.cpp : implementation file
//

#include "stdafx.h"
#include "ViewDlgDemo.h"
#include "MyScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView

IMPLEMENT_DYNCREATE(CMyScrollView, CScrollView)

CMyScrollView::CMyScrollView()
{
}

CMyScrollView::~CMyScrollView()
{
}


BEGIN_MESSAGE_MAP(CMyScrollView, CScrollView)
	//{{AFX_MSG_MAP(CMyScrollView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView drawing

void CMyScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CMyScrollView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->TextOut(20,20,"在对话框中创建和使用视图");
}

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView diagnostics

#ifdef _DEBUG
void CMyScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMyScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView message handlers
