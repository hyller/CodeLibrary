// CommandRangeDemoDoc.cpp : implementation of the CCommandRangeDemoDoc class
//

#include "stdafx.h"
#include "CommandRangeDemo.h"

#include "CommandRangeDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoDoc

IMPLEMENT_DYNCREATE(CCommandRangeDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCommandRangeDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CCommandRangeDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoDoc construction/destruction

CCommandRangeDemoDoc::CCommandRangeDemoDoc()
{
	// TODO: add one-time construction code here

}

CCommandRangeDemoDoc::~CCommandRangeDemoDoc()
{
}

BOOL CCommandRangeDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoDoc serialization

void CCommandRangeDemoDoc::Serialize(CArchive& ar)
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
// CCommandRangeDemoDoc diagnostics

#ifdef _DEBUG
void CCommandRangeDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCommandRangeDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCommandRangeDemoDoc commands
