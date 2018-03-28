// ComboToolbarDoc.cpp : implementation of the CComboToolbarDoc class
//

#include "stdafx.h"
#include "ComboToolbar.h"

#include "ComboToolbarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarDoc

IMPLEMENT_DYNCREATE(CComboToolbarDoc, CDocument)

BEGIN_MESSAGE_MAP(CComboToolbarDoc, CDocument)
	//{{AFX_MSG_MAP(CComboToolbarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarDoc construction/destruction

CComboToolbarDoc::CComboToolbarDoc()
{
	// TODO: add one-time construction code here

}

CComboToolbarDoc::~CComboToolbarDoc()
{
}

BOOL CComboToolbarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CComboToolbarDoc serialization

void CComboToolbarDoc::Serialize(CArchive& ar)
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
// CComboToolbarDoc diagnostics

#ifdef _DEBUG
void CComboToolbarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CComboToolbarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComboToolbarDoc commands
