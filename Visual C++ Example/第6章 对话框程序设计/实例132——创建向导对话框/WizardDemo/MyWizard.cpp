// MyWizard.cpp : implementation file
//

#include "stdafx.h"
#include "WizardDemo.h"
#include "MyWizard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyWizard

IMPLEMENT_DYNAMIC(CMyWizard, CPropertySheet)

CMyWizard::CMyWizard(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CMyWizard::CMyWizard(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&MyStep1); //添加属性页1 
	AddPage(&MyStep2); //添加属性页2 	
	AddPage(&MyStep3); //添加属性页3 
}

CMyWizard::~CMyWizard()
{
}


BEGIN_MESSAGE_MAP(CMyWizard, CPropertySheet)
	//{{AFX_MSG_MAP(CMyWizard)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWizard message handlers
