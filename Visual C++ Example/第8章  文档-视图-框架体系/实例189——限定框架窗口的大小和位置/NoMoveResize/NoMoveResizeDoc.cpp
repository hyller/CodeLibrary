// NoMoveResizeDoc.cpp : implementation of the CNoMoveResizeDoc class
//

#include "stdafx.h"
#include "NoMoveResize.h"

#include "NoMoveResizeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeDoc

IMPLEMENT_DYNCREATE(CNoMoveResizeDoc, CDocument)

BEGIN_MESSAGE_MAP(CNoMoveResizeDoc, CDocument)
	//{{AFX_MSG_MAP(CNoMoveResizeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeDoc construction/destruction

CNoMoveResizeDoc::CNoMoveResizeDoc()
{
	// TODO: add one-time construction code here

}

CNoMoveResizeDoc::~CNoMoveResizeDoc()
{
}

BOOL CNoMoveResizeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeDoc serialization

void CNoMoveResizeDoc::Serialize(CArchive& ar)
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
// CNoMoveResizeDoc diagnostics

#ifdef _DEBUG
void CNoMoveResizeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNoMoveResizeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNoMoveResizeDoc commands
