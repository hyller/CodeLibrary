// HollowFontDemoDoc.cpp : implementation of the CHollowFontDemoDoc class
//

#include "stdafx.h"
#include "HollowFontDemo.h"

#include "HollowFontDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoDoc

IMPLEMENT_DYNCREATE(CHollowFontDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CHollowFontDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CHollowFontDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoDoc construction/destruction

CHollowFontDemoDoc::CHollowFontDemoDoc()
{
	// TODO: add one-time construction code here

}

CHollowFontDemoDoc::~CHollowFontDemoDoc()
{
}

BOOL CHollowFontDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoDoc serialization

void CHollowFontDemoDoc::Serialize(CArchive& ar)
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
// CHollowFontDemoDoc diagnostics

#ifdef _DEBUG
void CHollowFontDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHollowFontDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHollowFontDemoDoc commands
