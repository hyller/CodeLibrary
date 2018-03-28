// DlgDocFrameDoc.cpp : implementation of the CDlgDocFrameDoc class
//

#include "stdafx.h"
#include "DlgDocFrame.h"

#include "DlgDocFrameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameDoc

IMPLEMENT_DYNCREATE(CDlgDocFrameDoc, CDocument)

BEGIN_MESSAGE_MAP(CDlgDocFrameDoc, CDocument)
	//{{AFX_MSG_MAP(CDlgDocFrameDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameDoc construction/destruction

CDlgDocFrameDoc::CDlgDocFrameDoc()
{
	// TODO: add one-time construction code here

}

CDlgDocFrameDoc::~CDlgDocFrameDoc()
{
}

BOOL CDlgDocFrameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	m_nPointCount=0;			//新建时点为0
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameDoc serialization

void CDlgDocFrameDoc::Serialize(CArchive& ar)
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
// CDlgDocFrameDoc diagnostics

#ifdef _DEBUG
void CDlgDocFrameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDlgDocFrameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameDoc commands
