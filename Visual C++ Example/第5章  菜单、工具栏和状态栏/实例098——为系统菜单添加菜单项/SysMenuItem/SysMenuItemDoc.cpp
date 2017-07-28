// SysMenuItemDoc.cpp : implementation of the CSysMenuItemDoc class
//

#include "stdafx.h"
#include "SysMenuItem.h"

#include "SysMenuItemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemDoc

IMPLEMENT_DYNCREATE(CSysMenuItemDoc, CDocument)

BEGIN_MESSAGE_MAP(CSysMenuItemDoc, CDocument)
	//{{AFX_MSG_MAP(CSysMenuItemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemDoc construction/destruction

CSysMenuItemDoc::CSysMenuItemDoc()
{
	// TODO: add one-time construction code here

}

CSysMenuItemDoc::~CSysMenuItemDoc()
{
}

BOOL CSysMenuItemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemDoc serialization

void CSysMenuItemDoc::Serialize(CArchive& ar)
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
// CSysMenuItemDoc diagnostics

#ifdef _DEBUG
void CSysMenuItemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSysMenuItemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemDoc commands
