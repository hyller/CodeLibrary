// TakeScreenDemoDoc.cpp : implementation of the CTakeScreenDemoDoc class
//

#include "stdafx.h"
#include "TakeScreenDemo.h"

#include "TakeScreenDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTakeScreenDemoDoc

IMPLEMENT_DYNCREATE(CTakeScreenDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTakeScreenDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CTakeScreenDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTakeScreenDemoDoc construction/destruction

CTakeScreenDemoDoc::CTakeScreenDemoDoc()
{
	// TODO: add one-time construction code here

}

CTakeScreenDemoDoc::~CTakeScreenDemoDoc()
{
}

BOOL CTakeScreenDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTakeScreenDemoDoc serialization

void CTakeScreenDemoDoc::Serialize(CArchive& ar)
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
// CTakeScreenDemoDoc diagnostics

#ifdef _DEBUG
void CTakeScreenDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTakeScreenDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTakeScreenDemoDoc commands
