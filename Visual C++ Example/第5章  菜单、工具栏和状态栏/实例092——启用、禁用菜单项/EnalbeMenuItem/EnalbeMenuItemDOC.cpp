// EnalbeMenuItemDoc.cpp : implementation of the CEnalbeMenuItemDoc class
//

#include "stdafx.h"
#include "EnalbeMenuItem.h"

#include "EnalbeMenuItemDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemDoc

IMPLEMENT_DYNCREATE(CEnalbeMenuItemDoc, CDocument)

BEGIN_MESSAGE_MAP(CEnalbeMenuItemDoc, CDocument)
	//{{AFX_MSG_MAP(CEnalbeMenuItemDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemDoc construction/destruction

CEnalbeMenuItemDoc::CEnalbeMenuItemDoc()
{
	// TODO: add one-time construction code here

}

CEnalbeMenuItemDoc::~CEnalbeMenuItemDoc()
{
}

BOOL CEnalbeMenuItemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemDoc serialization

void CEnalbeMenuItemDoc::Serialize(CArchive& ar)
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
// CEnalbeMenuItemDoc diagnostics

#ifdef _DEBUG
void CEnalbeMenuItemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEnalbeMenuItemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEnalbeMenuItemDoc commands
