// UIThreadDemoDoc.cpp : implementation of the CUIThreadDemoDoc class
//

#include "stdafx.h"
#include "UIThreadDemo.h"

#include "UIThreadDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIThreadDemoDoc

IMPLEMENT_DYNCREATE(CUIThreadDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CUIThreadDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CUIThreadDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIThreadDemoDoc construction/destruction

CUIThreadDemoDoc::CUIThreadDemoDoc()
{
	// TODO: add one-time construction code here

}

CUIThreadDemoDoc::~CUIThreadDemoDoc()
{
}

BOOL CUIThreadDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUIThreadDemoDoc serialization

void CUIThreadDemoDoc::Serialize(CArchive& ar)
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
// CUIThreadDemoDoc diagnostics

#ifdef _DEBUG
void CUIThreadDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUIThreadDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUIThreadDemoDoc commands
