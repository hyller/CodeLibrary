// RestoreWinPosDoc.cpp : implementation of the CRestoreWinPosDoc class
//

#include "stdafx.h"
#include "RestoreWinPos.h"

#include "RestoreWinPosDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosDoc

IMPLEMENT_DYNCREATE(CRestoreWinPosDoc, CDocument)

BEGIN_MESSAGE_MAP(CRestoreWinPosDoc, CDocument)
	//{{AFX_MSG_MAP(CRestoreWinPosDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosDoc construction/destruction

CRestoreWinPosDoc::CRestoreWinPosDoc()
{
	// TODO: add one-time construction code here

}

CRestoreWinPosDoc::~CRestoreWinPosDoc()
{
}

BOOL CRestoreWinPosDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosDoc serialization

void CRestoreWinPosDoc::Serialize(CArchive& ar)
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
// CRestoreWinPosDoc diagnostics

#ifdef _DEBUG
void CRestoreWinPosDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRestoreWinPosDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosDoc commands
