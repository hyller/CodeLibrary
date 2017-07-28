// StatusTimeDoc.cpp : implementation of the CStatusTimeDoc class
//

#include "stdafx.h"
#include "StatusTime.h"

#include "StatusTimeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeDoc

IMPLEMENT_DYNCREATE(CStatusTimeDoc, CDocument)

BEGIN_MESSAGE_MAP(CStatusTimeDoc, CDocument)
	//{{AFX_MSG_MAP(CStatusTimeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeDoc construction/destruction

CStatusTimeDoc::CStatusTimeDoc()
{
	// TODO: add one-time construction code here

}

CStatusTimeDoc::~CStatusTimeDoc()
{
}

BOOL CStatusTimeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStatusTimeDoc serialization

void CStatusTimeDoc::Serialize(CArchive& ar)
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
// CStatusTimeDoc diagnostics

#ifdef _DEBUG
void CStatusTimeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStatusTimeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusTimeDoc commands
