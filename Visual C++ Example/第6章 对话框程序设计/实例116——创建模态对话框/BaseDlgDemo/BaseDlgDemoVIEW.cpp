// BaseDlgDemoView.cpp : implementation of the CBaseDlgDemoView class
//

#include "stdafx.h"
#include "BaseDlgDemo.h"

#include "BaseDlgDemoDoc.h"
#include "BaseDlgDemoView.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoView

IMPLEMENT_DYNCREATE(CBaseDlgDemoView, CView)

BEGIN_MESSAGE_MAP(CBaseDlgDemoView, CView)
	//{{AFX_MSG_MAP(CBaseDlgDemoView)
	ON_COMMAND(ID_CREATEDLG, OnCreatedlg)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoView construction/destruction

CBaseDlgDemoView::CBaseDlgDemoView()
{
	// TODO: add construction code here

}

CBaseDlgDemoView::~CBaseDlgDemoView()
{
}

BOOL CBaseDlgDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoView drawing

void CBaseDlgDemoView::OnDraw(CDC* pDC)
{
	CBaseDlgDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(30,30,szOut);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoView printing

BOOL CBaseDlgDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseDlgDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseDlgDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoView diagnostics

#ifdef _DEBUG
void CBaseDlgDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBaseDlgDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDlgDemoDoc* CBaseDlgDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDlgDemoDoc)));
	return (CBaseDlgDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoView message handlers

void CBaseDlgDemoView::OnCreatedlg() 
{
	MyDialog dlg;//创建对话框类实例
	int nRet=dlg.DoModal();//显示对话框，并回去对话框的返回值	
	szOut.Format("模态对话框的返回值为 %d",nRet);
	Invalidate(true);//更新显示
}



	

