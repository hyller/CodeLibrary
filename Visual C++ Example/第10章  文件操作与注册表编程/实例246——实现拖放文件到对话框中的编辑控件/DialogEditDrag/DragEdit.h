#if !defined(AFX_DRAGEDIT_H__B0B79BAF_22BA_436E_8D85_874409093940__INCLUDED_)
#define AFX_DRAGEDIT_H__B0B79BAF_22BA_436E_8D85_874409093940__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DragEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDragEdit window

class CDragEdit : public CEdit
{
// Construction
public:
	CDragEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDragEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDragEdit)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGEDIT_H__B0B79BAF_22BA_436E_8D85_874409093940__INCLUDED_)
