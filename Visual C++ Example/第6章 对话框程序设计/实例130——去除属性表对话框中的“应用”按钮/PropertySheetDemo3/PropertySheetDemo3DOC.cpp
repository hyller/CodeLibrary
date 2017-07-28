// PropertySheetDemo3Doc.cpp : implementation of the CPropertySheetDemo3Doc class
//

#include "stdafx.h"
#include "PropertySheetDemo3.h"

#include "PropertySheetDemo3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3Doc

IMPLEMENT_DYNCREATE(CPropertySheetDemo3Doc, CDocument)

BEGIN_MESSAGE_MAP(CPropertySheetDemo3Doc, CDocument)
	//{{AFX_MSG_MAP(CPropertySheetDemo3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3Doc construction/destruction

CPropertySheetDemo3Doc::CPropertySheetDemo3Doc()
{
	// TODO: add one-time construction code here

}

CPropertySheetDemo3Doc::~CPropertySheetDemo3Doc()
{
}

BOOL CPropertySheetDemo3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3Doc serialization

void CPropertySheetDemo3Doc::Serialize(CArchive& ar)
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
// CPropertySheetDemo3Doc diagnostics

#ifdef _DEBUG
void CPropertySheetDemo3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPropertySheetDemo3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3Doc commands
