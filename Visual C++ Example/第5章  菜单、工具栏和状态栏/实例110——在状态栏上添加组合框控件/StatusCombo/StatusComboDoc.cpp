// StatusComboDoc.cpp : implementation of the CStatusComboDoc class
//

#include "stdafx.h"
#include "StatusCombo.h"

#include "StatusComboDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatusComboDoc

IMPLEMENT_DYNCREATE(CStatusComboDoc, CDocument)

BEGIN_MESSAGE_MAP(CStatusComboDoc, CDocument)
	//{{AFX_MSG_MAP(CStatusComboDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatusComboDoc construction/destruction

CStatusComboDoc::CStatusComboDoc()
{
	// TODO: add one-time construction code here

}

CStatusComboDoc::~CStatusComboDoc()
{
}

BOOL CStatusComboDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStatusComboDoc serialization

void CStatusComboDoc::Serialize(CArchive& ar)
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
// CStatusComboDoc diagnostics

#ifdef _DEBUG
void CStatusComboDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStatusComboDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStatusComboDoc commands
