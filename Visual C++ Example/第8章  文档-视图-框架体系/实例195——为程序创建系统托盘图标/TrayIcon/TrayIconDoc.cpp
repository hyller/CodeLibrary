// TrayIconDoc.cpp : implementation of the CTrayIconDoc class
//

#include "stdafx.h"
#include "TrayIcon.h"

#include "TrayIconDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrayIconDoc

IMPLEMENT_DYNCREATE(CTrayIconDoc, CDocument)

BEGIN_MESSAGE_MAP(CTrayIconDoc, CDocument)
	//{{AFX_MSG_MAP(CTrayIconDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrayIconDoc construction/destruction

CTrayIconDoc::CTrayIconDoc()
{
	// TODO: add one-time construction code here

}

CTrayIconDoc::~CTrayIconDoc()
{
}

BOOL CTrayIconDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTrayIconDoc serialization

void CTrayIconDoc::Serialize(CArchive& ar)
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
// CTrayIconDoc diagnostics

#ifdef _DEBUG
void CTrayIconDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTrayIconDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrayIconDoc commands
