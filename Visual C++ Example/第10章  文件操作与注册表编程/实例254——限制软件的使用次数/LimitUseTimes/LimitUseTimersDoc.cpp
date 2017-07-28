// LimitUseTimersDoc.cpp : implementation of the CLimitUseTimersDoc class
//

#include "stdafx.h"
#include "LimitUseTimers.h"

#include "LimitUseTimersDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersDoc

IMPLEMENT_DYNCREATE(CLimitUseTimersDoc, CDocument)

BEGIN_MESSAGE_MAP(CLimitUseTimersDoc, CDocument)
	//{{AFX_MSG_MAP(CLimitUseTimersDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersDoc construction/destruction

CLimitUseTimersDoc::CLimitUseTimersDoc()
{
	// TODO: add one-time construction code here

}

CLimitUseTimersDoc::~CLimitUseTimersDoc()
{
}

BOOL CLimitUseTimersDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersDoc serialization

void CLimitUseTimersDoc::Serialize(CArchive& ar)
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
// CLimitUseTimersDoc diagnostics

#ifdef _DEBUG
void CLimitUseTimersDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLimitUseTimersDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLimitUseTimersDoc commands
