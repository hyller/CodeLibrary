// ShapePage.cpp : implementation file
//

#include "stdafx.h"
#include "PropertySheetDemo2.h"
#include "ShapePage.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapePage property page

IMPLEMENT_DYNCREATE(CShapePage, CPropertyPage)

CShapePage::CShapePage() : CPropertyPage(CShapePage::IDD)
{
	//{{AFX_DATA_INIT(CShapePage)
	m_radio = -1;
	//}}AFX_DATA_INIT
}

CShapePage::~CShapePage()
{
}

void CShapePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShapePage)
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShapePage, CPropertyPage)
	//{{AFX_MSG_MAP(CShapePage)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapePage message handlers

BOOL CShapePage::OnApply() 
{
	// TODO: Add your specialized code here and/or call the base class
	CMainFrame* pMFrm=(CMainFrame*)AfxGetMainWnd();
	//向视图类发送用户自定义消息
	pMFrm->GetActiveView()->SendMessage(WM_USER_APPLY);
	return CPropertyPage::OnApply();
}

void CShapePage::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	SetModified();//激活应用按钮
}
void CShapePage::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	SetModified();//激活应用按钮
}
