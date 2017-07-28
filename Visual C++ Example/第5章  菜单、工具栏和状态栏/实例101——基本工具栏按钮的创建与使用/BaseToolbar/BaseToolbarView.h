// BaseToolbarView.h : interface of the CBaseToolbarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASETOOLBARVIEW_H__C8EE8A8F_D689_44A9_BC81_EC69F7445AA6__INCLUDED_)
#define AFX_BASETOOLBARVIEW_H__C8EE8A8F_D689_44A9_BC81_EC69F7445AA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseToolbarView : public CView
{
protected: // create from serialization only
	CBaseToolbarView();
	DECLARE_DYNCREATE(CBaseToolbarView)

// Attributes
public:
	CBaseToolbarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseToolbarView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseToolbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseToolbarView)
	afx_msg void OnButtonstar();
	afx_msg void OnButtonstop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BaseToolbarView.cpp
inline CBaseToolbarDoc* CBaseToolbarView::GetDocument()
   { return (CBaseToolbarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASETOOLBARVIEW_H__C8EE8A8F_D689_44A9_BC81_EC69F7445AA6__INCLUDED_)
