// DrawArrowDemoDoc.cpp : implementation of the CDrawArrowDemoDoc class
//

#include "stdafx.h"
#include "DrawArrowDemo.h"

#include "DrawArrowDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoDoc

IMPLEMENT_DYNCREATE(CDrawArrowDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawArrowDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawArrowDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoDoc construction/destruction

CDrawArrowDemoDoc::CDrawArrowDemoDoc()
{
	// TODO: add one-time construction code here

}

CDrawArrowDemoDoc::~CDrawArrowDemoDoc()
{
}

BOOL CDrawArrowDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoDoc serialization

void CDrawArrowDemoDoc::Serialize(CArchive& ar)
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
// CDrawArrowDemoDoc diagnostics

#ifdef _DEBUG
void CDrawArrowDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawArrowDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawArrowDemoDoc commands
