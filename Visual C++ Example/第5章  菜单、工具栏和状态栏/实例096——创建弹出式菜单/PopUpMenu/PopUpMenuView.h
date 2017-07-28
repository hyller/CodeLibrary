// PopUpMenuView.h : interface of the CPopUpMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPUPMENUVIEW_H__50786CF4_60D4_42A9_B604_CD3984420A75__INCLUDED_)
#define AFX_POPUPMENUVIEW_H__50786CF4_60D4_42A9_B604_CD3984420A75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPopUpMenuView : public CView
{
protected: // create from serialization only
	CPopUpMenuView();
	DECLARE_DYNCREATE(CPopUpMenuView)

// Attributes
public:
	CPopUpMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopUpMenuView)
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
	virtual ~CPopUpMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_menuradio;

// Generated message map functions
protected:
	//{{AFX_MSG(CPopUpMenuView)
	afx_msg void OnMenured();
	afx_msg void OnUpdateMenured(CCmdUI* pCmdUI);
	afx_msg void OnMenugreen();
	afx_msg void OnUpdateMenugreen(CCmdUI* pCmdUI);
	afx_msg void OnMenublue();
	afx_msg void OnUpdateMenublue(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PopUpMenuView.cpp
inline CPopUpMenuDoc* CPopUpMenuView::GetDocument()
   { return (CPopUpMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPUPMENUVIEW_H__50786CF4_60D4_42A9_B604_CD3984420A75__INCLUDED_)
