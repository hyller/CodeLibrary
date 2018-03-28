// PropertySheetDemoDoc.cpp : implementation of the CPropertySheetDemoDoc class
//

#include "stdafx.h"
#include "PropertySheetDemo.h"

#include "PropertySheetDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoDoc

IMPLEMENT_DYNCREATE(CPropertySheetDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPropertySheetDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CPropertySheetDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoDoc construction/destruction

CPropertySheetDemoDoc::CPropertySheetDemoDoc()
{
	// TODO: add one-time construction code here

}

CPropertySheetDemoDoc::~CPropertySheetDemoDoc()
{
}

BOOL CPropertySheetDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoDoc serialization

void CPropertySheetDemoDoc::Serialize(CArchive& ar)
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
// CPropertySheetDemoDoc diagnostics

#ifdef _DEBUG
void CPropertySheetDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPropertySheetDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemoDoc commands
