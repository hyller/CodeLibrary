// CMDDialogBarDoc.cpp : implementation of the CCMDDialogBarDoc class
//

#include "stdafx.h"
#include "CMDDialogBar.h"

#include "CMDDialogBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarDoc

IMPLEMENT_DYNCREATE(CCMDDialogBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CCMDDialogBarDoc, CDocument)
	//{{AFX_MSG_MAP(CCMDDialogBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarDoc construction/destruction

CCMDDialogBarDoc::CCMDDialogBarDoc()
{
	// TODO: add one-time construction code here

}

CCMDDialogBarDoc::~CCMDDialogBarDoc()
{
}

BOOL CCMDDialogBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarDoc serialization

void CCMDDialogBarDoc::Serialize(CArchive& ar)
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
// CCMDDialogBarDoc diagnostics

#ifdef _DEBUG
void CCMDDialogBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCMDDialogBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCMDDialogBarDoc commands
