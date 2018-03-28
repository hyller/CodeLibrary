// CopyBmpDemoDoc.cpp : implementation of the CCopyBmpDemoDoc class
//

#include "stdafx.h"
#include "CopyBmpDemo.h"

#include "CopyBmpDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoDoc

IMPLEMENT_DYNCREATE(CCopyBmpDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCopyBmpDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CCopyBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoDoc construction/destruction

CCopyBmpDemoDoc::CCopyBmpDemoDoc()
{
	// TODO: add one-time construction code here

}

CCopyBmpDemoDoc::~CCopyBmpDemoDoc()
{
}

BOOL CCopyBmpDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoDoc serialization

void CCopyBmpDemoDoc::Serialize(CArchive& ar)
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
// CCopyBmpDemoDoc diagnostics

#ifdef _DEBUG
void CCopyBmpDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCopyBmpDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCopyBmpDemoDoc commands
