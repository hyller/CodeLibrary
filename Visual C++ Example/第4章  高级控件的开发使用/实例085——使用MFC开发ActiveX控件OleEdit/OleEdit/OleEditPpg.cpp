// OleEditPpg.cpp : Implementation of the COleEditPropPage property page class.

#include "stdafx.h"
#include "OleEdit.h"
#include "OleEditPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COleEditPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COleEditPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(COleEditPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COleEditPropPage, "OLEEDIT.OleEditPropPage.1",
	0x1703c752, 0xf2f8, 0x4c13, 0xac, 0xa8, 0xd3, 0x7d, 0x53, 0x5a, 0x11, 0xf6)


/////////////////////////////////////////////////////////////////////////////
// COleEditPropPage::COleEditPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for COleEditPropPage

BOOL COleEditPropPage::COleEditPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_OLEEDIT_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// COleEditPropPage::COleEditPropPage - Constructor

COleEditPropPage::COleEditPropPage() :
	COlePropertyPage(IDD, IDS_OLEEDIT_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(COleEditPropPage)
	m_bText = FALSE;
	m_bNumbers = FALSE;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// COleEditPropPage::DoDataExchange - Moves data between page and properties

void COleEditPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(COleEditPropPage)
	DDP_Check(pDX, IDC_CHECK_CHAR, m_bText, _T("bText") );
	DDX_Check(pDX, IDC_CHECK_CHAR, m_bText);
	DDP_Check(pDX, IDC_CHECK_NUMBER, m_bNumbers, _T("bNumbers") );
	DDX_Check(pDX, IDC_CHECK_NUMBER, m_bNumbers);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// COleEditPropPage message handlers
