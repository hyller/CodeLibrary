#if !defined(AFX_SALESET_H__673E8A66_96BB_4128_9831_D270CE39F471__INCLUDED_)
#define AFX_SALESET_H__673E8A66_96BB_4128_9831_D270CE39F471__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SaleSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSaleSet recordset

class CSaleSet : public CRecordset
{
public:
	CSaleSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSaleSet)

// Field/Param Data
	//{{AFX_FIELD(CSaleSet, CRecordset)
	CString	m_MedicineID;
	CString	m_MedicineName;
	int		m_MedicineNumber;
	float	m_MedicinePrice;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaleSet)
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

#endif // !defined(AFX_SALESET_H__673E8A66_96BB_4128_9831_D270CE39F471__INCLUDED_)
