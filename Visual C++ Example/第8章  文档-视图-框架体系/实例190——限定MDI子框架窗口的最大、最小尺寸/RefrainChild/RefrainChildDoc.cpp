// RefrainChildDoc.cpp : implementation of the CRefrainChildDoc class
//

#include "stdafx.h"
#include "RefrainChild.h"

#include "RefrainChildDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildDoc

IMPLEMENT_DYNCREATE(CRefrainChildDoc, CDocument)

BEGIN_MESSAGE_MAP(CRefrainChildDoc, CDocument)
	//{{AFX_MSG_MAP(CRefrainChildDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildDoc construction/destruction

CRefrainChildDoc::CRefrainChildDoc()
{
	// TODO: add one-time construction code here

}

CRefrainChildDoc::~CRefrainChildDoc()
{
}

BOOL CRefrainChildDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRefrainChildDoc serialization

void CRefrainChildDoc::Serialize(CArchive& ar)
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
// CRefrainChildDoc diagnostics

#ifdef _DEBUG
void CRefrainChildDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRefrainChildDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRefrainChildDoc commands
