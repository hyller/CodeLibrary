// SearchIDDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SearchIDDlg.h"
#include "medicSearch.h"
#include "medicAdminDoc.h"
#include "MedicListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchIDDlg dialog


CSearchIDDlg::CSearchIDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchIDDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchIDDlg)
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void CSearchIDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchIDDlg)
	DDX_Text(pDX, IDC_ID_EDIT, m_id);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchIDDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchIDDlg)
	ON_BN_CLICKED(ID_SEARCH_ID, OnSearchId)
	ON_BN_CLICKED(ID_SEARCH_ID_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchIDDlg message handlers

void CSearchIDDlg::OnSearchId() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_id=="")
	{
		AfxMessageBox("请输入要查询的药品代号");
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
			medicSearch.Search(m_id,0);
		}
	}
	CDialog::OnOK();
}

void CSearchIDDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
