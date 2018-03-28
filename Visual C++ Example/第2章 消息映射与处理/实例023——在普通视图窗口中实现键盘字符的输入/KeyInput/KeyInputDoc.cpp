// KeyInputDoc.cpp : implementation of the CKeyInputDoc class
//

#include "stdafx.h"
#include "KeyInput.h"

#include "KeyInputDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyInputDoc

IMPLEMENT_DYNCREATE(CKeyInputDoc, CDocument)

BEGIN_MESSAGE_MAP(CKeyInputDoc, CDocument)
	//{{AFX_MSG_MAP(CKeyInputDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyInputDoc construction/destruction

CKeyInputDoc::CKeyInputDoc()
{
	// TODO: add one-time construction code here

}

CKeyInputDoc::~CKeyInputDoc()
{
}

BOOL CKeyInputDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKeyInputDoc serialization

void CKeyInputDoc::Serialize(CArchive& ar)
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
// CKeyInputDoc diagnostics

#ifdef _DEBUG
void CKeyInputDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKeyInputDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKeyInputDoc commands
