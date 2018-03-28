// MirroBmpDemoDoc.cpp : implementation of the CMirroBmpDemoDoc class
//

#include "stdafx.h"
#include "MirroBmpDemo.h"

#include "MirroBmpDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoDoc

IMPLEMENT_DYNCREATE(CMirroBmpDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMirroBmpDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CMirroBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoDoc construction/destruction

CMirroBmpDemoDoc::CMirroBmpDemoDoc()
{
	// TODO: add one-time construction code here

}

CMirroBmpDemoDoc::~CMirroBmpDemoDoc()
{
}

BOOL CMirroBmpDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoDoc serialization

void CMirroBmpDemoDoc::Serialize(CArchive& ar)
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
// CMirroBmpDemoDoc diagnostics

#ifdef _DEBUG
void CMirroBmpDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMirroBmpDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMirroBmpDemoDoc commands
