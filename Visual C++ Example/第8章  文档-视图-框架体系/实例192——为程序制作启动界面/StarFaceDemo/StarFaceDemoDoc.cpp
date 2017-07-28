// StarFaceDemoDoc.cpp : implementation of the CStarFaceDemoDoc class
//

#include "stdafx.h"
#include "StarFaceDemo.h"

#include "StarFaceDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoDoc

IMPLEMENT_DYNCREATE(CStarFaceDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CStarFaceDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CStarFaceDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoDoc construction/destruction

CStarFaceDemoDoc::CStarFaceDemoDoc()
{
	// TODO: add one-time construction code here

}

CStarFaceDemoDoc::~CStarFaceDemoDoc()
{
}

BOOL CStarFaceDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoDoc serialization

void CStarFaceDemoDoc::Serialize(CArchive& ar)
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
// CStarFaceDemoDoc diagnostics

#ifdef _DEBUG
void CStarFaceDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStarFaceDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoDoc commands
