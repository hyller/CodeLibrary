// MedicAdminView.h : interface of the CMedicAdminView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDICADMINVIEW_H__D967F4F9_B1E6_4D1F_989D_B78BCE696ABA__INCLUDED_)
#define AFX_MEDICADMINVIEW_H__D967F4F9_B1E6_4D1F_989D_B78BCE696ABA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMedicAdminView : public CFormView
{
protected: // create from serialization only
	CMedicAdminView();
	DECLARE_DYNCREATE(CMedicAdminView)

public:
	//{{AFX_DATA(CMedicAdminView)
	enum{ IDD = IDD_MEDICADMIN_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CMedicAdminDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedicAdminView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMedicAdminView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CSaleSet* saleSet;
	CMedicSet* medicSet;
	CUserSet* userSet;
	//{{AFX_MSG(CMedicAdminView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MedicAdminView.cpp
inline CMedicAdminDoc* CMedicAdminView::GetDocument()
   { return (CMedicAdminDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDICADMINVIEW_H__D967F4F9_B1E6_4D1F_989D_B78BCE696ABA__INCLUDED_)
