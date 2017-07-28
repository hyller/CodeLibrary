// SimulateMouseView.cpp : implementation of the CSimulateMouseView class
//

#include "stdafx.h"
#include "SimulateMouse.h"

#include "SimulateMouseDoc.h"
#include "SimulateMouseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseView

IMPLEMENT_DYNCREATE(CSimulateMouseView, CView)

BEGIN_MESSAGE_MAP(CSimulateMouseView, CView)
	//{{AFX_MSG_MAP(CSimulateMouseView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseView construction/destruction

CSimulateMouseView::CSimulateMouseView()
{
	// TODO: add construction code here

}

CSimulateMouseView::~CSimulateMouseView()
{
}

BOOL CSimulateMouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseView drawing

void CSimulateMouseView::OnDraw(CDC* pDC)
{
	CSimulateMouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseView printing

BOOL CSimulateMouseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSimulateMouseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSimulateMouseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseView diagnostics

#ifdef _DEBUG
void CSimulateMouseView::AssertValid() const
{
	CView::AssertValid();
}

void CSimulateMouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimulateMouseDoc* CSimulateMouseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimulateMouseDoc)));
	return (CSimulateMouseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseView message handlers
