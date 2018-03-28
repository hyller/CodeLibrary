// ClipBmpDemoDoc.cpp : implementation of the CClipBmpDemoDoc class
//

#include "stdafx.h"
#include "ClipBmpDemo.h"

#include "ClipBmpDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClipBmpDemoDoc

IMPLEMENT_DYNCREATE(CClipBmpDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CClipBmpDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CClipBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClipBmpDemoDoc construction/destruction

CClipBmpDemoDoc::CClipBmpDemoDoc()
{
	// TODO: add one-time construction code here

}

CClipBmpDemoDoc::~CClipBmpDemoDoc()
{
}

BOOL CClipBmpDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CClipBmpDemoDoc serialization

void CClipBmpDemoDoc::Serialize(CArchive& ar)
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
// CClipBmpDemoDoc diagnostics

#ifdef _DEBUG
void CClipBmpDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CClipBmpDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClipBmpDemoDoc commands
