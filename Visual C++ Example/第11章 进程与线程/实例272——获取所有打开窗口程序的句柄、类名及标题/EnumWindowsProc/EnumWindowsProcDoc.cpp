// EnumWindowsProcDoc.cpp : implementation of the CEnumWindowsProcDoc class
//

#include "stdafx.h"
#include "EnumWindowsProc.h"

#include "EnumWindowsProcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcDoc

IMPLEMENT_DYNCREATE(CEnumWindowsProcDoc, CDocument)

BEGIN_MESSAGE_MAP(CEnumWindowsProcDoc, CDocument)
	//{{AFX_MSG_MAP(CEnumWindowsProcDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcDoc construction/destruction

CEnumWindowsProcDoc::CEnumWindowsProcDoc()
{
	// TODO: add one-time construction code here

}

CEnumWindowsProcDoc::~CEnumWindowsProcDoc()
{
}

BOOL CEnumWindowsProcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcDoc serialization

void CEnumWindowsProcDoc::Serialize(CArchive& ar)
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
// CEnumWindowsProcDoc diagnostics

#ifdef _DEBUG
void CEnumWindowsProcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEnumWindowsProcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEnumWindowsProcDoc commands
