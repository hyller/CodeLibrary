// OpenURLDoc.cpp : implementation of the COpenURLDoc class
//

#include "stdafx.h"
#include "OpenURL.h"

#include "OpenURLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenURLDoc

IMPLEMENT_DYNCREATE(COpenURLDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenURLDoc, CDocument)
	//{{AFX_MSG_MAP(COpenURLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenURLDoc construction/destruction

COpenURLDoc::COpenURLDoc()
{
	// TODO: add one-time construction code here

}

COpenURLDoc::~COpenURLDoc()
{
}

BOOL COpenURLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COpenURLDoc serialization

void COpenURLDoc::Serialize(CArchive& ar)
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
// COpenURLDoc diagnostics

#ifdef _DEBUG
void COpenURLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenURLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenURLDoc commands
