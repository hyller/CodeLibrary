// UserSet.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "UserSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserSet

IMPLEMENT_DYNAMIC(CUserSet, CRecordset)

CUserSet::CUserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CUserSet)
	m_UserAccount = _T("");
	m_UserName = _T("");
	m_UserPassword = _T("");
	m_UserClassification = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CUserSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=medicine");
}

CString CUserSet::GetDefaultSQL()
{
	return _T("[user]");
}

void CUserSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CUserSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[UserAccount]"), m_UserAccount);
	RFX_Text(pFX, _T("[UserName]"), m_UserName);
	RFX_Text(pFX, _T("[UserPassword]"), m_UserPassword);
	RFX_Text(pFX, _T("[UserClassification]"), m_UserClassification);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUserSet diagnostics

#ifdef _DEBUG
void CUserSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
