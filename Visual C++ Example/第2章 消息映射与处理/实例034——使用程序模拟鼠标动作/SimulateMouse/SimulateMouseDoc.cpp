// SimulateMouseDoc.cpp : implementation of the CSimulateMouseDoc class
//

#include "stdafx.h"
#include "SimulateMouse.h"

#include "SimulateMouseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseDoc

IMPLEMENT_DYNCREATE(CSimulateMouseDoc, CDocument)

BEGIN_MESSAGE_MAP(CSimulateMouseDoc, CDocument)
	//{{AFX_MSG_MAP(CSimulateMouseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseDoc construction/destruction

CSimulateMouseDoc::CSimulateMouseDoc()
{
	// TODO: add one-time construction code here

}

CSimulateMouseDoc::~CSimulateMouseDoc()
{
}

BOOL CSimulateMouseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseDoc serialization

void CSimulateMouseDoc::Serialize(CArchive& ar)
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
// CSimulateMouseDoc diagnostics

#ifdef _DEBUG
void CSimulateMouseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSimulateMouseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSimulateMouseDoc commands
