// KeyMessageMenuDoc.cpp : implementation of the CKeyMessageMenuDoc class
//

#include "stdafx.h"
#include "KeyMessageMenu.h"

#include "KeyMessageMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuDoc

IMPLEMENT_DYNCREATE(CKeyMessageMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CKeyMessageMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CKeyMessageMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuDoc construction/destruction

CKeyMessageMenuDoc::CKeyMessageMenuDoc()
{
	// TODO: add one-time construction code here

}

CKeyMessageMenuDoc::~CKeyMessageMenuDoc()
{
}

BOOL CKeyMessageMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuDoc serialization

void CKeyMessageMenuDoc::Serialize(CArchive& ar)
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
// CKeyMessageMenuDoc diagnostics

#ifdef _DEBUG
void CKeyMessageMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKeyMessageMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKeyMessageMenuDoc commands
