// TextButtonToolDoc.cpp : implementation of the CTextButtonToolDoc class
//

#include "stdafx.h"
#include "TextButtonTool.h"

#include "TextButtonToolDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolDoc

IMPLEMENT_DYNCREATE(CTextButtonToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextButtonToolDoc, CDocument)
	//{{AFX_MSG_MAP(CTextButtonToolDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolDoc construction/destruction

CTextButtonToolDoc::CTextButtonToolDoc()
{
	// TODO: add one-time construction code here

}

CTextButtonToolDoc::~CTextButtonToolDoc()
{
}

BOOL CTextButtonToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolDoc serialization

void CTextButtonToolDoc::Serialize(CArchive& ar)
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
// CTextButtonToolDoc diagnostics

#ifdef _DEBUG
void CTextButtonToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextButtonToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolDoc commands
