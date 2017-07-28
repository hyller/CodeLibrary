// PopUpToolBarDoc.cpp : implementation of the CPopUpToolBarDoc class
//

#include "stdafx.h"
#include "PopUpToolBar.h"

#include "PopUpToolBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarDoc

IMPLEMENT_DYNCREATE(CPopUpToolBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CPopUpToolBarDoc, CDocument)
	//{{AFX_MSG_MAP(CPopUpToolBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarDoc construction/destruction

CPopUpToolBarDoc::CPopUpToolBarDoc()
{
	// TODO: add one-time construction code here

}

CPopUpToolBarDoc::~CPopUpToolBarDoc()
{
}

BOOL CPopUpToolBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarDoc serialization

void CPopUpToolBarDoc::Serialize(CArchive& ar)
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
// CPopUpToolBarDoc diagnostics

#ifdef _DEBUG
void CPopUpToolBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPopUpToolBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarDoc commands
