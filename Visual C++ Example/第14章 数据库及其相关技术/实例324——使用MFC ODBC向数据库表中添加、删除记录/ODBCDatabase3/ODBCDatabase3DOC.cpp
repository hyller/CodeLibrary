// ODBCDatabase3Doc.cpp : implementation of the CODBCDatabase3Doc class
//

#include "stdafx.h"
#include "ODBCDatabase3.h"

#include "ODBCDatabase3Set.h"
#include "ODBCDatabase3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3Doc

IMPLEMENT_DYNCREATE(CODBCDatabase3Doc, CDocument)

BEGIN_MESSAGE_MAP(CODBCDatabase3Doc, CDocument)
	//{{AFX_MSG_MAP(CODBCDatabase3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3Doc construction/destruction

CODBCDatabase3Doc::CODBCDatabase3Doc()
{
	// TODO: add one-time construction code here

}

CODBCDatabase3Doc::~CODBCDatabase3Doc()
{
}

BOOL CODBCDatabase3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3Doc serialization

void CODBCDatabase3Doc::Serialize(CArchive& ar)
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
// CODBCDatabase3Doc diagnostics

#ifdef _DEBUG
void CODBCDatabase3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CODBCDatabase3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3Doc commands
