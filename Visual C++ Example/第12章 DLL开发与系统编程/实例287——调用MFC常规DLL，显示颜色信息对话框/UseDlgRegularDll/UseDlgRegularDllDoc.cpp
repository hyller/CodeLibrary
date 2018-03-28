// UseDlgRegularDllDoc.cpp : implementation of the CUseDlgRegularDllDoc class
//

#include "stdafx.h"
#include "UseDlgRegularDll.h"

#include "UseDlgRegularDllDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseDlgRegularDllDoc

IMPLEMENT_DYNCREATE(CUseDlgRegularDllDoc, CDocument)

BEGIN_MESSAGE_MAP(CUseDlgRegularDllDoc, CDocument)
	//{{AFX_MSG_MAP(CUseDlgRegularDllDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseDlgRegularDllDoc construction/destruction

CUseDlgRegularDllDoc::CUseDlgRegularDllDoc()
{
	// TODO: add one-time construction code here

}

CUseDlgRegularDllDoc::~CUseDlgRegularDllDoc()
{
}

BOOL CUseDlgRegularDllDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUseDlgRegularDllDoc serialization

void CUseDlgRegularDllDoc::Serialize(CArchive& ar)
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
// CUseDlgRegularDllDoc diagnostics

#ifdef _DEBUG
void CUseDlgRegularDllDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUseDlgRegularDllDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseDlgRegularDllDoc commands
