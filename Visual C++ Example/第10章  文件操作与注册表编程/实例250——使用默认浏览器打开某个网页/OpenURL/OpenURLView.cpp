// OpenURLView.cpp : implementation of the COpenURLView class
//

#include "stdafx.h"
#include "OpenURL.h"

#include "OpenURLDoc.h"
#include "OpenURLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenURLView

IMPLEMENT_DYNCREATE(COpenURLView, CView)

BEGIN_MESSAGE_MAP(COpenURLView, CView)
	//{{AFX_MSG_MAP(COpenURLView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenURLView construction/destruction

COpenURLView::COpenURLView()
{
	// TODO: add construction code here

}

COpenURLView::~COpenURLView()
{
}

BOOL COpenURLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COpenURLView drawing

void COpenURLView::OnDraw(CDC* pDC)
{
	COpenURLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(20,20,"执行帮助|在线帮助菜单命令，将使用默认浏览器打开主页127.0.0.1");
}

/////////////////////////////////////////////////////////////////////////////
// COpenURLView printing

BOOL COpenURLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpenURLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpenURLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COpenURLView diagnostics

#ifdef _DEBUG
void COpenURLView::AssertValid() const
{
	CView::AssertValid();
}

void COpenURLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenURLDoc* COpenURLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenURLDoc)));
	return (COpenURLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenURLView message handlers
