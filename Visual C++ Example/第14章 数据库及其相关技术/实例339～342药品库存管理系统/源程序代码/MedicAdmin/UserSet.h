#if !defined(AFX_USERSET_H__AFBC7CDF_E865_4E8C_98AA_D91F563502D0__INCLUDED_)
#define AFX_USERSET_H__AFBC7CDF_E865_4E8C_98AA_D91F563502D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserSet recordset

class CUserSet : public CRecordset
{
public:
	CUserSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUserSet)

// Field/Param Data
	//{{AFX_FIELD(CUserSet, CRecordset)
	CString	m_UserAccount;
	CString	m_UserName;
	CString	m_UserPassword;
	CString	m_UserClassification;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERSET_H__AFBC7CDF_E865_4E8C_98AA_D91F563502D0__INCLUDED_)
