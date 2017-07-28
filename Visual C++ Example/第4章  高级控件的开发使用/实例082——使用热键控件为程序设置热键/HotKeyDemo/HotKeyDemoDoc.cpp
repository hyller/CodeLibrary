// HotKeyDemoDoc.cpp : implementation of the CHotKeyDemoDoc class
//

#include "stdafx.h"
#include "HotKeyDemo.h"

#include "HotKeyDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoDoc

IMPLEMENT_DYNCREATE(CHotKeyDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CHotKeyDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CHotKeyDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoDoc construction/destruction

CHotKeyDemoDoc::CHotKeyDemoDoc()
{
	// TODO: add one-time construction code here

}

CHotKeyDemoDoc::~CHotKeyDemoDoc()
{
}

BOOL CHotKeyDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoDoc serialization

void CHotKeyDemoDoc::Serialize(CArchive& ar)
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
// CHotKeyDemoDoc diagnostics

#ifdef _DEBUG
void CHotKeyDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHotKeyDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHotKeyDemoDoc commands
