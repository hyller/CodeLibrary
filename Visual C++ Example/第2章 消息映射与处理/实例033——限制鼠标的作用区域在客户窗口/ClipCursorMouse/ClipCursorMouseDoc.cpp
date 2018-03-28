// ClipCursorMouseDoc.cpp : implementation of the CClipCursorMouseDoc class
//

#include "stdafx.h"
#include "ClipCursorMouse.h"

#include "ClipCursorMouseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseDoc

IMPLEMENT_DYNCREATE(CClipCursorMouseDoc, CDocument)

BEGIN_MESSAGE_MAP(CClipCursorMouseDoc, CDocument)
	//{{AFX_MSG_MAP(CClipCursorMouseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseDoc construction/destruction

CClipCursorMouseDoc::CClipCursorMouseDoc()
{
	// TODO: add one-time construction code here

}

CClipCursorMouseDoc::~CClipCursorMouseDoc()
{
}

BOOL CClipCursorMouseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseDoc serialization

void CClipCursorMouseDoc::Serialize(CArchive& ar)
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
// CClipCursorMouseDoc diagnostics

#ifdef _DEBUG
void CClipCursorMouseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CClipCursorMouseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseDoc commands
