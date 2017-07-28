// PaintDcDemoDoc.cpp : implementation of the CPaintDcDemoDoc class
//

#include "stdafx.h"
#include "PaintDcDemo.h"

#include "PaintDcDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoDoc

IMPLEMENT_DYNCREATE(CPaintDcDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaintDcDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CPaintDcDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoDoc construction/destruction

CPaintDcDemoDoc::CPaintDcDemoDoc()
{
	// TODO: add one-time construction code here

}

CPaintDcDemoDoc::~CPaintDcDemoDoc()
{
}

BOOL CPaintDcDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoDoc serialization

void CPaintDcDemoDoc::Serialize(CArchive& ar)
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
// CPaintDcDemoDoc diagnostics

#ifdef _DEBUG
void CPaintDcDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaintDcDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaintDcDemoDoc commands
