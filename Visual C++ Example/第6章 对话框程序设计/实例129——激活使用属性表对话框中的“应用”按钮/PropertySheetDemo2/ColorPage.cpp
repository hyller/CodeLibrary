// ColorPage.cpp : implementation file
//

#include "stdafx.h"
#include "PropertySheetDemo2.h"
#include "ColorPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorPage property page

IMPLEMENT_DYNCREATE(CColorPage, CPropertyPage)

CColorPage::CColorPage() : CPropertyPage(CColorPage::IDD)
{
	//{{AFX_DATA_INIT(CColorPage)
	m_r = 0;
	m_g = 0;
	m_b = 0;
	//}}AFX_DATA_INIT
}

CColorPage::~CColorPage()
{
}

void CColorPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorPage)
	DDX_Text(pDX, IDC_EDIT1, m_r);
	DDV_MinMaxInt(pDX, m_r, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_g);
	DDV_MinMaxInt(pDX, m_g, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_b);
	DDV_MinMaxInt(pDX, m_b, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColorPage, CPropertyPage)
	//{{AFX_MSG_MAP(CColorPage)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorPage message handlers

void CColorPage::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
		SetModified();//激活应用按钮
}

void CColorPage::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
		SetModified();//激活应用按钮
}

void CColorPage::OnChangeEdit3() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
		SetModified();//激活应用按钮
}
