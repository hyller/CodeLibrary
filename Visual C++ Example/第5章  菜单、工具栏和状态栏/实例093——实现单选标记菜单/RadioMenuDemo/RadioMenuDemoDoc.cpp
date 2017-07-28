// RadioMenuDemoDoc.cpp : implementation of the CRadioMenuDemoDoc class
//

#include "stdafx.h"
#include "RadioMenuDemo.h"

#include "RadioMenuDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoDoc

IMPLEMENT_DYNCREATE(CRadioMenuDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CRadioMenuDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CRadioMenuDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoDoc construction/destruction

CRadioMenuDemoDoc::CRadioMenuDemoDoc()
{
	// TODO: add one-time construction code here

}

CRadioMenuDemoDoc::~CRadioMenuDemoDoc()
{
}

BOOL CRadioMenuDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoDoc serialization

void CRadioMenuDemoDoc::Serialize(CArchive& ar)
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
// CRadioMenuDemoDoc diagnostics

#ifdef _DEBUG
void CRadioMenuDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRadioMenuDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRadioMenuDemoDoc commands
