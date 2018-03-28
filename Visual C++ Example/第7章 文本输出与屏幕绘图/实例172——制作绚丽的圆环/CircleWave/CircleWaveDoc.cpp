// CircleWaveDoc.cpp : implementation of the CCircleWaveDoc class
//

#include "stdafx.h"
#include "CircleWave.h"

#include "CircleWaveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveDoc

IMPLEMENT_DYNCREATE(CCircleWaveDoc, CDocument)

BEGIN_MESSAGE_MAP(CCircleWaveDoc, CDocument)
	//{{AFX_MSG_MAP(CCircleWaveDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveDoc construction/destruction

CCircleWaveDoc::CCircleWaveDoc()
{
	// TODO: add one-time construction code here

}

CCircleWaveDoc::~CCircleWaveDoc()
{
}

BOOL CCircleWaveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCircleWaveDoc serialization

void CCircleWaveDoc::Serialize(CArchive& ar)
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
// CCircleWaveDoc diagnostics

#ifdef _DEBUG
void CCircleWaveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCircleWaveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCircleWaveDoc commands
