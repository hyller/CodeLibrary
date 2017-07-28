// BaseToolbarDoc.cpp : implementation of the CBaseToolbarDoc class
//

#include "stdafx.h"
#include "BaseToolbar.h"

#include "BaseToolbarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarDoc

IMPLEMENT_DYNCREATE(CBaseToolbarDoc, CDocument)

BEGIN_MESSAGE_MAP(CBaseToolbarDoc, CDocument)
	//{{AFX_MSG_MAP(CBaseToolbarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarDoc construction/destruction

CBaseToolbarDoc::CBaseToolbarDoc()
{
	// TODO: add one-time construction code here

}

CBaseToolbarDoc::~CBaseToolbarDoc()
{
}

BOOL CBaseToolbarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarDoc serialization

void CBaseToolbarDoc::Serialize(CArchive& ar)
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
// CBaseToolbarDoc diagnostics

#ifdef _DEBUG
void CBaseToolbarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseToolbarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseToolbarDoc commands
