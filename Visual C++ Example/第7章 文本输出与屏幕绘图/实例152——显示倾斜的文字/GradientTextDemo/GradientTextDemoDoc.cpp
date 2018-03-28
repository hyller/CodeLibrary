// GradientTextDemoDoc.cpp : implementation of the CGradientTextDemoDoc class
//

#include "stdafx.h"
#include "GradientTextDemo.h"

#include "GradientTextDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoDoc

IMPLEMENT_DYNCREATE(CGradientTextDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CGradientTextDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CGradientTextDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoDoc construction/destruction

CGradientTextDemoDoc::CGradientTextDemoDoc()
{
	// TODO: add one-time construction code here

}

CGradientTextDemoDoc::~CGradientTextDemoDoc()
{
}

BOOL CGradientTextDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoDoc serialization

void CGradientTextDemoDoc::Serialize(CArchive& ar)
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
// CGradientTextDemoDoc diagnostics

#ifdef _DEBUG
void CGradientTextDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGradientTextDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGradientTextDemoDoc commands
