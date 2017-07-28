// MappingDemoDoc.cpp : implementation of the CMappingDemoDoc class
//

#include "stdafx.h"
#include "MappingDemo.h"

#include "MappingDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoDoc

IMPLEMENT_DYNCREATE(CMappingDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMappingDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CMappingDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoDoc construction/destruction

CMappingDemoDoc::CMappingDemoDoc()
{
	// TODO: add one-time construction code here

}

CMappingDemoDoc::~CMappingDemoDoc()
{
}

BOOL CMappingDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMappingDemoDoc serialization

void CMappingDemoDoc::Serialize(CArchive& ar)
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
// CMappingDemoDoc diagnostics

#ifdef _DEBUG
void CMappingDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMappingDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMappingDemoDoc commands
