// MedicAdminDoc.cpp : implementation of the CMedicAdminDoc class
//

#include "stdafx.h"
#include "MedicAdmin.h"

#include "MedicAdminDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminDoc

IMPLEMENT_DYNCREATE(CMedicAdminDoc, CDocument)

BEGIN_MESSAGE_MAP(CMedicAdminDoc, CDocument)
	//{{AFX_MSG_MAP(CMedicAdminDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminDoc construction/destruction

CMedicAdminDoc::CMedicAdminDoc()
{
	// TODO: add one-time construction code here

}

CMedicAdminDoc::~CMedicAdminDoc()
{
}

BOOL CMedicAdminDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMedicAdminDoc serialization

void CMedicAdminDoc::Serialize(CArchive& ar)
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
// CMedicAdminDoc diagnostics

#ifdef _DEBUG
void CMedicAdminDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMedicAdminDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminDoc commands

/*BOOL CMedicAdminDoc::SetData()
{
	userHeader[0] = _T("医生");
	userHeader[1] = _T("售药员");
	userHeader[2] = _T("管理员");
	return TRUE;
}*/

void CMedicAdminDoc::SetTitle(LPCTSTR lpszTitle) 
{
	// TODO: Add your specialized code here and/or call the base class
	lpszTitle="药品管理系统";
	CDocument::SetTitle(lpszTitle);
}
