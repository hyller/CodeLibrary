// ReBarDemoDoc.cpp : implementation of the CReBarDemoDoc class
//

#include "stdafx.h"
#include "ReBarDemo.h"

#include "ReBarDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoDoc

IMPLEMENT_DYNCREATE(CReBarDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CReBarDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CReBarDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoDoc construction/destruction

CReBarDemoDoc::CReBarDemoDoc()
{
	// TODO: add one-time construction code here

}

CReBarDemoDoc::~CReBarDemoDoc()
{
}

BOOL CReBarDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CReBarDemoDoc serialization

void CReBarDemoDoc::Serialize(CArchive& ar)
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
// CReBarDemoDoc diagnostics

#ifdef _DEBUG
void CReBarDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CReBarDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CReBarDemoDoc commands
