// ODBCDatabase3Set.cpp : implementation of the CODBCDatabase3Set class
//

#include "stdafx.h"
#include "ODBCDatabase3.h"
#include "ODBCDatabase3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3Set implementation

IMPLEMENT_DYNAMIC(CODBCDatabase3Set, CRecordset)

CODBCDatabase3Set::CODBCDatabase3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CODBCDatabase3Set)
	m_Age = _T("");
	m_name = _T("");
	m_sex = _T("");
	m_stuno = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CODBCDatabase3Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=student");
}

CString CODBCDatabase3Set::GetDefaultSQL()
{
	return _T("[STUDENT]");
}

void CODBCDatabase3Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CODBCDatabase3Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[年龄]"), m_Age);
	RFX_Text(pFX, _T("[姓名]"), m_name);
	RFX_Text(pFX, _T("[性别]"), m_sex);
	RFX_Text(pFX, _T("[学号]"), m_stuno);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3Set diagnostics

#ifdef _DEBUG
void CODBCDatabase3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBCDatabase3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
