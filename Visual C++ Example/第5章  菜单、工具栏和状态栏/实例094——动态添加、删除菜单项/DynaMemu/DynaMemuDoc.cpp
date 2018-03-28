// DynaMemuDoc.cpp : implementation of the CDynaMemuDoc class
//

#include "stdafx.h"
#include "DynaMemu.h"

#include "DynaMemuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuDoc

IMPLEMENT_DYNCREATE(CDynaMemuDoc, CDocument)

BEGIN_MESSAGE_MAP(CDynaMemuDoc, CDocument)
	//{{AFX_MSG_MAP(CDynaMemuDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuDoc construction/destruction

CDynaMemuDoc::CDynaMemuDoc()
{
	// TODO: add one-time construction code here

}

CDynaMemuDoc::~CDynaMemuDoc()
{
}

BOOL CDynaMemuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynaMemuDoc serialization

void CDynaMemuDoc::Serialize(CArchive& ar)
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
// CDynaMemuDoc diagnostics

#ifdef _DEBUG
void CDynaMemuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynaMemuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuDoc commands
