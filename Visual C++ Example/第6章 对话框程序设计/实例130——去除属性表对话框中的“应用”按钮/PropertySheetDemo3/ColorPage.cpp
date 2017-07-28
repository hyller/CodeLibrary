// ColorPage.cpp : implementation file
//

#include "stdafx.h"
#include "PropertySheetDemo3.h"
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
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorPage message handlers
