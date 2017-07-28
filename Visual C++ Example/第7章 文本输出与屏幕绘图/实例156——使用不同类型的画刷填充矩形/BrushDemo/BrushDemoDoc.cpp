// BrushDemoDoc.cpp : implementation of the CBrushDemoDoc class
//

#include "stdafx.h"
#include "BrushDemo.h"

#include "BrushDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoDoc

IMPLEMENT_DYNCREATE(CBrushDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CBrushDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CBrushDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoDoc construction/destruction

CBrushDemoDoc::CBrushDemoDoc()
{
	// TODO: add one-time construction code here

}

CBrushDemoDoc::~CBrushDemoDoc()
{
}

BOOL CBrushDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBrushDemoDoc serialization

void CBrushDemoDoc::Serialize(CArchive& ar)
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
// CBrushDemoDoc diagnostics

#ifdef _DEBUG
void CBrushDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBrushDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBrushDemoDoc commands
