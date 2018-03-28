// FaceControl5Doc.cpp : implementation of the CFaceControl5Doc class
//

#include "stdafx.h"
#include "FaceControl5.h"

#include "FaceControl5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5Doc

IMPLEMENT_DYNCREATE(CFaceControl5Doc, CDocument)

BEGIN_MESSAGE_MAP(CFaceControl5Doc, CDocument)
	//{{AFX_MSG_MAP(CFaceControl5Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5Doc construction/destruction

CFaceControl5Doc::CFaceControl5Doc()
{
	// TODO: add one-time construction code here

}

CFaceControl5Doc::~CFaceControl5Doc()
{
}

BOOL CFaceControl5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFaceControl5Doc serialization

void CFaceControl5Doc::Serialize(CArchive& ar)
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
// CFaceControl5Doc diagnostics

#ifdef _DEBUG
void CFaceControl5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFaceControl5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl5Doc commands
