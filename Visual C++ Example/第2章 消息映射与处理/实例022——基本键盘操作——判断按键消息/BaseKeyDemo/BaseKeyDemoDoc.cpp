// BaseKeyDemoDoc.cpp : implementation of the CBaseKeyDemoDoc class
//

#include "stdafx.h"
#include "BaseKeyDemo.h"

#include "BaseKeyDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoDoc

IMPLEMENT_DYNCREATE(CBaseKeyDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CBaseKeyDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CBaseKeyDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoDoc construction/destruction

CBaseKeyDemoDoc::CBaseKeyDemoDoc()
{
	// TODO: add one-time construction code here

}

CBaseKeyDemoDoc::~CBaseKeyDemoDoc()
{
}

BOOL CBaseKeyDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoDoc serialization

void CBaseKeyDemoDoc::Serialize(CArchive& ar)
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
// CBaseKeyDemoDoc diagnostics

#ifdef _DEBUG
void CBaseKeyDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseKeyDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseKeyDemoDoc commands
