// DlgDateExchangeDoc.cpp : implementation of the CDlgDateExchangeDoc class
//

#include "stdafx.h"
#include "DlgDateExchange.h"

#include "DlgDateExchangeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchangeDoc

IMPLEMENT_DYNCREATE(CDlgDateExchangeDoc, CDocument)

BEGIN_MESSAGE_MAP(CDlgDateExchangeDoc, CDocument)
	//{{AFX_MSG_MAP(CDlgDateExchangeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchangeDoc construction/destruction

CDlgDateExchangeDoc::CDlgDateExchangeDoc()
{
	// TODO: add one-time construction code here

}

CDlgDateExchangeDoc::~CDlgDateExchangeDoc()
{
}

BOOL CDlgDateExchangeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchangeDoc serialization

void CDlgDateExchangeDoc::Serialize(CArchive& ar)
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
// CDlgDateExchangeDoc diagnostics

#ifdef _DEBUG
void CDlgDateExchangeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDlgDateExchangeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgDateExchangeDoc commands
