// PrintRealDemo2Doc.cpp : implementation of the CPrintRealDemo2Doc class
//

#include "stdafx.h"
#include "PrintRealDemo2.h"

#include "PrintRealDemo2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2Doc

IMPLEMENT_DYNCREATE(CPrintRealDemo2Doc, CDocument)

BEGIN_MESSAGE_MAP(CPrintRealDemo2Doc, CDocument)
	//{{AFX_MSG_MAP(CPrintRealDemo2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2Doc construction/destruction

CPrintRealDemo2Doc::CPrintRealDemo2Doc()
{
	// TODO: add one-time construction code here

}

CPrintRealDemo2Doc::~CPrintRealDemo2Doc()
{
}

BOOL CPrintRealDemo2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2Doc serialization

void CPrintRealDemo2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2Doc diagnostics

#ifdef _DEBUG
void CPrintRealDemo2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintRealDemo2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemo2Doc commands
