// PropertySheetDemo2Doc.cpp : implementation of the CPropertySheetDemo2Doc class
//

#include "stdafx.h"
#include "PropertySheetDemo2.h"

#include "PropertySheetDemo2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo2Doc

IMPLEMENT_DYNCREATE(CPropertySheetDemo2Doc, CDocument)

BEGIN_MESSAGE_MAP(CPropertySheetDemo2Doc, CDocument)
	//{{AFX_MSG_MAP(CPropertySheetDemo2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo2Doc construction/destruction

CPropertySheetDemo2Doc::CPropertySheetDemo2Doc()
{
	// TODO: add one-time construction code here

}

CPropertySheetDemo2Doc::~CPropertySheetDemo2Doc()
{
}

BOOL CPropertySheetDemo2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo2Doc serialization

void CPropertySheetDemo2Doc::Serialize(CArchive& ar)
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
// CPropertySheetDemo2Doc diagnostics

#ifdef _DEBUG
void CPropertySheetDemo2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPropertySheetDemo2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo2Doc commands
