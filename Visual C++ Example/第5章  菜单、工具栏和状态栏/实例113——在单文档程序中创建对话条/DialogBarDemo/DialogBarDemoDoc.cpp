// DialogBarDemoDoc.cpp : implementation of the CDialogBarDemoDoc class
//

#include "stdafx.h"
#include "DialogBarDemo.h"

#include "DialogBarDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoDoc

IMPLEMENT_DYNCREATE(CDialogBarDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDialogBarDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CDialogBarDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoDoc construction/destruction

CDialogBarDemoDoc::CDialogBarDemoDoc()
{
	// TODO: add one-time construction code here

}

CDialogBarDemoDoc::~CDialogBarDemoDoc()
{
}

BOOL CDialogBarDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoDoc serialization

void CDialogBarDemoDoc::Serialize(CArchive& ar)
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
// CDialogBarDemoDoc diagnostics

#ifdef _DEBUG
void CDialogBarDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDialogBarDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDemoDoc commands
