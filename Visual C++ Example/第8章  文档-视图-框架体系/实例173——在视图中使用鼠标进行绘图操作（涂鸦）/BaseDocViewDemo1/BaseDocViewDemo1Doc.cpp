// BaseDocViewDemo1Doc.cpp : implementation of the CBaseDocViewDemo1Doc class
//

#include "stdafx.h"
#include "BaseDocViewDemo1.h"

#include "BaseDocViewDemo1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1Doc

IMPLEMENT_DYNCREATE(CBaseDocViewDemo1Doc, CDocument)

BEGIN_MESSAGE_MAP(CBaseDocViewDemo1Doc, CDocument)
	//{{AFX_MSG_MAP(CBaseDocViewDemo1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1Doc construction/destruction

CBaseDocViewDemo1Doc::CBaseDocViewDemo1Doc()
{
	// TODO: add one-time construction code here

}

CBaseDocViewDemo1Doc::~CBaseDocViewDemo1Doc()
{
}

BOOL CBaseDocViewDemo1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1Doc serialization

void CBaseDocViewDemo1Doc::Serialize(CArchive& ar)
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
// CBaseDocViewDemo1Doc diagnostics

#ifdef _DEBUG
void CBaseDocViewDemo1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseDocViewDemo1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1Doc commands
