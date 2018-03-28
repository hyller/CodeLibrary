// PenDemoDoc.cpp : implementation of the CPenDemoDoc class
//

#include "stdafx.h"
#include "PenDemo.h"

#include "PenDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPenDemoDoc

IMPLEMENT_DYNCREATE(CPenDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPenDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CPenDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPenDemoDoc construction/destruction

CPenDemoDoc::CPenDemoDoc()
{
	// TODO: add one-time construction code here

}

CPenDemoDoc::~CPenDemoDoc()
{
}

BOOL CPenDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPenDemoDoc serialization

void CPenDemoDoc::Serialize(CArchive& ar)
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
// CPenDemoDoc diagnostics

#ifdef _DEBUG
void CPenDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPenDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPenDemoDoc commands
