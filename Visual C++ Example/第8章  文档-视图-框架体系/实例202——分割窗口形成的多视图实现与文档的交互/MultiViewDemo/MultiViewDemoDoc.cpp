// MultiViewDemoDoc.cpp : implementation of the CMultiViewDemoDoc class
//

#include "stdafx.h"
#include "MultiViewDemo.h"

#include "MultiViewDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoDoc

IMPLEMENT_DYNCREATE(CMultiViewDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMultiViewDemoDoc, CDocument)
	//{{AFX_MSG_MAP(CMultiViewDemoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoDoc construction/destruction

CMultiViewDemoDoc::CMultiViewDemoDoc()
{
	// TODO: add one-time construction code here
	add=false;
}

CMultiViewDemoDoc::~CMultiViewDemoDoc()
{
}

BOOL CMultiViewDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoDoc serialization

void CMultiViewDemoDoc::Serialize(CArchive& ar)
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
// CMultiViewDemoDoc diagnostics

#ifdef _DEBUG
void CMultiViewDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMultiViewDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiViewDemoDoc commands
