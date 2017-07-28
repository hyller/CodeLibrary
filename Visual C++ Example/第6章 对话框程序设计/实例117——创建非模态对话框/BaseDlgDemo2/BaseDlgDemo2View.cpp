// BaseDlgDemo2View.cpp : implementation of the CBaseDlgDemo2View class
//

#include "stdafx.h"
#include "BaseDlgDemo2.h"

#include "BaseDlgDemo2Doc.h"
#include "BaseDlgDemo2View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2View

IMPLEMENT_DYNCREATE(CBaseDlgDemo2View, CView)

BEGIN_MESSAGE_MAP(CBaseDlgDemo2View, CView)
	//{{AFX_MSG_MAP(CBaseDlgDemo2View)
	ON_COMMAND(ID_CREATEDLG, OnCreatedlg)
	ON_COMMAND(ID_CREATEDLG2, OnCreatedlg2)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2View construction/destruction

CBaseDlgDemo2View::CBaseDlgDemo2View()
{
	// TODO: add construction code here

}

CBaseDlgDemo2View::~CBaseDlgDemo2View()
{
}

BOOL CBaseDlgDemo2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2View drawing

void CBaseDlgDemo2View::OnDraw(CDC* pDC)
{
	CBaseDlgDemo2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,30,szOut);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2View printing

BOOL CBaseDlgDemo2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseDlgDemo2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseDlgDemo2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2View diagnostics

#ifdef _DEBUG
void CBaseDlgDemo2View::AssertValid() const
{
	CView::AssertValid();
}

void CBaseDlgDemo2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDlgDemo2Doc* CBaseDlgDemo2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDlgDemo2Doc)));
	return (CBaseDlgDemo2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2View message handlers

void CBaseDlgDemo2View::OnCreatedlg() 
{
	MyDialog dlg;//创建对话框类实例
	int nRet=dlg.DoModal();//显示对话框，并回去对话框的返回值	
	szOut.Format("模态对话框的返回值为 %d",nRet);
	Invalidate(true);//更新显示
}


void CBaseDlgDemo2View::OnCreatedlg2() 
{
	// TODO: Add your command handler code here
	MyDialog* pDialog;										//对话框类对象指针 
	pDialog = new MyDialog();							
   //Check if new succeeded and we got a valid pointer to a dialog object
   if(pDialog != NULL)
   {
	  BOOL ret = pDialog->Create(IDD_DIALOG1,this);				//创建非模态对话框
      if(!ret)   											//创建失败
      AfxMessageBox("创建对话框失败");
	  CRect clientRect,dlgRect;
	  GetClientRect(&clientRect);								//获取客户区窗口大小
	  ClientToScreen(clientRect);								//转换为屏幕坐标
	  pDialog->GetWindowRect(&dlgRect);						//获取对话框窗口大小
	  //移动对话框窗口
	  pDialog->MoveWindow(clientRect.left+30, clientRect.top+50,dlgRect.Width(),dlgRect.Height());
      pDialog->ShowWindow(SW_SHOW);						//显示对话框
	  szOut="创建并在指定位置显示非模态对话框";
	  Invalidate(true);//更新显示
   }
   else
      AfxMessageBox("创建对话框对象失败");
}
