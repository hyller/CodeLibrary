// DragViewEditDoc.cpp : implementation of the CDragViewEditDoc class
//

#include "stdafx.h"
#include "DragViewEdit.h"

#include "DragViewEditDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditDoc

IMPLEMENT_DYNCREATE(CDragViewEditDoc, CDocument)

BEGIN_MESSAGE_MAP(CDragViewEditDoc, CDocument)
	//{{AFX_MSG_MAP(CDragViewEditDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditDoc construction/destruction

CDragViewEditDoc::CDragViewEditDoc()
{
	// TODO: add one-time construction code here

}

CDragViewEditDoc::~CDragViewEditDoc()
{
}

BOOL CDragViewEditDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDragViewEditDoc serialization

void CDragViewEditDoc::Serialize(CArchive& ar)
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
// CDragViewEditDoc diagnostics

#ifdef _DEBUG
void CDragViewEditDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDragViewEditDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditDoc commands
