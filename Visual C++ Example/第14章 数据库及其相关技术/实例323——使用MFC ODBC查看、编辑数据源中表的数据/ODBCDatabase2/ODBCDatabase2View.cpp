// ODBCDatabase2View.cpp : implementation of the CODBCDatabase2View class
//

#include "stdafx.h"
#include "ODBCDatabase2.h"

#include "ODBCDatabase2Set.h"
#include "ODBCDatabase2Doc.h"
#include "ODBCDatabase2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2View

IMPLEMENT_DYNCREATE(CODBCDatabase2View, CRecordView)

BEGIN_MESSAGE_MAP(CODBCDatabase2View, CRecordView)
	//{{AFX_MSG_MAP(CODBCDatabase2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2View construction/destruction

CODBCDatabase2View::CODBCDatabase2View()
	: CRecordView(CODBCDatabase2View::IDD)
{
	//{{AFX_DATA_INIT(CODBCDatabase2View)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CODBCDatabase2View::~CODBCDatabase2View()
{
}

void CODBCDatabase2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CODBCDatabase2View)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_stuno, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_name, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_sex, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_Age, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CODBCDatabase2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CODBCDatabase2View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBCDatabase2Set;
	CRecordView::OnInitialUpdate();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2View printing

BOOL CODBCDatabase2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CODBCDatabase2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CODBCDatabase2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2View diagnostics

#ifdef _DEBUG
void CODBCDatabase2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBCDatabase2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBCDatabase2Doc* CODBCDatabase2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCDatabase2Doc)));
	return (CODBCDatabase2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2View database support
CRecordset* CODBCDatabase2View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2View message handlers
