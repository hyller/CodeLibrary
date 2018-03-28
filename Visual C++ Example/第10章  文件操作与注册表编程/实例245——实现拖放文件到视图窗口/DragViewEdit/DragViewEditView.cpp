// DragViewEditView.cpp : implementation of the CDragViewEditView class
//

#include "stdafx.h"
#include "DragViewEdit.h"

#include "DragViewEditDoc.h"
#include "DragViewEditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditView

IMPLEMENT_DYNCREATE(CDragViewEditView, CFormView)

BEGIN_MESSAGE_MAP(CDragViewEditView, CFormView)
	//{{AFX_MSG_MAP(CDragViewEditView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditView construction/destruction

CDragViewEditView::CDragViewEditView()
	: CFormView(CDragViewEditView::IDD)
{
	//{{AFX_DATA_INIT(CDragViewEditView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CDragViewEditView::~CDragViewEditView()
{
}

void CDragViewEditView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDragViewEditView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CDragViewEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CDragViewEditView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditView printing

BOOL CDragViewEditView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDragViewEditView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDragViewEditView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDragViewEditView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditView diagnostics

#ifdef _DEBUG
void CDragViewEditView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDragViewEditView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDragViewEditDoc* CDragViewEditView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDragViewEditDoc)));
	return (CDragViewEditDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditView message handlers

void CDragViewEditView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CDragViewEditDoc *pDoc=GetDocument();
	SetDlgItemText(IDC_EDIT1,pDoc->GetPathName());
}
