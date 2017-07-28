// DyScrollRectDoc.cpp : implementation of the CDyScrollRectDoc class
//

#include "stdafx.h"
#include "DyScrollRect.h"

#include "DyScrollRectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectDoc

IMPLEMENT_DYNCREATE(CDyScrollRectDoc, CDocument)

BEGIN_MESSAGE_MAP(CDyScrollRectDoc, CDocument)
	//{{AFX_MSG_MAP(CDyScrollRectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectDoc construction/destruction

CDyScrollRectDoc::CDyScrollRectDoc()
{
	// TODO: add one-time construction code here

}

CDyScrollRectDoc::~CDyScrollRectDoc()
{
}

BOOL CDyScrollRectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectDoc serialization

void CDyScrollRectDoc::Serialize(CArchive& ar)
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
// CDyScrollRectDoc diagnostics

#ifdef _DEBUG
void CDyScrollRectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDyScrollRectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectDoc commands
