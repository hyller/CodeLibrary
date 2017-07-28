// ODBCDatabase2Set.h : interface of the CODBCDatabase2Set class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCDatabase2SET_H__D36014E9_ABA4_491D_B8BD_AEB9AA489AE6__INCLUDED_)
#define AFX_ODBCDatabase2SET_H__D36014E9_ABA4_491D_B8BD_AEB9AA489AE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CODBCDatabase2Set : public CRecordset
{
public:
	CODBCDatabase2Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CODBCDatabase2Set)

// Field/Param Data
	//{{AFX_FIELD(CODBCDatabase2Set, CRecordset)
	CString	m_Age;
	CString	m_name;
	CString	m_sex;
	CString	m_stuno;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDatabase2Set)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDatabase2SET_H__D36014E9_ABA4_491D_B8BD_AEB9AA489AE6__INCLUDED_)

