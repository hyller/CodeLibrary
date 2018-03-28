// SaleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SaleDlg.h"
#include "mainfrm.h"
#include "medicAdmindoc.h"
#include "managemedic.h"
#include "MedicListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaleDlg dialog


CSaleDlg::CSaleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSaleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSaleDlg)
	m_name = _T("");
	m_number = 0;
	//}}AFX_DATA_INIT
}


void CSaleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSaleDlg)
	DDX_Control(pDX, IDC_SETTLEMENT_BUTTON, m_settlement);
	DDX_Control(pDX, IDC_SALE_LIST, m_saleList);
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_NUMBER_EDIT, m_number);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSaleDlg, CDialog)
	//{{AFX_MSG_MAP(CSaleDlg)
	ON_BN_CLICKED(ID_ADD,OnAdd)
	ON_BN_CLICKED(IDC_RECOVER_BUTTON, OnRecoverButton)
	ON_BN_CLICKED(ID_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_SETTLEMENT_BUTTON, OnSettlementButton)
	ON_BN_CLICKED(IDC_EXIT_BUTTON, OnExitButton)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaleDlg message handlers

BOOL CSaleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strSale[]={"药品代号","药品名称","出售数量","金额(元)"};
	for(int j=0;j<4;j++)
	{
		m_saleList.InsertColumn(j,strSale[j],LVCFMT_LEFT,92);
	}
	CMainFrame* theMainFrm=(CMainFrame*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)theMainFrm->GetActiveDocument();
	theSaleSet=&pDoc->theSaleSet;
	theMedicSet=&pDoc->theMedicSet;
	theSaleSet->m_strFilter="";
	theSaleSet->Requery();
	for(int i=0;;i++)
	{
		if(theSaleSet->IsEOF())
		{
			break;
		}
		CString str;
		str.Format("%d",theSaleSet->m_MedicineNumber);
		m_saleList.InsertItem(i,theSaleSet->m_MedicineID);
		m_saleList.SetItemText(i,1,theSaleSet->m_MedicineName);
		m_saleList.SetItemText(i,2,str);
		str.Format("%f",theSaleSet->m_MedicinePrice);
		m_saleList.SetItemText(i,3,str);
		theSaleSet->MoveNext();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSaleDlg::OnAdd() 
{
	// TODO: Add extra validation here
	UpdateData();
	
	if(m_name=="")
	{
		AfxMessageBox("请填入药品名称!");
		return;
	}
	if(m_number == 0)
	{
		AfxMessageBox("请输入销售药品数量!");
		return;
	}
	CManageMedic manageMedic;
	CSale* newSale=new CSale;
	theMedicSet->m_strFilter="MedicineName='"+m_name+"'";
	theMedicSet->Requery();
	if(theMedicSet->GetRecordCount())
	{
		newSale->m_MedicineID=theMedicSet->m_MedicineID;
		newSale->m_MedicineName=theMedicSet->m_MedicineName;
		newSale->m_MedicineNumber=m_number;
		newSale->m_MedicinePrice=theMedicSet->m_UnitPrice*m_number;
		manageMedic.SetSale(newSale);
		manageMedic.SetSaleSet(theSaleSet);
		manageMedic.SetMedicSet(theMedicSet);
		CTime expireTime=manageMedic.GetExpireTime();
		CTime nowTime=CTime::GetCurrentTime();
		if(expireTime<nowTime)
		{
			AfxMessageBox("该药品已过期!");
			return;
		}
		if(manageMedic.AddToSaleTable())
		{
			int number=m_saleList.GetItemCount();
			CString str;
			str.Format("%d",newSale->m_MedicineNumber);
			m_saleList.InsertItem(number,newSale->m_MedicineID);
			m_saleList.SetItemText(number,1,newSale->m_MedicineName);
			m_saleList.SetItemText(number,2,str);
			str.Format("%f",newSale->m_MedicinePrice);
			m_saleList.SetItemText(number,3,str);
		}
	}
	else
	{
		AfxMessageBox("仓库中没有该药品!");
	}
	m_name="";
	m_number=0;
	UpdateData(FALSE);

	//CDialog::OnOK();
}

/*void CSaleDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CManageMedic manageMadic;
	//CSale* modSale;
//	manageMadic.SetSale
}*/

void CSaleDlg::OnRecoverButton() 
{
	// TODO: Add your control notification handler code here
	CManageMedic manageMedic;
	manageMedic.SetMedicSet(theMedicSet);
	manageMedic.SetSaleSet(theSaleSet);
	manageMedic.Recover();
	m_saleList.DeleteAllItems();
}

void CSaleDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CManageMedic manageMedic;
	CSale* oldSale=new CSale;
	if(m_name=="")
	{
		AfxMessageBox("请输入药品名称!");
		return;
	}
	theSaleSet->m_strFilter="MedicineName='"+m_name+"'";
	theSaleSet->Requery();
	if(!theSaleSet->GetRecordCount())
	{
		AfxMessageBox("您要删除的药品不在出售单内!");
	}
	else
	{
		oldSale->m_MedicineID=theSaleSet->m_MedicineID;
		oldSale->m_MedicineName=theSaleSet->m_MedicineName;
		oldSale->m_MedicineNumber=theSaleSet->m_MedicineNumber;
		oldSale->m_MedicinePrice=theSaleSet->m_MedicinePrice;
		manageMedic.SetSale(oldSale);
		manageMedic.SetSaleSet(theSaleSet);
		manageMedic.SetMedicSet(theMedicSet);
		if(manageMedic.DeleteFromSaleTable())
		{
			m_saleList.DeleteAllItems();
			theSaleSet->m_strFilter="";
			theSaleSet->Requery();
			for(int i=0;;i++)
			{
				if(theSaleSet->IsEOF())
				{
					break;
				}
				CString str;
				str.Format("%d",theSaleSet->m_MedicineNumber);
				m_saleList.InsertItem(i,theSaleSet->m_MedicineID);
				m_saleList.SetItemText(i,1,theSaleSet->m_MedicineName);
				m_saleList.SetItemText(i,2,str);
				str.Format("%f",theSaleSet->m_MedicinePrice);
				m_saleList.SetItemText(i,3,str);
				theSaleSet->MoveNext();
			}
		}
	}
	m_name="";
	m_number=0;
	UpdateData(FALSE);
}

void CSaleDlg::OnSettlementButton() 
{
	// TODO: Add your control notification handler code here
	CManageMedic manageMedic;
	manageMedic.SetSaleSet(theSaleSet);
	float money;
	money=manageMedic.CheckOut();
	CString str;
	str.Format("%f",money);
	if(money)
	{
		AfxMessageBox("请支付 "+str+" 元!");
		//CDialog::OnOK();
	}
	else
	{
		AfxMessageBox("请填写出售单!");
	}
}

void CSaleDlg::OnExitButton() 
{
	// TODO: Add your control notification handler code here
	theSaleSet->m_strFilter="";
	theSaleSet->Requery();
	if(!theSaleSet->GetRecordCount())
	{
		CFrameWnd* pWnd=(CFrameWnd*)AfxGetMainWnd();
		CMedicAdminDoc* pDoc=(CMedicAdminDoc*)pWnd->GetActiveDocument();
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
	else
	{
		AfxMessageBox("在退出前请结账或恢复数据!");
	}
}


void CSaleDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	/*theSaleSet->m_strFilter="";
	theSaleSet->Requery();
	if(!theSaleSet->GetRecordCount())
	{
		CDialog::OnClose();
	}
	else
	{
		AfxMessageBox("在退出前请结账或恢复数据!");
	}*/	
	OnExitButton();
}
