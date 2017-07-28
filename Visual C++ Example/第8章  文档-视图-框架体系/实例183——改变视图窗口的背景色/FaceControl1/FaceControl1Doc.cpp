// FaceControl1Doc.cpp : implementation of the CFaceControl1Doc class
//

#include "stdafx.h"
#include "FaceControl1.h"

#include "FaceControl1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1Doc

IMPLEMENT_DYNCREATE(CFaceControl1Doc, CDocument)

BEGIN_MESSAGE_MAP(CFaceControl1Doc, CDocument)
	//{{AFX_MSG_MAP(CFaceControl1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1Doc construction/destruction

CFaceControl1Doc::CFaceControl1Doc()
{
	// TODO: add one-time construction code here

}

CFaceControl1Doc::~CFaceControl1Doc()
{
}

BOOL CFaceControl1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFaceControl1Doc serialization

void CFaceControl1Doc::Serialize(CArchive& ar)
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
// CFaceControl1Doc diagnostics

#ifdef _DEBUG
void CFaceControl1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFaceControl1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1Doc commands
