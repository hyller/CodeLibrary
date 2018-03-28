// StaticSplitWnd3Doc.cpp : implementation of the CStaticSplitWnd3Doc class
//

#include "stdafx.h"
#include "StaticSplitWnd3.h"

#include "StaticSplitWnd3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3Doc

IMPLEMENT_DYNCREATE(CStaticSplitWnd3Doc, CDocument)

BEGIN_MESSAGE_MAP(CStaticSplitWnd3Doc, CDocument)
	//{{AFX_MSG_MAP(CStaticSplitWnd3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3Doc construction/destruction

CStaticSplitWnd3Doc::CStaticSplitWnd3Doc()
{
	// TODO: add one-time construction code here

}

CStaticSplitWnd3Doc::~CStaticSplitWnd3Doc()
{
}

BOOL CStaticSplitWnd3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3Doc serialization

void CStaticSplitWnd3Doc::Serialize(CArchive& ar)
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
// CStaticSplitWnd3Doc diagnostics

#ifdef _DEBUG
void CStaticSplitWnd3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStaticSplitWnd3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd3Doc commands
