// FullScreenDemoDoc.cpp : implementation of the CFullScreenDemoDoc class
//

#include "stdafx.h"
#include "FullScreenDemo.h"

#include "FullScreenDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDemoDoc

IMPLEMENT_DYNCREATE(CFullScreenDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CFullScreenDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CFullScreenDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDemoDoc construction/destruction

CFullScreenDemoDoc::CFullScreenDemoDoc()
{
	// TODO: add one-time construction code here

}

CFullScreenDemoDoc::~CFullScreenDemoDoc()
{
}

BOOL CFullScreenDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFullScreenDemoDoc serialization

void CFullScreenDemoDoc::Serialize(CArchive& ar)
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
// CFullScreenDemoDoc diagnostics

#ifdef _DEBUG
void CFullScreenDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFullScreenDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFullScreenDemoDoc commands
