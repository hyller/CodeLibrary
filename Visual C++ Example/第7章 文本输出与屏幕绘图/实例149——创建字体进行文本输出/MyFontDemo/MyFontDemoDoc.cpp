// MyFontDemoDoc.cpp : implementation of the CMyFontDemoDoc class
//

#include "stdafx.h"
#include "MyFontDemo.h"

#include "MyFontDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoDoc

IMPLEMENT_DYNCREATE(CMyFontDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyFontDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CMyFontDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoDoc construction/destruction

CMyFontDemoDoc::CMyFontDemoDoc()
{
	// TODO: add one-time construction code here

}

CMyFontDemoDoc::~CMyFontDemoDoc()
{
}

BOOL CMyFontDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoDoc serialization

void CMyFontDemoDoc::Serialize(CArchive& ar)
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
// CMyFontDemoDoc diagnostics

#ifdef _DEBUG
void CMyFontDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyFontDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyFontDemoDoc commands
