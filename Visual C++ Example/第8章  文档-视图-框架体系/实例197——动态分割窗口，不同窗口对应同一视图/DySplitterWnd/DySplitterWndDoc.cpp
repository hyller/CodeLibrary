// DySplitterWndDoc.cpp : implementation of the CDySplitterWndDoc class
//

#include "stdafx.h"
#include "DySplitterWnd.h"

#include "DySplitterWndDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndDoc

IMPLEMENT_DYNCREATE(CDySplitterWndDoc, CDocument)

BEGIN_MESSAGE_MAP(CDySplitterWndDoc, CDocument)
	//{{AFX_MSG_MAP(CDySplitterWndDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndDoc construction/destruction

CDySplitterWndDoc::CDySplitterWndDoc()
{
	// TODO: add one-time construction code here

}

CDySplitterWndDoc::~CDySplitterWndDoc()
{
}

BOOL CDySplitterWndDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndDoc serialization

void CDySplitterWndDoc::Serialize(CArchive& ar)
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
// CDySplitterWndDoc diagnostics

#ifdef _DEBUG
void CDySplitterWndDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDySplitterWndDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndDoc commands
