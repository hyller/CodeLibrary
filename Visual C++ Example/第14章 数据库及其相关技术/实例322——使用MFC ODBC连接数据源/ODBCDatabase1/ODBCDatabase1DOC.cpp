// ODBCDatabase1Doc.cpp : implementation of the CODBCDatabase1Doc class
//

#include "stdafx.h"
#include "ODBCDatabase1.h"

#include "ODBCDatabase1Set.h"
#include "ODBCDatabase1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1Doc

IMPLEMENT_DYNCREATE(CODBCDatabase1Doc, CDocument)

BEGIN_MESSAGE_MAP(CODBCDatabase1Doc, CDocument)
	//{{AFX_MSG_MAP(CODBCDatabase1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1Doc construction/destruction

CODBCDatabase1Doc::CODBCDatabase1Doc()
{
	// TODO: add one-time construction code here

}

CODBCDatabase1Doc::~CODBCDatabase1Doc()
{
}

BOOL CODBCDatabase1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1Doc serialization

void CODBCDatabase1Doc::Serialize(CArchive& ar)
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
// CODBCDatabase1Doc diagnostics

#ifdef _DEBUG
void CODBCDatabase1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CODBCDatabase1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase1Doc commands
