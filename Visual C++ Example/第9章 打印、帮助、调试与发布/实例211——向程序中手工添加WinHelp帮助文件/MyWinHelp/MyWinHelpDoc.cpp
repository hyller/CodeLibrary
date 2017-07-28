// MyWinHelpDoc.cpp : implementation of the CMyWinHelpDoc class
//

#include "stdafx.h"
#include "MyWinHelp.h"

#include "MyWinHelpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpDoc

IMPLEMENT_DYNCREATE(CMyWinHelpDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyWinHelpDoc, CDocument)
	//{{AFX_MSG_MAP(CMyWinHelpDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpDoc construction/destruction

CMyWinHelpDoc::CMyWinHelpDoc()
{
	// TODO: add one-time construction code here

}

CMyWinHelpDoc::~CMyWinHelpDoc()
{
}

BOOL CMyWinHelpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpDoc serialization

void CMyWinHelpDoc::Serialize(CArchive& ar)
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
// CMyWinHelpDoc diagnostics

#ifdef _DEBUG
void CMyWinHelpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyWinHelpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyWinHelpDoc commands
