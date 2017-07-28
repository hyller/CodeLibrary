// Step2.cpp : implementation file
//

#include "stdafx.h"
#include "WizardDemo.h"
#include "Step2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep2 property page

IMPLEMENT_DYNCREATE(CStep2, CPropertyPage)

CStep2::CStep2() : CPropertyPage(CStep2::IDD)
{
	//{{AFX_DATA_INIT(CStep2)
		// NOTE: the ClassWizardDemo will add member initialization here
	//}}AFX_DATA_INIT
}

CStep2::~CStep2()
{
}

void CStep2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStep2)
		// NOTE: the ClassWizardDemo will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStep2, CPropertyPage)
	//{{AFX_MSG_MAP(CStep2)
		// NOTE: the ClassWizardDemo will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep2 message handlers

BOOL CStep2::OnSetActive() 
{
	CPropertySheet* pParent=(CPropertySheet*)GetParent(); 	
	pParent->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK); 	
	SetDlgItemText(IDC_TEXT2,"这是向导的第二步"); 
	return CPropertyPage::OnSetActive();
}
