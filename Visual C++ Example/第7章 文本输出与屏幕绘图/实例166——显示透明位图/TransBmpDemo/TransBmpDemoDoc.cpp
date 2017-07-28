// TransBmpDemoDoc.cpp : implementation of the CTransBmpDemoDoc class
//

#include "stdafx.h"
#include "TransBmpDemo.h"

#include "TransBmpDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoDoc

IMPLEMENT_DYNCREATE(CTransBmpDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTransBmpDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CTransBmpDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoDoc construction/destruction

CTransBmpDemoDoc::CTransBmpDemoDoc()
{
	// TODO: add one-time construction code here

}

CTransBmpDemoDoc::~CTransBmpDemoDoc()
{
}

BOOL CTransBmpDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoDoc serialization

void CTransBmpDemoDoc::Serialize(CArchive& ar)
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
// CTransBmpDemoDoc diagnostics

#ifdef _DEBUG
void CTransBmpDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTransBmpDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTransBmpDemoDoc commands
