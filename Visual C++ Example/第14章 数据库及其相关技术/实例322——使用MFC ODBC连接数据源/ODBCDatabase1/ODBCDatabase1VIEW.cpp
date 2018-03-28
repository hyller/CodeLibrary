// ODBCDatabase1View.cpp : implementation of the CODBCDatabase1View class
//

#include "stdafx.h"
#include "ODBCDatabase1.h"

#include "ODBCDatabase1Set.h"
#include "ODBCDatabase1Doc.h"
#include "ODBCDatabase1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1View

IMPLEMENT_DYNCREATE(CODBCDatabase1View, CRecordView)

BEGIN_MESSAGE_MAP(CODBCDatabase1View, CRecordView)
	//{{AFX_MSG_MAP(CODBCDatabase1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1View construction/destruction

CODBCDatabase1View::CODBCDatabase1View()
	: CRecordView(CODBCDatabase1View::IDD)
{
	//{{AFX_DATA_INIT(CODBCDatabase1View)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CODBCDatabase1View::~CODBCDatabase1View()
{
}

void CODBCDatabase1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CODBCDatabase1View)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CODBCDatabase1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CODBCDatabase1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBCDatabase1Set;
	CRecordView::OnInitialUpdate();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1View printing

BOOL CODBCDatabase1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CODBCDatabase1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CODBCDatabase1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1View diagnostics

#ifdef _DEBUG
void CODBCDatabase1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBCDatabase1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBCDatabase1Doc* CODBCDatabase1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCDatabase1Doc)));
	return (CODBCDatabase1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1View database support
CRecordset* CODBCDatabase1View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1View message handlers
