// BaseDlgDemo2Doc.cpp : implementation of the CBaseDlgDemo2Doc class
//

#include "stdafx.h"
#include "BaseDlgDemo2.h"

#include "BaseDlgDemo2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2Doc

IMPLEMENT_DYNCREATE(CBaseDlgDemo2Doc, CDocument)

BEGIN_MESSAGE_MAP(CBaseDlgDemo2Doc, CDocument)
	//{{AFX_MSG_MAP(CBaseDlgDemo2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2Doc construction/destruction

CBaseDlgDemo2Doc::CBaseDlgDemo2Doc()
{
	// TODO: add one-time construction code here

}

CBaseDlgDemo2Doc::~CBaseDlgDemo2Doc()
{
}

BOOL CBaseDlgDemo2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2Doc serialization

void CBaseDlgDemo2Doc::Serialize(CArchive& ar)
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
// CBaseDlgDemo2Doc diagnostics

#ifdef _DEBUG
void CBaseDlgDemo2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseDlgDemo2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDlgDemo2Doc commands
