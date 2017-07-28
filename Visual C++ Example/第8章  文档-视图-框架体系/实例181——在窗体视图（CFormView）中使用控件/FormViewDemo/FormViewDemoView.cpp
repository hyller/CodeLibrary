// FormViewDemoView.cpp : implementation of the CFormViewDemoView class
//

#include "stdafx.h"
#include "FormViewDemo.h"

#include "FormViewDemoDoc.h"
#include "FormViewDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormViewDemoView

IMPLEMENT_DYNCREATE(CFormViewDemoView, CFormView)

BEGIN_MESSAGE_MAP(CFormViewDemoView, CFormView)
	//{{AFX_MSG_MAP(CFormViewDemoView)
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormViewDemoView construction/destruction

CFormViewDemoView::CFormViewDemoView()
	: CFormView(CFormViewDemoView::IDD)
{
	//{{AFX_DATA_INIT(CFormViewDemoView)
	m_user = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CFormViewDemoView::~CFormViewDemoView()
{
}

void CFormViewDemoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormViewDemoView)
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDV_MaxChars(pDX, m_user, 20);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	DDV_MaxChars(pDX, m_password, 20);
	//}}AFX_DATA_MAP
}

BOOL CFormViewDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFormViewDemoView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CFormViewDemoView printing

BOOL CFormViewDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFormViewDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFormViewDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFormViewDemoView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CFormViewDemoView diagnostics

#ifdef _DEBUG
void CFormViewDemoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormViewDemoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFormViewDemoDoc* CFormViewDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormViewDemoDoc)));
	return (CFormViewDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormViewDemoView message handlers

void CFormViewDemoView::OnCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_password=="gaoshou")
	{
		AfxMessageBox("ª∂”≠”√ªß£∫"+m_user);
	}
	else
	{
		AfxMessageBox("√‹¬Î¥ÌŒÛ!");
	}
	m_user=m_password="";
	UpdateData(false);
	
}
