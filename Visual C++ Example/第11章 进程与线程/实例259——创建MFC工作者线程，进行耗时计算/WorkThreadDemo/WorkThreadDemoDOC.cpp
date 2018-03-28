// WorkThreadDemoDoc.cpp : implementation of the CWorkThreadDemoDoc class
//

#include "stdafx.h"
#include "WorkThreadDemo.h"

#include "WorkThreadDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkThreadDemoDoc

IMPLEMENT_DYNCREATE(CWorkThreadDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CWorkThreadDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CWorkThreadDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkThreadDemoDoc construction/destruction

CWorkThreadDemoDoc::CWorkThreadDemoDoc()
{
	// TODO: add one-time construction code here

}

CWorkThreadDemoDoc::~CWorkThreadDemoDoc()
{
}

BOOL CWorkThreadDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWorkThreadDemoDoc serialization

void CWorkThreadDemoDoc::Serialize(CArchive& ar)
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
// CWorkThreadDemoDoc diagnostics

#ifdef _DEBUG
void CWorkThreadDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWorkThreadDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWorkThreadDemoDoc commands
