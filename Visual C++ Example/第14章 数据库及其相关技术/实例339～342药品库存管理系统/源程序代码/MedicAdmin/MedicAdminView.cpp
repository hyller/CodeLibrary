// MedicAdminView.cpp : implementation of the CMedicAdminView class
//

#include "stdafx.h"
#include "MedicAdmin.h"

#include "MedicAdminDoc.h"
#include "MedicAdminView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminView

IMPLEMENT_DYNCREATE(CMedicAdminView, CFormView)

BEGIN_MESSAGE_MAP(CMedicAdminView, CFormView)
	//{{AFX_MSG_MAP(CMedicAdminView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminView construction/destruction

CMedicAdminView::CMedicAdminView()
	: CFormView(CMedicAdminView::IDD)
{
	//{{AFX_DATA_INIT(CMedicAdminView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMedicAdminView::~CMedicAdminView()
{
}

void CMedicAdminView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMedicAdminView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CMedicAdminView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMedicAdminView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminView diagnostics

#ifdef _DEBUG
void CMedicAdminView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMedicAdminView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMedicAdminDoc* CMedicAdminView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMedicAdminDoc)));
	return (CMedicAdminDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminView message handlers


	



int CMedicAdminView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
