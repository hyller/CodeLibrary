// BaseDlgDemoDoc.cpp : implementation of the CBaseDlgDemoDoc class
//

#include "stdafx.h"
#include "BaseDlgDemo.h"

#include "BaseDlgDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoDoc

IMPLEMENT_DYNCREATE(CBaseDlgDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CBaseDlgDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CBaseDlgDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoDoc construction/destruction

CBaseDlgDemoDoc::CBaseDlgDemoDoc()
{
	// TODO: add one-time construction code here

}

CBaseDlgDemoDoc::~CBaseDlgDemoDoc()
{
}

BOOL CBaseDlgDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoDoc serialization

void CBaseDlgDemoDoc::Serialize(CArchive& ar)
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
// CBaseDlgDemoDoc diagnostics

#ifdef _DEBUG
void CBaseDlgDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseDlgDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemoDoc commands
