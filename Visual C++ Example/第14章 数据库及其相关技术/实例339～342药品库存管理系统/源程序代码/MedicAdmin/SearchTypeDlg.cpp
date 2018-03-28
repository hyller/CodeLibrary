// SearchTypeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SearchTypeDlg.h"
#include "MedicSearch.h"
#include "MedicAdminDoc.h"
#include "MedicListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchTypeDlg dialog


CSearchTypeDlg::CSearchTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchTypeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchTypeDlg)
	m_type = _T("");
	//}}AFX_DATA_INIT
}


void CSearchTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchTypeDlg)
	DDX_Text(pDX, IDC_TYPE_EDIT, m_type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchTypeDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchTypeDlg)
	ON_BN_CLICKED(ID_SEARCH_TYPE, OnSearchType)
	ON_BN_CLICKED(ID_SEARCH_TYPE_EXIT, OnSearchTypeExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchTypeDlg message handlers

void CSearchTypeDlg::OnSearchType() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_type=="")
	{
		AfxMessageBox("请输入要查询的药品类别");
		return;
	}
	CMedicSearch medicSearch;
	CFrameWnd* pWnd=(CFrameWnd*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)pWnd->GetActiveDocument();
	CMedicSet* theMedicSet=&pDoc->theMedicSet;
	POSITION pos=pDoc->GetFirstViewPosition();
	while(pos != NULL)
	{
		CView* pView=pDoc->GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			CListCtrl* theListCtrl=((CMedicListView*)pView)->theListCtrl;
			medicSearch.SetListCtrl(theListCtrl);
			medicSearch.SetMedicSet(theMedicSet);
			medicSearch.Search(m_type,2);
		}
	}
	CDialog::OnOK();
}

void CSearchTypeDlg::OnSearchTypeExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
