// DlgDateExchange2Doc.cpp : implementation of the CDlgDateExchange2Doc class
//

#include "stdafx.h"
#include "DlgDateExchange2.h"

#include "DlgDateExchange2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2Doc

IMPLEMENT_DYNCREATE(CDlgDateExchange2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDlgDateExchange2Doc, CDocument)
	//{{AFX_MSG_MAP(CDlgDateExchange2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2Doc construction/destruction

CDlgDateExchange2Doc::CDlgDateExchange2Doc()
{
	// TODO: add one-time construction code here

}

CDlgDateExchange2Doc::~CDlgDateExchange2Doc()
{
}

BOOL CDlgDateExchange2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2Doc serialization

void CDlgDateExchange2Doc::Serialize(CArchive& ar)
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
// CDlgDateExchange2Doc diagnostics

#ifdef _DEBUG
void CDlgDateExchange2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDlgDateExchange2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchange2Doc commands
