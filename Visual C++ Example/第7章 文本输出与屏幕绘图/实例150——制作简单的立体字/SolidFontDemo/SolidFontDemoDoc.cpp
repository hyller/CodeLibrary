// SolidFontDemoDoc.cpp : implementation of the CSolidFontDemoDoc class
//

#include "stdafx.h"
#include "SolidFontDemo.h"

#include "SolidFontDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoDoc

IMPLEMENT_DYNCREATE(CSolidFontDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CSolidFontDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CSolidFontDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoDoc construction/destruction

CSolidFontDemoDoc::CSolidFontDemoDoc()
{
	// TODO: add one-time construction code here

}

CSolidFontDemoDoc::~CSolidFontDemoDoc()
{
}

BOOL CSolidFontDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoDoc serialization

void CSolidFontDemoDoc::Serialize(CArchive& ar)
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
// CSolidFontDemoDoc diagnostics

#ifdef _DEBUG
void CSolidFontDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSolidFontDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSolidFontDemoDoc commands
