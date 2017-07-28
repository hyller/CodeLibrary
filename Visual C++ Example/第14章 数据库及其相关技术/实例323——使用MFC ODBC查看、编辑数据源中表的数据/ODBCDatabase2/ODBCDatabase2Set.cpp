// ODBCDatabase2Set.cpp : implementation of the CODBCDatabase2Set class
//

#include "stdafx.h"
#include "ODBCDatabase2.h"
#include "ODBCDatabase2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2Set implementation

IMPLEMENT_DYNAMIC(CODBCDatabase2Set, CRecordset)

CODBCDatabase2Set::CODBCDatabase2Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CODBCDatabase2Set)
	m_Age = _T("");
	m_name = _T("");
	m_sex = _T("");
	m_stuno = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CODBCDatabase2Set::GetDefaultConnect()
{
	return _T("ODBC;DSN=student");
}

CString CODBCDatabase2Set::GetDefaultSQL()
{
	return _T("[STUDENT]");
}

void CODBCDatabase2Set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CODBCDatabase2Set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[年龄]"), m_Age);
	RFX_Text(pFX, _T("[姓名]"), m_name);
	RFX_Text(pFX, _T("[性别]"), m_sex);
	RFX_Text(pFX, _T("[学号]"), m_stuno);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase2Set diagnostics

#ifdef _DEBUG
void CODBCDatabase2Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CODBCDatabase2Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
