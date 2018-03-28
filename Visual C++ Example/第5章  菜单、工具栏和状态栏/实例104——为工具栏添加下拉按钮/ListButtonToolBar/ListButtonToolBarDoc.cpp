// ListButtonToolBarDoc.cpp : implementation of the CListButtonToolBarDoc class
//

#include "stdafx.h"
#include "ListButtonToolBar.h"

#include "ListButtonToolBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarDoc

IMPLEMENT_DYNCREATE(CListButtonToolBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CListButtonToolBarDoc, CDocument)
	//{{AFX_MSG_MAP(CListButtonToolBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarDoc construction/destruction

CListButtonToolBarDoc::CListButtonToolBarDoc()
{
	// TODO: add one-time construction code here

}

CListButtonToolBarDoc::~CListButtonToolBarDoc()
{
}

BOOL CListButtonToolBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarDoc serialization

void CListButtonToolBarDoc::Serialize(CArchive& ar)
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
// CListButtonToolBarDoc diagnostics

#ifdef _DEBUG
void CListButtonToolBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CListButtonToolBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarDoc commands
