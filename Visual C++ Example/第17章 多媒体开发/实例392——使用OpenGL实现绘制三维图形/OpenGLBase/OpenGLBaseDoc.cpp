// OpenGLBaseDoc.cpp : implementation of the COpenGLBaseDoc class
//

#include "stdafx.h"
#include "OpenGLBase.h"

#include "OpenGLBaseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseDoc

IMPLEMENT_DYNCREATE(COpenGLBaseDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGLBaseDoc, CDocument)
	//{{AFX_MSG_MAP(COpenGLBaseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseDoc construction/destruction

COpenGLBaseDoc::COpenGLBaseDoc()
{
	// TODO: add one-time construction code here

}

COpenGLBaseDoc::~COpenGLBaseDoc()
{
}

BOOL COpenGLBaseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseDoc serialization

void COpenGLBaseDoc::Serialize(CArchive& ar)
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
// COpenGLBaseDoc diagnostics

#ifdef _DEBUG
void COpenGLBaseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGLBaseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseDoc commands
