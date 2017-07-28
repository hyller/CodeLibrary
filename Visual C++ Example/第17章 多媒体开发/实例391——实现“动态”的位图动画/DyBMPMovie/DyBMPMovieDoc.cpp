// DyBMPMovieDoc.cpp : implementation of the CDyBMPMovieDoc class
//

#include "stdafx.h"
#include "DyBMPMovie.h"

#include "DyBMPMovieDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieDoc

IMPLEMENT_DYNCREATE(CDyBMPMovieDoc, CDocument)

BEGIN_MESSAGE_MAP(CDyBMPMovieDoc, CDocument)
	//{{AFX_MSG_MAP(CDyBMPMovieDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieDoc construction/destruction

CDyBMPMovieDoc::CDyBMPMovieDoc()
{
	// TODO: add one-time construction code here

}

CDyBMPMovieDoc::~CDyBMPMovieDoc()
{
}

BOOL CDyBMPMovieDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieDoc serialization

void CDyBMPMovieDoc::Serialize(CArchive& ar)
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
// CDyBMPMovieDoc diagnostics

#ifdef _DEBUG
void CDyBMPMovieDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDyBMPMovieDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDyBMPMovieDoc commands
