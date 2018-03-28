// SelectMunuDoc.cpp : implementation of the CSelectMunuDoc class
//

#include "stdafx.h"
#include "SelectMunu.h"

#include "SelectMunuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuDoc

IMPLEMENT_DYNCREATE(CSelectMunuDoc, CDocument)

BEGIN_MESSAGE_MAP(CSelectMunuDoc, CDocument)
	//{{AFX_MSG_MAP(CSelectMunuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuDoc construction/destruction

CSelectMunuDoc::CSelectMunuDoc()
{
	// TODO: add one-time construction code here

}

CSelectMunuDoc::~CSelectMunuDoc()
{
}

BOOL CSelectMunuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSelectMunuDoc serialization

void CSelectMunuDoc::Serialize(CArchive& ar)
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
// CSelectMunuDoc diagnostics

#ifdef _DEBUG
void CSelectMunuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSelectMunuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuDoc commands
