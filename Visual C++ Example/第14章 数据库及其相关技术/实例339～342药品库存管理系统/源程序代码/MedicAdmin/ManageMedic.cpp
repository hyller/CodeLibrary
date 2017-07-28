// ManageMedic.cpp: implementation of the CManageMedic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MedicAdmin.h"
#include "ManageMedic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CManageMedic::CManageMedic()
{

}

CManageMedic::~CManageMedic()
{

}

void CManageMedic::SetMedic(CMedic *theMedic)
{
	m_theMedic=theMedic;
}

void CManageMedic::SetMedicSet(CMedicSet *theMedicSet)
{
	m_theMedicSet=theMedicSet;
}

void CManageMedic::Import()
{
	m_theMedicSet->m_strFilter="MedicineID='"+m_theMedic->m_MedicineID+"'";
	m_theMedicSet->Requery();
	if(m_theMedicSet->GetRecordCount())
	{
		if(m_theMedic->m_MedicineName != m_theMedicSet->m_MedicineName)
		{
			AfxMessageBox("输入的代号和名称不匹配!");
			return;
		}
		if(m_theMedic->m_MedicineClassification != m_theMedicSet->m_MedicineClassification)
		{
			AfxMessageBox("输入的代号和类别不匹配!");
			return;
		}
		m_theMedicSet->Edit();
		m_theMedicSet->m_MedicineNumber += m_theMedic->m_MedicineNumber;
		if(m_theMedicSet->CanUpdate())
		{
			m_theMedicSet->Update();
		}
	}
	else
	{
		m_theMedicSet->AddNew();
		m_theMedicSet->m_MedicineID=m_theMedic->m_MedicineID;
		m_theMedicSet->m_MedicineName=m_theMedic->m_MedicineName;
		m_theMedicSet->m_MedicineClassification=m_theMedic->m_MedicineClassification;
		m_theMedicSet->m_ProduceCompany=m_theMedic->m_ProduceCompany;
		m_theMedicSet->m_ProduceDate=m_theMedic->m_ProduceDate;
		m_theMedicSet->m_Produceplace=m_theMedic->m_Produceplace;
		m_theMedicSet->m_MedicineNumber=m_theMedic->m_MedicineNumber;
		m_theMedicSet->m_QeulityAssurancePeriod=m_theMedic->m_QeulityAssurancePeriod;
		m_theMedicSet->m_UnitPrice=m_theMedic->m_UnitPrice;
		m_theMedicSet->m_Description=m_theMedic->m_Description;
		if(m_theMedicSet->CanUpdate())
		{
			m_theMedicSet->Update();
		}
		if(m_theMedicSet->IsEOF())
		{
			m_theMedicSet->MoveLast();
		}
		m_theMedicSet->Requery();
	}

}

void CManageMedic::SetSale(CSale *theSale)
{
	m_theSale=theSale;
}

void CManageMedic::SetSaleSet(CSaleSet *theSaleSet)
{
	m_theSaleSet=theSaleSet;
}

BOOL CManageMedic::AddToSaleTable()
{
	m_theSaleSet->m_strFilter="MedicineID='"+m_theSale->m_MedicineID+"'";
	m_theSaleSet->Requery();
	if(m_theSaleSet->GetRecordCount())
	{
		AfxMessageBox("该药品已经存在!");
		return FALSE;
	}
	m_theMedicSet->m_strFilter="MedicineID='"+m_theSale->m_MedicineID+"'";
	m_theMedicSet->Requery();
	if(!m_theMedicSet->GetRecordCount())
	{
		AfxMessageBox("仓库中没有该药品!");
		return FALSE;
	}
	if(m_theMedicSet->m_MedicineNumber < m_theSale->m_MedicineNumber)
	{
		AfxMessageBox("该药品库存不足!");
		return FALSE;
	}
	m_theSaleSet->AddNew();
	m_theSaleSet->m_MedicineID=m_theSale->m_MedicineID;
	m_theSaleSet->m_MedicineName=m_theSale->m_MedicineName;
	m_theSaleSet->m_MedicineNumber=m_theSale->m_MedicineNumber;
	m_theSaleSet->m_MedicinePrice=m_theSale->m_MedicinePrice;
	if(m_theSaleSet->CanUpdate())
	{
		m_theSaleSet->Update();
	}
	if(!m_theSaleSet->IsEOF())
	{
		m_theSaleSet->MoveLast();
	}
	m_theSaleSet->Requery();
	int number=m_theMedicSet->m_MedicineNumber;
	m_theMedicSet->Edit();
	m_theMedicSet->m_MedicineNumber = number - m_theSale->m_MedicineNumber;
	if(m_theMedicSet->CanUpdate())
	{
		m_theMedicSet->Update();
	}
	return TRUE;
}

BOOL CManageMedic::ModifyFromSaleTable()
{
	m_theSaleSet->m_strFilter="MedicineID='"+m_theSale->m_MedicineID+"'";
	m_theSaleSet->Requery();
	if(m_theSaleSet->GetRecordCount())
	{
		m_theSaleSet->Edit();
		m_theSaleSet->m_MedicineNumber=m_theSale->m_MedicineNumber;
		m_theSaleSet->m_MedicinePrice=m_theSale->m_MedicinePrice;
		if(m_theSaleSet->CanUpdate())
		{
			m_theSaleSet->Update();
		}
		return TRUE;
	}
	else
	{
		AfxMessageBox("请选择增加按钮!");
		return FALSE;
	}
}

BOOL CManageMedic::DeleteFromSaleTable()
{
	m_theSaleSet->m_strFilter="MedicineID='"+m_theSale->m_MedicineID+"'";
	m_theSaleSet->Requery();
	if(!m_theSaleSet->GetRecordCount())
	{
		AfxMessageBox("您要删除的药品不存在!");
		return FALSE;
	}
	int number=m_theSaleSet->m_MedicineNumber;
	m_theSaleSet->Delete();
	m_theMedicSet->m_strFilter="MedicineID='"+m_theSale->m_MedicineID+"'";
	m_theMedicSet->Requery();
	int number2=m_theMedicSet->m_MedicineNumber;
	m_theMedicSet->Edit();
	m_theMedicSet->m_MedicineNumber = number + number2;
	if(m_theMedicSet->CanUpdate())
	{
		m_theMedicSet->Update();
	}
	return TRUE;
}

BOOL CManageMedic::Recover()
{
  	m_theSaleSet->m_strFilter="";
	m_theSaleSet->Requery();
	int number=m_theSaleSet->GetRecordCount();
	if(!number)
	{
		AfxMessageBox("没有要恢复的数据!");
		return FALSE;
	}
	for(int i=0;;i++)
	{
		if(m_theSaleSet->IsEOF())
		{
			break;
		}
		int number=m_theSaleSet->m_MedicineNumber;
		m_theMedicSet->m_strFilter="MedicineID='"+m_theSaleSet->m_MedicineID+"'";
		m_theMedicSet->Requery();
		m_theSaleSet->Delete();
		m_theSaleSet->MoveNext();
		int number2=m_theMedicSet->m_MedicineNumber;
		m_theMedicSet->Edit();
		m_theMedicSet->m_MedicineNumber = number + number2;
		if(m_theMedicSet->CanUpdate())
		{
			m_theMedicSet->Update();
		}
	}
	return TRUE;
}

float CManageMedic::CheckOut()
{
	m_theSaleSet->m_strFilter="";
	m_theSaleSet->Requery();
	if(!m_theSaleSet->GetRecordCount())
	{
		return 0;
	}
	float money=0;
	for(int i=0;;i++)
	{
		if(m_theSaleSet->IsEOF())
		{
			break;
		}
		money += m_theSaleSet->m_MedicinePrice;
		m_theSaleSet->Delete();
		m_theSaleSet->MoveNext();
	}
	return money;
}

CTime CManageMedic::GetExpireTime()
{
	CTime timeProduce=m_theMedicSet->m_ProduceDate;
	int quelity=m_theMedicSet->m_QeulityAssurancePeriod;
	int month=(timeProduce.GetMonth()+quelity) % 12;
	if(month==0)
	{
		month=12;
	}
	int year=(timeProduce.GetMonth()+quelity)/12+timeProduce.GetYear();
	if(month==12)
	{
		year=year-1;
	}
	int day=timeProduce.GetDay();
	CTime timeAfter(year,month,day,0,0,0);	
	return timeAfter;
}

void CManageMedic::DeleteAllZeroNumber()
{
	m_theMedicSet->m_strFilter="MedicineNumber=0";
	m_theMedicSet->Requery();
	for(int i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		m_theMedicSet->Delete();
		m_theMedicSet->MoveNext();
	}
}

void CManageMedic::DeleteOverdueMedic()
{
	m_theMedicSet->m_strFilter="";
	m_theMedicSet->Requery();
	for(int i=0;;i++)
	{
		if(m_theMedicSet->IsEOF())
		{
			break;
		}
		CTime expireTime=GetExpireTime();
		CTime nowTime=CTime::GetCurrentTime();
		if(expireTime<nowTime)
		{
			m_theMedicSet->Delete();
		}
		m_theMedicSet->MoveNext();
	}
}
