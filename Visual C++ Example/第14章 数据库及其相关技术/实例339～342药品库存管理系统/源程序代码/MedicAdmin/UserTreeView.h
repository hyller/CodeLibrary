#if !defined(AFX_USERTREEVIEW_H__CA83AABC_94C3_46A4_88AD_4A40C0140011__INCLUDED_)
#define AFX_USERTREEVIEW_H__CA83AABC_94C3_46A4_88AD_4A40C0140011__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserTreeView view

class CUserTreeView : public CTreeView
{
protected:
	CUserTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CUserTreeView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CUserTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:
	CImageList m_theImageList;
	CTreeCtrl* m_theTreeCtrl;
	// Generated message map functions
protected:
	
	//{{AFX_MSG(CUserTreeView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERTREEVIEW_H__CA83AABC_94C3_46A4_88AD_4A40C0140011__INCLUDED_)
