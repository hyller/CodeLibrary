// BaseMouseDemoDoc.cpp : implementation of the CBaseMouseDemoDoc class
//

#include "stdafx.h"
#include "BaseMouseDemo.h"

#include "BaseMouseDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseMouseDemoDoc

IMPLEMENT_DYNCREATE(CBaseMouseDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CBaseMouseDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CBaseMouseDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseMouseDemoDoc construction/destruction

CBaseMouseDemoDoc::CBaseMouseDemoDoc()
{
	// TODO: add one-time construction code here

}

CBaseMouseDemoDoc::~CBaseMouseDemoDoc()
{
}

BOOL CBaseMouseDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseMouseDemoDoc serialization

void CBaseMouseDemoDoc::Serialize(CArchive& ar)
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
// CBaseMouseDemoDoc diagnostics

#ifdef _DEBUG
void CBaseMouseDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseMouseDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseMouseDemoDoc commands
