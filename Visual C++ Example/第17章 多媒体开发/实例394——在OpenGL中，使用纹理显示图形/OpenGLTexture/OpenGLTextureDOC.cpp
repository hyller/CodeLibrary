// OpenGLTextureDoc.cpp : implementation of the COpenGLTextureDoc class
//

#include "stdafx.h"
#include "OpenGLTexture.h"

#include "OpenGLTextureDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureDoc

IMPLEMENT_DYNCREATE(COpenGLTextureDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGLTextureDoc, CDocument)
	//{{AFX_MSG_MAP(COpenGLTextureDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureDoc construction/destruction

COpenGLTextureDoc::COpenGLTextureDoc()
{
	// TODO: add one-time construction code here

}

COpenGLTextureDoc::~COpenGLTextureDoc()
{
}

BOOL COpenGLTextureDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureDoc serialization

void COpenGLTextureDoc::Serialize(CArchive& ar)
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
// COpenGLTextureDoc diagnostics

#ifdef _DEBUG
void COpenGLTextureDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGLTextureDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureDoc commands
