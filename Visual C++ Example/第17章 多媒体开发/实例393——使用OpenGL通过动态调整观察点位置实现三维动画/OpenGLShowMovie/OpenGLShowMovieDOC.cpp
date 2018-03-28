// OpenGLShowMovieDoc.cpp : implementation of the COpenGLShowMovieDoc class
//

#include "stdafx.h"
#include "OpenGLShowMovie.h"

#include "OpenGLShowMovieDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGLShowMovieDoc

IMPLEMENT_DYNCREATE(COpenGLShowMovieDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGLShowMovieDoc, CDocument)
	//{{AFX_MSG_MAP(COpenGLShowMovieDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLShowMovieDoc construction/destruction

COpenGLShowMovieDoc::COpenGLShowMovieDoc()
{
	// TODO: add one-time construction code here

}

COpenGLShowMovieDoc::~COpenGLShowMovieDoc()
{
}

BOOL COpenGLShowMovieDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COpenGLShowMovieDoc serialization

void COpenGLShowMovieDoc::Serialize(CArchive& ar)
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
// COpenGLShowMovieDoc diagnostics

#ifdef _DEBUG
void COpenGLShowMovieDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGLShowMovieDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLShowMovieDoc commands
