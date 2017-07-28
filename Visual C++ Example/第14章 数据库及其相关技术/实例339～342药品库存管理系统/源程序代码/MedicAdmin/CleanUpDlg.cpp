// CleanUpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "CleanUpDlg.h"
#include "Mainfrm.h"
#include "medicAdminDoc.h"
#include "manageMedic.h"
#include "MedicListView.h"
#include "MedicSearch.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCleanUpDlg dialog


CCleanUpDlg::CCleanUpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCleanUpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCleanUpDlg)
	m_selectRadio = -1;
	//}}AFX_DATA_INIT
}


void CCleanUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCleanUpDlg)
	DDX_Control(pDX, IDC_LIST, m_showList);
	DDX_Radio(pDX, IDC_ZERO_RADIO, m_selectRadio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCleanUpDlg, CDialog)
	//{{AFX_MSG_MAP(CCleanUpDlg)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_CLEAN_UP_BUTTON, OnCleanUpButton)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_ZERO_RADIO, OnZeroRadio)
	ON_BN_CLICKED(IDC_OVERDUE_RADIO, OnOverdueRadio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCleanUpDlg message handlers

BOOL CCleanUpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CManageMedic manageMedic;
	CString header[]={"药品代号","药品名称","库存数量","是否过期"};
	for(int i=0;i<4;i++)
	{
		m_showList.InsertColumn(i,header[i],LVCFMT_LEFT,90);
	}
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)pMainFrm->GetActiveDocument();
	m_theMedicSet=&pDoc->theMedicSet;
	m_theMedicSet->m_strFilter="";
	m_theMedicSet->Requery();
	for(i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		m_showList.InsertItem(i,m_theMedicSet->m_MedicineID);
		m_showList.SetItemText(i,1,m_theMedicSet->m_MedicineName);
		CString str;
		str.Format("%d",m_theMedicSet->m_MedicineNumber);
		m_showList.SetItemText(i,2,str);
		manageMedic.SetMedicSet(m_theMedicSet);
		CTime timeAfter=manageMedic.GetExpireTime();
		CTime timeNow=CTime::GetCurrentTime();
		CString strfool;
		if(timeAfter>timeNow)
		{
			strfool="否";
		}
		else
		{
			strfool="是";
		}
		m_showList.SetItemText(i,3,strfool);
		m_theMedicSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCleanUpDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
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
			theMedicSet->m_strFilter="";
			theMedicSet->Requery();
			theListCtrl->DeleteAllItems();
			CString str;
			for(int i=0;;i++)
			{
				if(theMedicSet->IsEOF())
				{
					break;
				}
				theListCtrl->InsertItem(i,theMedicSet->m_MedicineID);
				theListCtrl->SetItemText(i,1,theMedicSet->m_MedicineName);
				theListCtrl->SetItemText(i,2,theMedicSet->m_MedicineClassification);
				str.Format("%d",theMedicSet->m_MedicineNumber);
				theListCtrl->SetItemText(i,3,str);
				theListCtrl->SetItemText(i,4,theMedicSet->m_ProduceCompany);
				theListCtrl->SetItemText(i,5,theMedicSet->m_Produceplace);
				CTime produceTime=theMedicSet->m_ProduceDate;
				str=produceTime.Format("%B %d,%Y");
				theListCtrl->SetItemText(i,6,str);
				str.Format("%d",theMedicSet->m_QeulityAssurancePeriod);
				theListCtrl->SetItemText(i,7,str);
				str.Format("%f",theMedicSet->m_UnitPrice);
				theListCtrl->SetItemText(i,8,str);
				theMedicSet->MoveNext();
			}
		}
	}
	CDialog::OnOK();
}

void CCleanUpDlg::OnCleanUpButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CManageMedic manageMedic;
	manageMedic.SetMedicSet(m_theMedicSet);
	if(m_selectRadio==0)
	{
		manageMedic.DeleteAllZeroNumber();
	}
	else
	{
		manageMedic.DeleteOverdueMedic();
	}
	m_theMedicSet->m_strFilter="";
	m_theMedicSet->Requery();
	m_showList.DeleteAllItems();
	for(int i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		m_showList.InsertItem(i,m_theMedicSet->m_MedicineID);
		m_showList.SetItemText(i,1,m_theMedicSet->m_MedicineName);
		CString str;
		str.Format("%d",m_theMedicSet->m_MedicineNumber);
		m_showList.SetItemText(i,2,str);
		manageMedic.SetMedicSet(m_theMedicSet);
		CTime timeAfter=manageMedic.GetExpireTime();
		CTime timeNow=CTime::GetCurrentTime();
		CString strfool;
		if(timeAfter>timeNow)
		{
			strfool="否";
		}
		else
		{
			strfool="是";
		}
		m_showList.SetItemText(i,3,strfool);
		m_theMedicSet->MoveNext();
	}
}

void CCleanUpDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	OnExit();
	//CDialog::OnClose();
}

void CCleanUpDlg::OnZeroRadio() 
{
	// TODO: Add your control notification handler code here
	CMedicSearch medicSearch;
	medicSearch.SetMedicSet(m_theMedicSet);
	medicSearch.SetListCtrl(&m_showList);
	medicSearch.SearchZeroNumber();
}

void CCleanUpDlg::OnOverdueRadio() 
{
	// TODO: Add your control notification handler code here
	CManageMedic manageMedic;
	m_theMedicSet->m_strFilter="";
	m_theMedicSet->Requery();
	m_showList.DeleteAllItems();
	for(int i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		manageMedic.SetMedicSet(m_theMedicSet);
		CTime timeAfter=manageMedic.GetExpireTime();
		CTime timeNow=CTime::GetCurrentTime();
		if(timeAfter<timeNow)
		{
			m_showList.InsertItem(i,m_theMedicSet->m_MedicineID);
			m_showList.SetItemText(i,1,m_theMedicSet->m_MedicineName);
			CString str;
			str.Format("%d",m_theMedicSet->m_MedicineNumber);
			m_showList.SetItemText(i,2,str);
			m_showList.SetItemText(i,3,"是");
		}
		else
		{
			i=i-1;
		}
		m_theMedicSet->MoveNext();
	}

}
