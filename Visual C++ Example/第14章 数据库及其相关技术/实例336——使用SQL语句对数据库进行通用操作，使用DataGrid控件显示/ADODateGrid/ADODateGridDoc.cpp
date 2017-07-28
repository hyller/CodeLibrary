// ADODateGridDoc.cpp : implementation of the CADODateGridDoc class
//

#include "stdafx.h"
#include "ADODateGrid.h"

#include "ADODateGridDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADODateGridDoc

IMPLEMENT_DYNCREATE(CADODateGridDoc, CDocument)

BEGIN_MESSAGE_MAP(CADODateGridDoc, CDocument)
	//{{AFX_MSG_MAP(CADODateGridDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODateGridDoc construction/destruction

CADODateGridDoc::CADODateGridDoc()
{
	// TODO: add one-time construction code here

}

CADODateGridDoc::~CADODateGridDoc()
{
}

BOOL CADODateGridDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CADODateGridDoc serialization

void CADODateGridDoc::Serialize(CArchive& ar)
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
// CADODateGridDoc diagnostics

#ifdef _DEBUG
void CADODateGridDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CADODateGridDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CADODateGridDoc commands
