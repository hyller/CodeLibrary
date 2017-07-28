// RgnDemoDoc.cpp : implementation of the CRgnDemoDoc class
//

#include "stdafx.h"
#include "RgnDemo.h"

#include "RgnDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoDoc

IMPLEMENT_DYNCREATE(CRgnDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CRgnDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CRgnDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoDoc construction/destruction

CRgnDemoDoc::CRgnDemoDoc()
{
	// TODO: add one-time construction code here

}

CRgnDemoDoc::~CRgnDemoDoc()
{
}

BOOL CRgnDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRgnDemoDoc serialization

void CRgnDemoDoc::Serialize(CArchive& ar)
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
// CRgnDemoDoc diagnostics

#ifdef _DEBUG
void CRgnDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRgnDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRgnDemoDoc commands
