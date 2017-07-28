// LineDDADemoDoc.cpp : implementation of the CLineDDADemoDoc class
//

#include "stdafx.h"
#include "LineDDADemo.h"

#include "LineDDADemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoDoc

IMPLEMENT_DYNCREATE(CLineDDADemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CLineDDADemoDoc, CDocument)
	//{{AFX_MSG_MAP(CLineDDADemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoDoc construction/destruction

CLineDDADemoDoc::CLineDDADemoDoc()
{
	// TODO: add one-time construction code here

}

CLineDDADemoDoc::~CLineDDADemoDoc()
{
}

BOOL CLineDDADemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoDoc serialization

void CLineDDADemoDoc::Serialize(CArchive& ar)
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
// CLineDDADemoDoc diagnostics

#ifdef _DEBUG
void CLineDDADemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLineDDADemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoDoc commands
