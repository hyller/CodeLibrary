// MedicSet.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "MedicSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMedicSet

IMPLEMENT_DYNAMIC(CMedicSet, CRecordset)

CMedicSet::CMedicSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMedicSet)
	m_MedicineID = _T("");
	m_MedicineName = _T("");
	m_MedicineClassification = _T("");
	m_Produceplace = _T("");
	m_MedicineNumber = 0;
	m_Description = _T("");
	m_UnitPrice = 0.0f;
	m_QeulityAssurancePeriod = 0;
	m_LowestNumber = 0;
	m_HighestNumber = 0;
	m_ProduceCompany = _T("");
	m_nFields = 12;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CMedicSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=medicine");
}

CString CMedicSet::GetDefaultSQL()
{
	return _T("[medicine]");
}

void CMedicSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMedicSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[MedicineID]"), m_MedicineID);
	RFX_Text(pFX, _T("[MedicineName]"), m_MedicineName);
	RFX_Text(pFX, _T("[MedicineClassification]"), m_MedicineClassification);
	RFX_Date(pFX, _T("[ProduceDate]"), m_ProduceDate);
	RFX_Text(pFX, _T("[Produceplace]"), m_Produceplace);
	RFX_Int(pFX, _T("[MedicineNumber]"), m_MedicineNumber);
	RFX_Text(pFX, _T("[Description]"), m_Description);
	RFX_Single(pFX, _T("[UnitPrice]"), m_UnitPrice);
	RFX_Int(pFX, _T("[QeulityAssurancePeriod]"), m_QeulityAssurancePeriod);
	RFX_Int(pFX, _T("[LowestNumber]"), m_LowestNumber);
	RFX_Int(pFX, _T("[HighestNumber]"), m_HighestNumber);
	RFX_Text(pFX, _T("[ProduceCompany]"), m_ProduceCompany);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMedicSet diagnostics

#ifdef _DEBUG
void CMedicSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMedicSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
