// MedicSearch.cpp: implementation of the CMedicSearch class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MedicAdmin.h"
#include "MedicSearch.h"
#include "ManageMedic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMedicSearch::CMedicSearch()
{

}

CMedicSearch::~CMedicSearch()
{

}

void CMedicSearch::SetListCtrl(CListCtrl *theListCtrl)
{
	m_theListCtrl=theListCtrl;
}

void CMedicSearch::SetMedicSet(CMedicSet *theMedicSet)
{
	m_theMedicSet=theMedicSet;
}

void CMedicSearch::Search(CString str1, int flag)
{
	if(flag==0)
	{
		m_theMedicSet->m_strFilter="MedicineID='"+str1+"'";
	}
	else if(flag==1)
	{
		m_theMedicSet->m_strFilter="MedicineName='"+str1+"'";
	}
	else if(flag==2)
	{
		m_theMedicSet->m_strFilter="MedicineClassification='"+str1+"'";
	}
	else
	{
		return;
	}
	m_theMedicSet->Requery();
	m_theListCtrl->DeleteAllItems();
	CString str;
	for(int i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		m_theListCtrl->InsertItem(i,m_theMedicSet->m_MedicineID);
		m_theListCtrl->SetItemText(i,1,m_theMedicSet->m_MedicineName);
		m_theListCtrl->SetItemText(i,2,m_theMedicSet->m_MedicineClassification);
		str.Format("%d",m_theMedicSet->m_MedicineNumber);
		m_theListCtrl->SetItemText(i,3,str);
		m_theListCtrl->SetItemText(i,4,m_theMedicSet->m_ProduceCompany);
		m_theListCtrl->SetItemText(i,5,m_theMedicSet->m_Produceplace);
		CTime produceTime=m_theMedicSet->m_ProduceDate;
		str=produceTime.Format("%B %d,%Y");
		m_theListCtrl->SetItemText(i,6,str);
		str.Format("%d",m_theMedicSet->m_QeulityAssurancePeriod);
		m_theListCtrl->SetItemText(i,7,str);
		str.Format("%f",m_theMedicSet->m_UnitPrice);
		m_theListCtrl->SetItemText(i,8,str);
		m_theMedicSet->MoveNext();
	}
}

void CMedicSearch::SearchAll()
{
	m_theMedicSet->m_strFilter="";
	m_theMedicSet->Requery();
	m_theListCtrl->DeleteAllItems();
	CString str;
	for(int i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		m_theListCtrl->InsertItem(i,m_theMedicSet->m_MedicineID);
		m_theListCtrl->SetItemText(i,1,m_theMedicSet->m_MedicineName);
		m_theListCtrl->SetItemText(i,2,m_theMedicSet->m_MedicineClassification);
		str.Format("%d",m_theMedicSet->m_MedicineNumber);
		m_theListCtrl->SetItemText(i,3,str);
		m_theListCtrl->SetItemText(i,4,m_theMedicSet->m_ProduceCompany);
		m_theListCtrl->SetItemText(i,5,m_theMedicSet->m_Produceplace);
		CTime produceTime=m_theMedicSet->m_ProduceDate;
		str=produceTime.Format("%B %d,%Y");
		m_theListCtrl->SetItemText(i,6,str);
		str.Format("%d",m_theMedicSet->m_QeulityAssurancePeriod);
		m_theListCtrl->SetItemText(i,7,str);
		str.Format("%f",m_theMedicSet->m_UnitPrice);
		m_theListCtrl->SetItemText(i,8,str);
		m_theMedicSet->MoveNext();
	}
}

void CMedicSearch::SearchZeroNumber()
{
	m_theMedicSet->m_strFilter="MedicineNumber=0";
	m_theMedicSet->Requery();
	m_theListCtrl->DeleteAllItems();
	CString str;
	for(int i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		m_theListCtrl->InsertItem(i,m_theMedicSet->m_MedicineID);
		m_theListCtrl->SetItemText(i,1,m_theMedicSet->m_MedicineName);
		m_theListCtrl->SetItemText(i,2,m_theMedicSet->m_MedicineClassification);
		str.Format("%d",m_theMedicSet->m_MedicineNumber);
		m_theListCtrl->SetItemText(i,3,str);
		m_theListCtrl->SetItemText(i,4,m_theMedicSet->m_ProduceCompany);
		m_theListCtrl->SetItemText(i,5,m_theMedicSet->m_Produceplace);
		CTime produceTime=m_theMedicSet->m_ProduceDate;
		str=produceTime.Format("%B %d,%Y");
		m_theListCtrl->SetItemText(i,6,str);
		str.Format("%d",m_theMedicSet->m_QeulityAssurancePeriod);
		m_theListCtrl->SetItemText(i,7,str);
		str.Format("%f",m_theMedicSet->m_UnitPrice);
		m_theListCtrl->SetItemText(i,8,str);
		m_theMedicSet->MoveNext();
	}
}

void CMedicSearch::SearchOverdueMedic()
{
	m_theMedicSet->m_strFilter="";
	m_theMedicSet->Requery();
	m_theListCtrl->DeleteAllItems();
	CString str;
	CManageMedic manageMedic;
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
			m_theListCtrl->InsertItem(i,m_theMedicSet->m_MedicineID);
			m_theListCtrl->SetItemText(i,1,m_theMedicSet->m_MedicineName);
			m_theListCtrl->SetItemText(i,2,m_theMedicSet->m_MedicineClassification);
			str.Format("%d",m_theMedicSet->m_MedicineNumber);
			m_theListCtrl->SetItemText(i,3,str);
			m_theListCtrl->SetItemText(i,4,m_theMedicSet->m_ProduceCompany);
			m_theListCtrl->SetItemText(i,5,m_theMedicSet->m_Produceplace);
			CTime produceTime=m_theMedicSet->m_ProduceDate;
			str=produceTime.Format("%B %d,%Y");
			m_theListCtrl->SetItemText(i,6,str);
			str.Format("%d",m_theMedicSet->m_QeulityAssurancePeriod);
			m_theListCtrl->SetItemText(i,7,str);
			str.Format("%f",m_theMedicSet->m_UnitPrice);
			m_theListCtrl->SetItemText(i,8,str);
		}
		else
		{
			i--;
		}
		m_theMedicSet->MoveNext();
	}
}
