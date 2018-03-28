// TimerDemoDoc.cpp : implementation of the CTimerDemoDoc class
//

#include "stdafx.h"
#include "TimerDemo.h"

#include "TimerDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoDoc

IMPLEMENT_DYNCREATE(CTimerDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTimerDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CTimerDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoDoc construction/destruction

CTimerDemoDoc::CTimerDemoDoc()
{
	// TODO: add one-time construction code here

}

CTimerDemoDoc::~CTimerDemoDoc()
{
}

BOOL CTimerDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTimerDemoDoc serialization

void CTimerDemoDoc::Serialize(CArchive& ar)
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
// CTimerDemoDoc diagnostics

#ifdef _DEBUG
void CTimerDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTimerDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTimerDemoDoc commands
