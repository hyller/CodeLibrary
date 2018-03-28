// DcDemoDoc.cpp : implementation of the CDcDemoDoc class
//

#include "stdafx.h"
#include "DcDemo.h"

#include "DcDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDcDemoDoc

IMPLEMENT_DYNCREATE(CDcDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDcDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDcDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDcDemoDoc construction/destruction

CDcDemoDoc::CDcDemoDoc()
{
	// TODO: add one-time construction code here

}

CDcDemoDoc::~CDcDemoDoc()
{
}

BOOL CDcDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDcDemoDoc serialization

void CDcDemoDoc::Serialize(CArchive& ar)
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
// CDcDemoDoc diagnostics

#ifdef _DEBUG
void CDcDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDcDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDcDemoDoc commands
