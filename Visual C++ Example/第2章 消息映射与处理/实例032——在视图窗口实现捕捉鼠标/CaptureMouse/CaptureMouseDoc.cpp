// CaptureMouseDoc.cpp : implementation of the CCaptureMouseDoc class
//

#include "stdafx.h"
#include "CaptureMouse.h"

#include "CaptureMouseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaptureMouseDoc

IMPLEMENT_DYNCREATE(CCaptureMouseDoc, CDocument)

BEGIN_MESSAGE_MAP(CCaptureMouseDoc, CDocument)
	//{{AFX_MSG_MAP(CCaptureMouseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaptureMouseDoc construction/destruction

CCaptureMouseDoc::CCaptureMouseDoc()
{
	// TODO: add one-time construction code here

}

CCaptureMouseDoc::~CCaptureMouseDoc()
{
}

BOOL CCaptureMouseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCaptureMouseDoc serialization

void CCaptureMouseDoc::Serialize(CArchive& ar)
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
// CCaptureMouseDoc diagnostics

#ifdef _DEBUG
void CCaptureMouseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCaptureMouseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCaptureMouseDoc commands
