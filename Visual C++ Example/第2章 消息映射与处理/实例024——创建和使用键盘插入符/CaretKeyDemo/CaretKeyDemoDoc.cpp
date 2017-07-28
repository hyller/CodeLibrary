// CaretKeyDemoDoc.cpp : implementation of the CCaretKeyDemoDoc class
//

#include "stdafx.h"
#include "CaretKeyDemo.h"

#include "CaretKeyDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaretKeyDemoDoc

IMPLEMENT_DYNCREATE(CCaretKeyDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCaretKeyDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CCaretKeyDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaretKeyDemoDoc construction/destruction

CCaretKeyDemoDoc::CCaretKeyDemoDoc()
{
	// TODO: add one-time construction code here

}

CCaretKeyDemoDoc::~CCaretKeyDemoDoc()
{
}

BOOL CCaretKeyDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCaretKeyDemoDoc serialization

void CCaretKeyDemoDoc::Serialize(CArchive& ar)
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
// CCaretKeyDemoDoc diagnostics

#ifdef _DEBUG
void CCaretKeyDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCaretKeyDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCaretKeyDemoDoc commands
