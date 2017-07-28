// FaceControl2Doc.cpp : implementation of the CFaceControl2Doc class
//

#include "stdafx.h"
#include "FaceControl2.h"

#include "FaceControl2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2Doc

IMPLEMENT_DYNCREATE(CFaceControl2Doc, CDocument)

BEGIN_MESSAGE_MAP(CFaceControl2Doc, CDocument)
	//{{AFX_MSG_MAP(CFaceControl2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2Doc construction/destruction

CFaceControl2Doc::CFaceControl2Doc()
{
	// TODO: add one-time construction code here

}

CFaceControl2Doc::~CFaceControl2Doc()
{
}

BOOL CFaceControl2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFaceControl2Doc serialization

void CFaceControl2Doc::Serialize(CArchive& ar)
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
// CFaceControl2Doc diagnostics

#ifdef _DEBUG
void CFaceControl2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFaceControl2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl2Doc commands
