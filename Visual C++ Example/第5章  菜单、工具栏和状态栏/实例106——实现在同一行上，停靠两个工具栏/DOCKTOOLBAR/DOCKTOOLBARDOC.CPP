// DockToolbarDoc.cpp : implementation of the CDockToolbarDoc class
//

#include "stdafx.h"
#include "DockToolbar.h"

#include "DockToolbarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarDoc

IMPLEMENT_DYNCREATE(CDockToolbarDoc, CDocument)

BEGIN_MESSAGE_MAP(CDockToolbarDoc, CDocument)
	//{{AFX_MSG_MAP(CDockToolbarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarDoc construction/destruction

CDockToolbarDoc::CDockToolbarDoc()
{
	// TODO: add one-time construction code here

}

CDockToolbarDoc::~CDockToolbarDoc()
{
}

BOOL CDockToolbarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDockToolbarDoc serialization

void CDockToolbarDoc::Serialize(CArchive& ar)
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
// CDockToolbarDoc diagnostics

#ifdef _DEBUG
void CDockToolbarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDockToolbarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDockToolbarDoc commands
