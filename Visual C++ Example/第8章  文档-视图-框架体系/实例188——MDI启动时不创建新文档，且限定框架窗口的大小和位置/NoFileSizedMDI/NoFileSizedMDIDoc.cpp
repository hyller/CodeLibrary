// NoFileSizedMDIDoc.cpp : implementation of the CNoFileSizedMDIDoc class
//

#include "stdafx.h"
#include "NoFileSizedMDI.h"

#include "NoFileSizedMDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIDoc

IMPLEMENT_DYNCREATE(CNoFileSizedMDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CNoFileSizedMDIDoc, CDocument)
	//{{AFX_MSG_MAP(CNoFileSizedMDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIDoc construction/destruction

CNoFileSizedMDIDoc::CNoFileSizedMDIDoc()
{
	// TODO: add one-time construction code here

}

CNoFileSizedMDIDoc::~CNoFileSizedMDIDoc()
{
}

BOOL CNoFileSizedMDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIDoc serialization

void CNoFileSizedMDIDoc::Serialize(CArchive& ar)
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
// CNoFileSizedMDIDoc diagnostics

#ifdef _DEBUG
void CNoFileSizedMDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNoFileSizedMDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIDoc commands
