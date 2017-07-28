// ODBCDatabase2Doc.cpp : implementation of the CODBCDatabase2Doc class
//

#include "stdafx.h"
#include "ODBCDatabase2.h"

#include "ODBCDatabase2Set.h"
#include "ODBCDatabase2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2Doc

IMPLEMENT_DYNCREATE(CODBCDatabase2Doc, CDocument)

BEGIN_MESSAGE_MAP(CODBCDatabase2Doc, CDocument)
	//{{AFX_MSG_MAP(CODBCDatabase2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2Doc construction/destruction

CODBCDatabase2Doc::CODBCDatabase2Doc()
{
	// TODO: add one-time construction code here

}

CODBCDatabase2Doc::~CODBCDatabase2Doc()
{
}

BOOL CODBCDatabase2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2Doc serialization

void CODBCDatabase2Doc::Serialize(CArchive& ar)
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
// CODBCDatabase2Doc diagnostics

#ifdef _DEBUG
void CODBCDatabase2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CODBCDatabase2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2Doc commands
