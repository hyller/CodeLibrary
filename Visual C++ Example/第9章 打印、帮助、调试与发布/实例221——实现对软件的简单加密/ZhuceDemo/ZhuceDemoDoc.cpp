// ZhuceDemoDoc.cpp : implementation of the CZhuceDemoDoc class
//

#include "stdafx.h"
#include "ZhuceDemo.h"

#include "ZhuceDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoDoc

IMPLEMENT_DYNCREATE(CZhuceDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CZhuceDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CZhuceDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoDoc construction/destruction

CZhuceDemoDoc::CZhuceDemoDoc()
{
	// TODO: add one-time construction code here

}

CZhuceDemoDoc::~CZhuceDemoDoc()
{
}

BOOL CZhuceDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoDoc serialization

void CZhuceDemoDoc::Serialize(CArchive& ar)
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
// CZhuceDemoDoc diagnostics

#ifdef _DEBUG
void CZhuceDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CZhuceDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CZhuceDemoDoc commands
