// FaceControl4Doc.cpp : implementation of the CFaceControl4Doc class
//

#include "stdafx.h"
#include "FaceControl4.h"

#include "FaceControl4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl4Doc

IMPLEMENT_DYNCREATE(CFaceControl4Doc, CDocument)

BEGIN_MESSAGE_MAP(CFaceControl4Doc, CDocument)
	//{{AFX_MSG_MAP(CFaceControl4Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl4Doc construction/destruction

CFaceControl4Doc::CFaceControl4Doc()
{
	// TODO: add one-time construction code here

}

CFaceControl4Doc::~CFaceControl4Doc()
{
}

BOOL CFaceControl4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFaceControl4Doc serialization

void CFaceControl4Doc::Serialize(CArchive& ar)
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
// CFaceControl4Doc diagnostics

#ifdef _DEBUG
void CFaceControl4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFaceControl4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl4Doc commands
