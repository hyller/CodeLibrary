// ADODataControlDoc.cpp : implementation of the CADODataControlDoc class
//

#include "stdafx.h"
#include "ADODataControl.h"

#include "ADODataControlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADODataControlDoc

IMPLEMENT_DYNCREATE(CADODataControlDoc, CDocument)

BEGIN_MESSAGE_MAP(CADODataControlDoc, CDocument)
	//{{AFX_MSG_MAP(CADODataControlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODataControlDoc construction/destruction

CADODataControlDoc::CADODataControlDoc()
{
	// TODO: add one-time construction code here

}

CADODataControlDoc::~CADODataControlDoc()
{
}

BOOL CADODataControlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CADODataControlDoc serialization

void CADODataControlDoc::Serialize(CArchive& ar)
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
// CADODataControlDoc diagnostics

#ifdef _DEBUG
void CADODataControlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CADODataControlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CADODataControlDoc commands
