// FaceControl3Doc.cpp : implementation of the CFaceControl3Doc class
//

#include "stdafx.h"
#include "FaceControl3.h"

#include "FaceControl3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3Doc

IMPLEMENT_DYNCREATE(CFaceControl3Doc, CDocument)

BEGIN_MESSAGE_MAP(CFaceControl3Doc, CDocument)
	//{{AFX_MSG_MAP(CFaceControl3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3Doc construction/destruction

CFaceControl3Doc::CFaceControl3Doc()
{
	// TODO: add one-time construction code here

}

CFaceControl3Doc::~CFaceControl3Doc()
{
}

BOOL CFaceControl3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFaceControl3Doc serialization

void CFaceControl3Doc::Serialize(CArchive& ar)
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
// CFaceControl3Doc diagnostics

#ifdef _DEBUG
void CFaceControl3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFaceControl3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl3Doc commands
