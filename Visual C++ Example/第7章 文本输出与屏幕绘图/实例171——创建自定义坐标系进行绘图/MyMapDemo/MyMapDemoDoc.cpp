// MyMapDemoDoc.cpp : implementation of the CMyMapDemoDoc class
//

#include "stdafx.h"
#include "MyMapDemo.h"

#include "MyMapDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoDoc

IMPLEMENT_DYNCREATE(CMyMapDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyMapDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CMyMapDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoDoc construction/destruction

CMyMapDemoDoc::CMyMapDemoDoc()
{
	// TODO: add one-time construction code here

}

CMyMapDemoDoc::~CMyMapDemoDoc()
{
}

BOOL CMyMapDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoDoc serialization

void CMyMapDemoDoc::Serialize(CArchive& ar)
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
// CMyMapDemoDoc diagnostics

#ifdef _DEBUG
void CMyMapDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyMapDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyMapDemoDoc commands
