// ChageTitleDoc.cpp : implementation of the CChageTitleDoc class
//

#include "stdafx.h"
#include "ChageTitle.h"

#include "ChageTitleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChageTitleDoc

IMPLEMENT_DYNCREATE(CChageTitleDoc, CDocument)

BEGIN_MESSAGE_MAP(CChageTitleDoc, CDocument)
	//{{AFX_MSG_MAP(CChageTitleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChageTitleDoc construction/destruction

CChageTitleDoc::CChageTitleDoc()
{
	// TODO: add one-time construction code here

}

CChageTitleDoc::~CChageTitleDoc()
{
}

BOOL CChageTitleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChageTitleDoc serialization

void CChageTitleDoc::Serialize(CArchive& ar)
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
// CChageTitleDoc diagnostics

#ifdef _DEBUG
void CChageTitleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChageTitleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChageTitleDoc commands
