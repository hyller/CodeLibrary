// StoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "StoreDlg.h"
#include "mainFrm.h"
#include "MedicAdminDoc.h"
#include "ManageMedic.h"
#include "MedicListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStoreDlg dialog


CStoreDlg::CStoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStoreDlg)
	m_company = _T("");
	m_day = 1;
	m_id = _T("");
	m_name = _T("");
	m_month = 1;
	m_periodQuelity = 0;
	m_number = 0;
	m_place = _T("");
	m_type = _T("");
	m_unitPrice = 0.0f;
	m_year = 2000;
	m_description = _T("");
	//}}AFX_DATA_INIT
}


void CStoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStoreDlg)
	DDX_Text(pDX, IDC_COMPANY_EDIT, m_company);
	DDX_Text(pDX, IDC_DAY_EDIT, m_day);
	DDX_Text(pDX, IDC_ID_EDIT, m_id);
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_MONTH_EDIT, m_month);
	DDX_Text(pDX, IDC_PERIODQUELITY_EDIT, m_periodQuelity);
	DDX_Text(pDX, IDC_NUMBER_EDIT, m_number);
	DDX_Text(pDX, IDC_PLACE_EDIT, m_place);
	DDX_Text(pDX, IDC_TYPE_EDIT, m_type);
	DDX_Text(pDX, IDC_UNITPRICE_EDIT, m_unitPrice);
	DDX_Text(pDX, IDC_YEAR_EDIT, m_year);
	DDX_Text(pDX, IDC_DESCRIPTION_EDIT, m_description);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStoreDlg, CDialog)
	//{{AFX_MSG_MAP(CStoreDlg)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, OnExitButton)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStoreDlg message handlers

void CStoreDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_id=="")
	{
		AfxMessageBox("请输入药品代号!");
		return;
	}
	if(m_name=="")
	{
		AfxMessageBox("请输入药品名称!");
		return;
	}
	if(m_type=="")
	{
		AfxMessageBox("请输入药品类别!");
		return;
	}
	if((m_year<=1900)||(m_month>12)||(m_month<1)||(m_day>31)||(m_day<1))
	{
		AfxMessageBox("请重新输入出产日期!");
		return;
	}
	
	CMedic* medic=new CMedic;
	medic->m_MedicineID=m_id;
	medic->m_MedicineName=m_name;
	medic->m_MedicineClassification=m_type;
	medic->m_Description=m_description;
	medic->m_MedicineNumber=m_number;
	medic->m_ProduceCompany=m_company;
	CTime produceTime(m_year,m_month,m_day,0,0,0);
	medic->m_ProduceDate=produceTime;
	medic->m_Produceplace=m_place;
	medic->m_QeulityAssurancePeriod=m_periodQuelity;
	medic->m_UnitPrice=m_unitPrice;

	CMainFrame* theFrm=(CMainFrame*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)theFrm->GetActiveDocument();
	CMedicSet* theSet=&pDoc->theMedicSet;
	CManageMedic* manageMedic=new CManageMedic;
	manageMedic->SetMedic(medic);
	manageMedic->SetMedicSet(theSet);
	manageMedic->Import();

	m_id="";
	m_name="";
	m_type="";
	m_description="";
	m_company="";
	m_place="";
	m_year=2000;
	m_day=1;
	m_month=1;
	m_unitPrice=0;
	m_periodQuelity=0;
	m_number=0;
	UpdateData(FALSE);
	//CDialog::OnOK();
}

void CStoreDlg::OnExitButton() 
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

void CStoreDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_id="";
	m_name="";
	m_type="";
	m_description="";
	m_company="";
	m_place="";
	m_year=2000;
	m_day=1;
	m_month=1;
	m_unitPrice=0;
	m_periodQuelity=0;
	m_number=0;
	UpdateData(FALSE);
	//CDialog::OnCancel();
}

void CStoreDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	OnExitButton();
	//CDialog::OnClose();
}
