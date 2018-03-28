// ViewControlBoxDoc.cpp : implementation of the CViewControlBoxDoc class
//

#include "stdafx.h"
#include "ViewControlBox.h"

#include "ViewControlBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewControlBoxDoc

IMPLEMENT_DYNCREATE(CViewControlBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CViewControlBoxDoc, CDocument)
	//{{AFX_MSG_MAP(CViewControlBoxDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewControlBoxDoc construction/destruction

CViewControlBoxDoc::CViewControlBoxDoc()
{
	// TODO: add one-time construction code here

}

CViewControlBoxDoc::~CViewControlBoxDoc()
{
}

BOOL CViewControlBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CViewControlBoxDoc serialization

void CViewControlBoxDoc::Serialize(CArchive& ar)
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
// CViewControlBoxDoc diagnostics

#ifdef _DEBUG
void CViewControlBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CViewControlBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewControlBoxDoc commands
