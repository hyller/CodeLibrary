// ADODataControlView.cpp : implementation of the CADODataControlView class
//

#include "stdafx.h"
#include "ADODataControl.h"

#include "ADODataControlDoc.h"
#include "ADODataControlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADODataControlView

IMPLEMENT_DYNCREATE(CADODataControlView, CFormView)

BEGIN_MESSAGE_MAP(CADODataControlView, CFormView)
	//{{AFX_MSG_MAP(CADODataControlView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODataControlView construction/destruction

CADODataControlView::CADODataControlView()
	: CFormView(CADODataControlView::IDD)
{
	//{{AFX_DATA_INIT(CADODataControlView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CADODataControlView::~CADODataControlView()
{
}

void CADODataControlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADODataControlView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CADODataControlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CADODataControlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CADODataControlView printing

BOOL CADODataControlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CADODataControlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CADODataControlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CADODataControlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CADODataControlView diagnostics

#ifdef _DEBUG
void CADODataControlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CADODataControlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CADODataControlDoc* CADODataControlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CADODataControlDoc)));
	return (CADODataControlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CADODataControlView message handlers
