// StatusBmpDoc.cpp : implementation of the CStatusBmpDoc class
//

#include "stdafx.h"
#include "StatusBmp.h"

#include "StatusBmpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpDoc

IMPLEMENT_DYNCREATE(CStatusBmpDoc, CDocument)

BEGIN_MESSAGE_MAP(CStatusBmpDoc, CDocument)
	//{{AFX_MSG_MAP(CStatusBmpDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpDoc construction/destruction

CStatusBmpDoc::CStatusBmpDoc()
{
	// TODO: add one-time construction code here

}

CStatusBmpDoc::~CStatusBmpDoc()
{
}

BOOL CStatusBmpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStatusBmpDoc serialization

void CStatusBmpDoc::Serialize(CArchive& ar)
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
// CStatusBmpDoc diagnostics

#ifdef _DEBUG
void CStatusBmpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStatusBmpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusBmpDoc commands
