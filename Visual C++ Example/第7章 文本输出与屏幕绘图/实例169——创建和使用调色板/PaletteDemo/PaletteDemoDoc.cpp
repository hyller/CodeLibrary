// PaletteDemoDoc.cpp : implementation of the CPaletteDemoDoc class
//

#include "stdafx.h"
#include "PaletteDemo.h"

#include "PaletteDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc

IMPLEMENT_DYNCREATE(CPaletteDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaletteDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CPaletteDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc construction/destruction

CPaletteDemoDoc::CPaletteDemoDoc()
{
	// TODO: add one-time construction code here

}

CPaletteDemoDoc::~CPaletteDemoDoc()
{
}

BOOL CPaletteDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc serialization

void CPaletteDemoDoc::Serialize(CArchive& ar)
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
// CPaletteDemoDoc diagnostics

#ifdef _DEBUG
void CPaletteDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaletteDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc commands
