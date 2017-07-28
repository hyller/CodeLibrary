// SuspendWndDoc.cpp : implementation of the CSuspendWndDoc class
//

#include "stdafx.h"
#include "SuspendWnd.h"

#include "SuspendWndDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndDoc

IMPLEMENT_DYNCREATE(CSuspendWndDoc, CDocument)

BEGIN_MESSAGE_MAP(CSuspendWndDoc, CDocument)
	//{{AFX_MSG_MAP(CSuspendWndDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndDoc construction/destruction

CSuspendWndDoc::CSuspendWndDoc()
{
	// TODO: add one-time construction code here

}

CSuspendWndDoc::~CSuspendWndDoc()
{
}

BOOL CSuspendWndDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSuspendWndDoc serialization

void CSuspendWndDoc::Serialize(CArchive& ar)
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
// CSuspendWndDoc diagnostics

#ifdef _DEBUG
void CSuspendWndDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSuspendWndDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSuspendWndDoc commands
