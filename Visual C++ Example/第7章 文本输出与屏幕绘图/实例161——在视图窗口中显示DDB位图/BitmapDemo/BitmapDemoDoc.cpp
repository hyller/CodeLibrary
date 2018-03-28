// BitmapDemoDoc.cpp : implementation of the CBitmapDemoDoc class
//

#include "stdafx.h"
#include "BitmapDemo.h"

#include "BitmapDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapDemoDoc

IMPLEMENT_DYNCREATE(CBitmapDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CBitmapDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CBitmapDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmapDemoDoc construction/destruction

CBitmapDemoDoc::CBitmapDemoDoc()
{
	// TODO: add one-time construction code here

}

CBitmapDemoDoc::~CBitmapDemoDoc()
{
}

BOOL CBitmapDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBitmapDemoDoc serialization

void CBitmapDemoDoc::Serialize(CArchive& ar)
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
// CBitmapDemoDoc diagnostics

#ifdef _DEBUG
void CBitmapDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBitmapDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBitmapDemoDoc commands
