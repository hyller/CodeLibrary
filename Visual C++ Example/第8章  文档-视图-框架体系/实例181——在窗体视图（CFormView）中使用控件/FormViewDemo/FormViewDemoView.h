// FormViewDemoView.h : interface of the CFormViewDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMVIEWDEMOVIEW_H__07DE8286_91E2_45AE_AD6D_9630B830B68E__INCLUDED_)
#define AFX_FORMVIEWDEMOVIEW_H__07DE8286_91E2_45AE_AD6D_9630B830B68E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFormViewDemoView : public CFormView
{
protected: // create from serialization only
	CFormViewDemoView();
	DECLARE_DYNCREATE(CFormViewDemoView)

public:
	//{{AFX_DATA(CFormViewDemoView)
	enum { IDD = IDD_FORMVIEWDEMO_FORM };
	CString	m_user;
	CString	m_password;
	//}}AFX_DATA

// Attributes
public:
	CFormViewDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormViewDemoView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFormViewDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFormViewDemoView)
	afx_msg void OnCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FormViewDemoView.cpp
inline CFormViewDemoDoc* CFormViewDemoView::GetDocument()
   { return (CFormViewDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMVIEWDEMOVIEW_H__07DE8286_91E2_45AE_AD6D_9630B830B68E__INCLUDED_)
