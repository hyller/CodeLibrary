// WindowDcDemoDoc.cpp : implementation of the CWindowDcDemoDoc class
//

#include "stdafx.h"
#include "WindowDcDemo.h"

#include "WindowDcDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWindowDcDemoDoc

IMPLEMENT_DYNCREATE(CWindowDcDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CWindowDcDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CWindowDcDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowDcDemoDoc construction/destruction

CWindowDcDemoDoc::CWindowDcDemoDoc()
{
	// TODO: add one-time construction code here

}

CWindowDcDemoDoc::~CWindowDcDemoDoc()
{
}

BOOL CWindowDcDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWindowDcDemoDoc serialization

void CWindowDcDemoDoc::Serialize(CArchive& ar)
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
// CWindowDcDemoDoc diagnostics

#ifdef _DEBUG
void CWindowDcDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWindowDcDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWindowDcDemoDoc commands
