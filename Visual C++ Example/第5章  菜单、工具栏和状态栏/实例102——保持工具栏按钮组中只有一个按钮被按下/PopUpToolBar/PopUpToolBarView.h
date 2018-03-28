// PopUpToolBarView.h : interface of the CPopUpToolBarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PopUpToolBarVIEW_H__C8EE8A8F_D689_44A9_BC81_EC69F7445AA6__INCLUDED_)
#define AFX_PopUpToolBarVIEW_H__C8EE8A8F_D689_44A9_BC81_EC69F7445AA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPopUpToolBarView : public CView
{
protected: // create from serialization only
	CPopUpToolBarView();
	DECLARE_DYNCREATE(CPopUpToolBarView)

// Attributes
public:
	CPopUpToolBarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopUpToolBarView)
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
	virtual ~CPopUpToolBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_radio;

// Generated message map functions
protected:
	//{{AFX_MSG(CPopUpToolBarView)
	afx_msg void OnButtonstar();
	afx_msg void OnButtonstop();
	afx_msg void OnUpdateButtonstar(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButtonstop(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PopUpToolBarView.cpp
inline CPopUpToolBarDoc* CPopUpToolBarView::GetDocument()
   { return (CPopUpToolBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PopUpToolBarVIEW_H__C8EE8A8F_D689_44A9_BC81_EC69F7445AA6__INCLUDED_)
