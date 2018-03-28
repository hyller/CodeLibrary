// ShapePage.cpp : implementation file
//

#include "stdafx.h"
#include "PropertySheetDemo.h"
#include "ShapePage.h"

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
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapePage message handlers
