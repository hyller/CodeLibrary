// PopUpMenuDoc.cpp : implementation of the CPopUpMenuDoc class
//

#include "stdafx.h"
#include "PopUpMenu.h"

#include "PopUpMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuDoc

IMPLEMENT_DYNCREATE(CPopUpMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CPopUpMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CPopUpMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuDoc construction/destruction

CPopUpMenuDoc::CPopUpMenuDoc()
{
	// TODO: add one-time construction code here

}

CPopUpMenuDoc::~CPopUpMenuDoc()
{
}

BOOL CPopUpMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuDoc serialization

void CPopUpMenuDoc::Serialize(CArchive& ar)
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
// CPopUpMenuDoc diagnostics

#ifdef _DEBUG
void CPopUpMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPopUpMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopUpMenuDoc commands
