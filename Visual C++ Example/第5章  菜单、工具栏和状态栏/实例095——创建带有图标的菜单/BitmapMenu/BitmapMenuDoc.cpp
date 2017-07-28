// BitmapMenuDoc.cpp : implementation of the CBitmapMenuDoc class
//

#include "stdafx.h"
#include "BitmapMenu.h"

#include "BitmapMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuDoc

IMPLEMENT_DYNCREATE(CBitmapMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CBitmapMenuDoc, CDocument)
	//{{AFX_MSG_MAP(CBitmapMenuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuDoc construction/destruction

CBitmapMenuDoc::CBitmapMenuDoc()
{
	// TODO: add one-time construction code here

}

CBitmapMenuDoc::~CBitmapMenuDoc()
{
}

BOOL CBitmapMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuDoc serialization

void CBitmapMenuDoc::Serialize(CArchive& ar)
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
// CBitmapMenuDoc diagnostics

#ifdef _DEBUG
void CBitmapMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBitmapMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuDoc commands
