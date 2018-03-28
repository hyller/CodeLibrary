#if !defined(AFX_MEDICSET_H__1CF5E0ED_7302_40C2_B3BB_8135BB63CB54__INCLUDED_)
#define AFX_MEDICSET_H__1CF5E0ED_7302_40C2_B3BB_8135BB63CB54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MedicSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMedicSet recordset

class CMedicSet : public CRecordset
{
public:
	CMedicSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMedicSet)

// Field/Param Data
	//{{AFX_FIELD(CMedicSet, CRecordset)
	CString	m_MedicineID;
	CString	m_MedicineName;
	CString	m_MedicineClassification;
	CTime	m_ProduceDate;
	CString	m_Produceplace;
	int		m_MedicineNumber;
	CString	m_Description;
	float	m_UnitPrice;
	int		m_QeulityAssurancePeriod;
	int		m_LowestNumber;
	int		m_HighestNumber;
	CString	m_ProduceCompany;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedicSet)
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

#endif // !defined(AFX_MEDICSET_H__1CF5E0ED_7302_40C2_B3BB_8135BB63CB54__INCLUDED_)
