// HtmlVIEDoc.cpp : implementation of the CHtmlVIEDoc class
//

#include "stdafx.h"
#include "HtmlVIE.h"

#include "HtmlVIEDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEDoc

IMPLEMENT_DYNCREATE(CHtmlVIEDoc, CDocument)

BEGIN_MESSAGE_MAP(CHtmlVIEDoc, CDocument)
	//{{AFX_MSG_MAP(CHtmlVIEDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEDoc construction/destruction

CHtmlVIEDoc::CHtmlVIEDoc()
{
	// TODO: add one-time construction code here

}

CHtmlVIEDoc::~CHtmlVIEDoc()
{
}

BOOL CHtmlVIEDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEDoc serialization

void CHtmlVIEDoc::Serialize(CArchive& ar)
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
// CHtmlVIEDoc diagnostics

#ifdef _DEBUG
void CHtmlVIEDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHtmlVIEDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHtmlVIEDoc commands
