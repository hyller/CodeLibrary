// StaticSplitWnd4Doc.cpp : implementation of the CStaticSplitWnd4Doc class
//

#include "stdafx.h"
#include "StaticSplitWnd4.h"

#include "StaticSplitWnd4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4Doc

IMPLEMENT_DYNCREATE(CStaticSplitWnd4Doc, CDocument)

BEGIN_MESSAGE_MAP(CStaticSplitWnd4Doc, CDocument)
	//{{AFX_MSG_MAP(CStaticSplitWnd4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4Doc construction/destruction

CStaticSplitWnd4Doc::CStaticSplitWnd4Doc()
{
	// TODO: add one-time construction code here

}

CStaticSplitWnd4Doc::~CStaticSplitWnd4Doc()
{
}

BOOL CStaticSplitWnd4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4Doc serialization

void CStaticSplitWnd4Doc::Serialize(CArchive& ar)
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
// CStaticSplitWnd4Doc diagnostics

#ifdef _DEBUG
void CStaticSplitWnd4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStaticSplitWnd4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStaticSplitWnd4Doc commands
