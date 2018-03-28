// BaseMenuDemoDoc.cpp : implementation of the CBaseMenuDemoDoc class
//

#include "stdafx.h"
#include "BaseMenuDemo.h"

#include "BaseMenuDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoDoc

IMPLEMENT_DYNCREATE(CBaseMenuDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CBaseMenuDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CBaseMenuDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoDoc construction/destruction

CBaseMenuDemoDoc::CBaseMenuDemoDoc()
{
	// TODO: add one-time construction code here

}

CBaseMenuDemoDoc::~CBaseMenuDemoDoc()
{
}

BOOL CBaseMenuDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoDoc serialization

void CBaseMenuDemoDoc::Serialize(CArchive& ar)
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
// CBaseMenuDemoDoc diagnostics

#ifdef _DEBUG
void CBaseMenuDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseMenuDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseMenuDemoDoc commands
