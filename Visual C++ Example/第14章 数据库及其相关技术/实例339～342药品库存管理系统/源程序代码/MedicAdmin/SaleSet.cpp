// SaleSet.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "SaleSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaleSet

IMPLEMENT_DYNAMIC(CSaleSet, CRecordset)

CSaleSet::CSaleSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSaleSet)
	m_MedicineID = _T("");
	m_MedicineName = _T("");
	m_MedicineNumber = 0;
	m_MedicinePrice = 0.0f;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSaleSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=medicine");
}

CString CSaleSet::GetDefaultSQL()
{
	return _T("[saleTable]");
}

void CSaleSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSaleSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[MedicineID]"), m_MedicineID);
	RFX_Text(pFX, _T("[MedicineName]"), m_MedicineName);
	RFX_Int(pFX, _T("[MedicineNumber]"), m_MedicineNumber);
	RFX_Single(pFX, _T("[MedicinePrice]"), m_MedicinePrice);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSaleSet diagnostics

#ifdef _DEBUG
void CSaleSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSaleSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
