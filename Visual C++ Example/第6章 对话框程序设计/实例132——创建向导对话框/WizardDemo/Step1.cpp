// Step1.cpp : implementation file
//

#include "stdafx.h"
#include "WizardDemo.h"
#include "Step1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep1 property page

IMPLEMENT_DYNCREATE(CStep1, CPropertyPage)

CStep1::CStep1() : CPropertyPage(CStep1::IDD)
{
	//{{AFX_DATA_INIT(CStep1)
		// NOTE: the ClassWizardDemo will add member initialization here
	//}}AFX_DATA_INIT
}

CStep1::~CStep1()
{
}

void CStep1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStep1)
		// NOTE: the ClassWizardDemo will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStep1, CPropertyPage)
	//{{AFX_MSG_MAP(CStep1)
		// NOTE: the ClassWizardDemo will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep1 message handlers

BOOL CStep1::OnSetActive() 
{
	CPropertySheet* pParent=(CPropertySheet*)GetParent(); // 获得属性表的指针 
	pParent->SetWizardButtons(PSWIZB_NEXT); // 设置属性表的显示按钮只为下一步 
	SetDlgItemText(IDC_TEXT1,"这是向导的第一步"); 
	return CPropertyPage::OnSetActive();
}
