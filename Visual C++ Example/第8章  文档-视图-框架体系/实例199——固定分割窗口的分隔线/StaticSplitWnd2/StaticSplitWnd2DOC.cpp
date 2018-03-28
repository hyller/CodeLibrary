// StaticSplitWnd2Doc.cpp : implementation of the CStaticSplitWnd2Doc class
//

#include "stdafx.h"
#include "StaticSplitWnd2.h"

#include "StaticSplitWnd2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2Doc

IMPLEMENT_DYNCREATE(CStaticSplitWnd2Doc, CDocument)

BEGIN_MESSAGE_MAP(CStaticSplitWnd2Doc, CDocument)
	//{{AFX_MSG_MAP(CStaticSplitWnd2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2Doc construction/destruction

CStaticSplitWnd2Doc::CStaticSplitWnd2Doc()
{
	// TODO: add one-time construction code here

}

CStaticSplitWnd2Doc::~CStaticSplitWnd2Doc()
{
}

BOOL CStaticSplitWnd2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2Doc serialization

void CStaticSplitWnd2Doc::Serialize(CArchive& ar)
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
// CStaticSplitWnd2Doc diagnostics

#ifdef _DEBUG
void CStaticSplitWnd2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStaticSplitWnd2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd2Doc commands
