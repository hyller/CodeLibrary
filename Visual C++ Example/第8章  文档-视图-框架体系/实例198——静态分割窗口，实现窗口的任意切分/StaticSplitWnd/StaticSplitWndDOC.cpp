// StaticSplitWndDoc.cpp : implementation of the CStaticSplitWndDoc class
//

#include "stdafx.h"
#include "StaticSplitWnd.h"

#include "StaticSplitWndDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndDoc

IMPLEMENT_DYNCREATE(CStaticSplitWndDoc, CDocument)

BEGIN_MESSAGE_MAP(CStaticSplitWndDoc, CDocument)
	//{{AFX_MSG_MAP(CStaticSplitWndDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndDoc construction/destruction

CStaticSplitWndDoc::CStaticSplitWndDoc()
{
	// TODO: add one-time construction code here

}

CStaticSplitWndDoc::~CStaticSplitWndDoc()
{
}

BOOL CStaticSplitWndDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndDoc serialization

void CStaticSplitWndDoc::Serialize(CArchive& ar)
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
// CStaticSplitWndDoc diagnostics

#ifdef _DEBUG
void CStaticSplitWndDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStaticSplitWndDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWndDoc commands
