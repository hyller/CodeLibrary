// ProgressbarStatusDoc.cpp : implementation of the CProgressbarStatusDoc class
//

#include "stdafx.h"
#include "ProgressbarStatus.h"

#include "ProgressbarStatusDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusDoc

IMPLEMENT_DYNCREATE(CProgressbarStatusDoc, CDocument)

BEGIN_MESSAGE_MAP(CProgressbarStatusDoc, CDocument)
	//{{AFX_MSG_MAP(CProgressbarStatusDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusDoc construction/destruction

CProgressbarStatusDoc::CProgressbarStatusDoc()
{
	// TODO: add one-time construction code here

}

CProgressbarStatusDoc::~CProgressbarStatusDoc()
{
}

BOOL CProgressbarStatusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusDoc serialization

void CProgressbarStatusDoc::Serialize(CArchive& ar)
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
// CProgressbarStatusDoc diagnostics

#ifdef _DEBUG
void CProgressbarStatusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProgressbarStatusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusDoc commands
