// RegistDemoDoc.cpp : implementation of the CRegistDemoDoc class
//

#include "stdafx.h"
#include "RegistDemo.h"

#include "RegistDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoDoc

IMPLEMENT_DYNCREATE(CRegistDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CRegistDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CRegistDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoDoc construction/destruction

CRegistDemoDoc::CRegistDemoDoc()
{
	// TODO: add one-time construction code here

}

CRegistDemoDoc::~CRegistDemoDoc()
{
}

BOOL CRegistDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRegistDemoDoc serialization

void CRegistDemoDoc::Serialize(CArchive& ar)
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
// CRegistDemoDoc diagnostics

#ifdef _DEBUG
void CRegistDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRegistDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRegistDemoDoc commands
