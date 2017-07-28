// BottomEdieView.cpp : implementation file
//

#include "stdafx.h"
#include "MultiViewDemo.h"
#include "BottomEditView.h"
#include "MultiViewDemoDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBottomEdieView

IMPLEMENT_DYNCREATE(CBottomEditView, CEditView)

CBottomEditView::CBottomEditView()
{
}

CBottomEditView::~CBottomEditView()
{
}


BEGIN_MESSAGE_MAP(CBottomEditView, CEditView)
	//{{AFX_MSG_MAP(CBottomEdieView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBottomEdieView drawing

void CBottomEditView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CBottomEdieView diagnostics

#ifdef _DEBUG
void CBottomEditView::AssertValid() const
{
	CEditView::AssertValid();
}

void CBottomEditView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBottomEdieView message handlers
void CBottomEditView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
	CEdit &mEdit=GetEditCtrl();//获取编辑视图控件
	mEdit.SetWindowText("等待用户输入学生信息！");//设置显示信息
	mEdit.EnableWindow(false);//编辑控件不可编辑
}
void CBottomEditView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CMultiViewDemoDoc* pDoc =(CMultiViewDemoDoc*)GetDocument();//获取文档指针
	if(pDoc->add)//添加了数据
	{
		CString str;
		str="添加了学号为"+pDoc->infoArray[0].GetAt(0)+"的学生信息！";
		CEdit &mEdit=GetEditCtrl();//获取编辑视图控件
		mEdit.SetWindowText(str);//显示信息
	}
}