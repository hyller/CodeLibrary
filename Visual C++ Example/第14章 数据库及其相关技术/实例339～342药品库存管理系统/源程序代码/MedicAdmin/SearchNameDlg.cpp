// SearchNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SearchNameDlg.h"
#include "MedicSearch.h"
#include "MedicAdminDoc.h"
#include "MedicListView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchNameDlg dialog


CSearchNameDlg::CSearchNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchNameDlg)
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void CSearchNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchNameDlg)
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchNameDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchNameDlg)
	ON_BN_CLICKED(ID_SEARCH_NAME, OnSearchName)
	ON_BN_CLICKED(ID_SEARCH_NAME_EXIT, OnSearchNameExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchNameDlg message handlers

void CSearchNameDlg::OnSearchName() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_name=="")
	{
		AfxMessageBox("请输入要查询的药品名称");
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
			medicSearch.Search(m_name,1);
		}
	}
	CDialog::OnOK();
}

void CSearchNameDlg::OnSearchNameExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
