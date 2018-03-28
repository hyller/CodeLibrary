// CursorMouseDemoDoc.cpp : implementation of the CCursorMouseDemoDoc class
//

#include "stdafx.h"
#include "CursorMouseDemo.h"

#include "CursorMouseDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoDoc

IMPLEMENT_DYNCREATE(CCursorMouseDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCursorMouseDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CCursorMouseDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoDoc construction/destruction

CCursorMouseDemoDoc::CCursorMouseDemoDoc()
{
	// TODO: add one-time construction code here

}

CCursorMouseDemoDoc::~CCursorMouseDemoDoc()
{
}

BOOL CCursorMouseDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoDoc serialization

void CCursorMouseDemoDoc::Serialize(CArchive& ar)
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
// CCursorMouseDemoDoc diagnostics

#ifdef _DEBUG
void CCursorMouseDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCursorMouseDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoDoc commands
