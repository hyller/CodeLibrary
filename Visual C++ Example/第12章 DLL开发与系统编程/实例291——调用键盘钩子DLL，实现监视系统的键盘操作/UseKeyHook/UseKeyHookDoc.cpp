// UseKeyHookDoc.cpp : implementation of the CUseKeyHookDoc class
//

#include "stdafx.h"
#include "UseKeyHook.h"

#include "UseKeyHookDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookDoc

IMPLEMENT_DYNCREATE(CUseKeyHookDoc, CDocument)

BEGIN_MESSAGE_MAP(CUseKeyHookDoc, CDocument)
	//{{AFX_MSG_MAP(CUseKeyHookDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookDoc construction/destruction

CUseKeyHookDoc::CUseKeyHookDoc()
{
	// TODO: add one-time construction code here

}

CUseKeyHookDoc::~CUseKeyHookDoc()
{
}

BOOL CUseKeyHookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookDoc serialization

void CUseKeyHookDoc::Serialize(CArchive& ar)
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
// CUseKeyHookDoc diagnostics

#ifdef _DEBUG
void CUseKeyHookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUseKeyHookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseKeyHookDoc commands
