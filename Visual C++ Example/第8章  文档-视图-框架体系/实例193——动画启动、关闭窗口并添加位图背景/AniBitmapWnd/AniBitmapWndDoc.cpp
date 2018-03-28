// AniBitmapWndDoc.cpp : implementation of the CAniBitmapWndDoc class
//

#include "stdafx.h"
#include "AniBitmapWnd.h"

#include "AniBitmapWndDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAniBitmapWndDoc

IMPLEMENT_DYNCREATE(CAniBitmapWndDoc, CDocument)

BEGIN_MESSAGE_MAP(CAniBitmapWndDoc, CDocument)
	//{{AFX_MSG_MAP(CAniBitmapWndDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAniBitmapWndDoc construction/destruction

CAniBitmapWndDoc::CAniBitmapWndDoc()
{
	// TODO: add one-time construction code here

}

CAniBitmapWndDoc::~CAniBitmapWndDoc()
{
}

BOOL CAniBitmapWndDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAniBitmapWndDoc serialization

void CAniBitmapWndDoc::Serialize(CArchive& ar)
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
// CAniBitmapWndDoc diagnostics

#ifdef _DEBUG
void CAniBitmapWndDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAniBitmapWndDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAniBitmapWndDoc commands
