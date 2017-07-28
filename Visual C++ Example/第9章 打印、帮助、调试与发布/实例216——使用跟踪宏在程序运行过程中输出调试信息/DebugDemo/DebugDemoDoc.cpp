// DebugDemoDoc.cpp : implementation of the CDebugDemoDoc class
//

#include "stdafx.h"
#include "DebugDemo.h"

#include "DebugDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoDoc

IMPLEMENT_DYNCREATE(CDebugDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDebugDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDebugDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoDoc construction/destruction

CDebugDemoDoc::CDebugDemoDoc()
{
	// TODO: add one-time construction code here

}

CDebugDemoDoc::~CDebugDemoDoc()
{
}

BOOL CDebugDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDebugDemoDoc serialization

void CDebugDemoDoc::Serialize(CArchive& ar)
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
// CDebugDemoDoc diagnostics

#ifdef _DEBUG
void CDebugDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDebugDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoDoc commands
