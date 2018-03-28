// PrintRealDemoDoc.cpp : implementation of the CPrintRealDemoDoc class
//

#include "stdafx.h"
#include "PrintRealDemo.h"

#include "PrintRealDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemoDoc

IMPLEMENT_DYNCREATE(CPrintRealDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrintRealDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CPrintRealDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemoDoc construction/destruction

CPrintRealDemoDoc::CPrintRealDemoDoc()
{
	// TODO: add one-time construction code here

}

CPrintRealDemoDoc::~CPrintRealDemoDoc()
{
}

BOOL CPrintRealDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemoDoc serialization

void CPrintRealDemoDoc::Serialize(CArchive& ar)
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
// CPrintRealDemoDoc diagnostics

#ifdef _DEBUG
void CPrintRealDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintRealDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintRealDemoDoc commands
