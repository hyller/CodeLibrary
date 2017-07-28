// AutoHelpDoc.cpp : implementation of the CAutoHelpDoc class
//

#include "stdafx.h"
#include "AutoHelp.h"

#include "AutoHelpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpDoc

IMPLEMENT_DYNCREATE(CAutoHelpDoc, CDocument)

BEGIN_MESSAGE_MAP(CAutoHelpDoc, CDocument)
	//{{AFX_MSG_MAP(CAutoHelpDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpDoc construction/destruction

CAutoHelpDoc::CAutoHelpDoc()
{
	// TODO: add one-time construction code here

}

CAutoHelpDoc::~CAutoHelpDoc()
{
}

BOOL CAutoHelpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAutoHelpDoc serialization

void CAutoHelpDoc::Serialize(CArchive& ar)
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
// CAutoHelpDoc diagnostics

#ifdef _DEBUG
void CAutoHelpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAutoHelpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAutoHelpDoc commands
